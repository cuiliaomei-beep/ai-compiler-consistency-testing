# dtype-promotion matrix (inductor, pairs=all, autocast=False)

- cases: 9344, mismatches: 787 {'dtype': 2, 'raise': 120, 'raise_type': 665, 'shape': 0}; wall 194.0 s

## lerp (70)
| dt1 | dt2 | form | eager | compiled | kind |
|---|---|---|---|---|---|
| bool | bool | tt | raise:NotImplementedError | raise:BackendCompilerFailed | raise_type |
| bool | bool | t0 | raise:NotImplementedError | raise:BackendCompilerFailed | raise_type |
| bool | int32 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | int32 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | int64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | int64 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | float16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | float16 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | bfloat16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | bfloat16 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | float32 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | float32 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | float64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | float64 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | complex64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | complex64 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | bool | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | bool | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | int32 | tt | raise:NotImplementedError | raise:BackendCompilerFailed | raise_type |
| int32 | int32 | t0 | raise:NotImplementedError | raise:BackendCompilerFailed | raise_type |
| int32 | int64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | int64 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | float16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | float16 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | bfloat16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | bfloat16 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | float32 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | float32 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | float64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | float64 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | complex64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | complex64 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | bool | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | bool | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | int32 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | int32 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | int64 | tt | raise:NotImplementedError | raise:BackendCompilerFailed | raise_type |
| int64 | int64 | t0 | raise:NotImplementedError | raise:BackendCompilerFailed | raise_type |
| int64 | float16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | float16 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | bfloat16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | bfloat16 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | float32 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | float32 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | float64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | float64 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | complex64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | complex64 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float16 | bool | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float16 | bool | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float16 | int32 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float16 | int32 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float16 | int64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float16 | int64 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float16 | bfloat16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float16 | bfloat16 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float16 | float32 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float16 | float32 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float16 | float64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float16 | float64 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float16 | complex64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float16 | complex64 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bfloat16 | bool | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bfloat16 | bool | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bfloat16 | int32 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bfloat16 | int32 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bfloat16 | int64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bfloat16 | int64 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bfloat16 | float16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bfloat16 | float16 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |

## layer_norm_w (70)
| dt1 | dt2 | form | eager | compiled | kind |
|---|---|---|---|---|---|
| bool | bool | tt | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| bool | bool | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| bool | int32 | tt | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| bool | int32 | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| bool | int64 | tt | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| bool | int64 | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| bool | float16 | tt | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| bool | float16 | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| bool | bfloat16 | tt | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| bool | bfloat16 | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| bool | float32 | tt | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| bool | float32 | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| bool | float64 | tt | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| bool | float64 | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| bool | complex64 | tt | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| bool | complex64 | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int32 | bool | tt | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int32 | bool | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int32 | int32 | tt | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int32 | int32 | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int32 | int64 | tt | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int32 | int64 | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int32 | float16 | tt | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int32 | float16 | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int32 | bfloat16 | tt | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int32 | bfloat16 | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int32 | float32 | tt | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int32 | float32 | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int32 | float64 | tt | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int32 | float64 | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int32 | complex64 | tt | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int32 | complex64 | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int64 | bool | tt | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int64 | bool | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int64 | int32 | tt | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int64 | int32 | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int64 | int64 | tt | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int64 | int64 | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int64 | float16 | tt | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int64 | float16 | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int64 | bfloat16 | tt | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int64 | bfloat16 | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int64 | float32 | tt | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int64 | float32 | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int64 | float64 | tt | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int64 | float64 | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int64 | complex64 | tt | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int64 | complex64 | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| float16 | bool | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float16 | bool | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float16 | int32 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float16 | int32 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float16 | int64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float16 | int64 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float16 | bfloat16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float16 | bfloat16 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float16 | float32 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float16 | float32 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float16 | float64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float16 | float64 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float16 | complex64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float16 | complex64 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bfloat16 | bool | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bfloat16 | bool | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bfloat16 | int32 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bfloat16 | int32 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bfloat16 | int64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bfloat16 | int64 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bfloat16 | float16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bfloat16 | float16 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |

