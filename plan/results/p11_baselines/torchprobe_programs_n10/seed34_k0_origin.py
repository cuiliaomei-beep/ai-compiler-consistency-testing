def forward(mlist, v12_0, v6_0):
    v13_0 = torch.nn.functional.softmax(v12_0, dim=0)
    v10_0 = v13_0[-65536:65536:65536]
    v8_0 = v10_0.to(dtype=torch.int64)
    v11_0 = torch.eq(v8_0, v8_0)
    v7_0 = mlist[1]()
    v9_0 = torch.where(v6_0, v7_0, v10_0)
    v3_0 = torch.clip(v9_0, -1.5, 1.5)
    v2_0 = torch.nn.functional.gelu(v3_0)
    v4_0 = v2_0.to(dtype=torch.float32)
    v5_0 = torch.clip(v4_0, -1.5, 1.5)
    v1_0 = torch.lt(v2_0, v9_0)
    return (v11_0, v5_0, v1_0)