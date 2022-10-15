---
title: "协方差矩阵_Covariance_Matrix"
tags:
- all
- Matrix
- Math/Statistics
date: "2021-10-29"
---
# Covariance Matrix

<div align="right"> 2021-10-29</div>

Tags: #Matrix #Math/Statistics 


https://janakiev.com/blog/covariance-matrix/


## Variance, Covariance 

- **Variance** measures the variation of a single random variable (like height of a person in a population)
	$$\sigma_{x}^{2}=\mathbb E \left(\frac{1}{n-1} \sum_{i=1}^{n}\left(x_{i}-\bar{x}\right)^{2}\right)$$
	Link: [为什么方差的分母常常是n-1](notes/2021/2021.10/为什么方差的分母常常是n-1.md)
	
- Whereas **[covariance](notes/2021/2021.12/Covariance-协方差.md)** is a measure of **how much two random variables vary together** (like the height of a person and the weight of a person in a population)
	$$\sigma(x, y)=\mathbb E\left(\frac{1}{n-1} \sum_{i=1}^{n}\left(x_{i}-\bar{x}\right)\left(y_{i}-\bar{y}\right)\right)$$

所以方差也可以看作一个随机变量自己与自己的协方差:
$$\sigma_{x}^{2} = \frac{1}{n-1} \sum_{i=1}^{n}(x_{i}-\bar{x})(x_{i}-\bar{x}) = \sigma(x, x)$$

## 协方差矩阵
[Wikipedia](https://zh.wikipedia.org/zh-hans/%E5%8D%8F%E6%96%B9%E5%B7%AE%E7%9F%A9%E9%98%B5):

假设$X$是以$n$个随机变量组成的列向量，

$\mathbf{X} = \begin{bmatrix} X_1 \\ X_2 \\ \vdots \\ X_n \end{bmatrix}$

并且$\mu_i$是$X_i$的期望值，即, $\mu_i = \mathrm{E}(X_i)$。协方差矩阵的第$(i,j)$項（第$(i,j)$項是一个协方差）被定义为如下形式：

$$\Sigma_{ij}
= \mathrm{cov}(X_i, X_j) = \mathrm{E}\begin{bmatrix}
(X_i - \mu_i) (X_j - \mu_j)
\end{bmatrix}$$

而协方差矩阵为：

$$\Sigma=\mathrm{E}
\left[
 \left(
 \mathbf{X} - \mathrm{E}[\mathbf{X}]
 \right)
 \left(
 \mathbf{X} - \mathrm{E}[\mathbf{X}]
 \right)^{\rm T}
\right]$$


$$=
\begin{bmatrix}
 \mathrm{E}[(X_1 - \mu_1)(X_1 - \mu_1)] & \mathrm{E}[(X_1 - \mu_1)(X_2 - \mu_2)] & \cdots & \mathrm{E}[(X_1 - \mu_1)(X_n - \mu_n)] \\ \\
 \mathrm{E}[(X_2 - \mu_2)(X_1 - \mu_1)] & \mathrm{E}[(X_2 - \mu_2)(X_2 - \mu_2)] & \cdots & \mathrm{E}[(X_2 - \mu_2)(X_n - \mu_n)] \\ \\
 \vdots & \vdots & \ddots & \vdots \\ \\
 \mathrm{E}[(X_n - \mu_n)(X_1 - \mu_1)] & \mathrm{E}[(X_n - \mu_n)(X_2 - \mu_2)] & \cdots & \mathrm{E}[(X_n - \mu_n)(X_n - \mu_n)]
\end{bmatrix}$$

矩阵中的第$(i,j)$个元素是$X_i$与$X_j$的协方差

## 进一步

矩阵的奇异值分解可以将数据还原为普通的形式, 这在LDA等许多算法中都有应用
进一步可以阅读以下文章:
https://janakiev.com/blog/covariance-matrix/