---
title: "内积和相关性的联系-Dot(Inner)_Product_&_Correlation"
tags:
- all
- Math
- InnerProduct
date: "2021-11-16"
---
# Inner Product & Correlation

<div align="right"> 2021-11-16</div>

Tags: #Math #InnerProduct

Source: [David Joyce's answer to Is there any relation between 'correlation of two signals' and 'dot product of two vectors'? - Quora](https://qr.ae/pGmGkx)

## Original Version

### Q: Is there any relation between 'correlation of two signals' and 'dot product of two vectors'?

**Answer:**
Yes, there is a connection between correlation and dot products (also called inner products).

Consider the vector space of real-valued random variables. These random variables don't have to be independent, so they may have a covariance

$$X \cdot Y=\operatorname{Cov}(X, Y)=E\left(\left(X-\mu_{X}\right)\left(Y-\mu_{Y}\right)\right)$$

Covariance is bilinear, so it can be used to define an inner product on the vector space of random variables making it an inner product space.

With an inner product, you can define the norm of a vector (also called the length of the vector by as the square root of the inner product with itself. So $\|X\|=\sqrt{X \cdot X}$ is defined as the square root of $\operatorname{Cov}(X, X)=E\left(\left(X-\mu_{X}\right)^{2}\right)$. This norm is the standard deviation $\sigma_{X}$ of $X$.

The correlation of two random variables is defined by
$$
\rho_{X Y}=\frac{\operatorname{Cov}(X, Y)}{\sigma_{X} \sigma_{Y}}
$$

That is precisely the definition of the the cosine of the angle $θ$ between two vectors

$$
\cos \theta=\frac{X \cdot Y}{\|X\|\|Y\|}
$$

In summary, covariance is an inner product, standard deviations are norms, and correlations are cosines of angles.


## Translation - 翻译

### 问题: "相关度"和"内积"这两个概念之间有什么联系吗? 

答: 的确, 相关度和内积(也叫做点积)之间有着一定的联系.

考虑一个由实数随机变量组成的向量空间. 这些随机变量之间不一定是相互独立的, 它们的协方差由下面这个式子给出:

$$X \cdot Y=\operatorname{Cov}(X, Y)=E\left(\left(X-\mu_{X}\right)\left(Y-\mu_{Y}\right)\right)$$

协方差是一个双线性函数, 所以它能够在实数随机变量组成的向量空间里面定义一个内积, 使其成为内积空间.

有了内积空间, 我们便能定义一个向量的范数(也就是向量的长度, 即一个向量与其自身内积的平方根): $\|X\|=\sqrt{X \cdot X}$ . 而这个定义下的内积也是协方差 $\operatorname{Cov}(X, X)=E\left(\left(X-\mu_{X}\right)^{2}\right)$ 的平方根. 即随机变量 $X$ 的标准差 $\sigma_{X}$.

两个随机变量之间的相关度的定义如下:
$$
\rho_{X Y}=\frac{\operatorname{Cov}(X, Y)}{\sigma_{X} \sigma_{Y}}
$$
而这正是两个变量之间夹角 $\theta$ 的余弦的定义:
$$
\cos \theta=\frac{X \cdot Y}{\|X\|\|Y\|}
$$
总之, 协方差等价于内积, 标准差等价于范数, 而相关度等价于夹角的余弦值. (余弦相似度)