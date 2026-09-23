import torch
torch.manual_seed(0)

def binary_cross_entropy_with_logits(
    input: Tensor,
    target: Tensor,
    weight: Tensor | None = None,
    size_average: bool | None = None,
    reduce: bool | None = None,
    reduction: str = "mean",
    pos_weight: Tensor | None = None,
) -> Tensor:
    r"""Compute Binary Cross Entropy between target and input logits.

    See :class:`~torch.nn.BCEWithLogitsLoss` for details.

    Args:
        input: Tensor of arbitrary shape as unnormalized scores (often referred to as logits).
        target: Tensor of the same shape as input with values between 0 and 1
        weight (Tensor, optional): a manual rescaling weight. If provided, the dimension
           of weight supports :ref:`broadcasting to a common shape <broadcasting-semantics>`
           with respect to the input (and target) shape.
        size_average (bool, optional): Deprecated (see :attr:`reduction`).
        reduce (bool, optional): Deprecated (see :attr:`reduction`).
        reduction (str, optional): Specifies the reduction to apply to the output:
            ``'none'`` | ``'mean'`` | ``'sum'``. ``'none'``: no reduction will be applied,
            ``'mean'``: the sum of the output will be divided by the number of
            elements in the output, ``'sum'``: the output will be summed. Note: :attr:`size_average`
            and :attr:`reduce` are in the process of being deprecated, and in the meantime,
            specifying either of those two args will override :attr:`reduction`. Default: ``'mean'``
        pos_weight (Tensor, optional): a weight of positive examples to be broadcasted with target.
            Must be a tensor with equal size along the class dimension to the number of classes.
            Pay close attention to PyTorch's broadcasting semantics in order to achieve the desired
            operations. For a target of size [B, C, H, W] (where B is batch size) pos_weight of
            size [B, C, H, W] will apply different pos_weights to each element of the batch or
            [C, H, W] the same pos_weights across the batch. To apply the same positive weight
            along all spatial dimensions for a 2D multi-class target [C, H, W] use: [C, 1, 1].
            Default: ``None``

    Examples::

         >>> input = torch.randn(3, requires_grad=True)
         >>> target = torch.empty(3).random_(2)
         >>> loss = F.binary_cross_entropy_with_logits(input, target)
         >>> loss.backward()
    """
    if has_torch_function_variadic(input, target, weight, pos_weight):
        return handle_torch_function(
            binary_cross_entropy_with_logits,
            (input, target, weight, pos_weight),
            input,
            target,
            weight=weight,
            size_average=size_average,
            reduce=reduce,
            reduction=reduction,
            pos_weight=pos_weight,
        )
    if size_average is not None or reduce is not None:
        reduction_enum = _Reduction.legacy_get_enum(size_average, reduce)
    else:
        reduction_enum = _Reduction.get_enum(reduction)

    if not (target.size() == input.size()):
        raise ValueError(
            f"Target size ({target.size()}) must be the same as input size ({input.size()})"
        )

    return torch.binary_cross_entropy_with_logits(
        input, target, weight, pos_weight, reduction_enum
    )

def opinfo_nn_functional_binary_cross_entropy_with_logits(*args):
    return binary_cross_entropy_with_logits(*args, reduction='mean', pos_weight=torch.tensor([0.5857021808624268, 0.058428168296813965, 4.531130313873291, 2.773437976837158, 3.3676023483276367], dtype=torch.float32))

args = (torch.randn(5, 5), torch.randn(1, 5))

eager = opinfo_nn_functional_binary_cross_entropy_with_logits(*args)
torch._dynamo.reset()
compiled = torch.compile(opinfo_nn_functional_binary_cross_entropy_with_logits, backend='eager')(*args)
print('eager   :', eager)
print('compiled:', compiled)
