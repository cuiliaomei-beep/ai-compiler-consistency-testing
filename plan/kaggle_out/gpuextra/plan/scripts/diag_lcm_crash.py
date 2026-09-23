"""torch.lcm / torch.gcd on INT_MIN neighbours: eager, one process per probe."""
import subprocess, sys
PROBES = {
 "gcd_i64_min_minp1": "torch.gcd(torch.tensor([-2**63]), torch.tensor([-2**63 + 1]))",
 "lcm_i64_min_minp1": "torch.lcm(torch.tensor([-2**63]), torch.tensor([-2**63 + 1]))",
 "gcd_i32_min_minp1": "torch.gcd(torch.tensor([-2**31], dtype=torch.int32), torch.tensor([-2**31 + 1], dtype=torch.int32))",
 "lcm_i32_min_minp1": "torch.lcm(torch.tensor([-2**31], dtype=torch.int32), torch.tensor([-2**31 + 1], dtype=torch.int32))",
 "lcm_i32_min_13": "torch.lcm(torch.tensor([-2**31], dtype=torch.int32), torch.tensor([13], dtype=torch.int32))",
 "lcm_i32_min_m13": "torch.lcm(torch.tensor([-2**31], dtype=torch.int32), torch.tensor([-13], dtype=torch.int32))",
 "gcd_i32_min_m13": "torch.gcd(torch.tensor([-2**31], dtype=torch.int32), torch.tensor([-13], dtype=torch.int32))",
 "gcd_i8_min_m127": "torch.gcd(torch.tensor([-128], dtype=torch.int8), torch.tensor([-127], dtype=torch.int8))",
 "lcm_i16_min_m13": "torch.lcm(torch.tensor([-2**15], dtype=torch.int16), torch.tensor([-13], dtype=torch.int16))",
 "lcm_i64_min_m13": "torch.lcm(torch.tensor([-2**63]), torch.tensor([-13]))",
 "lcm_0_0": "torch.lcm(torch.tensor([0]), torch.tensor([0]))",
 "numpy_ref": "__import__('numpy').lcm(__import__('numpy').array([-2**31], dtype='int32'), __import__('numpy').array([-13], dtype='int32'))",
 "numpy_gcd_ref": "__import__('numpy').gcd(__import__('numpy').array([-2**31], dtype='int32'), __import__('numpy').array([-13], dtype='int32'))",
}
if len(sys.argv) == 2:
    import torch
    print("RESULT", eval(PROBES[sys.argv[1]]).tolist())
else:
    import torch; print("torch", torch.__version__)
    for k in PROBES:
        p = subprocess.run([sys.executable, __file__, k], capture_output=True, text=True, timeout=120)
        line = [l for l in p.stdout.splitlines() if l.startswith("RESULT")]
        print(f"{k:22s} {line[0][7:] if line else 'EXIT ' + hex(p.returncode & 0xffffffff)}")
