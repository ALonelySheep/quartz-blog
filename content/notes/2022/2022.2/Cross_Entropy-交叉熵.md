---
title: "Cross_Entropy-交叉熵"
tags:
- all
- InformationTheory
- DeepLearning
date: "2022-02-11"
---
# Cross Entropy - 交叉熵

<div align="right"> 2022-02-11</div>

Tags: #InformationTheory #DeepLearning 

## Intuition
- 熵是编码一个事件所需要的最短平均长度
	$$\begin{aligned}H(p)&=\sum_{x_{i}} p\left(x_{i}\right) \log \frac{1}{p\left(x_{i}\right)} \\
	&=-\sum_{x} p(x) \log p(x)	\end{aligned}$$
- 而交叉熵则是一种特殊情况下编码的平均最短长度: 事件真实的概率分布是 $p(x)$, 但是我们以为事件的分布是 $q(x)$ .  

	- 因此, 交叉熵可以看作每个信息片段在错误分布 $q$ 下的期望编码位长度，而信息实际分布为 $p$。这就是期望 $\operatorname{E}_p$ 是基于 $p$ 而不是 $q$ 的原因.[^3]
	$$\begin{aligned}   H(p, q)&=\sum_{x_{i}} p\left(x_{i}\right) \log \frac{1}{q\left(x_{i}\right)} \\
	&=-\sum_{x} p(x) \log q(x) \end{aligned}$$



## Formal Definition
- 在指定集合下, 分布 $q$  相对于分布 $p$ 的交叉熵定义如下:
$$H(p, q) = -\operatorname{E}_p[\log q]$$
其中符号 $E_p[\cdot]$ 的含义是 相对于分布 $p$ 的期望值.

- 交叉熵的定义也可以从 [KL散度](notes/2022/2022.2/KL_Divergence-KL散度.md) $D_{\mathrm{KL}}(p \parallel q)$ 得出(KL散度也叫做$p$ 相对于 $q$的相对熵).
$$H(p, q) = H(p) + D_{\mathrm{KL}}(p \parallel q)$$
其中 $H(p)$ 是分布 $p$ 的 [熵(Entropy)](notes/2022/2022.2/Entropy-熵.md) .

- 对于离散分布 $p$ 和 $q$ :
$$H(p, q)=-\sum_{x \in \mathcal{X}} p(x) \log q(x)$$
[^1]
## 性质
- 交叉熵不是对称的: *i.e.* $$H(p,q)\neq H(q,p)$$
	- KL散度也不是对称的
	- 尽管不是对称的，但是无论是 $H(p,q)$ 还是 $H(p,q)$ 其实都可以作为概率相似程度的衡量标准


- 交叉熵是非负的: $$H(p, q)=-\sum_{x } p(x) \log q(x)$$
	其中 $p(x), q(x)\in[\ 0,1\ ], \log q(x)\leq0$
	
## 交叉熵: 作为损失函数
[交叉熵是怎样衡量输出和真实值的差别的呢?](notes/2022/2022.2/D2L-14-Cross%20Entropy%20as%20Loss.md)

## Cross Entropy in Neural Networks
![](notes/2022/2022.2/assets/img_2022-10-15-9.png)
- 在[Softmax回归](notes/2022/2022.2/D2L-13-Softmax_Regression.md)里面, 前面的真实概率分布是[One-hot_Encoding-独热编码](notes/2022/2022.1/One-hot_Encoding-独热编码.md)的, 所以整个求和式里只有一项留下来了, 即模型输出类的预测概率的负对数$-\log q(x)$
<iframe width="560" height="315" src="https://www.youtube.com/embed/6ArSys5qHAU?start=170" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>

[^1]: 其中$\mathcal{X}$ 指的是测度论里面的"支撑集". Reference: [Support (measure theory) - Wikipedia](https://en.wikipedia.org/wiki/Support_(measure_theory))
[^2]: [为什么用交叉熵做损失函数 - 知乎](https://zhuanlan.zhihu.com/p/70804197)
[^3]: [交叉熵 - 维基百科，自由的百科全书](https://zh.wikipedia.org/wiki/%E4%BA%A4%E5%8F%89%E7%86%B5)   [Cross entropy - Wikipedia](https://en.wikipedia.org/wiki/Cross_entropy) [详解机器学习中的熵、条件熵、相对熵和交叉熵 - 知乎](https://zhuanlan.zhihu.com/p/35379531)