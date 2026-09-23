"""10.3 / 10.4  Model surgery and hyper-parameter changes after compilation; eager safety mechanisms under compile.

Same protocol as side_effect_diff.py (whose observation / comparison / isolation code is reused): every case is
`case(C)`; `C` wraps what gets compiled (identity in the eager run); the returned observation of the compiled run
must equal the eager one.  The cases here follow what users do to a model *after* `torch.compile(model)`:
freeze / unfreeze, cast, swap sub-modules, load a state dict, change dropout / batch-norm / optimizer
hyper-parameters between steps -- and whether eager's diagnostics (anomaly mode, deterministic mode, inference
tensors, integer division by zero) still fire.

    python scripts/model_surgery_diff.py --isolate
    python scripts/model_surgery_diff.py --report
"""
import os
import sys
import warnings

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import side_effect_diff as S  # noqa: E402

import torch  # noqa: E402
import torch.nn as nn  # noqa: E402
import torch.nn.functional as F  # noqa: E402

S.CASES.clear()
case, T, lin = S.case, S.T, S.lin


def mlp():
    torch.manual_seed(0)
    m = nn.Sequential(nn.Linear(3, 4), nn.Tanh(), nn.Linear(4, 2))
    with torch.no_grad():
        for k, p in enumerate(m.parameters()):
            p.copy_(T(*p.shape) * (k + 1) / 3)
    return m


def grads(m):
    return [None if p.grad is None else p.grad.clone() for p in m.parameters()]


def fb(cm, m, x):
    m.zero_grad(set_to_none=True)
    y = cm(x)
    y.sum().backward()
    return [y, grads(m)]


# ---- 10.3 a: surgery on a compiled module -------------------------------------------------------------------------
@case
def freeze_layer_after_compile(C):
    m = mlp(); cm = C(m); out = [fb(cm, m, T(2, 3))]
    m[0].weight.requires_grad_(False); m[0].bias.requires_grad_(False)
    return out + [fb(cm, m, T(2, 3))]
@case
def unfreeze_layer_after_compile(C):
    m = mlp(); m[2].weight.requires_grad_(False); cm = C(m); out = [fb(cm, m, T(2, 3))]
    m[2].weight.requires_grad_(True)
    return out + [fb(cm, m, T(2, 3))]
@case
def freeze_all_then_call(C):
    m = mlp(); cm = C(m); out = [fb(cm, m, T(2, 3))]
    m.requires_grad_(False)
    y = cm(T(2, 3))
    return out + [y, y.requires_grad, y.grad_fn is None]
@case
def cast_module_double_after_compile(C):
    m = mlp(); cm = C(m); out = [cm(T(2, 3))]
    m.double()
    return out + [cm(T(2, 3).double())]
@case
def cast_module_bfloat16_after_compile(C):
    m = mlp(); cm = C(m); out = [cm(T(2, 3))]
    m.bfloat16()
    return out + [cm(T(2, 3).bfloat16())]
@case
def replace_activation_after_compile(C):
    m = mlp(); cm = C(m); out = [cm(T(2, 3))]
    m[1] = nn.ReLU()
    return out + [cm(T(2, 3))]
@case
def replace_linear_other_width(C):
    m = mlp(); cm = C(m); out = [cm(T(2, 3))]
    m[0] = lin(3, 6); m[2] = lin(6, 2)
    return out + [cm(T(2, 3))]
@case
def load_state_dict_after_compile(C):
    m = mlp(); cm = C(m); out = [cm(T(2, 3))]
    m.load_state_dict({k: v * 0.5 for k, v in m.state_dict().items()})
    return out + [cm(T(2, 3))]
@case
def load_state_dict_assign_after_compile(C):
    m = mlp(); cm = C(m); out = [cm(T(2, 3))]
    m.load_state_dict({k: v * 0.5 for k, v in m.state_dict().items()}, assign=True)
    return out + [fb(cm, m, T(2, 3))]
