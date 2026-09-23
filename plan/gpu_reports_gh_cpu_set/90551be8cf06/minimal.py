import torch
torch.manual_seed(0)

def test_factory_apis():
    return {
        "ones": torch.ones(2),
        "zeros": torch.zeros(2),
        "tensor": torch.tensor([1.0, 2.0]),
        "arange": torch.arange(2.0),
        "empty": torch.empty(2)
    }

args = (...)  # see execution_trace.json

eager = test_factory_apis(*args)
torch._dynamo.reset()
compiled = torch.compile(test_factory_apis, backend='eager')(*args)
print('eager   :', eager)
print('compiled:', compiled)
