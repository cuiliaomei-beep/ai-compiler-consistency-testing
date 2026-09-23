# Dynamo python-semantics differential (eager/dynamic)

- programs: 77, divergences: 14; wall 12.1 s

| program | call | what | eager | compiled |
|---|---|---|---|---|
| item_and_python_math | 0 | raise | `('tuple', [-4, '-3.142', 3, 0])` | `'raise:InternalTorchDynamoError'` |
| item_and_python_math | 1 | raise | `('tuple', [-4, '-3.142', 3, 0])` | `'raise:InternalTorchDynamoError'` |
| python_random | 0 | return | `('tuple', [('T', 'torch.float32', (3, 4), [8.301250457763672, 6.752222061157227, 5.160182476043701, 7.4799957275390625, 6.084205627441406, 5.818995475769043, 7.` | `('tuple', [('T', 'torch.float32', (3, 4), [3.0806920528411865, 2.9846348762512207, 2.885910749435425, 3.0297651290893555, 2.9432106018066406, 2.926764488220215,` |
| python_random | 1 | return | `('tuple', [('T', 'torch.float32', (3, 4), [8.301250457763672, 6.752222061157227, 5.160182476043701, 7.4799957275390625, 6.084205627441406, 5.818995475769043, 7.` | `('tuple', [('T', 'torch.float32', (3, 4), [9.168004989624023, 7.777594089508057, 6.34857702255249, 8.430845260620117, 7.177981376647949, 6.9399285316467285, 8.3` |
| numpy_scalar_types | 0 | return | `('tuple', [('T', 'torch.float32', (3, 4), [5.122988224029541, -0.38028669357299805, -6.036368370056152, 2.205293655395508, -2.7535672187805176, -3.6957864761352` | `('tuple', [('T', 'torch.float32', (3, 4), [5.122988224029541, -0.38028669357299805, -6.036368370056152, 2.205293655395508, -2.7535672187805176, -3.6957864761352` |
| numpy_scalar_types | 1 | return | `('tuple', [('T', 'torch.float32', (3, 4), [5.122988224029541, -0.38028669357299805, -6.036368370056152, 2.205293655395508, -2.7535672187805176, -3.6957864761352` | `('tuple', [('T', 'torch.float32', (3, 4), [5.122988224029541, -0.38028669357299805, -6.036368370056152, 2.205293655395508, -2.7535672187805176, -3.6957864761352` |
| dataclass_namedtuple | 0 | return | `'raise:RuntimeError'` | `'raise:RecursionError'` |
| dataclass_namedtuple | 1 | return | `'raise:RuntimeError'` | `'raise:RecursionError'` |
| inplace_leaf_error | 0 | return | `'raise:RuntimeError'` | `'raise:TorchRuntimeError'` |
| inplace_leaf_error | 1 | return | `'raise:RuntimeError'` | `'raise:TorchRuntimeError'` |
| manual_seed_inside | 0 | return | `'raise:RuntimeError'` | `'raise:TorchRuntimeError'` |
| manual_seed_inside | 1 | return | `'raise:RuntimeError'` | `'raise:TorchRuntimeError'` |
| exception_message_with_value | 0 | return | `'raise:ValueError'` | `'raise:InternalTorchDynamoError'` |
| exception_message_with_value | 1 | return | `'raise:ValueError'` | `'raise:InternalTorchDynamoError'` |
