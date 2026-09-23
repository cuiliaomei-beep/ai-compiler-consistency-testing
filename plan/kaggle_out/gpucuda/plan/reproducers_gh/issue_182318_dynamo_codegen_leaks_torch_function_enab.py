# source: https://github.com/pytorch/pytorch/issues/182318
# title: Dynamo codegen leaks torch function enabled state via _EnableTorchFunction destructor
# state: open  created: 2026-05-04
# mined automatically; the harness records the torch.compile target and its first call

import torch

@torch.compile(backend="eager")
def repro():
    with torch._C.DisableTorchFunctionSubclass():
        g = torch._C._EnableTorchFunction()
        del g

repro()
print(torch._C._is_torch_function_enabled())  # prints False, should be True
print(torch._C._get_torch_function_state())   # prints SUBCLASSES_DISABLED, should be ENABLED
