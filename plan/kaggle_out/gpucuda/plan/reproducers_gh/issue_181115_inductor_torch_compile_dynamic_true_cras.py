# source: https://github.com/pytorch/pytorch/issues/181115
# title: [inductor] torch.compile(dynamic=True) crashes in TorchInductor CPU codegen with AttributeError: 'StrictLessThan' object has no attribute 'diff'
# state: closed  created: 2026-04-22
# mined automatically; the harness records the torch.compile target and its first call

import torch
import torch.nn as nn
import torch.nn.functional as F

_m_t25553926 = nn.Linear(3, 11)
_m_t25553927 = nn.AvgPool2d(2)
_m_t25553934 = nn.AvgPool2d(2)

torch.manual_seed(0)
t25553925 = torch.randn([16, 16, 9, 3])

def model_551427():
    t25553926 = _m_t25553926(t25553925)
    t25553927 = _m_t25553927(t25553926)
    t25553934 = _m_t25553934(t25553927)
    t25553936 = F.gelu(t25553934, approximate='tanh')
    return t25553936

# Eager forward — works fine
_eager_out = model_551427()
assert torch.isfinite(_eager_out).all(), 'eager output not finite'

# Compiled forward — works fine
_compiled = torch.compile(model_551427, backend='inductor')
_compiled_out = _compiled()
assert torch.isfinite(_compiled_out).all(), 'compiled output not finite'

# eager/compiled output comparison
assert torch.allclose(_eager_out, _compiled_out, atol=1e-4, rtol=1e-4), (
    f'eager/compiled mismatch: max_diff={(_eager_out - _compiled_out).abs().max().item():.6f}'
)

# Backward pass — works fine
_bwd_out = model_551427()
if _bwd_out.grad_fn is not None:
    _bwd_out.mean().backward()
    _all_params = [p for _m in [_m_t25553926, _m_t25553927, _m_t25553934] for p in _m.parameters() if p.grad is not None]
    assert all(torch.isfinite(p.grad).all() for p in _all_params), 'non-finite gradients after backward'

# torch.func.grad composed with torch.compile — works fine
import torch.func as _torch_func
def _fn_grad_551427(t25553925):
    t25553926 = _m_t25553926(t25553925)
    t25553927 = _m_t25553927(t25553926)
    t25553934 = _m_t25553934(t25553927)
    t25553936 = F.gelu(t25553934, approximate='tanh')
    return t25553936.mean()
_fgrad_eager = _torch_func.grad(_fn_grad_551427)(t25553925)
_fgrad_compiled = torch.compile(_torch_func.grad(_fn_grad_551427))(t25553925)
assert torch.allclose(_fgrad_eager, _fgrad_compiled, atol=1e-4, rtol=1e-4), (
    f'func.grad eager/compiled mismatch: max_diff={(_fgrad_eager - _fgrad_compiled).abs().max().item():.6f}'
)

# torch.func.grad composed with torch.compile and dynamic=True — crashes
_fgrad_dynamic = torch.compile(_torch_func.grad(_fn_grad_551427), dynamic=True)(t25553925)
assert torch.allclose(_fgrad_eager, _fgrad_dynamic, atol=1e-4, rtol=1e-4), (
    f'func.grad dynamic mismatch: max_diff={(_fgrad_eager - _fgrad_dynamic).abs().max().item():.6f}'
)
