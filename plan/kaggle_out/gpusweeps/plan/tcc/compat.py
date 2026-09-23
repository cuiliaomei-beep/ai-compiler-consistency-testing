"""Version-defensive access to PyTorch internals.

Everything the pipeline needs from ``torch._dynamo`` / ``torch._inductor`` is
wrapped here so that a PyTorch upgrade breaks one file. Every helper degrades
to a documented fallback instead of raising. No other module in ``tcc`` may
import ``torch._dynamo`` directly.
"""
from __future__ import annotations

import inspect
import os
import random
import shutil
import subprocess
import sys
from typing import Any, Callable, Dict, Optional

_IMPORT_ERROR: Optional[BaseException] = None
try:
    import torch  # type: ignore
except Exception as exc:  # pragma: no cover - environment dependent
    torch = None  # type: ignore[assignment]
    _IMPORT_ERROR = exc

HAVE_TORCH = torch is not None


def require_torch():
    if torch is None:
        raise RuntimeError(f"PyTorch could not be imported: {_IMPORT_ERROR!r}")
    return torch


# --------------------------------------------------------------------------
# environment (plan 18.2)
# --------------------------------------------------------------------------

def environment() -> Dict[str, Any]:
    """Everything the Environment section of an issue needs."""
    import platform

    env: Dict[str, Any] = {
        "python": sys.version.split()[0],
        "platform": platform.platform(),
        "os": f"{platform.system()} {platform.release()}",
        "torch": None,
        "torch_git": None,
        "cuda": None,
        "rocm": None,
        "device_name": None,
        "triton": None,
        "tilelang": None,
        "cxx_compiler": None,
    }
    if torch is None:
        return env
    env["torch"] = getattr(torch, "__version__", None)
    env["torch_git"] = getattr(getattr(torch, "version", None), "git_version", None)
    try:
        env["rocm"] = getattr(torch.version, "hip", None)
        if torch.cuda.is_available():
            env["cuda"] = torch.version.cuda
            env["device_name"] = torch.cuda.get_device_name(0)
        else:
            env["device_name"] = "cpu"
    except Exception:
        pass
    for mod in ("triton", "tilelang"):
        try:
            m = __import__(mod)
            env[mod] = getattr(m, "__version__", "present")
        except Exception:
            pass
    env["cxx_compiler"] = shutil.which("cl") or shutil.which("g++") or shutil.which("clang++")
    return env


def has_cuda() -> bool:
    try:
        return bool(torch is not None and torch.cuda.is_available())
    except Exception:
        return False


def has_triton() -> bool:
    try:
        import triton  # noqa: F401
        return True
    except Exception:
        return False


def default_device() -> str:
    return "cuda" if has_cuda() else "cpu"


# --------------------------------------------------------------------------
# determinism
# --------------------------------------------------------------------------

def seed_everything(seed: int = 0) -> None:
    random.seed(seed)
    if torch is None:
        return
    try:
        torch.manual_seed(seed)
        if torch.cuda.is_available():
            torch.cuda.manual_seed_all(seed)
    except Exception:
        pass
    try:
        import numpy as np  # type: ignore
        np.random.seed(seed)
    except Exception:
        pass


def sync() -> None:
    if torch is None:
        return
    try:
        if torch.cuda.is_available():
            torch.cuda.synchronize()
    except Exception:
        pass


# --------------------------------------------------------------------------
# dynamo access
# --------------------------------------------------------------------------

def dynamo_reset() -> bool:
    """Clear the *in-process* caches (not the on-disk ones)."""
    if torch is None:
        return False
    try:
        torch._dynamo.reset()
        return True
    except Exception:
        return False


_LOCAL_BACKENDS: Dict[str, Callable] = {}


def register_local_backend(name: str, fn: Callable) -> None:
    _LOCAL_BACKENDS[name] = fn


