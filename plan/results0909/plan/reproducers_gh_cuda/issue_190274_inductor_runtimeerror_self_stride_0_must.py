# source: https://github.com/pytorch/pytorch/issues/190274
# title: [inductor] RuntimeError: self.stride(0) must be divisible by 2 to view Double as ComplexDouble
# state: open  created: 2026-07-16
# mined automatically; the harness records the torch.compile target and its first call

import torch

_m_t4011 = torch.nn.ReflectionPad1d(-1).eval()

torch.manual_seed(0)
t4010 = torch.randn([3, 3], dtype=torch.complex128)

def model_2450():
    t4011 = _m_t4011(t4010)
    t4012 = torch.trapz(t4011, t4011)
    return t4012

# eager baseline -- succeeds
eager_out = model_2450()
print("eager OK:", type(eager_out))

# inductor compile -- crashes
compiled = torch.compile(model_2450, backend="inductor")
with torch.no_grad():
    compiled_out = compiled()
print("compiled OK:", type(compiled_out))
