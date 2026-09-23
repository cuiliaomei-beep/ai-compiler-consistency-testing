# Seed import report

- corpus incidents with code: **1463**
- accepted as runnable cases: **9**

## Outcome breakdown

| outcome | n |
|---|---:|
| skip: not a github issue | 1054 |
| skip: project not whitelisted | 251 |
| reject: does not reference torch | 55 |
| reject: requires a GPU | 45 |
| reject: no tensor constructor to build inputs from | 18 |
| reject: contains a forbidden process/network/filesystem pattern | 13 |
| ACCEPTED | 9 |
| reject: does not run | 7 |
| reject: compile target `model` is not defined in the snippet | 4 |
| reject: could not determine the call arguments | 3 |
| reject: no function definition and no torch.compile target | 2 |
| reject: unparseable: unexpected indent (<unknown>, line 10) | 1 |
| reject: unparseable: unmatched '}' (<unknown>, line 11) | 1 |

## Accepted

| incident | project | fn | params | contexts |
|---|---|---|---:|---:|
| TC-2026-01109 | pytorch/pytorch | `f` | 1 | 4 |
| TC-2026-01120 | pytorch/pytorch | `fn` | 1 | 4 |
| TC-2026-01131 | pytorch/pytorch | `fn` | 1 | 4 |
| TC-2026-01137 | pytorch/pytorch | `g` | 1 | 4 |
| TC-2026-01148 | pytorch/pytorch | `fn` | 1 | 4 |
| TC-2026-01161 | pytorch/pytorch | `f` | 1 | 4 |
| TC-2026-01170 | pytorch/pytorch | `function` | 2 | 4 |
| TC-2026-01179 | pytorch/pytorch | `foo` | 2 | 4 |
| TC-2026-01230 | pytorch/pytorch | `func` | 1 | 4 |

## Rejected (reached extraction, then failed)

