def forward(mlist, v0_0):
    v10_0 = torch.nn.functional.softmax(v0_0, dim=0)
    v8_0 = torch.atan(v10_0)
    v9_0 = torch.abs(v10_0)
    v3_0 = torch.nn.functional.gelu(v9_0)
    v2_0 = v3_0.squeeze(4)
    v4_0 = mlist[1](v2_0)
    v7_0 = v4_0.to(dtype=torch.int64)
    v6_0 = v4_0.argmin(1)
    v5_0 = v4_0.to(dtype=torch.float64)
    v1_0 = v2_0.max(3).values
    return (v8_0, v7_0, v6_0, v5_0, v1_0)