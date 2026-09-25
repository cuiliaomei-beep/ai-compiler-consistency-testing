def forward(mlist, v10_0, v8_0):
    v11_0 = mlist[0]()
    v12_0 = torch.min(v10_0, v11_0)
    v9_0 = torch.relu(v8_0)
    v6_0 = torch.mul(v9_0, v12_0)
    v7_0 = torch.max(v6_0, v9_0)
    backup = v6_0[0].clone()
    v6_0[0] = 0.97438866
    v6_0[0] = backup
    v1_0 = torch.abs(v6_0)
    v0_0 = torch.zeros(torch.Size([1]), dtype=torch.bool, device='cpu')
    for i in range(0, 1):
        v0_0[i] = torch.lt(v1_0[i], v6_0[i])
    v3_0 = v1_0.to(dtype=torch.float32)
    v5_0 = v3_0.argmin(0)
    v4_0 = torch.gt(v3_0, v12_0)
    if v6_0[0] >= v8_0.max():
        v2_0 = v1_0.to(dtype=torch.bool)
    return (v7_0, v0_0, v5_0, v4_0, v2_0)