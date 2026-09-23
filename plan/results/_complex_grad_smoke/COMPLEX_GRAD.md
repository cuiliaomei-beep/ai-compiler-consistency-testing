# complex-input gradients eager vs aot_eager (torch 2.14.0+cpu)

- operators: 5, samples run: 10, flagged: 2; wall 3 s

| op | sample | shapes | eager err | compiled err | scale |
|---|---|---|---|---|---|
| linalg.pinv | 0 | [[5, 5]] | 2.9e-06 | 3.9e+00 | 3.0e+00 |
| linalg.pinv | 1 | [[3, 1], [3, 1]] | 1.1e-06 | 2.0e+00 | 1.5e+00 |
