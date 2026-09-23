"""Write real-model reproducer files (NEXT_DIRECTIONS 5.7) into reproducers_models/.

Each file builds a small torchvision model (random weights, fixed seed, eval mode) and calls
``torch.compile(target)(x)`` once, which is what ``run.py campaign --from-dir`` records.
Variants per model: fp32 / channels_last / bf16 autocast / train mode / dynamic=True, plus
torchvision.ops functional reproducers (roi_align, nms, deform_conv2d, ...).

usage: python scripts/make_model_reproducers.py [--out reproducers_models] [--size 64] [--batch 2]
Then:  python run.py campaign --from-dir reproducers_models --backend inductor --out reports_models
"""
import argparse
import os

HERE = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))

MODELS = {
    # name: (constructor expression, extra ctor kwargs)
    "resnet18": "torchvision.models.resnet18(weights=None)",
    "mobilenet_v3_small": "torchvision.models.mobilenet_v3_small(weights=None)",
    "mobilenet_v2": "torchvision.models.mobilenet_v2(weights=None)",
    "squeezenet1_0": "torchvision.models.squeezenet1_0(weights=None)",
    "shufflenet_v2_x0_5": "torchvision.models.shufflenet_v2_x0_5(weights=None)",
    "efficientnet_b0": "torchvision.models.efficientnet_b0(weights=None)",
    "regnet_y_400mf": "torchvision.models.regnet_y_400mf(weights=None)",
    "mnasnet0_5": "torchvision.models.mnasnet0_5(weights=None)",
    "convnext_tiny": "torchvision.models.convnext_tiny(weights=None)",
    "densenet121": "torchvision.models.densenet121(weights=None)",
    "googlenet": "torchvision.models.googlenet(weights=None, aux_logits=False, init_weights=False)",
    "vit_small": ("torchvision.models.vision_transformer.VisionTransformer(image_size=SIZE, patch_size=8, "
                  "num_layers=2, num_heads=2, hidden_dim=32, mlp_dim=64)"),
    "swin_small": ("torchvision.models.swin_transformer.SwinTransformer(patch_size=[4, 4], embed_dim=24, "
                   "depths=[2, 2], num_heads=[2, 2], window_size=[4, 4])"),
    "fcn_resnet18_like": None,   # segmentation head on a small backbone, written explicitly below
}

VARIANTS = ("fp32", "channels_last", "bf16_autocast", "train", "dynamic")

HEADER = '''# Real model reproducer (NEXT_DIRECTIONS 5.7): {model} / {variant}
# torchvision {tv_note}; random weights, fixed seed; input {batch}x3x{size}x{size}.
import torch
import torchvision

torch.manual_seed(0)
SIZE = {size}
'''

OPS_FILES = {
    "ops_roi_align": '''# torchvision.ops.roi_align under torch.compile (custom op with a meta kernel)
import torch
import torchvision

torch.manual_seed(0)
feat = torch.randn(2, 4, 16, 16)
boxes = torch.tensor([[0, 1.0, 1.0, 9.0, 9.0], [1, 2.0, 3.0, 14.0, 12.0], [0, 0.0, 0.0, 15.0, 15.0]])


def f(feat, boxes):
    return torchvision.ops.roi_align(feat, boxes, output_size=(4, 4), spatial_scale=1.0, sampling_ratio=2, aligned=True)


print(torch.compile(f)(feat, boxes))
''',
    "ops_nms": '''# torchvision.ops.nms under torch.compile (data-dependent output shape)
import torch
import torchvision

torch.manual_seed(0)
boxes = torch.rand(32, 4) * 50
boxes[:, 2:] += boxes[:, :2] + 1
scores = torch.rand(32)


def f(boxes, scores):
    keep = torchvision.ops.nms(boxes, scores, 0.5)
    return boxes[keep].sum(dim=0), keep.numel()


print(torch.compile(f)(boxes, scores))
''',
    "ops_box_iou": '''# torchvision.ops.box_iou / box_convert under torch.compile
import torch
import torchvision

torch.manual_seed(0)
a = torch.rand(6, 4) * 20
a[:, 2:] += a[:, :2] + 1
b = torch.rand(5, 4) * 20
b[:, 2:] += b[:, :2] + 1


def f(a, b):
    iou = torchvision.ops.box_iou(a, b)
    c = torchvision.ops.box_convert(a, "xyxy", "cxcywh")
    return iou, c, torchvision.ops.generalized_box_iou(a, b)


print(torch.compile(f)(a, b))
''',
    "ops_deform_conv2d": '''# torchvision.ops.deform_conv2d under torch.compile
import torch
import torchvision

torch.manual_seed(0)
x = torch.randn(1, 4, 10, 10)
offset = torch.randn(1, 2 * 3 * 3, 8, 8) * 0.5
weight = torch.randn(6, 4, 3, 3)
mask = torch.rand(1, 3 * 3, 8, 8)


def f(x, offset, weight, mask):
    return torchvision.ops.deform_conv2d(x, offset, weight, mask=mask)


print(torch.compile(f)(x, offset, weight, mask))
''',
    "ops_stochastic_depth_eval": '''# torchvision.ops.StochasticDepth / DropBlock in eval mode (identity) + FrozenBatchNorm2d
import torch
import torchvision

torch.manual_seed(0)


class Net(torch.nn.Module):
    def __init__(self):
        super().__init__()
        self.bn = torchvision.ops.FrozenBatchNorm2d(3)
        self.sd = torchvision.ops.StochasticDepth(0.2, "row")
        self.conv = torch.nn.Conv2d(3, 3, 3, padding=1)

    def forward(self, x):
        return self.sd(self.conv(self.bn(x))) + x


model = Net().eval()
x = torch.randn(2, 3, 8, 8)
print(torch.compile(model)(x))
''',
}

