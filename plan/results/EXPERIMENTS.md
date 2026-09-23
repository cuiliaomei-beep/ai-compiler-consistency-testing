# Experiments A-E

backend eager, budget 12

## Experiment A: Shape boundary: who reaches k-1 / k / k+1 first?

```json
{
 "question": "x.shape[0] >= 32: tests to trigger a fault at 31 / 32 / 33-tail",
 "codegen_boundary_31": {
  "ours": {
   "detected": true,
   "tests_to_detect": 9,
   "tests": 9,
   "stage": "inductor_codegen",
   "kinds": [
    "value"
   ],
   "probe": "layered",
   "ttf_s": 2.3597936000005575
  },
  "random": {
   "detected": "0/5",
   "mean_tests_to_detect": null,
   "runs": [
    {
     "detected": false,
     "tests_to_detect": null,
     "tests": 9,
     "stage": null,
     "kinds": [],
     "probe": null,
     "ttf_s": null
    },
    {
     "detected": false,
     "tests_to_detect": null,
     "tests": 8,
     "stage": null,
     "kinds": [],
     "probe": null,
     "ttf_s": null
    },
    {
     "detected": false,
     "tests_to_detect": null,
     "tests": 9,
     "stage": null,
     "kinds": [],
     "probe": null,
     "ttf_s": null
    },
    {
     "detected": false,
     "tests_to_detect": null,
     "tests": 11,
     "stage": null,
     "kinds": [],
     "probe": null,
     "ttf_s": null
    },
    {
     "detected": false,
     "tests_to_detect": null,
     "tests": 9,
     "stage": null,
     "kinds": [],
     "probe": null,
     "ttf_s": null
    }
   ]
  }
 },
 "codegen_boundary_32": {
  "ours": {
   "detected": true,
   "tests_to_detect": 1,
   "tests": 1,
   "stage": "inductor_codegen",
   "kinds": [
    "value"
   ],
   "probe": "layered",
   "ttf_s": 0.07331400000839494
  },
  "random": {
   "detected": "5/5",
   "mean_tests_to_detect": 1.0,
   "runs": [
    {
     "detected": true,
     "tests_to_detect": 1,
     "tests": 1,
     "stage": "inductor_codegen",
     "kinds": [
      "value"
     ],
     "probe": "layered",
     "ttf_s": 0.07429489999776706
    },
    {
     "detected": true,
     "tests_to_detect": 1,
     "tests": 1,
     "stage": "inductor_codegen",
     "kinds": [
      "value"
     ],
     "probe": "layered",
     "ttf_s": 0.07166159999906085
    },
    {
     "detected": true,
     "tests_to_detect": 1,
     "tests": 1,
     "stage": "inductor_codegen",
     "kinds": [
      "value"
     ],
     "probe": "layered",
     "ttf_s": 0.07199530000798404
    },
    {
     "detected": true,
     "tests_to_detect": 1,
     "tests": 1,
     "stage": "inductor_codegen",
     "kinds": [
      "value"
     ],
     "probe": "layered",
     "ttf_s": 0.07164489998831414
    },
    {
     "detected": true,
     "tests_to_detect": 1,
     "tests": 1,
     "stage": "inductor_codegen",
     "kinds": [
      "value"
     ],
     "probe": "layered",
     "ttf_s": 0.07619580000755377
    }
   ]
  }
 },
 "codegen_mod16_tail": {
  "ours": {
   "detected": false,
   "tests_to_detect": null,
   "tests": 12,
   "stage": null,
   "kinds": [],
   "probe": null,
   "ttf_s": null
  },
  "random": {
   "detected": "3/5",
   "mean_tests_to_detect": 3.3,
   "runs": [
    {
     "detected": true,
     "tests_to_detect": 3,
     "tests": 3,
     "stage": "inductor_codegen",
     "kinds": [
      "value"
     ],
     "probe": "layered",
     "ttf_s": 0.1639569999970263
    },
    {
     "detected": false,
     "tests_to_detect": null,
     "tests": 8,
     "stage": null,
     "kinds": [],
     "probe": null,
     "ttf_s": null
    },
    {
     "detected": true,
     "tests_to_detect": 5,
     "tests": 5,
     "stage": "inductor_codegen",
     "kinds": [
      "value"
     ],
     "probe": "layered",
     "ttf_s": 0.2658995999954641
    },
    {
     "detected": true,
     "tests_to_detect": 2,
     "tests": 2,
     "stage": "inductor_codegen",
     "kinds": [
      "value"
     ],
     "probe": "layered",
     "ttf_s": 0.11777830000210088
    },
    {
     "detected": false,
     "tests_to_detect": null,
     "tests": 9,
     "stage": null,
     "kinds": [],
     "probe": null,
     "ttf_s": null
    }
   ]
  }
 },
 "wall_s": 7.5
}
```

## Experiment B: dtype specialization: cold vs warm on the same program.

