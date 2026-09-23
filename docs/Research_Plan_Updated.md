# 研究计划：面向 Toxic Compilation 一致性缺陷的自动检测
## Python 层语义分析 + 一致性导向动态测试生成

## 1. 研究目标

本研究不再做 Toxic Compilation 的现象统计、分类或趋势分析，而是直接针对已经观察到的 **source-artifact consistency failure** 设计自动检测技术。

研究对象限定为 Python 驱动的编译/JIT 场景：开发者看到并认可的是 Python 层程序及其输入语义，但最终执行的是经过 graph capture、lowering、code generation、JIT specialization 或 cache reuse 后的产物。当最终产物的可观察行为与 Python 层语义不一致时，即视为待检测的一致性缺陷。

重点检测三类具体问题：

1. **Code-generation semantic deviation**：生成代码没有保持 Python 层程序语义；
2. **JIT specialization inconsistency**：对 shape、dtype、stride、device、Python scalar、flag 等上下文的特化不正确；
3. **Cache consistency failure**：生成产物在不等价上下文中被错误复用，导致 warm-cache 行为与 Python eager 或 cold-compile 行为不一致。

核心问题不是“编译器是否崩溃”，而是：

> 对同一个 Python 程序，在语义上应当等价的 source-level execution 与 compiled execution 之间，是否出现输出、异常、状态、别名、梯度或缓存行为的不一致？

---

## 2. 检测目标与形式化定义

给定 Python 函数 `f`、输入 `x` 和执行上下文 `c`：

- `E(f,x,c)`：Python eager 执行；
- `C(f,x,c)`：经过 Python compiler/JIT/codegen 后的执行。

定义可观察语义：

`Obs(r) = <value, shape, dtype, exception, mutation, alias, gradient>`

正常情况下应满足：

`Obs(E(f,x,c)) ≈ Obs(C(f,x,c))`

其中数值输出允许按照 dtype 使用合理的浮点误差。

对于缓存问题，进一步比较：

`compiled-cold(f,x,c2)` 与 `compiled-warm(f,x,c1 -> c2)`。

若 cold compile 正确，而在执行过 `c1` 后的 warm-cache `c2` 错误，则优先判定为 specialization/cache consistency failure。

---

## 3. 研究范围

### 3.1 重点分析的 Python 语义因素

**Tensor metadata**
- shape / rank
- dtype
- device
- stride
- layout / contiguous
- requires_grad

**Python-level values**
- int / float / bool
- None / non-None
- enum
- string
- list / tuple / dict 的长度、key 和元素属性
- default argument
- global variable
- closure variable

**结构与状态**
- branch condition
- loop bound
- tensor index / slice
- reshape dimension
- alias / view
- in-place mutation
- exception condition
- compile flag
- backend option

这些因素不是普通 fuzzing 参数，而是可能改变最终编译语义的 **semantic factors**。

---

## 4. 总体方法

```text
Python Program
      |
      v
┌──────────────────────────────────────┐
│ Phase 1: Python Semantic Analysis    │
│ AST / CFG / Dataflow / Alias / State│
└─────────────────┬────────────────────┘
                  |
                  v
        Semantic Factors
                  |
                  v
      Consistency Test Obligations
      (boundary / pair / sequence)
                  |
                  v
┌──────────────────────────────────────┐
│ Phase 2: Guided Dynamic Testing      │
│ input mutation + context sequences   │
└─────────────────┬────────────────────┘
                  |
          +-------+-------+
          |               |
          v               v
     Python Eager     Compiled / JIT
          |               |
          +-------+-------+
                  |
                  v
┌──────────────────────────────────────┐
│ Phase 3: Validation & Diagnosis      │
│ value/state/alias/gradient/cache     │
│ staged localization + minimization   │
└─────────────────┬────────────────────┘
                  |
                  v
          Confirmed Failure
                  |
                  v
┌──────────────────────────────────────┐
│ Phase 4: Issue Report Generation     │
│ dedup + environment + reproducer     │
│ expected/actual + trigger evidence   │
└──────────────────────────────────────┘
```

核心思想：

> **先静态确定“哪些 Python 语义因素值得改变”，再生成能区分不同语义上下文的成对/序列测试，而不是对所有 tensor 属性进行无目标随机变异。**