## prelu_w (70)
| dt1 | dt2 | form | eager | compiled | kind |
|---|---|---|---|---|---|
| bool | bool | tt | raise:NotImplementedError | bool(3, 4) | raise |
| bool | bool | t0 | raise:NotImplementedError | bool(3, 4) | raise |
| bool | int32 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | int32 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | int64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | int64 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | float16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | float16 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | bfloat16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | bfloat16 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | float32 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | float32 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | float64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | float64 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | complex64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | complex64 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | bool | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | bool | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | int32 | tt | raise:NotImplementedError | int32(3, 4) | raise |
| int32 | int32 | t0 | raise:NotImplementedError | int32(3, 4) | raise |
| int32 | int64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | int64 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | float16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | float16 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | bfloat16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | bfloat16 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | float32 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | float32 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | float64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | float64 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | complex64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | complex64 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | bool | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | bool | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | int32 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | int32 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | int64 | tt | raise:NotImplementedError | int64(3, 4) | raise |
| int64 | int64 | t0 | raise:NotImplementedError | int64(3, 4) | raise |
| int64 | float16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | float16 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | bfloat16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | bfloat16 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | float32 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | float32 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | float64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | float64 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | complex64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | complex64 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float16 | bool | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float16 | bool | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float16 | int32 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float16 | int32 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float16 | int64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float16 | int64 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float16 | bfloat16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float16 | bfloat16 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float16 | float32 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float16 | float32 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float16 | float64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float16 | float64 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float16 | complex64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float16 | complex64 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bfloat16 | bool | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bfloat16 | bool | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bfloat16 | int32 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bfloat16 | int32 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bfloat16 | int64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bfloat16 | int64 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bfloat16 | float16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bfloat16 | float16 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |

## scatter_add (64)
| dt1 | dt2 | form | eager | compiled | kind |
|---|---|---|---|---|---|
| bool | int32 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | int32 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | int64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | int64 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | float16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | float16 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | bfloat16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | bfloat16 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | float32 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | float32 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | float64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | float64 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | complex64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | complex64 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | bool | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | bool | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | int64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | int64 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | float16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | float16 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | bfloat16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | bfloat16 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | float32 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | float32 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | float64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | float64 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | complex64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | complex64 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | bool | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | bool | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | int32 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | int32 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | float16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | float16 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | bfloat16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | bfloat16 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | float32 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | float32 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | float64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | float64 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | complex64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | complex64 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float16 | bool | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float16 | bool | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float16 | int32 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float16 | int32 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float16 | int64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float16 | int64 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float16 | bfloat16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float16 | bfloat16 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float16 | float32 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float16 | float32 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float16 | float64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float16 | float64 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float16 | complex64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float16 | complex64 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bfloat16 | bool | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bfloat16 | bool | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bfloat16 | int32 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bfloat16 | int32 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bfloat16 | int64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bfloat16 | int64 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bfloat16 | float16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bfloat16 | float16 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |

## kl_div (54)
| dt1 | dt2 | form | eager | compiled | kind |
|---|---|---|---|---|---|
| bool | bool | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | bool | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | int32 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | int32 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | int64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | int64 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | float16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | float16 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | bfloat16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | bfloat16 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | float32 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | float32 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | float64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | float64 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | complex64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | complex64 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | bool | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | bool | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | int32 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | int32 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | int64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | int64 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | float16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | float16 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | bfloat16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | bfloat16 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | float32 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | float32 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | float64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | float64 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | complex64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | complex64 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | bool | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | bool | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | int32 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | int32 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | int64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | int64 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | float16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | float16 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | bfloat16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | bfloat16 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | float32 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | float32 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | float64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | float64 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | complex64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | complex64 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float16 | bool | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float16 | bool | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float16 | int32 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float16 | int32 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float16 | int64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float16 | int64 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |

