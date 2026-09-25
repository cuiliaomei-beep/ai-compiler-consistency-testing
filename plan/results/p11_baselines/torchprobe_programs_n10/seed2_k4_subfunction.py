def forward(mlist, v6_0):
    v7_0 = mlist[0]()
    v13_0 = torch.sigmoid(v7_0)
    v10_0 = mlist[1]()
    v12_0 = torch.div(v10_0, v13_0)
    v8_0 = torch.add(v6_0, v12_0)
    v9_0 = v8_0.to(dtype=torch.float64)
    v4_0 = torch.nn.functional.leaky_relu(v8_0)
    v3_0 = torch.nn.functional.leaky_relu(v4_0)
    v0_0 = torch.add(v3_0, v8_0)

    def subfunc(v0_0):
        v1_0 = v0_0.to(dtype=torch.bool)
        v5_0 = torch.add(v0_0, v0_0)
        v2_0 = torch.clip(v3_0, -1.5, 1.5)
        return (v2_0, v1_0, v5_0)
    v2_0, v1_0, v5_0 = subfunc(v0_0)
    return (v9_0, v1_0, v5_0, v2_0)