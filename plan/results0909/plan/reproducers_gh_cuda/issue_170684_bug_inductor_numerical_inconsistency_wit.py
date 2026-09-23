# source: https://github.com/pytorch/pytorch/issues/170684
# title: [Bug][Inductor] Numerical inconsistency with eager for aten.cosine_similarity
# state: closed  created: 2025-12-17
# mined automatically; the harness records the torch.compile target and its first call

import torch

def model_func(x1, x2, dim, eps):
    out = torch.ops.aten.cosine_similarity(x1, x2=x2,dim=dim,eps=eps,)
    return out

op_config = {'x1':torch.randn([5, 6, 7],dtype=torch.bfloat16, device='cuda') * 0.1,'x2':torch.randn([5, 6, 7],dtype=torch.bfloat16, device='cuda') * 0.1,'dim':2,'eps':1e-05,}
compiled_eager = torch.compile(model_func, backend="eager")
out1 = compiled_eager(**op_config)
compiled_inductor = torch.compile(model_func, backend="inductor", options={"trace.enabled": True,})
out_inductor = compiled_inductor(**op_config)
torch.testing.assert_close(out1, out_inductor)
