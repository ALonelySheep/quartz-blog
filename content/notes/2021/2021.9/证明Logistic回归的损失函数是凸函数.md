---
title: "证明Logistic回归的损失函数是凸函数"
tags:
- all
- MachineLearning
- LogisticRegression
- ConvexOptimization
- CostFunction
date: "2021-09-11"
---
# 证明Logistic回归的损失函数是凸函数

<div align="right"> 2021-09-11</div>

Tags: #MachineLearning #LogisticRegression #ConvexOptimization #CostFunction 

![首先 如何证明一个函数为凸函数](notes/2021/2021.9/正则项不影响线性回归损失函数的凸性.md#首先%20如何证明一个函数为凸函数)

## 证明
### 原函数
[Part.13_Cost_Function-Logistic_Regression(ML_Andrew.Ng.)](notes/2021/2021.8/Part.13_Cost_Function-Logistic_Regression(ML_Andrew.Ng.).md)
$$\begin{aligned}
h&=g(X \theta) \\
J(\theta)&=-\frac{1}{m} \cdot\left[y^{T} \log (h)+(1-y)^{T} \log (1-h)\right]
\end{aligned}$$
### 一阶导数
在梯度下降里面我们已经求出了一阶导数了:
![推导](notes/2021/2021.8/Part.14_Logistic_Regression&Gradient_Descent(ML_Andrew.Ng.).md#推导)

### 二阶导数
$$h(x)=g\left(\theta^Tx\right) $$
$$\begin{aligned}
\frac{\partial}{\partial \theta_{j}} h(x)&=
\frac{\partial}{\partial \theta_{j}} g\left(\theta^Tx\right)\\
&=g\left(\theta^Tx\right)\left(1-g\left(\theta^Tx\right)\right) \frac{\partial}{\partial \theta_{j}} \theta^Tx\\
&=g\left(\theta^Tx\right)\left(1-g\left(\theta^Tx\right)\right)x_j\\
&=h(x)\left(1-h(x)\right)x_j
\end{aligned}$$


$$\begin{aligned}
\frac{\partial^2}{\partial \theta_{j}^2} J(\theta) 
&=\frac{\partial}{\partial \theta_{j}}\left[\frac{1}{m} \sum_{i=1}^{m}\left(h(x^{(i)})-y^{(i)}\right) x^{(i)}_{j}\right]\\
&=\frac{1}{m} \sum_{i=1}^{m}\left(\frac{\partial}{\partial \theta_{j}}h(x^{(i)})\right) x^{(i)}_{j} \\
&=\frac{1}{m} \sum_{i=1}^{m}g\left(\theta^Tx\right)\left(1-g\left(\theta^Tx\right)\right)\left(x_j^{(i)}\right)^2 \\
&=\frac{1}{m} \sum_{i=1}^{m}h(x)\left(1-h(x)\right)\left(x_j^{(i)}\right)^2
\end{aligned}$$
- 接下来判断二阶导数的负号: 对于Sigmoid函数的导函数部分, 观察函数图像, 蓝色曲线为导函数始终大于零:
[Logistic Function](notes/2021/2021.8/Sigmoid_Function.md#Logistic%20Function)
![Logistic](notes/2021/2021.7/assets/Logistic.svg)
同时$\left(x_j^{(i)}\right)^2$也非负, 所以二阶导数恒大于等于零, 函数为凸函数, 证毕.

