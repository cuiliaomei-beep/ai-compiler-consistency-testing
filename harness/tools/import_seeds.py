#!/usr/bin/env python
"""Turn real issue reproducers from the incident corpus into harness cases.

The harness ships seven hand-written cases. They validate the machinery; they
do not find bugs. The ammunition is the 295 real issue reproducers already in
the dataset, and this converts the CPU-reproducible subset into runnable
:class:`tcd.case.Case` objects.

    python tools/import_seeds.py --out seeds/
    python run.py list --tag seed

**Safety.** Every snippet in that corpus carries a blanket
"DEFENSIVE-RESEARCH SAMPLE - DO NOT EXECUTE" banner, because the same corpus
also holds archived malicious npm and PyPI packages. This importer therefore
refuses to execute anything that is not, provably:

  * sourced from a GitHub issue (``source == "github_issue"``), and
  * from a whitelisted compiler project, and
  * free of the process/network/filesystem patterns listed in ``FORBIDDEN``.

Anything else is rejected and reported, never run. Do not relax these gates to
raise the conversion rate.
"""
from __future__ import annotations

import argparse
import ast
import json
import os
import re
import sys
import textwrap
from typing import Any, Dict, List, Optional, Tuple

sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))

from tcd.analysis import analyze_source  # noqa: E402

DEFAULT_DATASET = r"D:\wsl\personal\dr\paper\有毒编译\toxic-compilation-dataset"

#: only issue reproducers from these projects are ever executed
PROJECT_WHITELIST = ("pytorch/pytorch", "llvm/llvm-project", "apache/tvm",
                     "openxla/xla", "pytorch/xla")

#: refuse to execute a snippet containing any of these
FORBIDDEN = (
    r"\bos\.system\b", r"\bsubprocess\b", r"\bsocket\b", r"\burllib\b",
    r"\brequests\b", r"\bshutil\b", r"\bexec\s*\(", r"\beval\s*\(",
    r"__import__", r"\bopen\s*\([^)]*['\"][wax]", r"\bpickle\b",
    r"\bctypes\b", r"\bpty\b", r"\bpopen\b", r"\bremove\b", r"\brmtree\b",
)
FORBIDDEN_RE = re.compile("|".join(FORBIDDEN), re.I)

#: mark a snippet as needing a GPU
GPU_RE = re.compile(
    r"\bcuda\b|\.cuda\(|device\s*=\s*['\"]cuda|torch\.cuda|triton\.jit|"
    r"tl\.load|tl\.store|num_warps|num_stages|nvidia|rocm|\bhip\b|nccl",
    re.I)

BANNER_RE = re.compile(r"^\s*/\*\s*DEFENSIVE-RESEARCH SAMPLE.*?\*/\s*$", re.M)

TENSOR_CTOR = re.compile(
    r"torch\.(randn|rand|zeros|ones|arange|tensor|empty|full|eye|linspace|randint)")


# --------------------------------------------------------------------------
# reading the corpus
# --------------------------------------------------------------------------

def load_corpus(root: str) -> List[Tuple[Dict, Dict]]:
    """Metadata only. Snippet *files* are read later, and only after the gates.

    The corpus also stores archived malware (npm ``postinstall.js`` and the
    like). Reading those files is pointless here and needlessly touches
    quarantined material, so metadata is loaded first and the bytes are only
    opened for incidents that already passed the whitelist.
    """
    d = os.path.join(root, "data")
    inc = [json.loads(l) for l in open(os.path.join(d, "incidents.jsonl"),
                                       encoding="utf-8") if l.strip()]
    code: Dict[str, Dict] = {}
    for l in open(os.path.join(d, "code_evidence.jsonl"), encoding="utf-8"):
        if l.strip():
            r = json.loads(l)
            code.setdefault(r["incident_id"], r)
    return [(r, code[r["incident_id"]]) for r in inc if r["incident_id"] in code]


def _read(path: str) -> str:
    try:
        with open(path, encoding="utf-8", errors="replace") as fh:
            return fh.read()
    except OSError:
        return ""


