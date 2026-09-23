# source: https://github.com/pytorch/pytorch/issues/195418
# title: [dynamo] canonicalize_output_graph_node_order silently drops torch.inference_mode()'s effect from the compiled graph
# state: closed  created: 2026-08-31
# mined automatically; the harness records the torch.compile target and its first call

import torch
import torch._dynamo.config as config

config.canonicalize_output_graph_node_order = True

def fn(x):
    with torch.inference_mode():
        return x + 1

x = torch.tensor(1.0, requires_grad=True)
ref = fn(x)
res = torch.compile(fn, backend="eager", fullgraph=True)(x)

print("ref.requires_grad:", ref.requires_grad, "is_inference:", torch.is_inference(ref))
print("res.requires_grad:", res.requires_grad, "is_inference:", torch.is_inference(res))
