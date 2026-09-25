def forward(mlist, v12_0, v6_0):
    v13_0 = torch.nn.functional.softmax(v12_0, dim=0)
    v10_0 = v13_0[-65536:65536:65536]
    v8_0 = v10_0.to(dtype=torch.int64)
    v11_0 = torch.eq(v8_0, v8_0)

    def subfunc(v6_0):
        if v6_0.shape[2] >= v11_0.max():
            v7_0 = mlist[1]()
            v9_0 = torch.where(v6_0, v7_0, v10_0)
        backup = v11_0[0].clone()
        v11_0[0] = True
        v3_0 = torch.zeros(torch.Size([16384, 1, 2, 2]), dtype=torch.float32, device='cpu')
        for i in range(0, 2):
            v3_0[:, :, :, i] = torch.clip(v9_0[:, :, :, i], -1.5, 1.5)
        v2_0 = torch.nn.functional.gelu(v3_0)
        v4_0 = v2_0.to(dtype=torch.float32)
        v5_0 = torch.clip(v4_0, -1.5, 1.5)
        v1_0 = torch.lt(v2_0, v9_0)
        return (v9_0, v2_0, v5_0, v7_0, v1_0, v11_0, backup, v3_0, v4_0)
    v9_0, v2_0, v5_0, v7_0, v1_0, v11_0, backup, v3_0, v4_0 = subfunc(v6_0)
    v11_0[0] = backup
    return (v11_0, v5_0, v1_0)