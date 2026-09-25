def forward(mlist, v13_0, v1_0):
    v14_0 = v13_0[:, -1:9223372036854775807:1]
    v8_0 = mlist[0]()
    v2_0 = mlist[1]()
    v10_0 = torch.where(v2_0, v8_0, v14_0)
    v12_0 = torch.neg(v10_0)
    v7_0 = torch.tan(v10_0)
    v6_0 = v7_0.max(0).values
    v5_0 = torch.nn.functional.leaky_relu(v1_0)
    v4_0 = v6_0.to(dtype=torch.float64)
    v11_0 = v4_0.to(dtype=torch.float32)
    v0_0 = torch.nn.functional.leaky_relu(v4_0)
    v3_0 = torch.max(v4_0, v5_0)
    return (v12_0, v11_0, v0_0, v3_0)