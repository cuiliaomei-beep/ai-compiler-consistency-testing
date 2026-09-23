# dtype-promotion matrix (inductor, pairs=lowprec, autocast=False)

- cases: 112, mismatches: 28 {'dtype': 12, 'raise': 12, 'raise_type': 4, 'shape': 0}; wall 255.9 s

## bce_weight (28)
| dt1 | dt2 | form | eager | compiled | kind |
|---|---|---|---|---|---|
| bool | float16 | tt | raise:NotImplementedError | float16() | raise |
| bool | float16 | t0 | raise:NotImplementedError | float16() | raise |
| bool | bfloat16 | tt | raise:NotImplementedError | bfloat16() | raise |
| bool | bfloat16 | t0 | raise:NotImplementedError | bfloat16() | raise |
| int32 | float16 | tt | raise:NotImplementedError | float16() | raise |
| int32 | float16 | t0 | raise:NotImplementedError | float16() | raise |
| int32 | bfloat16 | tt | raise:NotImplementedError | bfloat16() | raise |
| int32 | bfloat16 | t0 | raise:NotImplementedError | bfloat16() | raise |
| int64 | float16 | tt | raise:NotImplementedError | float16() | raise |
| int64 | float16 | t0 | raise:NotImplementedError | float16() | raise |
| int64 | bfloat16 | tt | raise:NotImplementedError | bfloat16() | raise |
| int64 | bfloat16 | t0 | raise:NotImplementedError | bfloat16() | raise |
| float16 | bfloat16 | tt | float16() | float32() | dtype |
| float16 | bfloat16 | t0 | float16() | float32() | dtype |
| float16 | float32 | tt | float16() | float32() | dtype |
| float16 | float32 | t0 | float16() | float32() | dtype |
| float16 | float64 | tt | float16() | float64() | dtype |
| float16 | float64 | t0 | float16() | float64() | dtype |
| bfloat16 | float16 | tt | bfloat16() | float32() | dtype |
| bfloat16 | float16 | t0 | bfloat16() | float32() | dtype |
| bfloat16 | float32 | tt | bfloat16() | float32() | dtype |
| bfloat16 | float32 | t0 | bfloat16() | float32() | dtype |
| bfloat16 | float64 | tt | bfloat16() | float64() | dtype |
| bfloat16 | float64 | t0 | bfloat16() | float64() | dtype |
| complex64 | float16 | tt | raise:NotImplementedError | raise:RuntimeError | raise_type |
| complex64 | float16 | t0 | raise:NotImplementedError | raise:RuntimeError | raise_type |
| complex64 | bfloat16 | tt | raise:NotImplementedError | raise:RuntimeError | raise_type |
| complex64 | bfloat16 | t0 | raise:NotImplementedError | raise:RuntimeError | raise_type |
