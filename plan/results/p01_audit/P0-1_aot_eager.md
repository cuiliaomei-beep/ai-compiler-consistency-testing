# P0-1 主实验复算：冻结 185 程序 × 逐语句插入 graph break（backend=aot_eager，torch 2.14.0+cpu，2026-09-25 17:06）

同一进程、同一 oracle（返回值精确比较 + STATE 快照 + 异常类型），三臂：eager、编译原程序、编译断点变体。每个程序两次调用。

## 计数（分子 / 分母按清单要求分列）

| 量 | 值 |
|---|---|
| 冻结程序数 | 185（dynamo_semantics 77, dynamo_semantics_more 74, dynamo_semantics_batch3 34） |
| 可运行 / 可改写程序数 | 185 / 185（AST 改写失败 0） |
| 每臂执行调用数 | 370（185 程序 × 2 次调用）；三臂合计 1110 |
| 静态插入位置数（顶层语句后） | 477；插入 0 处的程序 11 个 |
| 实际触发的用户断点数（Dynamo 计数器 `graph_break`：追踪时遇到的用户断点，两次调用合计；帧被重复追踪时可多于静态数，语句未执行到或提前抛出时少于静态数） | 543 |
| 所有静态断点都被触发的程序数 | 155；触发数少于插入数的程序 19 个 |
| 图段数（Dynamo `frames.total`，两次调用合计） | 原程序臂 724，断点臂 1279 |
| 分歧实例（程序×调用） | 原程序臂 21，断点臂 27，交集 19 |
| 成对分类 | 同（无分歧）341；同一分歧 13；新增 8；消失 2；改变 6 |
| 本次运行墙钟 | 68.2 s（eager 臂 0.07 s、原程序臂 21.64 s、断点臂 45.35 s，含编译） |

## 非“同”配对逐项（程序 × 调用）

| 程序 | 调用 | 配对 | 原程序臂 | 断点臂 | 静态插入 | 实际触发 | 图段 原/断 | 根因 | 判定 |
|---|---|---|---|---|---|---|---|---|---|
| `gen_send` | 0 | new | — | raise | 4 | 3 | 1 / 4 | C42 | defect |
| `gen_send` | 1 | new | — | raise | 4 | 3 | 1 / 4 | C42 | defect |
| `collections_types` | 0 | new | — | return | 9 | 9 | 1 / 10 | C41 | defect |
| `collections_types` | 1 | new | — | return | 9 | 9 | 1 / 10 | C41 | defect |
| `python_random` | 0 | gone | return | — | 4 | 4 | 3 / 6 | known-B17 | known-defect |
| `python_random` | 1 | gone | return | — | 4 | 4 | 3 / 6 | known-B17 | known-defect |
| `numpy_scalar_types` | 0 | changed | return | return | 2 | 2 | 2 / 3 | known-numpy | known-defect |
| `numpy_scalar_types` | 1 | changed | return | return | 2 | 2 | 2 / 3 | known-numpy | known-defect |
| `gen_return_value_stopiteration` | 0 | new | — | return | 4 | 4 | 1 / 5 | C42 | defect |
| `gen_return_value_stopiteration` | 1 | new | — | return | 4 | 4 | 1 / 5 | C42 | defect |
| `gen_throw` | 0 | new | — | raise | 3 | 3 | 1 / 4 | C42 | defect |
| `gen_throw` | 1 | new | — | raise | 3 | 3 | 1 / 4 | C42 | defect |
| `tensor_subclass_torch_function` | 0 | changed | state | raise | 3 | 3 | 8 / 6 | known-state | known-defect |
| `tensor_subclass_torch_function` | 1 | changed | state | raise | 3 | 3 | 8 / 6 | known-state | known-defect |
| `threading_local_state` | 0 | changed | state | state | 2 | 4 | 4 / 7 | known-state | known-defect |
| `threading_local_state` | 1 | changed | state | state | 2 | 4 | 4 / 7 | known-state | known-defect |

## 独立根因（新增分歧去重后）

新增分歧实例 8 处，来自 4 个程序，去重后 **2 个独立根因**：

