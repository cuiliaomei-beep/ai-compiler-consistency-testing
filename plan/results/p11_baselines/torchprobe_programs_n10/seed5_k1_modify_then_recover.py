def forward(mlist, v8_0, v7_0):
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
    v0_0 = torch.clip(v2_0, -1.5, 1.5)
    v1_0 = torch.relu(v0_0)
    v10_0 = torch.min(v2_0, v1_0)
    return (v11_0, v5_0, v4_0, v10_0)