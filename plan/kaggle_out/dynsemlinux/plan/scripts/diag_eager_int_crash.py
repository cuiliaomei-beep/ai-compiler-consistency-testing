"""Eager-only probes: does an integer edge case kill the interpreter?  One process per probe."""
import subprocess, sys
PROBES = {
 "lcm_int64_min_m1": "torch.lcm(torch.tensor([-2**63]), torch.tensor([-1]))",
 "lcm_int32_min_m1": "torch.lcm(torch.tensor([-2**31], dtype=torch.int32), torch.tensor([-1], dtype=torch.int32))",
 "lcm_int8_min_m1": "torch.lcm(torch.tensor([-128], dtype=torch.int8), torch.tensor([-1], dtype=torch.int8))",
 "lcm_int64_min_min": "torch.lcm(torch.tensor([-2**63]), torch.tensor([-2**63]))",
 "lcm_int64_min_3": "torch.lcm(torch.tensor([-2**63]), torch.tensor([3]))",
 "gcd_int64_min_m1": "torch.gcd(torch.tensor([-2**63]), torch.tensor([-1]))",
 "gcd_int64_min_0": "torch.gcd(torch.tensor([-2**63]), torch.tensor([0]))",
 "div_trunc_int64": "torch.div(torch.tensor([-2**63]), torch.tensor([-1]), rounding_mode='trunc')",
 "div_floor_int64": "torch.div(torch.tensor([-2**63]), torch.tensor([-1]), rounding_mode='floor')",
 "div_trunc_int32": "torch.div(torch.tensor([-2**31], dtype=torch.int32), torch.tensor([-1], dtype=torch.int32), rounding_mode='trunc')",
 "div_trunc_int8": "torch.div(torch.tensor([-128], dtype=torch.int8), torch.tensor([-1], dtype=torch.int8), rounding_mode='trunc')",
 "floor_divide_int64": "torch.floor_divide(torch.tensor([-2**63]), torch.tensor([-1]))",
 "remainder_int64": "torch.remainder(torch.tensor([-2**63]), torch.tensor([-1]))",
 "fmod_int64": "torch.fmod(torch.tensor([-2**63]), torch.tensor([-1]))",
 "fmod_int32": "torch.fmod(torch.tensor([-2**31], dtype=torch.int32), torch.tensor([-1], dtype=torch.int32))",
 "scalar_floordiv": "torch.tensor([-2**63]) // -1",
 "scalar_mod": "torch.tensor([-2**63]) % -1",
 "div_trunc_vec": "torch.div(torch.full((64,), -2**63), torch.full((64,), -1), rounding_mode='trunc')",
}
if len(sys.argv) == 2:
    import torch
    print("RESULT", eval(PROBES[sys.argv[1]]).tolist())
else:
    import torch; print("torch", torch.__version__)
    for k in PROBES:
        p = subprocess.run([sys.executable, __file__, k], capture_output=True, text=True, timeout=120)
        line = [l for l in p.stdout.splitlines() if l.startswith("RESULT")]
        err = p.stderr.strip().splitlines()[-1][:120] if p.stderr.strip() else ""
        print(f"{k:24s} {line[0][7:] if line else 'EXIT ' + hex(p.returncode & 0xffffffff) + ' ' + err}")
