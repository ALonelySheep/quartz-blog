---
title: "Part.14_Logistic_Regression&Gradient_Descent(ML_Andrew.Ng.)"
tags:
- all
- LogisticRegression
- GradientDescent
- MachineLearning
date: "2021-08-19"
---
# Logistic Regression & Gradient Descent

<div align="right"> 2021-08-19</div>

Tags: #LogisticRegression  #GradientDescent  #MachineLearning 

- **Gradient Descent:**
![Algorithm](notes/2021/2021.8/Part.5_Gradient_Descent(ML_Andrew.Ng.).md#Algorithm)

- **Cost Function:**
![Cost Function](notes/2021/2021.8/Part.13_Cost_Function-Logistic_Regression(ML_Andrew.Ng.).md#更简洁的形式#Cost%20Function)

## 推导
损失函数里面的$g(x)$为Logistic函数, [Logistic的导函数](notes/2021/2021.8/Sigmoid_Function.md#Logistic%20Function)为:
$$\begin{aligned}
\frac {d}{dx}g(x)&=g(x)\left(1-g(x)\right)\\
\end{aligned}$$

求偏导数$\frac{\Large\partial}{\Large\partial \Large\theta_{j}} J(\theta)$:

为了使思路清晰, 我们先计算对于一个数据点的偏导数, 即先计算求和符号的后半部分: $\frac{\Large\partial}{\Large\partial \Large\theta_{j}}  C(\theta)$, 根据导数的性质, 有$\frac{\Large\partial}{\Large\partial \Large\theta_{j}} J(\theta)=-\frac{\Large1}{\Large m} \sum_{i=1}^{m} \frac{\Large\partial}{\Large\partial \Large\theta_{j}}  C^{(i)}(\theta)$ :

$$\begin{aligned}
\frac{\partial}{\partial \theta_{j}} C(\theta) 
&=\frac{\partial}{\partial \theta_{j}}\left(\ y \log \left(h_{\theta}\left(x\right)\right)
+\left(1-y\right) \log \left(1-h_{\theta}\left(x\right)\right)\ \right)\\

&=\left(y \frac{1}{g\left(\theta^Tx\right)}-(1-y) \frac{1}{1-g\left(\theta^Tx\right)}\right) \frac{\partial}{\partial \theta_{j}} g\left(\theta^Tx\right) \\
&=\left(y \frac{1}{g\left(\theta^Tx\right)}-(1-y) \frac{1}{1-g\left(\theta^Tx\right)}\right) g\left(\theta^Tx\right)\left(1-g\left(\theta^Tx\right)\right) \frac{\partial}{\partial \theta_{j}} \theta^Tx\\
&=\left(y\left(1-g\left(\theta^Tx\right)\right)-(1-y) g\left(\theta^Tx\right)\right) x_{j} \\
&=\left(y-yg\left(\theta^Tx\right)+yg\left(\theta^Tx\right)-g\left(\theta^Tx\right)\right) x_{j} \\
&=\left(y-h_{\theta}(x)\right) x_{j}
\end{aligned}$$

(注意: 证明里面$\theta,x$均为列向量, 有所不同的是: 在上面向量化的损失函数里面, $X_{m\times n}$是每一行为一个数据)

带入所有样本点, 计算 $\frac{\Large\partial}{\Large\partial \Large\theta_{j}} J(\theta)$ :
$$\begin{aligned}
\frac{\partial}{\partial \theta_{j}} J(\theta) 
&=-\frac{1}{m} \sum_{i=1}^{m} \frac{\partial}{\partial \theta_{j}}   C^{(i)}(\theta)\\
&=\frac{1}{m} \sum_{i=1}^{m}\left(h_{\theta}(x^{(i)})-y^{(i)}\right) x^{(i)}_{j}
\end{aligned}$$

## 结果
带入梯度下降里面:
$$
\begin{array}{l}
\text { repeat until convergence }\{\\
\begin{array}{cc}
&\theta_{j}:=\theta_{j}-\alpha \frac 1 m \sum_{i=1}^{m} \left(h_{\theta}(x^{(i)})-y^{(i)}\right) x_j^{(i)} 
\end{array}\\
\text { \} }
\\\\ \text { (simultaneously update } 
j=0, \cdots ,j=n)
\end{array}
$$

向量化后的公式:
$$\theta:=\theta-\alpha\frac{1}{m} X^{T}(g(X \theta)-\vec{y})$$

- 比较Linear Regression里面的梯度下降公式: 
[Relation_Between_Linear_Regression&Gradient_Descent_梯度下降和线性回归的关系](notes/2021/2021.8/Relation_Between_Linear_Regression&Gradient_Descent_梯度下降和线性回归的关系.md)
发现是完全一样的.