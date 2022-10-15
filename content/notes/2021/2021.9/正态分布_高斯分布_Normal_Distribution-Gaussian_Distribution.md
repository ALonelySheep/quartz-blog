---
title: "正态分布_高斯分布_Normal_Distribution-Gaussian_Distribution"
tags:
- all
- Math/Statistics
date: "2021-09-16"
---
# 正态分布

<div align="right"> 2021-09-16</div>

Tags: #Math/Statistics

## 概率密度函数
正态分布, 概率密度函数:
$$f(x)=\frac{1}{\sigma \sqrt{2 \pi}} e^{\Large -\frac{1}{2}\left(\frac{x-\mu}{\sigma}\right)^{2}}$$
or
$$f(x)=\frac{1}{\sigma \sqrt{2 \pi}} \exp\left(-\frac{1}{2}\left(\frac{x-\mu}{\sigma}\right)^{2}\right)$$

## 重要性质
- Mean $(\mu)$ and standard deviation $(\sigma)$
$$
\begin{aligned}
&\mu=E(X)=\int_{-\infty}^{\infty} x p(x) d x \\
&\sigma^{2}=E\left\{(X-\mu)^{2}\right\}=\int_{-\infty}^{\infty}(x-\mu)^{2} p(x) d x
\end{aligned}
$$

- Probability within any particular number of standard deviations of $\mu$
$$
\begin{aligned}
p\{\mu-k \sigma \leq x \leq \mu+k \sigma\} &=\int_{\mu-k \sigma}^{\mu+k \sigma} \frac{1}{\sqrt{2 \pi} \sigma} \exp \left[-\frac{(x-\mu)^{2}}{2 \sigma^{2}}\right] d x \\
&=\frac{1}{\sqrt{2 \pi}} \int_{-k}^{k} \exp \left[-\frac{y^{2}}{2}\right] d y
\end{aligned}
$$

- 线性变换后: 
如果 $X \sim N\left(\mu,\sigma^{2}\right)$ 且 $a, b$是实数, 那么
$$a X+b \sim N\left(a \mu+b,(a \sigma)^{2}\right)$$

- 正态分布的和还是正态分布[^1]
$$\begin{aligned}
&X \sim N\left(\mu_{X}, \sigma_{X}^{2}\right) \\
&Y \sim N\left(\mu_{Y}, \sigma_{Y}^{2}\right) \\
&Z=X+Y
\end{aligned}$$
则
$$Z \sim N\left(\mu_{X}+\mu_{Y}, \sigma_{X}^{2}+\sigma_{Y}^{2}\right)$$

## 记忆公式
- 注意$\sigma$在根号外面
- 指数是负的($x=\mu$的时候等于0, 同时取得最大值)


## 与拉普拉斯分布的联系

[拉普拉斯分布与高斯分布的联系_Relation_of_Laplace_distribution _and_Gaussian_distribution](notes/2021/2021.8/拉普拉斯分布与高斯分布的联系_Relation_of_Laplace_distribution%20_and_Gaussian_distribution.md)

## Higher Dimensions
$$\begin{aligned}
&p\{x\}=\frac{1}{(\sqrt{2 \pi})^{n / 2}|C|^{1 / 2}} \exp \left[-\frac{1}{2}(x-\mu)^{T} C^{-1}(x-\mu)\right] \\
&x=\left[\begin{array}{c}
x_{1} \\
\cdots \\
x_{n}
\end{array}\right] \quad \mu=\left[\begin{array}{c}
\mu_{1} \\
\cdots \\
\mu_{n}
\end{array}\right] \quad C=\left[\begin{array}{ccc}
\sigma_{11}^{2} & \ldots & \sigma_{1 n}^{2} \\
\cdots & & \ldots \\
\sigma_{m 1}^{2} & \ldots & \sigma_{m n}^{2}
\end{array}\right]
\end{aligned}$$


[^1]: [Sum of normally distributed random variables - Wikipedia](https://en.wikipedia.org/wiki/Sum_of_normally_distributed_random_variables)