# dtype-promotion matrix (inductor, pairs=float, autocast=True)

- cases: 1825, mismatches: 113 {'dtype': 1, 'raise': 1, 'raise_type': 111, 'shape': 0}; wall 30.2 s

## masked_fill (25)
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

## bce_weight (25)
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

## atan2 (6)
| dt1 | dt2 | form | eager | compiled | kind |
|---|---|---|---|---|---|
| float16 | float16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float16 | bfloat16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float16 | float32 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float16 | float64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float16 | complex64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bfloat16 | float16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |

## addcmul (6)
| dt1 | dt2 | form | eager | compiled | kind |
|---|---|---|---|---|---|
| float16 | float16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float16 | bfloat16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float16 | float32 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float16 | float64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float16 | complex64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bfloat16 | float16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |

## addcdiv (6)
| dt1 | dt2 | form | eager | compiled | kind |
|---|---|---|---|---|---|
| float16 | float16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float16 | bfloat16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float16 | float32 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float16 | float64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float16 | complex64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bfloat16 | float16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |

## scatter_add (6)
| dt1 | dt2 | form | eager | compiled | kind |
|---|---|---|---|---|---|
| float16 | float16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float16 | bfloat16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float16 | float32 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float16 | float64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float16 | complex64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bfloat16 | float16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |

## lerp (5)
| dt1 | dt2 | form | eager | compiled | kind |
|---|---|---|---|---|---|
| float16 | bfloat16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float16 | float32 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float16 | float64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float16 | complex64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bfloat16 | float16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |

## lerp_w (5)
| dt1 | dt2 | form | eager | compiled | kind |
|---|---|---|---|---|---|
| float16 | bfloat16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float16 | float32 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float16 | float64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| float16 | complex64 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |
| bfloat16 | float16 | tt | raise:RuntimeError | raise:TorchRuntimeError | raise_type |

## ldexp (1)
| dt1 | dt2 | form | eager | compiled | kind |
|---|---|---|---|---|---|
| float16 | float16 | tt | float32(3, 4) | float16(3, 4) | dtype |

## bitwise_and (1)
| dt1 | dt2 | form | eager | compiled | kind |
|---|---|---|---|---|---|
| float16 | float16 | tt | raise:NotImplementedError | raise:InductorError | raise_type |

## bitwise_xor (1)
| dt1 | dt2 | form | eager | compiled | kind |
|---|---|---|---|---|---|
| float16 | float16 | tt | raise:NotImplementedError | raise:InductorError | raise_type |

## multilabel_soft_margin_w (1)
| dt1 | dt2 | form | eager | compiled | kind |
|---|---|---|---|---|---|
| float16 | float16 | tt | raise:NotImplementedError | float32() | raise |
