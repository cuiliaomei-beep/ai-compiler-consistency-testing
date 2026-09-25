def forward(mlist, v9_0):

    def subfunc():
        v20_0 = mlist[0]()
        v19_0 = mlist[1]()
        v21_0 = torch.sub(v19_0, v20_0)
        if v20_0.sum() >= v19_0:
            v18_0 = v21_0.triu(0)
            v17_0 = torch.nn.functional.softmax(v18_0, dim=0)
            v16_0 = torch.sigmoid(v17_0)
            v15_0 = v9_0.triu(0)
            v14_0 = torch.cos(v16_0)
            v5_0 = v14_0.to(dtype=torch.float32)
            v10_0 = torch.sigmoid(v5_0)
            v12_0 = torch.add(v5_0, v5_0)
            backup = v10_0[1, 1].clone()
            v10_0[1, 1] = 0.5977386
            v11_0 = torch.add(v14_0, v15_0)
            v6_0 = v11_0.mean(0)
            v22_0 = v6_0[-2:-1:1]
            v1_0 = torch.nn.functional.leaky_relu(v6_0)
        v13_0 = torch.zeros(torch.Size([2]), dtype=torch.float64, device='cpu')
        for i in range(0, 2):
            v13_0[i] = torch.neg(v1_0[i])
        v8_0 = torch.sigmoid(v1_0)
        v3_0 = torch.mul(v6_0, v6_0)
        v2_0 = torch.sin(v6_0)
        v0_0 = torch.neg(v2_0)
        return (v16_0, v6_0, v0_0, v2_0, v21_0, v5_0, v12_0, v10_0, v19_0, v13_0, backup, v17_0, v20_0, v1_0, v8_0, v15_0, v11_0, v3_0, v18_0, v14_0, v22_0)
    v16_0, v6_0, v0_0, v2_0, v21_0, v5_0, v12_0, v10_0, v19_0, v13_0, backup, v17_0, v20_0, v1_0, v8_0, v15_0, v11_0, v3_0, v18_0, v14_0, v22_0 = subfunc()
    v7_0 = torch.max(v0_0, v2_0)
    v4_0 = torch.sub(v6_0, v0_0)
    v10_0[1, 1] = backup
    return (v10_0, v12_0, v22_0, v13_0, v8_0, v3_0, v7_0, v4_0)