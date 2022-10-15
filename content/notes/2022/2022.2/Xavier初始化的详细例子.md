---
title: "Xavier初始化的详细例子"
tags:
- all


---
以MLP为例

- 假设:
  - $w_{i, j}^{s}$ 是 i.i.d, 那么 $\mathbb{E}\left[w_{i, j}^{s}\right]=0, \operatorname{Var}\left[w_{i, j}^{s}\right]=\gamma_{s}$
  - $h_{i}^{s-1}$ 独立于 $w_{i, j}^{s}$
  - 假设没有激活函数, 即: $$\mathbf{h}^{s}=\mathbf{W}^{s} \mathbf{h}^{s-1}, \text { 这里 } \mathbf{W}^{s} \in \mathbb{R}^{n_{s} \times n_{s-1}}$$

##### 正向均值

$$\mathbb{E}\left[h_{i}^{s}\right]=\mathbb{E}\left[\sum_{j} w_{i, j}^{s} h_{j}^{s-1}\right]=\sum_{j} \mathbb{E}\left[w_{i, j}^{s}\right] \mathbb{E}\left[h_{j}^{s-1}\right]=0$$

##### 正向方差

$$\begin{aligned}
\operatorname{Var}\left[h_{i}^{s}\right] &=\mathbb{E}\left[\left(h_{i}^{s}\right)^{2}\right]-\mathbb{E}\left[h_{i}^{s}\right]^{2}\\
&=\mathbb{E}\left[\left(\sum_{j} w_{i, j}^{s} h_{j}^{s-1}\right)^{2}\right] \\
&=\mathbb{E}\left[\sum_{j}\left(w_{i, j}^{s}\right)^{2}\left(h_{j}^{s-1}\right)^{2}+\sum_{j \neq k} w_{i, j}^{s} w_{i, k}^{s} h_{j}^{s-1} h_{k}^{s-1}\right] \\
(\text{because i.i.d, covariance is 0} )
&=\mathbb{E}\left[\sum_{j}\left(w_{i, j}^{s}\right)^{2}\left(h_{j}^{s-1}\right)^{2}\right] \\
&=\sum_{j} \mathbb{E}\left[\left(w_{i, j}^{s}\right)^{2}\right] \mathbb{E}\left[\left(h_{j}^{s-1}\right)^{2}\right] \\
(\text{because }\mathbb{E}\left[h_{j}^{s-1}\right]^{2}, \mathbb{E}\left[w_{i,j}^{s}\right]^{2}\space is\space 0)
&=\sum_{j} \operatorname{Var}\left[w_{i, j}^{s}\right] \operatorname{Var}\left[h_{j}^{s-1}\right]\\
\left(\mathbf{W}^{s} \in \mathbb{R}^{n_{s} \times n_{s-1}}\right)
&=n_{s-1} \gamma_{s} \operatorname{Var}\left[h_{j}^{s-1}\right]
\end{aligned}$$

- 这意味着如果输入层输出层要方差不变, 则必须有 $$n_{s-1} \gamma_{s}=1$$

##### 反向部分

首先, 因为 $\mathbf{h}^{s}=\mathbf{W}^{s} \mathbf{h}^{s-1}$, 所以 $$\begin{aligned}\frac{\partial\ell}{\partial\mathbf{h}^{s-1}}
&=\frac{\partial\ell}{\partial\mathbf{h}^{s}}
\frac{\partial\mathbf{h}^{s}}{\partial\mathbf{h}^{s-1}}\\
&=\frac{\partial\ell}{\partial\mathbf{h}^{s}}
\frac{\partial\mathbf{W}^{s} \mathbf{h}^{s-1}}{\partial\mathbf{h}^{s-1}}\\
&=\frac{\partial\ell}{\partial\mathbf{h}^{s}}
\mathbf{W}^{s}\end{aligned}$$

为了和上面正向的步骤相似, 我们同时取一个转置, 得到:
$$\left(\frac{\partial\ell}{\partial\mathbf{h}^{s-1}}\right)^T
=\left(\mathbf{W}^{s}\right)^T\left(\frac{\partial\ell}{\partial\mathbf{h}^{s}}\right)^T$$

##### 反向均值

$$\mathbb{E}\left[\left(\frac{\partial\ell}{\partial\mathbf{h}^{s-1}}\right)^T_i\right]
=\mathbb{E}\left[\sum_{j} w_{j, i}^{s} \left(\frac{\partial\ell}{\partial\mathbf{h}^{s}}\right)^T_{j}\right]
=\sum_{j} \mathbb{E}\left[w_{j, i}^{s}\right] \mathbb{E}\left[\left(\frac{\partial\ell}{\partial\mathbf{h}^{s}}\right)^T_{j}\right]=0$$

##### 反向方差

$$\begin{aligned}
\operatorname{Var}\left[\left(\frac{\partial\ell}{\partial\mathbf{h}^{s-1}}\right)^T_i\right]
&=\mathbb{E}\left[\left(\left(\frac{\partial\ell}{\partial\mathbf{h}^{s-1}}\right)^T_i\right)^{2}\right]-\mathbb{E}\left[\left(\frac{\partial\ell}{\partial\mathbf{h}^{s-1}}\right)^T_i\right]^{2}\\
&=\mathbb{E}\left[\left(\sum_{j} w_{j, i}^{s} \left(\frac{\partial\ell}
{\partial\mathbf{h}^{s}}\right)^T_{j}\right)^{2}\right] \\
&=\mathbb{E}\left[\sum_{j}\left(w_{j, i}^{s}\right)^{2}\left(\left(\frac{\partial\ell}
{\partial\mathbf{h}^{s}}\right)^T_{j}\right)^{2}+\sum_{j \neq k} w_{j, i}^{s} w_{k, i}^{s} \left(\frac{\partial\ell}
{\partial\mathbf{h}^{s}}\right)^T_{j} \left(\frac{\partial\ell}
{\partial\mathbf{h}^{s}}\right)^T_{k}\right] \\
&=\mathbb{E}\left[\sum_{j}\left(w_{j, i}^{s}\right)^{2}\left(\left(\frac{\partial\ell}
{\partial\mathbf{h}^{s}}\right)^T_{j}\right)^{2}\right] \\
&=\sum_{j} \mathbb{E}\left[\left(w_{j, i}^{s}\right)^{2}\right] \mathbb{E}\left[\left(\left(\frac{\partial\ell}
{\partial\mathbf{h}^{s}}\right)^T_{j}\right)^{2}\right] \\
&=\sum_{j} \operatorname{Var}\left[w_{j, i}^{s}\right] \operatorname{Var}\left[\left(\frac{\partial\ell}
{\partial\mathbf{h}^{s}}\right)^T_{j}\right]\\
\left(\mathbf{W}^{s} \in \mathbb{R}^{n_{s} \times n_{s-1}}\right)
&=n_{s} \gamma_{s} \operatorname{Var}\left[\left(\frac{\partial\ell}
{\partial\mathbf{h}^{s}}\right)^T_{j}\right]
\end{aligned}$$

- 这意味着如果输入层输出层要方差不变, 则必须有 $$n_{s} \gamma_{s}=1$$