## group_norm_w (54)
| dt1 | dt2 | form | eager | compiled | kind |
|---|---|---|---|---|---|
| bool | bool | tt | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| bool | bool | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| bool | int32 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | int32 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | int64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | int64 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | float16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | float16 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | bfloat16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | bfloat16 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | float32 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | float32 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | float64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | float64 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | complex64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | complex64 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | bool | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | bool | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | int32 | tt | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int32 | int32 | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int32 | int64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | int64 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | float16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | float16 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | bfloat16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | bfloat16 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | float32 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | float32 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | float64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | float64 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | complex64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | complex64 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | bool | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | bool | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | int32 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | int32 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | int64 | tt | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int64 | int64 | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int64 | float16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | float16 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | bfloat16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | bfloat16 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | float32 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | float32 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | float64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | float64 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | complex64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | complex64 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float16 | bool | tt | raise:RuntimeError | float16(3, 4, 1) | raise |
| float16 | bool | t0 | raise:RuntimeError | float16(3, 4, 1) | raise |
| float16 | int32 | tt | raise:RuntimeError | float16(3, 4, 1) | raise |
| float16 | int32 | t0 | raise:RuntimeError | float16(3, 4, 1) | raise |
| float16 | int64 | tt | raise:RuntimeError | float16(3, 4, 1) | raise |
| float16 | int64 | t0 | raise:RuntimeError | float16(3, 4, 1) | raise |

## embedding_bag_w (53)
| dt1 | dt2 | form | eager | compiled | kind |
|---|---|---|---|---|---|
| bool | bool | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | bool | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| bool | int32 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | int32 | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| bool | int64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | int64 | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| bool | float16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | float16 | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| bool | bfloat16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | bfloat16 | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| bool | float32 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | float32 | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| bool | float64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | float64 | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| bool | complex64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | complex64 | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int32 | bool | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | bool | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int32 | int32 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | int32 | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int32 | int64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | int64 | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int32 | float16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | float16 | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int32 | bfloat16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | bfloat16 | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int32 | float32 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | float32 | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int32 | float64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | float64 | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int32 | complex64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | complex64 | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int64 | bool | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | bool | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int64 | int32 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | int32 | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int64 | int64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | int64 | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int64 | float16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | float16 | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int64 | bfloat16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | bfloat16 | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int64 | float32 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | float32 | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int64 | float64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | float64 | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int64 | complex64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | complex64 | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| float16 | bool | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float16 | int32 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float16 | int64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float16 | float16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float16 | bfloat16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |

## batch_norm_w (51)
| dt1 | dt2 | form | eager | compiled | kind |
|---|---|---|---|---|---|
| bool | bool | tt | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| bool | bool | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| bool | int32 | tt | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| bool | int32 | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| bool | int64 | tt | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| bool | int64 | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| bool | float16 | tt | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| bool | float16 | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| bool | bfloat16 | tt | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| bool | bfloat16 | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| bool | float32 | tt | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| bool | float32 | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| bool | float64 | tt | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| bool | float64 | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| bool | complex64 | tt | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| bool | complex64 | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int32 | bool | tt | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int32 | bool | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int32 | int32 | tt | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int32 | int32 | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int32 | int64 | tt | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int32 | int64 | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int32 | float16 | tt | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int32 | float16 | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int32 | bfloat16 | tt | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int32 | bfloat16 | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int32 | float32 | tt | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int32 | float32 | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int32 | float64 | tt | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int32 | float64 | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int32 | complex64 | tt | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int32 | complex64 | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int64 | bool | tt | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int64 | bool | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int64 | int32 | tt | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int64 | int32 | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int64 | int64 | tt | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int64 | int64 | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int64 | float16 | tt | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int64 | float16 | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int64 | bfloat16 | tt | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int64 | bfloat16 | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int64 | float32 | tt | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int64 | float32 | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int64 | float64 | tt | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int64 | float64 | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int64 | complex64 | tt | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int64 | complex64 | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| float16 | bool | tt | raise:RuntimeError | float16(3, 4) | raise |
| float16 | int32 | tt | raise:RuntimeError | float16(3, 4) | raise |
| float16 | int64 | tt | raise:RuntimeError | float16(3, 4) | raise |

## cross_entropy_soft_w (48)
| dt1 | dt2 | form | eager | compiled | kind |
|---|---|---|---|---|---|
| bool | bool | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | bool | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | int32 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | int32 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | int64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | int64 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | float16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | float16 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | bfloat16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | bfloat16 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | float32 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | float32 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | float64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | float64 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | complex64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | complex64 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | bool | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | bool | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | int32 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | int32 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | int64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | int64 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | float16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | float16 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | bfloat16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | bfloat16 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | float32 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | float32 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | float64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | float64 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | complex64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | complex64 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | bool | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | bool | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | int32 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | int32 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | int64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | int64 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | float16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | float16 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | bfloat16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | bfloat16 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | float32 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | float32 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | float64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | float64 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | complex64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | complex64 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |

## bce_logits_pos_weight (34)
| dt1 | dt2 | form | eager | compiled | kind |
|---|---|---|---|---|---|
| int32 | bool | tt | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int32 | bool | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int32 | int32 | tt | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int32 | int32 | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int32 | int64 | tt | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int32 | int64 | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int32 | float16 | tt | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int32 | float16 | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int32 | bfloat16 | tt | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int32 | bfloat16 | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int32 | float32 | tt | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int32 | float32 | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int32 | float64 | tt | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int32 | float64 | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int32 | complex64 | tt | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int32 | complex64 | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int64 | bool | tt | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int64 | bool | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int64 | int32 | tt | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int64 | int32 | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int64 | int64 | tt | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int64 | int64 | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int64 | float16 | tt | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int64 | float16 | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int64 | bfloat16 | tt | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int64 | bfloat16 | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int64 | float32 | tt | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int64 | float32 | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int64 | float64 | tt | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int64 | float64 | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int64 | complex64 | tt | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int64 | complex64 | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| float16 | bool | tt | raise:NotImplementedError | float16() | raise |
| float16 | bool | t0 | raise:NotImplementedError | float16() | raise |

## bce_logits_weight (32)
| dt1 | dt2 | form | eager | compiled | kind |
|---|---|---|---|---|---|
| int32 | bool | tt | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int32 | bool | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int32 | int32 | tt | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int32 | int32 | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int32 | int64 | tt | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int32 | int64 | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int32 | float16 | tt | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int32 | float16 | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int32 | bfloat16 | tt | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int32 | bfloat16 | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int32 | float32 | tt | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int32 | float32 | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int32 | float64 | tt | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int32 | float64 | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int32 | complex64 | tt | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int32 | complex64 | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int64 | bool | tt | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int64 | bool | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int64 | int32 | tt | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int64 | int32 | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int64 | int64 | tt | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int64 | int64 | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int64 | float16 | tt | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int64 | float16 | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int64 | bfloat16 | tt | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int64 | bfloat16 | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int64 | float32 | tt | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int64 | float32 | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int64 | float64 | tt | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int64 | float64 | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int64 | complex64 | tt | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int64 | complex64 | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |

## lerp_w (24)
| dt1 | dt2 | form | eager | compiled | kind |
|---|---|---|---|---|---|
| bool | bool | tt | raise:NotImplementedError | raise:BackendCompilerFailed | raise_type |
| bool | bool | t0 | raise:NotImplementedError | raise:BackendCompilerFailed | raise_type |
| bool | int32 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | int32 | t0 | raise:NotImplementedError | raise:BackendCompilerFailed | raise_type |
| bool | int64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | int64 | t0 | raise:NotImplementedError | raise:BackendCompilerFailed | raise_type |
| bool | float16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | float16 | t0 | float16(3, 4) | raise:BackendCompilerFailed | raise |
| bool | bfloat16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | bfloat16 | t0 | bfloat16(3, 4) | raise:BackendCompilerFailed | raise |
| bool | float32 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | float32 | t0 | float32(3, 4) | raise:BackendCompilerFailed | raise |
| bool | float64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | float64 | t0 | float64(3, 4) | raise:BackendCompilerFailed | raise |
| bool | complex64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | complex64 | t0 | complex64(3, 4) | raise:BackendCompilerFailed | raise |
| int32 | bool | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | bool | t0 | raise:NotImplementedError | float32(3, 4) | raise |
| int32 | int32 | tt | raise:NotImplementedError | float32(3, 4) | raise |
| int32 | int32 | t0 | raise:NotImplementedError | float32(3, 4) | raise |
| int32 | int64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | int64 | t0 | raise:NotImplementedError | float32(3, 4) | raise |
| int32 | float16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | bfloat16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |

