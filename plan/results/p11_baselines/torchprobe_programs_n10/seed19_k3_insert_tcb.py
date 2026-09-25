def forward(mlist, v9_0):
    v10_0 = torch.nn.functional.pad(v9_0, (0, 0, 0, 0, 0, 0, 0, 0), 'constant', value=0.5)
    v8_0 = torch.cos(v10_0)
    v7_0 = v8_0.transpose(2, 4)
    backup = v10_0[0, 0, 0, 0, 0].clone()
    v10_0[0, 0, 0, 0, 0] = 0.87992793
    v4_0 = torch.nn.functional.gelu(v7_0)
    v1_0 = torch.sub(v4_0, v4_0)
    if v8_0.min() >= v7_0.max():
        v6_0 = torch.zeros(torch.Size([1, 1, 1, 1, 1]), dtype=torch.float32, device='cpu')
        for i in range(0, 1):
            v6_0[:, i, :, :, :] = torch.atan(v1_0[:, i, :, :, :])
        v5_0 = v1_0.to(dtype=torch.int32)
        v3_0 = torch.clip(v5_0, -1, 1)
        v0_0 = torch.sub(v4_0, v1_0)
        v2_0 = torch.cos(v1_0)
    return (v6_0, v3_0, v0_0, v2_0)