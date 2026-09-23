import torch
torch.manual_seed(0)

def model_func(dropout, train, dropout_seed, dtype, layout, device, pin_memory):
    out = torch.ops.aten._cudnn_init_dropout_state(
        dropout,
        train,
        dropout_seed=dropout_seed,
        dtype=dtype,
        layout=layout,
        device=device,
        pin_memory=pin_memory,
    )
    return out

args = (...)  # see execution_trace.json

eager = model_func(*args)
torch._dynamo.reset()
compiled = torch.compile(model_func, backend='eager')(*args)
print('eager   :', eager)
print('compiled:', compiled)
