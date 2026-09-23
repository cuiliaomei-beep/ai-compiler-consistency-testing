import torch
torch.manual_seed(0)

def multi_margin_loss(
    input: Tensor,
    target: Tensor,
    p: int = 1,
    margin: float = 1.0,
    weight: Tensor | None = None,
    size_average: bool | None = None,
    reduce: bool | None = None,
    reduction: str = "mean",
) -> Tensor:
    r"""Compute the multi margin loss, with optional weighting.

    See :class:`~torch.nn.MultiMarginLoss` for details.

    Args:
        input (Tensor): Predicted values.
        target (Tensor): Ground truth values.
        p (int, optional): Has a default value of 1. 1 and 2 are the only supported values.
        margin (float, optional): Margin for multi margin loss. Has a default value of 1.
        weight (Tensor, optional): Weights for each sample. Default: None.
        size_average (bool, optional): Deprecated (see :attr:`reduction`).
        reduce (bool, optional): Deprecated (see :attr:`reduction`).
        reduction (str, optional): Specifies the reduction to apply to the output:
                                  'none' | 'mean' | 'sum'. 'mean': the mean of the output is taken.
                                  'sum': the output will be summed. 'none': no reduction will be applied.
                                  Default: 'mean'.

    Returns:
        Tensor: Multi margin loss (optionally weighted).
    """
    if has_torch_function_variadic(input, target, weight):
        return handle_torch_function(
            multi_margin_loss,
            (input, target, weight),
            input,
            target,
            p=p,
            margin=margin,
            weight=weight,
            size_average=size_average,
            reduce=reduce,
            reduction=reduction,
        )
    if size_average is not None or reduce is not None:
        reduction_enum = _Reduction.legacy_get_enum(size_average, reduce)
    else:
        reduction_enum = _Reduction.get_enum(reduction)
    if p != 1 and p != 2:
        raise ValueError("only p == 1 and p == 2 supported")
    if weight is not None:
        if weight.dim() != 1:
            raise ValueError("weight must be one-dimensional")

    return torch._C._nn.multi_margin_loss(
        input,
        target,
        p,
        margin,
        weight,
        # pyrefly: ignore [bad-argument-type]
        reduction_enum,
    )

def opinfo_nn_functional_multi_margin_loss(*args):
    return multi_margin_loss(*args, weight=None)

args = (torch.randn(1).to(torch.float16), torch.randint(0, 4, (1,)))

eager = opinfo_nn_functional_multi_margin_loss(*args)
torch._dynamo.reset()
compiled = torch.compile(opinfo_nn_functional_multi_margin_loss, backend='inductor')(*args)
print('eager   :', eager)
print('compiled:', compiled)
