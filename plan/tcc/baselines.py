"""Plan sections 22-24: baselines and the common consistency harness.

B1  Random / Hypothesis-style: exhaustive factor enumeration with random values,
    no static analysis, output-only oracle by default.
B2  FreeFuzz, B3 NNSmith, B4 TorchProbe, B6 TitanFuzz: external tools. They are
    not bundled; the adapter reports whether the tool is importable and, for
    Setting B (common harness), loads the programs the tool generated from a
    directory of reproducer files, so every generator is judged by the same
    eager-vs-compiled oracle, hardware, version and budget.
"""
from __future__ import annotations

import importlib
import random
from dataclasses import dataclass
from typing import Any, Callable, Dict, List, Optional, Sequence, Tuple

from .factors import analyze
from .generate import TestPlan, context_switch_sequences
from .oracle import ALL_ORACLES
from .program import Context, Program, single_factor_pairs
from .scs import SCS, DeriveOptions
from .seeds import programs_from_dir

_DTYPES = ["float16", "bfloat16", "float64", "float32"]
_LAYOUTS = ["noncontig", "transposed"]
_SCALARS: List[Any] = [True, False, 0, 1, 2, 3, 4, 5, 7, 8, 16, 31, 32, 33, None, "sum", "mean", 0.5]


def random_contexts(program: Program, budget: int, rng: random.Random,
                    base: Optional[Context] = None) -> List[Context]:
    """Exhaustive factor families, random values, no knowledge of the program."""
    base = base or program.base_context
    n_args = max(1, len(program.param_names()))
    out: List[Context] = [base]
    names = {base.name}
    tries = 0
    while len(out) < budget and tries < budget * 20:
        tries += 1
        family = rng.choice(["dtype", "layout", "resize", "requires_grad", "substitute", "compile", "rank"])
        f: Dict[str, Any] = dict(base.factors)
        if family == "dtype":
            v = rng.choice(_DTYPES)
            f["dtype"] = v
            name = f"rand:dtype={v}"
        elif family == "layout":
            v = rng.choice(_LAYOUTS)
            f["layout"] = v
            name = f"rand:layout={v}"
        elif family == "resize":
            i, d, v = rng.randrange(n_args), rng.randrange(2), rng.choice([1, 2, 3, 4, 7, 8, 9, 15, 16, 17, 31, 32, 33, 64])
            f["resize"] = {"arg": i, "dim": d, "value": v}
            name = f"rand:arg{i}.dim{d}={v}"
        elif family == "requires_grad":
            i = rng.randrange(n_args)
            f["requires_grad"] = {"arg": i, "value": bool(rng.getrandbits(1))}
            name = f"rand:arg{i}.grad={f['requires_grad']['value']}"
        elif family == "substitute":
            i, v = rng.randrange(n_args), rng.choice(_SCALARS)
            f["substitute"] = {"arg": i, "value": v}
            name = f"rand:arg{i}={v!r}"
        elif family == "rank":
            i = rng.randrange(n_args)
            f["rank"] = {"arg": i, "delta": rng.choice([1, -1])}
            name = f"rand:arg{i}.rank{f['rank']['delta']:+d}"
        else:
            f["compile"] = {"dynamic": bool(rng.getrandbits(1))}
            name = f"rand:dynamic={f['compile']['dynamic']}"
        if name in names:
            continue
        names.add(name)
        out.append(Context(name, f))
    return out


def random_plan_builder(budget: int = 12, seed: int = 0, sequences: bool = True,
                        oracles: Sequence[str] = ALL_ORACLES, level: str = "A0") -> Callable[[Program], TestPlan]:
    def build(program: Program) -> TestPlan:
        rng = random.Random(f"{seed}:{program.name}")
        a = analyze(program.fn, program.get_source())
        ctxs = random_contexts(program, budget, rng)
        pairs = single_factor_pairs(ctxs)
        rng.shuffle(pairs)
        seqs = context_switch_sequences(pairs[:budget], ("A->B", "A->B->A")) if sequences else []
        return TestPlan(program.name, a, SCS(site=a.function, params=a.params), [], ctxs, pairs, seqs,
                        list(oracles), level=level)
    return build


# --------------------------------------------------------------------------
# external tools
# --------------------------------------------------------------------------

@dataclass
class ExternalTool:
    key: str
    name: str
    venue: str
    module: str
    install_hint: str

    def available(self) -> bool:
        try:
            importlib.import_module(self.module)
            return True
        except Exception:
            return False

    def programs(self, directory: Optional[str]) -> Tuple[List[Program], List[Tuple[str, str]]]:
        """Setting B: programs the tool generated, as reproducer files."""
        if not directory:
            return [], [("-", f"no directory of {self.name} outputs was given (--external DIR)")]
        return programs_from_dir(directory)


