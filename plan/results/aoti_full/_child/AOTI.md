# export / AOTInductor differential

- operators: 12, samples: 12; export ok/fail: 12/0; AOTI ok/fail: 11/1
- findings: 0 — export-only 0, aoti-only 0, shared with torch.compile(inductor) 0
- wall: 63.3 s

| path | op | kwargs | shapes | dtypes | detail | inductor too |
|---|---|---|---|---|---|---|
