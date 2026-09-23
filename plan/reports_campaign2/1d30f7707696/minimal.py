import torch
torch.manual_seed(0)

def forward(self, *args, **kwargs):
    self.differentiable = True

    tensor_map: Dict[str, torch.Tensor] = {}

    if len(args) == len(self.input_map):
        for i, key in enumerate(self.ir.input_var()):
            tensor_map[key] = args[i]
    elif len(kwargs) == len(self.input_map):
        for ir_key in self.input_map:
            tensor_map[ir_key] = kwargs[ir_key]
    else:
        raise ValueError("Either user args only or kwargs only")

    self.debug_numeric(tensor_map)

    self.invalid_found_last = False

    self.interm_grad = []

    # LOG.
    if self.print_grad >= 2:
        for k, v in tensor_map.items():
            if v.requires_grad:
                self.interm_grad.append((k, v))

        for i, p in enumerate(self.parameters()):
            if p.requires_grad:
                self.interm_grad.append((f"p_{i}", p))

    for stmt_idx, (inst, inps, outs, op) in enumerate(self.instructions):
        input_tensors = [tensor_map[idx] for idx in inps]

        check_type(op, input_tensors, is_input=True, msg="input")

        # REAL FORWARD.
        output_tensors = inst(*input_tensors)
        if not isinstance(output_tensors, list):
            output_tensors = [output_tensors]

        check_type(op, output_tensors, is_input=False, msg="output")

        for i, out_key in enumerate(outs):
            # put values back to tensor_map.
            tensor_map[out_key] = output_tensors[i]
            # Check differentiability.
            self.differentiable &= output_tensors[i].grad_fn is not None
            # TODO(@ganler): optimize: unref tensors that are not going to be used anymore.

        # LOG.
        if TORCH_LOG.isEnabledFor(logging.DEBUG):
            TORCH_LOG.debug(f">> statment {stmt_idx}")
            for inp_i, i in enumerate(input_tensors):
                TORCH_LOG.debug(f"  (shape={i.shape} dtype={i.dtype})")
                TORCH_LOG.debug(
                    f"[inp]@{inp_i} :: {i.min().data:.5f} ~ {i.max().data:.5f}"
                )
            for out_i, o in enumerate(output_tensors):
                TORCH_LOG.debug(f"  (shape={o.shape} dtype={o.dtype})")
                TORCH_LOG.debug(
                    f"[out]@{out_i} :: {o.min().data:.5f} ~ {o.max().data:.5f}"
                )

        if self.print_grad >= 2:
            if output_tensors[0].requires_grad:
                for i in range(len(output_tensors)):
                    output_tensors[i].retain_grad()
                    self.interm_grad.append((f"{op}{i}", output_tensors[i]))

        if self.check_intermediate_numeric or (
            self.use_gradient and not self.stop_updating_loss
        ):
            if loss_fn.dispatch(type(op)) is not None:
                loss = loss_fn(op)(*input_tensors)
                if not isinstance(loss, tuple):
                    loss = ("", loss)  # loss suffix, loss
                vul_op_loss = loss
            else:
                vul_op_loss = None
            self.invalid_found_last |= not numeric_valid(output_tensors)

            if self.invalid_found_last and (
                self.use_gradient and not self.stop_updating_loss
            ):
                if self.print_grad >= 1:
                    for inp_i, inp in enumerate(input_tensors):
                        TORCH_LOG.info(
                            f"[inp]@{inp_i} :: {inp.min().data:.5f} ~ {inp.max().data:.5f}"
                        )

                ConstraintCheck.true(
                    vul_op_loss is not None,
                    f"op={op} has no `torch_loss` but produces NaN or INF!",
                )
                # TODO: some less vulnerable ops (like Mul) may also trigger Inf and will crash the process.
                # Given its low chance of happening, ignore it for now.
                loss_suf, l = vul_op_loss
                msg = f"loss_{loss_suf}: {l.min().data:.3f} ~ {l.max().data:.3f} ~ {torch.sum((l > 0) * l).item()}"
                if self.print_grad >= 1:
                    TORCH_LOG.info(
                        f"Iter #{self.iter_num} [NaN/Inf] in outputs ~ {op} :: {msg}"
                    )

                ConstraintCheck.true(
                    torch.all(l > 0),
                    f"`{op}` outputs NaN/INF found non-positive loss!",
                )
                loss_name = f"{op}_{loss_suf}"
                ConstraintCheck.true(self.loss is None, "Multiple loss detected!")
                self.loss = loss_name, torch.sum((l > 0) * l)
                if loss_name != self.cur_loss_name:
                    self.reset_optimizer()
                    self.cur_loss_name = loss_name

                self.stop_updating_loss = True
                return output_tensors

    self.first_run = False
    return tuple(tensor_map[key] for key in self.output_map)

args = (torch.randint(0, 4, (1, 1,)).to(torch.int8),)

# context A then context B on the same compiled callable (no reset)
# A = {} (base)
# B = {'requires_grad': {'arg': 0, 'value': True}}
args_b = (torch.randint(0, 4, (1, 1,)).to(torch.int8),)
torch._dynamo.reset()
compiled = torch.compile(nnsmith_100003, backend='inductor')
compiled(*args)              # warm the cache under A
warm = compiled(*args_b)     # execute under B without a reset
torch._dynamo.reset()
cold = torch.compile(nnsmith_100003, backend='inductor')(*args_b)
eager = nnsmith_100003(*args_b)
print('eager :', eager)
print('cold  :', cold)
print('warm  :', warm)