@case
def param_data_swapped(C):
    m = mlp(); cm = C(m); out = [cm(T(2, 3))]
    m[0].weight.data = T(4, 3) * 2
    return out + [cm(T(2, 3))]
@case
def param_replaced_by_new_parameter(C):
    m = mlp(); cm = C(m); out = [cm(T(2, 3))]
    m[0].weight = nn.Parameter(T(4, 3) * 2)
    return out + [fb(cm, m, T(2, 3))]
@case
def bias_removed_after_compile(C):
    m = mlp(); cm = C(m); out = [cm(T(2, 3))]
    m[0].bias = None
    return out + [cm(T(2, 3))]
@case
def tied_weights_grad_sums(C):
    a, b = nn.Linear(3, 3, bias=False), nn.Linear(3, 3, bias=False)
    with torch.no_grad():
        a.weight.copy_(T(3, 3))
    b.weight = a.weight
    m = nn.Sequential(a, nn.Tanh(), b); cm = C(m)
    return fb(cm, m, T(2, 3))
@case
def tie_weights_after_compile(C):
    a, b = lin(3, 3), lin(3, 3)
    m = nn.Sequential(a, nn.Tanh(), b); cm = C(m); out = [fb(cm, m, T(2, 3))]
    b.weight = a.weight
    return out + [fb(cm, m, T(2, 3))]
@case
def weight_norm_then_change_g(C):
    m = torch.nn.utils.parametrizations.weight_norm(lin(3, 2)); cm = C(m); out = [cm(T(2, 3))]
    with torch.no_grad():
        m.parametrizations.weight.original0.mul_(3)
    return out + [fb(cm, m, T(2, 3))]
@case
def parametrization_added_after_compile(C):
    class Sym(nn.Module):
        def forward(self, w):
            return w.triu() + w.triu(1).transpose(-1, -2)
    m = lin(3, 3); cm = C(m); out = [cm(T(2, 3))]
    torch.nn.utils.parametrize.register_parametrization(m, "weight", Sym())
    return out + [cm(T(2, 3))]
@case
def parametrization_removed_after_compile(C):
    class Double(nn.Module):
        def forward(self, w):
            return w * 2
    m = lin(3, 3); torch.nn.utils.parametrize.register_parametrization(m, "weight", Double()); cm = C(m); out = [cm(T(2, 3))]
    torch.nn.utils.parametrize.remove_parametrizations(m, "weight", leave_parametrized=False)
    return out + [cm(T(2, 3))]
@case
def module_list_grows(C):
    class M(nn.Module):
        def __init__(self):
            super().__init__(); self.layers = nn.ModuleList([lin(3, 3)])
        def forward(self, x):
            for l in self.layers:
                x = torch.tanh(l(x))
            return x
    m = M(); cm = C(m); out = [cm(T(2, 3))]
    m.layers.append(lin(3, 3))
    return out + [cm(T(2, 3))]
@case
def forward_monkeypatched_after_compile(C):
    m = lin(); cm = C(m); out = [cm(T(2, 3))]
    m.forward = lambda x: F.linear(x, m.weight, m.bias) * 10
    return out + [cm(T(2, 3))]
@case
def class_attribute_changed(C):
    class M(nn.Module):
        scale = 2.0
        def forward(self, x):
            return x * self.scale
    m = M(); cm = C(m); out = [cm(T(3))]
    M.scale = 5.0
    return out + [cm(T(3))]
@case
def python_attrs_changed(C):
    class M(nn.Module):
        def __init__(self):
            super().__init__(); self.scale, self.n, self.flag, self.cfg, self.items = 2.0, 1, True, {"bias": 0.5}, [1.0]
        def forward(self, x):
            y = x * self.scale + self.cfg["bias"]
            for _ in range(self.n):
                y = y + sum(self.items)
            return y if self.flag else -y
    m = M(); cm = C(m); out = [cm(T(3))]
    m.scale = 3.0; out.append(cm(T(3)))
    m.n = 3; out.append(cm(T(3)))
    m.flag = False; out.append(cm(T(3)))
    m.cfg["bias"] = -1.0; out.append(cm(T(3)))
    m.items.append(2.0); out.append(cm(T(3)))
    return out
