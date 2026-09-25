def forward(mlist, v4_0):
    v5_0 = v4_0.max(0).values
    v0_0 = v5_0[:, :, -1:1:1]
    v3_0 = v5_0.to(dtype=torch.int32)
    v10_0 = v3_0.argmin(1)
    v1_0 = v3_0.to(dtype=torch.float32)
    v6_0 = v1_0.to(dtype=torch.float32)
    backup = v6_0[0, 0, 0].clone()
    v6_0[0, 0, 0] = 0.5830849
    v6_0[0, 0, 0] = backup
    v8_0 = torch.nn.functional.pad(v6_0, (0, 0, 0, 0, 0, 0), 'constant', value=0.5)
    v2_0 = mlist[0](v1_0)
    v7_0 = mlist[1](v2_0)
    v9_0 = torch.cos(v7_0)
    return (v0_0, v10_0, v8_0, v9_0)