def forward(mlist, v20_0, v22_0, v4_0, v15_0, v7_0):
    v26_0 = torch.nn.functional.gelu(v20_0)
    v25_0 = v26_0.min(0).values
    v23_0 = torch.div(v4_0, v22_0)
    v21_0 = torch.sin(v25_0)
    v18_0 = torch.neg(v23_0)
    v16_0 = torch.min(v23_0, v15_0)
    v10_0 = v21_0.max(0).values
    v14_0 = torch.nn.functional.gelu(v21_0)
    v13_0 = torch.Tensor.flatten(v14_0)
    v11_0 = mlist[0]()
    v12_0 = torch.matmul(v16_0, v11_0)
    v9_0 = torch.sub(v7_0, v12_0)
    v17_0 = torch.Tensor.flatten(v9_0)
    v19_0 = v17_0.mean(0)
    v6_0 = torch.div(v13_0, v9_0)
    v3_0 = torch.sin(v6_0)
    v5_0 = torch.cos(v3_0)
    v0_0 = v3_0.argmin(2)
    v8_0 = torch.eq(v0_0, v0_0)
    backup = v9_0[1, 64, 1, 2, 0].clone()
    v9_0[1, 64, 1, 2, 0] = 0.5807490944862366
    v1_0 = v6_0.to(dtype=torch.int64)
    v2_0 = v1_0.max(3).values
    return (v18_0, v10_0, v19_0, v5_0, v8_0, v2_0)