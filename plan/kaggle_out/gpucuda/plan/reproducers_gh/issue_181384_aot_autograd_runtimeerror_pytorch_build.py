# source: https://github.com/pytorch/pytorch/issues/181384
# title: [aot_autograd] RuntimeError: /pytorch/build/aten/src/ATen/RegisterZeroTensor_0.cpp:254: SymIntArrayRef expected to contain only concrete integers when using torch.compile(dynamic=True) with torch.func.grad over GroupNorm
# state: closed  created: 2026-04-24
# mined automatically; the harness records the torch.compile target and its first call

import os as _os, tempfile as _tmp
_os.environ.setdefault(
    'TORCHINDUCTOR_CACHE_DIR',
    _tmp.mkdtemp(prefix='inductor_'),
)
del _os, _tmp

import torch
import torch.nn as nn
import torch.nn.functional as F

_m_t8952041 = nn.AvgPool2d(2)
_m_t8952043 = nn.LayerNorm([5])
_m_t8952044 = nn.BatchNorm2d(12).eval()
_m_t8952047 = nn.GroupNorm(12, 12).eval()

torch.manual_seed(0)
t8952039 = torch.randn([2, 12, 10, 10])

def model_229908():
    t8952041 = _m_t8952041(t8952039)
    t8952043 = _m_t8952043(t8952041)
    t8952044 = _m_t8952044(t8952043)
    t8952047 = _m_t8952047(t8952044)
    t8952050 = torch.abs(t8952047)
    return t8952050

# Eager forward — works fine
_eager_out = model_229908()
assert torch.isfinite(_eager_out).all(), 'eager output not finite'

# Compiled forward — works fine
_compiled = torch.compile(model_229908, backend='inductor')
_compiled_out = _compiled()
assert torch.isfinite(_compiled_out).all(), 'compiled output not finite'

# eager/compiled output comparison
assert torch.allclose(_eager_out, _compiled_out, atol=1e-4, rtol=1e-4), (
    f'eager/compiled mismatch: max_diff={(_eager_out - _compiled_out).abs().max().item():.6f}'
)

# Backward pass — works fine
_bwd_out = model_229908()
if _bwd_out.grad_fn is not None:
    _bwd_out.mean().backward()
    _all_params = [p for _m in [_m_t8952041, _m_t8952043, _m_t8952044, _m_t8952047] for p in _m.parameters() if p.grad is not None]
    assert all(torch.isfinite(p.grad).all() for p in _all_params), 'non-finite gradients after backward'

# torch.func.grad composed with torch.compile - crashes
import torch.func as _torch_func
def _fn_grad_229908(t8952039):
    t8952041 = _m_t8952041(t8952039)
    t8952043 = _m_t8952043(t8952041)
    t8952044 = _m_t8952044(t8952043)
    t8952047 = _m_t8952047(t8952044)
    t8952050 = torch.abs(t8952047)
    return t8952050.mean()
_fgrad_eager = _torch_func.grad(_fn_grad_229908)(t8952039)
_fgrad_compiled = torch.compile(_torch_func.grad(_fn_grad_229908))(t8952039)
assert torch.allclose(_fgrad_eager, _fgrad_compiled, atol=1e-4, rtol=1e-4), (
    f'func.grad eager/compiled mismatch: max_diff={(_fgrad_eager - _fgrad_compiled).abs().max().item():.6f}'
)
_fgrad_dynamic = torch.compile(_torch_func.grad(_fn_grad_229908), dynamic=True)(t8952039)
assert torch.allclose(_fgrad_eager, _fgrad_dynamic, atol=1e-4, rtol=1e-4), (
    f'func.grad dynamic mismatch: max_diff={(_fgrad_eager - _fgrad_dynamic).abs().max().item():.6f}'
)
