# compiled optimizer.step differential (torch 2.14.0+cpu, cpu, steps=3)

- configurations: 1008, flagged: 42

| optim | flags | impl | params | finding |
|---|---|---|---|---|
| SGD | {} | {'foreach': True} | complex64 | InductorError: AssertionError: <built-in function getitem> is not an OpOverload |
| SGD | {'momentum': 0.9} | {'foreach': True} | complex64 | InductorError: AssertionError: <built-in function getitem> is not an OpOverload |
| SGD | {'momentum': 0.9, 'nesterov': True} | {'foreach': True} | complex64 | InductorError: AssertionError: <built-in function getitem> is not an OpOverload |
| SGD | {'weight_decay': 0.1} | {'foreach': True} | complex64 | InductorError: AssertionError: <built-in function getitem> is not an OpOverload |
| SGD | {'maximize': True} | {'foreach': True} | complex64 | InductorError: AssertionError: <built-in function getitem> is not an OpOverload |
| SGD | {'momentum': 0.5, 'dampening': 0.5} | {'foreach': True} | complex64 | InductorError: AssertionError: <built-in function getitem> is not an OpOverload |
| Adam | {'capturable': True} | {} | fp32 | AssertionError: If capturable=True, params and state_steps must be on supported devices: ['cuda', 'xpu', 'hpu', 'pri |
| Adam | {'capturable': True} | {} | bf16 | AssertionError: If capturable=True, params and state_steps must be on supported devices: ['cuda', 'xpu', 'hpu', 'pri |
| Adam | {'capturable': True} | {} | fp64 | AssertionError: If capturable=True, params and state_steps must be on supported devices: ['cuda', 'xpu', 'hpu', 'pri |
| Adam | {'capturable': True} | {} | complex64 | AssertionError: If capturable=True, params and state_steps must be on supported devices: ['cuda', 'xpu', 'hpu', 'pri |
| Adam | {'capturable': True} | {} | mixed_and_nograd | AssertionError: If capturable=True, params and state_steps must be on supported devices: ['cuda', 'xpu', 'hpu', 'pri |
| Adam | {'capturable': True} | {} | scalar_param | AssertionError: If capturable=True, params and state_steps must be on supported devices: ['cuda', 'xpu', 'hpu', 'pri |
| Adam | {'capturable': True} | {'foreach': True} | fp32 | AssertionError: If capturable=True, params and state_steps must be on supported devices: ['cuda', 'xpu', 'hpu', 'pri |
| Adam | {'capturable': True} | {'foreach': True} | bf16 | AssertionError: If capturable=True, params and state_steps must be on supported devices: ['cuda', 'xpu', 'hpu', 'pri |
| Adam | {'capturable': True} | {'foreach': True} | fp64 | AssertionError: If capturable=True, params and state_steps must be on supported devices: ['cuda', 'xpu', 'hpu', 'pri |
| Adam | {'capturable': True} | {'foreach': True} | complex64 | AssertionError: If capturable=True, params and state_steps must be on supported devices: ['cuda', 'xpu', 'hpu', 'pri |
| Adam | {'capturable': True} | {'foreach': True} | mixed_and_nograd | AssertionError: If capturable=True, params and state_steps must be on supported devices: ['cuda', 'xpu', 'hpu', 'pri |
| Adam | {'capturable': True} | {'foreach': True} | scalar_param | AssertionError: If capturable=True, params and state_steps must be on supported devices: ['cuda', 'xpu', 'hpu', 'pri |
| Adam | {'capturable': True} | {'foreach': False} | fp32 | AssertionError: If capturable=True, params and state_steps must be on supported devices: ['cuda', 'xpu', 'hpu', 'pri |
| Adam | {'capturable': True} | {'foreach': False} | bf16 | AssertionError: If capturable=True, params and state_steps must be on supported devices: ['cuda', 'xpu', 'hpu', 'pri |
| Adam | {'capturable': True} | {'foreach': False} | fp64 | AssertionError: If capturable=True, params and state_steps must be on supported devices: ['cuda', 'xpu', 'hpu', 'pri |
| Adam | {'capturable': True} | {'foreach': False} | complex64 | AssertionError: If capturable=True, params and state_steps must be on supported devices: ['cuda', 'xpu', 'hpu', 'pri |
| Adam | {'capturable': True} | {'foreach': False} | mixed_and_nograd | AssertionError: If capturable=True, params and state_steps must be on supported devices: ['cuda', 'xpu', 'hpu', 'pri |
| Adam | {'capturable': True} | {'foreach': False} | scalar_param | AssertionError: If capturable=True, params and state_steps must be on supported devices: ['cuda', 'xpu', 'hpu', 'pri |
| AdamW | {'capturable': True} | {} | fp32 | AssertionError: If capturable=True, params and state_steps must be on supported devices: ['cuda', 'xpu', 'hpu', 'pri |
| AdamW | {'capturable': True} | {} | bf16 | AssertionError: If capturable=True, params and state_steps must be on supported devices: ['cuda', 'xpu', 'hpu', 'pri |
| AdamW | {'capturable': True} | {} | fp64 | AssertionError: If capturable=True, params and state_steps must be on supported devices: ['cuda', 'xpu', 'hpu', 'pri |
| AdamW | {'capturable': True} | {} | complex64 | AssertionError: If capturable=True, params and state_steps must be on supported devices: ['cuda', 'xpu', 'hpu', 'pri |
| AdamW | {'capturable': True} | {} | mixed_and_nograd | AssertionError: If capturable=True, params and state_steps must be on supported devices: ['cuda', 'xpu', 'hpu', 'pri |
| AdamW | {'capturable': True} | {} | scalar_param | AssertionError: If capturable=True, params and state_steps must be on supported devices: ['cuda', 'xpu', 'hpu', 'pri |
| AdamW | {'capturable': True} | {'foreach': True} | fp32 | AssertionError: If capturable=True, params and state_steps must be on supported devices: ['cuda', 'xpu', 'hpu', 'pri |
| AdamW | {'capturable': True} | {'foreach': True} | bf16 | AssertionError: If capturable=True, params and state_steps must be on supported devices: ['cuda', 'xpu', 'hpu', 'pri |
| AdamW | {'capturable': True} | {'foreach': True} | fp64 | AssertionError: If capturable=True, params and state_steps must be on supported devices: ['cuda', 'xpu', 'hpu', 'pri |
| AdamW | {'capturable': True} | {'foreach': True} | complex64 | AssertionError: If capturable=True, params and state_steps must be on supported devices: ['cuda', 'xpu', 'hpu', 'pri |
| AdamW | {'capturable': True} | {'foreach': True} | mixed_and_nograd | AssertionError: If capturable=True, params and state_steps must be on supported devices: ['cuda', 'xpu', 'hpu', 'pri |
| AdamW | {'capturable': True} | {'foreach': True} | scalar_param | AssertionError: If capturable=True, params and state_steps must be on supported devices: ['cuda', 'xpu', 'hpu', 'pri |
| AdamW | {'capturable': True} | {'foreach': False} | fp32 | AssertionError: If capturable=True, params and state_steps must be on supported devices: ['cuda', 'xpu', 'hpu', 'pri |
| AdamW | {'capturable': True} | {'foreach': False} | bf16 | AssertionError: If capturable=True, params and state_steps must be on supported devices: ['cuda', 'xpu', 'hpu', 'pri |
| AdamW | {'capturable': True} | {'foreach': False} | fp64 | AssertionError: If capturable=True, params and state_steps must be on supported devices: ['cuda', 'xpu', 'hpu', 'pri |
| AdamW | {'capturable': True} | {'foreach': False} | complex64 | AssertionError: If capturable=True, params and state_steps must be on supported devices: ['cuda', 'xpu', 'hpu', 'pri |
| AdamW | {'capturable': True} | {'foreach': False} | mixed_and_nograd | AssertionError: If capturable=True, params and state_steps must be on supported devices: ['cuda', 'xpu', 'hpu', 'pri |
| AdamW | {'capturable': True} | {'foreach': False} | scalar_param | AssertionError: If capturable=True, params and state_steps must be on supported devices: ['cuda', 'xpu', 'hpu', 'pri |
