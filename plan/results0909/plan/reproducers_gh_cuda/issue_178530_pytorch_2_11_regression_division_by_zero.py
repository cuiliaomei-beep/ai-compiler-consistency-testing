# source: https://github.com/pytorch/pytorch/issues/178530
# title: Pytorch 2.11 regression: Division by zero exception on empty tensor with torch.compile and dynamic size
# state: closed  created: 2026-03-26
# mined automatically; the harness records the torch.compile target and its first call

import torch

def compute(dates, query_date, initial_dfs, target_dfs, half_life):

    """
    Returns a tensor of shape (t, B) where t = number of dates

    that precede the maturity date.  When the trade is already matured,

    t = 0 and the output is an empty (0, B) tensor.

    """

    # t is a data-dependent size -> unbacked symint inside torch.compile

    t = torch.searchsorted(dates, query_date).item()

    torch._check(t >= 0)

    torch._check(t <= dates.shape[0])

 

    sim_yfs = torch.arange(t, device=dates.device, dtype=initial_dfs.dtype)

    decay   = torch.exp(

        -torch.log(torch.tensor(2.0, device=dates.device, dtype=initial_dfs.dtype))

        / half_life * sim_yfs

    )

    # outer-product broadcast: (1, B) ** (t, 1)  ->  (t, B)

    return (

        (initial_dfs.unsqueeze(0) ** decay.unsqueeze(1))

        * (target_dfs.unsqueeze(0) ** (1.0 - decay.unsqueeze(1)))

    )

 

 

# ---------------------------------------------------------------------------

# Setup

# ---------------------------------------------------------------------------

 

device = "cuda"

dtype  = torch.float64

 

dates       = torch.tensor([100, 200, 300, 400, 500], device=device, dtype=torch.int32)

initial_dfs = torch.rand(12, device=device, dtype=dtype)

target_dfs  = torch.rand(12, device=device, dtype=dtype)

half_life   = torch.tensor(1.0, device=device, dtype=dtype)

 

# query_date=350 -> t=3  (trade still alive,  3 future stopping dates)

future_date  = torch.tensor(350, device=device, dtype=torch.int32)

 

# query_date=50  -> t=0  (trade already matured, 0 future stopping dates)

matured_date = torch.tensor(50, device=device, dtype=torch.int32)

 

# ---------------------------------------------------------------------------

# 1. Without torch.compile – works correctly for both t>0 and t=0

# ---------------------------------------------------------------------------


print("--- Without torch.compile ---")


r1 = compute(dates, future_date, initial_dfs, target_dfs, half_life)

print(f"  t=3 (future trade):          shape = {r1.shape}")   # torch.Size([3, 12])

 

r2 = compute(dates, matured_date, initial_dfs, target_dfs, half_life)

print(f"  t=0 (already-matured trade): shape = {r2.shape}")   # torch.Size([0, 12])

 

# ---------------------------------------------------------------------------

# 2. With torch.compile(dynamic=True) – works for t>0, crashes for t=0

# ---------------------------------------------------------------------------

 
compiled = torch.compile(compute, fullgraph=True, dynamic=True)


r3 = compiled(dates, future_date, initial_dfs, target_dfs, half_life)

print(f"  t=3 (future trade):          shape = {r3.shape}")   # torch.Size([3, 12])

r4 = compiled(dates, matured_date, initial_dfs, target_dfs, half_life)

print(f"  shape = {r4.shape}")   # never reached – crashes above