四个阶段是**一个统一检测流程中的连续步骤，而不是相互替代的方法**。Phase 1 不直接判定缺陷，而是产生能够指导测试的 `Semantic Factor` 和 `Consistency Test Obligation`；Phase 2 根据这些义务生成输入并执行 eager/compiled/cold/warm 测试；Phase 3 对失败进行一致性确认、定位与最小化；Phase 4 将已经确认的失败整理为可直接提交给开发者的 Issue 草稿。

---

## 5. Phase 1：Python 层语义分析与测试义务生成

### 5.1 编译边界识别

首先定位 Python 代码进入编译/JIT 系统的边界：

```python
torch.compile(f)
@torch.compile
torch.jit.script(...)
torch.jit.trace(...)

@triton.jit
...

@tilelang.jit
...
```

以及真实项目中对这些接口的 wrapper。

为每个边界构建：

```text
CompilationSite
 |- target function
 |- arguments
 |- compiler/backend
 |- compile options
 |- reachable Python functions
 `- external state
```

只对从 CompilationSite 可达的 Python 函数执行后续分析，避免全项目重型程序分析。

### 5.2 Python 前端表示

采用两级表示：

**AST**
- branch
- loop
- expression
- function call
- indexing
- container operation
- global / closure access

**Bytecode**
- wrapper/decorator 后的实际调用
- 动态 dispatch
- AST 不容易直接恢复的控制行为

构建轻量 IR：

```text
Assign
Call
Branch
Index
Mutation
Return
Raise
StateRead
StateWrite
```

并构建四类依赖：

- data dependency
- control dependency
- alias dependency
- state dependency

---

## 6. Semantic Factor Analysis

对于函数参数建立抽象状态。

### 6.1 Tensor 抽象

```text
TensorState(x):
    rank
    shape[d]
    dtype
    device
    stride[d]
    contiguous
    requires_grad
    alias_group
```

例如：

```python
if x.shape[0] > 32:
    ...
```

得到：

```text
x.shape[0] -> branch -> observable result
```

因此 `shape[0]` 被标记为 semantic factor。

### 6.2 Python Scalar / Flag 分析

例如：

```python
def f(x, use_fast):
    if use_fast:
        return fast_path(x)
    return slow_path(x)
```

得到：

```text
use_fast -> control -> output
```

因此测试直接覆盖 `True/False`。

### 6.3 Shape 与边界约束

对于：

```python
if x.shape[0] >= 32:
```

提取约束并自动生成：

```text
31
32
33
```

对于：

```python
if x.shape[0] % 16 == 0:
```

优先生成：

```text
15, 16, 17, 31, 32, 33
```

用于覆盖 tile、warp、vectorization 等编译边界。

---

## 7. Index / Shape 关联分析

AI compiler 中大量错误与 shape 和 indexing 联合出现，因此显式恢复：

```python
n = x.shape[0]
i = n - 1
y = x[i]
```

得到：

```text
x.shape[0] -> n -> i -> x[i]
```

并形成：

`0 <= i < x.shape[0]`

重点支持：

- `x[i]`
- `x[:, i]`
- slice
- gather
- scatter
- reshape
- view
- mask
- tile/block index

目标不是证明数组安全，而是确定哪些 shape/index 关系可能导致 Python 与生成代码进入不同语义路径。

---

## 8. Alias 与 Mutation Analysis

例如：

```python
def f(x):
    y = x.view(-1)
    y[0] += 1
    return x
```

构建：

```text
x --alias--> y --mutation--> observable state of x
```

因此 oracle 同时比较：

- 返回值
- 调用后的输入状态
- alias/view 关系

该部分针对：

- view elimination
- copy insertion
- mutation reordering
- functionalization
- alias analysis error

---

## 9. Semantic Context Signature

对每个 compilation site 计算 **Semantic Context Signature (SCS)**：

```text
SCS(f) = {
    x.shape[0],
    x.dtype,
    x.stride[1],
    requires_grad,
    python_flag,
    backend,
    compile_flag
}
```

SCS 不等价于编译器真实 cache key。

它表示：

> 从 Python 程序本身看，哪些上下文变化可能改变合法语义。

后续可以用它指导 cache/specialization consistency testing，而无需预先理解框架内部全部 cache-key 实现。

---

## 10. Consistency Test Obligation

静态分析不直接报告 bug，而是生成测试义务：

```text
TO = <Site, Factor, Constraint, Relation, Oracle>
```

例如：

```yaml
site: foo
factor: x.shape[0]
constraints:
  - 31
  - 32
  - 33
