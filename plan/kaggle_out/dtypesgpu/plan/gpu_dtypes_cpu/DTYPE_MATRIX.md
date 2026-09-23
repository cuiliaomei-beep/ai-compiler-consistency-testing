# dtype-promotion matrix (inductor, pairs=lowprec, autocast=False)

- cases: 4088, mismatches: 1034 {'dtype': 42, 'raise': 555, 'raise_type': 437, 'shape': 0}; wall 2728.6 s

## heaviside (52)
| dt1 | dt2 | form | eager | compiled | kind |
|---|---|---|---|---|---|
| bool | float16 | tt | raise:RuntimeError | float16(3, 4) | raise |
| bool | float16 | t0 | raise:RuntimeError | float16(3, 4) | raise |
| bool | bfloat16 | tt | raise:RuntimeError | bfloat16(3, 4) | raise |
| bool | bfloat16 | t0 | raise:RuntimeError | bfloat16(3, 4) | raise |
| int32 | float16 | tt | raise:RuntimeError | float16(3, 4) | raise |
| int32 | float16 | t0 | raise:RuntimeError | float16(3, 4) | raise |
| int32 | bfloat16 | tt | raise:RuntimeError | bfloat16(3, 4) | raise |
| int32 | bfloat16 | t0 | raise:RuntimeError | bfloat16(3, 4) | raise |
| int64 | float16 | tt | raise:RuntimeError | float16(3, 4) | raise |
| int64 | float16 | t0 | raise:RuntimeError | float16(3, 4) | raise |
| int64 | bfloat16 | tt | raise:RuntimeError | bfloat16(3, 4) | raise |
| int64 | bfloat16 | t0 | raise:RuntimeError | bfloat16(3, 4) | raise |
| float16 | bool | tt | raise:RuntimeError | float16(3, 4) | raise |
| float16 | bool | t0 | raise:RuntimeError | float16(3, 4) | raise |
| float16 | int32 | tt | raise:RuntimeError | float16(3, 4) | raise |
| float16 | int32 | t0 | raise:RuntimeError | float16(3, 4) | raise |
| float16 | int64 | tt | raise:RuntimeError | float16(3, 4) | raise |
| float16 | int64 | t0 | raise:RuntimeError | float16(3, 4) | raise |
| float16 | bfloat16 | tt | raise:RuntimeError | float32(3, 4) | raise |
| float16 | bfloat16 | t0 | raise:RuntimeError | float16(3, 4) | raise |
| float16 | float32 | tt | raise:RuntimeError | float32(3, 4) | raise |
| float16 | float32 | t0 | raise:RuntimeError | float16(3, 4) | raise |
| float16 | float64 | tt | raise:RuntimeError | float64(3, 4) | raise |
| float16 | float64 | t0 | raise:RuntimeError | float16(3, 4) | raise |
| float16 | complex64 | tt | raise:RuntimeError | raise:NotImplementedError | raise_type |
| float16 | complex64 | t0 | raise:RuntimeError | raise:NotImplementedError | raise_type |
| bfloat16 | bool | tt | raise:RuntimeError | bfloat16(3, 4) | raise |
| bfloat16 | bool | t0 | raise:RuntimeError | bfloat16(3, 4) | raise |
| bfloat16 | int32 | tt | raise:RuntimeError | bfloat16(3, 4) | raise |
| bfloat16 | int32 | t0 | raise:RuntimeError | bfloat16(3, 4) | raise |
| bfloat16 | int64 | tt | raise:RuntimeError | bfloat16(3, 4) | raise |
| bfloat16 | int64 | t0 | raise:RuntimeError | bfloat16(3, 4) | raise |
| bfloat16 | float16 | tt | raise:RuntimeError | float32(3, 4) | raise |
| bfloat16 | float16 | t0 | raise:RuntimeError | bfloat16(3, 4) | raise |
| bfloat16 | float32 | tt | raise:RuntimeError | float32(3, 4) | raise |
| bfloat16 | float32 | t0 | raise:RuntimeError | bfloat16(3, 4) | raise |
| bfloat16 | float64 | tt | raise:RuntimeError | float64(3, 4) | raise |
| bfloat16 | float64 | t0 | raise:RuntimeError | bfloat16(3, 4) | raise |
| bfloat16 | complex64 | tt | raise:RuntimeError | raise:NotImplementedError | raise_type |
| bfloat16 | complex64 | t0 | raise:RuntimeError | raise:NotImplementedError | raise_type |
| float32 | float16 | tt | raise:RuntimeError | float32(3, 4) | raise |
| float32 | float16 | t0 | raise:RuntimeError | float32(3, 4) | raise |
| float32 | bfloat16 | tt | raise:RuntimeError | float32(3, 4) | raise |
| float32 | bfloat16 | t0 | raise:RuntimeError | float32(3, 4) | raise |
| float64 | float16 | tt | raise:RuntimeError | float64(3, 4) | raise |
| float64 | float16 | t0 | raise:RuntimeError | float64(3, 4) | raise |
| float64 | bfloat16 | tt | raise:RuntimeError | float64(3, 4) | raise |
| float64 | bfloat16 | t0 | raise:RuntimeError | float64(3, 4) | raise |
| complex64 | float16 | tt | raise:RuntimeError | raise:NotImplementedError | raise_type |
| complex64 | float16 | t0 | raise:RuntimeError | raise:NotImplementedError | raise_type |
| complex64 | bfloat16 | tt | raise:RuntimeError | raise:NotImplementedError | raise_type |
| complex64 | bfloat16 | t0 | raise:RuntimeError | raise:NotImplementedError | raise_type |

## lerp (52)
| dt1 | dt2 | form | eager | compiled | kind |
|---|---|---|---|---|---|
| bool | float16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | float16 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | bfloat16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | bfloat16 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | float16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | float16 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | bfloat16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | bfloat16 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | float16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | float16 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | bfloat16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | bfloat16 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
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
| bfloat16 | float32 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bfloat16 | float32 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bfloat16 | float64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bfloat16 | float64 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bfloat16 | complex64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bfloat16 | complex64 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float32 | float16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float32 | float16 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float32 | bfloat16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float32 | bfloat16 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float64 | float16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float64 | float16 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float64 | bfloat16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float64 | bfloat16 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| complex64 | float16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| complex64 | float16 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| complex64 | bfloat16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| complex64 | bfloat16 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |

## scatter_add (52)
| dt1 | dt2 | form | eager | compiled | kind |
|---|---|---|---|---|---|
| bool | float16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | float16 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | bfloat16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | bfloat16 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | float16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | float16 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | bfloat16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | bfloat16 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | float16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | float16 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | bfloat16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | bfloat16 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
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
| bfloat16 | float32 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bfloat16 | float32 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bfloat16 | float64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bfloat16 | float64 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bfloat16 | complex64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bfloat16 | complex64 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float32 | float16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float32 | float16 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float32 | bfloat16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float32 | bfloat16 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float64 | float16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float64 | float16 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float64 | bfloat16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float64 | bfloat16 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| complex64 | float16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| complex64 | float16 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| complex64 | bfloat16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| complex64 | bfloat16 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |

