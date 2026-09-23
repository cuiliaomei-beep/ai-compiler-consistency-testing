import torch
torch.manual_seed(0)

def fn(q, k, v, current_pos: int):
    P_plus = current_pos + 1                  # derived sym-int OUTSIDE the closure
    def mask_mod(b, h, q_idx, kv_idx):
        return (kv_idx >= 0) & (kv_idx <= P_plus)
    bm = create_block_mask(mask_mod, B=None, H=None,
                            Q_LEN=q.shape[2], KV_LEN=k.shape[2],
                            device=q.device)
    return flex_attention(q, k, v, block_mask=bm)

args = (torch.randn(1, 4, 1, 64).to(torch.float16), torch.randn(1, 4, 13, 64).to(torch.float16), torch.randn(1, 4, 13, 64).to(torch.float16))

eager = fn(*args)
torch._dynamo.reset()
compiled = torch.compile(fn, backend='eager')(*args)
print('eager   :', eager)
print('compiled:', compiled)