oracle:
  - value
  - shape
```

或：

```yaml
site: foo
factor: x.dtype
relation: change_only_one_factor
values:
  - float16
  - float32
execution:
  - cold
  - warm_sequence
```

---

## 11. Phase 2：一致性导向动态测试生成与差分执行

### 11.1 Base Input

先获得一个合法 seed，来源包括：

1. 项目现有 unit test；
2. GitHub issue reproducer；
3. 官方 example；
4. 函数签名/annotation 自动构造；
5. 简单随机合法输入。

动态方法不重新发明整个程序，而是在合法 seed 上围绕 SCS 做定向变异。

---

## 12. Pairwise Semantic Mutation

对每一个 semantic factor，只改变一个因素，其余保持不变。

例如：

```text
T1:
shape=[32,64]
dtype=float16
stride=contiguous
flag=True

T2:
shape=[32,64]
dtype=float32
stride=contiguous
flag=True
```

这样一旦出现不一致，根因更容易定位。

---

## 13. Boundary-Guided Generation

对：

```python
x.shape[0] > 32
n % 16 == 0
i < x.shape[1]
```

优先生成：

```text
boundary - 1
boundary
boundary + 1
```

将搜索空间从 arbitrary tensor input space 缩小到 semantic boundary space。

---

## 14. Cache / Specialization Sequence Generation

普通 differential testing 只做：

```text
eager(x)
compiled(x)
```

本方法额外生成：

```text
compile(x1)
-> warm cache
-> execute(x2)
```

其中 `x1` 与 `x2` 只在某一 semantic factor 上不同。

示例：

```text
x1:
shape=[32,32]
dtype=float16

x2:
shape=[32,32]
dtype=float32
```

执行矩阵：

```text
E1      = eager(x1)
C1      = compiled_cold(x1)

E2      = eager(x2)
C2cold  = compiled_cold(x2)

reset
compiled(x1)
C2warm  = compiled_warm(x2)
```

比较：

```text
E2 vs C2cold
E2 vs C2warm
C2cold vs C2warm
```

若：

```text
E2 == C2cold
E2 != C2warm
```

则是很强的 cache/specialization consistency signal。

---

## 15. Context-Switch Testing

自动构造：

```text
same shape / different dtype
same dtype / different stride
different Python scalar
different compile flag
different requires_grad
different backend
```

对每个 SCS factor 执行：

```text
A -> B
B -> A
A -> B -> A
```

用于检测：

- stale artifact reuse
- under-specialization
- incomplete guard
- wrong recompilation
- incorrect cache invalidation

---

## 16. 多层执行与缺陷定位

以 PyTorch 为例：

```text
E0: Python eager
E1: torch.compile backend="eager"
E2: AOT eager / equivalent intermediate backend
E3: TorchInductor
E4: generated Triton/CUDA path
```

如果：

```text
E0 == E1 == E2
E3 != E0
```

问题更可能进入于 Inductor lowering/codegen。

如果：

```text
E0 != E1
```

则问题可能已经发生在 graph capture / Dynamo semantics。

这比单纯 `eager vs torch.compile` 更利于定位 source-artifact divergence 进入的阶段。

---

## 17. Phase 3：一致性验证、缺陷定位与最小化

### 17.1 Consistency Oracle

### O1. Value Oracle
比较 scalar、tensor、tuple/list/dict 和 nested structures；浮点使用 dtype-aware tolerance。

### O2. Metadata Oracle
比较 shape、dtype、device、layout。

### O3. Exception Oracle
比较：
- eager 抛异常而 compiled 不抛
- compiled 抛异常而 eager 不抛
- exception type 不一致

### O4. Mutation Oracle
比较输入 tensor、mutable object 和 module state 的前后状态。

### O5. Alias Oracle
比较 view/storage sharing/in-place propagation。

### O6. Gradient Oracle
比较 forward、input gradient、parameter gradient。

### O7. Cache Oracle
记录 cold、warm、context switch 和 recompile behavior。

---

### 17.2 Failure Minimization

### 输入最小化
依次缩小：
- rank
- shape
- tensor values
- arguments
- container size
- flags

### Python 程序最小化
利用 static slice 优先删除：
- 与目标 semantic factor 无关的 statement
- 无关 branch
- 无关 call
- 无关 parameter

输出：

```text
minimal.py
environment.yaml
expected.txt
actual.txt
trace.json
semantic_factor.json
```

---

## 18. Phase 4：Developer-Ready Issue Report Generation

检测工具的最终输出不应停留在 `AssertionError` 或原始执行日志，而应自动生成**开发者可直接审阅和提交的 Issue 草稿**。该阶段只处理经过 Phase 3 重新执行和一致性确认的失败。

### 18.1 Issue 生成前的验证流程

每个候选失败依次执行：

```text
1. deterministic rerun
2. fixed random seed
3. eager/reference validation
4. compiled cold-cache validation
5. compiled warm/context-switch validation
6. failure minimization
7. existing-issue deduplication
8. environment sanitization
9. issue draft generation
```

只有当最小化后的 reproducer 仍能够稳定复现不一致时，才进入 Issue 生成阶段。

### 18.2 自动收集的信息

工具自动从静态分析、运行环境和差分执行中收集：

```text
Project / component
Python version
framework/compiler version
commit/version
CUDA/ROCm/runtime version
GPU/device
backend
compile flags