def lookup_backend(name: str) -> Callable:
    if name in _LOCAL_BACKENDS:
        return _LOCAL_BACKENDS[name]
    t = require_torch()
    for getter in (
        lambda: t._dynamo.lookup_backend(name),
        lambda: t._dynamo.backends.registry.lookup_backend(name),
    ):
        try:
            b = getter()
            if callable(b):
                return b
        except Exception:
            continue
    raise RuntimeError(f"cannot resolve dynamo backend {name!r} on torch {t.__version__}")


def backend_available(name: str) -> bool:
    try:
        lookup_backend(name)
        return True
    except Exception:
        return False


class CompileCounter:
    """Counts real backend invocations - the exact recompile signal.

    ``count`` is windowed (reset per call), ``total`` accumulates.
    """

    def __init__(self, backend: str = "inductor"):
        self.backend_name = backend
        self._inner = lookup_backend(backend)
        self.count = 0
        self.total = 0

    def __call__(self, gm, example_inputs, **kwargs):
        self.count += 1
        self.total += 1
        return self._inner(gm, example_inputs, **kwargs)

    def reset(self) -> None:
        self.count = 0


def counters_snapshot() -> Dict[str, Dict[str, int]]:
    if torch is None:
        return {}
    try:
        from torch._dynamo.utils import counters
        return {k: dict(v) for k, v in counters.items()}
    except Exception:
        return {}


def frames_total(snap: Dict[str, Dict[str, int]]) -> int:
    try:
        return int(snap.get("frames", {}).get("total", 0))
    except Exception:
        return 0


def compile_fn(fn: Callable, backend, dynamic: Optional[bool] = None,
               fullgraph: bool = False, **options) -> Callable:
    t = require_torch()
    kwargs: Dict[str, Any] = {"backend": backend, "fullgraph": fullgraph}
    if dynamic is not None:
        kwargs["dynamic"] = dynamic
    if options:
        kwargs["options"] = options
    return t.compile(fn, **kwargs)


def dynamo_same(ref, res, fp64_ref=None, tol: float = 1e-4) -> Optional[bool]:
    """PyTorch's own accuracy predicate, when available."""
    if torch is None:
        return None
    try:
        from torch._dynamo.utils import same as _same
    except Exception:
        return None
    wanted = {"fp64_ref": fp64_ref, "tol": tol, "equal_nan": True}
    try:
        params = set(inspect.signature(_same).parameters)
        kwargs = {k: v for k, v in wanted.items() if k in params}
    except (TypeError, ValueError):
        kwargs = {}
    import logging
    lg = logging.getLogger("torch._dynamo.utils")
    lvl = lg.level
    lg.setLevel(logging.CRITICAL)  # `same` logs every mismatch at ERROR; we report it ourselves
    try:
        return bool(_same(ref, res, **kwargs))
    except Exception:
        return None
    finally:
        lg.setLevel(lvl)


# --------------------------------------------------------------------------
# on-disk cache control (plan 14: cold must really be cold)
# --------------------------------------------------------------------------

class cache_scope:
    """Enable/disable the on-disk FX-graph / autograd caches for a block."""

    _ENV = ("TORCHINDUCTOR_FX_GRAPH_CACHE", "TORCHINDUCTOR_AUTOGRAD_CACHE")
    _CFG = ("fx_graph_cache", "autograd_cache")

    def __init__(self, disk_cache: bool):
        self.disk_cache = disk_cache
        self._env: Dict[str, Optional[str]] = {}
        self._cfg: Dict[str, Any] = {}

    def __enter__(self):
        for k in self._ENV:
            self._env[k] = os.environ.get(k)
            os.environ[k] = "1" if self.disk_cache else "0"
        try:
            cfg = torch._inductor.config if torch is not None else None
        except Exception:
            cfg = None
        self._cfgobj = cfg
        if cfg is not None:
            for a in self._CFG:
                if hasattr(cfg, a):
                    self._cfg[a] = getattr(cfg, a)
                    try:
                        setattr(cfg, a, bool(self.disk_cache))
                    except Exception:
                        self._cfg.pop(a, None)
        return self

    def __exit__(self, *exc):
        for k, v in self._env.items():
            if v is None:
                os.environ.pop(k, None)
            else:
                os.environ[k] = v
        if self._cfgobj is not None:
            for a, v in self._cfg.items():
                try:
                    setattr(self._cfgobj, a, v)
                except Exception:
                    pass
        return False


