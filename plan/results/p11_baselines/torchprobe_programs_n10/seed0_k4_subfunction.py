def forward(mlist, v0_0, v7_0):
    v9_0 = torch.sin(v0_0)

    def subfunc():
        backup = v9_0[0, 0, 0].clone()
        v9_0[0, 0, 0] = 0.30742281675338745
        v10_0 = torch.sigmoid(v7_0)
        v11_0 = torch.sin(v10_0)
        v9_0[0, 0, 0] = backup
        v8_0 = torch.mul(v9_0, v7_0)
        v3_0 = v8_0.transpose(1, 2)
        v6_0 = v3_0.sum(2)
        v4_0 = torch.zeros(torch.Size([1, 1, 1]), dtype=torch.float64, device='cpu')
        for i in range(0, 1):
            v4_0[i, :, :] = torch.abs(v3_0[i, :, :])
        return (v11_0, v8_0, v4_0, backup, v9_0, v6_0, v10_0, v3_0)
    v11_0, v8_0, v4_0, backup, v9_0, v6_0, v10_0, v3_0 = subfunc()
    v1_0 = v3_0.to(dtype=torch.bool)
    if v4_0.sum() >= v6_0.max():
        v5_0 = torch.logical_or(v1_0, v1_0)
        v2_0 = v3_0.to(dtype=torch.float64)
    return (v11_0, v6_0, v4_0, v5_0, v2_0)