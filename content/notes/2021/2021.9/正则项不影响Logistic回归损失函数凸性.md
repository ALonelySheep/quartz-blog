---
title: "正则项不影响Logistic回归损失函数凸性"
tags:
- all
- MachineLearning
- LogisticRegression
- Regularization
- ConvexOptimization
- CostFunction
date: "2021-09-11"
---
# 正则项不影响Logistic回归损失函数凸性

<div align="right"> 2021-09-11</div>

Tags: #MachineLearning #LogisticRegression #Regularization #ConvexOptimization #CostFunction 

## 首先, 没有加正则项的二阶导数如下
![二阶导数](notes/2021/2021.9/证明Logistic回归的损失函数是凸函数.md#二阶导数)


## 那么只需要计算正则项的二阶导数
$$\begin{align}
J(\theta)&=P(\theta)+\frac\lambda{2m}\sum^n_{i=1}\theta_i^2
\end{align}$$

$$\begin{aligned}
\frac{\partial^2}{\partial \theta_{j}^2}
\left(\frac\lambda{2m}\sum^n_{i=1}\theta_i^2\right)&=
\frac{\lambda}{m}\frac{\partial}{\partial \theta_{j}} \theta_{j}\\
&=\frac{\lambda}{m}>0
\end{aligned}$$
所以损失函数还是凸的
