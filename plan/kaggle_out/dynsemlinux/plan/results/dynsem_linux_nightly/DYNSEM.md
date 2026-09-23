# Dynamo python-semantics differential (eager)

- programs: 185, divergences: 17; wall 24.6 s

| program | call | what | eager | compiled |
|---|---|---|---|---|
| numpy_scalar_types | 0 | return | `('tuple', [('T', 'torch.float32', (3, 4), [5.122988224029541, -0.38028669357299805, -6.036368370056152, 2.205293655395508, -2.7535672187805176, -3.6957864761352` | `('tuple', [('T', 'torch.float32', (3, 4), [5.122988224029541, -0.38028669357299805, -6.036368370056152, 2.205293655395508, -2.7535672187805176, -3.6957864761352` |
| numpy_scalar_types | 1 | return | `('tuple', [('T', 'torch.float32', (3, 4), [5.122988224029541, -0.38028669357299805, -6.036368370056152, 2.205293655395508, -2.7535672187805176, -3.6957864761352` | `('tuple', [('T', 'torch.float32', (3, 4), [5.122988224029541, -0.38028669357299805, -6.036368370056152, 2.205293655395508, -2.7535672187805176, -3.6957864761352` |
| inplace_leaf_error | 0 | return | `'raise:RuntimeError'` | `'raise:TorchRuntimeError'` |
| inplace_leaf_error | 1 | return | `'raise:RuntimeError'` | `'raise:TorchRuntimeError'` |
| manual_seed_inside | 0 | return | `'raise:RuntimeError'` | `'raise:TorchRuntimeError'` |
| manual_seed_inside | 1 | return | `'raise:RuntimeError'` | `'raise:TorchRuntimeError'` |
| np_scalar_math | 0 | return | `('tuple', [2, 2.5, 5, ('T', 'torch.float32', (3, 4), [3.852490186691284, -0.733572244644165, -5.4469733238220215, 1.4210782051086426, -2.711305856704712, -3.496` | `('tuple', [2, 2.5, 5, ('T', 'torch.float32', (3, 4), [3.852490186691284, -0.733572244644165, -5.4469733238220215, 1.4210782051086426, -2.711305856704712, -3.496` |
| np_scalar_math | 1 | return | `('tuple', [2, 2.5, 5, ('T', 'torch.float32', (3, 4), [3.852490186691284, -0.733572244644165, -5.4469733238220215, 1.4210782051086426, -2.711305856704712, -3.496` | `('tuple', [2, 2.5, 5, ('T', 'torch.float32', (3, 4), [3.852490186691284, -0.733572244644165, -5.4469733238220215, 1.4210782051086426, -2.711305856704712, -3.496` |
| slicing_negative_steps | 0 | return | `'raise:ValueError'` | `'raise:TorchRuntimeError'` |
| slicing_negative_steps | 1 | return | `'raise:ValueError'` | `'raise:TorchRuntimeError'` |
| exception_after_graph_break | 0 | return | `('tuple', [('T', 'torch.float32', (3, 4), [4.081992149353027, 0.41314220428466797, -3.357578754425049, 2.1368625164031982, -1.1690447330474854, -1.7971909046173` | `('tuple', [('T', 'torch.float32', (3, 4), [4.081992149353027, 0.41314220428466797, -3.357578754425049, 2.1368625164031982, -1.1690447330474854, -1.7971909046173` |
| exception_after_graph_break | 1 | return | `('tuple', [('T', 'torch.float32', (3, 4), [4.081992149353027, 0.41314220428466797, -3.357578754425049, 2.1368625164031982, -1.1690447330474854, -1.7971909046173` | `('tuple', [('T', 'torch.float32', (3, 4), [4.081992149353027, 0.41314220428466797, -3.357578754425049, 2.1368625164031982, -1.1690447330474854, -1.7971909046173` |
| deepcopy_module_state | 0 | return | `('tuple', [False, ('T', 'torch.bool', (), [True], False, ())])` | `('tuple', [False, ('T', 'torch.bool', (), [False], False, ())])` |
| tensor_subclass_torch_function | 0 | state | `('dict', [('count', 0), ('log', ('list', ['mul', 'add', 'sum', 'item'])), ('d', ('dict', [])), ('s', ('set', []))])` | `('dict', [('count', 0), ('log', ('list', ['mul', 'add', 'sum', '__get__', '__get__', '__get__', '__get__', '__get__', '__get__', '_is_view', '__get__', 'size', ` |
| tensor_subclass_torch_function | 1 | state | `('dict', [('count', 0), ('log', ('list', ['mul', 'add', 'sum', 'item', 'mul', 'add', 'sum', 'item'])), ('d', ('dict', [])), ('s', ('set', []))])` | `('dict', [('count', 0), ('log', ('list', ['mul', 'add', 'sum', '__get__', '__get__', '__get__', '__get__', '__get__', '__get__', '_is_view', '__get__', 'size', ` |
| threading_local_state | 0 | state | `('dict', [('count', 0), ('log', ('list', [])), ('d', ('dict', [])), ('s', ('set', [])), ('tl', <_thread._local object at 0x79df20c949f0>)])` | `('dict', [('count', 0), ('log', ('list', [])), ('d', ('dict', [])), ('s', ('set', [])), ('tl', <_thread._local object at 0x79df2172fdd0>)])` |
| threading_local_state | 1 | state | `('dict', [('count', 0), ('log', ('list', [])), ('d', ('dict', [])), ('s', ('set', [])), ('tl', <_thread._local object at 0x79df20c949f0>)])` | `('dict', [('count', 0), ('log', ('list', [])), ('d', ('dict', [])), ('s', ('set', [])), ('tl', <_thread._local object at 0x79df2172fdd0>)])` |
