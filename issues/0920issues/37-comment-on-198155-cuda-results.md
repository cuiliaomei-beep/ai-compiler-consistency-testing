<!-- 提交信息（不要复制到 GitHub） -->
# pytorch/pytorch — 0920 第 37 条：在**自己的** #198155 下的补充评论（同一族在 CUDA / Triton 上的结果：383 对静默，其中 73 对只在 CUDA 上出现——整数 matmul 族与整数池化）

| 项 | 值 |
|---|---|
| 评论位置 | https://github.com/pytorch/pytorch/issues/198155 （你 2026-09-22 提交的 36：134 个算子在 eager 拒绝的 dtype 上照算） |
| **提交网址** | https://github.com/pytorch/pytorch/issues/198155#new_comment_field |
| **怎么提交（是评论，不是新 issue）** | ① 打开提交网址，滚到底部评论框；② **Write** 页签粘贴 `## Comment` 下面到文件末尾的全部内容；③ **Preview**；④ **Comment**；⑤ 把时间戳链接贴给我登记。 |
| 为什么是评论 | 同一扫描、同一机制，只是换成 CUDA 设备；补上 GPU 的数字和 CUDA 专属的算子 |
| 验证版本 | Tesla T4，torch 2.14.0+cu130（Kaggle `tcc-edgeunsupgpu`，`--unsupported --device cuda`，1,303 对） |
| 证据包 | `plan/kaggle_out/edgeunsupgpu/cases.jsonl` |
| 优先级 | 低–中（补充信息） |

---

## Comment

The same sweep on CUDA (Tesla T4, torch 2.14.0+cu130, Triton backend; every OpInfo op × every dtype it does not declare support for on CUDA, 1,303 operator–dtype pairs): **383 pairs / 99 operators** where eager raises and the compiled function returns. 310 of them are the same pairs as on CPU (93 operators), so the family is device-independent; 73 pairs are CUDA-only, and they are mostly the ops whose CUDA eager kernels are narrower than the CPU ones:

`__rmatmul__` (int8, uint8, int16, int32, int64); `_softmax_backward_data` (bool); `addcmul` (bool); `addmv` (int8, uint8, int16, int32, int64); `bitwise_left_shift` (bool); `bitwise_right_shift` (bool); `dot` (int8, uint8, int16, int32, int64); `inner` (int8, uint8, int16, int32, int64); `masked.cumprod` (bool); `masked.cumsum` (bool); `matmul` (int8, uint8, int16, int32, int64); `mv` (int8, uint8, int16, int32, int64); `nn.functional.avg_pool1d` (int8, int64); `nn.functional.avg_pool2d` (int64, bool); `nn.functional.avg_pool3d` (int64); `nn.functional.batch_norm` (int8, uint8, int16, int32, int64, complex64); `nn.functional.hardshrink` (bool); `nn.functional.local_response_norm` (int64, bool); `nn.functional.max_pool2d` (int8, uint8, int16, int32, int64); `nn.functional.max_pool3d` (int8, uint8, int16, int32, int64); `nn.functional.one_hot` (bool); `std` (bool); `tensordot` (int8, uint8, int16, int32, int64); `var` (bool); `vdot` (int8, uint8, int16, int32, int64)

The integer `matmul` / `mv` / `dot` / `inner` / `tensordot` / `addmv` group is the largest: eager CUDA has no integer GEMM (`"addmm_cuda" not implemented for 'Long'`), while the Triton template Inductor generates computes it, so a program that is rejected in eager on GPU runs after `torch.compile`. Integer `max_pool2d/3d` and `batch_norm` on integer/complex input are the same pattern. Conversely 96 CPU-only pairs (mostly the `special.*` functions on float16/bfloat16 and `avg_pool` on integers) have working CUDA eager kernels, so they are not "lost validation" there. The generic guard suggested above would need the per-device support table (the OpInfo `dtypesIfCUDA` lists carry exactly this).