def _snippet_text(root: str, iid: str, ce: Dict) -> str:
    sp = (ce.get("snippet_path") or "").strip()
    if sp:
        p = os.path.join(root, sp.replace("/", os.sep))
        if os.path.exists(p):
            return _read(p)
    d = os.path.join(root, "snippets", iid)
    if os.path.isdir(d):
        try:
            names = sorted(os.listdir(d))
        except OSError:
            return ""
        return "\n".join(_read(os.path.join(d, fn)) for fn in names)
    return ""


def clean(text: str) -> str:
    """Strip the sample banner and the blank-line doubling from extraction."""
    text = BANNER_RE.sub("", text)
    lines = text.splitlines()
    # the corpus stores some issue bodies with every line doubled by a blank
    blanks = sum(1 for l in lines if not l.strip())
    if lines and blanks > 0.45 * len(lines):
        out, prev_blank = [], False
        for l in lines:
            if not l.strip():
                if prev_blank:
                    continue
                prev_blank = True
            else:
                prev_blank = False
            out.append(l)
        lines = out
    return "\n".join(lines).strip() + "\n"


# --------------------------------------------------------------------------
# extraction
# --------------------------------------------------------------------------

class Rejected(Exception):
    pass


def _find_compile_target(tree: ast.Module) -> Optional[str]:
    """Which function does the snippet compile?"""
    for node in ast.walk(tree):
        if isinstance(node, ast.Call) and _dotted(node.func) == "torch.compile":
            if node.args and isinstance(node.args[0], ast.Name):
                return node.args[0].id
    for node in ast.walk(tree):
        if isinstance(node, (ast.FunctionDef, ast.AsyncFunctionDef)):
            for dec in node.decorator_list:
                d = _dotted(dec.func if isinstance(dec, ast.Call) else dec)
                if d == "torch.compile":
                    return node.name
    return None


def _dotted(node: ast.AST) -> str:
    parts: List[str] = []
    while isinstance(node, ast.Attribute):
        parts.append(node.attr)
        node = node.value
    if isinstance(node, ast.Name):
        parts.append(node.id)
        return ".".join(reversed(parts))
    return ""


def _call_args(tree: ast.Module, fname: str) -> Optional[List[str]]:
    """Argument expressions of the first plain call to ``fname``."""
    for node in ast.walk(tree):
        if isinstance(node, ast.Call):
            if isinstance(node.func, ast.Name) and node.func.id == fname:
                return [ast.unparse(a) for a in node.args]
            # torch.compile(f)(x)  /  torch.compile(f, ...)(x)
            if isinstance(node.func, ast.Call) and \
                    _dotted(node.func.func) == "torch.compile":
                return [ast.unparse(a) for a in node.args]
    return None


