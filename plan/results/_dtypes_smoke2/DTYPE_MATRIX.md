# dtype-promotion matrix (aot_eager, pairs=float, autocast=False)

- cases: 50, mismatches: 25 {'dtype': 0, 'raise': 0, 'raise_type': 25, 'shape': 0}; wall 2.9 s

## embedding_bag_w (25)
| dt1 | dt2 | form | eager | compiled | kind |
|---|---|---|---|---|---|
| float16 | float16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float16 | bfloat16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float16 | float32 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float16 | float64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float16 | complex64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bfloat16 | float16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bfloat16 | bfloat16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bfloat16 | float32 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bfloat16 | float64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bfloat16 | complex64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float32 | float16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float32 | bfloat16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float32 | float32 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float32 | float64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float32 | complex64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float64 | float16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float64 | bfloat16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float64 | float32 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float64 | float64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float64 | complex64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| complex64 | float16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| complex64 | bfloat16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| complex64 | float32 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| complex64 | float64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| complex64 | complex64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