## matmul (16)
| dt1 | dt2 | form | eager | compiled | kind |
|---|---|---|---|---|---|
| bool | bool | tt | raise:NotImplementedError | raise:BackendCompilerFailed | raise_type |
| bool | bool | t0 | raise:NotImplementedError | raise:BackendCompilerFailed | raise_type |
| bool | int32 | tt | raise:RuntimeError | raise:BackendCompilerFailed | raise_type |
| bool | int32 | t0 | raise:RuntimeError | raise:BackendCompilerFailed | raise_type |
| bool | int64 | tt | raise:RuntimeError | raise:BackendCompilerFailed | raise_type |
| bool | int64 | t0 | raise:RuntimeError | raise:BackendCompilerFailed | raise_type |
| bool | float16 | tt | raise:RuntimeError | raise:BackendCompilerFailed | raise_type |
| bool | float16 | t0 | raise:RuntimeError | raise:BackendCompilerFailed | raise_type |
| bool | bfloat16 | tt | raise:RuntimeError | raise:BackendCompilerFailed | raise_type |
| bool | bfloat16 | t0 | raise:RuntimeError | raise:BackendCompilerFailed | raise_type |
| bool | float32 | tt | raise:RuntimeError | raise:BackendCompilerFailed | raise_type |
| bool | float32 | t0 | raise:RuntimeError | raise:BackendCompilerFailed | raise_type |
| bool | float64 | tt | raise:RuntimeError | raise:BackendCompilerFailed | raise_type |
| bool | float64 | t0 | raise:RuntimeError | raise:BackendCompilerFailed | raise_type |
| int32 | bool | tt | raise:RuntimeError | raise:BackendCompilerFailed | raise_type |
| int32 | bool | t0 | raise:RuntimeError | raise:BackendCompilerFailed | raise_type |

## linear (16)
| dt1 | dt2 | form | eager | compiled | kind |
|---|---|---|---|---|---|
| bool | bool | tt | raise:NotImplementedError | raise:BackendCompilerFailed | raise_type |
| bool | bool | t0 | raise:NotImplementedError | raise:BackendCompilerFailed | raise_type |
| bool | int32 | tt | raise:RuntimeError | raise:BackendCompilerFailed | raise_type |
| bool | int32 | t0 | raise:RuntimeError | raise:BackendCompilerFailed | raise_type |
| bool | int64 | tt | raise:RuntimeError | raise:BackendCompilerFailed | raise_type |
| bool | int64 | t0 | raise:RuntimeError | raise:BackendCompilerFailed | raise_type |
| bool | float16 | tt | raise:RuntimeError | raise:BackendCompilerFailed | raise_type |
| bool | float16 | t0 | raise:RuntimeError | raise:BackendCompilerFailed | raise_type |
| bool | bfloat16 | tt | raise:RuntimeError | raise:BackendCompilerFailed | raise_type |
| bool | bfloat16 | t0 | raise:RuntimeError | raise:BackendCompilerFailed | raise_type |
| bool | float32 | tt | raise:RuntimeError | raise:BackendCompilerFailed | raise_type |
| bool | float32 | t0 | raise:RuntimeError | raise:BackendCompilerFailed | raise_type |
| bool | float64 | tt | raise:RuntimeError | raise:BackendCompilerFailed | raise_type |
| bool | float64 | t0 | raise:RuntimeError | raise:BackendCompilerFailed | raise_type |
| int32 | bool | tt | raise:RuntimeError | raise:BackendCompilerFailed | raise_type |
| int32 | bool | t0 | raise:RuntimeError | raise:BackendCompilerFailed | raise_type |

## sub (6)
| dt1 | dt2 | form | eager | compiled | kind |
|---|---|---|---|---|---|
| bool | int32 | tt | raise:NotImplementedError | int32(3, 4) | raise |
| bool | int32 | t0 | raise:NotImplementedError | int32(3, 4) | raise |
| bool | int64 | tt | raise:NotImplementedError | int64(3, 4) | raise |
| bool | int64 | t0 | raise:NotImplementedError | int64(3, 4) | raise |
| bool | float16 | tt | raise:NotImplementedError | float16(3, 4) | raise |
| bool | float16 | t0 | raise:NotImplementedError | float16(3, 4) | raise |

