"""One-off (2026-09-23): give the Numba (06) and JAX (11) drafts the same three-sentence **Summary.** paragraph as every other issue draft."""
import glob
import os

ISSUES = os.path.join(os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__)))), "0920issues")

NEW = {
    "06": ("The NumPy ufuncs `np.remainder`",
           "**Summary.** For signed integer arrays that contain the pair `(iinfo(dtype).min, -1)`, NumPy's `np.remainder`, `np.mod`, and `np.divmod` return `0`, while the same "
           "ufuncs inside an `@njit` function terminate the interpreter: there is no Python exception, the process exits with status `0xC0000095` (integer overflow) on Windows and is "
           "killed by `SIGFPE`, the hardware trap of `idiv`, on Linux (Numba 0.67.0). A single such element in the data takes down the whole process, a server or a notebook kernel "
           "included, and `try/except` cannot catch it. Because the Python operator `%` and `np.floor_divide` inside the same jitted function return `0`, only the ufunc remainder path "
           "lacks the guard for this operand pair, and all four signed dtypes, int8 and int16 included, are affected."),
    "11": ("`jnp.gcd(x1, x2)` and `jnp.lcm(x1, x2)` do not return",
           "**Summary.** When one argument is the most negative value of a signed integer dtype and the other is non-zero, `np.gcd` and `np.lcm` return immediately, while `jnp.gcd(x1, x2)` "
           "and `jnp.lcm(x1, x2)` never return, both op-by-op and under `jax.jit` (jax 0.11.2, CPU, Windows and Linux). The call cannot be interrupted from Python, so a single such element "
           "in an array hangs the whole process. Because `abs(INT_MIN)` is still negative, the Euclidean `while_loop` starts from a negative value and its final ordering step keeps "
           "swapping the same two numbers, so every signed dtype is affected for every non-zero partner, in either argument position."),
}
for num, (anchor, text) in NEW.items():
    p = glob.glob(os.path.join(ISSUES, num + "-*.md"))[0]
    s = open(p, encoding="utf-8").read()
    if "**Summary.**" in s:
        continue
    i = s.index(anchor)
    j = s.index("\n\n", i)
    s = s[:i] + text + s[j:]
    open(p, "w", encoding="utf-8").write(s)
    print("updated", os.path.basename(p))