## nll_weight (52)
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
| float16 | bool | tt | raise:RuntimeError | float16() | raise |
| float16 | bool | t0 | raise:RuntimeError | float16() | raise |
| float16 | int32 | tt | raise:RuntimeError | float16() | raise |
| float16 | int32 | t0 | raise:RuntimeError | float16() | raise |
| float16 | int64 | tt | raise:RuntimeError | float16() | raise |
| float16 | int64 | t0 | raise:RuntimeError | float16() | raise |
| float16 | bfloat16 | tt | raise:RuntimeError | float32() | raise |
| float16 | bfloat16 | t0 | raise:RuntimeError | float32() | raise |
| float16 | float32 | tt | raise:RuntimeError | float32() | raise |
| float16 | float32 | t0 | raise:RuntimeError | float32() | raise |
| float16 | float64 | tt | raise:RuntimeError | float64() | raise |
| float16 | float64 | t0 | raise:RuntimeError | float64() | raise |
| float16 | complex64 | tt | raise:RuntimeError | complex64() | raise |
| float16 | complex64 | t0 | raise:RuntimeError | complex64() | raise |
| bfloat16 | bool | tt | raise:RuntimeError | bfloat16() | raise |
| bfloat16 | bool | t0 | raise:RuntimeError | bfloat16() | raise |
| bfloat16 | int32 | tt | raise:RuntimeError | bfloat16() | raise |
| bfloat16 | int32 | t0 | raise:RuntimeError | bfloat16() | raise |
| bfloat16 | int64 | tt | raise:RuntimeError | bfloat16() | raise |
| bfloat16 | int64 | t0 | raise:RuntimeError | bfloat16() | raise |
| bfloat16 | float16 | tt | raise:RuntimeError | float32() | raise |
| bfloat16 | float16 | t0 | raise:RuntimeError | float32() | raise |
| bfloat16 | float32 | tt | raise:RuntimeError | float32() | raise |
| bfloat16 | float32 | t0 | raise:RuntimeError | float32() | raise |
| bfloat16 | float64 | tt | raise:RuntimeError | float64() | raise |
| bfloat16 | float64 | t0 | raise:RuntimeError | float64() | raise |
| bfloat16 | complex64 | tt | raise:RuntimeError | complex64() | raise |
| bfloat16 | complex64 | t0 | raise:RuntimeError | complex64() | raise |
| float32 | float16 | tt | raise:RuntimeError | float32() | raise |
| float32 | float16 | t0 | raise:RuntimeError | float32() | raise |
| float32 | bfloat16 | tt | raise:RuntimeError | float32() | raise |
| float32 | bfloat16 | t0 | raise:RuntimeError | float32() | raise |
| float64 | float16 | tt | raise:RuntimeError | float64() | raise |
| float64 | float16 | t0 | raise:RuntimeError | float64() | raise |
| float64 | bfloat16 | tt | raise:RuntimeError | float64() | raise |
| float64 | bfloat16 | t0 | raise:RuntimeError | float64() | raise |
| complex64 | float16 | tt | raise:NotImplementedError | complex64() | raise |
| complex64 | float16 | t0 | raise:NotImplementedError | complex64() | raise |
| complex64 | bfloat16 | tt | raise:NotImplementedError | complex64() | raise |
| complex64 | bfloat16 | t0 | raise:NotImplementedError | complex64() | raise |

## multilabel_soft_margin_w (52)
| dt1 | dt2 | form | eager | compiled | kind |
|---|---|---|---|---|---|
| int32 | float16 | tt | raise:NotImplementedError | float16() | raise |
| int32 | float16 | t0 | raise:NotImplementedError | float16() | raise |
| int32 | bfloat16 | tt | raise:NotImplementedError | bfloat16() | raise |
| int32 | bfloat16 | t0 | raise:NotImplementedError | bfloat16() | raise |
| int64 | float16 | tt | raise:NotImplementedError | float16() | raise |
| int64 | float16 | t0 | raise:NotImplementedError | float16() | raise |
| int64 | bfloat16 | tt | raise:NotImplementedError | bfloat16() | raise |
| int64 | bfloat16 | t0 | raise:NotImplementedError | bfloat16() | raise |
| float16 | bool | tt | raise:NotImplementedError | float16() | raise |
| float16 | bool | t0 | raise:NotImplementedError | float16() | raise |
| float16 | int32 | tt | raise:NotImplementedError | float16() | raise |
| float16 | int32 | t0 | raise:NotImplementedError | float16() | raise |
| float16 | int64 | tt | raise:NotImplementedError | float16() | raise |
| float16 | int64 | t0 | raise:NotImplementedError | float16() | raise |
| float16 | float16 | tt | raise:NotImplementedError | float16() | raise |
| float16 | float16 | t0 | raise:NotImplementedError | float16() | raise |
| float16 | bfloat16 | tt | raise:NotImplementedError | float32() | raise |
| float16 | bfloat16 | t0 | raise:NotImplementedError | float32() | raise |
| float16 | float32 | tt | raise:NotImplementedError | float32() | raise |
| float16 | float32 | t0 | raise:NotImplementedError | float32() | raise |
| float16 | float64 | tt | raise:NotImplementedError | float64() | raise |
| float16 | float64 | t0 | raise:NotImplementedError | float64() | raise |
| float16 | complex64 | tt | raise:NotImplementedError | complex64() | raise |
| float16 | complex64 | t0 | raise:NotImplementedError | complex64() | raise |
| bfloat16 | bool | tt | raise:NotImplementedError | bfloat16() | raise |
| bfloat16 | bool | t0 | raise:NotImplementedError | bfloat16() | raise |
| bfloat16 | int32 | tt | raise:NotImplementedError | bfloat16() | raise |
| bfloat16 | int32 | t0 | raise:NotImplementedError | bfloat16() | raise |
| bfloat16 | int64 | tt | raise:NotImplementedError | bfloat16() | raise |
| bfloat16 | int64 | t0 | raise:NotImplementedError | bfloat16() | raise |
| bfloat16 | float16 | tt | raise:NotImplementedError | float32() | raise |
| bfloat16 | float16 | t0 | raise:NotImplementedError | float32() | raise |
| bfloat16 | bfloat16 | tt | raise:NotImplementedError | bfloat16() | raise |
| bfloat16 | bfloat16 | t0 | raise:NotImplementedError | bfloat16() | raise |
| bfloat16 | float32 | tt | raise:NotImplementedError | float32() | raise |
| bfloat16 | float32 | t0 | raise:NotImplementedError | float32() | raise |
| bfloat16 | float64 | tt | raise:NotImplementedError | float64() | raise |
| bfloat16 | float64 | t0 | raise:NotImplementedError | float64() | raise |
| bfloat16 | complex64 | tt | raise:NotImplementedError | complex64() | raise |
| bfloat16 | complex64 | t0 | raise:NotImplementedError | complex64() | raise |
| float32 | float16 | tt | raise:NotImplementedError | float32() | raise |
| float32 | float16 | t0 | raise:NotImplementedError | float32() | raise |
| float32 | bfloat16 | tt | raise:NotImplementedError | float32() | raise |
| float32 | bfloat16 | t0 | raise:NotImplementedError | float32() | raise |
| float64 | float16 | tt | raise:NotImplementedError | float64() | raise |
| float64 | float16 | t0 | raise:NotImplementedError | float64() | raise |
| float64 | bfloat16 | tt | raise:NotImplementedError | float64() | raise |
| float64 | bfloat16 | t0 | raise:NotImplementedError | float64() | raise |
| complex64 | float16 | tt | raise:NotImplementedError | raise:RuntimeError | raise_type |
| complex64 | float16 | t0 | raise:NotImplementedError | raise:RuntimeError | raise_type |
| complex64 | bfloat16 | tt | raise:NotImplementedError | raise:RuntimeError | raise_type |
| complex64 | bfloat16 | t0 | raise:NotImplementedError | raise:RuntimeError | raise_type |

## prelu_w (52)
| dt1 | dt2 | form | eager | compiled | kind |
|---|---|---|---|---|---|
| bool | float16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | float16 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | bfloat16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | bfloat16 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | float16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | float16 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | bfloat16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | bfloat16 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | float16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | float16 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | bfloat16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | bfloat16 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
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
| bfloat16 | float32 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bfloat16 | float32 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bfloat16 | float64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bfloat16 | float64 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bfloat16 | complex64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bfloat16 | complex64 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float32 | float16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float32 | float16 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float32 | bfloat16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float32 | bfloat16 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float64 | float16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float64 | float16 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float64 | bfloat16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float64 | bfloat16 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| complex64 | float16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| complex64 | float16 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| complex64 | bfloat16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| complex64 | bfloat16 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |

