def forward(mlist, v6_0):
    v11_0 = mlist[0]()
    v12_0 = torch.atan(v11_0)
    v7_0 = torch.atan(v6_0)
    v8_0 = v7_0.max(1).values
    v3_0 = torch.add(v12_0, v7_0)
    backup = v7_0[0, 1].clone()
    v7_0[0, 1] = 0.47989643
    v4_0 = torch.gt(v12_0, v3_0)
    v0_0 = torch.atan(v3_0)
    v9_0 = v0_0.reshape(4, 1)
    v7_0[0, 1] = backup
    v2_0 = torch.div(v7_0, v0_0)
    v10_0 = torch.min(v6_0, v2_0)
    v5_0 = torch.matmul(v0_0, v0_0)
    return (v8_0, v4_0, v9_0, v10_0, v5_0)