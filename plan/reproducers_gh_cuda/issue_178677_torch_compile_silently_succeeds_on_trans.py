# source: https://github.com/pytorch/pytorch/issues/178677
# title: `torch.compile` silently succeeds on `TransformerEncoder` with all-masked `src_key_padding_mask` where eager raises RuntimeError
# state: open  created: 2026-03-28
# mined automatically; the harness records the torch.compile target and its first call

import torch
import torch.nn as nn

class RandomPermutationTransformer(nn.Module):
    def __init__(self, vocab_size=10000, d_model=512, nhead=8,
                 num_layers=6, slice_shape=8):
        super().__init__()
        self.slice_shape = slice_shape
        self.embedding = nn.Embedding(vocab_size, d_model)
        self.pos_encoding = nn.Parameter(torch.randn(1, 1000, d_model))
        encoder_layer = nn.TransformerEncoderLayer(
            d_model=d_model, nhead=nhead,
            dim_feedforward=2048, dropout=0.1, batch_first=True
        )
        self.transformer = nn.TransformerEncoder(
            encoder_layer, num_layers=num_layers
        )
        self.classifier = nn.Sequential(
            nn.Linear(d_model, 256), nn.ReLU(),
            nn.Dropout(0.2), nn.Linear(256, 2)
        )
        self.bn = nn.BatchNorm1d(d_model)

    def forward(self, x, attention_mask=None):
        batch_size, seq_len = x.shape
        embedded = self.embedding(x)
        embedded = embedded + self.pos_encoding[:, :seq_len, :]
        if attention_mask is not None:
            transformer_out = self.transformer(
                embedded, src_key_padding_mask=attention_mask
            )
        else:
            transformer_out = self.transformer(embedded)
        pooled = transformer_out.mean(dim=1)
        pooled = self.bn(pooled)
        perm = torch.randperm(batch_size, device=pooled.device)
        selected_indices = perm[:self.slice_shape]
        selected_pooled = pooled[selected_indices]
        logits = self.classifier(selected_pooled)
        return logits


model = RandomPermutationTransformer(
    vocab_size=10000, d_model=512, nhead=8,
    num_layers=6, slice_shape=8
).cuda()
model.eval()

input_ids = torch.randint(0, 10000, (16, 128), dtype=torch.long).cuda()
# All positions masked — edge case
attention_mask = torch.ones(16, 128, dtype=torch.bool).cuda()

# Eager: fails
try:
    with torch.no_grad():
        model(input_ids, attention_mask)
    print("eager: OK")
except RuntimeError as e:
    print(f"eager: ERROR — {e}")

# Compiled: succeeds (inconsistent)
torch._dynamo.reset()
compiled_model = torch.compile(model)
try:
    with torch.no_grad():
        out = compiled_model(input_ids, attention_mask)
    print(f"compile: OK — shape={out.shape}")
except Exception as e:
    print(f"compile: ERROR — {e}")
