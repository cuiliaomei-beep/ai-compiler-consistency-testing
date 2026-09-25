def forward(mlist, v11_0, v9_0):
    v12_0 = v11_0.max(0).values
    v7_0 = torch.nn.functional.leaky_relu(v12_0)
    v10_0 = torch.mul(v12_0, v9_0)
    v8_0 = torch.sin(v10_0)
    v4_0 = torch.nn.functional.gelu(v8_0)
    v2_0 = torch.sub(v8_0, v4_0)
    v3_0 = torch.tan(v4_0)
    v5_0 = torch.max(v2_0, v3_0)
    v1_0 = v3_0.to(dtype=torch.bool)
    if v3_0 < v10_0:
        v6_0 = torch.logical_xor(v1_0, v1_0)
    return (v7_0, v5_0, v6_0)