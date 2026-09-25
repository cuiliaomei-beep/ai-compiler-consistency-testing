def forward(mlist, v22_0, v18_0, v2_0):
    v23_0 = v22_0.transpose(1, 3)
    v19_0 = v18_0.to(dtype=torch.int32)
    v14_0 = v23_0[:, 0:2:1, :, :]
    v13_0 = torch.add(v2_0, v14_0)
    v11_0 = v19_0.max(1).values
    v9_0 = torch.Tensor.flatten(v11_0)
    v1_0 = torch.eq(v13_0, v11_0)
    v8_0 = torch.clip(v13_0, -1, 1)
    v6_0 = v9_0.to(dtype=torch.float64)
    v16_0 = v6_0.reshape(1, 1, 2)
    v4_0 = v9_0.to(dtype=torch.float64)
    v10_0 = torch.cos(v4_0)
    backup = v16_0[0, 0, 0].clone()
    v16_0[0, 0, 0] = 0.6990179419517517
    v21_0 = v10_0.to(dtype=torch.float64)
    v3_0 = torch.mul(v9_0, v8_0)
    v0_0 = torch.sub(v9_0, v3_0)
    v17_0 = torch.min(v0_0, v13_0)
    v5_0 = torch.mul(v3_0, v0_0)
    v12_0 = v5_0.to(dtype=torch.float64)
    v20_0 = v12_0.sum(1)
    v15_0 = torch.lt(v4_0, v12_0)
    v16_0[0, 0, 0] = backup
    return (v1_0, v16_0, v21_0, v17_0, v20_0, v15_0)