# 在 Kaggle Notebook 上跑 GPU campaign

## 一次性准备

1. 注册 kaggle.com，**Settings → Phone Verification** 绑定手机（不绑定没有 GPU 和网络）。
2. 本机打包：在 `toxic_compile/` 下运行 `powershell -File plan\kaggle\pack.ps1`，得到 `plan_kaggle.zip`（代码 + 语料 + 挖到的 reproducer，不含本机结果）。
3. Kaggle 左侧 **Datasets → New Dataset**，上传 `plan_kaggle.zip` 和 `plan/kaggle/bootstrap.sh`，标题填 `tcc-plan`（URL 会是 `/kaggle/input/tcc-plan/`）。

## 每次运行

1. **Code → New Notebook**，右侧 Settings：
   - Accelerator：**GPU T4 x2**（或 P100）；
   - Internet：**On**（pip 装 nnsmith、查重要访问 GitHub）；
   - Persistence：Files only（可选）。
   - Add Input → 选你的 `tcc-plan` 数据集。
2. 第一个 cell：

   ```python
   !bash /kaggle/input/tcc-plan/bootstrap.sh
   ```

   看到 `cuda True Tesla T4`、`triton x.y.z`、`29/29 checks passed` 即可。
3. 第二个 cell 跑 campaign（按价值排序，可只跑前几步）：

   ```python
   !bash /kaggle/working/plan/kaggle/campaign_gpu.sh
   ```

   单个 campaign 1–2 小时；免费配额每周 30 小时 GPU，单次会话最长 12 小时。
4. **要让它在你关掉浏览器后继续跑**：右上 **Save Version → Save & Run All (Commit)**。提交运行结束后，在 Notebook 的 **Output** 页能下载 `/kaggle/working/plan/gpu_reports_*`（每个目录里有 `SUMMARY.md`、`CAMPAIGN.md`、各候选的 `issue.md`）。
5. 把下载的 `gpu_reports_*` 放回本机 `plan/` 下，按本机的分诊流程处理（`TO_SUBMIT.md`、`campaign --status`）。

## 注意

- 交互式会话 20 分钟无操作会断，长任务一定用 Save & Run All。
- 每步都支持断点续跑（`progress.json`），会话被杀最多损失一个程序；重新 Run All 时把 `--out` 目录保留在 Output 里再挂回来即可续跑。
- GPU 上 Inductor 生成的是 Triton 内核，这就是计划里的 E4 层；`--device cuda` 会把所有种子张量搬到 GPU，`device` 因子的 cpu↔cuda 切换也自动生效。
- Colab 的步骤相同（Runtime → Change runtime type → T4），只是把 `/kaggle/input/...` 换成 Google Drive 路径。
