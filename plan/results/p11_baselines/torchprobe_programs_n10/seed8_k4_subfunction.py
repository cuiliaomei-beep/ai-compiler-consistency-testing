def forward(mlist, v10_0):
    v11_0 = torch.abs(v10_0)
    v9_0 = v11_0.squeeze(0)
    v8_0 = torch.zeros(torch.Size([1]), dtype=torch.float32, device='cpu')
    for i in range(0, 1):
        v8_0[i] = torch.cos(v11_0[i])
    v0_0 = v8_0.argmax(0)
    backup = v8_0[0].clone()
    v8_0[0] = 0.94641024
    v8_0[0] = backup
    v4_0 = torch.nn.functional.softmax(v8_0, dim=0)
    v5_0 = v4_0.argmax(0)
    v6_0 = torch.min(v5_0, v5_0)

    def subfunc(v8_0):
        v1_0 = torch.neg(v8_0)
        if v1_0.sum() < v11_0.mean():
            v3_0 = v1_0.max(0).values
            v2_0 = torch.atan(v1_0)
        return (v2_0, v1_0, v3_0)
    v2_0, v1_0, v3_0 = subfunc(v8_0)
    return (v9_0, v0_0, v6_0, v3_0, v2_0)