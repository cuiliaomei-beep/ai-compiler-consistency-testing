# unary dtype sweep (inductor, torch 2.14.0+cpu)

- cases: 240, mismatches: 74 {'raise_type': 68, 'raise': 6}; wall 68 s

| op | dtype | mode | eager | compiled | kind |
|---|---|---|---|---|---|
| abs | complex64 | out=float64 | float64(3, 4) | raise:TorchRuntimeError | raise |
| abs | complex64 | out=bfloat16 | bfloat16(3, 4) | raise:TorchRuntimeError | raise |
| round | bool | plain | raise:NotImplementedError | bool(3, 4) | raise |
| round | bool | plain | raise:NotImplementedError | bool(3, 4) | raise |
| round | bool | plain | raise:NotImplementedError | bool(3, 4) | raise |
| round | bool | plain | raise:NotImplementedError | bool(3, 4) | raise |

(raise_type mismatches = 68, omitted: exception-class wrapping only)