@case
def buffer_inplace_and_replaced(C):
    class M(nn.Module):
        def __init__(self):
            super().__init__(); self.register_buffer("b", torch.ones(3))
        def forward(self, x):
            return x + self.b
    m = M(); cm = C(m); out = [cm(T(3))]
    m.b.mul_(4); out.append(cm(T(3)))
    m.b = torch.full((3,), 7.0); out.append(cm(T(3)))
    m.register_buffer("b", torch.full((3,), 9.0), persistent=False); out.append(cm(T(3)))
    return out


# ---- 10.3 b: layer hyper-parameters changed between calls -----------------------------------------------------------
@case
def dropout_p_changed(C):
    m = nn.Dropout(0.5); cm = C(m); m.train(); cm(T(8))
    m.p = 0.0; a = cm(T(8))
    m.p = 1.0; b = cm(T(8))
    return [a, b]
@case
def dropout_train_eval_train(C):
    m = nn.Sequential(lin(3, 3), nn.Dropout(1.0)); cm = C(m)
    out = [cm(T(2, 3))]; m.eval(); out.append(cm(T(2, 3))); m.train(); out.append(cm(T(2, 3)))
    return out
@case
def batchnorm_momentum_eps_changed(C):
    m = nn.BatchNorm1d(3); cm = C(m); x = T(4, 3)
    out = [cm(x), m.running_mean.clone(), m.running_var.clone(), int(m.num_batches_tracked)]
    m.momentum = 0.9; out += [cm(x * 2), m.running_mean.clone(), m.running_var.clone()]
    m.eps = 10.0; out += [cm(x), m.running_var.clone()]
    m.momentum = None; out += [cm(x * 3), m.running_mean.clone(), int(m.num_batches_tracked)]
    m.eval(); out += [cm(x), m.running_mean.clone(), int(m.num_batches_tracked)]
    return out
@case
def batchnorm_track_stats_disabled_after_compile(C):
    m = nn.BatchNorm1d(3); cm = C(m); x = T(4, 3); out = [cm(x)]
    m.track_running_stats = False; m.running_mean = None; m.running_var = None; m.num_batches_tracked = None
    m.eval()
    return out + [cm(x * 2)]
@case
def layernorm_eps_and_affine_changed(C):
    m = nn.LayerNorm(3); cm = C(m); x = T(2, 3); out = [cm(x)]
    m.eps = 5.0; out.append(cm(x))
    m.weight = None; m.bias = None; out.append(cm(x))
    return out
@case
def leaky_relu_slope_changed(C):
    m = nn.LeakyReLU(0.1); cm = C(m); out = [cm(T(4) - 1)]
    m.negative_slope = 0.5
    return out + [cm(T(4) - 1)]
@case
def softmax_dim_changed(C):
    m = nn.Softmax(dim=0); cm = C(m); out = [cm(T(2, 3))]
    m.dim = 1
    return out + [cm(T(2, 3))]
@case
def conv_padding_stride_changed(C):
    m = nn.Conv1d(1, 1, 3, bias=False)
    with torch.no_grad():
        m.weight.fill_(1.0)
    cm = C(m); x = T(1, 1, 8); out = [cm(x)]
    m.padding = (1,); out.append(cm(x))
    m.stride = (2,); out.append(cm(x))
    return out
@case
def embedding_padding_idx_changed(C):
    m = nn.Embedding(4, 2)
    with torch.no_grad():
        m.weight.copy_(T(4, 2))
    cm = C(m); idx = torch.tensor([0, 1, 1, 3])
    out = [fb(cm, m, idx)]
    m.padding_idx = 1
    return out + [fb(cm, m, idx)]
