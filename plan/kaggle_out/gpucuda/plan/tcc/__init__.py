"""tcc - Toxic Compilation Consistency detection.

An implementation of the research plan "面向 Toxic Compilation 一致性缺陷的自动检测"
(Python-level semantic analysis + consistency-oriented dynamic test generation).

    Phase 1  sites / ir / factors / scs        static analysis -> test obligations
    Phase 2  seeds / generate / execute        pairwise, boundary and cache-sequence tests
    Phase 3  observe / oracle / localize /     O1-O7, staged localization, minimization
             minimize
    Phase 4  report                            developer-ready issue drafts + dedup

    faults / corpus / benchmark                ground-truth benchmark
    baselines / ablation / experiments         RQ1-RQ5, experiments A-E
"""
__version__ = "0.1.0"
