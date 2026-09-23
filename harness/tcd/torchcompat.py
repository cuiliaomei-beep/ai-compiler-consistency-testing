"""Version-defensive wrappers around PyTorch private APIs.

Everything the harness needs from ``torch._dynamo`` lives here, so a PyTorch
upgrade breaks one file instead of the whole harness. Every helper degrades to
a documented fallback instead of raising.

Nothing else in ``tcd`` may import ``torch._dynamo`` directly.
"""
from __future__ import annotations

import inspect
import os
import random
from typing import Any, Callable, Dict, Optional

_IMPORT_ERROR: Optional[BaseException] = None
try:  # torch is optional so the offline modules stay importable/testable
    import torch
except Exception as exc:  # pragma: no cover - depends on environment
    torch = None  # type: ignore[assignment]
    _IMPORT_ERROR = exc

HAVE_TORCH = torch is not None


def require_torch():
    """Return the torch module, or raise with the original import error."""
    if torch is None:
        raise RuntimeError(
            "PyTorch is required for this operation but could not be imported: "
            f"{_IMPORT_ERROR!r}"
        )
    return torch


def environment() -> Dict[str, Any]:
    """Everything that belongs in a bug report's Environment section."""
    import platform
    import sys

    env: Dict[str, Any] = {
        "python": sys.version.split()[0],
        "platform": platform.platform(),
        "torch": None,
        "torch_git": None,
        "cuda": None,
        "device_name": None,
        "triton": None,
    }
    if torch is None:
        return env
    env["torch"] = getattr(torch, "__version__", None)
    env["torch_git"] = getattr(getattr(torch, "version", None), "git_version", None)
    try:
        if torch.cuda.is_available():
            env["cuda"] = torch.version.cuda
            env["device_name"] = torch.cuda.get_device_name(0)
    except Exception:
        pass
    try:
        import triton  # type: ignore

        env["triton"] = getattr(triton, "__version__", None)
    except Exception:
        pass
    return env


def dynamo_reset() -> bool:
    """Clear the *in-process* Dynamo/Inductor caches. Returns success."""
    if torch is None:
        return False
    try:
        torch._dynamo.reset()
        return True
    except Exception:
        return False


def seed_everything(seed: int = 0) -> None:
    """Make a run reproducible enough that a rerun is meaningful evidence."""
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


#: Synthetic backends the harness registers itself (see selfcheck.poison_backend).
_LOCAL_BACKENDS: Dict[str, Callable] = {}


def register_local_backend(name: str, fn: Callable) -> None:
    """Make a synthetic backend addressable by name, like a real one."""
    _LOCAL_BACKENDS[name] = fn


def lookup_backend(name: str) -> Callable:
    """Resolve a named Dynamo backend to its compiler callable.

    We need the raw callable (not the string) so it can be wrapped by
    :class:`CompileCounter`.
    """
    if name in _LOCAL_BACKENDS:
        return _LOCAL_BACKENDS[name]
    t = require_torch()
    for getter in (
        lambda: t._dynamo.lookup_backend(name),
        lambda: t._dynamo.backends.registry.lookup_backend(name),
    ):
        try:
            backend = getter()
            if callable(backend):
                return backend
        except Exception:
            continue
    raise RuntimeError(f"cannot resolve dynamo backend {name!r} on torch {t.__version__}")


