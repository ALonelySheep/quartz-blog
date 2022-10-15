---
title: "Relation_between_Softmax_and_Logistic_Regression"
tags:
- all
- SoftmaxRegression
- LogisticRegression
- Classification
- MulticlassClassification
date: "2022-02-11"
---
# Softmax 与 Logistic 回归的联系

<div align="right"> 2022-02-11</div>

Tags: #SoftmaxRegression #LogisticRegression #Classification #MulticlassClassification 

Ref: [Unsupervised Feature Learning and Deep Learning Tutorial](http://deeplearning.stanford.edu/tutorial/supervised/SoftmaxRegression/)

- 二分类的[Softmax回归](notes/2022/2022.2/D2L-13-Softmax_Regression.md)形式如下: 
$$h_{\theta}(x)=\frac{1}{\exp \left(\theta^{(1) \top} x\right)+\exp \left(\theta^{(2) \top} x^{(i)}\right)}\left[\begin{array}{c}
\exp \left(\theta^{(1) \top} x\right) \\
\exp \left(\theta^{(2) \top} x\right)
\end{array}\right]$$

- 根据: [Softmax_Regression_is_Over-parameterized](notes/2022/2022.2/Softmax_Regression_is_Over-parameterized.md), 我们可以让参数同时减去 $\psi=\theta^{(2)}$, 得到: 

$$\begin{aligned}
h(x) &=\frac{1}{\exp \left(\left(\theta^{(1)}-\theta^{(2)}\right)^{\top} x^{(i)}\right)+\exp \left(\overrightarrow{0}^{\top} x\right)}\left[\exp \left(\left(\theta^{(1)}-\theta^{(2)}\right)^{\top} x\right) \exp \left(\overrightarrow{0}^{\top} x\right)\right] \\
&=\left[\begin{array}{l}
\frac{1}{1+\exp \left(\left(\theta^{(1)}-\theta^{(2)}\right)^{\top} x^{(i)}\right)} \\
\frac{\exp \left(\left(\theta^{(1)}-\theta^{(2)}\right)^{\top} x\right)}{1+\exp \left(\left(\theta^{(1)}-\theta^{(2)}\right)^{\top} x^{(i)}\right)}
\end{array}\right] \\
&=\left[\begin{array}{c}
\frac{1}{1+\exp \left(\left(\theta^{(1)}-\theta^{(2)}\right)^{\top}
x^{(i)}\right)}\\
{1-\frac{1}{1+\exp \left(\left(\theta^{(1)}-\theta^{(2)}\right)^{\top} x^{(i)}\right)}}
\end{array}\right]
\end{aligned}$$

通过将 $\theta^{(2)}-\theta^{(1)}$ 替换为 $\theta'$, 得到
$$\begin{bmatrix}
\frac{1}{1+\exp \left(-(\theta')^{\top}
x^{(i)}\right)}\\
{1-\frac{1}{1+\exp \left(-(\theta')^{\top} x^{(i)}\right)}}
\end{bmatrix}$$
我们可以看到函数预测第一个类的概率为: 
$$\frac{1}{1+\exp \left(-(\theta')^{\top}
x^{(i)}\right)}$$
就是[Logistic回归](notes/2021/2021.8/Part.12_Logistic_Regression(ML_Andrew.Ng.).md)的情形.

第二个类的概率为
$${1-\frac{1}{1+\exp \left(-(\theta')^{\top} x^{(i)}\right)}}$$
也就是logistic回归没有表述出来的情况.