def extract(text: str, iid: str) -> Dict[str, Any]:
    """Split a snippet into an executable prelude, a target fn, and its inputs."""
    src = clean(text)
    if FORBIDDEN_RE.search(src):
        raise Rejected("contains a forbidden process/network/filesystem pattern")
    if GPU_RE.search(src):
        raise Rejected("requires a GPU")
    if not re.search(r"\btorch\b", src):
        raise Rejected("does not reference torch")
    # Issue reproducers routinely omit the obvious import. Supplying it recovers
    # far more seeds than it costs: without this, two thirds of the whitelisted
    # candidates were rejected for a missing first line.
    if not re.search(r"^\s*import torch\b", src, re.M):
        src = "import torch\n" + src
    if not TENSOR_CTOR.search(src):
        raise Rejected("no tensor constructor to build inputs from")

    try:
        tree = ast.parse(src)
    except SyntaxError as e:
        raise Rejected(f"unparseable: {e}") from None

    fname = _find_compile_target(tree)
    if fname is None:
        defs = [n.name for n in tree.body
                if isinstance(n, (ast.FunctionDef, ast.AsyncFunctionDef))]
        if not defs:
            raise Rejected("no function definition and no torch.compile target")
        fname = defs[0]

    fn_node = next((n for n in tree.body
                    if isinstance(n, (ast.FunctionDef, ast.AsyncFunctionDef))
                    and n.name == fname), None)
    if fn_node is None:
        raise Rejected(f"compile target `{fname}` is not defined in the snippet")

    args = _call_args(tree, fname)
    if not args:
        # fall back to any module-level names that hold tensors
        args = [t.id for n in tree.body if isinstance(n, ast.Assign)
                for t in n.targets if isinstance(t, ast.Name)
                and TENSOR_CTOR.search(ast.unparse(n.value))]
        args = args[: len(fn_node.args.args)]
    if not args:
        raise Rejected("could not determine the call arguments")

    # prelude: imports, classes, defs, and the assignments the args depend on
    need = set()
    for a in args:
        try:
            for n in ast.walk(ast.parse(a, mode="eval")):
                if isinstance(n, ast.Name):
                    need.add(n.id)
        except SyntaxError:
            pass

    # Two parts, and the split matters: `prelude` runs once (imports, classes,
    # helper defs), `setup` runs before EVERY call so each execution gets freshly
    # allocated tensors. Sharing input tensors across runs would let one run's
    # in-place writes leak into the next, and the mutation oracle would then
    # report a divergence that the compiler never caused.
    prelude: List[str] = []
    setup: List[str] = []
    if not re.search(r"^\s*import torch\b", src, re.M):
        prelude.append("import torch")
    for node in tree.body:
        if isinstance(node, (ast.Import, ast.ImportFrom, ast.ClassDef,
                             ast.FunctionDef, ast.AsyncFunctionDef)):
            prelude.append(ast.unparse(node))
        elif isinstance(node, ast.Assign):
            targets = {t.id for t in node.targets if isinstance(t, ast.Name)}
            val = ast.unparse(node.value)
            # keep assignments that feed the args, but never ones that compile
            if targets & need and "torch.compile" not in val:
                setup.append(ast.unparse(node))

    # strip a torch.compile decorator: the harness applies compilation itself
    fn_src = ast.unparse(fn_node)
    fn_src = re.sub(r"^@torch\.compile.*?\n", "", fn_src, flags=re.M)

    return {
        "incident_id": iid,
        "fn_name": fname,
        "fn_source": fn_src,
        "prelude": "\n".join(prelude),
        "setup": "\n".join(setup),
        "arg_exprs": args,
        "n_params": len(fn_node.args.args),
    }


# --------------------------------------------------------------------------
# contexts, derived from the static analysis
# --------------------------------------------------------------------------

def derive_contexts(fn_source: str) -> List[Dict[str, Any]]:
    """Single-factor context variants suggested by Phase 1.

    This is where the static scan pays off directly: shape boundaries come from
    the predicates the program actually tests, rather than from a fixed list.
    """
    a = analyze_source(fn_source)
    ctxs: List[Dict[str, Any]] = [{"name": "base", "factors": {"variant": "base"}}]

    # dtype is always worth varying: it is the canonical warm-cache probe
    for dt in ("float16", "float64"):
        ctxs.append({"name": f"dtype_{dt}", "factors": {"variant": "base", "dtype": dt}})

    # contiguity: the layout class the plan targets
    ctxs.append({"name": "noncontig", "factors": {"variant": "noncontig"}})

    for b in a.boundaries[:2]:
        for v in b.values:
            ctxs.append({
                "name": f"dim{v}",
                "factors": {"variant": "base", "resize_dim0": v},
                "from": f"{b.expr} {b.op} {b.constant}",
            })
    return ctxs


# --------------------------------------------------------------------------
# validation: does it actually run?
# --------------------------------------------------------------------------

def validate(seed: Dict[str, Any]) -> Tuple[bool, str]:
    """Execute the seed once in eager. A seed that will not run is not a seed."""
    ns: Dict[str, Any] = {"__name__": "_seed"}
    try:
        exec(compile(seed["prelude"], f"<{seed['incident_id']}:prelude>", "exec"), ns)
        exec(compile(seed["fn_source"], f"<{seed['incident_id']}:fn>", "exec"), ns)
    except Exception as e:
        return False, f"prelude/fn failed: {type(e).__name__}: {str(e)[:120]}"

    fn = ns.get(seed["fn_name"])
    if not callable(fn):
        return False, "target is not callable after exec"
    try:
        exec(compile(seed["setup"], f"<{seed['incident_id']}:setup>", "exec"), ns)
        args = [eval(a, ns) for a in seed["arg_exprs"]]
    except Exception as e:
        return False, f"argument eval failed: {type(e).__name__}: {str(e)[:120]}"
    if len(args) != seed["n_params"]:
        return False, f"arity mismatch: {len(args)} args for {seed['n_params']} params"
    try:
        fn(*args)
    except Exception as e:
        return False, f"eager call raised: {type(e).__name__}: {str(e)[:120]}"
    return True, "ok"


