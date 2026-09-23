import torch
torch.manual_seed(0)

def binary_cross_entropy(
    input: Tensor,
    target: Tensor,
    weight: Tensor | None = None,
    size_average: bool | None = None,
    reduce: bool | None = None,
    reduction: str = "mean",
) -> Tensor:
    r"""Compute Binary Cross Entropy between the target and input probabilities.

    See :class:`~torch.nn.BCELoss` for details.

    Args:
        input: Tensor of arbitrary shape as probabilities.
        target: Tensor of the same shape as input with values between 0 and 1.
        weight (Tensor, optional): a manual rescaling weight
                if provided it's repeated to match input tensor shape
        size_average (bool, optional): Deprecated (see :attr:`reduction`).
        reduce (bool, optional): Deprecated (see :attr:`reduction`).
        reduction (str, optional): Specifies the reduction to apply to the output:
            ``'none'`` | ``'mean'`` | ``'sum'``. ``'none'``: no reduction will be applied,
            ``'mean'``: the sum of the output will be divided by the number of
            elements in the output, ``'sum'``: the output will be summed. Note: :attr:`size_average`
            and :attr:`reduce` are in the process of being deprecated, and in the meantime,
            specifying either of those two args will override :attr:`reduction`. Default: ``'mean'``

    Examples::

        >>> input = torch.randn(3, 2, requires_grad=True)
        >>> target = torch.rand(3, 2, requires_grad=False)
        >>> loss = F.binary_cross_entropy(torch.sigmoid(input), target)
        >>> loss.backward()
    """
    if has_torch_function_variadic(input, target, weight):
        return handle_torch_function(
            binary_cross_entropy,
            (input, target, weight),
            input,
            target,
            weight=weight,
            size_average=size_average,
            reduce=reduce,
            reduction=reduction,
        )
    if size_average is not None or reduce is not None:
        reduction_enum = _Reduction.legacy_get_enum(size_average, reduce)
    else:
        reduction_enum = _Reduction.get_enum(reduction)
    if target.size() != input.size():
        raise ValueError(
            f"Using a target size ({target.size()}) that is different to the input size ({input.size()}) is deprecated. "
            "Please ensure they have the same size."
        )

    if weight is not None:
        new_size = torch.broadcast_shapes(target.size(), weight.size())
        weight = weight.expand(new_size)

    # pyrefly: ignore [bad-argument-type]
    return torch._C._nn.binary_cross_entropy(input, target, weight, reduction_enum)

def opinfo_nn_functional_binary_cross_entropy(*args):
    return binary_cross_entropy(*args)

args = (torch.randn(5), torch.randn(1))

eager = opinfo_nn_functional_binary_cross_entropy(*args)
torch._dynamo.reset()
compiled = torch.compile(opinfo_nn_functional_binary_cross_entropy, backend='eager')(*args)
print('eager   :', eager)
print('compiled:', compiled)
