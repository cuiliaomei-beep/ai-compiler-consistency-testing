def forward(mlist, v9_0):
    v10_0 = torch.sin(v9_0)
    v8_0 = torch.Tensor.flatten(v10_0)
    v6_0 = torch.abs(v10_0)
    v7_0 = v6_0.to(dtype=torch.float64)
    v2_0 = torch.max(v7_0, v8_0)
    v4_0 = v6_0.to(dtype=torch.float64)
    v5_0 = torch.nn.functional.gelu(v6_0)
    backup = v7_0[0, 0, 1].clone()
    v7_0[0, 0, 1] = 0.9795723557472229
    v3_0 = v5_0.mean(0)
    v0_0 = torch.gt(v5_0, v3_0)
    v1_0 = torch.gt(v3_0, v3_0)
    v7_0[0, 0, 1] = backup
    return (v2_0, v4_0, v0_0, v1_0)