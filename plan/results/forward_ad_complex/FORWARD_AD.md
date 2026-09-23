# forward-mode AD through compiled ops (aot_eager, torch 2.14.0+cpu)

- ops: 317, rows: 308, flagged: 1; wall 14 s

| op | finding |
|---|---|
| addr | RuntimeError: InferenceMode::is_enabled() && primal.is_inference() && tangent.is_inference() INTERNAL ASSERT FAILED at "C:\\actions-ru |
