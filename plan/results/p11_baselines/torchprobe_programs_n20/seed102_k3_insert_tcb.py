def forward(mlist, v11_0):
    v23_0 = mlist[0]()
    v22_0 = mlist[1]()
    v16_0 = mlist[2]()
    v24_0 = torch.where(v16_0, v22_0, v23_0)
    v21_0 = torch.Tensor.flatten(v24_0)
    v15_0 = mlist[3]()
    v17_0 = torch.div(v15_0, v21_0)
    v14_0 = torch.sigmoid(v11_0)
    v13_0 = torch.zeros(torch.Size([1, 1]), dtype=torch.float64, device='cpu')
    for i in range(0, 1):
        v13_0[i, :] = torch.tan(v14_0[i, :])
    v12_0 = torch.max(v17_0, v13_0)
    v10_0 = v12_0.min(1).values
    v7_0 = torch.atan(v10_0)
    v19_0 = v7_0.argmin(0)
    v6_0 = torch.relu(v7_0)
    v2_0 = v7_0[0:1:1]
    backup = v17_0[0, 0].clone()
    v17_0[0, 0] = 0.9091114401817322
    v4_0 = v2_0.mean(0)
    v3_0 = torch.Tensor.flatten(v2_0)
    v8_0 = v3_0.sum(0)
    v0_0 = torch.mul(v7_0, v3_0)
    v5_0 = v3_0.argmax(0)
    v9_0 = torch.add(v5_0, v5_0)
    v20_0 = torch.eq(v19_0, v9_0)
    if v23_0 >= v9_0:
        v1_0 = torch.add(v7_0, v7_0)
    v18_0 = torch.abs(v1_0)
    return (v6_0, v4_0, v8_0, v0_0, v20_0, v18_0)