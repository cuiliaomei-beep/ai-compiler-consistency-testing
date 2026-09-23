# source: https://github.com/pytorch/pytorch/issues/188151
# title: torch.cond fails in torch.compile with simpliest symbolic shapes (torch 2.12+)
# state: closed  created: 2026-06-25
# mined automatically; the harness records the torch.compile target and its first call

import torch

@torch.compile(dynamic=True, fullgraph=True)
def f(rows: int, cols: int):
    pred = torch.tensor(True)

    def true_fn():
        return torch.ones(rows, cols)

    def false_fn():
        return torch.zeros(rows, cols)

    return torch.cond(pred, true_fn, false_fn)


if __name__ == "__main__":
    print(f"PyTorch version: {torch.__version__}")
    print(f"CUDA available: {torch.cuda.is_available()}")
    result = f(5, 1000)
    print(f"Result shape: {result.shape}")