@case
def functional_training_flag_python_bool(C):
    f = C(lambda x, training: F.dropout(x, 1.0, training=training))
    return [f(T(4), True), f(T(4), False), f(T(4), True)]


# ---- 10.3 c: optimizers with a compiled step ---------------------------------------------------------------------------
def train(C, make_opt, steps, mutate):
    m = mlp(); opt = make_opt(m.parameters())
    step = C(lambda: opt.step())
    out = []
    for k in range(steps):
        mutate(k, opt)
        opt.zero_grad()
        (m(T(2, 3)) ** 2).sum().backward()
        step()
        out.append([p.detach().clone() for p in m.parameters()])
    return out


@case
def sgd_lr_changed_between_steps(C):
    def mut(k, opt):
        opt.param_groups[0]["lr"] = [0.1, 0.01, 0.5, 0.0][k]
    return train(C, lambda p: torch.optim.SGD(p, lr=0.1), 4, mut)
@case
def sgd_momentum_wd_nesterov_changed(C):
    def mut(k, opt):
        g = opt.param_groups[0]
        if k == 1: g["momentum"] = 0.9
        if k == 2: g["weight_decay"] = 0.1
        if k == 3: g["nesterov"] = True
    return train(C, lambda p: torch.optim.SGD(p, lr=0.1), 5, mut)
@case
def adam_lr_betas_eps_changed(C):
    def mut(k, opt):
        g = opt.param_groups[0]
        if k == 1: g["lr"] = 0.5
        if k == 2: g["betas"] = (0.5, 0.5)
        if k == 3: g["eps"] = 1.0
        if k == 4: g["weight_decay"] = 0.5
    return train(C, lambda p: torch.optim.Adam(p, lr=0.1), 6, mut)
@case
def adamw_maximize_wd_changed(C):
    def mut(k, opt):
        g = opt.param_groups[0]
        if k == 2: g["maximize"] = True
        if k == 3: g["weight_decay"] = 0.0
    return train(C, lambda p: torch.optim.AdamW(p, lr=0.1), 5, mut)
@case
def adam_tensor_lr_changed_inplace(C):
    def mut(k, opt):
        if k == 2: opt.param_groups[0]["lr"].fill_(0.5)
    return train(C, lambda p: torch.optim.Adam(p, lr=torch.tensor(0.1)), 4, mut)
@case
def sgd_foreach_toggled(C):
    def mut(k, opt):
        if k == 1: opt.param_groups[0]["foreach"] = False
        if k == 2: opt.param_groups[0]["foreach"] = True
    return train(C, lambda p: torch.optim.SGD(p, lr=0.1, momentum=0.5), 4, mut)
@case
def rmsprop_adagrad_lr_changed(C):
    def mut(k, opt):
        if k == 2: opt.param_groups[0]["lr"] = 1.0
    return [train(C, lambda p: torch.optim.RMSprop(p, lr=0.1), 4, mut), train(C, lambda p: torch.optim.Adagrad(p, lr=0.1), 4, mut)]
@case
def lr_scheduler_with_compiled_step(C):
    m = mlp(); opt = torch.optim.SGD(m.parameters(), lr=0.5); sched = torch.optim.lr_scheduler.StepLR(opt, 1, gamma=0.1)
    step = C(lambda: opt.step()); out = []
    for _ in range(4):
        opt.zero_grad(); (m(T(2, 3)) ** 2).sum().backward(); step(); sched.step()
        out.append([p.detach().clone() for p in m.parameters()] + [opt.param_groups[0]["lr"]])
    return out
