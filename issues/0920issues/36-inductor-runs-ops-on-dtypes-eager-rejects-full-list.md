<!-- 提交信息（不要复制到 issue 里） -->
# pytorch/pytorch — 0920 issue 36（中：Inductor 在 eager 内核未实现的 dtype 上照算——134 个算子 / 418 个 (算子, dtype) 组合的穷举清单；29 号评论那一族的完整版）

| 项 | 值 |
|---|---|
| 仓库 | https://github.com/pytorch/pytorch |
| 验证版本 | 全量清单来自 Linux CPU（Kaggle `tcc-edgeunsup`，torch 2.14.0，`scripts/opinfo_edge_sweep.py --unsupported`：OpInfo 全算子 × 各自不支持的 dtype，1,345 对）；Windows 上 41 个代表用例在 2.14.0 与 nightly 2.15.0.dev20260911 复核，33 个静默（其余 8 个响亮报错） |
| **提交 issue 链接** | https://github.com/pytorch/pytorch/issues/new?template=pt2-bug-report.yml |
| 使用的模板 | `.github/ISSUE_TEMPLATE/pt2-bug-report.yml` |
| 提交前查重 | 2026-09-22：`torch.compile accepts dtype eager NotImplementedError list operators`、`inductor runs op on unsupported dtype`、`one_hot float index torch.compile accepts`、`softmax int64 torch.compile returns`、`conv2d bool tensor torch.compile`、`bessel float16 inductor Half`：无汇总报告。相关（单算子）：#197554 伞形（malfet；你的 04/22/29 三条评论在其下）、#195674（bool 减法）、#195673（`rand_like` 整数）、#193811（upsample int32）、#144247（float 位运算垃圾值）、#193757（BCE target 越界）；15:13 复查又见 #197807（logcumsumexp uint8）、#185481（bool argmax）——都在清单内，已列入正文。本条把整族一次列全并给出通用修法建议 |
| 证据包 | `plan/kaggle_out/edgeunsup/cases.jsonl`、`plan/results/pairs/unsupported_family_list.md`（分组清单）、`plan/reports_pairs/unsupported_dtype_family.py`（41 个代表用例，本机复核） |
| 根因 | eager 内核用 `AT_DISPATCH_*` 宏限定 dtype，不支持的 dtype 抛 `NotImplementedError: "xxx_cpu" not implemented for 'Bool'`；Inductor 走分解/lowering，按类型提升规则直接生成代码，从不查内核的 dtype 覆盖表。结果分三种：按提升后的 dtype 算出合理值（int → float 的 softmax/损失）、算出无意义的值（float 的位运算把浮点位模式当整数）、接受本应拒绝的实参（`one_hot` 的 float 下标） |
| 建议标签 | oncall: pt2, module: inductor, module: correctness (silent) |

---

## Title

[inductor] 134 operators run under `torch.compile` on dtypes their eager kernels reject with `NotImplementedError` (bool conv, int softmax/losses, float bitwise ops, half special functions, complex norms): full list

## Body

### 🐛 Describe the bug

**Summary.** For 134 operators (418 operator–dtype pairs), eager raises `NotImplementedError: "<kernel>" not implemented for '<dtype>'` (or an explicit dtype check) while the Inductor-compiled function returns a tensor: bool inputs to `conv2d`, `argmax`, `round`; integer inputs to `softmax`, `var`, the pooling ops and the `nn.functional` losses; float inputs to `bitwise_*`; half inputs to the `special.*` functions; complex inputs to `batch_norm`, `mse_loss`, `nansum` (torch 2.14.0 and nightly, Linux and Windows). A program that fails in eager runs once compiled, and in the bitwise and `one_hot` cases returns numbers with no meaning. Because Inductor's decompositions and lowerings generate code from the type-promotion rules alone rather than from the dtype coverage of the eager kernels (`AT_DISPATCH_*`), every operator whose eager kernel is narrower than its decomposition is affected.

Representative cases (the full list is below):

```python
import torch, torch.nn.functional as F

i64 = torch.tensor([[1, -2, 3], [4, 0, -6]]); b = torch.tensor([[True, False, True], [False, True, True]])
f32 = torch.tensor([[1.5, -2.25, 3.0], [0.5, 0.0, -6.0]]); c64 = f32.to(torch.complex64)
cases = {"softmax(int64)": lambda: torch.softmax(i64, 1), "F.avg_pool2d(int8)": lambda: F.avg_pool2d(i64.to(torch.int8)[None], 2), "bitwise_not(float32)": lambda: torch.bitwise_not(f32),
         "conv2d(bool)": lambda: F.conv2d(b[None, None].expand(1, 1, 2, 3), torch.ones(1, 1, 2, 2, dtype=torch.bool)), "argmax(bool)": lambda: torch.argmax(b),
         "F.one_hot(float32)": lambda: F.one_hot(f32.abs().long().float(), 7), "special.bessel_j0(float16)": lambda: torch.special.bessel_j0(f32.half()),
         "F.batch_norm(complex64)": lambda: F.batch_norm(c64, None, None, training=True), "F.mse_loss(complex64)": lambda: F.mse_loss(c64, c64)}
for name, f in cases.items():
    try:
        e = f"returns {f().dtype}"
    except Exception as ex:
        e = f"raises {type(ex).__name__}: {str(ex)[:52]}"
    torch._dynamo.reset()
    r = torch.compile(f)()
    print(f"{name:28s} eager {e:66s} compiled returns {str(r.dtype).split('.')[-1]} {r.flatten()[:3].tolist()}")
```

