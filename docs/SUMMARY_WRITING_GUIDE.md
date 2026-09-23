# Issue Summary 写作规则（依赖解析不一致类问题）

适用范围：向开源项目提交"文档/配置写的安装方式与实际解析结果不一致"类 issue 时，正文最前面的 Summary 段。
生成实现：`scripts/make_issues_v2.py` 中 `S["summary"]` 的拼装逻辑；本文件是人工复核与今后手写时的规则。

## 1. 目标

用 2 到 3 句话让维护者在不读细节的情况下明白三件事：
1. **实际情况与项目说明不一样**：按哪条路径装到什么，按另一条路径装到什么。
2. **这会造成什么困惑**：用户或 CI 预期什么、实际得到什么、为什么难以察觉或难以排查。
3. **潜在风险**：这种不一致意味着什么被暴露出来。

## 2. 结构（固定三句）

**第 1 句 — 事实**
- 句式："The repository documents more than one way to install it, and they do not produce the same environment: following `<路径 A>` installs `<包 版本>` from <index A>, while following `<路径 B>` installs `<包 版本>` from <index B>; N further package(s) differ the same way (<包名列表>)."
- 路径写成文件加行号或命令，例如 `` `Dockerfile:9` ``、`` `README.md:154` ``、`` `pip install .` ``、`` `uv pip install .` ``。
- 主角选**直接依赖**中最重要的一个（优先 torch 类），其余包只列名字。
- index 用可读名：PyPI、download.pytorch.org/whl/cu124、test.pypi.org。

**第 2 句 — 困惑**（按案例类型选一种，只写一句）
- PyTorch 系列包在官方渠道与 PyPI 之间不一致：用户读 README/Dockerfile 预期得到其中写明的 CUDA/ROCm 构建，实际因安装器和 index 顺序得到另一变体或大版本；排查困难（GPU 未使用、CUDA 库不匹配），且两条路径没有针对同一套依赖测试过。
- 通用包（certifi、tqdm、packaging 等）被 PyTorch index 的旧副本替换：项目中没有任何地方表明这些包应来自 PyTorch index，但某条路径悄悄装了多年前的副本；两条路径的用户运行不同版本而无任何提示。
- 涉及 TestPyPI：CI 本意只测试待发布的包，但 index 配置让传递依赖也能从 test.pypi.org 取，测试环境与用户从 PyPI 得到的不同，且可能取到任意上传。
- 其他：声明本身不决定装入哪个 artifact，结果取决于路径，用户与 CI 可能运行不同版本而无任何提示。

**第 3 句 — 潜在风险**（存在 `--extra-index-url` 或两个 index 参与时才写）
- "Because the selection is decided by index visibility and installer semantics rather than by the project, it is also an exposure: whichever index publishes a higher version of these names decides what gets installed."

## 3. 必须遵守

- 只陈述可复核的事实：版本、index、文件、路径，都要能在正文的 Steps 与 Selected files 中找到依据。
- 不下"是否恶意"的结论。不写 "not malicious"、"official builds"、"no security impact"、"safe"；也不写 "malicious"、"attack"、"compromised"。用"exposure"、"pre-condition"、"decided by index order rather than by the project"这类描述风险的措辞，结论留给开发者。
- 不写问候、致谢、自我介绍、研究背景、"we measured 120 projects" 之类内容。
- 不用 "seems"、"might be a bug"、"I think" 之类弱化词，也不用夸大词（critical、severe、dangerous）。
- 长度：2 到 3 句，通常 80 到 130 个英文单词；多于一个包时用一句带括号的列表，不逐个展开。
- 时态用一般现在时；主语是仓库、路径、用户，不是"我们"。

## 4. 与正文其余部分的分工

- Summary 只回答"哪里不一样、为什么困惑、风险是什么"。
- 具体每个包的两侧结果放 Description；命令放 Steps to reproduce；机制解释放 Root cause；建议放 Proposed fix；文件哈希放 Selected files。Summary 不重复这些细节。
- 有模板的仓库：Summary 放在模板的 "Bug description / Describe the bug / Summary" 字段开头；无模板时单独成 `### Summary` 节，位于正文最前。

## 5. 示例

CEBRA（torch 类）：
> The repository documents more than one way to install it, and they do not produce the same environment: following `pip install .` installs `torch 2.14.0` from PyPI, while following `Dockerfile:9` installs `torch 2.6.0+cu124` from download.pytorch.org/whl/cu124; 1 further package(s) differ the same way (torchvision). A user who reads the README/Dockerfile expects the CUDA/ROCm build named there, but depending on the installer and index order gets a different variant or major version, which is confusing to debug (GPU silently unused, mismatched CUDA libraries) and means the two paths are not tested against the same dependencies. Because the selection is decided by index visibility and installer semantics rather than by the project, it is also an exposure: whichever index publishes a higher version of these names decides what gets installed.

sisl（TestPyPI 类）：
> The repository documents more than one way to install it, and they do not produce the same environment: following `pip install .` installs `python-dateutil 2.9.0.post0` from PyPI, while following `.github/workflows/wheels.yaml:222` installs `python-dateutil 3.9.0` from test.pypi.org. The CI job intends to test only the package under release from test.pypi.org, but the index configuration also lets transitive dependencies be taken from there, so the tested environment differs from what users get from PyPI and can pick up arbitrary uploads. Because the selection is decided by index visibility and installer semantics rather than by the project, it is also an exposure: whichever index publishes a higher version of these names decides what gets installed.

## 6. 复核清单（提交前逐条打勾）

- [ ] 第 1 句的两个路径、两个版本、两个 index 与 Selected files 表一致
- [ ] 第 2 句选对了案例类型，没有同时写两种
- [ ] 没有出现"恶意/非恶意"或"官方构建"的判断词
- [ ] 没有问候语、研究背景、第一人称复数
- [ ] 2 到 3 句，不超过 130 词
- [ ] 若没有 `--extra-index-url` 且只涉及一个 index，去掉第 3 句
