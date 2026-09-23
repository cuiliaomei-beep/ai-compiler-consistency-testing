# source: https://github.com/pytorch/pytorch/issues/180841
# title: [Inductor] ImportError: file too short when compiling model with nn.MultiheadAttention and invalid attn_mask shape
# state: closed  created: 2026-04-20
# mined automatically; the harness records the torch.compile target and its first call

import torch
import torch.nn as nn

class TestAttentionModel(nn.Module):

    def __init__(self):
        super().__init__()
        self.fc1 = nn.Linear(20, 20)
        self.relu = nn.ReLU()
        self.fc2 = nn.Linear(20, 20)
        self.num_heads = 4
        self.attention = nn.MultiheadAttention(embed_dim=20, num_heads=1, batch_first=True)
        self.loss_fn = nn.MSELoss()

    def my_attention(self, x, num_heads=1):
        attn_mask = torch.ones((x.shape[0], x.shape[1], x.shape[1]), dtype=torch.bool)
        return self.attention(x, x, x, attn_mask=attn_mask)

    def forward(self, x):
        x = self.fc1(x)
        x = self.relu(x)
        x = self.fc2(x)
        (attn_out, _) = self.my_attention(x)
        return attn_out

def get_default_model():
    return TestAttentionModel()

def get_sample_inputs():
    x = torch.randn(2, 1, 20, requires_grad=True)
    return (x,)

def main():
    model = get_default_model()
    model.eval()
    inputs = get_sample_inputs()
    try:
        with torch.no_grad():
            output_eager = model(*inputs)
        print(f'Eager: {output_eager}')
    except Exception as e:
        print(f'Eager: {e}')
    try:
        compiled_model = torch.compile(model, fullgraph=True)
        with torch.no_grad():
            output_compile = compiled_model(*inputs)
        print(f'Compile: {output_compile}')
    except Exception as e:
        print(f'\nOriginal exception:\n {e}')
if __name__ == '__main__':
    main()
