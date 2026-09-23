# Dynamo python-semantics differential (eager/dynamic)

- programs: 57, divergences: 6; wall 9.2 s

| program | call | what | eager | compiled |
|---|---|---|---|---|
| try_error_in_except_handler | 0 | raise | `('tuple', ['index', 'RuntimeError'])` | `'raise:IndexError'` |
| try_error_in_except_handler | 1 | raise | `('tuple', ['index', 'RuntimeError'])` | `'raise:IndexError'` |
| gen_in_zip_strict_uneven | 0 | return | `('tuple', ['strict', 'zip() argument 2 is '])` | `('tuple', ['strict', 'zip() argument 0 is '])` |
| gen_in_zip_strict_uneven | 1 | return | `('tuple', ['strict', 'zip() argument 2 is '])` | `('tuple', ['strict', 'zip() argument 0 is '])` |
| global_statement_counter | 0 | return | `('tuple', [('T', 'torch.float32', (3, 4), [1.5409960746765137, -0.293428897857666, -2.1787893772125244, 0.5684312582015991, -1.0845223665237427, -1.398595452308` | `('tuple', [('T', 'torch.float32', (3, 4), [4.622988224029541, -0.880286693572998, -6.536368370056152, 1.7052937746047974, -3.2535672187805176, -4.19578647613525` |
| global_statement_counter | 1 | return | `('tuple', [('T', 'torch.float32', (3, 4), [3.0819921493530273, -0.586857795715332, -4.357578754425049, 1.1368625164031982, -2.1690447330474854, -2.7971909046173` | `('tuple', [('T', 'torch.float32', (3, 4), [6.163984298706055, -1.173715591430664, -8.715157508850098, 2.2737250328063965, -4.338089466094971, -5.594381809234619` |
