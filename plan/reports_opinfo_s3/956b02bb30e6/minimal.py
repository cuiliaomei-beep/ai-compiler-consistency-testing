import torch
torch.manual_seed(0)

def local_response_norm(
    input: Tensor,
    size: int,
    alpha: float = 1e-4,
    beta: float = 0.75,
    k: float = 1.0,
) -> Tensor:
    r"""Apply local response normalization over an input signal.

    The input signal is composed of several input planes, where channels occupy the second dimension.
    Normalization is applied across channels.

    See :class:`~torch.nn.LocalResponseNorm` for details.
    """
    if has_torch_function_unary(input):
        return handle_torch_function(
            local_response_norm, (input,), input, size, alpha=alpha, beta=beta, k=k
        )
    dim = input.dim()
    if dim < 3:
        raise ValueError(
            f"Expected 3D or higher dimensionality                          input (got {dim} dimensions)"
        )

    if input.numel() == 0:
        return input

    div = input.mul(input)
    if dim == 3:
        div = div.unsqueeze(1)
        # pyrefly: ignore [bad-argument-type]
        div = pad(div, (0, 0, size // 2, (size - 1) // 2))
        div = avg_pool2d(div, (size, 1), stride=1).squeeze(1)
    else:
        sizes = input.size()
        div = div.view(sizes[0], 1, sizes[1], sizes[2], -1)
        # pyrefly: ignore [bad-argument-type]
        div = pad(div, (0, 0, 0, 0, size // 2, (size - 1) // 2))
        div = avg_pool3d(div, (size, 1, 1), stride=1).squeeze(1)
        div = div.view(sizes)
    div = div.mul(alpha).add(k).pow(beta)
    return input / div

def opinfo_nn_functional_local_response_norm(*args):
    return local_response_norm(*args, 2, beta=0.5)

args = (torch.randn(6, 3),)

eager = opinfo_nn_functional_local_response_norm(*args)
torch._dynamo.reset()
compiled = torch.compile(opinfo_nn_functional_local_response_norm, backend='eager')(*args)
print('eager   :', eager)
print('compiled:', compiled)
