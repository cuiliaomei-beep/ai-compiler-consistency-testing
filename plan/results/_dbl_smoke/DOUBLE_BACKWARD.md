# double backward under compile (aot_eager, torch 2.14.0+cpu)

- ops: 10, rows: 10, flagged: 10; wall 2 s

| op | finding |
|---|---|
| softmax | RuntimeError: torch.compile with aot_autograd does not currently support double backward |
| softmax | RuntimeError: torch.compile with aot_autograd does not currently support double backward |
| nn.functional.gelu | RuntimeError: torch.compile with aot_autograd does not currently support double backward |
| sin | RuntimeError: torch.compile with aot_autograd does not currently support double backward |
| tanh | RuntimeError: torch.compile with aot_autograd does not currently support double backward |
| var | RuntimeError: torch.compile with aot_autograd does not currently support double backward |
| var | RuntimeError: torch.compile with aot_autograd does not currently support double backward |
| linalg.pinv | RuntimeError: torch.compile with aot_autograd does not currently support double backward |
| linalg.pinv | RuntimeError: torch.compile with aot_autograd does not currently support double backward |
| linalg.pinv | RuntimeError: torch.compile with aot_autograd does not currently support double backward |