@case
def add_param_group_after_compile(C):
    m = mlp(); extra = nn.Parameter(T(3)); opt = torch.optim.SGD(m.parameters(), lr=0.1)
    step = C(lambda: opt.step()); out = []
    for k in range(3):
        if k == 1:
            opt.add_param_group({"params": [extra], "lr": 1.0})
        opt.zero_grad(); ((m(T(2, 3)) ** 2).sum() + (extra ** 2).sum()).backward(); step()
        out.append([p.detach().clone() for p in m.parameters()] + [extra.detach().clone()])
    return out
@case
def param_frozen_between_optimizer_steps(C):
    m = mlp(); opt = torch.optim.Adam(m.parameters(), lr=0.1); step = C(lambda: opt.step()); out = []
    for k in range(4):
        if k == 2:
            m[0].weight.requires_grad_(False); m[0].weight.grad = None
        opt.zero_grad(); (m(T(2, 3)) ** 2).sum().backward(); step()
        out.append([p.detach().clone() for p in m.parameters()])
    return out
@case
def grad_none_for_some_params(C):
    m = mlp(); opt = torch.optim.Adam(m.parameters(), lr=0.1); step = C(lambda: opt.step()); out = []
    for k in range(3):
        opt.zero_grad(set_to_none=True)
        (m[0](T(2, 3)) ** 2).sum().backward() if k == 1 else (m(T(2, 3)) ** 2).sum().backward()
        step(); out.append([p.detach().clone() for p in m.parameters()])
    return out
@case
def gradient_accumulation_two_microbatches(C):
    m = mlp(); cm = C(m); m.zero_grad()
    cm(T(2, 3)).sum().backward(); cm(T(2, 3) * 2).sum().backward()
    return grads(m)
@case
def clip_grad_norm_compiled(C):
    m = mlp(); (m(T(2, 3)) ** 2).sum().backward()
    f = C(lambda mx: torch.nn.utils.clip_grad_norm_(m.parameters(), mx))
    a = f(1.0); g1 = grads(m); b = f(0.01); g2 = grads(m)
    return [a, g1, b, g2]
@case
def grad_scaler_skips_inf_step(C):
    m = mlp(); opt = torch.optim.SGD(m.parameters(), lr=0.1); scaler = torch.amp.GradScaler("cpu", init_scale=4.0)
    cm = C(m); out = []
    for k in range(3):
        opt.zero_grad(); loss = (cm(T(2, 3)) ** 2).sum() * (float("inf") if k == 1 else 1.0)
        scaler.scale(loss).backward(); scaler.step(opt); scaler.update()
        out.append([p.detach().clone() for p in m.parameters()] + [scaler.get_scale()])
    return out
@case
def ema_update_compiled_decay_changed(C):
    m = mlp(); ema = [p.detach().clone() * 0 for p in m.parameters()]
    def upd(decay):
        with torch.no_grad():
            for e, p in zip(ema, m.parameters()):
                e.mul_(decay).add_(p, alpha=1 - decay)
    f = C(upd); f(0.9); f(0.9); f(0.5); f(1.0); f(0.0)
    return ema


# ---- 10.3 d: global switches flipped after compilation -------------------------------------------------------------------
@case
def grad_mode_flipped_globally(C):
    m = mlp(); cm = C(m); out = [cm(T(2, 3)).requires_grad]
    torch.set_grad_enabled(False)
    try:
        out.append(cm(T(2, 3)).requires_grad)
    finally:
        torch.set_grad_enabled(True)
    return out + [cm(T(2, 3)).requires_grad]
@case
def default_dtype_flipped(C):
    f = C(lambda x: x + torch.ones(3) * 0.1); out = [f(T(3))]
    torch.set_default_dtype(torch.float64)
    try:
        out.append(f(T(3)))
    finally:
        torch.set_default_dtype(torch.float32)
    return out
@case
def autocast_bf16_flipped(C):
    m = mlp(); cm = C(m); out = [cm(T(2, 3))]
    with torch.autocast("cpu", dtype=torch.bfloat16):
        out.append(cm(T(2, 3)))
    return out + [cm(T(2, 3))]
