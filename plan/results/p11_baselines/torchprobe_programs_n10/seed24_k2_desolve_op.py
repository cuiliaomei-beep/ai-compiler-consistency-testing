def forward(mlist, v10_0):
    v11_0 = torch.sin(v10_0)
    v6_0 = torch.zeros(torch.Size([1, 1, 1, 1, 1]), dtype=torch.float32, device='cpu')
    for i in range(0, 1):
        v6_0[i, :, :, :, :] = torch.sin(v11_0[i, :, :, :, :])
    v8_0 = torch.sigmoid(v6_0)
    v5_0 = mlist[0](v6_0)
    v3_0 = torch.abs(v5_0)
    backup = v5_0[0, 0, 0, 0, 0].clone()
    v5_0[0, 0, 0, 0, 0] = 0.33722693
    v7_0 = v3_0.max(2).values
    v9_0 = torch.nn.functional.pad(v7_0, (0, 0, 0, 0, 0, 0), 'replicate')
    v1_0 = v3_0.transpose(1, 2)
    v4_0 = v1_0.argmin(4)
    v0_0 = v1_0[:, :, :, :, -1:1:1]
    return (v8_0, v9_0, v4_0, v0_0)