| incident | project | reason |
|---|---|---|
| TC-2026-01108 | pytorch/pytorch | does not reference torch |
| TC-2026-01112 | pytorch/pytorch | argument eval failed: NameError: name 'x1_inner' is not defined |
| TC-2026-01113 | pytorch/pytorch | requires a GPU |
| TC-2026-01114 | pytorch/pytorch | no tensor constructor to build inputs from |
| TC-2026-01115 | pytorch/pytorch | requires a GPU |
| TC-2026-01116 | pytorch/pytorch | no function definition and no torch.compile target |
| TC-2026-01117 | pytorch/pytorch | requires a GPU |
| TC-2026-01118 | pytorch/pytorch | requires a GPU |
| TC-2026-01119 | pytorch/pytorch | requires a GPU |
| TC-2026-01121 | pytorch/pytorch | requires a GPU |
| TC-2026-01122 | pytorch/pytorch | argument eval failed: ModuleNotFoundError: No module named 'torch.hpu' |
| TC-2026-01123 | pytorch/pytorch | no tensor constructor to build inputs from |
| TC-2026-01125 | pytorch/pytorch | no tensor constructor to build inputs from |
| TC-2026-01126 | pytorch/pytorch | requires a GPU |
| TC-2026-01127 | pytorch/pytorch | compile target `model` is not defined in the snippet |
| TC-2026-01128 | pytorch/pytorch | requires a GPU |
| TC-2026-01129 | pytorch/pytorch | requires a GPU |
| TC-2026-01130 | pytorch/pytorch | no tensor constructor to build inputs from |
| TC-2026-01134 | pytorch/pytorch | requires a GPU |
| TC-2026-01135 | pytorch/pytorch | requires a GPU |
| TC-2026-01136 | pytorch/pytorch | prelude/fn failed: ModuleNotFoundError: No module named 'torch.distributed._composable.fsdp._fsdp_param' |
| TC-2026-01138 | pytorch/pytorch | requires a GPU |
| TC-2026-01139 | pytorch/pytorch | requires a GPU |
| TC-2026-01142 | pytorch/pytorch | requires a GPU |
| TC-2026-01143 | pytorch/pytorch | requires a GPU |
| TC-2026-01144 | pytorch/pytorch | no tensor constructor to build inputs from |
| TC-2026-01145 | pytorch/pytorch | compile target `model` is not defined in the snippet |
| TC-2026-01146 | pytorch/pytorch | argument eval failed: NameError: name 'x' is not defined |
| TC-2026-01147 | pytorch/pytorch | unparseable: unexpected indent (<unknown>, line 10) |
| TC-2026-01149 | pytorch/pytorch | does not reference torch |
| TC-2026-01150 | pytorch/pytorch | requires a GPU |
| TC-2026-01151 | pytorch/pytorch | requires a GPU |
| TC-2026-01152 | pytorch/pytorch | requires a GPU |
| TC-2026-01153 | pytorch/pytorch | requires a GPU |
| TC-2026-01154 | pytorch/pytorch | could not determine the call arguments |
| TC-2026-01155 | pytorch/pytorch | contains a forbidden process/network/filesystem pattern |
| TC-2026-01157 | pytorch/pytorch | requires a GPU |
| TC-2026-01158 | pytorch/pytorch | no tensor constructor to build inputs from |
| TC-2026-01159 | pytorch/pytorch | contains a forbidden process/network/filesystem pattern |
| TC-2026-01160 | pytorch/pytorch | requires a GPU |
| TC-2026-01162 | pytorch/pytorch | requires a GPU |
| TC-2026-01163 | pytorch/pytorch | contains a forbidden process/network/filesystem pattern |
| TC-2026-01164 | pytorch/pytorch | compile target `model` is not defined in the snippet |
| TC-2026-01165 | pytorch/pytorch | requires a GPU |
| TC-2026-01166 | pytorch/pytorch | argument eval failed: NameError: name 'N' is not defined |
| TC-2026-01167 | pytorch/pytorch | compile target `model` is not defined in the snippet |
| TC-2026-01169 | pytorch/pytorch | no tensor constructor to build inputs from |
| TC-2026-01171 | pytorch/pytorch | requires a GPU |
| TC-2026-01173 | pytorch/pytorch | requires a GPU |
| TC-2026-01174 | pytorch/pytorch | requires a GPU |
| TC-2026-01175 | pytorch/pytorch | no tensor constructor to build inputs from |
| TC-2026-01178 | pytorch/pytorch | no tensor constructor to build inputs from |
| TC-2026-01180 | pytorch/pytorch | no tensor constructor to build inputs from |
| TC-2026-01181 | pytorch/pytorch | requires a GPU |
| TC-2026-01182 | pytorch/pytorch | requires a GPU |
| TC-2026-01184 | pytorch/pytorch | no tensor constructor to build inputs from |
| TC-2026-01185 | pytorch/pytorch | no tensor constructor to build inputs from |
| TC-2026-01186 | pytorch/pytorch | does not reference torch |
| TC-2026-01189 | pytorch/pytorch | does not reference torch |
| TC-2026-01191 | pytorch/pytorch | requires a GPU |
| TC-2026-01192 | pytorch/pytorch | does not reference torch |
| TC-2026-01194 | pytorch/pytorch | requires a GPU |
| TC-2026-01195 | pytorch/pytorch | no function definition and no torch.compile target |
| TC-2026-01196 | pytorch/pytorch | no tensor constructor to build inputs from |
| TC-2026-01197 | pytorch/pytorch | requires a GPU |
| TC-2026-01198 | pytorch/pytorch | requires a GPU |
| TC-2026-01199 | pytorch/pytorch | requires a GPU |
| TC-2026-01200 | pytorch/pytorch | no tensor constructor to build inputs from |
| TC-2026-01202 | pytorch/pytorch | contains a forbidden process/network/filesystem pattern |
| TC-2026-01204 | pytorch/pytorch | does not reference torch |
| TC-2026-01205 | pytorch/pytorch | contains a forbidden process/network/filesystem pattern |
| TC-2026-01206 | pytorch/pytorch | does not reference torch |
| TC-2026-01207 | pytorch/pytorch | requires a GPU |
| TC-2026-01208 | pytorch/pytorch | no tensor constructor to build inputs from |
| TC-2026-01209 | pytorch/pytorch | does not reference torch |
| TC-2026-01210 | pytorch/pytorch | requires a GPU |
| TC-2026-01211 | pytorch/pytorch | requires a GPU |
| TC-2026-01212 | pytorch/pytorch | argument eval failed: NameError: name 'N' is not defined |
| TC-2026-01213 | pytorch/pytorch | requires a GPU |
| TC-2026-01214 | pytorch/pytorch | does not reference torch |
