---
title: "Mean_Squared_Error_均方误差"
tags:
- all
- MachineLearning
- CostFunction
date: "2021-07-31"
---
# Mean Squared Error

<div align="right"> 2021-07-31</div>

Tags: #MachineLearning #CostFunction

Mean Square Error: 平均平方误差, 简称均方差, MSE, 又称 Mean Squared **Deviation** (MSD)

均方差的形式很简单, 但是也有许多问题值得思考
- 为什么采用平方, 而不是绝对值, 三次方等等

## StackExchange上面一个很好的解释
[Why_do_cost_functions_use_the_square_error/为什么损失函数要使用均方误差](notes/2021/2021.8/Why_do_cost_functions_use_the_square_error.md)

## 为什么MSE是合理的

> 均方误差有非常好的几何意义, 它对应了常用的**欧几里得距离**或简称"欧氏距离" (Euclidean distance). 基于均方误差最小化来进行模型求解的方法称为"最小二乘法" (least square method). 在线性回归中，最小二乘法就是试图找到一条直线，使所有样本到直线上的欧氏距离之和最小.[^1]

^0a7c67

## 为什么前面有$\frac{1}{2m}$

$$J\left(\theta_{0}, \theta_{1}\right)=\frac{1}{2 m} \sum_{i=1}^{m}\left(\hat{y}^{(i)}-y^{(i)}\right)^{2}=\frac{1}{2 m} \sum_{i=1}^{m}\left(h_{\theta}\left(x^{(i)}\right)-y^{(i)}\right)^{2}$$[Cost Function ML_Andrew.Ng.](notes/2021/2021.8/Part.3_Linear_Regression(ML_Andrew.Ng.).md#Cost%20Function)
	
The mean is halved $\left(\frac{1}{2}\right)$ as a convenience for the computation of the gradient descent, as the derivative term of the square function will cancel out the $\frac{1}{2}$ term.[^2]

Also:
[Regarding the frac1 2 term](notes/2021/2021.8/Why_do_cost_functions_use_the_square_error.md#Regarding%20the%20frac1%202%20term)

	
	
[^1]: 周志华, 机器学习, 第三章, 线性模
[^2]: 吴恩达机器学习的解释