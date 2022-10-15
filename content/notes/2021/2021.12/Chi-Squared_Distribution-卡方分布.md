---
title: "Chi-Squared_Distribution-卡方分布"
tags:
- all
- Math/Statistics
date: "2021-12-04"
---
# Chi-Squared Distribution

<div align="right"> 2021-12-04</div>

Tags: #Math/Statistics 

[A very Good Website](https://www.probabilitycourse.com/chapter8/8_3_3_confidence_intervals_for_norm_samples.php)
[Chi-squared distribution - Wikipedia](https://en.wikipedia.org/wiki/Chi-squared_distribution)

## 重要结论

$Z_{1},Z_{2},\cdots,Z_{n}$ are independent standard normal random variables,

- **The Sum of independent Standard Normal Variables are still Normal:**
$$X=Z_{1}+Z_{2}+\cdots+Z_{n}$$

Link: [正态分布_高斯分布_Normal_Distribution-Gaussian_Distribution](notes/2021/2021.9/正态分布_高斯分布_Normal_Distribution-Gaussian_Distribution.md)

- 但是正态独立随机变量的**平方和**是卡方分布的:

$$Y=Z_{1}^{2}+Z_{2}^{2}+\cdots+Z_{n}^{2}$$
then $Y$ is said to have a chi-squared distribution with $n$ degrees of freedom shown by $$Y \sim \chi^{2}(n)$$

- 卡方分布其实是一种特殊的Gamma分布: $$Y\sim Gamma\left(\frac n2,\frac1 2\right)$$

- 下面是卡方分布的图像随着自由度的变化:

![The chi-Square distribution](notes/2021/2021.12/assets/The%20chi-Square%20distribution.svg)