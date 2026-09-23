"""Fetch only the log of a Kaggle kernel session (no output files): python kaggle/kernel_log.py <owner/slug> <out.log>

The CLI writes the log only after listing and downloading every output file, which fails on flaky links; the
log itself comes with the first page of the session-output listing.
"""
import sys
import time

from kaggle.api.kaggle_api_extended import KaggleApi
from kagglesdk.kernels.types.kernels_api_service import ApiListKernelSessionOutputRequest

ref, out = sys.argv[1], sys.argv[2]
owner, slug = ref.split("/")
api = KaggleApi()
api.authenticate()
for attempt in range(8):
    try:
        with api.build_kaggle_client() as kaggle:
            req = ApiListKernelSessionOutputRequest()
            req.user_name, req.kernel_slug, req.page_size = owner, slug, 1
            resp = kaggle.kernels.kernels_api_client.list_kernel_session_output(req)
        with open(out, "w", encoding="utf-8") as fh:
            fh.write(resp.log or "")
        print(f"log written to {out} ({len(resp.log or '')} bytes)")
        break
    except Exception as e:  # noqa: BLE001
        print(f"attempt {attempt + 1} failed: {str(e)[:100]}")
        time.sleep(15)