minimal reproducer
semantic factor
trigger condition
controlled factors
execution sequence

expected behavior
actual behavior
numeric difference
exception difference
mutation/alias difference
gradient difference

cold-cache result
warm-cache result
recompile/cache observations
suspected compiler stage
```

其中 `semantic factor`、`trigger condition` 和 `controlled factors` 直接来自 Phase 1，因此报告能够解释**为什么该测试被生成**，而不仅仅给出一个失败输入。

### 18.3 Issue 模板

自动生成 `issue.md`：

```markdown
# [Compiler] Incorrect result when <semantic factor> changes

## Summary
The compiled execution is inconsistent with Python eager execution
when <factor> changes from <A> to <B>.

## Environment
- Python:
- Framework:
- Compiler backend:
- Commit/version:
- CUDA/ROCm:
- GPU:
- OS:

## Minimal Reproducer

```python
# minimized reproducer
```

## Expected Behavior

Eager/reference result:

```text
...
```

## Actual Behavior

Compiled result:

```text
...
```

## Trigger Condition

Changed semantic factor:

```text
dtype: float16 -> float32
```

Controlled factors:

```text
shape: unchanged
stride: unchanged
device: unchanged
compile flags: unchanged
```

## Cache / Specialization Evidence

| Execution | Result |
|---|---|
| eager(B) | correct |
| compiled cold(B) | correct |
| compiled A -> warm B | incorrect |

## Difference

```text
max absolute error:
first mismatching element:
exception/state/alias difference:
```

## Suspected Stage

```text
TorchDynamo / AOTAutograd / Inductor / Triton / cache specialization
```

## Reproducibility