## bitwise_and (48)
| dt1 | dt2 | form | eager | compiled | kind |
|---|---|---|---|---|---|
| bool | float16 | tt | raise:NotImplementedError | float16(3, 4) | raise |
| bool | float16 | t0 | raise:NotImplementedError | float16(3, 4) | raise |
| bool | bfloat16 | tt | raise:NotImplementedError | bfloat16(3, 4) | raise |
| bool | bfloat16 | t0 | raise:NotImplementedError | bfloat16(3, 4) | raise |
| int32 | float16 | tt | raise:NotImplementedError | float16(3, 4) | raise |
| int32 | float16 | t0 | raise:NotImplementedError | float16(3, 4) | raise |
| int32 | bfloat16 | tt | raise:NotImplementedError | bfloat16(3, 4) | raise |
| int32 | bfloat16 | t0 | raise:NotImplementedError | bfloat16(3, 4) | raise |
| int64 | float16 | tt | raise:NotImplementedError | float16(3, 4) | raise |
| int64 | float16 | t0 | raise:NotImplementedError | float16(3, 4) | raise |
| int64 | bfloat16 | tt | raise:NotImplementedError | bfloat16(3, 4) | raise |
| int64 | bfloat16 | t0 | raise:NotImplementedError | bfloat16(3, 4) | raise |
| float16 | bool | tt | raise:NotImplementedError | float16(3, 4) | raise |
| float16 | bool | t0 | raise:NotImplementedError | float16(3, 4) | raise |
| float16 | int32 | tt | raise:NotImplementedError | float16(3, 4) | raise |
| float16 | int32 | t0 | raise:NotImplementedError | float16(3, 4) | raise |
| float16 | int64 | tt | raise:NotImplementedError | float16(3, 4) | raise |
| float16 | int64 | t0 | raise:NotImplementedError | float16(3, 4) | raise |
| float16 | float16 | tt | raise:NotImplementedError | float16(3, 4) | raise |
| float16 | float16 | t0 | raise:NotImplementedError | float16(3, 4) | raise |
| float16 | bfloat16 | tt | raise:NotImplementedError | float32(3, 4) | raise |
| float16 | bfloat16 | t0 | raise:NotImplementedError | float16(3, 4) | raise |
| float16 | float32 | tt | raise:NotImplementedError | float32(3, 4) | raise |
| float16 | float32 | t0 | raise:NotImplementedError | float16(3, 4) | raise |
| float16 | float64 | tt | raise:NotImplementedError | float64(3, 4) | raise |
| float16 | float64 | t0 | raise:NotImplementedError | float16(3, 4) | raise |
| bfloat16 | bool | tt | raise:NotImplementedError | bfloat16(3, 4) | raise |
| bfloat16 | bool | t0 | raise:NotImplementedError | bfloat16(3, 4) | raise |
| bfloat16 | int32 | tt | raise:NotImplementedError | bfloat16(3, 4) | raise |
| bfloat16 | int32 | t0 | raise:NotImplementedError | bfloat16(3, 4) | raise |
| bfloat16 | int64 | tt | raise:NotImplementedError | bfloat16(3, 4) | raise |
| bfloat16 | int64 | t0 | raise:NotImplementedError | bfloat16(3, 4) | raise |
| bfloat16 | float16 | tt | raise:NotImplementedError | float32(3, 4) | raise |
| bfloat16 | float16 | t0 | raise:NotImplementedError | bfloat16(3, 4) | raise |
| bfloat16 | bfloat16 | tt | raise:NotImplementedError | bfloat16(3, 4) | raise |
| bfloat16 | bfloat16 | t0 | raise:NotImplementedError | bfloat16(3, 4) | raise |
| bfloat16 | float32 | tt | raise:NotImplementedError | float32(3, 4) | raise |
| bfloat16 | float32 | t0 | raise:NotImplementedError | bfloat16(3, 4) | raise |
| bfloat16 | float64 | tt | raise:NotImplementedError | float64(3, 4) | raise |
| bfloat16 | float64 | t0 | raise:NotImplementedError | bfloat16(3, 4) | raise |
| float32 | float16 | tt | raise:NotImplementedError | float32(3, 4) | raise |
| float32 | float16 | t0 | raise:NotImplementedError | float32(3, 4) | raise |
| float32 | bfloat16 | tt | raise:NotImplementedError | float32(3, 4) | raise |
| float32 | bfloat16 | t0 | raise:NotImplementedError | float32(3, 4) | raise |
| float64 | float16 | tt | raise:NotImplementedError | float64(3, 4) | raise |
| float64 | float16 | t0 | raise:NotImplementedError | float64(3, 4) | raise |
| float64 | bfloat16 | tt | raise:NotImplementedError | float64(3, 4) | raise |
| float64 | bfloat16 | t0 | raise:NotImplementedError | float64(3, 4) | raise |

## bitwise_xor (48)
| dt1 | dt2 | form | eager | compiled | kind |
|---|---|---|---|---|---|
| bool | float16 | tt | raise:NotImplementedError | float16(3, 4) | raise |
| bool | float16 | t0 | raise:NotImplementedError | float16(3, 4) | raise |
| bool | bfloat16 | tt | raise:NotImplementedError | bfloat16(3, 4) | raise |
| bool | bfloat16 | t0 | raise:NotImplementedError | bfloat16(3, 4) | raise |
| int32 | float16 | tt | raise:NotImplementedError | float16(3, 4) | raise |
| int32 | float16 | t0 | raise:NotImplementedError | float16(3, 4) | raise |
| int32 | bfloat16 | tt | raise:NotImplementedError | bfloat16(3, 4) | raise |
| int32 | bfloat16 | t0 | raise:NotImplementedError | bfloat16(3, 4) | raise |
| int64 | float16 | tt | raise:NotImplementedError | float16(3, 4) | raise |
| int64 | float16 | t0 | raise:NotImplementedError | float16(3, 4) | raise |
| int64 | bfloat16 | tt | raise:NotImplementedError | bfloat16(3, 4) | raise |
| int64 | bfloat16 | t0 | raise:NotImplementedError | bfloat16(3, 4) | raise |
| float16 | bool | tt | raise:NotImplementedError | float16(3, 4) | raise |
| float16 | bool | t0 | raise:NotImplementedError | float16(3, 4) | raise |
| float16 | int32 | tt | raise:NotImplementedError | float16(3, 4) | raise |
| float16 | int32 | t0 | raise:NotImplementedError | float16(3, 4) | raise |
| float16 | int64 | tt | raise:NotImplementedError | float16(3, 4) | raise |
| float16 | int64 | t0 | raise:NotImplementedError | float16(3, 4) | raise |
| float16 | float16 | tt | raise:NotImplementedError | float16(3, 4) | raise |
| float16 | float16 | t0 | raise:NotImplementedError | float16(3, 4) | raise |
| float16 | bfloat16 | tt | raise:NotImplementedError | float32(3, 4) | raise |
| float16 | bfloat16 | t0 | raise:NotImplementedError | float16(3, 4) | raise |
| float16 | float32 | tt | raise:NotImplementedError | float32(3, 4) | raise |
| float16 | float32 | t0 | raise:NotImplementedError | float16(3, 4) | raise |
| float16 | float64 | tt | raise:NotImplementedError | float64(3, 4) | raise |
| float16 | float64 | t0 | raise:NotImplementedError | float16(3, 4) | raise |
| bfloat16 | bool | tt | raise:NotImplementedError | bfloat16(3, 4) | raise |
| bfloat16 | bool | t0 | raise:NotImplementedError | bfloat16(3, 4) | raise |
| bfloat16 | int32 | tt | raise:NotImplementedError | bfloat16(3, 4) | raise |
| bfloat16 | int32 | t0 | raise:NotImplementedError | bfloat16(3, 4) | raise |
| bfloat16 | int64 | tt | raise:NotImplementedError | bfloat16(3, 4) | raise |
| bfloat16 | int64 | t0 | raise:NotImplementedError | bfloat16(3, 4) | raise |
| bfloat16 | float16 | tt | raise:NotImplementedError | float32(3, 4) | raise |
| bfloat16 | float16 | t0 | raise:NotImplementedError | bfloat16(3, 4) | raise |
| bfloat16 | bfloat16 | tt | raise:NotImplementedError | bfloat16(3, 4) | raise |
| bfloat16 | bfloat16 | t0 | raise:NotImplementedError | bfloat16(3, 4) | raise |
| bfloat16 | float32 | tt | raise:NotImplementedError | float32(3, 4) | raise |
| bfloat16 | float32 | t0 | raise:NotImplementedError | bfloat16(3, 4) | raise |
| bfloat16 | float64 | tt | raise:NotImplementedError | float64(3, 4) | raise |
| bfloat16 | float64 | t0 | raise:NotImplementedError | bfloat16(3, 4) | raise |
| float32 | float16 | tt | raise:NotImplementedError | float32(3, 4) | raise |
| float32 | float16 | t0 | raise:NotImplementedError | float32(3, 4) | raise |
| float32 | bfloat16 | tt | raise:NotImplementedError | float32(3, 4) | raise |
| float32 | bfloat16 | t0 | raise:NotImplementedError | float32(3, 4) | raise |
| float64 | float16 | tt | raise:NotImplementedError | float64(3, 4) | raise |
| float64 | float16 | t0 | raise:NotImplementedError | float64(3, 4) | raise |
| float64 | bfloat16 | tt | raise:NotImplementedError | float64(3, 4) | raise |
| float64 | bfloat16 | t0 | raise:NotImplementedError | float64(3, 4) | raise |

