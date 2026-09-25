def forward(mlist, v11_0, v10_0):
    v12_0 = torch.sub(v10_0, v11_0)
    v8_0 = torch.clip(v12_0, -1.5, 1.5)
    v5_0 = v8_0.to(dtype=torch.float64)
    v9_0 = torch.clip(v5_0, -1.5, 1.5)
    v4_0 = v5_0.min(4).values
    v0_0 = torch.max(v4_0, v8_0)
    v3_0 = torch.lt(v4_0, v5_0)
    v2_0 = torch.max(v4_0, v4_0)
    v1_0 = torch.gt(v4_0, v4_0)
    v6_0 = torch.logical_or(v1_0, v3_0)
    return (v9_0, v0_0, v2_0, v6_0)