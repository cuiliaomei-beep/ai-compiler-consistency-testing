# export / AOTInductor differential

- operators: 4, samples: 4; export ok/fail: 1/0; AOTI ok/fail: 0/1
- findings: 0 — export-only 0, aoti-only 0, shared with torch.compile(inductor) 0
- wall: 195.4 s

| path | op | kwargs | shapes | dtypes | detail | inductor too |
|---|---|---|---|---|---|---|
