def forward(mlist, v10_0, v5_0):
    v11_0 = v10_0.triu(0)
    v4_0 = v11_0.triu(0)
    v7_0 = v11_0.max(1).values
    backup = v7_0[0].clone()
    v7_0[0] = 0.029281556606292725
    v7_0[0] = backup
    v6_0 = torch.div(v7_0, v5_0)
    v8_0 = v6_0.argmin(0)
    v0_0 = torch.lt(v8_0, v8_0)
    v2_0 = v6_0.to(dtype=torch.float64)
    v1_0 = torch.min(v6_0, v6_0)
    v9_0 = v1_0.reshape(1)
    v3_0 = torch.matmul(v2_0, v1_0)
    return (v4_0, v0_0, v9_0, v3_0)