def forward(mlist, v7_0, v11_0, v8_0, v0_0):
    v14_0 = v7_0.transpose(0, 1)
    v13_0 = torch.sub(v11_0, v14_0)
    v9_0 = torch.mul(v13_0, v8_0)
    v6_0 = torch.nn.functional.pad(v9_0, (0, -1, 0, 0), 'replicate')
    v2_0 = v0_0.min(4).values
    backup = v13_0[0, 0, 0, 1].clone()
    v13_0[0, 0, 0, 1] = 0.9432387
    v5_0 = mlist[0](v2_0)
    v4_0 = v0_0.max(3).values
    v1_0 = v4_0.argmin(2)
    v3_0 = torch.div(v6_0, v4_0)
    v10_0 = v3_0.reshape(4, 1, 2, 1)
    return (v5_0, v1_0, v10_0)