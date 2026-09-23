import os, sys
sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
try:
    from tcc.compat import ensure_msvc_env; ensure_msvc_env()
except Exception:
    pass
import torch
print("torch", torch.__version__)

def scale(x, temperature):            # temperature = 1.0 is the usual default
    return x / temperature
def ema_start(avg, decay):            # decay = 1.0 -> "keep the old average"
    return avg * decay
def residual(x, bias):                # bias = 0 disables the term
    return x + bias
class Net(torch.nn.Module):
    def __init__(self, t=1.0):
        super().__init__(); self.t = t
    def forward(self, logits):
        return logits / self.t

def check(name, f, args, dev="cpu", grad=False):
    out = []
    for backend in (None, "aot_eager", "inductor"):
        torch._dynamo.reset()
        x = torch.arange(1.0, 5.0, device=dev).requires_grad_(grad)
        g = f if backend is None else torch.compile(f, backend=backend)
        y = g(x, *args)
        ident, shares = y is x, y.data_ptr() == x.data_ptr()
        with torch.no_grad():
            y.detach().mul_(2)
        out.append(f"{'eager' if backend is None else backend}: y is x={ident} x={x.detach().tolist()}")
    print(f"{name:34s}", " | ".join(out))

check("x / temperature   (1.0)", scale, (1.0,))
check("avg * decay       (1.0)", ema_start, (1.0,))
check("x + bias          (0)", residual, (0,))
check("x + bias          (0.0 tensor)", residual, (torch.zeros(()),))
check("nn.Module logits / self.t (1.0)", lambda x: Net()(x), ())
check("x / temperature   requires_grad", scale, (1.0,), grad=True)
check("x * 1 under no_grad param", lambda x: x * 1, (), grad=True)
if torch.cuda.is_available():
    check("x / temperature   (1.0) cuda", scale, (1.0,), dev="cuda")
    check("x + 0 cuda", lambda x: x + 0, (), dev="cuda")

# downstream effect: a training-style loop that updates the returned buffer in place
torch._dynamo.reset()
def step(buf, momentum):
    return buf * momentum
for comp in (False, True):
    torch._dynamo.reset()
    g = torch.compile(step) if comp else step
    history = torch.ones(3)
    new = g(history, 1.0)
    new.add_(5)                        # update the *new* buffer
    print("compiled" if comp else "eager   ", "history after updating the new buffer:", history.tolist())
