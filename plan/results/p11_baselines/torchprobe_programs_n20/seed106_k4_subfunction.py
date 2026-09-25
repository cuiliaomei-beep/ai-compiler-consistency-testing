def forward(mlist, v19_0, v18_0, v15_0, v10_0, v2_0):
    v13_0 = torch.cos(v19_0)
    v21_0 = torch.relu(v13_0)
    v20_0 = torch.lt(v18_0, v19_0)
    v23_0 = torch.logical_and(v20_0, v20_0)
    v22_0 = torch.where(v20_0, v19_0, v13_0)
    v24_0 = torch.tan(v22_0)
    v25_0 = mlist[0](v24_0)
    v11_0 = v15_0.reshape(4)
    v14_0 = mlist[1]()
    v16_0 = torch.where(v20_0, v14_0, v15_0)
    v12_0 = torch.mul(v10_0, v16_0)
    v8_0 = v12_0.argmax(1)
    v7_0 = v8_0.max(1).values

    def subfunc(v8_0):
        v17_0 = v2_0.to(dtype=torch.int32)
        v0_0 = v2_0.argmax(3)
        v5_0 = torch.add(v8_0, v8_0)
        return (v5_0, v17_0, v0_0)
    v5_0, v17_0, v0_0 = subfunc(v8_0)
    if v22_0 < v2_0.sum():
        v6_0 = v5_0.triu(0)
        v3_0 = torch.min(v8_0, v2_0)
        v4_0 = v3_0.max(3).values
        backup = v16_0[1, 1, 0].clone()
    v16_0[1, 1, 0] = 0
    v1_0 = torch.max(v8_0, v4_0)
    v9_0 = torch.abs(v1_0)
    return (v21_0, v23_0, v25_0, v11_0, v7_0, v17_0, v0_0, v6_0, v9_0)