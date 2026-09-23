<!-- 提交信息（不要复制到 issue 里） -->
# pytorch/pytorch — 0920 issue 02b（高：默认配置下静默错值 / 错形状；发布版与最新 nightly、CPU 与 CUDA 都复现；是已关闭的 #194976 的残留）

| 项 | 值 |
|---|---|
| 仓库 | https://github.com/pytorch/pytorch |
| 为什么编号是 02b | 2026-09-21 重排编号之后才发现；优先级在 02 与 03 之间，为了不打乱你已经在用的编号，插在 02 后面。**建议紧接着 02 提交** |
| 验证版本 | torch 2.14.0+cpu 与 nightly 2.15.0.dev20260911+cpu（Windows）；Linux CPU 2.14.0 与 nightly 2.15.0.dev20260921、Tesla T4 CUDA（2.14.0+cu130 与 nightly 2.15.0.dev20260921+cu130）同样复现（Kaggle `tcc-staleepslinux` / `tcc-staleepsgpu`，`plan/kaggle_out/staleepslinux.log`、`staleepsgpu.log`）。`aot_eager` 正确；关掉 FX 图缓存或 AOTAutograd 缓存任意一个也正确 |
| **提交 issue 链接** | https://github.com/pytorch/pytorch/issues/new?template=pt2-bug-report.yml |
| 使用的模板 | `.github/ISSUE_TEMPLATE/pt2-bug-report.yml` |
| 提交前查重 | 2026-09-21：`tensorify_python_scalars stale`、`stale float eps layer_norm compile`、`rms_norm eps python float torch.compile wrong`、`automatic dynamic float stale value inductor`、`specialize_float stale AOTAutogradCache`：无同报告。**相关**：#194976（closed，clamp 上的同一机制）及其修复 #195040（只堵了 `_tensorify_python_scalars.py` 末尾那一遍的特化路径，修复已在 nightly 里，本条在含该修复的 nightly 上仍复现）；#194817（open PR，只处理 SDPA 的 scale） |
| 证据包 | `plan/reports_scalar_seq/specialized_float_kwarg_census.py`（51 个带浮点参数的算子普查，nightly 上 18 个出错）、`norm_eps_stale_min.py`（最小复现 + 缓存 2×2 对照 + “结果对应哪个陈旧值”）、`layer_norm_eps_stale2.py`；发现来源 `plan/scripts/scalar_arg_sequence_diff.py`（10.9b：标量实参逐次变化 × 默认缓存，100 个程序；2.14.0 上 14/44 出错、nightly 上残留本条） |
| 触发条件（已隔离） | 同一个 Python float 实参 `s`：① 在图里有一处能被“张量化”的用法（如 `x * s`），因此第二个取值起它变成动态输入；② 它的一个**表达式**（`s + 1e-3`、`1 + s`、`s / 4`…）传给某个算子的 C++ double 形参。只写 `eps=s`（裸符号）或没有 ① 时不触发 |
| 建议标签 | oncall: pt2, module: dynamic shapes, module: aotdispatch, module: correctness (silent) |

---

## Title

