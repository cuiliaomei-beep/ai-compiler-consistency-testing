# Cross-process disk-cache differential

Process A compiles with v1 into an empty cache dir; process B compiles the same source with v2 against the same dir.
`STALE` = B hit the cache and its compiled result disagrees with B's own eager result.

- control (identical source in two processes): cache hit in B — shared cache works
- cases: 24, wall 763.2 s
- verdicts: STALE=0, hit-ok=2, miss=21, bypass=0, error=0, infra=1, A-mismatch=0

| case | what is baked | v1 → v2 | B: fx hit/miss | B: aot hit/miss | verdict | detail |
|---|---|---|---|---|---|---|
| closure_float | float constant from a global/closure | 1.5 → 2.5 | 0/1 | 0/1 | **miss** |  |
| closure_int_shape | int constant used as a view size | 3 → 4 | 0/1 | 0/1 | **miss** |  |
| int_slice | int constant in a slice | 3 → 5 | 0/1 | 0/1 | **miss** |  |
| tensor_const_inside | tensor constant created inside the graph | 1.5 → 2.5 | 0/1 | 0/1 | **miss** |  |
| tensor_const_inside_big | 100-element tensor constant created inside the graph | 0.0 → 1.0 | 0/1 | 0/1 | **miss** |  |
| tensor_const_global | global tensor captured by the graph | 1.5 → 2.5 | 1/0 | 1/0 | **hit-ok** |  |
| attr_float | object attribute | 1.5 → 2.5 | 0/1 | 0/1 | **miss** |  |
| default_arg | default argument | 1.5 → 2.5 | 0/1 | 0/1 | **miss** |  |
| math_const | module attribute (math.pi / math.e) | 'pi' → 'e' | 0/1 | 0/1 | **miss** |  |
| str_mode | string constant selecting the kernel | 'nearest' → 'linear' | 0/1 | 0/1 | **miss** |  |
| bool_flag | bool constant on a branch | True → False | 0/1 | 0/1 | **miss** |  |
| tuple_kernel | tuple constant (kernel_size) | (2, 2) → (3, 3) | 0/1 | 0/1 | **miss** |  |
| full_inside | torch.full with a Python scalar inside the graph | 1.5 → 2.5 | 0/1 | 0/1 | **miss** |  |
| arange_inside | arange size constant inside the graph (output shape changes) | 4 → 6 | 0/1 | 0/1 | **miss** |  |
| default_dtype | process-global default dtype (changes the dtype of a constant made inside the graph) | 'float32' → 'float64' | 0/1 | 0/1 | **miss** |  |
| matmul_precision | process-global matmul precision | 'highest' → 'medium' | 0/1 | 0/1 | **miss** |  |
| deterministic | process-global deterministic-algorithms flag | False → True | 0/1 | 0/1 | **miss** |  |
| inductor_simdlen | inductor config that changes codegen (vectorisation) | 'None' → 1 | 0/1 | 0/1 | **miss** |  |
| inductor_epilogue | inductor config epilogue_fusion | True → False | 0/1 | 0/1 | **miss** |  |
| freezing_param | frozen parameter values (freezing bakes weights as constants) | 1.0 → 2.0 | 1/0 | 0/0 | **hit-ok** |  |
| module_attr_int | nn.Module int attribute used as a shape | 3 → 4 | 0/1 | 0/1 | **miss** |  |
| requires_grad | input requires_grad (AOTAutograd forward-only vs joint graph) | False → True | None/None | None/None | **infra** | exit 1: Traceback (most recent call last):
  File "<string>", line 8, in <module |
| grad_mode | process-global grad mode | True → False | 0/1 | 0/1 | **miss** |  |
| num_threads | thread count (changes the parallel reduction order) | 1 → 4 | 0/1 | 0/1 | **miss** |  |
