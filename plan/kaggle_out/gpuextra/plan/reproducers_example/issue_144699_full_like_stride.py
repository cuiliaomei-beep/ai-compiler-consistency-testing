# 模板：一个 reproducer 文件 = 一个被测程序。
# 规则：
#   1. 定义一个函数 `f`（或者用 @torch.compile 装饰 / torch.compile(某函数) 标出编译目标，
#      若两者都没有则文件里只能有一个函数）；
#   2. 定义 `args`：一次合法调用的参数元组（张量会在每次执行前重新克隆，可放心用 in-place）；
#   3. 不要出现 subprocess / open( / eval( / 网络等（安全门会拒绝整个文件）；
#   4. 需要 GPU 的写法（"cuda"）在无 GPU 机器上会被跳过；
#   5. 文件名会成为程序名，建议用 issue 编号 + 主题。
#
# 可选：模块级注释里写上来源 issue，会原样进入报告的 notes。
# 来源：https://github.com/pytorch/pytorch/issues/144699 （inductor full_like 对非连续输入的 stride）
import torch


def f(x):
    return torch.full_like(x, 3)


args = (torch.randn(4, 5, 6).transpose(1, -1),)