```text
Reproduced N/N runs with fixed seed.
```
```

### 18.4 Issue 输出目录

每个确认缺陷生成一个独立目录：

```text
reports/<failure-id>/
├── issue.md
├── minimal.py
├── environment.txt
├── expected.txt
├── actual.txt
├── execution_trace.json
├── semantic_factor.json
└── metadata.json
```

其中：

- `issue.md`：面向开发者的可读报告；
- `minimal.py`：可直接运行的最小复现；
- `execution_trace.json`：记录 eager/cold/warm/context-switch 执行过程；
- `semantic_factor.json`：记录静态分析得到的测试依据；
- `metadata.json`：供批量实验和 Issue 去重使用。

### 18.5 Issue 去重

在提交前，以以下特征构建 failure signature：

```text
project
compiler stage
semantic factor
oracle type
exception type
top stack frame
minimal AST/hash
cold/warm behavior
```

先在本地失败库中聚类，再检索项目现有 Issue。对于疑似重复项，不自动形成新的提交建议，而是在 `issue.md` 中标注可能的已有 Issue。

### 18.6 提交流程

工具生成的是 **developer-ready issue draft**，而不是未经审核地自动提交 GitHub Issue。研究者最后检查：

- reproducer 是否仍然有效；
- 是否包含敏感路径、token 或环境信息；
- 是否已有重复 Issue；
- 是否属于 documented unsupported behavior；
- 描述是否准确。

确认后即可将 `issue.md` 直接粘贴到项目 Issue Tracker。

该设计使工具的终点从：

```text
find a mismatch
```

扩展为：

```text
find
-> confirm
-> minimize
-> explain
-> package
-> report
```

这对于真实缺陷发现实验尤其重要，因为开发者确认和修复往往依赖高质量、可复现、能够解释触发条件的报告。


---

# 19. 测试对象

测试对象不应泛化到所有 Toxic Compilation 事件，而应只选择能够体现 **Python source -> compiled artifact consistency** 的系统。

## 19.1 核心对象

| 系统 | 测试入口 | 重点问题 | 优先级 |
|---|---|---|---|
| PyTorch / TorchDynamo / TorchInductor | `torch.compile` | dynamic shape、Python control flow、functionalization、codegen、guard、cache | 最高 |
| Triton | `@triton.jit` | shape/dtype specialization、kernel codegen、JIT、cache | 最高 |
| TileLang | Python/JIT kernel interface | tile shape、dtype、layout、generated kernel | 高 |

### PyTorch

主测试对象。其优势是存在天然 oracle：

```text
Python eager
vs
torch.compile
```

同时编译链包含：

```text
TorchDynamo
AOTAutograd
Inductor
Triton
```

可以覆盖多层 consistency failure。

### Triton

重点参数：

```text
dtype
constexpr
shape
stride
block size
num_warps
num_stages
device
```

重点检测 JIT specialization 和 cache reuse。

### TileLang

重点研究：

```text
tile size
layout
dtype
shape
thread/block mapping
```

对 generated kernel 语义的影响。

## 19.2 扩展对象

| 系统 | 使用方式 | 说明 |
|---|---|---|
| TVM | 只选具有 Python reference/eager oracle 的函数 | 验证方法向其他 compiler stack 的迁移 |
| vLLM | 选择 Python-facing custom op / Triton kernel | 测试真实上层系统中的 kernel consistency |
| TensorRT | 扩展验证 | graph/ONNX 边界较强，不作为 Python 静态分析核心对象 |

主实验建议集中于：

```text
PyTorch + Triton + TileLang
```

---

## 21. 历史缺陷测试集

从已有 Toxic Compilation 数据中只抽取：

```text
code-generation semantic deviation
JIT specialization
cache integrity failure
wrong generated code
```

并要求：

1. Python 层存在 reproducer；
2. eager/reference 行为明确；
3. compiled/JIT 行为可运行；
4. 有 buggy commit/version；
5. 有 fixed commit/version 或明确修复；
6. 确实属于 consistency，而不是普通 API misuse。

形成：

```text
BugID
Project
BuggyVersion
FixedVersion
PythonEntry
SemanticFactor
ExpectedBehavior
ActualBehavior
CompilerStage
OriginalIssue
```

这些历史数据只作为 **ground-truth detection benchmark**，不是新的 empirical contribution。

---

# 21. 新缺陷测试对象

对核心系统最新可运行版本运行。

Seed 来源：

```text
官方 compiler tests
真实 issue reproducers
官方 examples
真实项目中的 compile/JIT 函数
```

预算统一为：
- 每个 compilation site 固定时间；或
- 每个 compilation site 固定测试数量。

---

# 22. 对比工具

## 22.1 TorchProbe —— 最重要的直接对比

**TorchProbe: Fuzzing Dynamic Deep Learning Compilers，APLAS 2023**

特点：
- 面向 PyTorch 2 dynamic compiler；
- 使用 semantics-preserving transformations 生成带 Python dynamic features 的程序；
- 检测 transformed/original program inconsistency；
- 已用于发现 PyTorch compiler 和 Triton 缺陷。

与本研究区别：

```text
TorchProbe:
program transformation
-> dynamic Python feature coverage

本研究:
static semantic dependency
-> targeted factor mutation
-> eager/compiled + cold/warm consistency
```

必须重点比较：
- dynamic control-flow bugs
- shape/dtype bugs
- cache/specialization bugs
- time-to-first-failure

---

## 22.2 NNSmith —— Compiler-oriented 生成基线

**NNSmith: Generating Diverse and Valid Test Cases for Deep Learning Compilers，ASPLOS 2023**

特点：
- 生成合法、复杂 DNN graph；
- 使用 operator constraints；
- differential testing；
- 可用于多种 DL compiler，包括 PyTorch 2 支持。

区别：

```text
NNSmith:
graph structure diversity

