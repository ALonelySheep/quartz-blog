---
title: "D2L-54-Gradient Clipping-梯度剪裁"
tags:
- all
- GradientClipping
date: "2022-04-02"
---
# Gradient Clipping

<div align="right"> 2022-04-02</div>

Tags: #GradientClipping

- 梯度剪裁是预防梯度爆炸的一种方法, 它直接给梯度设置一个上限.

$$\mathbf{g} \leftarrow \min \left(1, \frac{\theta}{\|\mathbf{g}\|}\right) \mathbf{g}$$
- 上面的写法有点绕, 因为为了保持梯度 $\mathbf{g}$ 的方向不变, 剪裁时需要作用于 $\mathbf{g}$ 的每一个分量, 整体上来说其实就是:
$$\mathbf{g} \leftarrow \min \left(\|\mathbf{g}\|, \theta \frac{\mathbf{g}}{\|\mathbf{g}\|}\right)$$

![400](notes/2022/2022.4/assets/img_2022-10-15-3.png)
- 相比直接减小学习率，Clipping是分段的, 可以只在梯度较大时加以限制.

- 抽象版的描述见：　[8.5. Implementation of Recurrent Neural Networks from Scratch — Dive into Deep Learning 0.17.5 documentation](https://d2l.ai/chapter_recurrent-neural-networks/rnn-scratch.html#gradient-clipping)

## PyTorch
[torch.nn.utils.clip_grad_norm_ — PyTorch 1.11.0 documentation](https://pytorch.org/docs/stable/generated/torch.nn.utils.clip_grad_norm_.html)
```python
nn.utils.clip_grad_norm_(model.parameters(), max_norm=CLIP_GRAD)
```

## D2l 里面的简易实现
```py
def grad_clipping(net, theta):  #@save
    """裁剪梯度"""
    if isinstance(net, nn.Module):
        params = [p for p in net.parameters() if p.requires_grad]
    else:
        params = net.params
    norm = torch.sqrt(sum(torch.sum((p.grad ** 2)) for p in params))
    if norm > theta:
        for param in params:
            param.grad[:] *= theta / norm #注意这里是*=
```