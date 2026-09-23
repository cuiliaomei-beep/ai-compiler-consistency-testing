# source: https://github.com/pytorch/pytorch/issues/95161
# title: AOTAutograd based torch.compile doesn't capture manual seed setting in the graph
# state: closed  created: 2023-02-20
# mined automatically; the harness records the torch.compile target and its first call

from typing import List
import torch
import torch._dynamo as dynamo
from torch._functorch.aot_autograd import aot_module_simplified

dynamo.reset()

def my_non_aot_compiler(gm: torch.fx.GraphModule, example_inputs: List[torch.Tensor]):
    print(gm.code)
    return gm.forward

def my_aot_compiler(gm: torch.fx.GraphModule, example_inputs: List[torch.Tensor]):
    def my_compiler(gm: torch.fx.GraphModule, example_inputs: List[torch.Tensor]):
        print(gm.code)
        return gm.forward

    # Invoke AOTAutograd
    return aot_module_simplified(
        gm,
        example_inputs,
        fw_compiler=my_compiler
    )

def my_example():
    torch.manual_seed(0)
    d_float32 = torch.rand((8, 8), device="cpu")
    return d_float32 + d_float32

compiled_fn = torch.compile(backend=my_aot_compiler)(my_example)
#compiled_fn = torch.compile(backend=my_non_aot_compiler)(my_example)

r1 = compiled_fn()
r2 = compiled_fn()
print("Results match? ", torch.allclose(r1, r2, atol = 0.001, rtol = 0.001))
