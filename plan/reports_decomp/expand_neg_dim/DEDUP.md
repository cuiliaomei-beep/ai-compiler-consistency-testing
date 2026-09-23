# Deduplication — `expand(-1, …)` on a 0-d tensor returns a tensor with a negative shape (eager bug)

Found 2026-09-10 by the FakeTensor-vs-real differential (`run.py decomp`, variant `zero_dim`, seed 1): the fake
path raises "Trying to create tensor with negative dimension -1: [-1, 5, 5]" while eager returns normally.
`minimal_verified.py`: eager `torch.tensor(1.5).expand(-1, 5, 5)` has shape `(-1, 5, 5)`, `numel() == -25`;
`clone()` on it raises; the 1-d input raises the proper "expanded size (-1) isn't allowed in a leading,
non-existing dimension" error. So the check in `inferExpandGeometry` is skipped when the source has 0 dims.

Tracker (search API, 2026-09-10): nothing for "expand -1 scalar tensor negative shape" / "expand zero-dim -1
leading dimension".

Decision: **eager-side candidate**, not a compile issue (compile is the correct side). Pending user review; if
filed it goes as a plain `module: tensor creation` bug.
