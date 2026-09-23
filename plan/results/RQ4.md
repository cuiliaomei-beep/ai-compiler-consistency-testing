# RQ4 cache / specialization

| setting | known cache bugs detected | warm-only failures | mean tests-to-trigger | tests |
|---|---:|---:|---:|---:|
| ordinary_eager_vs_compiled | 0/6 | 0 | None | 148 |
| random_sequence | 5/6 | 11 | 6.45 | 155 |
| scs_guided_sequence | 6/6 | 17 | 4.76 | 93 |

## recompile / cache behaviour of the real compiler (section 15 switch table)

| program | A | B | factor | recompile A->B | recompile B->A | cold vs warm | A->B->A | verdict |
|---|---|---|---|---|---|---|---|---|
| dtype_reduce | base | dtype=float16 | dtype | True | False | False | False | none |
| dtype_reduce | base | x.grad=True | requires_grad | True | False | False | False | none |
| dtype_reduce | base | dtype=float64 | dtype | True | False | False | False | none |
| dtype_reduce | base | x.grad=False | requires_grad | False | False | False | False | none |
| dtype_reduce | base | dtype=bfloat16 | dtype | True | False | False | False | none |
| python_flag_semantic | base | use_relu=True | substitute | False | False | False | False | none |
| python_flag_semantic | base | dtype=float16 | dtype | True | False | False | False | none |
| python_flag_semantic | base | x.grad=True | requires_grad | True | False | False | False | none |
| python_flag_semantic | base | use_relu=False | substitute | True | False | False | False | none |
| python_flag_semantic | base | dtype=float64 | dtype | True | False | False | False | none |
| python_flag_semantic | base | x.grad=False | requires_grad | False | False | False | False | none |
| requires_grad_switch | base | dtype=float16 | dtype | True | False | False | False | none |
| requires_grad_switch | base | x.grad=True | requires_grad | False | False | False | False | none |
| requires_grad_switch | base | dtype=float64 | dtype | True | False | False | False | none |
| requires_grad_switch | base | x.grad=False | requires_grad | True | False | False | False | none |
| requires_grad_switch | base | dtype=bfloat16 | dtype | True | False | False | False | none |
| stride_read | base | dtype=float16 | dtype | True | False | False | False | none |
| stride_read | base | layout=noncontig | layout | True | False | False | False | none |
| stride_read | base | x.grad=True | requires_grad | True | False | False | False | none |
| stride_read | base | dtype=float64 | dtype | True | False | False | False | none |
| stride_read | base | layout=transposed | layout | True | False | False | False | none |
| stride_read | base | x.grad=False | requires_grad | False | False | False | False | none |
| shape_boundary | base | dtype=float16 | dtype | True | False | False | False | none |
| shape_boundary | base | x.grad=True | requires_grad | True | False | False | False | none |
| shape_boundary | base | dtype=float64 | dtype | True | False | False | False | none |
| shape_boundary | base | x.grad=False | requires_grad | False | False | False | False | none |
