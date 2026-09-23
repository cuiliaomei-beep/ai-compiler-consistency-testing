# source: https://github.com/pytorch/pytorch/issues/136662
# title: Composition of torch.compile and torch.func.grad silently produces a wrong result. 
# state: closed  created: 2024-09-25
# mined automatically; the harness records the torch.compile target and its first call

import torch

fixed_values = torch.tensor([[    0.0000,     0.0000,     0.0000,     0.0000,     0.0000,     0.0000],
                             [    0.0000,     0.0000,     0.0000,     0.0000,     0.0000,     0.0000],
                             [    0.0000,     0.0000,     0.0000,     0.0000,     0.0000,     0.0000],
                             [-1068.6385,     0.0000,    65.0000,     0.0000, -torch.inf,     0.0000]],
                            dtype=torch.float64)

free_vars_mask = torch.tensor([[ True,  True, False,  True,  True,  True],
                               [ True, False,  True,  True,  True,  True],
                               [ True,  True,  True,  True,  True,  True],
                               [False, False, False, False, False,  True]])

dependency_matrix = torch.tensor([[[1.0000, 0.0000, 0.0000, 0.0000, 0.0000, 0.0000],
                                   [0.0000, 1.0000, 0.0000, 0.0000, 0.0000, 0.0000],
                                   [0.0000, 0.0000, 1.0000, 2.0000, 0.0000, 0.0000],
                                   [0.0000, 0.0000, 0.5000, 1.0000, 0.0000, 0.0000],
                                   [0.0000, 0.0000, 0.0000, 0.0000, 1.0000, 0.0000],
                                   [0.0000, 0.0000, 0.0000, 0.0000, 0.0000, 1.0000]],
                        
                                  [[1.0000, 0.0000, 0.0000, 0.0000, 0.0000, 0.0000],
                                   [0.0000, 1.0000, 0.0000, 0.0000, 0.0000, 0.0000],
                                   [0.0000, 0.0000, 1.0000, 0.0000, 0.0000, 0.0000],
                                   [0.0000, 0.0000, 0.0000, 1.0000, 0.0000, 0.0000],
                                   [0.0000, 0.0000, 0.0000, 0.0000, 1.0000, 0.0000],
                                   [0.0000, 0.0000, 0.0000, 0.0000, 0.0000, 1.0000]],
                          
                                  [[1.0000, 0.0000, 0.0000, 0.0000, 0.0000, 0.0000],
                                   [0.0000, 1.0000, 0.0000, 0.0000, 0.0000, 0.0000],
                                   [0.0000, 0.0000, 1.0000, 0.0000, 0.0000, 0.0000],
                                   [0.0000, 0.0000, 0.0000, 1.0000, 0.0000, 0.0000],
                                   [0.0000, 0.0000, 0.0000, 0.0000, 1.0000, 0.0000],
                                   [0.0000, 0.0000, 0.0000, 0.0000, 0.0000, 1.0000]],
                          
                                  [[1.0000, 0.0000, 0.0000, 0.0000, 0.0000, 0.0000],
                                   [0.0000, 1.0000, 0.0000, 0.0000, 0.0000, 0.0000],
                                   [0.0000, 0.0000, 1.0000, 0.0000, 0.0000, 0.0000],
                                   [0.0000, 0.0000, 0.0000, 1.0000, 0.0000, 0.0000],
                                   [0.0000, 0.0000, 0.0000, 0.0000, 1.0000, 0.0000],
                                   [0.0000, 0.0000, 0.0000, 0.0000, 0.0000, 1.0000]]],
                                 dtype=torch.float64)

free_vars_linear_indices = torch.where(free_vars_mask.ravel())[0]
free_vars_indices = tuple(map(lambda x: x.detach().clone(),\
                              torch.unravel_index(free_vars_linear_indices,\
                                                  free_vars_mask.shape)))

test_input = torch.tensor([-218.5399,    3.1056,   21.8333,    4.1535,    0.2   ,  144.8986,
                             49.6429,   60.1429,    3.9028,    0.59  ,  126.218 ,   -6.0392,
                             98.5   ,   35.5714,    4.8792,    0.2   ,    0.01  ],
                          dtype=torch.float64)

def to_constrained_params(vars):
    
    two_over_pi = torch.tensor(2.0 / torch.pi, dtype=vars.dtype)
    one = torch.tensor(1.0, dtype=vars.dtype)
    hundred = torch.tensor(100.0, dtype=vars.dtype)
    fifty = torch.tensor(50.0, dtype=vars.dtype)
    
    processed_vars = torch.zeros_like(vars)

    processed_vars[:, 0] += (two_over_pi * torch.arctan(vars[:, 0] / hundred) + one)*fifty
    processed_vars[:, 2] += torch.abs(vars[:, 2])
    processed_vars[:, 3] += torch.abs(vars[:, 3])
    processed_vars[:, 4] += torch.exp(vars[:, 4])

    processed_vars[:, 1] += torch.abs(vars[:, 1])
    processed_vars[[2], 1] *= -1
    
    weights = torch.abs(vars[:, 5])
    weights = weights / torch.sum(weights)
    processed_vars[:, 5] += weights

    return processed_vars
    
def test_func(free_vars):

    # Prepare free variable by placing them at the right indices of the All Variables Matrix
    free_vars_same_shape = torch.zeros_like(fixed_values, dtype=free_vars.dtype)
    free_vars_same_shape[free_vars_indices] += free_vars

    # Create All Variables Matrix by merging free variable and fixed variables
    # and performing Unconstrained-To-Constrained transformation
    processed_vars = to_constrained_params(fixed_values + free_vars_same_shape)

    processed_vars = (processed_vars.unsqueeze(-2) @ dependency_matrix).squeeze(dim=-2)
    
    return processed_vars.sum()

# the Test Function without JIT compilation
print(test_func(test_input))
# tensor(760.4707, dtype=torch.float64)

# the Test Function with JIT compilation - Same Output
print(torch.compile(test_func, fullgraph=True)(test_input))
# tensor(760.4707, dtype=torch.float64)


# The gradient of the test function without JIT
print(torch.func.grad(test_func, argnums=0)(test_input))
# tensor([5.5109e-02, 1.0000e+00, 1.5000e+00, 6.3656e+01, 0.0000e+00, 1.0270e-01,
#         1.0000e+00, 1.0000e+00, 4.9541e+01, 0.0000e+00, 1.2275e-01, 1.0000e+00,
#         1.0000e+00, 1.0000e+00, 1.3153e+02, 0.0000e+00, 0.0000e+00],
#        dtype=torch.float64)

# The gradient of the test function with JIT
print(torch.compile(torch.func.grad(test_func, argnums=0), fullgraph=True)(test_input))
# tensor([0., 1., 0., 0., 0., 0., 0., 0., 0., 0., 0., 1., 0., 0., 0., 0., 0.],
#        dtype=torch.float64)