## layer_norm_w (48)
| dt1 | dt2 | form | eager | compiled | kind |
|---|---|---|---|---|---|
| bool | float16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | float16 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | bfloat16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | bfloat16 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | float16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | float16 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | bfloat16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | bfloat16 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | float16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | float16 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | bfloat16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | bfloat16 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float16 | bool | tt | raise:RuntimeError | float16(3, 4) | raise |
| float16 | bool | t0 | raise:RuntimeError | float16(3, 4) | raise |
| float16 | int32 | tt | raise:RuntimeError | float16(3, 4) | raise |
| float16 | int32 | t0 | raise:RuntimeError | float16(3, 4) | raise |
| float16 | int64 | tt | raise:RuntimeError | float16(3, 4) | raise |
| float16 | int64 | t0 | raise:RuntimeError | float16(3, 4) | raise |
| float16 | bfloat16 | tt | raise:RuntimeError | float16(3, 4) | raise |
| float16 | bfloat16 | t0 | raise:RuntimeError | float16(3, 4) | raise |
| float16 | float64 | tt | raise:RuntimeError | float16(3, 4) | raise |
| float16 | float64 | t0 | raise:RuntimeError | float16(3, 4) | raise |
| float16 | complex64 | tt | raise:RuntimeError | float16(3, 4) | raise |
| float16 | complex64 | t0 | raise:RuntimeError | float16(3, 4) | raise |
| bfloat16 | bool | tt | raise:RuntimeError | bfloat16(3, 4) | raise |
| bfloat16 | bool | t0 | raise:RuntimeError | bfloat16(3, 4) | raise |
| bfloat16 | int32 | tt | raise:RuntimeError | bfloat16(3, 4) | raise |
| bfloat16 | int32 | t0 | raise:RuntimeError | bfloat16(3, 4) | raise |
| bfloat16 | int64 | tt | raise:RuntimeError | bfloat16(3, 4) | raise |
| bfloat16 | int64 | t0 | raise:RuntimeError | bfloat16(3, 4) | raise |
| bfloat16 | float16 | tt | raise:RuntimeError | bfloat16(3, 4) | raise |
| bfloat16 | float16 | t0 | raise:RuntimeError | bfloat16(3, 4) | raise |
| bfloat16 | float64 | tt | raise:RuntimeError | bfloat16(3, 4) | raise |
| bfloat16 | float64 | t0 | raise:RuntimeError | bfloat16(3, 4) | raise |
| bfloat16 | complex64 | tt | raise:RuntimeError | bfloat16(3, 4) | raise |
| bfloat16 | complex64 | t0 | raise:RuntimeError | bfloat16(3, 4) | raise |
| float32 | float16 | tt | raise:RuntimeError | float32(3, 4) | raise |
| float32 | float16 | t0 | raise:RuntimeError | float32(3, 4) | raise |
| float32 | bfloat16 | tt | raise:RuntimeError | float32(3, 4) | raise |
| float32 | bfloat16 | t0 | raise:RuntimeError | float32(3, 4) | raise |
| float64 | float16 | tt | raise:RuntimeError | float64(3, 4) | raise |
| float64 | float16 | t0 | raise:RuntimeError | float64(3, 4) | raise |
| float64 | bfloat16 | tt | raise:RuntimeError | float64(3, 4) | raise |
| float64 | bfloat16 | t0 | raise:RuntimeError | float64(3, 4) | raise |
| complex64 | float16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| complex64 | float16 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| complex64 | bfloat16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| complex64 | bfloat16 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |

## group_norm_w (48)
| dt1 | dt2 | form | eager | compiled | kind |
|---|---|---|---|---|---|
| bool | float16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | float16 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | bfloat16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | bfloat16 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | float16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | float16 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | bfloat16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | bfloat16 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | float16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | float16 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | bfloat16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | bfloat16 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float16 | bool | tt | raise:RuntimeError | float16(3, 4, 1) | raise |
| float16 | bool | t0 | raise:RuntimeError | float16(3, 4, 1) | raise |
| float16 | int32 | tt | raise:RuntimeError | float16(3, 4, 1) | raise |
| float16 | int32 | t0 | raise:RuntimeError | float16(3, 4, 1) | raise |
| float16 | int64 | tt | raise:RuntimeError | float16(3, 4, 1) | raise |
| float16 | int64 | t0 | raise:RuntimeError | float16(3, 4, 1) | raise |
| float16 | bfloat16 | tt | raise:RuntimeError | float16(3, 4, 1) | raise |
| float16 | bfloat16 | t0 | raise:RuntimeError | float16(3, 4, 1) | raise |
| float16 | float64 | tt | raise:RuntimeError | float16(3, 4, 1) | raise |
| float16 | float64 | t0 | raise:RuntimeError | float16(3, 4, 1) | raise |
| float16 | complex64 | tt | raise:RuntimeError | float16(3, 4, 1) | raise |
| float16 | complex64 | t0 | raise:RuntimeError | float16(3, 4, 1) | raise |
| bfloat16 | bool | tt | raise:RuntimeError | bfloat16(3, 4, 1) | raise |
| bfloat16 | bool | t0 | raise:RuntimeError | bfloat16(3, 4, 1) | raise |
| bfloat16 | int32 | tt | raise:RuntimeError | bfloat16(3, 4, 1) | raise |
| bfloat16 | int32 | t0 | raise:RuntimeError | bfloat16(3, 4, 1) | raise |
| bfloat16 | int64 | tt | raise:RuntimeError | bfloat16(3, 4, 1) | raise |
| bfloat16 | int64 | t0 | raise:RuntimeError | bfloat16(3, 4, 1) | raise |
| bfloat16 | float16 | tt | raise:RuntimeError | bfloat16(3, 4, 1) | raise |
| bfloat16 | float16 | t0 | raise:RuntimeError | bfloat16(3, 4, 1) | raise |
| bfloat16 | float64 | tt | raise:RuntimeError | bfloat16(3, 4, 1) | raise |
| bfloat16 | float64 | t0 | raise:RuntimeError | bfloat16(3, 4, 1) | raise |
| bfloat16 | complex64 | tt | raise:RuntimeError | bfloat16(3, 4, 1) | raise |
| bfloat16 | complex64 | t0 | raise:RuntimeError | bfloat16(3, 4, 1) | raise |
| float32 | float16 | tt | raise:RuntimeError | float32(3, 4, 1) | raise |
| float32 | float16 | t0 | raise:RuntimeError | float32(3, 4, 1) | raise |
| float32 | bfloat16 | tt | raise:RuntimeError | float32(3, 4, 1) | raise |
| float32 | bfloat16 | t0 | raise:RuntimeError | float32(3, 4, 1) | raise |
| float64 | float16 | tt | raise:RuntimeError | float64(3, 4, 1) | raise |
| float64 | float16 | t0 | raise:RuntimeError | float64(3, 4, 1) | raise |
| float64 | bfloat16 | tt | raise:RuntimeError | float64(3, 4, 1) | raise |
| float64 | bfloat16 | t0 | raise:RuntimeError | float64(3, 4, 1) | raise |
| complex64 | float16 | tt | raise:RuntimeError | complex64(3, 4, 1) | raise |
| complex64 | float16 | t0 | raise:RuntimeError | complex64(3, 4, 1) | raise |
| complex64 | bfloat16 | tt | raise:RuntimeError | complex64(3, 4, 1) | raise |
| complex64 | bfloat16 | t0 | raise:RuntimeError | complex64(3, 4, 1) | raise |

