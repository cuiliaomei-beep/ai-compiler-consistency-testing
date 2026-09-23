# source: https://github.com/pytorch/pytorch/issues/170642
# title: _cudnn_init_dropout_state crashes with dtype != Byte
# state: closed  created: 2025-12-17
# mined automatically; the harness records the torch.compile target and its first call

import torch

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

op_config = {
    "dropout": 0.5,
    "train": True,
    "dropout_seed": 12345,
    "dtype": torch.float32,   # non-byte dtype
    "layout": None,
    "device": "cuda:0",
    "pin_memory": False,
}

compiled_eager = torch.compile(model_func, backend="eager")
out = compiled_eager(**op_config)
