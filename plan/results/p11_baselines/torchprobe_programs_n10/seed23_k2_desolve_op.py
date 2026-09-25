def forward(mlist, v0_0):
    v10_0 = mlist[0]()
    v9_0 = mlist[1]()
    v11_0 = torch.add(v9_0, v10_0)
    v7_0 = torch.zeros(torch.Size([2, 2]), dtype=torch.int32, device='cpu')
    for i in range(0, 2):
        v7_0[:, i] = torch.clip(v0_0[:, i], -1, 1)
    v8_0 = v11_0.tril(0)
    v4_0 = torch.Tensor.flatten(v8_0)
    v5_0 = torch.Tensor.flatten(v11_0)
    v12_0 = v5_0.to(dtype=torch.float32)
    v6_0 = torch.mul(v11_0, v7_0)
    backup = v6_0[0, 1].clone()
    v6_0[0, 1] = 0
    v6_0[0, 1] = backup
    v3_0 = v6_0.tril(0)
    v2_0 = torch.eq(v6_0, v6_0)
    v1_0 = torch.lt(v6_0, v6_0)
    return (v4_0, v12_0, v3_0, v2_0, v1_0)