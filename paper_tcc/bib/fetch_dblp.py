"""Build bib/references.bib from dblp.

dblp.org's HTML/BibTeX pages sit behind an anti-bot challenge, so records are read from dblp's public
SPARQL endpoint (https://sparql.dblp.org) and written in dblp's standard BibTeX layout:
  * a '% <dblp bibtex link>' comment precedes every entry,
  * the title value is wrapped in double braces,
  * the editor field is not emitted.
Usage:  python bib/fetch_dblp.py            (re-resolves everything; cache in bib/dblp_cache.json)
"""
import json
import os
import re
import sys
import time
import urllib.parse
import urllib.request

HERE = os.path.dirname(os.path.abspath(__file__))
CACHE = os.path.join(HERE, "dblp_cache.json")
ENDPOINT = "https://sparql.dblp.org/sparql"
PFX = "PREFIX dblp: <https://dblp.org/rdf/schema#>\n"

# (title as listed in dblp without the trailing period, year or None)
REFS = [
    # --- DL compilers / frameworks
    ("PyTorch 2: Faster Machine Learning Through Dynamic Python Bytecode Transformation and Graph Compilation", 2024),
    ("PyTorch: An Imperative Style, High-Performance Deep Learning Library", 2019),
    ("TVM: An Automated End-to-End Optimizing Compiler for Deep Learning", 2018),
    ("Triton: an intermediate language and compiler for tiled neural network computations", 2019),
    ("TensorFlow: A System for Large-Scale Machine Learning", 2016),
    ("torch.fx: Practical Program Capture and Transformation for Deep Learning in Python", 2022),
    ("MLIR: Scaling Compiler Infrastructure for Domain Specific Computation", 2021),
    
    ("The Deep Learning Compiler: A Comprehensive Survey", 2021),
    # --- DL compiler testing
    ("NNSmith: Generating Diverse and Valid Test Cases for Deep Learning Compilers", 2023),
    ("TorchProbe: Fuzzing Dynamic Deep Learning Compilers", 2023),
    ("Coverage-guided tensor compiler fuzzing with joint IR-pass mutation", 2022),
    ("Fuzzing Deep Learning Compilers with HirGen", 2023),
    ("MLIRSmith: Random Program Generation for Fuzzing MLIR Compiler Infrastructure", 2023),
    ("NeuRI: Diversifying DNN Generation via Inductive Rule Inference", 2023),
    ("WhiteFox: White-Box Compiler Fuzzing Empowered by Large Language Models", 2024),
    ("GenCoG: A DSL-Based Approach to Generating Computation Graphs for TVM Testing", 2023),
    ("Metamorphic Testing of Deep Learning Compilers", 2022),
    ("A comprehensive study of deep learning compiler bugs", 2021),
    # --- DL library testing
    ("Free Lunch for Testing: Fuzzing Deep-Learning Libraries from Open Source", 2022),
    ("Large Language Models Are Zero-Shot Fuzzers: Fuzzing Deep-Learning Libraries via Large Language Models", 2023),
    ("Large Language Models are Edge-Case Generators: Crafting Unusual Programs for Fuzzing Deep Learning Libraries", 2024),
    ("Fuzzing deep-learning libraries via automated relational API inference", 2022),
    ("DocTer: documentation-guided fuzzing for testing deep learning API functions", 2022),
    ("CRADLE: cross-backend validation to detect and localize bugs in deep learning libraries", 2019),
    ("Deep learning library testing via effective model generation", 2020),
    ("Audee: Automated Testing for Deep Learning Frameworks", 2020),
    ("Muffin: Testing Deep Learning Libraries via Neural Architecture Fuzzing", 2022),
    ("Predoo: precision testing of deep learning operators", 2021),
    ("ACETest: Automated Constraint Extraction for Testing Deep Learning Operators", 2023),
    ("Fuzzing Automatic Differentiation in Deep-Learning Libraries", 2023),
    # --- empirical studies of DL bugs
    ("A comprehensive study on deep learning bug characteristics", 2019),
    ("Toward Understanding Deep Learning Framework Bugs", 2023),
    ("Silent bugs in deep learning frameworks: an empirical study of Keras and TensorFlow", 2024),
    ("An Empirical Study Towards Characterizing Deep Learning Development and Deployment Across Different Frameworks and Platforms", 2019),
    # --- compiler testing and validation
    ("Finding and understanding bugs in C compilers", 2011),
    ("Compiler validation via equivalence modulo inputs", 2014),
    ("Random testing for C and C++ compilers with YARPGen", 2020),
    ("Differential Testing for Software", 1998),
    ("A Survey of Compiler Testing", 2021),
    ("Test-case reduction for C compiler bugs", 2012),
    ("Simplifying and Isolating Failure-Inducing Input", 2002),
    ("Formal verification of a realistic compiler", 2009),
    ("Alive2: bounded translation validation for LLVM", 2021),
    ("Translation Validation", 1998),
    
    # --- metamorphic / oracle
    ("Metamorphic Testing: A Review of Challenges and Opportunities", 2018),
    ("A Survey on Metamorphic Testing", 2016),
    ("The Oracle Problem in Software Testing: A Survey", 2015),
    # --- JIT testing
    ("Validating JIT Compilers via Compilation Space Exploration", 2023),
    ("JIT-Picking: Differential Fuzzing of JavaScript Engines", 2022),
    # --- supply chain / trust
    ("Reflections on Trusting Trust", 1984),
    ("Reproducible Builds: Increasing the Integrity of Software Supply Chains", 2022),
    ("in-toto: Providing farm-to-table guarantees for bits and bytes", 2019),
    ("Sigstore: Software Signing for Everybody", 2022),
    ("Backstabber's Knife Collection: A Review of Open Source Software Supply Chain Attacks", 2020),
    ("SoK: Taxonomy of Attacks on Open-Source Software Supply Chains", 2023),
]


