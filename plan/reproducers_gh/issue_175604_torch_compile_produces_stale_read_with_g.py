# source: https://github.com/pytorch/pytorch/issues/175604
# title: torch.compile produces stale read with generator over mutated list
# state: closed  created: 2026-02-24
# mined automatically; the harness records the torch.compile target and its first call

class M(nn.Module):
    def forward(self, x):
        lst = [torch.tensor(-1.)]
        g = (v for v in lst)      # generator captures list reference
        lst[0] = x.mean() + 1     # mutation after generator creation
        val = next(g)             # deferred read
        # if val < 0:
            # raise RuntimeError("stale read")
        return val

m = M()
x = torch.randn(4)

print("eager:", m(x))

cm = torch.compile(m)
print("compiled:", cm(x))
