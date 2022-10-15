---
title: "拉普拉斯分布与高斯分布的联系_Relation_of_Laplace_distribution _and_Gaussian_distribution"
tags:
- all
- Math/Statistics
- GaussianDistribution
- LaplaceDistribution
date: "2021-07-31"
---
# Gaussian distribution, Laplace distribution: The Relation

<div align="right"> 2021-07-31</div>

Tags: #Math/Statistics #GaussianDistribution #LaplaceDistribution

拉普拉斯分布, 概率密度函数:
![](notes/2021/2021.7/assets/img_2022-10-15-1.png)
![](notes/2021/2021.7/assets/img_2022-10-15-2.png)

![概率密度函数](notes/2021/2021.9/正态分布_高斯分布_Normal_Distribution-Gaussian_Distribution.md#概率密度函数)

- Look at the formula for the PDF in the infobox -- it's just the Gaussian with  $|\boldsymbol{x}-\boldsymbol{\mu}|$ instead of $(\boldsymbol{x}-\boldsymbol{\mu})^{2}$)[^2]

- 拉普拉斯分布的概率密度函数让我们联想到[正态分布](https://zh.wikipedia.org/wiki/%E6%AD%A3%E6%80%81%E5%88%86%E5%B8%83 "正态分布")，但是，**正态分布**是用相对于 _μ_ **[平均值](https://zh.wikipedia.org/wiki/%E5%B9%B3%E5%9D%87%E5%80%BC)的差的平方**来表示，而**拉普拉斯概率密度**用相对于**平均值的差的[绝对值](https://zh.wikipedia.org/wiki/%E7%BB%9D%E5%AF%B9%E5%80%BC "绝对值")** 来表示。因此，拉普拉斯分布的尾部比正态分布更加平坦。[^1]
[^1]: https://zh.wikipedia.org/zh-hans/%E6%8B%89%E6%99%AE%E6%8B%89%E6%96%AF%E5%88%86%E5%B8%83
[^2]: [Why_do_cost_functions_use_the_square_error](notes/2021/2021.8/Why_do_cost_functions_use_the_square_error.md#^b7e1c9)