# source: https://github.com/pytorch/pytorch/issues/191445
# title: [Inductor] Generated AOTAutograd forward wrapper uses unbacked SymInt before assignment for `cat` output
# state: open  created: 2026-07-29
# mined automatically; the harness records the torch.compile target and its first call

import torch

torch._dynamo.config.capture_scalar_outputs = True
torch._dynamo.config.capture_dynamic_output_shape_ops = True

NUM_EXPERTS = 4
HIDDEN_SIZE = 128


def grouped_experts(x, expert_ids, weights):
    order = torch.argsort(expert_ids)
    sorted_x = x.index_select(0, order)

    counts = torch.bincount(expert_ids, minlength=NUM_EXPERTS)
    ends = torch.cumsum(counts, dim=0)

    outputs = []
    start = 0
    for expert in range(NUM_EXPERTS):
        end = ends[expert].item()
        expert_input = sorted_x[start:end]
        outputs.append(expert_input @ weights[expert].T)
        start = end

    sorted_output = torch.cat(outputs, dim=0)
    output = torch.empty_like(sorted_output)
    output.index_copy_(0, order, sorted_output)
    return output


device = torch.device("cuda:0")
expert_ids = torch.tensor(
    [0, 1, 2, 3] * 16,
    device=device,
    dtype=torch.int64,
)
x = torch.randn(64, HIDDEN_SIZE, device=device, requires_grad=True)
weights = torch.randn(
    NUM_EXPERTS,
    HIDDEN_SIZE,
    HIDDEN_SIZE,
    device=device,
    requires_grad=True,
)

compiled = torch.compile(
    grouped_experts,
    backend="inductor",
    fullgraph=True,
    dynamic=True,
)
actual = compiled(x, expert_ids, weights)
actual.square().mean().backward()
torch.cuda.synchronize()
