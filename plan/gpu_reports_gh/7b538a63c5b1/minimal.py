import torch
torch.manual_seed(0)

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

args = (torch.randn(64, 128).requires_grad_(True), torch.randint(0, 4, (64,)), torch.randn(4, 128, 128))

eager = grouped_experts(*args)
torch._dynamo.reset()
compiled = torch.compile(grouped_experts, backend='inductor')(*args)
print('eager   :', eager)
print('compiled:', compiled)
