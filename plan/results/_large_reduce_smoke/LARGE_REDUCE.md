# large-reduction accumulation sweep (torch 2.14.0+cpu, cpu, n=100003, rows=4)

- cases: 18, flagged: 0 (compiled error > 4x eager error against float64 truth)

| op | values | dtype | eager rel-err | compiled rel-err | eager[0] | compiled[0] | truth[0] |
|---|---|---|---|---|---|---|---|
