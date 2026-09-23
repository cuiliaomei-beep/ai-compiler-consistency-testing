# Binding-form factor: how a scalar reaches the operator

- operators: 386, samples: 386, scalar slots: 386, variants: 4090, checks: 10651, compiles: 10651, infra: 0
- findings: 106, of which **form-specific** (the literal form passes the same mode): 23
- wall: 2453.3 s

| mode | op | slot | form | detail | literal form passes |
|---|---|---|---|---|---|
| static | var_mean | arg1=True | literal | [value] output[1]: NaN/Inf pattern differs from the float64 truth | False |
| dynamic | var_mean | arg1=True | literal | [value] output[1]: NaN/Inf pattern differs from the float64 truth | False |
| static | var_mean | arg1=True | pos_param | [value] output[1]: NaN/Inf pattern differs from the float64 truth | False |
| dynamic | var_mean | arg1=True | pos_param | [value] output[1]: NaN/Inf pattern differs from the float64 truth | False |
| rebind | var_mean | arg1=True | pos_param | [value] output[1]: NaN/Inf pattern differs from the float64 truth | False |
| static | var_mean | arg1=True | default_param | [value] output[1]: NaN/Inf pattern differs from the float64 truth | False |
| dynamic | var_mean | arg1=True | default_param | [value] output[1]: NaN/Inf pattern differs from the float64 truth | False |
| static | var_mean | arg1=True | kwargs_param | [value] output[1]: NaN/Inf pattern differs from the float64 truth | False |
| dynamic | var_mean | arg1=True | kwargs_param | [value] output[1]: NaN/Inf pattern differs from the float64 truth | False |
| rebind | var_mean | arg1=True | kwargs_param | [value] output[1]: NaN/Inf pattern differs from the float64 truth | False |
| static | var_mean | arg1=True | closure | [value] output[1]: NaN/Inf pattern differs from the float64 truth | False |
| dynamic | var_mean | arg1=True | closure | [value] output[1]: NaN/Inf pattern differs from the float64 truth | False |
| rebind | var_mean | arg1=True | closure | [value] output[1]: NaN/Inf pattern differs from the float64 truth | False |
| static | var_mean | arg1=True | global | [value] output[1]: NaN/Inf pattern differs from the float64 truth | False |
| dynamic | var_mean | arg1=True | global | [value] output[1]: NaN/Inf pattern differs from the float64 truth | False |
| rebind | var_mean | arg1=True | global | [value] output[1]: NaN/Inf pattern differs from the float64 truth | False |
| static | var_mean | arg1=True | attribute | [value] output[1]: NaN/Inf pattern differs from the float64 truth | False |
| dynamic | var_mean | arg1=True | attribute | [value] output[1]: NaN/Inf pattern differs from the float64 truth | False |
| rebind | var_mean | arg1=True | attribute | [value] output[1]: NaN/Inf pattern differs from the float64 truth | False |
| static | var_mean | arg1=True | list_elem | [value] output[1]: NaN/Inf pattern differs from the float64 truth | False |
| dynamic | var_mean | arg1=True | list_elem | [value] output[1]: NaN/Inf pattern differs from the float64 truth | False |
| rebind | var_mean | arg1=True | list_elem | [value] output[1]: NaN/Inf pattern differs from the float64 truth | False |
| static | var_mean | arg1=True | dict_elem | [value] output[1]: NaN/Inf pattern differs from the float64 truth | False |
| dynamic | var_mean | arg1=True | dict_elem | [value] output[1]: NaN/Inf pattern differs from the float64 truth | False |
| rebind | var_mean | arg1=True | dict_elem | [value] output[1]: NaN/Inf pattern differs from the float64 truth | False |
| static | var_mean | arg1=True | kwargs_expand | [value] output[1]: NaN/Inf pattern differs from the float64 truth | False |
| dynamic | var_mean | arg1=True | kwargs_expand | [value] output[1]: NaN/Inf pattern differs from the float64 truth | False |
| rebind | var_mean | arg1=True | kwargs_expand | [value] output[1]: NaN/Inf pattern differs from the float64 truth | False |
| static | std_mean | arg1=False | literal | [value] output[1]: NaN/Inf pattern differs from the float64 truth | False |
| dynamic | std_mean | arg1=False | literal | [value] output[1]: NaN/Inf pattern differs from the float64 truth | False |
| static | std_mean | arg1=False | pos_param | [value] output[1]: NaN/Inf pattern differs from the float64 truth | False |
| dynamic | std_mean | arg1=False | pos_param | [value] output[1]: NaN/Inf pattern differs from the float64 truth | False |
| rebind | std_mean | arg1=False | pos_param | [value] output[1]: NaN/Inf pattern differs from the float64 truth | False |
| static | std_mean | arg1=False | default_param | [value] output[1]: NaN/Inf pattern differs from the float64 truth | False |
| dynamic | std_mean | arg1=False | default_param | [value] output[1]: NaN/Inf pattern differs from the float64 truth | False |
| static | std_mean | arg1=False | kwargs_param | [value] output[1]: NaN/Inf pattern differs from the float64 truth | False |
| dynamic | std_mean | arg1=False | kwargs_param | [value] output[1]: NaN/Inf pattern differs from the float64 truth | False |
| rebind | std_mean | arg1=False | kwargs_param | [value] output[1]: NaN/Inf pattern differs from the float64 truth | False |
| static | std_mean | arg1=False | closure | [value] output[1]: NaN/Inf pattern differs from the float64 truth | False |
| dynamic | std_mean | arg1=False | closure | [value] output[1]: NaN/Inf pattern differs from the float64 truth | False |
| rebind | std_mean | arg1=False | closure | [value] output[1]: NaN/Inf pattern differs from the float64 truth | False |
| static | std_mean | arg1=False | global | [value] output[1]: NaN/Inf pattern differs from the float64 truth | False |
| dynamic | std_mean | arg1=False | global | [value] output[1]: NaN/Inf pattern differs from the float64 truth | False |
| rebind | std_mean | arg1=False | global | [value] output[1]: NaN/Inf pattern differs from the float64 truth | False |
| static | std_mean | arg1=False | attribute | [value] output[1]: NaN/Inf pattern differs from the float64 truth | False |
| dynamic | std_mean | arg1=False | attribute | [value] output[1]: NaN/Inf pattern differs from the float64 truth | False |
| rebind | std_mean | arg1=False | attribute | [value] output[1]: NaN/Inf pattern differs from the float64 truth | False |
| static | std_mean | arg1=False | list_elem | [value] output[1]: NaN/Inf pattern differs from the float64 truth | False |
| dynamic | std_mean | arg1=False | list_elem | [value] output[1]: NaN/Inf pattern differs from the float64 truth | False |
| rebind | std_mean | arg1=False | list_elem | [value] output[1]: NaN/Inf pattern differs from the float64 truth | False |
| static | std_mean | arg1=False | dict_elem | [value] output[1]: NaN/Inf pattern differs from the float64 truth | False |
| dynamic | std_mean | arg1=False | dict_elem | [value] output[1]: NaN/Inf pattern differs from the float64 truth | False |
| rebind | std_mean | arg1=False | dict_elem | [value] output[1]: NaN/Inf pattern differs from the float64 truth | False |
| static | std_mean | arg1=False | kwargs_expand | [value] output[1]: NaN/Inf pattern differs from the float64 truth | False |
| dynamic | std_mean | arg1=False | kwargs_expand | [value] output[1]: NaN/Inf pattern differs from the float64 truth | False |
| rebind | std_mean | arg1=False | kwargs_expand | [value] output[1]: NaN/Inf pattern differs from the float64 truth | False |
| rebind | native_group_norm | arg3=1 | pos_param | [exception] test raised TorchRuntimeError, ref returned normally :: RuntimeError when making fake te | False |
| rebind | native_group_norm | arg3=1 | kwargs_param | [exception] test raised TorchRuntimeError, ref returned normally :: RuntimeError when making fake te | False |
| rebind | native_group_norm | arg3=1 | closure | [exception] test raised TorchRuntimeError, ref returned normally :: RuntimeError when making fake te | False |
| rebind | native_group_norm | arg3=1 | global | [exception] test raised TorchRuntimeError, ref returned normally :: RuntimeError when making fake te | False |
| rebind | native_group_norm | arg3=1 | attribute | [exception] test raised TorchRuntimeError, ref returned normally :: RuntimeError when making fake te | False |
| rebind | native_group_norm | arg3=1 | list_elem | [exception] test raised TorchRuntimeError, ref returned normally :: RuntimeError when making fake te | False |
| rebind | native_group_norm | arg3=1 | dict_elem | [exception] test raised TorchRuntimeError, ref returned normally :: RuntimeError when making fake te | False |
| rebind | native_group_norm | arg3=1 | kwargs_expand | [exception] test raised TorchRuntimeError, ref returned normally :: RuntimeError when making fake te | False |
| rebind | native_group_norm | arg3=1 | tensor_item | [exception] test raised TorchRuntimeError, ref returned normally :: RuntimeError when making fake te | False |
| rebind | nn.functional.interpolate | scale_factor=0.6 | pos_param | [value] output[0]: compiled err vs fp64 = 1.516e+01 exceeds 4.0x eager err 0.000e+00 | False |
| rebind | nn.functional.interpolate | scale_factor=0.6 | kwargs_param | [value] output[0]: compiled err vs fp64 = 1.516e+01 exceeds 4.0x eager err 0.000e+00 | False |
| rebind | nn.functional.interpolate | scale_factor=0.6 | closure | [value] output[0]: compiled err vs fp64 = 1.516e+01 exceeds 4.0x eager err 0.000e+00 | False |
| rebind | nn.functional.interpolate | scale_factor=0.6 | global | [value] output[0]: compiled err vs fp64 = 1.516e+01 exceeds 4.0x eager err 0.000e+00 | False |
| rebind | nn.functional.interpolate | scale_factor=0.6 | attribute | [value] output[0]: compiled err vs fp64 = 1.516e+01 exceeds 4.0x eager err 0.000e+00 | False |
| rebind | nn.functional.interpolate | scale_factor=0.6 | list_elem | [value] output[0]: compiled err vs fp64 = 1.516e+01 exceeds 4.0x eager err 0.000e+00 | False |
| rebind | nn.functional.interpolate | scale_factor=0.6 | dict_elem | [value] output[0]: compiled err vs fp64 = 1.516e+01 exceeds 4.0x eager err 0.000e+00 | False |
| rebind | nn.functional.interpolate | scale_factor=0.6 | kwargs_expand | [value] output[0]: compiled err vs fp64 = 1.516e+01 exceeds 4.0x eager err 0.000e+00 | False |
| rebind | nn.functional.interpolate | scale_factor=0.6 | tensor_item | [value] output[0]: compiled err vs fp64 = 1.516e+01 exceeds 4.0x eager err 0.000e+00 | False |
| dynamic | max_pool2d_with_indices_backward | kernel_size=3 | pos_param | [exception] test raised TorchRuntimeError, ref returned normally :: RuntimeError when making fake te | True |
| rebind | max_pool2d_with_indices_backward | kernel_size=3 | pos_param | [exception] test raised TorchRuntimeError, ref returned normally :: RuntimeError when making fake te | False |
| dynamic | max_pool2d_with_indices_backward | kernel_size=3 | default_param | [exception] test raised TorchRuntimeError, ref returned normally :: RuntimeError when making fake te | True |
| dynamic | max_pool2d_with_indices_backward | kernel_size=3 | kwargs_param | [exception] test raised TorchRuntimeError, ref returned normally :: RuntimeError when making fake te | True |
| rebind | max_pool2d_with_indices_backward | kernel_size=3 | kwargs_param | [exception] test raised TorchRuntimeError, ref returned normally :: RuntimeError when making fake te | False |
| dynamic | max_pool2d_with_indices_backward | kernel_size=3 | closure | [exception] test raised TorchRuntimeError, ref returned normally :: RuntimeError when making fake te | True |
| rebind | max_pool2d_with_indices_backward | kernel_size=3 | closure | [exception] test raised TorchRuntimeError, ref returned normally :: RuntimeError when making fake te | False |
| dynamic | max_pool2d_with_indices_backward | kernel_size=3 | tensor_item | [exception] test raised TorchRuntimeError, ref returned normally :: RuntimeError when making fake te | True |
| rebind | max_pool2d_with_indices_backward | kernel_size=3 | tensor_item | [exception] test raised TorchRuntimeError, ref returned normally :: RuntimeError when making fake te | False |
| rebind | resize_ | arg1=[1, 1, 1] | pos_param | [value] output[0]: compiled err vs fp64 = 8.068e-04 exceeds 4.0x eager err 0.000e+00 | False |
| rebind | resize_ | arg1=[1, 1, 1] | kwargs_param | [value] output[0]: compiled err vs fp64 = 8.068e+00 exceeds 4.0x eager err 0.000e+00 | False |
| rebind | resize_ | arg1=[1, 1, 1] | closure | [value] output[0]: compiled err vs fp64 = 9.068e-04 exceeds 4.0x eager err 0.000e+00 | False |
| rebind | resize_ | arg1=[1, 1, 1] | global | [value] output[0]: compiled err vs fp64 = 8.068e-04 exceeds 4.0x eager err 0.000e+00 | False |
| rebind | resize_ | arg1=[1, 1, 1] | attribute | [value] output[0]: compiled err vs fp64 = 3.973e+00 exceeds 4.0x eager err 0.000e+00 | False |
| static | linalg.norm | arg1=inf | pos_param | [exception] ref raised NameError, test returned normally | True |
| dynamic | linalg.norm | arg1=inf | pos_param | [exception] ref raised NameError, test returned normally | True |
| static | linalg.norm | arg1=inf | kwargs_param | [exception] ref raised NameError, test returned normally | True |
| dynamic | linalg.norm | arg1=inf | kwargs_param | [exception] ref raised NameError, test returned normally | True |
| static | linalg.norm | arg1=inf | tensor_item | [exception] ref raised NameError, test returned normally | True |
| dynamic | linalg.norm | arg1=inf | tensor_item | [exception] ref raised NameError, test returned normally | True |
| static | linalg.norm | arg1=inf | pos_param | [exception] ref raised NameError, test returned normally | True |
| dynamic | linalg.norm | arg1=inf | pos_param | [exception] ref raised NameError, test returned normally | True |
| static | linalg.norm | arg1=inf | kwargs_param | [exception] ref raised NameError, test returned normally | True |
| dynamic | linalg.norm | arg1=inf | kwargs_param | [exception] ref raised NameError, test returned normally | True |
| static | linalg.norm | arg1=inf | tensor_item | [exception] ref raised NameError, test returned normally | True |
| dynamic | linalg.norm | arg1=inf | tensor_item | [exception] ref raised NameError, test returned normally | True |
| static | linalg.norm | arg1=-inf | pos_param | [exception] ref raised NameError, test returned normally | True |
| dynamic | linalg.norm | arg1=-inf | pos_param | [exception] ref raised NameError, test returned normally | True |
| static | linalg.norm | arg1=-inf | kwargs_param | [exception] ref raised NameError, test returned normally | True |
| dynamic | linalg.norm | arg1=-inf | kwargs_param | [exception] ref raised NameError, test returned normally | True |
| static | linalg.norm | arg1=-inf | tensor_item | [exception] ref raised NameError, test returned normally | True |
| dynamic | linalg.norm | arg1=-inf | tensor_item | [exception] ref raised NameError, test returned normally | True |
