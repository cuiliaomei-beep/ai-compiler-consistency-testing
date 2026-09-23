# source: https://github.com/pytorch/pytorch/issues/188545
# title: [PT2] Output mismatch between eager and torch.compile for torch.special.bessel_y0 with +inf input on CUDA
# state: closed  created: 2026-06-30
# mined automatically; the harness records the torch.compile target and its first call

import torch

def test_bessel_y0_mismatch():
    x = torch.tensor([float('nan'), float('inf'), float('-inf')], dtype=torch.float64, device='cuda')
    
    print("Input:", x)
    
    eager_out = torch.special.bessel_y0(x)
    print("Eager output:   ", eager_out)
    
    @torch.compile(backend="inductor")
    def compiled_bessel_y0(x):
        return torch.special.bessel_y0(x)
        
    inductor_out = compiled_bessel_y0(x)
    print("Inductor output:", inductor_out)
    

if __name__ == "__main__":
    test_bessel_y0_mismatch()
