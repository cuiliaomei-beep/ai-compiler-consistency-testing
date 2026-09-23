# source: https://github.com/pytorch/pytorch/issues/188048
# title: [Inductor][CUDA] torch.div(rounding_mode="floor") mismatches eager for infinite inputs
# state: closed  created: 2026-06-24
# mined automatically; the harness records the torch.compile target and its first call

import torch
import torch._dynamo
import torch._inductor.config

torch._inductor.config.fallback_random = True


def fn(a, b):
    return torch.div(a, b, rounding_mode="floor")


def main():
    print("torch:", torch.__version__)
    print("cuda:", torch.version.cuda)

    device = "cuda"
    dtype = torch.float64

    a = torch.tensor(
        [float("nan"), float("inf"), -float("inf")],
        device=device,
        dtype=dtype,
    )
    b = torch.tensor(
        [1.0, 1.0, 1.0],
        device=device,
        dtype=dtype,
    )

    eager_out_1 = fn(a,b)
    eager_out_2 = fn(b,a)
    torch.cuda.synchronize()

    torch._dynamo.reset()
    compiled_fn = torch.compile(fn, backend="inductor", fullgraph=True)
    compiled_out_1 = compiled_fn(a, b)
    compiled_out_2 = compiled_fn(b, a)
    torch.cuda.synchronize()

    print("\ninput a:", a)
    print("input b:", b)

    print("\neager output:")
    print("\na/b:")
    print(eager_out_1)
    print("\nb/a:")
    print(eager_out_2)

    print("\ninductor output:")
    print("\na/b:")
    print(compiled_out_1)
    print("\nb/a:")
    print(compiled_out_2)



if __name__ == "__main__":
    main()