## batch_norm_w (48)
| dt1 | dt2 | form | eager | compiled | kind |
|---|---|---|---|---|---|
| bool | float16 | tt | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| bool | float16 | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| bool | bfloat16 | tt | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| bool | bfloat16 | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int32 | float16 | tt | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int32 | float16 | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int32 | bfloat16 | tt | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int32 | bfloat16 | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int64 | float16 | tt | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int64 | float16 | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int64 | bfloat16 | tt | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int64 | bfloat16 | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| float16 | bool | tt | raise:RuntimeError | float16(3, 4) | raise |
| float16 | bool | t0 | raise:RuntimeError | float16(3, 4) | raise |
| float16 | int32 | tt | raise:RuntimeError | float16(3, 4) | raise |
| float16 | int32 | t0 | raise:RuntimeError | float16(3, 4) | raise |
| float16 | int64 | tt | raise:RuntimeError | float16(3, 4) | raise |
| float16 | int64 | t0 | raise:RuntimeError | float16(3, 4) | raise |
| float16 | bfloat16 | tt | raise:RuntimeError | float16(3, 4) | raise |
| float16 | bfloat16 | t0 | raise:RuntimeError | float16(3, 4) | raise |
| float16 | float64 | tt | raise:RuntimeError | float16(3, 4) | raise |
| float16 | float64 | t0 | raise:RuntimeError | float16(3, 4) | raise |
| float16 | complex64 | tt | raise:RuntimeError | float16(3, 4) | raise |
| float16 | complex64 | t0 | raise:RuntimeError | float16(3, 4) | raise |
| bfloat16 | bool | tt | raise:RuntimeError | bfloat16(3, 4) | raise |
| bfloat16 | bool | t0 | raise:RuntimeError | bfloat16(3, 4) | raise |
| bfloat16 | int32 | tt | raise:RuntimeError | bfloat16(3, 4) | raise |
| bfloat16 | int32 | t0 | raise:RuntimeError | bfloat16(3, 4) | raise |
| bfloat16 | int64 | tt | raise:RuntimeError | bfloat16(3, 4) | raise |
| bfloat16 | int64 | t0 | raise:RuntimeError | bfloat16(3, 4) | raise |
| bfloat16 | float16 | tt | raise:RuntimeError | bfloat16(3, 4) | raise |
| bfloat16 | float16 | t0 | raise:RuntimeError | bfloat16(3, 4) | raise |
| bfloat16 | float64 | tt | raise:RuntimeError | bfloat16(3, 4) | raise |
| bfloat16 | float64 | t0 | raise:RuntimeError | bfloat16(3, 4) | raise |
| bfloat16 | complex64 | tt | raise:RuntimeError | bfloat16(3, 4) | raise |
| bfloat16 | complex64 | t0 | raise:RuntimeError | bfloat16(3, 4) | raise |
| float32 | float16 | tt | raise:RuntimeError | float32(3, 4) | raise |
| float32 | float16 | t0 | raise:RuntimeError | float32(3, 4) | raise |
| float32 | bfloat16 | tt | raise:RuntimeError | float32(3, 4) | raise |
| float32 | bfloat16 | t0 | raise:RuntimeError | float32(3, 4) | raise |
| float64 | float16 | tt | raise:RuntimeError | float64(3, 4) | raise |
| float64 | float16 | t0 | raise:RuntimeError | float64(3, 4) | raise |
| float64 | bfloat16 | tt | raise:RuntimeError | float64(3, 4) | raise |
| float64 | bfloat16 | t0 | raise:RuntimeError | float64(3, 4) | raise |
| complex64 | float16 | tt | raise:NotImplementedError | complex64(3, 4) | raise |
| complex64 | float16 | t0 | raise:NotImplementedError | complex64(3, 4) | raise |
| complex64 | bfloat16 | tt | raise:NotImplementedError | complex64(3, 4) | raise |
| complex64 | bfloat16 | t0 | raise:NotImplementedError | complex64(3, 4) | raise |

## index_put (44)
| dt1 | dt2 | form | eager | compiled | kind |
|---|---|---|---|---|---|
| bool | float16 | tt | raise:RuntimeError | bool(3, 4) | raise |
| bool | float16 | t0 | raise:RuntimeError | bool(3, 4) | raise |
| bool | bfloat16 | tt | raise:RuntimeError | bool(3, 4) | raise |
| bool | bfloat16 | t0 | raise:RuntimeError | bool(3, 4) | raise |
| int32 | float16 | tt | raise:RuntimeError | int32(3, 4) | raise |
| int32 | float16 | t0 | raise:RuntimeError | int32(3, 4) | raise |
| int32 | bfloat16 | tt | raise:RuntimeError | int32(3, 4) | raise |
| int32 | bfloat16 | t0 | raise:RuntimeError | int32(3, 4) | raise |
| int64 | float16 | tt | raise:RuntimeError | int64(3, 4) | raise |
| int64 | float16 | t0 | raise:RuntimeError | int64(3, 4) | raise |
| int64 | bfloat16 | tt | raise:RuntimeError | int64(3, 4) | raise |
| int64 | bfloat16 | t0 | raise:RuntimeError | int64(3, 4) | raise |
| float16 | bool | tt | raise:RuntimeError | float16(3, 4) | raise |
| float16 | bool | t0 | raise:RuntimeError | float16(3, 4) | raise |
| float16 | int32 | tt | raise:RuntimeError | float16(3, 4) | raise |
| float16 | int32 | t0 | raise:RuntimeError | float16(3, 4) | raise |
| float16 | int64 | tt | raise:RuntimeError | float16(3, 4) | raise |
| float16 | int64 | t0 | raise:RuntimeError | float16(3, 4) | raise |
| float16 | bfloat16 | tt | raise:RuntimeError | float16(3, 4) | raise |
| float16 | bfloat16 | t0 | raise:RuntimeError | float16(3, 4) | raise |
| float16 | float32 | tt | raise:RuntimeError | float16(3, 4) | raise |
| float16 | float32 | t0 | raise:RuntimeError | float16(3, 4) | raise |
| float16 | float64 | tt | raise:RuntimeError | float16(3, 4) | raise |
| float16 | float64 | t0 | raise:RuntimeError | float16(3, 4) | raise |
| bfloat16 | bool | tt | raise:RuntimeError | bfloat16(3, 4) | raise |
| bfloat16 | bool | t0 | raise:RuntimeError | bfloat16(3, 4) | raise |
| bfloat16 | int32 | tt | raise:RuntimeError | bfloat16(3, 4) | raise |
| bfloat16 | int32 | t0 | raise:RuntimeError | bfloat16(3, 4) | raise |
| bfloat16 | int64 | tt | raise:RuntimeError | bfloat16(3, 4) | raise |
| bfloat16 | int64 | t0 | raise:RuntimeError | bfloat16(3, 4) | raise |
| bfloat16 | float16 | tt | raise:RuntimeError | bfloat16(3, 4) | raise |
| bfloat16 | float16 | t0 | raise:RuntimeError | bfloat16(3, 4) | raise |
| bfloat16 | float32 | tt | raise:RuntimeError | bfloat16(3, 4) | raise |
| bfloat16 | float32 | t0 | raise:RuntimeError | bfloat16(3, 4) | raise |
| bfloat16 | float64 | tt | raise:RuntimeError | bfloat16(3, 4) | raise |
| bfloat16 | float64 | t0 | raise:RuntimeError | bfloat16(3, 4) | raise |
| float32 | float16 | tt | raise:RuntimeError | float32(3, 4) | raise |
| float32 | float16 | t0 | raise:RuntimeError | float32(3, 4) | raise |
| float32 | bfloat16 | tt | raise:RuntimeError | float32(3, 4) | raise |
| float32 | bfloat16 | t0 | raise:RuntimeError | float32(3, 4) | raise |
| float64 | float16 | tt | raise:RuntimeError | float64(3, 4) | raise |
| float64 | float16 | t0 | raise:RuntimeError | float64(3, 4) | raise |
| float64 | bfloat16 | tt | raise:RuntimeError | float64(3, 4) | raise |
| float64 | bfloat16 | t0 | raise:RuntimeError | float64(3, 4) | raise |

## cross_entropy_weight (44)
| dt1 | dt2 | form | eager | compiled | kind |
|---|---|---|---|---|---|
| int32 | float16 | tt | raise:NotImplementedError | float16() | raise |
| int32 | float16 | t0 | raise:NotImplementedError | float16() | raise |
| int32 | bfloat16 | tt | raise:NotImplementedError | bfloat16() | raise |
| int32 | bfloat16 | t0 | raise:NotImplementedError | bfloat16() | raise |
| int64 | float16 | tt | raise:NotImplementedError | float16() | raise |
| int64 | float16 | t0 | raise:NotImplementedError | float16() | raise |
| int64 | bfloat16 | tt | raise:NotImplementedError | bfloat16() | raise |
| int64 | bfloat16 | t0 | raise:NotImplementedError | bfloat16() | raise |
| float16 | bool | tt | raise:RuntimeError | float16() | raise |
| float16 | bool | t0 | raise:RuntimeError | float16() | raise |
| float16 | int32 | tt | raise:RuntimeError | float16() | raise |
| float16 | int32 | t0 | raise:RuntimeError | float16() | raise |
| float16 | int64 | tt | raise:RuntimeError | float16() | raise |
| float16 | int64 | t0 | raise:RuntimeError | float16() | raise |
| float16 | bfloat16 | tt | raise:RuntimeError | float32() | raise |
| float16 | bfloat16 | t0 | raise:RuntimeError | float32() | raise |
| float16 | float32 | tt | raise:RuntimeError | float32() | raise |
| float16 | float32 | t0 | raise:RuntimeError | float32() | raise |
| float16 | float64 | tt | raise:RuntimeError | float64() | raise |
| float16 | float64 | t0 | raise:RuntimeError | float64() | raise |
| float16 | complex64 | tt | raise:RuntimeError | complex64() | raise |
| float16 | complex64 | t0 | raise:RuntimeError | complex64() | raise |
| bfloat16 | bool | tt | raise:RuntimeError | bfloat16() | raise |
| bfloat16 | bool | t0 | raise:RuntimeError | bfloat16() | raise |
| bfloat16 | int32 | tt | raise:RuntimeError | bfloat16() | raise |
| bfloat16 | int32 | t0 | raise:RuntimeError | bfloat16() | raise |
| bfloat16 | int64 | tt | raise:RuntimeError | bfloat16() | raise |
| bfloat16 | int64 | t0 | raise:RuntimeError | bfloat16() | raise |
| bfloat16 | float16 | tt | raise:RuntimeError | float32() | raise |
| bfloat16 | float16 | t0 | raise:RuntimeError | float32() | raise |
| bfloat16 | float32 | tt | raise:RuntimeError | float32() | raise |
| bfloat16 | float32 | t0 | raise:RuntimeError | float32() | raise |
| bfloat16 | float64 | tt | raise:RuntimeError | float64() | raise |
| bfloat16 | float64 | t0 | raise:RuntimeError | float64() | raise |
| bfloat16 | complex64 | tt | raise:RuntimeError | complex64() | raise |
| bfloat16 | complex64 | t0 | raise:RuntimeError | complex64() | raise |
| float32 | float16 | tt | raise:RuntimeError | float32() | raise |
| float32 | float16 | t0 | raise:RuntimeError | float32() | raise |
| float32 | bfloat16 | tt | raise:RuntimeError | float32() | raise |
| float32 | bfloat16 | t0 | raise:RuntimeError | float32() | raise |
| float64 | float16 | tt | raise:RuntimeError | float64() | raise |
| float64 | float16 | t0 | raise:RuntimeError | float64() | raise |
| float64 | bfloat16 | tt | raise:RuntimeError | float64() | raise |
| float64 | bfloat16 | t0 | raise:RuntimeError | float64() | raise |

