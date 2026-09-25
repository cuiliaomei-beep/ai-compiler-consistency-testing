| program | stmts | blockers (why TorchProbe cannot take it as a seed) | mutations with a site |
|---|---:|---|---|
| shape_boundary | 2 | control_flow:if; python_reads_tensor_metadata:shape | - |
| mod_tiling | 5 | control_flow:if; python_reads_tensor_metadata:shape; non_static_indexing:x[:pad] | - |
| index_chain | 4 | python_reads_tensor_metadata:shape; non_static_indexing:x[i] | - |
| dtype_read | 2 | control_flow:if; python_reads_tensor_metadata:dtype; ops_outside_temisu_renderer:float,half | - |
| python_flag | 2 | control_flow:if; non_tensor_args:1 | - |
| python_flag_semantic | 2 | control_flow:if; non_tensor_args:1; ops_outside_temisu_renderer:tanh | - |
| scalar_compare | 2 | control_flow:if; non_static_indexing:x[:n]; non_tensor_args:1 | - |
| none_check | 2 | control_flow:if; non_tensor_args:1 | - |
| view_inplace | 3 | in_place_mutation; ops_outside_temisu_renderer:view | - |
| noncontig_copy | 3 | in_place_mutation; ops_outside_temisu_renderer:copy_ | - |
| overlapping_views | 5 | in_place_mutation; ops_outside_temisu_renderer:add_,mul_ | - |
| alias_returned | 2 | (representable) | insert_tcb, modify_then_recover, subfunction |
| conditional_mutation | 2 | control_flow:if; python_reads_tensor_metadata:shape; in_place_mutation; ops_outside_temisu_renderer:add_ | - |
| chunk_inplace | 3 | in_place_mutation; ops_outside_temisu_renderer:chunk,mul_ | - |
| requires_grad_switch | 2 | (representable) | insert_tcb, desolve_op, modify_then_recover, subfunction |
| global_state | 1 | module_globals:SCALE | - |
| closure_fn | 1 | closure_vars:k | - |
| reshape_dim | 1 | non_tensor_args:1 | - |
| loop_bound | 2 | control_flow:for; non_tensor_args:1; python_calls:range | - |
| exception_path | 2 | control_flow:if,raise; python_reads_tensor_metadata:shape; python_calls:ValueError | - |
| container_len | 2 | control_flow:if; non_tensor_args:1; python_calls:len | - |
| string_mode | 2 | control_flow:if; non_tensor_args:1 | - |
| stride_read | 2 | control_flow:if; python_reads_tensor_metadata:stride; ops_outside_temisu_renderer:contiguous,stride,t | - |
| mask_index | 2 | non_static_indexing:x[m] | - |
| gather_shape | 3 | python_reads_tensor_metadata:device,shape; ops_outside_temisu_renderer:arange,index_select | - |
| dtype_reduce | 1 | (representable) | desolve_op, subfunction |
| contiguous_read | 2 | control_flow:if; python_reads_tensor_metadata:is_contiguous; ops_outside_temisu_renderer:is_contiguous,view | - |
| rank_read | 2 | control_flow:if; python_reads_tensor_metadata:ndim | - |
| flag_and_shape | 2 | control_flow:if; python_reads_tensor_metadata:shape; non_tensor_args:1 | - |
