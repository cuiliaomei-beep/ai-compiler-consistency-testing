def forward(mlist, v14_0, v12_0, v4_0):
    v13_0 = mlist[0]()
    v15_0 = torch.where(v12_0, v13_0, v14_0)
    v10_0 = mlist[1]()
    v11_0 = torch.add(v15_0, v10_0)
    if v4_0.mean() >= v15_0.mean():
        v8_0 = torch.cos(v11_0)
        backup = v15_0[0].clone()
    v15_0[0] = 0.6684114336967468
    v0_0 = torch.zeros(torch.Size([1, 1, 1, 2, 1]), dtype=torch.float64, device='cpu')
    for i in range(0, 1):
        v0_0[i, :, :, :, :] = torch.sin(v4_0[i, :, :, :, :])
    v2_0 = v4_0.to(dtype=torch.float32)
    v6_0 = torch.min(v2_0, v2_0)
    v7_0 = torch.sigmoid(v6_0)
    v5_0 = torch.max(v8_0, v4_0)
    v3_0 = torch.clip(v5_0, -1.5, 1.5)
    v1_0 = torch.sub(v3_0, v3_0)
    return (v0_0, v7_0, v1_0)