[pt2] Python float argument that changes between calls goes stale in the cached graph (residual of #194976): norm `eps`, `huber_loss` delta, SDPA `scale`, `interpolate(scale_factor=...)` keep an earlier value (`interpolate`: old output shape)

## Body

### 🐛 Describe the bug

**Summary.** For `f(x, s)` that uses a Python float as `x * s` and, through arithmetic, as a float parameter of an operator (`F.rms_norm(x * s, (4,), eps=s + 1e-3)`), eager and `aot_eager` use the current `s`, while the default `torch.compile` keeps the parameter computed from the second `s` for all later values (torch 2.14.0 and nightly 2026-09-21, CPU and CUDA). A schedule that varies a loss `delta`, a `label_smoothing`, an attention `scale` or an `interpolate` scale factor computes with an old value, with no error, and `interpolate` returns the old shape. Because fake-tensor propagation specialises the symbolic float with a ShapeEnv guard rather than a graph input, AOT bakes the constant while the Dynamo graph stays identical for every `s`, so after each recompile AOTAutogradCache returns the first artifact.

```python
import torch, torch.nn.functional as F

torch.manual_seed(0)
x, y = torch.randn(4, 4), torch.randn(4, 4)
programs = {
    "rms_norm(x * s, eps=s + 1e-3)":          lambda s: F.rms_norm(x * s, (4,), eps=s + 1e-3),
    "huber_loss(x * s, y, delta=s + 0.1)":    lambda s: F.huber_loss(x * s, y, delta=s + 0.1),
    "interpolate(x * s, scale_factor=1 + s)": lambda s: F.interpolate((x * s)[None], scale_factor=1.0 + s),
}
for name, f in programs.items():
    torch._dynamo.reset()
    cf = torch.compile(f)
    print(name)
    for s in (0.9, 0.5, 0.25, 2.0):
        want, got = f(s), cf(s)
        same = want.shape == got.shape and torch.allclose(want, got)
        print(f"    s={s:<5} eager shape {tuple(want.shape)}  compiled shape {tuple(got.shape)}  " + ("ok" if same else "WRONG" + ("" if want.shape != got.shape else f" (max abs diff {(want - got).abs().max().item():.3f})")))
```

```
rms_norm(x * s, eps=s + 1e-3)
    s=0.9   eager shape (4, 4)  compiled shape (4, 4)  ok
    s=0.5   eager shape (4, 4)  compiled shape (4, 4)  ok
    s=0.25  eager shape (4, 4)  compiled shape (4, 4)  WRONG (max abs diff 0.218)
    s=2.0   eager shape (4, 4)  compiled shape (4, 4)  WRONG (max abs diff 0.348)
huber_loss(x * s, y, delta=s + 0.1)
    s=0.9   eager shape ()  compiled shape ()  ok
    s=0.5   eager shape ()  compiled shape ()  ok
    s=0.25  eager shape ()  compiled shape ()  WRONG (max abs diff 0.120)
    s=2.0   eager shape ()  compiled shape ()  WRONG (max abs diff 0.731)
interpolate(x * s, scale_factor=1 + s)
    s=0.9   eager shape (1, 4, 7)  compiled shape (1, 4, 7)  ok
    s=0.5   eager shape (1, 4, 6)  compiled shape (1, 4, 6)  ok
    s=0.25  eager shape (1, 4, 5)  compiled shape (1, 4, 6)  WRONG
    s=2.0   eager shape (1, 4, 12)  compiled shape (1, 4, 6)  WRONG
```

The first call specialises `s` (static), the second makes it automatically dynamic and is still right, and every value after that reuses the parameter of the second call: for `rms_norm` the compiled result equals eager's result with `eps = 0.5 + 1e-3` exactly. With `TORCHINDUCTOR_FX_GRAPH_CACHE=0` or `TORCHINDUCTOR_AUTOGRAD_CACHE=0` (either one), and with `backend="aot_eager"`, all rows are `ok`.

Of 51 operators with a float parameter that I tried in this shape, 18 are affected on nightly: `rms_norm`, `layer_norm`, `group_norm`, `batch_norm`, `instance_norm` (eps) and `batch_norm` momentum, `cosine_similarity` eps, `pairwise_distance` / `cdist` p, `quantile` q, `interpolate` scale_factor (nearest and linear), `smooth_l1_loss` beta, `huber_loss` delta, `cross_entropy` label_smoothing, `poisson_nll_loss` eps, `triplet_margin_loss` margin, and `scaled_dot_product_attention` scale. Pointwise ops whose scalar is tensorified (`clamp`, `leaky_relu`, `elu`, `hardtanh`, `threshold`, `addcmul`, `lerp`, `where`, `pow`, …) are correct on nightly; on 2.14.0, which predates the fix for #194976, many of those are wrong as well (`torch.add(x * s, y, alpha=1 - s)`, the EMA update, among them).

**Root cause.** `TORCH_LOGS=graph_code,aot_graphs,recompiles` for the `rms_norm` program:

```
[0/1] Dynamo graph:   item = l_s_.item(); mul = l_x_ * item; add = item + 0.001; rms_norm = torch.rms_norm(mul, (4,), None, add)
[0/1] AOT graph:      mul = aten.mul.Tensor(arg0_1, _local_scalar_dense) ... add_1 = aten.add.Scalar(mean, 0.5009999871253967)
[0/2] recompile:      guard failure  (0.001 + s) == 0.501   # functional.py: rms_norm (_dynamo/utils.py in run_node)
[0/2] Dynamo graph:   identical text to [0/1]
[0/2] AOT graph:      "Forward graph (from cache)" ... add_1 = aten.add.Scalar(mean, 0.5009999871253967)
```

The operator takes a C++ `double`, so tracing it on fake tensors specialises the expression `zf + 0.001` and records the ShapeEnv guard `(0.001 + s) == 0.501`; the value is burned into the AOT graph, but the Dynamo graph still carries the symbolic expression. The guard works (the third call recompiles), but the recompile produces the same Dynamo graph, AOTAutogradCache keys on that graph and prunes guards over symbols that are not placeholder SymInts, and the artifact with `0.501` inside comes back. This is the mechanism described in #195040, which closed it for the final sweep of `_tensorify_python_scalars.py`; specialisation that happens earlier, during Dynamo's fake-tensor propagation of an op with a float schema argument, is not covered.

**Possible fix.** Treat a float symbol that gets specialised during tracing the same way #195040 treats one specialised in the tensorify sweep: mark it with `TensorifyState.specialize` and restart analysis so that Dynamo bakes the value into its own output graph (the value then is part of the cache key); or, more narrowly, make AOTAutogradCache bypass / miss when the ShapeEnv holds an equality guard over a float symbol that is not a graph input.

### Error logs

No error. The recompile log shows the guard failing and the forward graph being served from cache.

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

Same result on nightly (2.15.0.dev20260911 on Windows, 2.15.0.dev20260921 on Linux), on Linux CPU with 2.14.0, and on CUDA (Tesla T4, 2.14.0+cu130 and nightly 2.15.0.dev20260921+cu130).