SEG_MODEL = '''

class SegNet(torch.nn.Module):
    """FCN-style head on the first two resnet18 stages (segmentation = interpolate + conv)."""

    def __init__(self):
        super().__init__()
        r = torchvision.models.resnet18(weights=None)
        self.stem = torch.nn.Sequential(r.conv1, r.bn1, r.relu, r.maxpool, r.layer1, r.layer2)
        self.head = torch.nn.Sequential(torch.nn.Conv2d(128, 32, 3, padding=1), torch.nn.BatchNorm2d(32),
                                        torch.nn.ReLU(), torch.nn.Dropout(0.1), torch.nn.Conv2d(32, 5, 1))

    def forward(self, x):
        h, w = x.shape[-2:]
        y = self.head(self.stem(x))
        return torch.nn.functional.interpolate(y, size=(h, w), mode="bilinear", align_corners=False)


model = SegNet()
'''


def body(model_key: str, ctor: str, variant: str, batch: int, size: int) -> str:
    out = []
    if ctor is None:
        out.append(SEG_MODEL)
    else:
        out.append(f"\nmodel = {ctor}\n")
    if variant == "train":
        out.append("model.train()\n")
    else:
        out.append("model.eval()\n")
    out.append(f"x = torch.randn({batch}, 3, SIZE, SIZE)\n")
    if variant == "channels_last":
        out.append("model = model.to(memory_format=torch.channels_last)\n"
                   "x = x.contiguous(memory_format=torch.channels_last)\n")
    if variant == "bf16_autocast":
        out.append("\n\ndef f(x):\n    with torch.autocast(x.device.type, dtype=torch.bfloat16):\n        return model(x)\n\n\n"
                   "print(torch.compile(f)(x))\n")
    elif variant == "dynamic":
        out.append("\ncompiled = torch.compile(model, dynamic=True)\nprint(compiled(x))\n")
    else:
        out.append("\ncompiled = torch.compile(model)\nprint(compiled(x))\n")
    return "".join(out)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--out", default=os.path.join(HERE, "reproducers_models"))
    ap.add_argument("--size", type=int, default=64)
    ap.add_argument("--batch", type=int, default=2)
    ap.add_argument("--models", default=",".join(MODELS))
    ap.add_argument("--variants", default=",".join(VARIANTS))
    a = ap.parse_args()
    os.makedirs(a.out, exist_ok=True)
    try:
        import torchvision
        tv_note = torchvision.__version__
    except Exception:  # noqa: BLE001
        tv_note = "(version unknown)"
    n = 0
    for key in a.models.split(","):
        ctor = MODELS[key]
        for variant in a.variants.split(","):
            if key in ("vit_small", "swin_small") and variant == "channels_last":
                continue   # not a conv net
            src = HEADER.format(model=key, variant=variant, tv_note=tv_note, batch=a.batch, size=a.size)
            src += body(key, ctor, variant, a.batch, a.size)
            path = os.path.join(a.out, f"model_{key}_{variant}.py")
            with open(path, "w", encoding="utf-8") as fh:
                fh.write(src)
            n += 1
    for name, src in OPS_FILES.items():
        with open(os.path.join(a.out, f"{name}.py"), "w", encoding="utf-8") as fh:
            fh.write(src)
        n += 1
    print(f"wrote {n} reproducer files to {a.out}")


if __name__ == "__main__":
    main()
