# source: https://github.com/pytorch/pytorch/issues/175830
# title: Numerical discrepancy in nn.LSTM between eager and compile modes with INDUCTOR_SHAPE_PADDING
# state: closed  created: 2026-02-26
# mined automatically; the harness records the torch.compile target and its first call

import torch
import torch.nn as nn
import os
import contextlib

torch.manual_seed(42)
torch.cuda.manual_seed_all(42)

@contextlib.contextmanager
def set_inductor_env_vars():
    original = os.environ.get("INDUCTOR_SHAPE_PADDING")
    try:
        os.environ["INDUCTOR_SHAPE_PADDING"] = "1"
        yield
    finally:
        if original is None:
            os.environ.pop("INDUCTOR_SHAPE_PADDING", None)
        else:
            os.environ["INDUCTOR_SHAPE_PADDING"] = original

def compare(t_a, t_b):
    a, b = t_a.detach().cpu().float(), t_b.detach().cpu().float()
    max_abs = torch.abs(a - b).max().item()
    l2_a, l2_b = torch.norm(a), torch.norm(b)
    rel_l2 = (torch.norm(a - b) / torch.maximum(l2_a, l2_b).clamp(min=1e-8)).item()
    return max_abs, rel_l2

def run_mode(lstm_layer, x_in, dev, dtype, opt):
    lstm = lstm_layer.to(dev).to(dtype).eval()
    if opt != "0000":
        with set_inductor_env_vars():
            lstm = torch.compile(lstm)
    with torch.no_grad():
        return lstm(x_in.to(dev).to(dtype))[0]

def run():
    x_in = torch.randn(64, 10, 50)
    lstm_layer = nn.LSTM(input_size=50, hidden_size=50, num_layers=1, batch_first=True, bidirectional=False)
    
    print("Input: shape={}".format(x_in.shape))
    print("Input - min: {:.6f}, max: {:.6f}, mean: {:.6f}".format(x_in.min().item(), x_in.max().item(), x_in.mean().item()))
    print("Input - has NaN: {}, has Inf: {}".format(torch.isnan(x_in).any().item(), torch.isinf(x_in).any().item()))
    print("=" * 60)
    
    modes = [
        ("Mode A (cuda/f32/0000)", 'cuda', torch.float32, '0000'),
        ("Switch Device (cpu/f32/0000)", 'cpu', torch.float32, '0000'),
        ("Switch Dtype (cuda/f16/0000)", 'cuda', torch.float16, '0000'),
        ("Switch Optimization (cuda/f32/0010)", 'cuda', torch.float32, '0010')
    ]
    
    outputs = {}
    for label, dev, dtype, opt in modes:
        print(f"\n>>> Running {label} ...")
        outputs[label] = run_mode(lstm_layer, x_in, dev, dtype, opt)
        has_nan = torch.isnan(outputs[label]).any().item()
        has_inf = torch.isinf(outputs[label]).any().item()
        print(f"  ✓ {label} executed successfully")
        print(f"  Output - min: {outputs[label].min().item():.6f}, max: {outputs[label].max().item():.6f}, mean: {outputs[label].mean().item():.6f}")
        print(f"  Output - has NaN: {has_nan}, has Inf: {has_inf}")
    
    ma_name = modes[0][0]
    for switch_idx in range(1, len(modes)):
        mb_name = modes[switch_idx][0]
        max_d, max_rd = compare(outputs[ma_name], outputs[mb_name])
        exceeds = "Yes" if max_rd > 1e-4 else "No"
        status = "DIFF > 1e-4" if max_rd > 1e-4 else "OK"
        
        print("\n" + "="*120)
        print(f"Comparison: {ma_name} vs {mb_name}")
        print("="*120)
        print(f"{'Layer Name':<40} | {'Max Abs Error':<15} | {'Rel L2 Error':<15} | {'> 1e-4':<8} | {'Status'}")
        print("-" * 120)
        print(f"{'lstm1':<40} | {max_d:.4e} | {max_rd:.4e} | {exceeds:<8} | {status}")
        print("="*120)

if __name__ == "__main__":
    run()
