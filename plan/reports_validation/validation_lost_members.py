import torch, torch.nn.functional as F

I = lambda *v: torch.tensor(v)
cases = {
    "index_add, source shape mismatch":   (lambda x, i, s: torch.index_add(x, 0, i, s), (torch.zeros(3, 2), I(0, 2), torch.tensor([3., 4.]))),
    "index_copy, negative index":         (lambda x, i, s: torch.index_copy(x, 0, i, s), (torch.zeros(4, 3), I(-1), torch.ones(1, 3))),
    "binary_cross_entropy, input > 1":    (lambda x, t: F.binary_cross_entropy(x, t), (torch.tensor([1.5, 0.2]), torch.tensor([1., 0.]))),
    "repeat_interleave, wrong output_size": (lambda x, r: torch.repeat_interleave(x, r, output_size=9), (torch.arange(3.), I(1, 2, 3))),
    "softmax on int64":                   (lambda x: torch.softmax(x, 0), (I(1, 2, 3),)),
    "layer_norm, float64 weight":         (lambda x, w: F.layer_norm(x, (3,), w), (torch.arange(6.).reshape(2, 3), torch.ones(3, dtype=torch.float64))),
    "one_hot on float":                   (lambda x: F.one_hot(x, 5), (torch.tensor([0.5, 1.5, 2.5]),)),
    "int64.mul_(float tensor)":           (lambda x, y: x.mul_(y), (I(1, 2, 3), torch.tensor([.5, .5, .5]))),
    "float.add_(1j)":                     (lambda x: x.add_(1j), (torch.ones(3),)),
    "take(out= overlapping input)":       (lambda x: torch.take(x, I(1, 2), out=x[:2]), (torch.arange(3),)),
}
for name, (fn, args) in cases.items():
    row = []
    for backend in (None, "aot_eager", "inductor"):
        torch._dynamo.reset()
        g = fn if backend is None else torch.compile(fn, backend=backend)
        try:
            out = g(*[a.clone() for a in args])
            row.append(f"returns {out.flatten()[:4].tolist()}")
        except Exception as e:
            row.append(f"raises {type(e).__name__}")
    print(f"{name:38s} eager: {row[0]:22s} aot_eager: {row[1]:34s} inductor: {row[2]}")
