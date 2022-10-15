---
title: "多元高斯分布-Mutivariate_Gaussian"
tags:
- all
- GaussianDistribution
- Math/Probability
date: "2021-12-24"
---
# Multivariate Gaussian

<div align="right"> 2021-12-24</div>

Tags: #GaussianDistribution #Math/Probability 

[正态分布_高斯分布_Normal_Distribution-Gaussian_Distribution](notes/2021/2021.9/正态分布_高斯分布_Normal_Distribution-Gaussian_Distribution.md)

$$p(x ; \mu, \Sigma)=\frac{1}{(2 \pi)^{n / 2}|\Sigma|^{1 / 2}} \exp \left(-\frac{1}{2}(x-\mu)^{T} \Sigma^{-1}(x-\mu)\right)$$

- 其中$\Sigma$是随机向量$X$的协方差矩阵, 可以证明: $\Sigma$一定是对称的正定矩阵.

---
---

关于多元高斯分布有很多很好的资料:
- CS229的Lecture Note
- [CS229: Machine Learning](https://cs229.stanford.edu/syllabus.html)
- 矩阵求导的那个PDF里面也有很好的推导过程
- 这两个链接:
	- [搞懂多维高斯分布的由来 - 知乎](https://zhuanlan.zhihu.com/p/39763207)
	- [多元高斯分布完全解析 - 知乎](https://zhuanlan.zhihu.com/p/58987388)