class CompileCounter:
    """A backend wrapper that counts real compilations.

    This is the harness's primary recompile signal. Counting backend
    invocations is exact and far more version-stable than reading
    ``torch._dynamo.utils.counters``, which we keep only as a cross-check.

    Usage::

        counter = CompileCounter("inductor")
        fn = torch.compile(f, backend=counter)
        counter.reset(); fn(x)      # counter.count == 1  (cold)
        counter.reset(); fn(x)      # counter.count == 0  (cache hit)
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
        """Zero the windowed counter (``total`` keeps accumulating)."""
        self.count = 0

    def __repr__(self) -> str:  # pragma: no cover - debug aid
        return f"CompileCounter({self.backend_name!r}, count={self.count}, total={self.total})"


def counters_snapshot() -> Dict[str, Dict[str, int]]:
    """Plain-dict copy of ``torch._dynamo.utils.counters`` (cross-check only)."""
    if torch is None:
        return {}
    try:
        from torch._dynamo.utils import counters

        return {k: dict(v) for k, v in counters.items()}
    except Exception:
        return {}


def frames_total(snap: Dict[str, Dict[str, int]]) -> int:
    """Frames compiled, per a counters snapshot. 0 when unavailable."""
    try:
        return int(snap.get("frames", {}).get("total", 0))
    except Exception:
        return 0


def dynamo_same(ref, res, fp64_ref=None, tol: float = 1e-4) -> Optional[bool]:
    """Call ``torch._dynamo.utils.same`` if present, tolerating signature drift.

    Returns ``None`` when the upstream helper is unavailable, so callers fall
    back to :mod:`tcd.oracle`'s own comparison. Using PyTorch's own accuracy
    predicate matters: a report it accepts cannot be dismissed on tolerance
    grounds.
    """
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
    except (TypeError, ValueError):  # pragma: no cover - builtins have no signature
        kwargs = {}
    try:
        return bool(_same(ref, res, **kwargs))
    except Exception:
        return None


def compile_fn(fn: Callable, backend, dynamic: Optional[bool] = None, **kwargs) -> Callable:
    """``torch.compile`` with a backend that may be a name or a callable."""
    t = require_torch()
    opts: Dict[str, Any] = {"backend": backend}
    if dynamic is not None:
        opts["dynamic"] = dynamic
    opts.update(kwargs)
    return t.compile(fn, **opts)


def ensure_msvc_env(verbose: bool = False) -> Optional[str]:
    """Make MSVC usable from this process, on Windows.

    Inductor's CPU backend shells out to ``cl``, and ``cl`` needs more than a
    path: it needs ``INCLUDE``/``LIB`` too. Normally you get those by launching
    a "x64 Native Tools" prompt, which is easy to forget and easy to get wrong.

    Instead we locate the toolchain with ``vswhere``, run its ``vcvars64.bat``
    in a throwaway shell, and import the variables it sets into this process.
    Returns the toolchain path on success, ``None`` if MSVC is absent or the
    platform is not Windows. Safe and cheap to call repeatedly.
    """
    import shutil
    import subprocess

    if os.name != "nt":
        return None
    if shutil.which("cl"):
        return "already on PATH"

    pf86 = os.environ.get("ProgramFiles(x86)", r"C:\Program Files (x86)")
    vswhere = os.path.join(pf86, "Microsoft Visual Studio", "Installer", "vswhere.exe")
    if not os.path.exists(vswhere):
        return None
    try:
        root = subprocess.check_output(
            [vswhere, "-latest", "-products", "*",
             "-requires", "Microsoft.VisualStudio.Component.VC.Tools.x86.x64",
             "-property", "installationPath"],
            stderr=subprocess.DEVNULL,
        ).decode(errors="replace").strip().splitlines()
    except Exception:
        return None
    if not root:
        return None

    vcvars = os.path.join(root[0], "VC", "Auxiliary", "Build", "vcvars64.bat")
    if not os.path.exists(vcvars):
        return None

    try:
        out = subprocess.check_output(
            f'cmd /s /c ""{vcvars}" >nul 2>&1 && set"',
            shell=True, stderr=subprocess.DEVNULL,
        ).decode(errors="replace")
    except Exception:
        return None

    wanted = {"PATH", "INCLUDE", "LIB", "LIBPATH", "VSINSTALLDIR",
              "VCINSTALLDIR", "WINDOWSSDKDIR", "UCRTVERSION",
              "WINDOWSSDKVERSION", "VCTOOLSINSTALLDIR"}
    imported = 0
    for line in out.splitlines():
        key, sep, val = line.partition("=")
        if sep and key.upper() in wanted:
            os.environ[key.upper() if key.upper() != "PATH" else "PATH"] = val
            imported += 1

    ok = shutil.which("cl") is not None
    if verbose:
        print(f"  MSVC env: imported {imported} vars from {vcvars}; "
              f"cl.exe {'found' if ok else 'STILL NOT FOUND'}")
    return root[0] if ok else None


#: Markers of a *toolchain* failure rather than a semantic one.
_INFRA_MARKERS = (
    "invalidcxxcompiler",       # no host C++ compiler
    "cppcompileerror",
    "compiler: cl",
    "cl is not found",
    "backendcompilerfailed",
    "inductorerror",
    "no module named 'triton'",
    "outofmemoryerror",
    "cuda out of memory",
    "no kernel image is available",
    "ptxas",
)


def is_infra_failure(exception: Optional[str], message: Optional[str]) -> bool:
    """Did the *toolchain* fail, rather than the program behave differently?

    This distinction decides whether a row is a bug candidate at all. A backend
    that cannot compile - no host compiler, no triton, out of memory - has told
    us nothing about semantics, and reporting it as a divergence buries the
    real findings. Such layers are dropped from the comparison instead.
    """
    blob = f"{exception or ''} {message or ''}".lower()
    return any(m in blob for m in _INFRA_MARKERS)


def declares_aliasing(op_name: str) -> Optional[bool]:
    """Does this aten operator *promise* that its outputs alias its input?

    The distinction decides whether an alias-relation change is a defect at all,
    and it is written down in the schema rather than guessed::

        aten::chunk(Tensor(a -> *) self, ...) -> Tensor(a)[]    # promises views
        aten::unsafe_chunk(Tensor self, ...)  -> Tensor[]       # promises nothing

    ``unsafe_chunk`` returning storage-sharing tensors in eager is an
    implementation detail, not a contract; functionalization is free to
    materialise copies instead. Reporting that as a miscompilation produces a
    false candidate for every ``unsafe_*`` operator in the corpus.

    Returns True (aliasing declared), False (explicitly not), or None (unknown
    operator - then the caller should check, since silence is not a promise
    either way).
    """
    if torch is None:
        return None
    try:
        packet = getattr(torch.ops.aten, op_name)
    except Exception:
        return None

    seen = False
    try:
        overloads = list(packet.overloads())
    except Exception:
        overloads = ["default"]
    for name in overloads:
        try:
            ov = getattr(packet, name)
            schema = ov._schema
        except Exception:
            continue
        seen = True
        for ret in schema.returns:
            if getattr(ret, "alias_info", None) is not None:
                return True
    return False if seen else None


def sync() -> None:
    """Force pending accelerator work to land before we read results."""
    if torch is None:
        return
    try:
        if torch.cuda.is_available():
            torch.cuda.synchronize()
    except Exception:
        pass