```
softmax(int64)               eager raises NotImplementedError: "softmax_lastdim_kernel_impl" not implemented for 'L compiled returns int64 [0, 0, 0]
F.avg_pool2d(int8)           eager raises NotImplementedError: "avg_pool2d" not implemented for 'Char' compiled returns int8 [0]
bitwise_not(float32)         eager raises NotImplementedError: "bitwise_not_cpu" not implemented for 'Float' compiled returns float32 [-2.999999761581421, 1.8749998807907104, -1.4999998807907104]
conv2d(bool)                 eager raises NotImplementedError: "slow_conv2d_cpu" not implemented for 'Bool' compiled returns int64 [2, 3]
argmax(bool)                 eager raises RuntimeError: argmax(): does not support bool input         compiled returns int64 [0]
F.one_hot(float32)           eager raises RuntimeError: one_hot is only applicable to index tensor of type L compiled returns int64 [0, 1, 0]
special.bessel_j0(float16)   eager raises NotImplementedError: "bessel_j0_cpu" not implemented for 'Half' compiled returns float16 [0.51171875, 0.082763671875, -0.260009765625]
F.batch_norm(complex64)      eager raises NotImplementedError: "batch_norm" not implemented for 'ComplexFloat' compiled returns complex64 [(0.9999799728393555+0j), (-0.9999960660934448+0j), (0.9999998211860657+0j)]
F.mse_loss(complex64)        eager raises NotImplementedError: "mse_cpu" not implemented for 'ComplexFloat' compiled returns complex64 [0j]
```

`bitwise_not(float32)` returns the float whose bit pattern is the complement of the input's (`~1.5 -> -2.9999998`); `F.one_hot` accepts a float index tensor; `batch_norm` on complex input normalizes the real part and returns `x+0j`. In the other cases the compiled result is what the float promotion of the decomposition gives, i.e. a plausible answer for a call that eager refuses. `backend="aot_eager"` raises like eager in every case, so the check is lost between the decomposition and the Inductor lowering, not in Dynamo.

<details>
<summary>Full list: 134 operators, grouped by the kind of input (Linux CPU, torch 2.14.0; OpInfo sample inputs cast to each dtype the op does not declare support for; "silent" = eager raises, compiled returns)</summary>

