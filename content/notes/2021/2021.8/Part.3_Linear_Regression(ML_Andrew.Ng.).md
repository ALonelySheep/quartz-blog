---
title: "Part.3_Linear_Regression(ML_Andrew.Ng.)"
tags:
- all
- MachineLearning
- SelfLearning
date: "2021-07-31"
---
# Linear Regression

<div align="right"> 2021-07-31</div>

Tags: #MachineLearning #SelfLearning

## Model Representation
- [Supervised Learning](notes/2021/2021.8/Part.1_Supervised_Learning(ML_Andrew.Ng.).md)
- [Regression Problem](notes/2021/2021.8/Part.1_Supervised_Learning(ML_Andrew.Ng.).md#Regression)
### Structure
基于训练集, 我们希望通过学习算法得到一个Hypothesis函数$h$, 在房价预测问题上. 输入房子的大小, 得到估计的价格. 
![](notes/2021/2021.7/assets/img_2022-10-15-5.png)
对于单变量的线性回归问题(Univariate Linear Regression), 可以表现为如下形式:
$$ h_\theta(x)=\theta_1 x+\theta_0$$
其中$h_\theta$可以简记为$h$

对于训练数据:

- **A pair** $(x^{(i)} , y^{(i)} )$ is called a **training example**

- The dataset that we’ll be using to learn—**a list of m training examples** $(x^{(i)},y^{(i)})\ , (i=1,...,m)$ — is called a **training set**.


## Cost Function
损失函数是用来衡量Hypothesis function的精确度的, 损失函数可以衡量Hypothesis在整个数据集上面平均误差

下面是一个名叫"[平方误差函数/Squared Error Function/Mean Squared Error](notes/2021/2021.8/Mean_Squared_Error_均方误差.md)"的损失函数:
$$J\left(\theta_{0}, \theta_{1}\right)=\frac{1}{2 m} \sum_{i=1}^{m}\left(\hat{y}^{(i)}-y^{(i)}\right)^{2}=\frac{1}{2 m} \sum_{i=1}^{m}\left(h_{\theta}\left(x^{(i)}\right)-y^{(i)}\right)^{2}$$
分开来看, $J\left(\theta_{0}, \theta_{1}\right)$实际上是$\frac 1 2\overline{x}$, $\overline{x}$是预测值与真实值误差的平方

Link:
[Why_do_cost_functions_use_the_square_error](notes/2021/2021.8/Why_do_cost_functions_use_the_square_error.md)

### 直观感受
[Part.4_Cost_Function_Intuition](notes/2021/2021.8/Part.4_Cost_Function_Intuition(ML_Andrew.Ng.).md)

## 推广:多项式回归
- Our hypothesis function need not be linear (a straight line) if that does not fit the data well.
- We can **change the behavior or curve** of our hypothesis function by making it a quadratic, cubic or square root function (or any other form).