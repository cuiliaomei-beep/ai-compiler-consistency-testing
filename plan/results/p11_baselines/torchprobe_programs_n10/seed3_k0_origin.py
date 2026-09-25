def forward(mlist, v6_0, v4_0):
    v10_0 = v6_0[-1:1:1, :, :]
    v9_0 = v10_0.squeeze(1)
    v7_0 = v9_0.mean(1)
    v5_0 = torch.sub(v7_0, v4_0)
    v3_0 = v5_0.to(dtype=torch.float32)
    v11_0 = torch.Tensor.flatten(v3_0)
    v8_0 = torch.mul(v3_0, v3_0)
    v0_0 = v5_0.min(0).values
    v1_0 = torch.atan(v5_0)
    v2_0 = v1_0.squeeze(0)
    return (v11_0, v8_0, v0_0, v2_0)