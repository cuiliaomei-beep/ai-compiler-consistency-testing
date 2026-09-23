# Dynamo python-semantics differential (eager)

- programs: 33, divergences: 44; wall 1.8 s

| program | call | what | eager | compiled |
|---|---|---|---|---|
| exc_index_caught_as_Exception | 0 | raise | `('tuple', ['IndexError', ('T', 'torch.float32', (3, 4), [2.5409960746765137, 0.706571102142334, -1.1787893772125244, 1.5684312582015991, -0.08452236652374268, -` | `'raise:IndexError'` |
| exc_index_caught_as_Exception | 1 | raise | `('tuple', ['IndexError', ('T', 'torch.float32', (3, 4), [2.5409960746765137, 0.706571102142334, -1.1787893772125244, 1.5684312582015991, -0.08452236652374268, -` | `'raise:IndexError'` |
| exc_index_caught_as_LookupError | 0 | raise | `('tuple', ['IndexError', 'select(): index 10 o'])` | `'raise:IndexError'` |
| exc_index_caught_as_LookupError | 1 | raise | `('tuple', ['IndexError', 'select(): index 10 o'])` | `'raise:IndexError'` |
| exc_index_caught_by_tuple | 0 | raise | `'IndexError'` | `'raise:IndexError'` |
| exc_index_caught_by_tuple | 1 | raise | `'IndexError'` | `'raise:IndexError'` |
| exc_index_in_nested_call | 0 | raise | `('tuple', ['caught in caller', ('T', 'torch.float32', (3, 4), [3.0819921493530273, -0.586857795715332, -4.357578754425049, 1.1368625164031982, -2.16904473304748` | `'raise:IndexError'` |
| exc_index_in_nested_call | 1 | raise | `('tuple', ['caught in caller', ('T', 'torch.float32', (3, 4), [3.0819921493530273, -0.586857795715332, -4.357578754425049, 1.1368625164031982, -2.16904473304748` | `'raise:IndexError'` |
| exc_index_in_loop_continue | 0 | raise | `('list', [('T', 'torch.float32', (), [-3.141735553741455], False, ()), ('T', 'torch.float32', (), [-3.141735553741455], False, ()), 'bad dim', ('T', 'torch.floa` | `'raise:IndexError'` |
| exc_index_in_loop_continue | 1 | raise | `('list', [('T', 'torch.float32', (), [-3.141735553741455], False, ()), ('T', 'torch.float32', (), [-3.141735553741455], False, ()), 'bad dim', ('T', 'torch.floa` | `'raise:IndexError'` |
| exc_index_in_comprehension | 0 | raise | `('list', [('T', 'torch.float32', (), [-3.141735553741455], False, ()), ('T', 'torch.float32', (), [-3.141735553741455], False, ()), None])` | `'raise:IndexError'` |
| exc_index_in_comprehension | 1 | raise | `('list', [('T', 'torch.float32', (), [-3.141735553741455], False, ()), ('T', 'torch.float32', (), [-3.141735553741455], False, ()), None])` | `'raise:IndexError'` |
| exc_index_in_generator_consumer | 0 | raise | `('list', [('T', 'torch.float32', (), [-1.0472452640533447], False, ()), 'gen raised'])` | `'raise:IndexError'` |
| exc_index_in_generator_consumer | 1 | raise | `('list', [('T', 'torch.float32', (), [-1.0472452640533447], False, ()), 'gen raised'])` | `'raise:IndexError'` |
| exc_index_then_finally_order | 0 | raise | `('list', ['finally', 'except'])` | `'raise:IndexError'` |
| exc_index_then_finally_order | 1 | raise | `('list', ['finally', 'except', 'finally', 'except'])` | `'raise:IndexError'` |
| exc_index_reraise_as_custom | 0 | raise | `('tuple', ['custom', 'IndexError'])` | `'raise:IndexError'` |
| exc_index_reraise_as_custom | 1 | raise | `('tuple', ['custom', 'IndexError'])` | `'raise:IndexError'` |
| exc_index_reraise_bare | 0 | raise | `('tuple', ['outer', 1])` | `'raise:IndexError'` |
| exc_index_reraise_bare | 1 | raise | `('tuple', ['outer', 2])` | `'raise:IndexError'` |
| exc_index_suppress | 0 | raise | `('tuple', ['suppressed', ('T', 'torch.float32', (3, 4), [2.5409960746765137, 0.706571102142334, -1.1787893772125244, 1.5684312582015991, -0.08452236652374268, -` | `'raise:IndexError'` |
| exc_index_suppress | 1 | raise | `('tuple', ['suppressed', ('T', 'torch.float32', (3, 4), [2.5409960746765137, 0.706571102142334, -1.1787893772125244, 1.5684312582015991, -0.08452236652374268, -` | `'raise:IndexError'` |
| exc_index_exit_swallows | 0 | raise | `('tuple', ['swallowed', ('list', ['IndexError'])])` | `'raise:IndexError'` |
| exc_index_exit_swallows | 1 | raise | `('tuple', ['swallowed', ('list', ['IndexError', 'IndexError'])])` | `'raise:IndexError'` |
| exc_index_else_branch | 0 | raise | `('Size', (1, 3, 4))` | `'raise:IndexError'` |
| exc_index_else_branch | 1 | raise | `('Size', (1, 3, 4))` | `'raise:IndexError'` |
| exc_index_sys_exc_info | 0 | raise | `('tuple', ['IndexError', True])` | `'raise:IndexError'` |
| exc_index_sys_exc_info | 1 | raise | `('tuple', ['IndexError', True])` | `'raise:IndexError'` |
| exc_index_message_kept | 0 | raise | `('tuple', [True, 'Dimension out of range ('])` | `'raise:IndexError'` |
| exc_index_message_kept | 1 | raise | `('tuple', [True, 'Dimension out of range ('])` | `'raise:IndexError'` |
| exc_not_implemented_bitwise_float | 0 | raise | `'NotImplementedError'` | `'raise:NotImplementedError'` |
| exc_not_implemented_bitwise_float | 1 | raise | `'NotImplementedError'` | `'raise:NotImplementedError'` |
| exc_runtime_shape_mismatch_handler_then_index | 0 | raise | `'inner index caught'` | `'raise:IndexError'` |
| exc_runtime_shape_mismatch_handler_then_index | 1 | raise | `'inner index caught'` | `'raise:IndexError'` |
| exc_index_from_python_list_vs_tensor | 0 | raise | `('list', ['list IndexError', 'Tensor IndexError'])` | `'raise:IndexError'` |
| exc_index_from_python_list_vs_tensor | 1 | raise | `('list', ['list IndexError', 'Tensor IndexError'])` | `'raise:IndexError'` |
| exc_key_error_dict_vs_index_tensor | 0 | raise | `'both caught'` | `'raise:IndexError'` |
| exc_key_error_dict_vs_index_tensor | 1 | raise | `'both caught'` | `'raise:IndexError'` |
| exc_index_lambda_in_map | 0 | raise | `('list', [('T', 'torch.float32', (), [-3.141735553741455], False, ()), ('T', 'torch.float32', (), [-3.141735553741455], False, ()), -1])` | `'raise:IndexError'` |
| exc_index_lambda_in_map | 1 | raise | `('list', [('T', 'torch.float32', (), [-3.141735553741455], False, ()), ('T', 'torch.float32', (), [-3.141735553741455], False, ()), -1])` | `'raise:IndexError'` |
| exc_index_after_graph_break_pattern | 0 | raise | `('tuple', ['caught after effect', ('list', ['mid'])])` | `'raise:IndexError'` |
| exc_index_after_graph_break_pattern | 1 | raise | `('tuple', ['caught after effect', ('list', ['mid', 'mid'])])` | `'raise:IndexError'` |
| exc_index_in_with_no_grad | 0 | raise | `('tuple', ['caught in no_grad', False])` | `'raise:IndexError'` |
| exc_index_in_with_no_grad | 1 | raise | `('tuple', ['caught in no_grad', False])` | `'raise:IndexError'` |