本研究:
Python semantic context diversity
```

本研究重点覆盖：
- Python branch
- scalar/closure
- alias/mutation
- warm cache
- context switch

---

## 22.3 FreeFuzz —— Python API 输入生成基线

**FreeFuzz: Free Lunch for Testing: Fuzzing Deep-Learning Libraries from Open Source，ICSE 2022**

特点：
- 从文档、测试和真实代码采集 API invocation；
- 动态学习参数 type/value/shape；
- value/type/database mutation；
- 面向 PyTorch/TensorFlow。

适合作为：

```text
没有静态 Python 语义依赖分析
但拥有真实输入分布信息
```

的输入生成 baseline。

---

## 22.4 TitanFuzz —— LLM 生成基线

**TitanFuzz: Large Language Models Are Zero-Shot Fuzzers，ISSTA 2023**

特点：
- 使用生成式和 infilling LLM 生成 DL API 测试程序；
- 关注有效、多样的 Python DL programs；
- 已应用于 PyTorch/TensorFlow。

用于回答：

> 强代码生成能力能否通过“生成更多程序”达到与静态语义导向方法相同的 consistency bug 检测能力？

---

## 22.5 DeepREL —— 可选 relational baseline

**DeepREL: Fuzzing Deep-Learning Libraries via Automated Relational API Inference，ESEC/FSE 2022**

特点：
- 自动推断相关 API；
- 生成 relational API tests；
- 根据不同 API 间关系发现 inconsistency。

其目标主要是 DL library API，而不是 compiler/JIT consistency，因此建议作为 supplemental baseline。

---

# 23. 推荐的最终 Baseline 组合

主实验：

```text
B1 Random / Hypothesis-style generation
B2 FreeFuzz
B3 NNSmith
B4 TorchProbe
B5 Our Approach
```

资源允许时增加：

```text
B6 TitanFuzz
```

DeepREL 放 supplemental。

**TorchProbe 是 closest baseline，建议必须比较。**

---

# 24. 公平比较方式

不同工具原生 oracle 不同，因此做两组实验。

## Setting A：Native Tool

按各工具公开配置运行：

```text
TorchProbe
NNSmith
FreeFuzz
TitanFuzz
```

比较：
- historical bugs detected
- unique failures
- time

## Setting B：Common Consistency Harness

只使用各工具的 test/program/input generator，将其生成测试统一送入：

```text
Python eager
vs
torch.compile
```

并使用相同：
- oracle
- hardware
- software version
- time/test budget

这样回答：

> 谁生成的测试更容易触发真实 source-artifact consistency failure？

---

# 25. 实验设计

## RQ1：Detection Effectiveness

**静态语义引导方法能否检测历史真实 consistency defects？**

对象：historical buggy/fixed benchmark。

指标：

```text
#Detected Bugs
Recall
False Positives on Fixed Versions
per-category Recall
```

按类别报告：

```text
shape
dtype
control flow
alias/mutation
codegen
specialization
cache
```

---

## RQ2：Comparison with Existing Tools

比较：

```text
Random
FreeFuzz
NNSmith
TorchProbe
Ours
```

相同预算：

```text
bugs found
unique failure clusters
time to first bug
valid test rate
executed tests
```

核心指标：

```text
BugDetectionRate = DetectedKnownBugs / ReproducibleKnownBugs
TestEfficiency   = UniqueFailures / ExecutedTests
TTF              = TimeToFirstFailure
```

---

## RQ3：Static Analysis Contribution

消融：

```text
A0 Dynamic random only
A1 + Tensor metadata
A2 + Flow-sensitive dependency
A3 + Shape/index relation
A4 + Alias/mutation
A5 + Semantic Context Signature
A6 + Cache sequence
FULL
```

比较：

```text
bugs found
tests required
TTF
invalid tests
analysis overhead
```

验证 Python 静态分析是否真正减少动态搜索空间。

---

## RQ4：Cache / Specialization Detection

单独评估：

```text
same shape / different dtype
same dtype / different stride
different Python scalar
different flag
different requires_grad
A->B
B->A
A->B->A
```

比较：

```text
ordinary eager-vs-compiled
random sequence
SCS-guided context sequence
```

指标：

```text
known cache bugs detected
warm-only failures
tests-to-trigger
recompile/cache behavior
```

---

## RQ5：Real-world Bug Finding

在：

```text
PyTorch
Triton
TileLang
```

最新版本上运行。

每个 failure 经：

```text
rerun
seed fixation
eager validation
cold/warm validation
minimization
existing issue search
issue draft generation
manual review
developer submission
```

对确认失败生成 `issue.md + minimal.py + environment + expected/actual + trace`。提交后持续记录：

```text
Generated
Submitted
Confirmed
Fixed
Duplicate
Invalid
Pending
```

该实验不仅统计“发现了多少 failure”，还评估从自动检测到开发者可处理报告的转化率。

并选 3--5 个 mechanism-level case study。

---

# 26. 关键实验

### Experiment A：Shape Boundary
针对 `x.shape[0] >= k`，比较 Random / NNSmith / TorchProbe / Ours 触发 `k-1/k/k+1` 的效率。

### Experiment B：dtype Specialization
保持 shape/value/flag 不变，只修改 `float16 -> float32`，比较 cold 与 warm。

### Experiment C：Python Control Flow
针对 `flag and x.shape[0] > 32` 系统覆盖 T/T、T/F、F/T、F/F。

### Experiment D：Alias / Mutation
比较 output-only oracle 与 mutation/alias oracle。

### Experiment E：Cache Context Switch
比较：

```text
A -> B
reset -> B
```

如果结果不同，进一步定位 cache/guard behavior。

---

# 27. 效率与扩展性

记录：

```text
Python LOC
functions analyzed
compilation sites
CFG nodes
semantic factors
test obligations
static-analysis time
test-generation time
execution time
compile count
peak memory
```

静态分析保持轻量：
- 只分析 Python 层；
- 从 compilation site demand-driven traversal；
- 不做完整 tensor symbolic execution；
- 仅对 scalar/shape/index 做轻量约束；
- 动态执行负责最终确认。

---

# 28. 方法与现有工作的差异

| 方法 | 主要测试空间 | Python 语义依赖 | Dynamic feature | Cache sequence | Alias/mutation consistency | 编译前后 consistency |
|---|---|---:|---:|---:|---:|---:|
| FreeFuzz | API 参数 | 否 | 部分 | 否 | 否 | 非主要目标 |
| NNSmith | DNN graph | 否 | 弱 | 否 | 弱 | 是 |
| TorchProbe | Python program transformation | 转换规则驱动 | 强 | 非核心 | 部分 | 是 |
| TitanFuzz | LLM-generated API programs | 否 | 部分 | 否 | 非核心 | 非主要目标 |
| **本研究** | **semantic factor + context sequence** | **是** | **强** | **是** | **是** | **核心目标** |

核心区别：

> **把 Python 程序本身作为 source-level specification，通过静态语义依赖分析确定哪些上下文变化必须被编译系统正确区分，再用定向的成对与序列测试验证生成产物。**

---

# 29. 推荐的最小可行实现

第一阶段只实现：

```text
PyTorch / torch.compile
```

静态支持：

```text
shape
dtype
Python scalar/bool
index
branch
alias/mutation
```

动态支持：

```text
eager
compiled cold
compiled warm
```

baseline：

```text
Random
FreeFuzz
NNSmith
TorchProbe
```

如果这一阶段已经能在历史 benchmark 上明显优于 TorchProbe/NNSmith，再扩展：

```text
Triton
TileLang
```

以及：

```text
stride
requires_grad
backend
compiler flags
```

---

# 30. 论文方法主线

```text
Python Program
    ↓
Semantic Dependency Analysis
    ↓
Semantic Context Signature
    ↓
Consistency Test Obligations
    ↓
Pairwise + Context-Sequence Generation
    ↓
Eager / Cold-Compile / Warm-Cache Differential Execution
    ↓
Consistency Oracle
    ↓
Failure Localization + Minimization
    ↓
Issue Deduplication
    ↓
Developer-Ready Issue Generation
```

真正需要突出的技术贡献：

1. **Python-level semantic dependency analysis**
2. **Semantic Context Signature**
3. **cache/specialization-aware context-sequence generation**
4. **multi-dimensional consistency oracle**
5. **staged differential localization and failure minimization**
6. **developer-ready issue report generation**
