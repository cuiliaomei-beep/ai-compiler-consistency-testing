"""Replace the short citation aliases used while drafting by the dblp keys of bib/references.bib.

Run once after bib/fetch_dblp.py:   python bib/apply_keys.py
It is idempotent: keys that already start with 'DBLP:' are left alone.  It also reports bib entries that are
never cited and aliases that have no dblp record.
"""
import glob
import os
import re

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(HERE)

ALIAS = {  # alias -> unique prefix of the title in bib/keys.txt
    "pytorch2": "PyTorch 2:", "pytorch": "PyTorch: An Imperative", "tvm": "TVM:", "triton": "Triton:",
    "tensorflow": "TensorFlow:", "torchfx": "torch.fx", "mlir": "MLIR:", "halide": "Halide:",
    "dlcsurvey": "The Deep Learning Compiler", "nnsmith": "NNSmith", "torchprobe": "TorchProbe",
    "tzer": "Coverage-guided tensor compiler", "hirgen": "Fuzzing Deep Learning Compilers with HirGen",
    "mlirsmith": "MLIRSmith", "neuri": "NeuRI", "whitefox": "WhiteFox", "gencog": "GenCoG",
    "mtdlc": "Metamorphic Testing of Deep Learning Compilers", "dlcbugs": "A comprehensive study of deep learning compiler",
    "freefuzz": "Free Lunch", "titanfuzz": "Large Language Models Are Zero-Shot", "fuzzgpt": "Large Language Models are Edge-Case",
    "deeprel": "Fuzzing deep-learning libraries via automated relational", "docter": "DocTer", "cradle": "CRADLE",
    "lemon": "Deep learning library testing via effective model", "audee": "Audee", "muffin": "Muffin",
    "predoo": "Predoo", "acetest": "ACETest", "nablafuzz": "Fuzzing Automatic Differentiation",
    "dlbugchar": "A comprehensive study on deep learning bug", "dlfwbugs": "Toward Understanding Deep Learning Framework",
    "silentbugs": "Silent bugs", "dldeploy": "An Empirical Study Towards Characterizing", "csmith": "Finding and understanding bugs in C",
    "emi": "Compiler validation via equivalence", "yarpgen": "Random testing for C and C++", "mckeeman": "Differential Testing for Software",
    "compilertestsurvey": "A Survey of Compiler Testing", "creduce": "Test-case reduction", "ddmin": "Simplifying and Isolating",
    "compcert": "Formal verification of a realistic", "alive2": "Alive2", "transval": "Translation Validation",
    "compilertestcmp": "An empirical comparison of compiler testing", "mtreview": "Metamorphic Testing: A Review",
    "mtsurvey": "A Survey on Metamorphic Testing", "oraclesurvey": "The Oracle Problem", "jitcse": "Validating JIT Compilers",
    "jitpicking": "JIT-Picking", "trustingtrust": "Reflections on Trusting Trust", "reprobuilds": "Reproducible Builds",
    "intoto": "in-toto", "sigstore": "Sigstore", "backstabber": "Backstabber", "soksupply": "SoK: Taxonomy",
}


def main():
    keys = {}
    for line in open(os.path.join(HERE, "keys.txt"), encoding="utf-8"):
        k, t = line.rstrip("\n").split("\t", 1)
        keys[t] = k
    amap, missing = {}, []
    for a, prefix in ALIAS.items():
        hit = [k for t, k in keys.items() if t.startswith(prefix)]
        if len(hit) == 1:
            amap[a] = hit[0]
        else:
            missing.append((a, prefix, hit))
    cited = set()
    cite_re = re.compile(r"\\cite[tp]?\{([^}]*)\}")
    for path in glob.glob(os.path.join(ROOT, "sections", "*.tex")) + glob.glob(os.path.join(ROOT, "figures", "*.tex")) \
            + glob.glob(os.path.join(ROOT, "tables", "*.tex")):
        s = open(path, encoding="utf-8").read()

        def repl(m):
            out = []
            for k in [x.strip() for x in m.group(1).split(",")]:
                k2 = amap.get(k, k)
                if not k2.startswith("DBLP:"):
                    print(f"  unresolved citation '{k}' in {os.path.basename(path)}")
                cited.add(k2)
                out.append(k2)
            return m.group(0).split("{")[0] + "{" + ",".join(out) + "}"

        s2 = cite_re.sub(repl, s)
        if s2 != s:
            open(path, "w", encoding="utf-8").write(s2)
    uncited = [k for k in keys.values() if k not in cited]
    print(f"{len(cited)} distinct keys cited; {len(uncited)} bib entries uncited; {len(missing)} aliases unresolved")
    for k in uncited:
        print("  uncited:", k)
    for m in missing:
        print("  alias problem:", m)


if __name__ == "__main__":
    main()