- **C42**：`gen_send`, `gen_return_value_stopiteration`, `gen_throw` —— generator alive across the break is reconstructed as tuple_iterator; .send raises AttributeError (#198190)
- **C41**：`collections_types` —— OrderedDict.move_to_end on a dict that becomes an input of the resume function is not replayed (#198189)

消失 / 改变的配对不是新发现：
- `python_random`（gone）：baseline diverges on both calls (values differ from eager) = the known item B17, random.seed inside a compiled function ignored (fixed upstream); with a break after every statement seed and draws are no longer in one traced frame and the compiled values equal eager, so the divergence disappears
- `numpy_scalar_types`（changed）：aot_eager arm only: baseline already diverges (numpy scalar promotion, known family C13/C20); under the break the compiled dtype changes from float32 to float64, still a divergence
- `tensor_subclass_torch_function`（changed）：baseline already diverges in the __torch_function__ call log; the break changes which calls are logged, not whether it diverges
- `threading_local_state`（changed）：baseline already diverges on the threading.local object stored in STATE; the break changes the repr of the object, not the divergence

预期行为 / 无效项：本语料的 185 程序在断点臂没有被判为预期行为的新增项（`functools.lru_cache` 的内联属于第 4 批程序，不在冻结语料内）。

## 代表程序的断点与图段（Dynamo 计数器）

| 程序 | 静态插入 | 实际触发 | 图段 原程序臂 | 图段 断点臂 | 其他断点原因（断点臂） |
|---|---|---|---|---|---|
| `gen_send` | 4 | 3 | 1 | 4 | Unsupported method call |
| `collections_types` | 9 | 9 | 1 | 10 | — |
| `python_random` | 4 | 4 | 3 | 6 | Attempted to call function marked as skipped |
| `numpy_scalar_types` | 2 | 2 | 2 | 3 | — |
| `gen_return_value_stopiteration` | 4 | 4 | 1 | 5 | — |
| `gen_throw` | 3 | 3 | 1 | 4 | Unsupported method call |
| `tensor_subclass_torch_function` | 3 | 3 | 8 | 6 | Invalid call to __build_class__; Unsupported Tensor.item() call with capture_scalar_outputs=False |
| `threading_local_state` | 2 | 4 | 4 | 7 | Unsupported function call |

触发数少于静态插入数的程序（断点位于未执行到的语句之后，或程序在到达前已抛出）：

- `gen_early_close`：插入 4，触发 2
- `gen_send`：插入 4，触发 3
- `assert_message`：插入 1，触发 0
- `closure_late_binding`：插入 2，触发 1
- `zip_strict_error`：插入 1，触发 0
- `graph_break_in_loop`：插入 3，触发 1
- `break_inside_try`：插入 2，触发 0
- `list_of_tensors_equality`：插入 1，触发 0
- `exception_message_with_value`：插入 2，触发 1
- `exception_after_graph_break`：插入 4，触发 3
- `exception_in_generator`：插入 4，触发 2
- `exception_chaining`：插入 1，触发 0
- `exception_group`：插入 1，触发 0
- `while_with_tensor_condition_item`：插入 3，触发 2
- `print_format_side_effect_count`：插入 1，触发 0
- `gen_expression_lazy_side_effect`：插入 4，触发 1
- `nested_generator_closure_var`：插入 2，触发 1
- `exception_args_and_notes`：插入 1，触发 0
- `nonlocal_generator_state_machine`：插入 5，触发 1

## 最小复现是否仍需 graph break

见 `results/p01_audit/minimal/`：40 号稿（C41）的代码块不含 `graph_break`，运行输出 eager 与 compiled 的 OrderedDict 顺序不同；41 号稿（C42）的代码块两段：第一段“生成器从编译函数返回”不含 graph break 即复现 `tuple_iterator` 与 `StopIteration.value=None`，第二段“挂起的生成器上 `.send`”以一个显式 `graph_break()` 作为挂起点。因此 C41 与 C42 的返回路径不需要断点；C42 的帧内 send/throw 形态以断点为触发条件。