# --------------------------------------------------------------------------
# toolchain failures are not semantic failures
# --------------------------------------------------------------------------

_INFRA_MARKERS = (
    "invalidcxxcompiler", "cppcompileerror", "compiler: cl", "cl is not found",
    "backendcompilerfailed", "inductorerror", "no module named 'triton'",
    "outofmemoryerror", "cuda out of memory", "no kernel image is available",
    "ptxas", "triton is not available", "requires cuda",
)


def is_infra_failure(exception: Optional[str], message: Optional[str]) -> bool:
    blob = f"{exception or ''} {message or ''}".lower()
    return any(m in blob for m in _INFRA_MARKERS)


# --------------------------------------------------------------------------
# MSVC on Windows: Inductor's CPU backend needs INCLUDE/LIB, not just cl.exe
# --------------------------------------------------------------------------

def ensure_msvc_env(verbose: bool = False) -> Optional[str]:
    if os.name != "nt":
        return None
    if shutil.which("cl") and os.environ.get("INCLUDE"):
        return "already configured"
    pf86 = os.environ.get("ProgramFiles(x86)", r"C:\Program Files (x86)")
    vswhere = os.path.join(pf86, "Microsoft Visual Studio", "Installer", "vswhere.exe")
    if not os.path.exists(vswhere):
        return None
    try:
        roots = subprocess.check_output(
            [vswhere, "-latest", "-products", "*", "-requires",
             "Microsoft.VisualStudio.Component.VC.Tools.x86.x64",
             "-property", "installationPath"],
            stderr=subprocess.DEVNULL).decode(errors="replace").strip().splitlines()
    except Exception:
        return None
    if not roots:
        return None
    vcvars = os.path.join(roots[0], "VC", "Auxiliary", "Build", "vcvars64.bat")
    if not os.path.exists(vcvars):
        return None
    try:
        out = subprocess.check_output(
            f'cmd /s /c ""{vcvars}" >nul 2>&1 && set"', shell=True,
            stderr=subprocess.DEVNULL).decode(errors="replace")
    except Exception:
        return None
    wanted = {"PATH", "INCLUDE", "LIB", "LIBPATH", "VSINSTALLDIR", "VCINSTALLDIR",
              "WINDOWSSDKDIR", "UCRTVERSION", "WINDOWSSDKVERSION", "VCTOOLSINSTALLDIR"}
    n = 0
    for line in out.splitlines():
        k, sep, v = line.partition("=")
        if sep and k.upper() in wanted:
            os.environ[k.upper()] = v
            n += 1
    ok = shutil.which("cl") is not None
    if verbose:
        print(f"  MSVC: imported {n} variables from {vcvars}; cl.exe "
              f"{'found' if ok else 'NOT found'}")
    return roots[0] if ok else None


def declares_aliasing(op_name: str) -> Optional[bool]:
    """Does this aten op *promise* output/input aliasing in its schema?"""
    if torch is None:
        return None
    try:
        packet = getattr(torch.ops.aten, op_name)
        overloads = list(packet.overloads())
    except Exception:
        return None
    seen = False
    for name in overloads:
        if "out" in name.lower():
            continue  # `out=` overloads alias their out argument by construction
        try:
            schema = getattr(packet, name)._schema
        except Exception:
            continue
        seen = True
        for ret in schema.returns:
            if getattr(ret, "alias_info", None) is not None:
                return True
    return False if seen else None