@case
def flush_denormal_flipped(C):
    f = C(lambda x: x * 0.5); x = torch.tensor([1e-38, 1.0]); out = [f(x)]
    ok = torch.set_flush_denormal(True)
    try:
        out.append(f(x))
    finally:
        torch.set_flush_denormal(False)
    return out + [ok]


# ---- 10.4: eager's safety / diagnostic mechanisms ---------------------------------------------------------------------------
@case
def anomaly_mode_nan_in_backward(C):
    f = C(lambda x: (torch.sqrt(x) * 0).sum()); x = torch.zeros(3, requires_grad=True)
    with warnings.catch_warnings():
        warnings.simplefilter("ignore")
        with torch.autograd.detect_anomaly():
            f(x).backward()
    return x.grad
@case
def anomaly_mode_nan_custom_function(C):
    class Bad(torch.autograd.Function):
        @staticmethod
        def forward(ctx, x):
            return x * 2
        @staticmethod
        def backward(ctx, g):
            return g * float("nan")
    f = C(lambda x: Bad.apply(x).sum()); x = torch.ones(3, requires_grad=True)
    with warnings.catch_warnings():
        warnings.simplefilter("ignore")
        with torch.autograd.detect_anomaly():
            f(x).backward()
    return x.grad
@case
def deterministic_mode_put_not_accumulate(C):
    f = C(lambda x, i, v: x.put_(i, v, accumulate=False))
    torch.use_deterministic_algorithms(True)
    try:
        return f(torch.zeros(4), torch.tensor([1, 1]), torch.tensor([1.0, 2.0]))
    finally:
        torch.use_deterministic_algorithms(False)
@case
def deterministic_mode_empty_is_filled(C):
    f = C(lambda x: torch.empty(5) + 0 * x.sum()); g = C(lambda x: torch.empty_like(x)); h = C(lambda x: x.new_empty(4).float())
    torch.use_deterministic_algorithms(True)
    try:
        return [torch.isnan(f(T(2))).all().item(), torch.isnan(g(T(6))).all().item(), torch.isnan(h(T(2))).all().item(),
                C(lambda: torch.empty(3, dtype=torch.int32))().tolist() == [torch.iinfo(torch.int32).max] * 3]
    finally:
        torch.use_deterministic_algorithms(False)
@case
def deterministic_mode_resize_is_filled(C):
    def f(x):
        y = x.clone(); y.resize_(6); return y
    torch.use_deterministic_algorithms(True)
    try:
        return torch.isnan(C(f)(T(2))[2:]).all().item()
    finally:
        torch.use_deterministic_algorithms(False)
@case
def inference_tensor_inplace_outside_inference_mode(C):
    with torch.inference_mode():
        x = torch.ones(3)
    C(lambda t: t.add_(1))(x)
    return x
@case
def inference_tensor_saved_for_backward(C):
    with torch.inference_mode():
        w = torch.ones(3)
    x = torch.ones(3, requires_grad=True)
    y = C(lambda a, b: (a * b).sum())(x, w); y.backward()
    return x.grad
@case
def leaf_requiring_grad_modified_inplace(C):
    x = torch.ones(3, requires_grad=True)
    C(lambda t: t.add_(1))(x)
    return x.detach()
@case
def view_of_leaf_modified_inplace(C):
    x = torch.ones(3, requires_grad=True)
    C(lambda t: t[0:2].mul_(2))(x)
    return x.detach()
@case
def no_grad_view_modified_in_grad_mode(C):
    base = torch.ones(3, requires_grad=True).clone()
    with torch.no_grad():
        v = base[0:2]
    y = C(lambda t: t.mul_(2))(v)
    return [y, base.detach()]
