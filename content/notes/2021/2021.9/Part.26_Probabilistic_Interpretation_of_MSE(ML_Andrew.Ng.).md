---
title: "Part.26_Probabilistic_Interpretation_of_MSE(ML_Andrew.Ng.)"
tags:
- all
- MachineLearning
- Math/Statistics
- MeanSquareError
- CostFunction
date: "2021-09-16"
---
# 均方差的合理性 - 概率解释

<div align="right"> 2021-09-16</div>

Tags: #MachineLearning #Math/Statistics #MeanSquareError #CostFunction 

## 之前的一些讨论
- [Mean_Squared_Error-均方误差](notes/2021/2021.8/Mean_Squared_Error_均方误差.md)
- [Why_do_cost_functions_use_the_square_error](notes/2021/2021.8/Why_do_cost_functions_use_the_square_error.md)

## CS229 - Probabilistic Interpretation

- [独立同分布-IID](notes/2021/2021.9/独立同分布-IID.md)
- [[notes/2021/2021.9/正态分布_高斯分布_Normal_Distribution-Gaussian_Distribution]]

Prerequisite: [似然函数](https://zh.wikipedia.org/zh-hans/%E4%BC%BC%E7%84%B6%E5%87%BD%E6%95%B0)
> 我需要进一步学习概率论(贝叶斯统计)

---

下面叙述从概率角度该怎么理解均方差的合理性, 其实是最大似然估计的思想, 和Bayesian估计的思想很像.

- **前提:** 误差$\epsilon$是**独立同分布(IID)** 的且服从**正态分布(Normal Distribution)** 
	- **理论基础:** 中心极限定理.


我们这样表示输入和输出的关系: 其中$x^{(i)}$是输入, $y^{(i)}$是输出, $\theta^{T}$是参数向量, $\epsilon^{(i)}$表示误差.
$$y^{(i)}=\theta^{T} x^{(i)}+\epsilon^{(i)}$$

根据我们的假设, 误差服从正态分布: 

$$
\begin{aligned}
\epsilon^{(i)}&\sim\mathcal{N}\left(0, \sigma^{2}\right)\quad\Rightarrow
\\p\left(\epsilon^{(i)}\right)&=\frac{1}{\sqrt{2 \pi} \sigma} \exp \left(-\frac{\left(\epsilon^{(i)}\right)^{2}}{2 \sigma^{2}}\right)
\end{aligned}$$
将输入输出的关系带进去, 可以得到$y^{(i)}$的概率密度分布:
$$
p\left(y^{(i)} \mid x^{(i)} ; \theta\right)=\frac{1}{\sqrt{2 \pi} \sigma} \exp \left(-\frac{\left(y^{(i)}-\theta^{T} x^{(i)}\right)^{2}}{2 \sigma^{2}}\right)
$$

联系[正态分布的表达式](notes/2021/2021.9/正态分布_高斯分布_Normal_Distribution-Gaussian_Distribution.md#概率密度函数):

$$f(x)=\frac{1}{\sigma \sqrt{2 \pi}} \exp\left(-\frac{1}{2}\left(\frac{x-\mu}{\sigma}\right)^{2}\right)$$

其中的$\theta^{T} x^{(i)}$就是数学期望$\mu$, 所以我们可以这样表示:

$$y^{(i)} \mid x^{(i)} ; \theta \sim \mathcal{N}\left(\theta^{T} x^{(i)}, \sigma^{2}\right)$$

- **下面是关键的一步:**

我们总是想要根据给定的$X$ (the design matrix, which contains all the $x^{(i)}$’s), 调整$\theta$, 来得到对于输出$Y$的最佳预测.

所以我们给出这个问题的似然函数:
$$L(\theta)=L(\theta ; X, \vec{y})=p(\vec{y} \mid X ; \theta)$$
它表示在给定的$\theta$下, 由训练集里面的$X$得到对应的$Y$的"似然性/可能性/合理性"

根据似然函数的定义(就相当于条件概率), 对于我们的训练集, $L(\theta)$表示如下:
$$\begin{aligned}
L(\theta) &=\prod_{i=1}^{m} p\left(y^{(i)} \mid x^{(i)} ; \theta\right) \\
&=\prod_{i=1}^{m} \frac{1}{\sqrt{2 \pi} \sigma} \exp \left(-\frac{\left(y^{(i)}-\theta^{T} x^{(i)}\right)^{2}}{2 \sigma^{2}}\right)
\end{aligned}$$
- 注意是连乘, 因为是联合概率

根据**极大似然估计**的思想, 我们想要知道$L(\theta)$取得最大值的时候的$\theta$值, 因为最大化这个函数十分复杂, 我们可以取对数(因为对数函数是严格递增的, 而这个的值域也在对数函数的定义域里面)

我们用$\ell(\theta)$表示$log\space likelihood$:
$$\begin{aligned}
\ell(\theta) &=\log L(\theta) \\
&=\log \prod_{i=1}^{m} \frac{1}{\sqrt{2 \pi} \sigma} \exp \left(-\frac{\left(y^{(i)}-\theta^{T} x^{(i)}\right)^{2}}{2 \sigma^{2}}\right) \\
&=\sum_{i=1}^{m} \log \frac{1}{\sqrt{2 \pi} \sigma} \exp \left(-\frac{\left(y^{(i)}-\theta^{T} x^{(i)}\right)^{2}}{2 \sigma^{2}}\right) \\
&=m \log \frac{1}{\sqrt{2 \pi} \sigma}-\frac{1}{\sigma^{2}} \cdot \frac{1}{2} \sum_{i=1}^{m}\left(y^{(i)}-\theta^{T} x^{(i)}\right)^{2}
\end{aligned}$$
所以要最大化$\ell(\theta)$相当于最小化 
$$\frac{1}{2} \sum_{i=1}^{m}\left(y^{(i)}-\theta^{T} x^{(i)}\right)^{2}$$
这和平方误差和只差一个$\frac 1 m$


> Note also that, in our previous discussion, **our final choice of $θ$ did not depend on what was $σ^2$,** and indeed we’d have arrived at the same result even if $σ^2$ were unknown. We will use this fact again later, when we talk about the **exponential family** and **generalized linear models**.