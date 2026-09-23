# Run summary

- **torch**: 2.14.0+cpu
- **device**: cpu
- **backend**: inductor
- **cases**: 9
- **candidates**: 21
- **submittable**: 11
- **unique signatures**: 21
- **elapsed**: 185.0s

## Candidates by priority

### high (11)

| signature | case | stage | probe | factor | oracles |
|---|---|---|---|---|---|
| `d3ff9deca070` | seed_2026_01137 | specialization_cache | warm | dtype | value |
| `50ccbd5988ca` | seed_2026_01137 | specialization_cache | warm | variant | value |
| `ec673a6440cd` | seed_2026_01148 | aot_functionalization | layered | - | value |
| `2b48a3e59889` | seed_2026_01148 | aot_functionalization | layered | - | value |
| `3d4c9e2434f7` | seed_2026_01148 | aot_functionalization | layered | - | value |
| `ecd6d12d224a` | seed_2026_01148 | aot_functionalization | layered | - | value |
| `b4fa94e7721e` | seed_2026_01161 | aot_functionalization | layered | - | value |
| `0eade94502e7` | seed_2026_01161 | aot_functionalization | layered | - | value |
| `b8fcaeced779` | seed_2026_01161 | aot_functionalization | layered | - | value |
| `54bfa0c4ba5b` | seed_2026_01161 | aot_functionalization | layered | - | value |
| `9f38ac7d7e93` | seed_2026_01170 | specialization_cache | warm | dtype | exception |

### low (4)

| signature | case | stage | probe | factor | oracles |
|---|---|---|---|---|---|
| `b31330804821` | seed_2026_01137 | dynamo_capture | layered | - | value |
| `510b8c8def34` | seed_2026_01137 | dynamo_capture | layered | - | value |
| `a165a1f5a6f6` | seed_2026_01137 | dynamo_capture | layered | - | value |
| `e1a9c82a93cc` | seed_2026_01137 | dynamo_capture | layered | - | value |

### info (6)

| signature | case | stage | probe | factor | oracles |
|---|---|---|---|---|---|
| `3e0d521abb47` | seed_2026_01109 | none | warm | variant | - |
| `d0b687823099` | seed_2026_01148 | none | warm | dtype | - |
| `7b7c64e52bfc` | seed_2026_01161 | none | warm | dtype | - |
| `b1427e80373d` | seed_2026_01161 | none | warm | variant | - |
| `069947b7bbfc` | seed_2026_01179 | none | warm | dtype | - |
| `efa62b00f8de` | seed_2026_01230 | none | warm | variant | - |

