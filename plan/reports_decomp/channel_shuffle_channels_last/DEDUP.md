# Deduplication — channel_shuffle drops the channels_last layout under Inductor

Found 2026-09-10 by the FakeTensor-vs-real stride differential (`run.py decomp`, variant `channels_last`, seed 1),
confirmed with `minimal_verified.py` on 2.14.0+cpu: `F.channel_shuffle(x_channels_last, 2)` — eager and
aot_eager return channels_last strides `(384, 1, 48, 6)`, Inductor returns contiguous `(384, 64, 8, 1)`.
`torch.native_channel_shuffle` identical; `group_norm` on the same input keeps channels_last under Inductor.

Tracker (search API, 2026-09-10): no report for channel_shuffle. The *family* "output memory format not preserved
under compile" has several accepted fixes: #187195 (max_unpool2d decomposition, merged), #179830
(upsample_nearest3d stride mismatch), #179837 (reflection/replication pad), #192681 (open, native_batch_norm fake
strides on CPU). So the project treats these as bugs.

Decision: **candidate (low severity)** — same family as the fixed reports above, new op. Pending user review.
