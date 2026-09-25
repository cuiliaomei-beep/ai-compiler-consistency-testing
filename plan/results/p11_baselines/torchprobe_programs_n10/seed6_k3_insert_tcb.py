def forward(mlist, v13_0, v12_0, v8_0, v3_0):
    if v12_0.sum() >= v3_0.float().mean():
        v14_0 = torch.matmul(v12_0, v13_0)
        v9_0 = torch.sub(v14_0, v8_0)
        v6_0 = torch.clip(v9_0, -1, 1)
        v5_0 = torch.sub(v3_0, v6_0)
        v4_0 = v5_0.argmax(0)
        v1_0 = v4_0.min(1).values
        backup = v4_0[0, 1, 0].clone()
    v4_0[0, 1, 0] = 0
    v11_0 = v1_0.triu(0)
    v2_0 = torch.abs(v5_0)
    v10_0 = v2_0.transpose(2, 0)
    v0_0 = torch.zeros(torch.Size([1, 1, 2, 2]), dtype=torch.bool, device='cpu')
    for i in range(0, 2):
        v0_0[:, :, :, i] = torch.eq(v2_0[:, :, :, i], v5_0[:, :, :, i])
    return (v11_0, v10_0, v0_0)