## hypot (6)
| dt1 | dt2 | form | eager | compiled | kind |
|---|---|---|---|---|---|
| bool | bool | tt | raise:NotImplementedError | float32(3, 4) | raise |
| bool | bool | t0 | raise:NotImplementedError | float32(3, 4) | raise |
| bool | int32 | tt | raise:NotImplementedError | float32(3, 4) | raise |
| bool | int32 | t0 | raise:NotImplementedError | float32(3, 4) | raise |
| bool | int64 | tt | raise:NotImplementedError | float32(3, 4) | raise |
| bool | int64 | t0 | raise:NotImplementedError | float32(3, 4) | raise |

## heaviside (6)
| dt1 | dt2 | form | eager | compiled | kind |
|---|---|---|---|---|---|
| bool | int32 | tt | raise:RuntimeError | int32(3, 4) | raise |
| bool | int32 | t0 | raise:RuntimeError | int32(3, 4) | raise |
| bool | int64 | tt | raise:RuntimeError | int64(3, 4) | raise |
| bool | int64 | t0 | raise:RuntimeError | int64(3, 4) | raise |
| bool | float16 | tt | raise:RuntimeError | float16(3, 4) | raise |
| bool | float16 | t0 | raise:RuntimeError | float16(3, 4) | raise |

## nextafter (6)
| dt1 | dt2 | form | eager | compiled | kind |
|---|---|---|---|---|---|
| bool | bool | tt | raise:NotImplementedError | float32(3, 4) | raise |
| bool | bool | t0 | raise:NotImplementedError | float32(3, 4) | raise |
| bool | int32 | tt | raise:NotImplementedError | float32(3, 4) | raise |
| bool | int32 | t0 | raise:NotImplementedError | float32(3, 4) | raise |
| bool | int64 | tt | raise:NotImplementedError | float32(3, 4) | raise |
| bool | int64 | t0 | raise:NotImplementedError | float32(3, 4) | raise |

## dist (6)
| dt1 | dt2 | form | eager | compiled | kind |
|---|---|---|---|---|---|
| bool | int32 | tt | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| bool | int32 | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| bool | int64 | tt | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| bool | int64 | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| bool | float16 | tt | raise:NotImplementedError | float16() | raise |
| bool | float16 | t0 | raise:NotImplementedError | float16() | raise |

## addcdiv (6)
| dt1 | dt2 | form | eager | compiled | kind |
|---|---|---|---|---|---|
| bool | bool | tt | raise:RuntimeError | float32(3, 4) | raise |
| bool | bool | t0 | raise:RuntimeError | float32(3, 4) | raise |
| bool | int32 | tt | raise:RuntimeError | float32(3, 4) | raise |
| bool | int32 | t0 | raise:RuntimeError | float32(3, 4) | raise |
| bool | int64 | tt | raise:RuntimeError | float32(3, 4) | raise |
| bool | int64 | t0 | raise:RuntimeError | float32(3, 4) | raise |

## index_put (6)
| dt1 | dt2 | form | eager | compiled | kind |
|---|---|---|---|---|---|
| bool | int32 | tt | raise:RuntimeError | bool(3, 4) | raise |
| bool | int32 | t0 | raise:RuntimeError | bool(3, 4) | raise |
| bool | int64 | tt | raise:RuntimeError | bool(3, 4) | raise |
| bool | int64 | t0 | raise:RuntimeError | bool(3, 4) | raise |
| bool | float16 | tt | raise:RuntimeError | bool(3, 4) | raise |
| bool | float16 | t0 | raise:RuntimeError | bool(3, 4) | raise |

## rsub (6)
| dt1 | dt2 | form | eager | compiled | kind |
|---|---|---|---|---|---|
| bool | int32 | tt | raise:NotImplementedError | int32(3, 4) | raise |
| bool | int32 | t0 | raise:NotImplementedError | int32(3, 4) | raise |
| bool | int64 | tt | raise:NotImplementedError | int64(3, 4) | raise |
| bool | int64 | t0 | raise:NotImplementedError | int64(3, 4) | raise |
| bool | float16 | tt | raise:NotImplementedError | float16(3, 4) | raise |
| bool | float16 | t0 | raise:NotImplementedError | float16(3, 4) | raise |