## embedding_bag_w (36)
| dt1 | dt2 | form | eager | compiled | kind |
|---|---|---|---|---|---|
| bool | float16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | float16 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | bfloat16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | bfloat16 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | float16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | float16 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | bfloat16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | bfloat16 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | float16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | float16 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | bfloat16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | bfloat16 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float16 | bool | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float16 | int32 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float16 | int64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float16 | float16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float16 | bfloat16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float16 | float32 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float16 | float64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float16 | complex64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bfloat16 | bool | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bfloat16 | int32 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bfloat16 | int64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bfloat16 | float16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bfloat16 | bfloat16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bfloat16 | float32 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bfloat16 | float64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bfloat16 | complex64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float32 | float16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float32 | bfloat16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float64 | float16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float64 | bfloat16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| complex64 | float16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| complex64 | float16 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| complex64 | bfloat16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| complex64 | bfloat16 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |

## huber_loss (32)
| dt1 | dt2 | form | eager | compiled | kind |
|---|---|---|---|---|---|
| bool | float16 | tt | raise:RuntimeError | float16() | raise |
| bool | float16 | t0 | raise:RuntimeError | float16() | raise |
| bool | bfloat16 | tt | raise:RuntimeError | bfloat16() | raise |
| bool | bfloat16 | t0 | raise:RuntimeError | bfloat16() | raise |
| int32 | float16 | tt | raise:RuntimeError | float16() | raise |
| int32 | float16 | t0 | raise:RuntimeError | float16() | raise |
| int32 | bfloat16 | tt | raise:RuntimeError | bfloat16() | raise |
| int32 | bfloat16 | t0 | raise:RuntimeError | bfloat16() | raise |
| int64 | float16 | tt | raise:RuntimeError | float16() | raise |
| int64 | float16 | t0 | raise:RuntimeError | float16() | raise |
| int64 | bfloat16 | tt | raise:RuntimeError | bfloat16() | raise |
| int64 | bfloat16 | t0 | raise:RuntimeError | bfloat16() | raise |
| float16 | bfloat16 | tt | float16() | float32() | dtype |
| float16 | bfloat16 | t0 | float16() | float32() | dtype |
| float16 | float32 | tt | float16() | float32() | dtype |
| float16 | float32 | t0 | float16() | float32() | dtype |
| float16 | float64 | tt | float16() | float64() | dtype |
| float16 | float64 | t0 | float16() | float64() | dtype |
| float16 | complex64 | tt | raise:RuntimeError | complex64() | raise |
| float16 | complex64 | t0 | raise:RuntimeError | complex64() | raise |
| bfloat16 | float16 | tt | bfloat16() | float32() | dtype |
| bfloat16 | float16 | t0 | bfloat16() | float32() | dtype |
| bfloat16 | float32 | tt | bfloat16() | float32() | dtype |
| bfloat16 | float32 | t0 | bfloat16() | float32() | dtype |
| bfloat16 | float64 | tt | bfloat16() | float64() | dtype |
| bfloat16 | float64 | t0 | bfloat16() | float64() | dtype |
| bfloat16 | complex64 | tt | raise:RuntimeError | complex64() | raise |
| bfloat16 | complex64 | t0 | raise:RuntimeError | complex64() | raise |
| complex64 | float16 | tt | raise:NotImplementedError | complex64() | raise |
| complex64 | float16 | t0 | raise:NotImplementedError | complex64() | raise |
| complex64 | bfloat16 | tt | raise:NotImplementedError | complex64() | raise |
| complex64 | bfloat16 | t0 | raise:NotImplementedError | complex64() | raise |

## kl_div (32)
| dt1 | dt2 | form | eager | compiled | kind |
|---|---|---|---|---|---|
| bool | float16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | float16 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | bfloat16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | bfloat16 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | float16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | float16 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | bfloat16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | bfloat16 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | float16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | float16 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | bfloat16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | bfloat16 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float16 | bool | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float16 | bool | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float16 | int32 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float16 | int32 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float16 | int64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float16 | int64 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float16 | complex64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float16 | complex64 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bfloat16 | bool | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bfloat16 | bool | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bfloat16 | int32 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bfloat16 | int32 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bfloat16 | int64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bfloat16 | int64 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bfloat16 | complex64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bfloat16 | complex64 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| complex64 | float16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| complex64 | float16 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| complex64 | bfloat16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| complex64 | bfloat16 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |

## masked_fill (30)
| dt1 | dt2 | form | eager | compiled | kind |
|---|---|---|---|---|---|
| bool | float16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | bfloat16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | float16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | bfloat16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | float16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | bfloat16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float16 | bool | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float16 | int32 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float16 | int64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float16 | float16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float16 | bfloat16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float16 | float32 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float16 | float64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float16 | complex64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float16 | complex64 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bfloat16 | bool | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bfloat16 | int32 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bfloat16 | int64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bfloat16 | float16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bfloat16 | bfloat16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bfloat16 | float32 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bfloat16 | float64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bfloat16 | complex64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bfloat16 | complex64 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float32 | float16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float32 | bfloat16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float64 | float16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float64 | bfloat16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| complex64 | float16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| complex64 | bfloat16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |

## lerp_w (29)
| dt1 | dt2 | form | eager | compiled | kind |
|---|---|---|---|---|---|
| bool | float16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | float16 | t0 | float16(3, 4) | raise:BackendCompilerFailed | raise |
| bool | bfloat16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | bfloat16 | t0 | bfloat16(3, 4) | raise:BackendCompilerFailed | raise |
| int32 | float16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | bfloat16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | float16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | bfloat16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float16 | bool | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float16 | int32 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float16 | int64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float16 | bfloat16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float16 | float32 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float16 | float64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float16 | complex64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float16 | complex64 | t0 | raise:NotImplementedError | complex32(3, 4) | raise |
| bfloat16 | bool | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bfloat16 | int32 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bfloat16 | int64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bfloat16 | float16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bfloat16 | float32 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bfloat16 | float64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bfloat16 | complex64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float32 | float16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float32 | bfloat16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float64 | float16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float64 | bfloat16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| complex64 | float16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| complex64 | bfloat16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |

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

