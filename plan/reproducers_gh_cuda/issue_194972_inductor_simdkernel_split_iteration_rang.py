# source: https://github.com/pytorch/pytorch/issues/194972
# title: [inductor] SIMDKernel._split_iteration_ranges incorrectly asserts guarding_hint_or_throw(s) == 1 on unbacked u0
# state: open  created: 2026-08-27
# mined automatically; the harness records the torch.compile target and its first call

import torch
torch._dynamo.config.capture_scalar_outputs = True
torch._dynamo.config.capture_dynamic_output_shape_ops = True

@torch.compile
def fn(arg0_1):
    _unique2 = torch.ops.aten._unique2.default(arg0_1, True, False, True)
    arg0_1 = None
    getitem = _unique2[0]
    getitem_2 = _unique2[2]
    _unique2 = None
    sym_size_int = torch.ops.aten.sym_size.int(getitem, 0)
    getitem = None
    ge_1 = sym_size_int >= 1
    _assert_scalar = torch.ops.aten._assert_scalar.default(
        ge_1, "Runtime assertion failed for expression u0 >= 1 on node 'ge'"
    )
    ge_1 = _assert_scalar = None
    le = sym_size_int <= 2
    _assert_scalar_1 = torch.ops.aten._assert_scalar.default(
        le, "Runtime assertion failed for expression u0 <= 2 on node 'le'"
    )
    le = _assert_scalar_1 = None
    eq_2 = sym_size_int == 1
    sym_size_int = None
    _assert_scalar_2 = torch.ops.aten._assert_scalar.default(
        eq_2, "Runtime assertion failed for expression Eq(u0, 1) on node 'eq'"
    )
    eq_2 = _assert_scalar_2 = None
    mul_2 = torch.ops.aten.mul.Tensor(getitem_2, 16)
    getitem_2 = None
    return mul_2

args = torch.zeros([212], dtype=torch.int32, device="cuda")
out = fn(args)
