def forward(mlist, v8_0):
    v9_0 = torch.clip(v8_0, -1.5, 1.5)
    v7_0 = torch.nn.functional.pad(v9_0, (0, 0, 0, 0), 'constant', value=0.5)
    v6_0 = torch.nn.functional.pad(v7_0, (1, 0, 0, 0), 'constant', value=0.5)
    v3_0 = v6_0.max(2).values
    v2_0 = torch.nn.functional.avg_pool2d(v3_0, kernel_size=(510, 511), stride=1, padding=255)
    v5_0 = v3_0.transpose(2, 1)
    v4_0 = v3_0.squeeze(2)
    v10_0 = torch.matmul(v4_0, v4_0)
    v1_0 = torch.nn.functional.pad(v3_0, (0, -1, 0, 0), 'reflect')
    v0_0 = torch.sigmoid(v1_0)
    return (v2_0, v5_0, v10_0, v0_0)