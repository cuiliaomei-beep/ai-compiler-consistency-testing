# Binding-form factor: how a scalar reaches the operator

- operators: 357, samples: 357, scalar slots: 357, variants: 3807, checks: 9956, compiles: 9835, infra: 121
- findings: 114, of which **form-specific** (the literal form passes the same mode): 8
- wall: 2477.8 s

| mode | op | slot | form | detail | literal form passes |
|---|---|---|---|---|---|
| dynamic | combinations | r=1 | literal | [exception] test raised TorchRuntimeError, ref returned normally :: Dynamo failed to run FX node wit | False |
| dynamic | combinations | r=1 | pos_param | [exception] test raised TorchRuntimeError, ref returned normally :: Dynamo failed to run FX node wit | False |
| dynamic | combinations | r=1 | default_param | [exception] test raised TorchRuntimeError, ref returned normally :: Dynamo failed to run FX node wit | False |
| dynamic | combinations | r=1 | kwargs_param | [exception] test raised TorchRuntimeError, ref returned normally :: Dynamo failed to run FX node wit | False |
| dynamic | combinations | r=1 | closure | [exception] test raised TorchRuntimeError, ref returned normally :: Dynamo failed to run FX node wit | False |
| dynamic | combinations | r=1 | global | [exception] test raised TorchRuntimeError, ref returned normally :: Dynamo failed to run FX node wit | False |
| dynamic | combinations | r=1 | attribute | [exception] test raised TorchRuntimeError, ref returned normally :: Dynamo failed to run FX node wit | False |
| dynamic | combinations | r=1 | list_elem | [exception] test raised TorchRuntimeError, ref returned normally :: Dynamo failed to run FX node wit | False |
| dynamic | combinations | r=1 | dict_elem | [exception] test raised TorchRuntimeError, ref returned normally :: Dynamo failed to run FX node wit | False |
| dynamic | combinations | r=1 | kwargs_expand | [exception] test raised TorchRuntimeError, ref returned normally :: Dynamo failed to run FX node wit | False |
| dynamic | combinations | r=1 | tensor_item | [exception] test raised TorchRuntimeError, ref returned normally :: Dynamo failed to run FX node wit | False |
| dynamic | quantile | dim=0 | literal | [exception] test raised TorchRuntimeError, ref returned normally :: Dynamo failed to run FX node wit | False |
| dynamic | quantile | dim=0 | pos_param | [exception] test raised TorchRuntimeError, ref returned normally :: Dynamo failed to run FX node wit | False |
| dynamic | quantile | dim=0 | default_param | [exception] test raised TorchRuntimeError, ref returned normally :: Dynamo failed to run FX node wit | False |
| dynamic | quantile | dim=0 | kwargs_param | [exception] test raised TorchRuntimeError, ref returned normally :: Dynamo failed to run FX node wit | False |
| dynamic | quantile | dim=0 | closure | [exception] test raised TorchRuntimeError, ref returned normally :: Dynamo failed to run FX node wit | False |
| dynamic | quantile | dim=0 | global | [exception] test raised TorchRuntimeError, ref returned normally :: Dynamo failed to run FX node wit | False |
| dynamic | quantile | dim=0 | attribute | [exception] test raised TorchRuntimeError, ref returned normally :: Dynamo failed to run FX node wit | False |
| dynamic | quantile | dim=0 | list_elem | [exception] test raised TorchRuntimeError, ref returned normally :: Dynamo failed to run FX node wit | False |
| dynamic | quantile | dim=0 | dict_elem | [exception] test raised TorchRuntimeError, ref returned normally :: Dynamo failed to run FX node wit | False |
| dynamic | quantile | dim=0 | kwargs_expand | [exception] test raised TorchRuntimeError, ref returned normally :: Dynamo failed to run FX node wit | False |
| dynamic | quantile | dim=0 | tensor_item | [exception] test raised TorchRuntimeError, ref returned normally :: Dynamo failed to run FX node wit | False |
| dynamic | nanquantile | dim=-1 | literal | [exception] test raised TorchRuntimeError, ref returned normally :: Dynamo failed to run FX node wit | False |
| dynamic | nanquantile | dim=-1 | pos_param | [exception] test raised TorchRuntimeError, ref returned normally :: Dynamo failed to run FX node wit | False |
| dynamic | nanquantile | dim=-1 | default_param | [exception] test raised TorchRuntimeError, ref returned normally :: Dynamo failed to run FX node wit | False |
| dynamic | nanquantile | dim=-1 | kwargs_param | [exception] test raised TorchRuntimeError, ref returned normally :: Dynamo failed to run FX node wit | False |
| dynamic | nanquantile | dim=-1 | closure | [exception] test raised TorchRuntimeError, ref returned normally :: Dynamo failed to run FX node wit | False |
| dynamic | nanquantile | dim=-1 | global | [exception] test raised TorchRuntimeError, ref returned normally :: Dynamo failed to run FX node wit | False |
| dynamic | nanquantile | dim=-1 | attribute | [exception] test raised TorchRuntimeError, ref returned normally :: Dynamo failed to run FX node wit | False |
| dynamic | nanquantile | dim=-1 | list_elem | [exception] test raised TorchRuntimeError, ref returned normally :: Dynamo failed to run FX node wit | False |
| dynamic | nanquantile | dim=-1 | dict_elem | [exception] test raised TorchRuntimeError, ref returned normally :: Dynamo failed to run FX node wit | False |
| dynamic | nanquantile | dim=-1 | kwargs_expand | [exception] test raised TorchRuntimeError, ref returned normally :: Dynamo failed to run FX node wit | False |
| dynamic | nanquantile | dim=-1 | tensor_item | [exception] test raised TorchRuntimeError, ref returned normally :: Dynamo failed to run FX node wit | False |
| dynamic | nn.functional.adaptive_avg_pool2d | arg1=5 | pos_param | [exception] test raised InductorError, ref returned normally :: LoweringException: TypeError: cannot | True |
| rebind | nn.functional.adaptive_avg_pool2d | arg1=5 | pos_param | [exception] test raised InductorError, ref returned normally :: LoweringException: TypeError: cannot | None |
| dynamic | nn.functional.adaptive_avg_pool2d | arg1=5 | kwargs_param | [exception] test raised InductorError, ref returned normally :: LoweringException: TypeError: cannot | True |
| rebind | nn.functional.adaptive_avg_pool2d | arg1=5 | kwargs_param | [exception] test raised InductorError, ref returned normally :: LoweringException: TypeError: cannot | None |
| dynamic | nn.functional.adaptive_avg_pool2d | arg1=5 | closure | [exception] test raised InductorError, ref returned normally :: LoweringException: TypeError: cannot | True |
| rebind | nn.functional.adaptive_avg_pool2d | arg1=5 | closure | [exception] test raised InductorError, ref returned normally :: LoweringException: TypeError: cannot | None |
| dynamic | nn.functional.adaptive_avg_pool2d | arg1=5 | tensor_item | [exception] test raised InductorError, ref returned normally :: LoweringException: TypeError: cannot | True |
| rebind | nn.functional.adaptive_avg_pool2d | arg1=5 | tensor_item | [exception] test raised InductorError, ref returned normally :: LoweringException: TypeError: cannot | None |
| dynamic | nn.functional.interpolate | scale_factor=1.7 | literal | [exception] test raised InductorError, ref returned normally :: OverflowError: cannot convert float  | False |
| dynamic | nn.functional.interpolate | scale_factor=1.7 | pos_param | [exception] test raised InductorError, ref returned normally :: OverflowError: cannot convert float  | False |
| dynamic | nn.functional.interpolate | scale_factor=1.7 | default_param | [exception] test raised InductorError, ref returned normally :: OverflowError: cannot convert float  | False |
| dynamic | nn.functional.interpolate | scale_factor=1.7 | kwargs_param | [exception] test raised InductorError, ref returned normally :: OverflowError: cannot convert float  | False |
| dynamic | nn.functional.interpolate | scale_factor=1.7 | closure | [exception] test raised InductorError, ref returned normally :: OverflowError: cannot convert float  | False |
| dynamic | nn.functional.interpolate | scale_factor=1.7 | global | [exception] test raised InductorError, ref returned normally :: OverflowError: cannot convert float  | False |
| dynamic | nn.functional.interpolate | scale_factor=1.7 | attribute | [exception] test raised InductorError, ref returned normally :: OverflowError: cannot convert float  | False |
| dynamic | nn.functional.interpolate | scale_factor=1.7 | list_elem | [exception] test raised InductorError, ref returned normally :: OverflowError: cannot convert float  | False |
| dynamic | nn.functional.interpolate | scale_factor=1.7 | dict_elem | [exception] test raised InductorError, ref returned normally :: OverflowError: cannot convert float  | False |
| dynamic | nn.functional.interpolate | scale_factor=1.7 | kwargs_expand | [exception] test raised InductorError, ref returned normally :: OverflowError: cannot convert float  | False |
| dynamic | nn.functional.interpolate | scale_factor=1.7 | tensor_item | [exception] test raised InductorError, ref returned normally :: OverflowError: cannot convert float  | False |
| dynamic | nn.functional.upsample_bilinear | scale_factor=1.7 | literal | [exception] test raised InductorError, ref returned normally :: OverflowError: cannot convert float  | False |
| dynamic | nn.functional.upsample_bilinear | scale_factor=1.7 | pos_param | [exception] test raised InductorError, ref returned normally :: OverflowError: cannot convert float  | False |
| dynamic | nn.functional.upsample_bilinear | scale_factor=1.7 | default_param | [exception] test raised InductorError, ref returned normally :: OverflowError: cannot convert float  | False |
| dynamic | nn.functional.upsample_bilinear | scale_factor=1.7 | kwargs_param | [exception] test raised InductorError, ref returned normally :: OverflowError: cannot convert float  | False |
| dynamic | nn.functional.upsample_bilinear | scale_factor=1.7 | closure | [exception] test raised InductorError, ref returned normally :: OverflowError: cannot convert float  | False |
| dynamic | nn.functional.upsample_bilinear | scale_factor=1.7 | global | [exception] test raised InductorError, ref returned normally :: OverflowError: cannot convert float  | False |
| dynamic | nn.functional.upsample_bilinear | scale_factor=1.7 | attribute | [exception] test raised InductorError, ref returned normally :: OverflowError: cannot convert float  | False |
| dynamic | nn.functional.upsample_bilinear | scale_factor=1.7 | list_elem | [exception] test raised InductorError, ref returned normally :: OverflowError: cannot convert float  | False |
| dynamic | nn.functional.upsample_bilinear | scale_factor=1.7 | dict_elem | [exception] test raised InductorError, ref returned normally :: OverflowError: cannot convert float  | False |
| dynamic | nn.functional.upsample_bilinear | scale_factor=1.7 | kwargs_expand | [exception] test raised InductorError, ref returned normally :: OverflowError: cannot convert float  | False |
| dynamic | nn.functional.upsample_bilinear | scale_factor=1.7 | tensor_item | [exception] test raised InductorError, ref returned normally :: OverflowError: cannot convert float  | False |
| dynamic | max_pool2d_with_indices_backward | padding=1 | pos_param | [exception] test raised TorchRuntimeError, ref returned normally :: Dynamo failed to run FX node wit | True |
| rebind | max_pool2d_with_indices_backward | padding=1 | pos_param | [exception] test raised TorchRuntimeError, ref returned normally :: Dynamo failed to run FX node wit | None |
| dynamic | max_pool2d_with_indices_backward | padding=1 | kwargs_param | [exception] test raised TorchRuntimeError, ref returned normally :: Dynamo failed to run FX node wit | True |
| rebind | max_pool2d_with_indices_backward | padding=1 | kwargs_param | [exception] test raised TorchRuntimeError, ref returned normally :: Dynamo failed to run FX node wit | None |
| dynamic | max_pool2d_with_indices_backward | padding=1 | closure | [exception] test raised TorchRuntimeError, ref returned normally :: Dynamo failed to run FX node wit | True |
| rebind | max_pool2d_with_indices_backward | padding=1 | closure | [exception] test raised TorchRuntimeError, ref returned normally :: Dynamo failed to run FX node wit | None |
| dynamic | max_pool2d_with_indices_backward | padding=1 | tensor_item | [exception] test raised TorchRuntimeError, ref returned normally :: Dynamo failed to run FX node wit | True |
| rebind | max_pool2d_with_indices_backward | padding=1 | tensor_item | [exception] test raised TorchRuntimeError, ref returned normally :: Dynamo failed to run FX node wit | None |
| static | scatter_add | arg1=0 | literal | [exception] test raised InternalTorchDynamoError, ref returned normally :: AcceleratorError: CUDA er | False |
| static | nonzero_static | size=5 | literal | [exception] test raised AssertionError, ref returned normally :: expected size 5==5, stride 1==3 at  | False |
| dynamic | nonzero_static | size=5 | literal | [exception] test raised AssertionError, ref returned normally :: expected size 5==5, stride 1==3 at  | False |
| static | nonzero_static | size=5 | pos_param | [exception] test raised AssertionError, ref returned normally :: expected size 5==5, stride 1==3 at  | False |
| dynamic | nonzero_static | size=5 | pos_param | [exception] test raised AssertionError, ref returned normally :: expected size 5==5, stride 1==3 at  | False |
| rebind | nonzero_static | size=5 | pos_param | [exception] test raised AssertionError, ref returned normally :: expected size 6==6, stride 1==3 at  | None |
| static | nonzero_static | size=5 | default_param | [exception] test raised AssertionError, ref returned normally :: expected size 5==5, stride 1==3 at  | False |
| dynamic | nonzero_static | size=5 | default_param | [exception] test raised AssertionError, ref returned normally :: expected size 5==5, stride 1==3 at  | False |
| static | nonzero_static | size=5 | kwargs_param | [exception] test raised AssertionError, ref returned normally :: expected size 5==5, stride 1==3 at  | False |
| dynamic | nonzero_static | size=5 | kwargs_param | [exception] test raised AssertionError, ref returned normally :: expected size 5==5, stride 1==3 at  | False |
| rebind | nonzero_static | size=5 | kwargs_param | [exception] test raised AssertionError, ref returned normally :: expected size 6==6, stride 1==3 at  | None |
| static | nonzero_static | size=5 | closure | [exception] test raised AssertionError, ref returned normally :: expected size 5==5, stride 1==3 at  | False |
| dynamic | nonzero_static | size=5 | closure | [exception] test raised AssertionError, ref returned normally :: expected size 5==5, stride 1==3 at  | False |
| rebind | nonzero_static | size=5 | closure | [exception] test raised AssertionError, ref returned normally :: expected size 6==6, stride 1==3 at  | None |
| static | nonzero_static | size=5 | global | [exception] test raised AssertionError, ref returned normally :: expected size 5==5, stride 1==3 at  | False |
| dynamic | nonzero_static | size=5 | global | [exception] test raised AssertionError, ref returned normally :: expected size 5==5, stride 1==3 at  | False |
| rebind | nonzero_static | size=5 | global | [exception] test raised AssertionError, ref returned normally :: expected size 6==6, stride 1==3 at  | None |
| static | nonzero_static | size=5 | attribute | [exception] test raised AssertionError, ref returned normally :: expected size 5==5, stride 1==3 at  | False |
| dynamic | nonzero_static | size=5 | attribute | [exception] test raised AssertionError, ref returned normally :: expected size 5==5, stride 1==3 at  | False |
| rebind | nonzero_static | size=5 | attribute | [exception] test raised AssertionError, ref returned normally :: expected size 6==6, stride 1==3 at  | None |
| static | nonzero_static | size=5 | list_elem | [exception] test raised AssertionError, ref returned normally :: expected size 5==5, stride 1==3 at  | False |
| dynamic | nonzero_static | size=5 | list_elem | [exception] test raised AssertionError, ref returned normally :: expected size 5==5, stride 1==3 at  | False |
| rebind | nonzero_static | size=5 | list_elem | [exception] test raised AssertionError, ref returned normally :: expected size 6==6, stride 1==3 at  | None |
| static | nonzero_static | size=5 | dict_elem | [exception] test raised AssertionError, ref returned normally :: expected size 5==5, stride 1==3 at  | False |
| dynamic | nonzero_static | size=5 | dict_elem | [exception] test raised AssertionError, ref returned normally :: expected size 5==5, stride 1==3 at  | False |
| rebind | nonzero_static | size=5 | dict_elem | [exception] test raised AssertionError, ref returned normally :: expected size 6==6, stride 1==3 at  | None |
| static | nonzero_static | size=5 | kwargs_expand | [exception] test raised AssertionError, ref returned normally :: expected size 5==5, stride 1==3 at  | False |
| dynamic | nonzero_static | size=5 | kwargs_expand | [exception] test raised AssertionError, ref returned normally :: expected size 5==5, stride 1==3 at  | False |
| rebind | nonzero_static | size=5 | kwargs_expand | [exception] test raised AssertionError, ref returned normally :: expected size 6==6, stride 1==3 at  | None |
| static | nonzero_static | size=5 | tensor_item | [exception] test raised AssertionError, ref returned normally :: expected size 5==5, stride 1==3 at  | False |
| dynamic | nonzero_static | size=5 | tensor_item | [exception] test raised InternalTorchDynamoError, ref returned normally :: RuntimeError: dictionary  | False |
| rebind | nonzero_static | size=5 | tensor_item | [exception] test raised AssertionError, ref returned normally :: expected size 6==6, stride 1==3 at  | None |
| rebind | grid_sampler_2d | arg2=2 | pos_param | [exception] test raised TorchRuntimeError, ref returned normally :: Dynamo failed to run FX node wit | None |
| rebind | grid_sampler_2d | arg2=2 | kwargs_param | [exception] test raised TorchRuntimeError, ref returned normally :: Dynamo failed to run FX node wit | None |
| rebind | grid_sampler_2d | arg2=2 | closure | [exception] test raised TorchRuntimeError, ref returned normally :: Dynamo failed to run FX node wit | None |
| rebind | grid_sampler_2d | arg2=2 | global | [exception] test raised TorchRuntimeError, ref returned normally :: Dynamo failed to run FX node wit | None |
| rebind | grid_sampler_2d | arg2=2 | attribute | [exception] test raised TorchRuntimeError, ref returned normally :: Dynamo failed to run FX node wit | None |
| rebind | grid_sampler_2d | arg2=2 | list_elem | [exception] test raised TorchRuntimeError, ref returned normally :: Dynamo failed to run FX node wit | None |
| rebind | grid_sampler_2d | arg2=2 | dict_elem | [exception] test raised TorchRuntimeError, ref returned normally :: Dynamo failed to run FX node wit | None |
| rebind | grid_sampler_2d | arg2=2 | kwargs_expand | [exception] test raised TorchRuntimeError, ref returned normally :: Dynamo failed to run FX node wit | None |
| rebind | grid_sampler_2d | arg2=2 | tensor_item | [exception] test raised TorchRuntimeError, ref returned normally :: Dynamo failed to run FX node wit | None |
| static | scatter_reduce | arg1=0 | literal | [exception] test raised InternalTorchDynamoError, ref returned normally :: AcceleratorError: CUDA er | False |
| static | scatter_reduce | arg1=0 | literal | [exception] test raised InternalTorchDynamoError, ref returned normally :: AcceleratorError: CUDA er | False |
