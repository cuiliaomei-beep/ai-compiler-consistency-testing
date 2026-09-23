"""torch.compile and the python `random` module: two silent divergences from eager (torch 2.14.0 / nightly).

(1) random.shuffle / random.sample inside a compiled function return the SAME result on every call
    (eager advances the global RNG).
(2) random.seed(k) inside a compiled function is not honoured on the first (compiling) call: the first call
    returns a value from a different RNG state, later calls are correct.
"""
import random
import torch

print("torch", torch.__version__)


def shuffle_fn(x):
    lst = [1, 2, 3, 4, 5]
    random.shuffle(lst)
    return x + lst[0], lst


def sample_fn(x):
    s = random.sample(range(100), 2)
    return x + s[0], s


def seed_fn(x):
    random.seed(0)
    return x + random.random(), random.random(), random.randint(0, 100)


for name, fn in [("shuffle", shuffle_fn), ("sample", sample_fn)]:
    for backend in ("eager", "inductor"):
        torch._dynamo.reset()
        cf = torch.compile(fn, backend=backend)
        random.seed(7); e = [fn(torch.zeros(1))[1] for _ in range(3)]
        random.seed(7); c = [cf(torch.zeros(1))[1] for _ in range(3)]
        print(f"[{name} {backend}] eager   : {e}\n{' ' * (len(name) + len(backend) + 4)}compiled: {c}   {'DIFF' if e != c else 'same'}")

for backend in ("eager", "inductor"):
    torch._dynamo.reset()
    cf = torch.compile(seed_fn, backend=backend)
    e = [seed_fn(torch.zeros(1))[1:] for _ in range(3)]
    c = [cf(torch.zeros(1))[1:] for _ in range(3)]
    print(f"[seed-inside {backend}] eager   : {e}\n{' ' * (len(backend) + 14)}compiled: {c}   {'DIFF' if e != c else 'same'}")
