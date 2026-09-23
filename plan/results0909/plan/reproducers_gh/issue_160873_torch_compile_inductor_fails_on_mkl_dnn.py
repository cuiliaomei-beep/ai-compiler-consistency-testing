# source: https://github.com/pytorch/pytorch/issues/160873
# title: `torch.compile` (Inductor) fails on MKL-DNN tensor densify (`to_dense`) with "Cannot access data pointer of Tensor that doesn't have storage"
# state: closed  created: 2025-08-18
# mined automatically; the harness records the torch.compile target and its first call

# repro_mkldnn_to_dense_compile.py
import torch
from torch import nn

class MyModel(nn.Module):
    def forward(self, x):
        x = x.to_dense()   # densify MKL-DNN tensor
        return x + 1       # simple elementwise op

def get_input():
    x = torch.randn(4, 4)
    x_mkldnn = x.to_mkldnn()     # construct mkldnn layout input
    assert x_mkldnn.is_mkldnn
    return x_mkldnn

def main():
    model = MyModel().eval()
    inp = get_input()

    # 1) Eager mode
    eager_out = model(inp)
    expected = inp.to_dense() + 1
    torch.testing.assert_close(eager_out, expected)
    print("[eager] OK, out shape:", tuple(eager_out.shape), "is_mkldnn:", eager_out.is_mkldnn)

    # 2) AOT-Eager backend
    compiled_ok = torch.compile(model, backend="aot_eager")
    out_ok = compiled_ok(inp.to_dense())  # feeding dense also works
    torch.testing.assert_close(out_ok, expected)
    print("[compile:aot_eager] OK, out shape:", tuple(out_ok.shape), "is_mkldnn:", out_ok.is_mkldnn)

    # 3) Inductor (default)
    compiled = torch.compile(model)  # backend='inductor'
    out = compiled(inp)              # <-- RuntimeError here
    torch.testing.assert_close(out, expected)

if __name__ == "__main__":
    main()
