# Binding-form factor: how a scalar reaches the operator

- operators: 3, samples: 3, scalar slots: 3, variants: 33, checks: 84, compiles: 84, infra: 0
- findings: 64, of which **form-specific** (the literal form passes the same mode): 0
- wall: 266.1 s

| mode | op | slot | form | detail | literal form passes |
|---|---|---|---|---|---|
| dynamic | combinations | r=1 | literal | [exception] exception type differs: AcceleratorError vs TorchRuntimeError :: Dynamo failed to run FX | False |
| dynamic | combinations | r=1 | pos_param | [exception] exception type differs: AcceleratorError vs TorchRuntimeError :: Dynamo failed to run FX | False |
| dynamic | combinations | r=1 | default_param | [exception] exception type differs: AcceleratorError vs TorchRuntimeError :: Dynamo failed to run FX | False |
| dynamic | combinations | r=1 | kwargs_param | [exception] exception type differs: AcceleratorError vs TorchRuntimeError :: Dynamo failed to run FX | False |
| dynamic | combinations | r=1 | closure | [exception] exception type differs: AcceleratorError vs TorchRuntimeError :: Dynamo failed to run FX | False |
| dynamic | combinations | r=1 | global | [exception] exception type differs: AcceleratorError vs TorchRuntimeError :: Dynamo failed to run FX | False |
| dynamic | combinations | r=1 | attribute | [exception] exception type differs: AcceleratorError vs TorchRuntimeError :: Dynamo failed to run FX | False |
| dynamic | combinations | r=1 | list_elem | [exception] exception type differs: AcceleratorError vs TorchRuntimeError :: Dynamo failed to run FX | False |
| dynamic | combinations | r=1 | dict_elem | [exception] exception type differs: AcceleratorError vs TorchRuntimeError :: Dynamo failed to run FX | False |
| dynamic | combinations | r=1 | kwargs_expand | [exception] exception type differs: AcceleratorError vs TorchRuntimeError :: Dynamo failed to run FX | False |
| dynamic | combinations | r=1 | tensor_item | [exception] exception type differs: AcceleratorError vs TorchRuntimeError :: Dynamo failed to run FX | False |
| static | linspace | arg2=0 | literal | [exception] test raised BackendCompilerFailed, ref returned normally :: backend='inductor' raised:
A | False |
| dynamic | linspace | arg2=0 | literal | [exception] test raised BackendCompilerFailed, ref returned normally :: backend='inductor' raised:
A | False |
| static | linspace | arg2=0 | pos_param | [exception] test raised BackendCompilerFailed, ref returned normally :: backend='inductor' raised:
A | False |
| dynamic | linspace | arg2=0 | pos_param | [exception] test raised BackendCompilerFailed, ref returned normally :: backend='inductor' raised:
A | False |
| static | linspace | arg2=0 | default_param | [exception] test raised BackendCompilerFailed, ref returned normally :: backend='inductor' raised:
A | False |
| dynamic | linspace | arg2=0 | default_param | [exception] test raised BackendCompilerFailed, ref returned normally :: backend='inductor' raised:
A | False |
| static | linspace | arg2=0 | kwargs_param | [exception] test raised BackendCompilerFailed, ref returned normally :: backend='inductor' raised:
A | False |
| dynamic | linspace | arg2=0 | kwargs_param | [exception] test raised BackendCompilerFailed, ref returned normally :: backend='inductor' raised:
A | False |
| static | linspace | arg2=0 | closure | [exception] test raised BackendCompilerFailed, ref returned normally :: backend='inductor' raised:
A | False |
| dynamic | linspace | arg2=0 | closure | [exception] test raised BackendCompilerFailed, ref returned normally :: backend='inductor' raised:
A | False |
| static | linspace | arg2=0 | global | [exception] test raised BackendCompilerFailed, ref returned normally :: backend='inductor' raised:
A | False |
| dynamic | linspace | arg2=0 | global | [exception] test raised BackendCompilerFailed, ref returned normally :: backend='inductor' raised:
A | False |
| static | linspace | arg2=0 | attribute | [exception] test raised BackendCompilerFailed, ref returned normally :: backend='inductor' raised:
A | False |
| dynamic | linspace | arg2=0 | attribute | [exception] test raised BackendCompilerFailed, ref returned normally :: backend='inductor' raised:
A | False |
| static | linspace | arg2=0 | list_elem | [exception] test raised BackendCompilerFailed, ref returned normally :: backend='inductor' raised:
A | False |
| dynamic | linspace | arg2=0 | list_elem | [exception] test raised BackendCompilerFailed, ref returned normally :: backend='inductor' raised:
A | False |
| static | linspace | arg2=0 | dict_elem | [exception] test raised BackendCompilerFailed, ref returned normally :: backend='inductor' raised:
A | False |
| dynamic | linspace | arg2=0 | dict_elem | [exception] test raised BackendCompilerFailed, ref returned normally :: backend='inductor' raised:
A | False |
| static | linspace | arg2=0 | kwargs_expand | [exception] test raised BackendCompilerFailed, ref returned normally :: backend='inductor' raised:
A | False |
| dynamic | linspace | arg2=0 | kwargs_expand | [exception] test raised BackendCompilerFailed, ref returned normally :: backend='inductor' raised:
A | False |
| static | linspace | arg2=0 | tensor_item | [exception] test raised BackendCompilerFailed, ref returned normally :: backend='inductor' raised:
A | False |
| dynamic | linspace | arg2=0 | tensor_item | [exception] test raised BackendCompilerFailed, ref returned normally :: backend='inductor' raised:
A | False |
| static | logspace | arg2=4 | literal | [exception] exception type differs: AcceleratorError vs GPUTooOldForTriton :: Found Tesla P100-PCIE- | False |
| dynamic | logspace | arg2=4 | literal | [exception] exception type differs: AcceleratorError vs GPUTooOldForTriton :: Found Tesla P100-PCIE- | False |
| static | logspace | arg2=4 | pos_param | [exception] exception type differs: AcceleratorError vs GPUTooOldForTriton :: Found Tesla P100-PCIE- | False |
| dynamic | logspace | arg2=4 | pos_param | [exception] exception type differs: AcceleratorError vs GPUTooOldForTriton :: Found Tesla P100-PCIE- | False |
| rebind | logspace | arg2=4 | pos_param | [exception] test raised BackendCompilerFailed, ref returned normally :: backend='inductor' raised:
A | None |
| static | logspace | arg2=4 | default_param | [exception] exception type differs: AcceleratorError vs GPUTooOldForTriton :: Found Tesla P100-PCIE- | False |
| dynamic | logspace | arg2=4 | default_param | [exception] exception type differs: AcceleratorError vs GPUTooOldForTriton :: Found Tesla P100-PCIE- | False |
| static | logspace | arg2=4 | kwargs_param | [exception] exception type differs: AcceleratorError vs GPUTooOldForTriton :: Found Tesla P100-PCIE- | False |
| dynamic | logspace | arg2=4 | kwargs_param | [exception] exception type differs: AcceleratorError vs GPUTooOldForTriton :: Found Tesla P100-PCIE- | False |
| rebind | logspace | arg2=4 | kwargs_param | [exception] test raised BackendCompilerFailed, ref returned normally :: backend='inductor' raised:
A | None |
| static | logspace | arg2=4 | closure | [exception] exception type differs: AcceleratorError vs GPUTooOldForTriton :: Found Tesla P100-PCIE- | False |
| dynamic | logspace | arg2=4 | closure | [exception] exception type differs: AcceleratorError vs GPUTooOldForTriton :: Found Tesla P100-PCIE- | False |
| rebind | logspace | arg2=4 | closure | [exception] test raised BackendCompilerFailed, ref returned normally :: backend='inductor' raised:
A | None |
| static | logspace | arg2=4 | global | [exception] exception type differs: AcceleratorError vs GPUTooOldForTriton :: Found Tesla P100-PCIE- | False |
| dynamic | logspace | arg2=4 | global | [exception] exception type differs: AcceleratorError vs GPUTooOldForTriton :: Found Tesla P100-PCIE- | False |
| rebind | logspace | arg2=4 | global | [exception] test raised BackendCompilerFailed, ref returned normally :: backend='inductor' raised:
A | None |
| static | logspace | arg2=4 | attribute | [exception] exception type differs: AcceleratorError vs GPUTooOldForTriton :: Found Tesla P100-PCIE- | False |
| dynamic | logspace | arg2=4 | attribute | [exception] exception type differs: AcceleratorError vs GPUTooOldForTriton :: Found Tesla P100-PCIE- | False |
| rebind | logspace | arg2=4 | attribute | [exception] test raised BackendCompilerFailed, ref returned normally :: backend='inductor' raised:
A | None |
| static | logspace | arg2=4 | list_elem | [exception] exception type differs: AcceleratorError vs GPUTooOldForTriton :: Found Tesla P100-PCIE- | False |
| dynamic | logspace | arg2=4 | list_elem | [exception] exception type differs: AcceleratorError vs GPUTooOldForTriton :: Found Tesla P100-PCIE- | False |
| rebind | logspace | arg2=4 | list_elem | [exception] test raised BackendCompilerFailed, ref returned normally :: backend='inductor' raised:
A | None |
| static | logspace | arg2=4 | dict_elem | [exception] exception type differs: AcceleratorError vs GPUTooOldForTriton :: Found Tesla P100-PCIE- | False |
| dynamic | logspace | arg2=4 | dict_elem | [exception] exception type differs: AcceleratorError vs GPUTooOldForTriton :: Found Tesla P100-PCIE- | False |
| rebind | logspace | arg2=4 | dict_elem | [exception] test raised BackendCompilerFailed, ref returned normally :: backend='inductor' raised:
A | None |
| static | logspace | arg2=4 | kwargs_expand | [exception] exception type differs: AcceleratorError vs GPUTooOldForTriton :: Found Tesla P100-PCIE- | False |
| dynamic | logspace | arg2=4 | kwargs_expand | [exception] exception type differs: AcceleratorError vs GPUTooOldForTriton :: Found Tesla P100-PCIE- | False |
| rebind | logspace | arg2=4 | kwargs_expand | [exception] test raised BackendCompilerFailed, ref returned normally :: backend='inductor' raised:
A | None |
| static | logspace | arg2=4 | tensor_item | [exception] exception type differs: AcceleratorError vs GPUTooOldForTriton :: Found Tesla P100-PCIE- | False |
| dynamic | logspace | arg2=4 | tensor_item | [exception] exception type differs: AcceleratorError vs GPUTooOldForTriton :: Found Tesla P100-PCIE- | False |
| rebind | logspace | arg2=4 | tensor_item | [exception] test raised BackendCompilerFailed, ref returned normally :: backend='inductor' raised:
A | None |