```json
{
 "question": "float16 <-> float32 with everything else fixed: cold vs warm",
 "cold_only": {
  "detected": false,
  "tests_to_detect": null,
  "tests": 7,
  "stage": null,
  "kinds": [],
  "probe": null,
  "ttf_s": null
 },
 "cold_plus_warm": {
  "detected": true,
  "tests_to_detect": 4,
  "tests": 4,
  "stage": "specialization_cache",
  "kinds": [
   "value"
  ],
  "probe": "matrix",
  "ttf_s": 0.49551140000403393
 },
 "return_trip": {
  "detected": true,
  "tests_to_detect": 3,
  "tests": 3,
  "stage": "cache_invalidation",
  "kinds": [
   "value"
  ],
  "probe": "matrix",
  "ttf_s": 0.43255759999738075
 },
 "wall_s": 1.6
}
```

## Experiment C: Control flow: is the T/T, T/F, F/T, F/F table covered?

```json
{
 "question": "flag and x.shape[0] > 32: which of T/T, T/F, F/T, F/F are executed",
 "ours": [
  "F/F",
  "F/T",
  "T/F",
  "T/T"
 ],
 "ours_contexts": [
  "base",
  "x.dim0=32",
  "flag=True",
  "dtype=float16",
  "x.grad=True",
  "compile.dynamic=True",
  "x.dim0=33",
  "flag=False",
  "flag=True+x.dim0=32",
  "flag=True+x.dim0=33",
  "flag=False+x.dim0=32",
  "flag=False+x.dim0=33"
 ],
 "random": [
  "T/F"
 ],
 "complete": true,
 "wall_s": 0.0
}
```

## Experiment D: Alias / mutation: output-only oracle vs mutation/alias oracle.

```json
{
 "question": "same tests, output-only oracle vs mutation/alias oracle",
 "functionalize_drop_mutation/view_inplace": {
  "output_only": {
   "detected": false,
   "tests_to_detect": null,
   "tests": 7,
   "stage": null,
   "kinds": [],
   "probe": null,
   "ttf_s": null
  },
  "mutation_alias": {
   "detected": true,
   "tests_to_detect": 1,
   "tests": 1,
   "stage": "inductor_codegen",
   "kinds": [
    "mutation",
    "alias"
   ],
   "probe": "layered",
   "ttf_s": 0.07040260000212584
  }
 },
 "functionalize_drop_mutation/overlapping_views": {
  "output_only": {
   "detected": false,
   "tests_to_detect": null,
   "tests": 7,
   "stage": null,
   "kinds": [],
   "probe": null,
   "ttf_s": null
  },
  "mutation_alias": {
   "detected": true,
   "tests_to_detect": 1,
   "tests": 1,
   "stage": "inductor_codegen",
   "kinds": [
    "mutation",
    "alias"
   ],
   "probe": "layered",
   "ttf_s": 0.07307540001056623
  }
 },
 "functionalize_alias_to_copy/alias_returned": {
  "output_only": {
   "detected": false,
   "tests_to_detect": null,
   "tests": 9,
   "stage": null,
   "kinds": [],
   "probe": null,
   "ttf_s": null
  },
  "mutation_alias": {
   "detected": true,
   "tests_to_detect": 1,
   "tests": 1,
   "stage": "inductor_codegen",
   "kinds": [
    "alias"
   ],
   "probe": "layered",
   "ttf_s": 0.0687362999888137
  }
 },
 "functionalize_drop_mutation/noncontig_copy": {
  "output_only": {
   "detected": false,
   "tests_to_detect": null,
   "tests": 8,
   "stage": null,
   "kinds": [],
   "probe": null,
   "ttf_s": null
  },
  "mutation_alias": {
   "detected": true,
   "tests_to_detect": 1,
   "tests": 1,
   "stage": "inductor_codegen",
   "kinds": [
    "mutation",
    "alias"
   ],
   "probe": "layered",
   "ttf_s": 0.06570400000782683
  }
 },
 "wall_s": 2.2
}
```

## Experiment E: Cache context switch: A -> B versus reset -> B.

```json
{
 "question": "compile(A) -> B  vs  reset -> B; if different, localise cache/guard behaviour",
 "rows": [
  {
   "compiler": "real",
   "A->B differs from reset->B": false,
   "recompiled": true,
   "eager_vs_cold": false,
   "eager_vs_warm": false,
   "A->B->A differs": false,
   "verdict": "none"
  },
  {
   "compiler": "underspec_dtype",
   "A->B differs from reset->B": true,
   "recompiled": false,
   "eager_vs_cold": false,
   "eager_vs_warm": true,
   "A->B->A differs": false,
   "verdict": "specialization_cache"
  },
  {
   "compiler": "cache_stale_on_return",
   "A->B differs from reset->B": false,
   "recompiled": true,
   "eager_vs_cold": false,
   "eager_vs_warm": false,
   "A->B->A differs": true,
   "verdict": "cache_invalidation"
  },
  {
   "compiler": "cache_result_memo",
   "A->B differs from reset->B": true,
   "recompiled": false,
   "eager_vs_cold": false,
   "eager_vs_warm": true,
   "A->B->A differs": false,
   "verdict": "specialization_cache"
  }
 ],
 "wall_s": 0.5
}
```
