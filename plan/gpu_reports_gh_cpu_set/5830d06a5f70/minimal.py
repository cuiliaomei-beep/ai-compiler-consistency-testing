import torch
torch.manual_seed(0)

def model():
    out = F.scaled_dot_product_attention(x, x, x)   # [4, 12, 4]
    out, _ = m_mha(out, out, out)                    # [4, 12, 4]
    out = torch.fft.fft(out).abs()                   # [4, 12, 4] real
    out = m_hardswish(out)                           # [4, 12, 4]
    return out

args = (...)  # see execution_trace.json

eager = model(*args)
torch._dynamo.reset()
compiled = torch.compile(model, backend='inductor')(*args)
print('eager   :', eager)
print('compiled:', compiled)
