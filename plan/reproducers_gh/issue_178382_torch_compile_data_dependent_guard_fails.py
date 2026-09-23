# source: https://github.com/pytorch/pytorch/issues/178382
# title: [torch.compile] Data-dependent guard fails when printing a boolean value derived from tensor
# state: closed  created: 2026-03-25
# mined automatically; the harness records the torch.compile target and its first call

import torch
import torch.nn as nn
import torch._dynamo

torch._dynamo.config.suppress_errors = False
torch._dynamo.config.verbose = True

class BoolTensorModel(nn.Module):
    def forward(self, x, mask):
        make_causal = bool((mask == 0).all())
        print(f"[Forward] make_causal={make_causal}")
        return x + 1

def main():
    x = torch.randn(2, 3)
    mask = torch.zeros(2, 3)

    model = BoolTensorModel()

    eager_out = model(x, mask)
    print("Eager mode output shape::\n", eager_out)

    try:
        compiled_model = torch.compile(model, fullgraph=True)
        compile_out = compiled_model(x, mask)
        print("Compiled mode output shape:\n", compile_out)
    except Exception as e:
        print("Compile error:\n", e)

if __name__ == "__main__":
    main()
