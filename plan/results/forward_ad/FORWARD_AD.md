# forward-mode AD through compiled ops (aot_eager, torch 2.14.0+cpu)

- ops: 506, rows: 497, flagged: 3; wall 23 s

| op | finding |
|---|---|
| addr | RuntimeError: InferenceMode::is_enabled() && primal.is_inference() && tangent.is_inference() INTERNAL ASSERT FAILED at "C:\\actions-ru |
| quantile | RuntimeError: InferenceMode::is_enabled() && primal.is_inference() && tangent.is_inference() INTERNAL ASSERT FAILED at "C:\\actions-ru |
| nanquantile | RuntimeError: InferenceMode::is_enabled() && primal.is_inference() && tangent.is_inference() INTERNAL ASSERT FAILED at "C:\\actions-ru |
