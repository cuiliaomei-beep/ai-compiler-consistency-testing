def forward(mlist, v12_0, v10_0):
    v0_0 = mlist[0]()
    v13_0 = torch.max(v0_0, v12_0)
    v11_0 = torch.cos(v10_0)
    v7_0 = v11_0.to(dtype=torch.float32)
    v6_0 = torch.mul(v13_0, v7_0)
    v2_0 = v6_0.argmax(0)
    v5_0 = v2_0.to(dtype=torch.int64)
    v8_0 = torch.gt(v5_0, v2_0)
    v1_0 = v6_0[-2:2:2]
    v3_0 = torch.max(v6_0, v1_0)
    v9_0 = torch.sub(v3_0, v6_0)
    return (v8_0, v9_0)