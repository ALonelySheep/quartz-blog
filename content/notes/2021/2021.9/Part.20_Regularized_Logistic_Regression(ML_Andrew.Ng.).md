---
title: "Part.20_Regularized_Logistic_Regression(ML_Andrew.Ng.)"
tags:
- all
- MachineLearning
- LogisticRegression
- Regularization
date: "2021-09-11"
---
# Regularized Logistic Regression

<div align="right"> 2021-09-11</div>

Tags: #MachineLearning #LogisticRegression #Regularization 

## 回顾一下没有正则化的情况
### 损失函数
[更简洁的形式](notes/2021/2021.8/Part.13_Cost_Function-Logistic_Regression(ML_Andrew.Ng.).md#更简洁的形式)
$$\begin{align}
J(\theta)
&=-\frac{1}{m} \sum_{i=1}^{m}\left[y^{(i)} \log \left(h_{\theta}\left(x^{(i)}\right)\right)+\left(1-y^{(i)}\right) \log \left(1-h_{\theta}\left(x^{(i)}\right)\right)\right]\\
\end{align}$$
or 向量化的
$$\begin{aligned}
h&=g(X \theta) \\
J(\theta)&=-\frac{1}{m} \cdot\left[y^{T} \log (h)+(1-y)^{T} \log (1-h)\right]
\end{aligned}$$
### 梯度下降公式
[结果](notes/2021/2021.8/Part.14_Logistic_Regression&Gradient_Descent(ML_Andrew.Ng.).md#结果)
$$\begin{aligned}
\frac{\partial}{\partial \theta_{j}} J(\theta) 
&=\frac{1}{m} \sum_{i=1}^{m}\left(h_{\theta}(x^{(i)})-y^{(i)}\right) x^{(i)}_{j}
\end{aligned}$$
- 是和线性回归完全一样的, 所以梯度下降公式也一样:
$$\begin{array}{l}
\text { repeat until convergence }\{\\
\begin{array}{cc}
&\theta_{j}:=\theta_{j}-\alpha \frac 1 m \sum_{i=1}^{m} \left(h_{\theta}(x^{(i)})-y^{(i)}\right) x_j^{(i)} 
\end{array}\\
\text { \} }
\\\\ \text { (simultaneously update } 
j=0, \cdots ,j=n)
\end{array}$$
---
## 正则化以后的损失函数
$$\begin{align}
J(\theta)
&=-\frac{1}{m} \sum_{i=1}^{m}
\left[y^{(i)} \log \left(h\left(x^{(i)}\right)\right)+\left(1-y^{(i)}\right) \log \left(1-h\left(x^{(i)}\right)\right)\right]
+\frac\lambda{2m}\sum^n_{i=1}\theta_i^2\\
&=P(\theta)+\frac\lambda{2m}\sum^n_{i=1}\theta_i^2
\end{align}$$
需要注意的就是正则项应该是加上去的, 原理损失函数前面的负号是为了"反转"$log$函数.

## 正则化以后的梯度下降

在计算偏导数的时候, 利用偏导数的性质, 我们只需要在最后加上正则项的偏导数即可:
$$\begin{aligned}
\frac{\partial}{\partial \theta_{j}} J(\theta) 
&=\frac{\partial}{\partial \theta_{j}}P(\theta)+
\frac\lambda{2m}\frac{\partial}{\partial \theta_{j}}\sum^n_{i=1}\theta_i^2\\
&=\frac{\partial}{\partial \theta_{j}}P(\theta)+
\frac\lambda{m}\theta_{j} \\
&=\frac{1}{m} \sum_{i=1}^{m}\left(h_{\theta}(x^{(i)})-y^{(i)}\right) x^{(i)}_{j}
+\frac\lambda{m}\theta_{j}
\end{aligned}$$
- 注意正则项在求和符号的外面

带入梯度更新公式有:
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

- 上面这部分是直接从线性回归那里拷贝过来的, 两者唯一的不同就是$h(x)$的定义不同

## 证明正则以后还是凸的
[正则项不影响Logistic回归损失函数凸性](notes/2021/2021.9/正则项不影响Logistic回归损失函数凸性.md)
