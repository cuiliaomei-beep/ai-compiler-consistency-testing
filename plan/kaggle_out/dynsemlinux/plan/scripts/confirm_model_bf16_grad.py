"""reports_models/61eda009bc8f: FCN-like model, bf16 autocast, gradient differs eager vs compiled by 1.32 (bf16, no fp64 ref).
Which side is right? Compare both bf16 gradients against the fp32 (no autocast) eager gradient of the same model."""
import os
import sys

HERE = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, HERE)
from tcc.compat import ensure_msvc_env  # noqa: E402

ensure_msvc_env()
import torch  # noqa: E402
import torchvision  # noqa: E402

torch.manual_seed(0)


class SegNet(torch.nn.Module):
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


model = SegNet().eval()
x0 = torch.randn(1, 3, 4, 64)
w = torch.randn(1, 5, 4, 64)      # fixed output weights for the scalar loss


LOSS = os.environ.get("LOSS", "weighted")


def grad_of(fn, dtype_note):
    x = x0.clone().requires_grad_(True)
    y = fn(x)
    if LOSS == "sum":
        y.sum().backward()                 # the campaign's O6 loss: plain sum in the output dtype
    else:
        (y.float() * w).sum().backward()
    return x.grad.detach().clone()


def f_bf16(x):
    with torch.autocast("cpu", dtype=torch.bfloat16):
        return model(x)


g_fp32 = grad_of(model, "fp32")                       # truth: fp32, no autocast
g_eager = grad_of(f_bf16, "eager bf16")
torch._dynamo.reset()
cf = torch.compile(f_bf16)
g_comp = grad_of(cf, "compiled bf16")
print(torch.__version__)
print("|eager_bf16 - fp32|    max:", (g_eager - g_fp32).abs().max().item(), " mean:", (g_eager - g_fp32).abs().mean().item())
print("|compiled_bf16 - fp32| max:", (g_comp - g_fp32).abs().max().item(), " mean:", (g_comp - g_fp32).abs().mean().item())
print("|eager_bf16 - compiled| max:", (g_eager - g_comp).abs().max().item())
print("fp32 grad scale        max:", g_fp32.abs().max().item())
# same for the forward output
with torch.no_grad():
    y32 = model(x0); ye = f_bf16(x0); yc = cf(x0)
print("forward |eager_bf16-fp32|:", (ye.float() - y32).abs().max().item(), " |compiled_bf16-fp32|:", (yc.float() - y32).abs().max().item())