**integer input to a floating-point-only op** (53 ops)
`_native_batch_norm_legit` (int8, uint8, int16, int32, int64, complex64); `_softmax_backward_data` (int8, uint8, int16, int32, int64, complex64); `addcdiv` (int8, uint8, int16, int32, int64, bool); `frac` (int8, uint8, int16, int32, int64); `grid_sampler_2d` (int8, uint8, int16, int32, int64, bool); `hypot` (int8, uint8, int16, int32, int64, bool); `igamma` (int8, uint8, int16, int32, int64, bool); `igammac` (int8, uint8, int16, int32, int64, bool); `log_softmax` (int8, uint8, int16, int32, int64); `logaddexp` (int8, uint8, int16, int32, int64); `logaddexp2` (int8, uint8, int16, int32, int64); `logcumsumexp` (int8, uint8, int16, int32, int64, bool); `masked.log_softmax` (int8, uint8, int16, int32, int64); `masked.logaddexp` (int8, uint8, int16, int32, int64); `masked.softmax` (int8, uint8, int16, int32, int64); `masked.softmin` (int8, uint8, int16, int32, int64); `max_pool2d_with_indices_backward` (int8, uint8, int16, int32, int64, bool); `native_batch_norm` (int8, uint8, int16, int32, int64, complex64); `nextafter` (int8, uint8, int16, int32, int64, bool); `nn.functional.adaptive_avg_pool1d` (int8, uint8, int16, int32, bool); `nn.functional.adaptive_avg_pool2d` (int8, uint8, int16, int32, bool); `nn.functional.adaptive_max_pool1d` (int8, uint8, int16, int32, bool); `nn.functional.adaptive_max_pool2d` (int8, uint8, int16, int32, bool); `nn.functional.adaptive_max_pool3d` (int8, uint8, int16, int32, int64, bool); `nn.functional.avg_pool1d` (int16, int32, bool); `nn.functional.avg_pool2d` (int8, int16, int32); `nn.functional.avg_pool3d` (int8, int16, int32, bool, float16, bfloat16); `nn.functional.batch_norm` (int8, uint8, int16, int32, int64, complex64); `nn.functional.binary_cross_entropy` (int8, uint8, int16, int32, int64); `nn.functional.cross_entropy` (int8, uint8, int16, int32, int64); `nn.functional.hardshrink` (int8, uint8, int16, int32, int64, complex64); `nn.functional.hardsigmoid` (int8, uint8, int16, int32, int64, bool); `nn.functional.hardswish` (int8, uint8, int16, int32, int64, bool); `nn.functional.huber_loss` (int8, uint8, int16, int32, int64, complex64); `nn.functional.linear_cross_entropy` (int8, uint8, int16, int32, int64); `nn.functional.local_response_norm` (int8, int16, int32); `nn.functional.logsigmoid` (int8, uint8, int16, int32, int64); `nn.functional.max_pool1d` (int8, uint8, int16, int32, int64, bool); `nn.functional.mish` (int8, uint8, int16, int32, int64, bool); `nn.functional.mse_loss` (int8, uint8, int16, int32, int64, complex64); `nn.functional.multi_margin_loss` (int8, uint8, int16, int32, int64, bool, float16, bfloat16); `nn.functional.multilabel_margin_loss` (int8, uint8, int16, int32, int64, bool, float16, bfloat16); `nn.functional.multilabel_soft_margin_loss` (int8, uint8, int16, int32, int64); `nn.functional.nll_loss` (int8, uint8, int16, int32, int64, complex64); `nn.functional.one_hot` (int8, uint8, int16, int32, float16, bfloat16, float32, float64); `nn.functional.smooth_l1_loss` (int8, uint8, int16, int32, int64, complex64); `nn.functional.soft_margin_loss` (int8, uint8, int16, int32, int64); `nn.functional.softmin` (int8, uint8, int16, int32, int64); `nn.functional.unfold` (int8, uint8, int16, int32, int64); `round` (int8, uint8, int16, int32, int64, bool); `softmax` (int8, uint8, int16, int32, int64); `std` (int8, uint8, int16, int32, int64); `var` (int8, uint8, int16, int32, int64)

**bool input** (62 ops)
`__rmatmul__` (bool); `__rmod__` (bool); `__rpow__` (bool); `addcdiv` (bool); `addmv` (bool); `argmax` (bool); `argmin` (bool); `ceil` (bool); `clamp` (bool); `dot` (bool); `floor` (bool); `fmod` (bool); `grid_sampler_2d` (bool); `hypot` (bool); `igamma` (bool); `igammac` (bool); `inner` (bool); `linalg.matrix_power` (bool); `linalg.multi_dot` (bool); `logcumsumexp` (bool); `masked.argmax` (bool); `masked.argmin` (bool); `masked.std` (bool); `masked.var` (bool); `matmul` (bool); `max_pool2d_with_indices_backward` (bool); `mv` (bool); `mvlgamma` (bool); `nextafter` (bool); `nn.functional.adaptive_avg_pool1d` (bool); `nn.functional.adaptive_avg_pool2d` (bool); `nn.functional.adaptive_max_pool1d` (bool); `nn.functional.adaptive_max_pool2d` (bool); `nn.functional.adaptive_max_pool3d` (bool); `nn.functional.avg_pool1d` (bool); `nn.functional.avg_pool3d` (bool); `nn.functional.conv1d` (bool); `nn.functional.conv2d` (bool); `nn.functional.conv3d` (bool); `nn.functional.conv_transpose1d` (bool); `nn.functional.conv_transpose2d` (bool); `nn.functional.conv_transpose3d` (bool); `nn.functional.hardsigmoid` (bool); `nn.functional.hardswish` (bool); `nn.functional.linear` (bool); `nn.functional.max_pool1d` (bool); `nn.functional.max_pool2d` (bool); `nn.functional.max_pool3d` (bool); `nn.functional.mish` (bool); `nn.functional.multi_margin_loss` (bool); `nn.functional.multilabel_margin_loss` (bool); `nn.functional.pad` (bool); `nn.functional.softsign` (bool); `nn.functional.tanhshrink` (bool); `nn.functional.threshold` (bool); `pow` (bool); `remainder` (bool); `round` (bool); `tensordot` (bool); `trace` (bool); `trunc` (bool); `vdot` (bool)

**float input to a bitwise op** (6 ops)
`__ror__` (float16, bfloat16, float32, float64); `__rxor__` (float16, bfloat16, float32, float64); `bitwise_and` (float16, bfloat16, float32, float64); `bitwise_not` (float16, bfloat16, float32, float64); `bitwise_or` (float16, bfloat16, float32, float64); `bitwise_xor` (float16, bfloat16, float32, float64)

