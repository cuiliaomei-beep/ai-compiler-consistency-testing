def forward(mlist, v5_0):
    v9_0 = v5_0.sum(1)
    v6_0 = torch.sin(v5_0)
    v2_0 = torch.zeros(torch.Size([1, 1, 1, 1, 1]), dtype=torch.float64, device='cpu')
    for i in range(0, 1):
        v2_0[:, :, :, i, :] = torch.nn.functional.gelu(v6_0[:, :, :, i, :])
    v1_0 = torch.abs(v6_0)
    v0_0 = torch.sin(v1_0)
    backup = v0_0[0, 0, 0, 0, 0].clone()
    v0_0[0, 0, 0, 0, 0] = 0.8147134184837341
    v3_0 = torch.atan(v1_0)
    v10_0 = torch.max(v5_0, v3_0)
    v8_0 = v3_0.to(dtype=torch.bool)
    if v9_0.sum() >= v6_0.min():
        v7_0 = torch.sub(v3_0, v6_0)
        v4_0 = torch.mul(v2_0, v3_0)
    v0_0[0, 0, 0, 0, 0] = backup
    return (v9_0, v0_0, v10_0, v8_0, v7_0, v4_0)