## softmax_dtype (6)
| dt1 | dt2 | form | eager | compiled | kind |
|---|---|---|---|---|---|
| bool | bool | tt | raise:NotImplementedError | raise:BackendCompilerFailed | raise_type |
| bool | bool | t0 | raise:NotImplementedError | raise:BackendCompilerFailed | raise_type |
| bool | int32 | tt | raise:NotImplementedError | int32(3, 4) | raise |
| bool | int32 | t0 | raise:NotImplementedError | int32(3, 4) | raise |
| bool | int64 | tt | raise:NotImplementedError | int64(3, 4) | raise |
| bool | int64 | t0 | raise:NotImplementedError | int64(3, 4) | raise |

## l1_loss (6)
| dt1 | dt2 | form | eager | compiled | kind |
|---|---|---|---|---|---|
| bool | int32 | tt | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| bool | int32 | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| bool | int64 | tt | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| bool | int64 | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| bool | float16 | tt | raise:NotImplementedError | float16() | raise |
| bool | float16 | t0 | raise:NotImplementedError | float16() | raise |

## huber_loss (6)
| dt1 | dt2 | form | eager | compiled | kind |
|---|---|---|---|---|---|
| bool | int32 | tt | raise:RuntimeError | int32() | raise |
| bool | int32 | t0 | raise:RuntimeError | int32() | raise |
| bool | int64 | tt | raise:RuntimeError | int64() | raise |
| bool | int64 | t0 | raise:RuntimeError | int64() | raise |
| bool | float16 | tt | raise:RuntimeError | float16() | raise |
| bool | float16 | t0 | raise:RuntimeError | float16() | raise |

## cosine_sim (6)
| dt1 | dt2 | form | eager | compiled | kind |
|---|---|---|---|---|---|
| bool | bool | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | bool | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | int32 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | int32 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | int64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | int64 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |

## bce_weight (6)
| dt1 | dt2 | form | eager | compiled | kind |
|---|---|---|---|---|---|
| bool | int32 | tt | raise:NotImplementedError | int32() | raise |
| bool | int32 | t0 | raise:NotImplementedError | int32() | raise |
| bool | int64 | tt | raise:NotImplementedError | int64() | raise |
| bool | int64 | t0 | raise:NotImplementedError | int64() | raise |
| bool | float16 | tt | raise:NotImplementedError | float16() | raise |
| bool | float16 | t0 | raise:NotImplementedError | float16() | raise |

## nll_weight (6)
| dt1 | dt2 | form | eager | compiled | kind |
|---|---|---|---|---|---|
| bool | int32 | tt | raise:RuntimeError | float32() | raise |
| bool | int32 | t0 | raise:RuntimeError | float32() | raise |
| bool | int64 | tt | raise:RuntimeError | float32() | raise |
| bool | int64 | t0 | raise:RuntimeError | float32() | raise |
| bool | float16 | tt | raise:RuntimeError | float16() | raise |
| bool | float16 | t0 | raise:RuntimeError | float16() | raise |

## masked_fill (5)
| dt1 | dt2 | form | eager | compiled | kind |
|---|---|---|---|---|---|
| bool | bool | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | int32 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | int64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | float16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | bfloat16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |

## logaddexp (4)
| dt1 | dt2 | form | eager | compiled | kind |
|---|---|---|---|---|---|
| bool | int32 | tt | raise:NotImplementedError | int32(3, 4) | raise |
| bool | int32 | t0 | raise:NotImplementedError | int32(3, 4) | raise |
| bool | int64 | tt | raise:NotImplementedError | int64(3, 4) | raise |
| bool | int64 | t0 | raise:NotImplementedError | int64(3, 4) | raise |

## logaddexp2 (4)
| dt1 | dt2 | form | eager | compiled | kind |
|---|---|---|---|---|---|
| bool | int32 | tt | raise:NotImplementedError | int32(3, 4) | raise |
| bool | int32 | t0 | raise:NotImplementedError | int32(3, 4) | raise |
| bool | int64 | tt | raise:NotImplementedError | int64(3, 4) | raise |
| bool | int64 | t0 | raise:NotImplementedError | int64(3, 4) | raise |