**float16 / bfloat16 input to a CPU kernel without a half implementation** (33 ops)
`__ror__` (float16, bfloat16); `__rxor__` (float16, bfloat16); `nn.functional.avg_pool3d` (float16, bfloat16); `nn.functional.multi_margin_loss` (float16, bfloat16); `nn.functional.multilabel_margin_loss` (float16, bfloat16); `nn.functional.one_hot` (float16, bfloat16); `special.airy_ai` (float16, bfloat16); `special.bessel_j0` (float16, bfloat16); `special.bessel_j1` (float16, bfloat16); `special.bessel_y0` (float16, bfloat16); `special.bessel_y1` (float16, bfloat16); `special.chebyshev_polynomial_t` (float16, bfloat16); `special.chebyshev_polynomial_u` (float16, bfloat16); `special.chebyshev_polynomial_v` (float16, bfloat16); `special.chebyshev_polynomial_w` (float16, bfloat16); `special.erfcx` (float16, bfloat16); `special.hermite_polynomial_h` (float16, bfloat16); `special.hermite_polynomial_he` (float16, bfloat16); `special.laguerre_polynomial_l` (float16, bfloat16); `special.legendre_polynomial_p` (float16, bfloat16); `special.log_ndtr` (float16, bfloat16); `special.modified_bessel_i0` (float16, bfloat16); `special.modified_bessel_i1` (float16, bfloat16); `special.modified_bessel_k0` (float16, bfloat16); `special.modified_bessel_k1` (float16, bfloat16); `special.ndtri` (float16, bfloat16); `special.scaled_modified_bessel_k0` (float16, bfloat16); `special.scaled_modified_bessel_k1` (float16, bfloat16); `special.shifted_chebyshev_polynomial_t` (float16, bfloat16); `special.shifted_chebyshev_polynomial_u` (float16, bfloat16); `special.shifted_chebyshev_polynomial_v` (float16, bfloat16); `special.shifted_chebyshev_polynomial_w` (float16, bfloat16); `special.spherical_bessel_j0` (float16, bfloat16)

**complex input** (17 ops)
`_batch_norm_with_update` (complex64); `_native_batch_norm_legit` (complex64); `_softmax_backward_data` (complex64); `nanmean` (complex64); `nansum` (complex64); `native_batch_norm` (complex64); `native_group_norm` (complex64); `nn.functional.batch_norm` (complex64); `nn.functional.group_norm` (complex64); `nn.functional.hardshrink` (complex64); `nn.functional.huber_loss` (complex64); `nn.functional.instance_norm` (complex64); `nn.functional.mse_loss` (complex64); `nn.functional.nll_loss` (complex64); `nn.functional.smooth_l1_loss` (complex64); `special.xlog1py` (complex64); `xlogy` (complex64)

</details>

The list was produced by taking every OpInfo, every dtype **not** in its declared support list, the op's sample inputs cast to that dtype, and comparing eager with `torch.compile` (1,345 operator–dtype pairs; 845 raise on both sides, 418 are silent, 55 had no castable sample). 41 representatives were re-run on Windows on 2.14.0 and on the 2026-09-11 nightly: 33 silent, 8 raise a compile-time error instead.

**Possible fix.** A single generic guard would cover the whole family: before lowering an `aten` op, check whether the eager kernel supports the input dtype — the OpInfo `dtypes` lists already encode this for CPU and CUDA, and at runtime a call on a zero-element tensor of the same dtype and rank answers it in microseconds — and fall back to the ATen kernel (which raises the same error as eager) when it does not. That keeps the improvements where a decomposition legitimately widens support (the `special.*` functions on half precision are arguably one) behind an explicit opt-in rather than an accident of which ops have decompositions. Individual members already reported: bool subtraction #195674, integer `rand_like` #195673, integer `upsample_bilinear2d` #193811, float bitwise ops #144247, BCE targets #193757, `logcumsumexp` on uint8 #197807, `argmax` on a bool mask #185481; the umbrella is #197554.

### Error logs

No error is raised by the compiled function; eager raises `NotImplementedError` (or the op's own dtype check) for every case above.

### Versions

```
PyTorch version: 2.14.0+cpu
OS: Microsoft Windows 11 Pro for Workstations (10.0.26200 64-bit)
MSVC: Microsoft (R) C/C++ Optimizing Compiler Version 19.44.35228 for x64
Python version: 3.14.7 (64-bit runtime)
Is CUDA available: False
CPU: 11th Gen Intel(R) Core(TM) i9-11900T @ 1.50GHz
[pip3] numpy==2.5.2
[pip3] torch==2.14.0+cpu
```

Same output on nightly 2.15.0.dev20260911+cpu; the full sweep ran on Linux (torch 2.14.0+cpu, Python 3.12).