@case
def int_div_by_zero_vector_body(C):
    x = torch.arange(1, 41, dtype=torch.int32); d = torch.ones(40, dtype=torch.int32); d[5] = 0
    return C(lambda a, b: a // b)(x, d)
@case
def int_div_by_zero_tail(C):
    x = torch.arange(1, 41, dtype=torch.int32); d = torch.ones(40, dtype=torch.int32); d[39] = 0
    return C(lambda a, b: a // b)(x, d)
@case
def int_remainder_by_zero(C):
    x = torch.arange(1, 41, dtype=torch.int64); d = torch.ones(40, dtype=torch.int64); d[39] = 0
    return C(lambda a, b: a % b)(x, d)
@case
def int_div_trunc_by_zero(C):
    x = torch.arange(1, 41, dtype=torch.int16); d = torch.ones(40, dtype=torch.int16); d[7] = 0
    return C(lambda a, b: torch.div(a, b, rounding_mode="trunc"))(x, d)
@case
def int_fmod_by_zero(C):
    x = torch.arange(1, 41, dtype=torch.int32); d = torch.ones(40, dtype=torch.int32); d[7] = 0
    return C(lambda a, b: torch.fmod(a, b))(x, d)
@case
def int_div_by_zero_scalar_divisor(C):
    return C(lambda a: a // 0)(torch.arange(1, 9, dtype=torch.int32))
@case
def int_div_by_zero_inside_reduction(C):
    x = torch.arange(1, 41, dtype=torch.int32).reshape(4, 10); d = torch.ones(4, 10, dtype=torch.int32); d[2, 3] = 0
    return C(lambda a, b: (a // b).sum(1))(x, d)
@case
def int_div_by_zero_masked_out(C):
    x = torch.arange(1, 41, dtype=torch.int32); d = torch.ones(40, dtype=torch.int32); d[5] = 0
    return C(lambda a, b: torch.where(b != 0, a // torch.where(b != 0, b, 1), a))(x, d)
@case
def int_div_by_zero_uint8_and_bool(C):
    x = torch.arange(1, 41, dtype=torch.uint8); d = torch.ones(40, dtype=torch.uint8); d[5] = 0
    return C(lambda a, b: a // b)(x, d)
@case
def int_pow_negative_exponent(C):
    return C(lambda a: a ** -1)(torch.arange(1, 9, dtype=torch.int32))
@case
def int_lshift_negative(C):
    return C(lambda a, b: a << b)(torch.arange(1, 9, dtype=torch.int32), torch.full((8,), -1, dtype=torch.int32))
@case
def retain_grad_on_compiled_output(C):
    x = torch.ones(3, requires_grad=True); y = C(lambda t: t * 2)(x); y.retain_grad(); (y * y).sum().backward()
    return [y.grad, x.grad]
@case
def post_accumulate_grad_hook_fires(C):
    m = lin(); log = []
    m.weight.register_post_accumulate_grad_hook(lambda p: log.append(float(p.grad.sum())))
    cm = C(m); cm(T(2, 3)).sum().backward(); cm(T(2, 3)).sum().backward()
    return log
@case
def input_tensor_hook_doubles_grad(C):
    x = torch.ones(3, requires_grad=True); x.register_hook(lambda g: g * 2)
    C(lambda t: (t * 3).sum())(x).backward()
    return x.grad
@case
def std_single_element_warns(C):
    f = C(lambda x: x.std())
    with warnings.catch_warnings(record=True) as w:
        warnings.simplefilter("always")
        y = f(torch.ones(1))
    return [y, len([x for x in w if "degrees of freedom" in str(x.message)]) > 0]


if __name__ == "__main__":
    if not any(a.startswith("--out-jsonl") for a in sys.argv):
        sys.argv += ["--out-jsonl", os.path.join(S.ROOT, "results", "surgery", "cases.jsonl")]
    S.__file__ = os.path.abspath(__file__)          # run_isolated() must re-invoke this script, not side_effect_diff.py
    S.main()