## mse_loss (4)
| dt1 | dt2 | form | eager | compiled | kind |
|---|---|---|---|---|---|
| bool | int32 | tt | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| bool | int32 | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| bool | int64 | tt | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| bool | int64 | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |

## smooth_l1_loss (4)
| dt1 | dt2 | form | eager | compiled | kind |
|---|---|---|---|---|---|
| bool | int32 | tt | raise:NotImplementedError | int32() | raise |
| bool | int32 | t0 | raise:NotImplementedError | int32() | raise |
| bool | int64 | tt | raise:NotImplementedError | int64() | raise |
| bool | int64 | t0 | raise:NotImplementedError | int64() | raise |

## div_floor (2)
| dt1 | dt2 | form | eager | compiled | kind |
|---|---|---|---|---|---|
| bool | bool | tt | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| bool | bool | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |

## floor_divide (2)
| dt1 | dt2 | form | eager | compiled | kind |
|---|---|---|---|---|---|
| bool | bool | tt | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| bool | bool | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |

## remainder (2)
| dt1 | dt2 | form | eager | compiled | kind |
|---|---|---|---|---|---|
| bool | bool | tt | raise:NotImplementedError | bool(3, 4) | raise |
| bool | bool | t0 | raise:NotImplementedError | bool(3, 4) | raise |

## fmod (2)
| dt1 | dt2 | form | eager | compiled | kind |
|---|---|---|---|---|---|
| bool | bool | tt | raise:NotImplementedError | bool(3, 4) | raise |
| bool | bool | t0 | raise:NotImplementedError | bool(3, 4) | raise |

## pow (2)
| dt1 | dt2 | form | eager | compiled | kind |
|---|---|---|---|---|---|
| bool | bool | tt | raise:NotImplementedError | bool(3, 4) | raise |
| bool | bool | t0 | raise:NotImplementedError | bool(3, 4) | raise |

## ldexp (2)
| dt1 | dt2 | form | eager | compiled | kind |
|---|---|---|---|---|---|
| bool | float16 | tt | float16(3, 4) | float32(3, 4) | dtype |
| bool | float16 | t0 | float16(3, 4) | float32(3, 4) | dtype |

## bitwise_and (2)
| dt1 | dt2 | form | eager | compiled | kind |
|---|---|---|---|---|---|
| bool | float16 | tt | raise:NotImplementedError | raise:InductorError | raise_type |
| bool | float16 | t0 | raise:NotImplementedError | raise:InductorError | raise_type |

## bitwise_xor (2)
| dt1 | dt2 | form | eager | compiled | kind |
|---|---|---|---|---|---|
| bool | float16 | tt | raise:NotImplementedError | raise:InductorError | raise_type |
| bool | float16 | t0 | raise:NotImplementedError | raise:InductorError | raise_type |

## addcmul (2)
| dt1 | dt2 | form | eager | compiled | kind |
|---|---|---|---|---|---|
| bool | bool | tt | raise:NotImplementedError | bool(3, 4) | raise |
| bool | bool | t0 | raise:NotImplementedError | bool(3, 4) | raise |

## clamp_minmax_t (2)
| dt1 | dt2 | form | eager | compiled | kind |
|---|---|---|---|---|---|
| bool | bool | tt | raise:NotImplementedError | bool(3, 4) | raise |
| bool | bool | t0 | raise:NotImplementedError | bool(3, 4) | raise |

## cumsum_dtype (2)
| dt1 | dt2 | form | eager | compiled | kind |
|---|---|---|---|---|---|
| bool | bool | tt | raise:NotImplementedError | bool(3, 4) | raise |
| bool | bool | t0 | raise:NotImplementedError | bool(3, 4) | raise |

## poisson_nll (2)
| dt1 | dt2 | form | eager | compiled | kind |
|---|---|---|---|---|---|
| bool | bool | tt | raise:NotImplementedError | float32() | raise |
| bool | bool | t0 | raise:NotImplementedError | float32() | raise |

## rms_norm_w (2)
| dt1 | dt2 | form | eager | compiled | kind |
|---|---|---|---|---|---|
| bool | bool | tt | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| bool | bool | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
