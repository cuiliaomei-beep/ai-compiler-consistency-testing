def f(x):
    x = torch.relu(x)
    x[..., :-1] = x[..., 1:].clone()
    x = torch.sigmoid(x)
    _v = x[:]
    _v.mul_(0.5)
    x = -torch.abs(x)
    return x
