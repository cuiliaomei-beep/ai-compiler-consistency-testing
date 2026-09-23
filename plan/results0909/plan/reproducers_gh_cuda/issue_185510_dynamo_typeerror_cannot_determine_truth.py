# source: https://github.com/pytorch/pytorch/issues/185510
# title: [Dynamo] TypeError: cannot determine truth value of Relational during stride sorting with dynamic=True
# state: open  created: 2026-05-28
# mined automatically; the harness records the torch.compile target and its first call

import torch
import torch.nn.functional as F

def target_function(x, shift, g2_x, g2_pw, g2_b, g2_fw, g3_x, g3_shift, g4_rolled, g4_cw, g4_cb, 
                    g5_x, g5_shift, g7_x, g7_shift, g8_x, g8_shift, g9_x, g9_aff, g9_crop, 
                    g10_x, g10_off, g10_pw, g10_pb, g10_blend, g1_crop, g6_cw, g6_cb):
    
    resized = F.interpolate(x, scale_factor=[1.5, 1.25], mode='bilinear', align_corners=False)
    
    patches = F.unfold(g2_x, kernel_size=3, padding=1, stride=1).transpose(1, 2).contiguous()
    proj = torch.einsum('blp,op->blo', patches, g2_pw) + g2_b.view(1, 1, -1)
    restored = torch.einsum('blo,po->blp', F.gelu(proj), g2_fw).transpose(1, 2).contiguous()
    norm = F.fold(torch.ones_like(restored), output_size=[6, 7], kernel_size=3, padding=1, stride=1).clamp_min(1.0)
    g2_call = F.fold(restored, output_size=[6, 7], kernel_size=3, padding=1, stride=1) / norm

    g3_call = F.interpolate(g3_x, scale_factor=[1.5, 1.25], mode='bilinear', align_corners=False)
    g5_call = F.interpolate(g5_x, scale_factor=[1.5, 1.25], mode='bilinear', align_corners=False)
    g7_call = F.interpolate(g7_x, scale_factor=[1.5, 1.25], mode='bilinear', align_corners=False)
    g8_call = F.interpolate(g8_x, scale_factor=[1.5, 1.25], mode='bilinear', align_corners=False)

    conv4 = F.conv2d(g4_rolled[:, :, 1:7, 1:8], g4_cw, g4_cb, padding=1)
    pool4 = F.max_pool2d(conv4, kernel_size=3, stride=1, padding=1)
    g4_call = torch.where(conv4 > pool4.mean(dim=[2, 3], keepdim=True), conv4, pool4)

    res9 = F.interpolate(F.pad(g9_x, [1, 2, 2, 1], 'reflect'), scale_factor=1.5, mode='bicubic', align_corners=False)
    grid9 = F.affine_grid(g9_aff, size=[2, 3, 13, 15], align_corners=False)
    g9_call = F.grid_sample(res9, grid9, mode='bilinear', padding_mode='reflection', align_corners=False)

    yy, xx = torch.meshgrid(torch.linspace(-1, 1, 6), torch.linspace(-1, 1, 7), indexing='ij')
    base = torch.stack([xx, yy], dim=-1).view(1, 6, 7, 2)
    gs = [F.grid_sample(g10_x, (base + g10_off[:, i].view(2, 1, 1, 2)).clamp(-1, 1), mode='bilinear', align_corners=True, padding_mode='border') for i in range(4)]
    proj10 = F.conv2d(torch.cat(gs, dim=1), g10_pw, g10_pb)
    sm10 = F.avg_pool2d(proj10, kernel_size=3, stride=1, padding=1)
    fused = proj10 * g10_blend.view(1, -1, 1, 1) + sm10 * (1.0 - g10_blend.view(1, -1, 1, 1))
    g10_call = torch.tanh(fused) * torch.sigmoid(fused)

    g1_call = torch.roll(resized, shifts=[1, -2], dims=[-2, -1])
    conv6 = F.conv2d(resized[:, :, 1:7, 1:8], g6_cw, g6_cb, padding=1)
    pool6 = F.max_pool2d(conv6, kernel_size=3, stride=1, padding=1)
    g6_call = torch.where(conv6 > pool6.mean(dim=[2, 3], keepdim=True), conv6, pool6)

    return g2_call, g3_call, g4_call, g5_call, g7_call, g8_call, g9_call, g10_call, g1_call, g6_call

if __name__ == "__main__":
    import traceback

    def rand(*shape):
        return torch.randn(*shape, dtype=torch.float32, requires_grad=True)

    def zero(*shape):
        return torch.zeros(*shape, dtype=torch.int64)

    def make_inputs():
        return [
            rand(2, 3, 6, 7), zero(2),
            rand(2, 3, 6, 7), rand(4, 27), rand(4), rand(27, 4),
            rand(2, 3, 6, 7), zero(2),
            rand(2, 3, 9, 8), rand(4, 3, 3, 3), rand(4),
            rand(2, 3, 6, 7), zero(2),
            rand(2, 3, 6, 7), zero(2),
            rand(2, 3, 6, 7), zero(2),
            rand(2, 3, 6, 7), rand(2, 2, 3), zero(2),
            rand(2, 3, 6, 7), rand(2, 4, 2),
            rand(4, 12, 1, 1), rand(4), rand(4),
            zero(2), rand(4, 3, 3, 3), rand(4),
        ]

    def clone_inputs(xs):
        return [
            x.detach().clone().requires_grad_(x.requires_grad)
            if x.is_floating_point() else x.clone()
            for x in xs
        ]

    def run(name, fn, xs):
        print(f"\n=== {name} ===")
        try:
            ys = fn(*xs)
            loss = sum(y.sum() for y in ys if y.is_floating_point())

            print("forward ok")
            print("loss:", loss.item())

            loss.backward()
            print("backward ok")

        except Exception:
            print("failed")
            traceback.print_exc()

    print("torch:", torch.__version__)
    print("cuda:", torch.version.cuda)

    inputs = make_inputs()

    run("Eager", target_function, clone_inputs(inputs))

    compiled_fn = torch.compile(target_function, backend="inductor", dynamic=True)
    run("Compiled / Inductor", compiled_fn, clone_inputs(inputs))