EXTERNAL: Dict[str, ExternalTool] = {
    "freefuzz": ExternalTool("freefuzz", "FreeFuzz", "ICSE 2022", "freefuzz",
                             "clone https://github.com/ise-uiuc/FreeFuzz and export generated API calls as f/args files"),
    "nnsmith": ExternalTool("nnsmith", "NNSmith", "ASPLOS 2023", "nnsmith",
                            "pip install nnsmith; run `nnsmith.model_gen backend.type=torchjit` and export models as f/args files"),
    "torchprobe": ExternalTool("torchprobe", "TorchProbe", "APLAS 2023", "torchprobe",
                               "clone the TorchProbe artifact (arXiv 2310.20078) and export transformed programs as f/args files"),
    "titanfuzz": ExternalTool("titanfuzz", "TitanFuzz", "ISSTA 2023", "titanfuzz",
                              "clone https://github.com/ise-uiuc/TitanFuzz and export generated programs as f/args files"),
    "deeprel": ExternalTool("deeprel", "DeepREL", "ESEC/FSE 2022", "deeprel",
                            "clone https://github.com/ise-uiuc/DeepREL (supplemental baseline)"),
}


def availability() -> List[Dict[str, Any]]:
    return [{"tool": t.name, "venue": t.venue, "available": t.available(), "hint": t.install_hint}
            for t in EXTERNAL.values()]


# --------------------------------------------------------------------------
# NNSmith (B3), driven programmatically when the package is importable
# --------------------------------------------------------------------------

def nnsmith_programs(n: int = 10, seed: int = 0, max_nodes: int = 6, timeout_ms: int = 10000
                     ) -> Tuple[List[Program], List[Tuple[str, str]]]:
    """Generate ``n`` NNSmith torch models and wrap them as programs.

    NNSmith's own harness feeds each model exactly one input and compares the
    compiled output with eager. Here the same models enter the common harness
    (Setting B): same oracle, hardware, version and budget as every other
    generator. The forward source is NNSmith's generic ``SymbolNet.forward``,
    so the static analysis finds no program-specific factor - which is the
    point of the comparison.
    """
    out: List[Program] = []
    rejected: List[Tuple[str, str]] = []
    try:
        import warnings
        warnings.filterwarnings("ignore")
        from nnsmith.graph_gen import model_gen  # type: ignore
        from nnsmith.materialize import Model  # type: ignore
        from nnsmith.narrow_spec import auto_opset  # type: ignore
        import torch  # type: ignore
    except Exception as e:  # noqa: BLE001
        return out, [("nnsmith", f"not importable: {type(e).__name__}: {e}")]
    try:
        ModelType = Model.init("torch", backend_target="cpu")
        ModelType.add_seed_setter()
        opset = auto_opset(ModelType)
    except Exception as e:  # noqa: BLE001
        return out, [("nnsmith", f"init failed: {type(e).__name__}: {e}")]
    for i in range(n):
        s = seed * 100003 + i
        try:
            gen = model_gen(opset=opset, seed=s, max_nodes=max_nodes, timeout_ms=timeout_ms)
            ir = gen.make_concrete()
            model = ModelType.from_gir(ir)
            model.refine_weights()
            oracle = model.make_oracle()
            module = model.torch_model.eval()
            keys = list(model.input_like)
            frozen = tuple(torch.from_numpy(oracle.input[k]).clone() for k in keys)
        except Exception as e:  # noqa: BLE001
            rejected.append((f"nnsmith-{s}", f"{type(e).__name__}: {str(e)[:80]}"))
            continue

        def fn(*args, _m=module):
            return _m(*args)
        fn.__name__ = f"nnsmith_{s}"

        def make_inputs(ctx: Context, _f=frozen) -> Tuple[Any, ...]:
            return tuple(t.clone() for t in _f)

        try:
            import inspect
            src = inspect.getsource(type(module).forward)
        except Exception:
            src = None
        out.append(Program(name=f"nnsmith_{s}", fn=fn, make_inputs=make_inputs,
                           tags=["nnsmith", "external"], notes=f"NNSmith model seed {s}, "
                           f"{ir.n_compute_inst()} ops, inputs {[tuple(t.shape) for t in frozen]}",
                           source=src, check_grad=False, project="nnsmith"))
    return out, rejected