def sparql(query, retries=3):
    data = urllib.parse.urlencode({"query": PFX + query, "format": "json"}).encode()
    for k in range(retries):
        try:
            req = urllib.request.Request(ENDPOINT, data=data, headers={"User-Agent": "bib-builder/1.0 (academic use)",
                                                                        "Accept": "application/sparql-results+json"})
            with urllib.request.urlopen(req, timeout=60) as r:
                return json.load(r)["results"]["bindings"]
        except Exception as e:  # noqa: BLE001
            if k == retries - 1:
                raise
            time.sleep(2 + 2 * k)
    return []


def esc(s):
    return s.replace("\\", "\\\\").replace('"', '\\"')


def find_record(title, year):
    """Return candidate record URIs for the title (exact first, then case-insensitive)."""
    for t in (title + ".", title):
        rows = sparql(f'SELECT ?p ?y WHERE {{ ?p dblp:title "{esc(t)}" . OPTIONAL {{ ?p dblp:yearOfPublication ?y }} }}')
        if rows:
            break
    else:
        words = [w for w in re.findall(r"[A-Za-z0-9]+", title) if len(w) > 3][:6]
        conds = " && ".join(f'CONTAINS(LCASE(?t), "{w.lower()}")' for w in words)
        rows = sparql(f"SELECT ?p ?y ?t WHERE {{ ?p dblp:title ?t . OPTIONAL {{ ?p dblp:yearOfPublication ?y }} FILTER({conds}) }} LIMIT 20")
        tl = re.sub(r"[^a-z0-9]", "", title.lower())
        rows = [r for r in rows if re.sub(r"[^a-z0-9]", "", r["t"]["value"].lower()).startswith(tl[:60])]
    cands = [(r["p"]["value"], r.get("y", {}).get("value", "")) for r in rows]
    # prefer the peer-reviewed version over CoRR, and the requested year
    def rank(c):
        uri, y = c
        return ("/journals/corr/" in uri, 0 if (year and y[:4] == str(year)) else 1, uri)
    return sorted(set(cands), key=rank)


def record(uri):
    rows = sparql(f"SELECT ?p ?o WHERE {{ <{uri}> ?p ?o }}")
    d = {}
    for r in rows:
        d.setdefault(r["p"]["value"].split("#")[-1], []).append(r["o"]["value"])
    sig = sparql(f"SELECT ?n ?name WHERE {{ <{uri}> dblp:hasSignature ?s . ?s dblp:signatureOrdinal ?n . "
                 f"?s dblp:signatureDblpName ?name }} ORDER BY ?n")
    d["_authors"] = [re.sub(r"\s+\d{4}$", "", s["name"]["value"]) for s in sorted(sig, key=lambda s: int(s["n"]["value"]))]
    return d


def first(d, k, default=None):
    v = d.get(k)
    return v[0] if v else default


def wrap(value, indent=18, width=78):
    words, lines, cur = value.split(), [], ""
    for w in words:
        if cur and len(cur) + 1 + len(w) > width:
            lines.append(cur)
            cur = w
        else:
            cur = (cur + " " + w).strip()
    lines.append(cur)
    return ("\n" + " " * indent).join(lines)


