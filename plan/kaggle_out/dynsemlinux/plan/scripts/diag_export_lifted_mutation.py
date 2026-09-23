"""Does torch.export keep or drop the in-place update of a closure-captured (lifted constant) running_mean?"""
import torch, torch.nn.functional as F
from torch.export import export
print("torch", torch.__version__)
RM, RV = torch.zeros(3), torch.ones(3)
class M(torch.nn.Module):
    def forward(self, x):
        return F.instance_norm(x, RM, RV, use_input_stats=True)
x = torch.randn(2, 3, 4, 4)
before = RM.clone(); M()(x); eager_delta = (RM - before).abs().sum().item(); RM.copy_(before)
ep = export(M(), (x,))
gm = ep.module()
consts = {k: (v.data_ptr() == RM.data_ptr()) for k, v in ep.constants.items()}
print("ep.constants aliases RM:", consts)
gm(x); d1 = (RM - before).abs().sum().item()
gm(x); d2 = (RM - before).abs().sum().item()
print(f"eager updates RM by {eager_delta:.4f}; after ep.module() call 1 RM delta={d1:.4f}, call 2 delta={d2:.4f}")
# does a second export (with the mutated RM) see the same constant, and does torch.compile behave like eager?
RM.copy_(before); torch._dynamo.reset(); torch.compile(M())(x); dc = (RM - before).abs().sum().item(); RM.copy_(before)
print(f"torch.compile updates RM by {dc:.4f}")
# graph: is the mutation represented as an output (buffer mutation) or as a copy_ on a constant?
sig = ep.graph_signature
print("buffers_to_mutate:", getattr(sig, "buffers_to_mutate", None), "| user_inputs_to_mutate:", getattr(sig, "user_inputs_to_mutate", None))
print("graph has copy_ nodes:", any("copy_" in str(n.target) for n in ep.graph.nodes))
