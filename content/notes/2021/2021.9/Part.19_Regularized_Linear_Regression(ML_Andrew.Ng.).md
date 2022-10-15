---
title: "Part.19_Regularized_Linear_Regression(ML_Andrew.Ng.)"
tags:
- all
- MachineLearning
- Regularization
- GradientDescent
- LinearRegression
- NormalEquation
date: "2021-09-10"
---
# Regularization & Linear Regression

<div align="right"> 2021-09-10</div>

Tags: #MachineLearning #Regularization #GradientDescent #LinearRegression #NormalEquation 

## Regularization & Gradient Descent
添加了正则项之后有两点需要注意:
- $\theta_0$需要单独处理 (不需要正则约束, 损失函数不一样)
- $\theta_1 \sim \theta_n$ 因为需要正则化, 损失函数$J(\theta)$发生了变化, 梯度需要重新计算
- [正则项不影响线性回归损失函数的凸性](notes/2021/2021.9/正则项不影响线性回归损失函数的凸性.md)

同时考虑上面两点, 梯度下降更新公式变为了: 

$$
\begin{aligned}
Re&peat\ \{\\
&\theta_{0}:=\theta_{0}-\alpha \frac{1}{m} \sum_{i=1}^{m}\left(h_{\theta}\left(x^{(i)}\right)-y^{(i)}\right) x_{0}^{(i)} \\
&\theta_{j}:=\theta_{j}-\alpha\left[ \frac{1}{m} \sum_{i=1}^{m}
\left(h_{\theta}\left(x^{(i)}\right)-y^{(i)}\right) x_{j}^{(i)}+\frac{\lambda}{m} \theta_{j}\right]
\quad\quad j \in\{1,2 \ldots n\}
\\ \}
\end{aligned}
$$
要是把方括号打开, 第二行的更新公式可以变为:
$$
\theta_{j}:=\theta_{j}\left(1-\alpha\frac\lambda m\right)
-\alpha\frac{1}{m} \sum_{i=1}^{m}
\left(h_{\theta}\left(x^{(i)}\right)-y^{(i)}\right) x_{j}^{(i)}
\quad\quad j \in\{1,2 \ldots n\}
$$
因为$\left(1-\alpha\frac\lambda m\right)$一定小于1, 所以这个更新公式每次都会缩小一点点$\theta_i$, 而公式的后半部分和没有正则化的公式是完全一样的.


## Regularization & Normal Equation
- 没有正则化的公式:	
$$
	\theta=\left(X^{T} X\right)^{-1} X^{T} \vec{y}	
$$
([Definition](notes/2021/2021.8/Part.9_Normal_Equation(ML_Andrew.Ng.).md#Definition))

- 加入正则项以后: 

$$\begin{aligned}
&\theta=(X^{T} X+\lambda \cdot L)^{-1} X^{T} \vec y \\
&\text { where } L=\left[\begin{array}{cccc}
0 & & & & \\
& 1 & & & \\
& & 1 & & \\
& & & \ddots & \\
& & & & 1
\end{array}\right]_{(n+1)\times(n+1)}
\end{aligned}$$

^72311a

$L$的第一个0可以理解为不用正则化$\theta_0$

- 在没有正则化以前$(X^{T} X+\lambda \cdot L)$可能不可逆, 但是正则化以后是一定可逆的:
	证明:[[notes/2021/2021.9/正则项会消除正规方程法可能的不可逆性]] 


