# source: https://github.com/pytorch/pytorch/issues/109105
# title: Inductor-Compiled Modules Produce  Incorrect Result When Handling Distributive Property of Multiplication
# state: closed  created: 2023-09-12
# mined automatically; the harness records the torch.compile target and its first call

import copy
import numpy as np
import torch
import pickle

class M1(torch.nn.Module):
    def __init__(self):
        super().__init__()
        self.c1 = torch.nn.Parameter(torch.tensor([6], dtype=torch.int8), requires_grad=False)
    def forward(self, *args):
        x = args[0]
        y = args[1]
        c1 = self.c1
        mul = torch.mul(c1, x)
        mul_1 = torch.mul(mul, y)
        add = torch.add(mul_1, mul)
        res = add.to(dtype = torch.float64)
        # res = (c1 * x * y) + (c1 * x)
        return res

class M2(torch.nn.Module):
    def __init__(self):
        super().__init__()
        self.c1 = torch.nn.Parameter(torch.tensor([6], dtype=torch.int8), requires_grad=False)
    def forward(self, *args):
        x = args[0]
        y = args[1]
        c1 = self.c1
        mul2 = torch.mul(c1, y)
        add = torch.add(mul2, c1)
        mul3 = torch.mul(add, x)
        res = mul3.to(dtype = torch.float64)
        # res = (c1 * y + c1) * x
        return res

# Obviously, (c1 * x * y) + (c1 * x) = (c1 * y + c1) * x
m1 = M1()
m2 = M2()

# inp_1 = [np.array(5, dtype='int8'), np.random.randn(32, 31, 1, 38, 1).astype('int8')]
special_input = pickle.load(open('./1.pickle', 'rb'))
inp_1 = [v for _, v in special_input.items()]

inp_2 = copy.deepcopy(inp_1)

m_out1 = m1(*[torch.from_numpy(v).to('cpu') for v in inp_1])
m_out2 = m2(*[torch.from_numpy(v).to('cpu') for v in inp_2])

# running without inductor will produce consistent results
np.testing.assert_allclose(m_out1, m_out2, rtol=1e-2, atol=1e-3, err_msg=f"Result mismatch")

opt1 = torch.compile(m1, fullgraph=True, backend='inductor', mode=None)
opt2 = torch.compile(m2, fullgraph=True, backend='inductor', mode=None)
opt_out1 = opt1(*[torch.from_numpy(v).to('cpu') for v in inp_1])
opt_out2 = opt2(*[torch.from_numpy(v).to('cpu') for v in inp_2])

# running with inductor will produce inconsistent results
np.testing.assert_allclose(opt_out1, opt_out2, rtol=1e-2, atol=1e-3, err_msg=f"Result mismatch") # Here will raise assertion failure