# --------------------------------------------------------------------------
# driver
# --------------------------------------------------------------------------

def main() -> int:
    p = argparse.ArgumentParser(description=__doc__,
                                formatter_class=argparse.RawDescriptionHelpFormatter)
    p.add_argument("--dataset", default=DEFAULT_DATASET)
    p.add_argument("--out", default="seeds")
    p.add_argument("--limit", type=int, default=0)
    args = p.parse_args()

    if not os.path.isdir(args.dataset):
        print(f"dataset not found: {args.dataset}")
        return 2

    corpus = load_corpus(args.dataset)
    print(f"\ncorpus: {len(corpus)} incidents with code evidence")

    stats: Dict[str, int] = {}

    def bump(k: str) -> None:
        stats[k] = stats.get(k, 0) + 1

    accepted: List[Dict[str, Any]] = []
    rejected: List[Tuple[str, str, str]] = []

    for r, ce in corpus:
        iid = r["incident_id"]
        proj = str(r.get("project") or r.get("source_repo") or "")

        # --- the safety gates, in order; nothing is READ before they pass ---
        if r.get("source") != "github_issue":
            bump("skip: not a github issue")
            continue
        if not any(w in proj.lower() for w in PROJECT_WHITELIST):
            bump("skip: project not whitelisted")
            continue
        if ce.get("snippet_provenance") not in ("issue_excerpt", "actual_published"):
            bump("skip: snippet is not a real excerpt")
            continue

        text = _snippet_text(args.dataset, iid, ce)
        if not text.strip():
            bump("skip: empty snippet")
            continue

        try:
            seed = extract(text, iid)
        except Rejected as e:
            bump(f"reject: {e}")
            rejected.append((iid, proj, str(e)))
            continue

        ok, why = validate(seed)
        if not ok:
            bump("reject: does not run")
            rejected.append((iid, proj, why))
            continue

        seed.update({
            "title": (r.get("title") or "")[:160],
            "project": proj,
            "references": (r.get("references") or [])[:3],
            "contexts": derive_contexts(seed["fn_source"]),
        })
        accepted.append(seed)
        bump("ACCEPTED")
        if args.limit and len(accepted) >= args.limit:
            break

    os.makedirs(args.out, exist_ok=True)
    manifest = os.path.join(args.out, "manifest.json")
    with open(manifest, "w", encoding="utf-8") as fh:
        json.dump(accepted, fh, indent=2, ensure_ascii=False)

    report = os.path.join(args.out, "IMPORT_REPORT.md")
    with open(report, "w", encoding="utf-8") as fh:
        fh.write("# Seed import report\n\n")
        fh.write(f"- corpus incidents with code: **{len(corpus)}**\n")
        fh.write(f"- accepted as runnable cases: **{len(accepted)}**\n\n")
        fh.write("## Outcome breakdown\n\n| outcome | n |\n|---|---:|\n")
        for k, v in sorted(stats.items(), key=lambda kv: -kv[1]):
            fh.write(f"| {k} | {v} |\n")
        fh.write("\n## Accepted\n\n| incident | project | fn | params | contexts |\n")
        fh.write("|---|---|---|---:|---:|\n")
        for s in accepted:
            fh.write(f"| {s['incident_id']} | {s['project']} | `{s['fn_name']}` "
                     f"| {s['n_params']} | {len(s['contexts'])} |\n")
        fh.write("\n## Rejected (reached extraction, then failed)\n\n")
        fh.write("| incident | project | reason |\n|---|---|---|\n")
        for iid, proj, why in rejected[:80]:
            fh.write(f"| {iid} | {proj} | {why} |\n")

    print(f"\n{'outcome':<48} n")
    print("-" * 56)
    for k, v in sorted(stats.items(), key=lambda kv: -kv[1]):
        print(f"{k:<48} {v}")
    print(f"\naccepted {len(accepted)} runnable seed case(s)")
    print(f"  manifest: {manifest}")
    print(f"  report:   {report}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
