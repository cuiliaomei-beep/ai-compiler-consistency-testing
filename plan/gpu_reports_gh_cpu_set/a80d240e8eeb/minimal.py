import torch
torch.manual_seed(0)

def forward(self, x):
        p = torch.randperm(5)
        # Create a non-injective (overlapping) view of randperm 
        idx = torch.as_strided(p, (5,), (0,))
        y = x[idx] + 1.0
        x.index_put_((idx,), y, accumulate=False)
        return x

args = (...)  # see execution_trace.json

eager = f(*args)
torch._dynamo.reset()
compiled = torch.compile(f, backend='inductor')(*args)
print('eager   :', eager)
print('compiled:', compiled)