ACRO = re.compile(r"\b([A-Z][A-Za-z]*[A-Z][A-Za-z]*|[A-Z]{2,})\b")


def protect(s):
    """dblp braces capitalised acronyms in venue names; mirror that."""
    return ACRO.sub(lambda m: "{" + m.group(1) + "}", s)


def to_bibtex(uri, d, cache):
    key = uri.split("/rec/")[1]
    btype = first(d, "bibtexType", "").split("#")[-1].lower() or "misc"
    fields = []
    authors = d["_authors"]
    if authors:
        fields.append(("author", (" and\n" + " " * 18).join(authors)))
    title = first(d, "title", "").rstrip()
    fields.append(("title", "{" + wrap(title) + "}"))   # outer braces added below -> {{...}}
    if btype == "inproceedings":
        part = first(d, "publishedAsPartOf")
        book, publisher, series, volume = first(d, "publishedInBook") or first(d, "publishedIn"), None, None, None
        if part:
            if part not in cache:
                cache[part] = record(part)
            pd = cache[part]
            book = first(pd, "title", book).rstrip(".")
            publisher = first(pd, "publishedBy")
            series = first(pd, "publishedInSeries")
            volume = first(pd, "publishedInSeriesVolume")
        fields.append(("booktitle", wrap(protect(book))))
        if series:
            fields.append(("series", wrap(protect(series))))
        if volume:
            fields.append(("volume", volume))
        if first(d, "pagination"):
            fields.append(("pages", first(d, "pagination").replace("-", "--")))
        if publisher:
            fields.append(("publisher", protect(publisher)))
    elif btype == "article":
        j = first(d, "publishedInJournal") or first(d, "publishedIn")
        fields.append(("journal", wrap(protect(j))))
        if first(d, "publishedInJournalVolume"):
            fields.append(("volume", first(d, "publishedInJournalVolume")))
        if first(d, "publishedInJournalVolumeIssue"):
            fields.append(("number", first(d, "publishedInJournalVolumeIssue")))
        if first(d, "pagination"):
            fields.append(("pages", first(d, "pagination").replace("-", "--")))
    else:
        if first(d, "publishedIn"):
            fields.append(("howpublished", first(d, "publishedIn")))
        if first(d, "publishedBy"):
            fields.append(("publisher", protect(first(d, "publishedBy"))))
    fields.append(("year", first(d, "yearOfPublication", "")))
    doi = first(d, "doi")
    url = first(d, "primaryDocumentPage") or doi
    if url:
        fields.append(("url", url))
    if doi:
        fields.append(("doi", doi.replace("https://doi.org/", "")))
    fields.append(("biburl", f"https://dblp.org/rec/{key}.bib"))
    fields.append(("bibsource", "dblp computer science bibliography, https://dblp.org"))
    body = ",\n".join(f"  {k:<12} = {{{v}}}" for k, v in fields)
    return f"% https://dblp.org/rec/{key}.html?view=bibtex\n@{btype}{{DBLP:{key},\n{body}\n}}\n"


def main():
    cache = json.load(open(CACHE, encoding="utf-8")) if os.path.exists(CACHE) else {}
    out, keys, missing = [], [], []
    for title, year in REFS:
        ck = "T::" + title
        if ck not in cache:
            try:
                cands = find_record(title, year)
            except Exception as e:  # noqa: BLE001
                print("  ! lookup failed:", title[:60], e)
                cands = []
            cache[ck] = cands[0][0] if cands else None
            time.sleep(0.3)
        uri = cache[ck]
        if not uri:
            missing.append(title)
            continue
        if uri not in cache:
            cache[uri] = record(uri)
            time.sleep(0.3)
        out.append(to_bibtex(uri, cache[uri], cache))
        keys.append((uri.split("/rec/")[1], title))
        json.dump(cache, open(CACHE, "w", encoding="utf-8"), ensure_ascii=False, indent=0)
    hdr = ("% references.bib -- every entry comes from dblp (https://dblp.org); the comment line above each entry is the\n"
           "% dblp BibTeX link of that record. Title values use double braces; editor fields are removed.\n"
           "% Regenerate with: python bib/fetch_dblp.py\n\n")
    open(os.path.join(HERE, "references.bib"), "w", encoding="utf-8").write(hdr + "\n".join(out))
    with open(os.path.join(HERE, "keys.txt"), "w", encoding="utf-8") as f:
        for k, t in keys:
            f.write(f"DBLP:{k}\t{t}\n")
    print(f"{len(out)} entries written; {len(missing)} missing")
    for m in missing:
        print("  MISSING:", m)


if __name__ == "__main__":
    sys.exit(main())
