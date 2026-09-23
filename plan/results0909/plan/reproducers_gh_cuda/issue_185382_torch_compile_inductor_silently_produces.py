# source: https://github.com/pytorch/pytorch/issues/185382
# title: `torch.compile`: Inductor silently produces wrong results for `addcdiv_`/`addcmul_` when `.item()` graph break occurs in a loop
# state: closed  created: 2026-05-27
# mined automatically; the harness records the torch.compile target and its first call

import torch
import torch._dynamo

def adam_step(param, grad, m, v, step_t):
    step_t.add_(1)
    m.mul_(0.9).add_(grad, alpha=0.1)
    v.mul_(0.999).addcmul_(grad, grad, value=0.001)
    step = step_t.item()  # graph break
    bc1 = 1 - 0.9 ** step
    bc2 = 1 - 0.999 ** step
    step_size = 0.001 / bc1
    denom = (v.sqrt() / (bc2 ** 0.5)).add_(1e-8)
    param.addcdiv_(m, denom, value=-step_size)

def train_loop(param_data, grad_data):
    p = param_data.clone()
    g = grad_data.clone()
    m = torch.zeros_like(p)
    v = torch.zeros_like(p)
    s = torch.tensor(0.0, device=p.device)
    for _ in range(3):
        adam_step(p, g, m, v, s)
    return p

torch.manual_seed(42)
p = torch.randn(128, device="cuda")
g = torch.randn(128, device="cuda")

eager_out = train_loop(p.clone(), g.clone())

torch._dynamo.reset()
compiled_out = torch.compile(train_loop, backend="inductor")(p.clone(), g.clone())
torch.cuda.synchronize()

torch._dynamo.reset()
aot_out = torch.compile(train_loop, backend="aot_eager")(p.clone(), g.clone())

print(f"Eager vs Inductor:  {(eager_out - compiled_out).abs().max().item():.6e}")  # 4.263520e-04 ← WRONG
print(f"Eager vs aot_eager: {(eager_out - aot_out).abs().max().item():.6e}")       # 2.328306e-10 ← correct
