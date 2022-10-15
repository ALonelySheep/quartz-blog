---
title: "Softmax_Regression_is_Over-parameterized"
tags:
- all
- SoftmaxRegression
date: "2022-02-11"
---
# Softmax Regression is Over-parameterized

<div align="right"> 2022-02-11</div>

Tags: #SoftmaxRegression

Ref: [Unsupervised Feature Learning and Deep Learning Tutorial](http://deeplearning.stanford.edu/tutorial/supervised/SoftmaxRegression/)

- 将Softmax回归里面的参数全部变化一个相同的值, 结果不变:
$$\begin{aligned}
P\left(y^{(i)}=k \mid x^{(i)} ; \theta\right) &=\frac{\exp \left(\left(\theta^{(k)}-\psi\right)^{\top} x^{(i)}\right)}{\sum_{j=1}^{K} \exp \left(\left(\theta^{(j)}-\psi\right)^{\top} x^{(i)}\right)} \\
&=\frac{\exp \left(\theta^{(k) \top} x^{(i)}\right) \exp \left(-\psi^{\top} x^{(i)}\right)}{\sum_{j=1}^{K} \exp \left(\theta^{(j) \top} x^{(i)}\right) \exp \left(-\psi^{\top} x^{(i)}\right)} \\
&=\frac{\exp \left(\theta^{(k) \top} x^{(i)}\right)}{\sum_{j=1}^{K} \exp \left(\theta^{(j) \top} x^{(i)}\right)}
\end{aligned}$$

- 这就意味着一个Hypothesis可能对应多个不同的参数组合 $\theta$
- 取 $\psi=\theta^{(K)}$, 我们可以消去任意参数 $\theta^{(K)}$.

