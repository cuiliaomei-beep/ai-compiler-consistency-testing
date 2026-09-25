def forward(mlist, v10_0):
    v11_0 = torch.nn.functional.pad(v10_0, (-1, -1, -1, -1, 0, -1), 'reflect')
    v5_0 = torch.sin(v11_0)
    v9_0 = torch.atan(v11_0)
    v8_0 = torch.nn.functional.avg_pool2d(v9_0, kernel_size=(510, 511), stride=1, padding=255)
    v7_0 = torch.nn.functional.gelu(v8_0)
    v6_0 = torch.sigmoid(v7_0)
    v4_0 = v6_0.max(1).values
    v3_0 = torch.relu(v4_0)
    v0_0 = v3_0[0:3640:3639, :, :]
    v2_0 = mlist[1](v3_0)
    return (v5_0, v0_0, v2_0)