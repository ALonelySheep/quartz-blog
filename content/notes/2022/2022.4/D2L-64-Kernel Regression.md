---
title: "D2L-64-Kernel Regression"
tags:
- all
- KernelRegression
- Nonparametric
- Attention
- MachineLearning
date: "2022-04-20"
---
# Nadaraya-Watson Kernel Regression

<div align="right"> 2022-04-20</div>

Tags: #KernelRegression #Nonparametric #Attention #MachineLearning 

## Intuition
<iframe width="560" height="315" src="https://www.youtube.com/embed/t9-RDKyOU3o" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>

## Definition
$$f(x) = \sum_{i=1}^n \frac{K(x - x_i)}{\sum_{j=1}^n K(x - x_j)} y_i$$
- 其中是$K$ 是 _核_（kernel）， 上面的估计器（Estimator）也被称为 _Nadaraya-Watson核回归_（*Nadaraya-Watson kernel regression*）

- 在核为高斯核 (Gaussian Kernel) 的时候：
	$$K(u) = \frac{1}{\sqrt{2\pi}} \exp(-\frac{u^2}{2})$$
$$\begin{split}\begin{aligned} f(x) &=\sum_{i=1}^n \frac{K(x - x_i)}{\sum_{j=1}^n K(x - x_j)} y_i\\ &= \sum_{i=1}^n \frac{\exp\left(-\frac{1}{2}(x - x_i)^2\right)}{\sum_{j=1}^n \exp\left(-\frac{1}{2}(x - x_j)^2\right)} y_i \\&= \sum_{i=1}^n \mathrm{softmax}\left(-\frac{1}{2}(x - x_i)^2\right) y_i. \end{aligned}\end{split}$$
 ^33f5b4
- 值得注意的是，Nadaraya-Watson核回归是一个非参数模型. 可以看到上式里面没有任何参数, 模型的拟合结果完全由样本点决定.

### Example of Nadaraya–Watson Estimator in practice
![](notes/2022/2022.4/assets/output_nadaraya-waston_736177_41_0.svg)[^2]
![400](notes/2022/2022.4/assets/nw-1-1.png)[^1]

## Kernel Regression and Attention 
[[notes/2022/2022.4/D2L-66-Kernel Regression and Attention]]




[^1]: [6.2 Kernel regression estimation | Notes for Predictive Modeling](https://bookdown.org/egarpor/PM-UC3M/npreg-kre.html)
[^2]: [10.2. 注意力汇聚：Nadaraya-Watson 核回归 — 动手学深度学习 2.0.0-beta0 documentation](https://zh-v2.d2l.ai/chapter_attention-mechanisms/nadaraya-waston.html)


