def forward(mlist, v8_0, v7_0):

    def subfunc(v7_0, v8_0):
        if v7_0.min() < v8_0.sum():
            v11_0 = torch.sigmoid(v8_0)
            v9_0 = torch.sub(v7_0, v8_0)
            backup = v9_0[7, 0, 1, 8, 0].clone()
            v9_0[7, 0, 1, 8, 0] = 0.91724783
            v9_0[7, 0, 1, 8, 0] = backup
            v6_0 = v9_0.sum(0)
            v3_0 = mlist[0](v6_0)
            v5_0 = torch.lt(v3_0, v3_0)
            v2_0 = torch.nn.functional.pad(v6_0, (-1, -1, 0, -2), 'constant', value=0.5)
            v4_0 = v2_0.to(dtype=torch.float32)
            v0_0 = torch.zeros(torch.Size([1, 30, 28, 1]), dtype=torch.float32, device='cpu')
            for i in range(0, 1):
                v0_0[:, :, :, i] = torch.clip(v2_0[:, :, :, i], -1.5, 1.5)
            v1_0 = torch.relu(v0_0)
            v10_0 = torch.min(v2_0, v1_0)
        return (v11_0, v4_0, backup, v9_0, v2_0, v1_0, v0_0, v5_0, v6_0, v10_0, v3_0)
    v11_0, v4_0, backup, v9_0, v2_0, v1_0, v0_0, v5_0, v6_0, v10_0, v3_0 = subfunc(v7_0, v8_0)
    return (v11_0, v5_0, v4_0, v10_0)