## ldexp (22)
| dt1 | dt2 | form | eager | compiled | kind |
|---|---|---|---|---|---|
| bool | float16 | tt | float16(3, 4) | float32(3, 4) | dtype |
| bool | float16 | t0 | float16(3, 4) | float32(3, 4) | dtype |
| bool | bfloat16 | tt | bfloat16(3, 4) | float32(3, 4) | dtype |
| bool | bfloat16 | t0 | bfloat16(3, 4) | float32(3, 4) | dtype |
| int32 | float16 | tt | float16(3, 4) | float32(3, 4) | dtype |
| int32 | float16 | t0 | float16(3, 4) | float32(3, 4) | dtype |
| int32 | bfloat16 | tt | bfloat16(3, 4) | float32(3, 4) | dtype |
| int32 | bfloat16 | t0 | bfloat16(3, 4) | float32(3, 4) | dtype |
| int64 | float16 | tt | float16(3, 4) | float32(3, 4) | dtype |
| int64 | float16 | t0 | float16(3, 4) | float32(3, 4) | dtype |
| int64 | bfloat16 | tt | bfloat16(3, 4) | float32(3, 4) | dtype |
| int64 | bfloat16 | t0 | bfloat16(3, 4) | float32(3, 4) | dtype |
| float16 | bool | tt | raise:NotImplementedError | float16(3, 4) | raise |
| float16 | bool | t0 | raise:NotImplementedError | float16(3, 4) | raise |
| float16 | bfloat16 | tt | float32(3, 4) | float16(3, 4) | dtype |
| float16 | float32 | tt | float32(3, 4) | float16(3, 4) | dtype |
| float16 | float64 | tt | float64(3, 4) | float16(3, 4) | dtype |
| bfloat16 | bool | tt | raise:NotImplementedError | bfloat16(3, 4) | raise |
| bfloat16 | bool | t0 | raise:NotImplementedError | bfloat16(3, 4) | raise |
| bfloat16 | float16 | tt | float32(3, 4) | bfloat16(3, 4) | dtype |
| bfloat16 | float32 | tt | float32(3, 4) | bfloat16(3, 4) | dtype |
| bfloat16 | float64 | tt | float64(3, 4) | bfloat16(3, 4) | dtype |

## bce_logits_pos_weight (19)
| dt1 | dt2 | form | eager | compiled | kind |
|---|---|---|---|---|---|
| int32 | float16 | tt | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int32 | float16 | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int32 | bfloat16 | tt | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int32 | bfloat16 | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int64 | float16 | tt | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int64 | float16 | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int64 | bfloat16 | tt | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int64 | bfloat16 | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| float16 | bool | tt | raise:NotImplementedError | float16() | raise |
| float16 | bool | t0 | raise:NotImplementedError | float16() | raise |
| float16 | complex64 | tt | raise:RuntimeError | float16() | raise |
| float16 | complex64 | t0 | raise:RuntimeError | float16() | raise |
| bfloat16 | bool | tt | raise:NotImplementedError | bfloat16() | raise |
| bfloat16 | bool | t0 | raise:NotImplementedError | bfloat16() | raise |
| bfloat16 | complex64 | tt | raise:RuntimeError | bfloat16() | raise |
| complex64 | float16 | tt | raise:NotImplementedError | raise:RuntimeError | raise_type |
| complex64 | float16 | t0 | raise:NotImplementedError | raise:RuntimeError | raise_type |
| complex64 | bfloat16 | tt | raise:NotImplementedError | raise:RuntimeError | raise_type |
| complex64 | bfloat16 | t0 | raise:NotImplementedError | raise:RuntimeError | raise_type |

## bce_logits_weight (16)
| dt1 | dt2 | form | eager | compiled | kind |
|---|---|---|---|---|---|
| int32 | float16 | tt | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int32 | float16 | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int32 | bfloat16 | tt | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int32 | bfloat16 | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int64 | float16 | tt | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int64 | float16 | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int64 | bfloat16 | tt | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| int64 | bfloat16 | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| float16 | complex64 | tt | raise:RuntimeError | float16() | raise |
| float16 | complex64 | t0 | raise:RuntimeError | float16() | raise |
| bfloat16 | complex64 | tt | raise:RuntimeError | bfloat16() | raise |
| bfloat16 | complex64 | t0 | raise:RuntimeError | raise:NotImplementedError | raise_type |
| complex64 | float16 | tt | raise:NotImplementedError | raise:RuntimeError | raise_type |
| complex64 | float16 | t0 | raise:NotImplementedError | raise:RuntimeError | raise_type |
| complex64 | bfloat16 | tt | raise:NotImplementedError | raise:RuntimeError | raise_type |
| complex64 | bfloat16 | t0 | raise:NotImplementedError | raise:RuntimeError | raise_type |

## cross_entropy_soft_w (16)
| dt1 | dt2 | form | eager | compiled | kind |
|---|---|---|---|---|---|
| bool | float16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | float16 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | bfloat16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bool | bfloat16 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | float16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | float16 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | bfloat16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int32 | bfloat16 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | float16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | float16 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | bfloat16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| int64 | bfloat16 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| complex64 | float16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| complex64 | float16 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| complex64 | bfloat16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| complex64 | bfloat16 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |

## softmax_dtype (12)
| dt1 | dt2 | form | eager | compiled | kind |
|---|---|---|---|---|---|
| float16 | bool | tt | raise:NotImplementedError | raise:BackendCompilerFailed | raise_type |
| float16 | bool | t0 | raise:NotImplementedError | raise:BackendCompilerFailed | raise_type |
| float16 | int32 | tt | raise:NotImplementedError | int32(3, 4) | raise |
| float16 | int32 | t0 | raise:NotImplementedError | int32(3, 4) | raise |
| float16 | int64 | tt | raise:NotImplementedError | int64(3, 4) | raise |
| float16 | int64 | t0 | raise:NotImplementedError | int64(3, 4) | raise |
| bfloat16 | bool | tt | raise:NotImplementedError | raise:BackendCompilerFailed | raise_type |
| bfloat16 | bool | t0 | raise:NotImplementedError | raise:BackendCompilerFailed | raise_type |
| bfloat16 | int32 | tt | raise:NotImplementedError | int32(3, 4) | raise |
| bfloat16 | int32 | t0 | raise:NotImplementedError | int32(3, 4) | raise |
| bfloat16 | int64 | tt | raise:NotImplementedError | int64(3, 4) | raise |
| bfloat16 | int64 | t0 | raise:NotImplementedError | int64(3, 4) | raise |

## sub (8)
| dt1 | dt2 | form | eager | compiled | kind |
|---|---|---|---|---|---|
| bool | float16 | tt | raise:NotImplementedError | float16(3, 4) | raise |
| bool | float16 | t0 | raise:NotImplementedError | float16(3, 4) | raise |
| bool | bfloat16 | tt | raise:NotImplementedError | bfloat16(3, 4) | raise |
| bool | bfloat16 | t0 | raise:NotImplementedError | bfloat16(3, 4) | raise |
| float16 | bool | tt | raise:NotImplementedError | float16(3, 4) | raise |
| float16 | bool | t0 | raise:NotImplementedError | float16(3, 4) | raise |
| bfloat16 | bool | tt | raise:NotImplementedError | bfloat16(3, 4) | raise |
| bfloat16 | bool | t0 | raise:NotImplementedError | bfloat16(3, 4) | raise |

## div_floor (8)
| dt1 | dt2 | form | eager | compiled | kind |
|---|---|---|---|---|---|
| float16 | complex64 | tt | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| float16 | complex64 | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| bfloat16 | complex64 | tt | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| bfloat16 | complex64 | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| complex64 | float16 | tt | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| complex64 | float16 | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| complex64 | bfloat16 | tt | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| complex64 | bfloat16 | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |

## floor_divide (8)
| dt1 | dt2 | form | eager | compiled | kind |
|---|---|---|---|---|---|
| float16 | complex64 | tt | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| float16 | complex64 | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| bfloat16 | complex64 | tt | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| bfloat16 | complex64 | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| complex64 | float16 | tt | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| complex64 | float16 | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| complex64 | bfloat16 | tt | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| complex64 | bfloat16 | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |

## xlogy (8)
| dt1 | dt2 | form | eager | compiled | kind |
|---|---|---|---|---|---|
| float16 | complex64 | tt | raise:NotImplementedError | complex64(3, 4) | raise |
| float16 | complex64 | t0 | raise:NotImplementedError | complex32(3, 4) | raise |
| bfloat16 | complex64 | tt | raise:NotImplementedError | complex64(3, 4) | raise |
| bfloat16 | complex64 | t0 | raise:NotImplementedError | bcomplex32(3, 4) | raise |
| complex64 | float16 | tt | raise:NotImplementedError | complex64(3, 4) | raise |
| complex64 | float16 | t0 | raise:NotImplementedError | complex64(3, 4) | raise |
| complex64 | bfloat16 | tt | raise:NotImplementedError | complex64(3, 4) | raise |
| complex64 | bfloat16 | t0 | raise:NotImplementedError | complex64(3, 4) | raise |

## logaddexp2 (8)
| dt1 | dt2 | form | eager | compiled | kind |
|---|---|---|---|---|---|
| float16 | complex64 | tt | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| float16 | complex64 | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| bfloat16 | complex64 | tt | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| bfloat16 | complex64 | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| complex64 | float16 | tt | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| complex64 | float16 | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| complex64 | bfloat16 | tt | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |
| complex64 | bfloat16 | t0 | raise:NotImplementedError | raise:TorchRuntimeError | raise_type |

