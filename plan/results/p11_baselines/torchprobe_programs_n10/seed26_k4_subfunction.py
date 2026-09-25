def forward(mlist, v10_0, v3_0):
    v11_0 = torch.clip(v10_0, -1, 1)
    v9_0 = torch.zeros(torch.Size([1, 1, 1, 1, 1]), dtype=torch.int64, device='cpu')
    for i in range(0, 1):
        v9_0[:, :, i, :, :] = torch.neg(v11_0[:, :, i, :, :])
    v0_0 = torch.abs(v3_0)

    def subfunc(v9_0, v11_0, v0_0, v3_0):
        v6_0 = v0_0.to(dtype=torch.int64)
        if v0_0 >= v9_0.max():
            v7_0 = v9_0.argmax(4)
            v5_0 = torch.clip(v9_0, -1, 1)
            v2_0 = v5_0.to(dtype=torch.float32)
            v8_0 = torch.cos(v2_0)
            v4_0 = torch.max(v9_0, v3_0)
            backup = v11_0[0, 0, 0, 0, 0].clone()
            v11_0[0, 0, 0, 0, 0] = 0
            v1_0 = v4_0.to(dtype=torch.bool)
        return (v2_0, v6_0, v5_0, v7_0, v1_0, v11_0, v8_0, backup, v4_0)
    v2_0, v6_0, v5_0, v7_0, v1_0, v11_0, v8_0, backup, v4_0 = subfunc(v9_0, v11_0, v0_0, v3_0)
    return (v6_0, v7_0, v8_0, v1_0)