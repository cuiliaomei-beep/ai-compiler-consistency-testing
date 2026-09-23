def f(x):
    x = torch.tanh(x)
    x[..., :-1] = x[..., 1:].clone()
    x = torch.relu(x)
    _v = x[:]
    _v.mul_(0.5)
    x = x + 0.25
    return x
