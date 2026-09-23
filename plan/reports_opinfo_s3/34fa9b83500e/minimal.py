import torch
torch.manual_seed(0)

def interpolate(  # noqa: F811
    input: Tensor,
    size: int | None = None,
    scale_factor: list[float] | None = None,
    mode: str = "nearest",
    align_corners: bool | None = None,
    recompute_scale_factor: bool | None = None,
    antialias: bool = False,
) -> Tensor:
    r"""Down/up samples the input.

    Tensor interpolated to either the given :attr:`size` or the given
    :attr:`scale_factor`

    The algorithm used for interpolation is determined by :attr:`mode`.

    Currently temporal, spatial and volumetric sampling are supported, i.e.
    expected inputs are 3-D, 4-D or 5-D in shape.

    The input dimensions are interpreted in the form:
    `mini-batch x channels x [optional depth] x [optional height] x width`.

    The modes available for resizing are: `nearest`, `linear` (3D-only),
    `bilinear`, `bicubic` (4D-only), `trilinear` (5D-only), `lanczos` (4D-only, CPU only), `area`, `nearest-exact`

    Args:
        input (Tensor): the input tensor
        size (int or Tuple[int] or Tuple[int, int] or Tuple[int, int, int]):
            output spatial size.
        scale_factor (float or Tuple[float]): multiplier for spatial size. If `scale_factor` is a tuple,
            its length has to match the number of spatial dimensions; `input.dim() - 2`.
        mode (str): algorithm used for upsampling:
            ``'nearest'`` | ``'linear'`` | ``'bilinear'`` | ``'bicubic'`` |
            ``'trilinear'`` | ``'lanczos'`` | ``'area'`` | ``'nearest-exact'``. Default: ``'nearest'``
        align_corners (bool, optional): Geometrically, we consider the pixels of the
            input and output as squares rather than points.
            If set to ``True``, the input and output tensors are aligned by the
            center points of their corner pixels, preserving the values at the corner pixels.
            If set to ``False``, the input and output tensors are aligned by the corner
            points of their corner pixels, and the interpolation uses edge value padding
            for out-of-boundary values, making this operation *independent* of input size
            when :attr:`scale_factor` is kept the same. This only has an effect when :attr:`mode`
            is ``'linear'``, ``'bilinear'``, ``'bicubic'`` or ``'trilinear'``.
            Default: ``None``. ``None`` leaves :attr:`align_corners` unset for modes
            that do not use it. For modes that use :attr:`align_corners`, ``None``
            is treated as ``False``.
        recompute_scale_factor (bool, optional): recompute the scale_factor for use in the
            interpolation calculation. If `recompute_scale_factor` is ``True``, then
            `scale_factor` must be passed in and `scale_factor` is used to compute the
            output `size`. The computed output `size` will be used to infer new scales for
            the interpolation. Note that when `scale_factor` is floating-point, it may differ
            from the recomputed `scale_factor` due to rounding and precision issues.
            If `recompute_scale_factor` is ``False``, then `size` or `scale_factor` will
            be used directly for interpolation. Default: ``None``.
        antialias (bool, optional): flag to apply anti-aliasing. Default: ``False``. Using anti-alias
            option together with ``align_corners=False``, interpolation result would match Pillow
            result for downsampling operation. Supported modes: ``'bilinear'``, ``'bicubic'``, ``'lanczos'``.

    .. note::
        With ``mode='bicubic'`` or ``mode='lanczos'``, it's possible to cause overshoot. For some dtypes, it can produce
        negative values or values greater than 255 for images. Explicitly call ``result.clamp(min=0,max=255)``
        if you want to reduce the overshoot when displaying the image.
        For ``uint8`` inputs, it already performs saturating cast operation. So, no manual `clamp` operation is needed.

    .. note::
        Mode ``mode='lanczos'`` uses a Lanczos-3 windowed sinc filter (6 taps) and requires
        ``antialias=True``. It only supports 4-D input (i.e. 2D spatial) and CPU. With ``antialias=True``
        and ``align_corners=False``, the result matches PIL's ``Image.LANCZOS`` resampling filter.

    .. note::
        Mode ``mode='nearest-exact'`` matches Scikit-Image and PIL nearest neighbours interpolation
        algorithms and fixes known issues with ``mode='nearest'``. This mode is introduced to keep
        backward compatibility.
        Mode ``mode='nearest'`` matches buggy OpenCV's ``INTER_NEAREST`` interpolation algorithm.

    .. note::
        The gradients for the dtype ``float16`` on CUDA may be inaccurate in the upsample operation
        when using modes ``['linear', 'bilinear', 'bicubic', 'trilinear', 'area']``.
        For more details, please refer to the discussion in
        `issue#104157 <https://github.com/pytorch/pytorch/issues/104157>`_.

    Note:
        {backward_reproducibility_note}
    """
    if has_torch_function_unary(input):
        return handle_torch_function(
            interpolate,  # pyrefly: ignore [bad-argument-type]
            (input,),
            input,
            size=size,
            scale_factor=scale_factor,  # pyrefly: ignore [bad-argument-type]
            mode=mode,
            align_corners=align_corners,
            recompute_scale_factor=recompute_scale_factor,
            antialias=antialias,
        )

    if mode in ("nearest", "area", "nearest-exact"):
        if align_corners is not None:
            raise ValueError(
                "align_corners option can only be set with the "
                "interpolating modes: linear | bilinear | bicubic | trilinear"
            )
    else:
        if align_corners is None:
            align_corners = False

    dim = input.dim() - 2  # Number of spatial dimensions.

    # Process size and scale_factor.  Validate that exactly one is set.
    # Validate its length if it is a list, or expand it if it is a scalar.
    # After this block, exactly one of output_size and scale_factors will
    # be non-None, and it will be a list (or tuple).
    if size is not None and scale_factor is not None:
        raise ValueError("only one of size or scale_factor should be defined")
    elif size is not None:
        if scale_factor is not None:
            raise AssertionError("scale_factor must be None when size is specified")
        scale_factors = None
        if isinstance(size, (list, tuple)):
            if len(size) != dim:
                raise ValueError(
                    "Input and output must have the same number of spatial dimensions, but got "
                    f"input with spatial dimensions of {list(input.shape[2:])} and output size of {size}. "
                    "Please provide input tensor in (N, C, d1, d2, ...,dK) format and "
                    "output size in (o1, o2, ...,oK) format."
                )
            if not torch.jit.is_scripting():
                if not all(_is_integer(x) for x in size):
                    raise TypeError(
                        "expected size to be one of int or Tuple[int] or Tuple[int, int] or "
                        f"Tuple[int, int, int], but got size with types {[type(x) for x in size]}"
                    )
            output_size = size
        else:
            output_size = [size for _ in range(dim)]
    elif scale_factor is not None:
        if size is not None:
            raise AssertionError("size must be None when scale_factor is specified")
        output_size = None
        if isinstance(scale_factor, (list, tuple)):
            if len(scale_factor) != dim:
                raise ValueError(
                    "Input and scale_factor must have the same number of spatial dimensions, but "
                    f"got input with spatial dimensions of {list(input.shape[2:])} and "
                    f"scale_factor of shape {scale_factor}. "
                    "Please provide input tensor in (N, C, d1, d2, ...,dK) format and "
                    "scale_factor in (s1, s2, ...,sK) format."
                )
            scale_factors = scale_factor
        else:
            scale_factors = [scale_factor for _ in range(dim)]
    else:
        raise ValueError("either size or scale_factor should be defined")

    if (
        recompute_scale_factor is not None
        and recompute_scale_factor
        and size is not None
    ):
        raise ValueError(
            "recompute_scale_factor is not meaningful with an explicit size."
        )

    # "area" mode always requires an explicit size rather than scale factor.
    # Reuse the recompute_scale_factor code path.
    if mode == "area" and output_size is None:
        recompute_scale_factor = True

    if recompute_scale_factor is not None and recompute_scale_factor:
        # We compute output_size here, then un-set scale_factors.
        # The C++ code will recompute it based on the (integer) output size.
        if scale_factors is None:
            raise AssertionError("scale_factors is unexpectedly None")
        if not torch.jit.is_scripting() and torch._C._get_tracing_state():
            # make scale_factor a tensor in tracing so constant doesn't get baked in
            output_size = [
                (
                    torch.floor(
                        (
                            # pyrefly: ignore [missing-attribute]
                            input.size(i + 2).float()
                            * torch.tensor(scale_factors[i], dtype=torch.float32)
                        ).float()
                    )
                )
                for i in range(dim)
            ]
        elif torch.jit.is_scripting():
            output_size = [
                math.floor(float(input.size(i + 2)) * scale_factors[i])
                for i in range(dim)
            ]
        else:
            output_size = [
                _sym_int(input.size(i + 2) * scale_factors[i]) for i in range(dim)
            ]
        scale_factors = None

    if antialias and not (
        mode in ("bilinear", "bicubic", "lanczos") and input.ndim == 4
    ):
        raise ValueError(
            "Anti-alias option is restricted to bilinear, bicubic, and lanczos modes and requires a 4-D tensor as input"
        )

    if input.dim() == 3 and mode == "nearest":
        # pyrefly: ignore [bad-argument-type]
        return torch._C._nn.upsample_nearest1d(input, output_size, scale_factors)
    if input.dim() == 4 and mode == "nearest":
        # pyrefly: ignore [bad-argument-type]
        return torch._C._nn.upsample_nearest2d(input, output_size, scale_factors)
    if input.dim() == 5 and mode == "nearest":
        # pyrefly: ignore [bad-argument-type]
        return torch._C._nn.upsample_nearest3d(input, output_size, scale_factors)

    if input.dim() == 3 and mode == "nearest-exact":
        # pyrefly: ignore [bad-argument-type]
        return torch._C._nn._upsample_nearest_exact1d(input, output_size, scale_factors)
    if input.dim() == 4 and mode == "nearest-exact":
        # pyrefly: ignore [bad-argument-type]
        return torch._C._nn._upsample_nearest_exact2d(input, output_size, scale_factors)
    if input.dim() == 5 and mode == "nearest-exact":
        # pyrefly: ignore [bad-argument-type]
        return torch._C._nn._upsample_nearest_exact3d(input, output_size, scale_factors)

    if input.dim() == 3 and mode == "area":
        if output_size is None:
            raise AssertionError("output_size is unexpectedly None")
        # pyrefly: ignore [bad-argument-type]
        return adaptive_avg_pool1d(input, output_size)
    if input.dim() == 4 and mode == "area":
        if output_size is None:
            raise AssertionError("output_size is unexpectedly None")
        return adaptive_avg_pool2d(input, output_size)
    if input.dim() == 5 and mode == "area":
        if output_size is None:
            raise AssertionError("output_size is unexpectedly None")
        return adaptive_avg_pool3d(input, output_size)

    if input.dim() == 3 and mode == "linear":
        if align_corners is None:
            raise AssertionError("align_corners is unexpectedly None")
        return torch._C._nn.upsample_linear1d(
            input,
            # pyrefly: ignore [bad-argument-type]
            output_size,
            align_corners,
            scale_factors,
        )
    if input.dim() == 4 and mode == "bilinear":
        if align_corners is None:
            raise AssertionError("align_corners is unexpectedly None")
        if antialias:
            return torch._C._nn._upsample_bilinear2d_aa(
                input,
                # pyrefly: ignore [bad-argument-type]
                output_size,
                align_corners,
                scale_factors,
            )
        # Two levels are necessary to prevent TorchScript from touching
        # are_deterministic_algorithms_enabled.
        if not torch.jit.is_scripting():
            if not input.is_cpu and torch.are_deterministic_algorithms_enabled():
                # Use slow decomp whose backward will be in terms of index_put
                # importlib is required because the import cannot be top level
                # (cycle) and cannot be nested (TS doesn't support)
                return importlib.import_module(
                    "torch._decomp.decompositions"
                )._upsample_linear_vec(input, output_size, align_corners, scale_factors)
        return torch._C._nn.upsample_bilinear2d(
            input,
            # pyrefly: ignore [bad-argument-type]
            output_size,
            align_corners,
            scale_factors,
        )
    if input.dim() == 5 and mode == "trilinear":
        if align_corners is None:
            raise AssertionError("align_corners is unexpectedly None")
        # Two levels are necessary to prevent TorchScript from touching
        # are_deterministic_algorithms_enabled.
        if not torch.jit.is_scripting():
            if not input.is_cpu and torch.are_deterministic_algorithms_enabled():
                # Use slow decomp whose backward will be in terms of index_put
                # importlib is required because the import cannot be top level
                # (cycle) and cannot be nested (TS doesn't support)
                return importlib.import_module(
                    "torch._decomp.decompositions"
                )._upsample_linear_vec(input, output_size, align_corners, scale_factors)
        return torch._C._nn.upsample_trilinear3d(
            input,
            # pyrefly: ignore [bad-argument-type]
            output_size,
            align_corners,
            scale_factors,
        )
    if input.dim() == 4 and mode == "bicubic":
        if align_corners is None:
            raise AssertionError("align_corners is unexpectedly None")
        if antialias:
            return torch._C._nn._upsample_bicubic2d_aa(
                input,
                # pyrefly: ignore [bad-argument-type]
                output_size,
                align_corners,
                scale_factors,
            )
        return torch._C._nn.upsample_bicubic2d(
            input,
            # pyrefly: ignore [bad-argument-type]
            output_size,
            align_corners,
            scale_factors,
        )

    if input.dim() == 4 and mode == "lanczos":
        if align_corners is None:
            raise AssertionError("align_corners is unexpectedly None")
        if align_corners:
            raise ValueError("Lanczos mode does not support align_corners=True")
        if not antialias:
            raise ValueError("Lanczos mode requires antialias=True")
        return torch._C._nn._upsample_lanczos2d_aa(
            input,
            # pyrefly: ignore [bad-argument-type]
            output_size,
            align_corners,
            scale_factors,
        )

    if input.dim() == 3 and mode == "bilinear":
        raise NotImplementedError("Got 3D input, but bilinear mode needs 4D input")
    if input.dim() == 3 and mode == "trilinear":
        raise NotImplementedError("Got 3D input, but trilinear mode needs 5D input")
    if input.dim() == 4 and mode == "linear":
        raise NotImplementedError("Got 4D input, but linear mode needs 3D input")
    if input.dim() == 4 and mode == "trilinear":
        raise NotImplementedError("Got 4D input, but trilinear mode needs 5D input")
    if input.dim() == 5 and mode == "linear":
        raise NotImplementedError("Got 5D input, but linear mode needs 3D input")
    if input.dim() == 5 and mode == "bilinear":
        raise NotImplementedError("Got 5D input, but bilinear mode needs 4D input")

    raise NotImplementedError(
        "Input Error: Only 3D, 4D and 5D input Tensors supported"
        f" (got {input.dim()}D) for the modes: nearest | linear | bilinear | bicubic | trilinear | lanczos | area | nearest-exact"
        f" (got {mode})"
    )

def opinfo_nn_functional_interpolate_trilinear(*args):
    return interpolate(*args, (5, 5, 5), scale_factor=None, mode='trilinear', align_corners=True)

args = (torch.randn(1, 2, 3, 4, 4, 4),)

eager = opinfo_nn_functional_interpolate_trilinear(*args)
torch._dynamo.reset()
compiled = torch.compile(opinfo_nn_functional_interpolate_trilinear, backend='eager')(*args)
print('eager   :', eager)
print('compiled:', compiled)
