# Deduplication — aoti_compile_and_package cannot serialize `torch.return_types.*` outputs

Found 2026-09-10 by the export/AOTI differential (`run.py aoti`): 11 OpInfo operators (max/min with dim, topk,
kthvalue, cummax, cummin, aminmax, frexp, geqrf, lu_unpack, nanmedian) export and compile fine but
`aoti_compile_and_package` raises `NotImplementedError: No registered serialization name for
<class 'torch.return_types.max'> found. Please update your _register_pytree_node call with a serialized_type_name
kwarg`. Returning the unpacked tuple works (`minimal_verified.py`).

Tracker (search API, 2026-09-10): no issue for "aoti_compile_and_package return_types" / "No registered
serialization name for return_types" / "AOTInductor namedtuple output topk max". Related open PR #113258
"[pytree] support PyStructSequence types for Python pytree" (2023, still open) — the general pytree support for
`torch.return_types`; it does not mention export/AOTI serialization.

Decision: **candidate (low–medium, usability)** — a model that returns `torch.max(x, dim)` as-is cannot be
packaged; the message points at an internal registration call the user cannot act on. Either register a
`serialized_type_name` for the structseq types or unpack them in export. Pending user review.
