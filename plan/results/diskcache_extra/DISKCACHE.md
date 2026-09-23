# Cross-process disk-cache differential

Process A compiles with v1 into an empty cache dir; process B compiles the same source with v2 against the same dir.
`STALE` = B hit the cache and its compiled result disagrees with B's own eager result.

- control (identical source in two processes): cache hit in B — shared cache works
- cases: 5, wall 264.8 s
- verdicts: STALE=0, hit-ok=1, miss=4, bypass=0, error=0, infra=0, A-mismatch=0

| case | what is baked | v1 → v2 | B: fx hit/miss | B: aot hit/miss | verdict | detail |
|---|---|---|---|---|---|---|
| requires_grad | input requires_grad (AOTAutograd forward-only vs joint graph) | False → True | 0/1 | 0/1 | **miss** |  |
| tensor_const_inside_huge | 10k-element constant folded inside the graph (constant-folding / large-constant path) | 0.5 → 1.5 | 0/1 | 0/1 | **miss** |  |
| closure_tensor_factory | tensor captured by a closure cell | 1.5 → 2.5 | 1/0 | 1/0 | **hit-ok** |  |
| dynamo_capture_scalar | dynamo config flag (graph break vs unbacked symint) | False → True | 0/1 | 0/1 | **miss** |  |
| compile_options_dynamic | torch.compile(dynamic=...) flag | False → True | 0/1 | 0/1 | **miss** |  |
