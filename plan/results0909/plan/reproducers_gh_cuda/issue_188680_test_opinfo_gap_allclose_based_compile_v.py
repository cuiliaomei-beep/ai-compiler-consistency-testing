# source: https://github.com/pytorch/pytorch/issues/188680
# title: [test] OpInfo gap: allclose-based compile-vs-eager checks are blind to signed-zero and signed-infinity divergences
# state: open  created: 2026-07-01
# mined automatically; the harness records the torch.compile target and its first call

@ops(op_db, allowed_dtypes=floating_and_complex_types())
def test_sign_sensitive_special_values(self, device, dtype, op):
    """
    Checks that signbit / isinf / isnan are identical between
    eager and torch.compile on the op's reference_inputs.
    """
