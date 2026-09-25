def forward(mlist, v11_0, v7_0):
    v12_0 = mlist[0]()
    v13_0 = torch.matmul(v11_0, v12_0)
    v8_0 = torch.nn.functional.softmax(v7_0, dim=0)
    v6_0 = torch.cos(v13_0)
    v5_0 = v6_0.transpose(0, 2)
    v4_0 = v8_0.argmin(0)
    v10_0 = v4_0[-1:1:1]
    v9_0 = v4_0.to(dtype=torch.int32)
    v1_0 = v4_0.to(dtype=torch.float32)
    v0_0 = torch.nn.functional.leaky_relu(v8_0)
    v3_0 = torch.matmul(v8_0, v5_0)
    return (v10_0, v9_0, v1_0, v0_0, v3_0)