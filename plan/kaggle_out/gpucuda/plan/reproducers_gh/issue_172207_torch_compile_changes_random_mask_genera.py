# source: https://github.com/pytorch/pytorch/issues/172207
# title: torch.compile() changes random mask generation causing 2x difference in loss values
# state: closed  created: 2026-01-12
# mined automatically; the harness records the torch.compile target and its first call

import torch
import torch.nn as nn
import torch.nn.functional as F

class TestModel(nn.Module):

    def __init__(self):
        super().__init__()
        self.fc1 = nn.Linear(10, 20)
        self.relu = nn.ReLU()
        self.fc2 = nn.Linear(20, 1)

    def forward(self, x, y):
        batch_size, seq_len, d_model_in = x.shape
        x = self.fc1(x)
        x = self.relu(x)
        attention_mask = torch.ones(seq_len, seq_len)
        attention_mask_1 = torch.zeros(seq_len, seq_len)
        attention_mask_2 = torch.full((seq_len, seq_len), 1.0)
        scores = torch.matmul(x, x.transpose(-1, -2))
        scores = scores * torch.ones(seq_len, seq_len)
        scores = scores.masked_fill(attention_mask == 0, -1000000000.0)
        attn_weights = F.softmax(scores, dim=-1)
        attn_output = torch.matmul(attn_weights, x)
        attn_output = self.relu(attn_output)
        output = self.fc2(attn_output).mean(dim=1)
        loss = F.mse_loss(torch.where(torch.rand(output.size()).lt(0.3), 10000000000.0, output), y)
        return loss

def get_default_model():
    return TestModel()

def get_sample_inputs():
    x = torch.randn(2, 5, 10, requires_grad=True)
    y = torch.randn(2, 1)
    return (x, y)

def main():

    torch.manual_seed(42)

    model = get_default_model()
    model.eval()

    inputs = get_sample_inputs()

    with torch.no_grad():
        output = model(*inputs)

    print('Input shape:', inputs[0].shape)
    print('Output shape:', output.shape if hasattr(output, 'shape') else 'N/A')
    print('Output value:', output)

    compiled_model = torch.compile(model)
    with torch.no_grad():
        output_compile = compiled_model(*inputs)

    print(f'Compile shape: {output_compile.shape if hasattr(output_compile, "shape") else "N/A"}')
    print(f'Compile value: {output_compile}')


if __name__ == '__main__':
    main()