## fmax (8)
| dt1 | dt2 | form | eager | compiled | kind |
|---|---|---|---|---|---|
| float16 | complex64 | tt | raise:RuntimeError | raise:NotImplementedError | raise_type |
| float16 | complex64 | t0 | raise:RuntimeError | raise:NotImplementedError | raise_type |
| bfloat16 | complex64 | tt | raise:RuntimeError | raise:NotImplementedError | raise_type |
| bfloat16 | complex64 | t0 | raise:RuntimeError | raise:NotImplementedError | raise_type |
| complex64 | float16 | tt | raise:RuntimeError | raise:NotImplementedError | raise_type |
| complex64 | float16 | t0 | raise:RuntimeError | raise:NotImplementedError | raise_type |
| complex64 | bfloat16 | tt | raise:RuntimeError | raise:NotImplementedError | raise_type |
| complex64 | bfloat16 | t0 | raise:RuntimeError | raise:NotImplementedError | raise_type |

## dist (8)
| dt1 | dt2 | form | eager | compiled | kind |
|---|---|---|---|---|---|
| bool | float16 | tt | raise:NotImplementedError | float16() | raise |
| bool | float16 | t0 | raise:NotImplementedError | float16() | raise |
| bool | bfloat16 | tt | raise:NotImplementedError | bfloat16() | raise |
| bool | bfloat16 | t0 | raise:NotImplementedError | bfloat16() | raise |
| float16 | bool | tt | raise:NotImplementedError | float16() | raise |
| float16 | bool | t0 | raise:NotImplementedError | float16() | raise |
| bfloat16 | bool | tt | raise:NotImplementedError | bfloat16() | raise |
| bfloat16 | bool | t0 | raise:NotImplementedError | bfloat16() | raise |

## rsub (8)
| dt1 | dt2 | form | eager | compiled | kind |
|---|---|---|---|---|---|
| bool | float16 | tt | raise:NotImplementedError | float16(3, 4) | raise |
| bool | float16 | t0 | raise:NotImplementedError | float16(3, 4) | raise |
| bool | bfloat16 | tt | raise:NotImplementedError | bfloat16(3, 4) | raise |
| bool | bfloat16 | t0 | raise:NotImplementedError | bfloat16(3, 4) | raise |
| float16 | bool | tt | raise:NotImplementedError | float16(3, 4) | raise |
| float16 | bool | t0 | raise:NotImplementedError | float16(3, 4) | raise |
| bfloat16 | bool | tt | raise:NotImplementedError | bfloat16(3, 4) | raise |
| bfloat16 | bool | t0 | raise:NotImplementedError | bfloat16(3, 4) | raise |

## matmul (8)
| dt1 | dt2 | form | eager | compiled | kind |
|---|---|---|---|---|---|
| bool | float16 | tt | raise:RuntimeError | raise:BackendCompilerFailed | raise_type |
| bool | float16 | t0 | raise:RuntimeError | raise:BackendCompilerFailed | raise_type |
| bool | bfloat16 | tt | raise:RuntimeError | raise:BackendCompilerFailed | raise_type |
| bool | bfloat16 | t0 | raise:RuntimeError | raise:BackendCompilerFailed | raise_type |
| float16 | bool | tt | raise:RuntimeError | raise:BackendCompilerFailed | raise_type |
| float16 | bool | t0 | raise:RuntimeError | raise:BackendCompilerFailed | raise_type |
| bfloat16 | bool | tt | raise:RuntimeError | raise:BackendCompilerFailed | raise_type |
| bfloat16 | bool | t0 | raise:RuntimeError | raise:BackendCompilerFailed | raise_type |

## linear (8)
| dt1 | dt2 | form | eager | compiled | kind |
|---|---|---|---|---|---|
| bool | float16 | tt | raise:RuntimeError | raise:BackendCompilerFailed | raise_type |
| bool | float16 | t0 | raise:RuntimeError | raise:BackendCompilerFailed | raise_type |
| bool | bfloat16 | tt | raise:RuntimeError | raise:BackendCompilerFailed | raise_type |
| bool | bfloat16 | t0 | raise:RuntimeError | raise:BackendCompilerFailed | raise_type |
| float16 | bool | tt | raise:RuntimeError | raise:BackendCompilerFailed | raise_type |
| float16 | bool | t0 | raise:RuntimeError | raise:BackendCompilerFailed | raise_type |
| bfloat16 | bool | tt | raise:RuntimeError | raise:BackendCompilerFailed | raise_type |
| bfloat16 | bool | t0 | raise:RuntimeError | raise:BackendCompilerFailed | raise_type |

## mse_loss (8)
| dt1 | dt2 | form | eager | compiled | kind |
|---|---|---|---|---|---|
| float16 | complex64 | tt | raise:NotImplementedError | complex64() | raise |
| float16 | complex64 | t0 | raise:NotImplementedError | complex64() | raise |
| bfloat16 | complex64 | tt | raise:NotImplementedError | complex64() | raise |
| bfloat16 | complex64 | t0 | raise:NotImplementedError | complex64() | raise |
| complex64 | float16 | tt | raise:NotImplementedError | complex64() | raise |
| complex64 | float16 | t0 | raise:NotImplementedError | complex64() | raise |
| complex64 | bfloat16 | tt | raise:NotImplementedError | complex64() | raise |
| complex64 | bfloat16 | t0 | raise:NotImplementedError | complex64() | raise |

## l1_loss (8)
| dt1 | dt2 | form | eager | compiled | kind |
|---|---|---|---|---|---|
| bool | float16 | tt | raise:NotImplementedError | float16() | raise |
| bool | float16 | t0 | raise:NotImplementedError | float16() | raise |
| bool | bfloat16 | tt | raise:NotImplementedError | bfloat16() | raise |
| bool | bfloat16 | t0 | raise:NotImplementedError | bfloat16() | raise |
| float16 | bool | tt | raise:NotImplementedError | float16() | raise |
| float16 | bool | t0 | raise:NotImplementedError | float16() | raise |
| bfloat16 | bool | tt | raise:NotImplementedError | bfloat16() | raise |
| bfloat16 | bool | t0 | raise:NotImplementedError | bfloat16() | raise |

## smooth_l1_loss (8)
| dt1 | dt2 | form | eager | compiled | kind |
|---|---|---|---|---|---|
| float16 | complex64 | tt | raise:NotImplementedError | complex64() | raise |
| float16 | complex64 | t0 | raise:NotImplementedError | complex64() | raise |
| bfloat16 | complex64 | tt | raise:NotImplementedError | complex64() | raise |
| bfloat16 | complex64 | t0 | raise:NotImplementedError | complex64() | raise |
| complex64 | float16 | tt | raise:NotImplementedError | complex64() | raise |
| complex64 | float16 | t0 | raise:NotImplementedError | complex64() | raise |
| complex64 | bfloat16 | tt | raise:NotImplementedError | complex64() | raise |
| complex64 | bfloat16 | t0 | raise:NotImplementedError | complex64() | raise |

## cosine_sim (8)
| dt1 | dt2 | form | eager | compiled | kind |
|---|---|---|---|---|---|
| float16 | complex64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float16 | complex64 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bfloat16 | complex64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bfloat16 | complex64 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| complex64 | float16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| complex64 | float16 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| complex64 | bfloat16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| complex64 | bfloat16 | t0 | raise:RuntimeError | raise:TorchRuntimeError | raise_type |

## sum_dtype (4)
| dt1 | dt2 | form | eager | compiled | kind |
|---|---|---|---|---|---|
| float16 | bool | tt | bool() | raise:InductorError | raise |
| float16 | bool | t0 | bool() | raise:InductorError | raise |
| bfloat16 | bool | tt | bool() | raise:InductorError | raise |
| bfloat16 | bool | t0 | bool() | raise:InductorError | raise |

## triplet_margin (4)
| dt1 | dt2 | form | eager | compiled | kind |
|---|---|---|---|---|---|
| float16 | bool | tt | raise:NotImplementedError | float16() | raise |
| float16 | bool | t0 | raise:NotImplementedError | float16() | raise |
| bfloat16 | bool | tt | raise:NotImplementedError | bfloat16() | raise |
| bfloat16 | bool | t0 | raise:NotImplementedError | bfloat16() | raise |

## logaddexp (2)
| dt1 | dt2 | form | eager | compiled | kind |
|---|---|---|---|---|---|
| float16 | complex64 | t0 | raise:NotImplementedError | complex32(3, 4) | raise |
| bfloat16 | complex64 | t0 | raise:NotImplementedError | bcomplex32(3, 4) | raise |
