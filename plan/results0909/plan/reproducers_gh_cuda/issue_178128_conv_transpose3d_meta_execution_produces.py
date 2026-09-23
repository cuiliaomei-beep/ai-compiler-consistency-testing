# source: https://github.com/pytorch/pytorch/issues/178128
# title: conv_transpose3d meta execution produces output for invalid bias shape instead of matching eager validation
# state: closed  created: 2026-03-23
# mined automatically; the harness records the torch.compile target and its first call

import torch
import numpy as np
import torch
import torch.nn.functional as F

def call_func(inputs, stride=1, padding=0, output_padding=0, groups=1, dilation=1):
    if len(inputs) == 2:
        input_tensor, weight = inputs
        bias = None
    elif len(inputs) == 3:
        input_tensor, weight, bias = inputs
    else:
        raise ValueError("inputs list must contain 2 (input, weight) or 3 (input, weight, bias) tensors")
    
    return F.conv_transpose3d(
        input_tensor, 
        weight, 
        bias=bias, 
        stride=stride, 
        padding=padding, 
        output_padding=output_padding, 
        groups=groups, 
        dilation=dilation
    )

# Create test inputs
input_tensor = torch.randn(20, 16, 50, 10, 20)
weight = torch.randn(16, 33, 3, 3, 3)
bias = torch.randn(33)
inputs = [input_tensor, weight, bias]

# Test parameters
stride = 1
padding = 1
output_padding = 1
groups = 2
dilation = 2

print("Testing torch.conv_transpose3d defect reproduction...")

# Test 1: Dynamic output shape (direct call)
print("\n1. Dynamic output shape (direct call):")
try:
    dynamic_result = call_func(inputs, stride=stride, padding=padding, output_padding=output_padding, groups=groups, dilation=dilation)
    print(f"Dynamic shape: {dynamic_result.shape}")
except Exception as e:
    print(f"Dynamic error: {e}")

# Test 2: Static output shape (torch.compile with dynamic=True)
print("\n2. Static output shape (torch.compile with dynamic=True):")
try:
    compiled_func = torch.compile(call_func, dynamic=True)
    static_result = compiled_func(inputs, stride=stride, padding=padding, output_padding=output_padding, groups=groups, dilation=dilation)
    print(f"Static shape: {static_result.shape}")
except Exception as e:
    print(f"Static error: {e}")

# Test 3: Meta output shape (device='meta')
print("\n3. Meta output shape (device='meta'):")
try:
    meta_input_tensor = torch.randn(20, 16, 50, 10, 20, device='meta')
    meta_weight = torch.randn(16, 33, 3, 3, 3, device='meta')
    meta_bias = torch.randn(33, device='meta')
    meta_inputs = [meta_input_tensor, meta_weight, meta_bias]
    
    meta_result = call_func(meta_inputs, stride=stride, padding=padding, output_padding=output_padding, groups=groups, dilation=dilation)
    print(f"Meta shape: {meta_result.shape}")
except Exception as e:
    print(f"Meta error: {e}")

print("\nDefect reproduction complete. The three approaches show inconsistent behavior.")
