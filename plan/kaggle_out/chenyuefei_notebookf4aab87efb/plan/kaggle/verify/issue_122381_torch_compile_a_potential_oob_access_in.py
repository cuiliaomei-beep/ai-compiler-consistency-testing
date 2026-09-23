# source: https://github.com/pytorch/pytorch/issues/122381
# title: [torch.compile] A potential OOB access in CUDA for attention model
# state: closed  created: 2024-03-21
# mined automatically; the harness records the torch.compile target and its first call

import torch

torch.manual_seed(420)

class Model(torch.nn.Module):

    def __init__(self, d_model, dropout_p=0.1, inv_scale_factor=1e-08):
        super().__init__()
        self.d_model = d_model
        self.dropout_p = dropout_p
        self.inv_scale_factor = inv_scale_factor
        self.dropout = torch.nn.Dropout(dropout_p)

    def forward(self, query, key, value):
        qk = torch.matmul(query, key.transpose(-2, -1))
        scaled_qk = qk.div(self.inv_scale_factor)
        softmax_qk = scaled_qk.softmax(dim=-1)
        dropout_qk = self.dropout(softmax_qk)
        return dropout_qk

device = "cuda"
d_model = 1
func = Model(10).to(device)

query = torch.randn(1, 5, 10).to(device)

key = torch.randn(1, 5, 10).to(device)

value = torch.randn(1, 5, 10).to(device)

with torch.no_grad():
    naive_result = func(query.clone(), key.clone(), value.clone())

    func1 = torch.compile(func)
    jit_result = func1(query.clone(), key.clone(), value.clone())

    print(naive_result)
    print(jit_result)
    print(torch._dynamo.utils.counters["inductor"])
"""
tensor([[[0.0000, 0.0000, 0.0000, 1.1111, 0.0000],
         [0.0000, 0.0000, 1.1111, 0.0000, 0.0000],
         [0.0000, 0.0000, 0.0000, 0.0000, 1.1111],
         [0.0000, 0.0000, 0.0000, 1.1111, 0.0000],
         [0.0000, 0.0000, 1.1111, 0.0000, 0.0000]]], device='cuda:0')
tensor([[[0.0000e+00, 0.0000e+00, 0.0000e+00, 0.0000e+00, 0.0000e+00],
         [0.0000e+00, 0.0000e+00, 1.6732e+03, 0.0000e+00, 0.0000e+00],
         [0.0000e+00, 0.0000e+00, 0.0000e+00, 0.0000e+00, 4.0731e-10],
         [0.0000e+00, 0.0000e+00, 0.0000e+00, 3.4720e-03, 0.0000e+00],
         [0.0000e+00, 0.0000e+00, 4.0205e+06, 0.0000e+00, 0.0000e+00]]],
       device='cuda:0')
Counter({'pattern_matcher_count': 4, 'pattern_matcher_nodes': 4})
"""
