---
title: "Part.28_Cost_Function-Neural_Network(ML_Andrew.Ng.)"
tags:
- all
- MachineLearning
- NeuralNetwork
- CostFunction
date: "2021-10-09"
---
# Cost Function - Neural Network

<div align="right"> 2021-10-09</div>

Tags: #MachineLearning #NeuralNetwork #CostFunction 

## Basic Concepts
![](notes/2021/2021.10/assets/img_2022-10-15-64.png)
$$\left\{\left(x^{(1)}, y^{(1)}\right),
\left(x^{(2)}, y^{(2)}\right), \ldots,
\left(x^{(m)}, y^{(m)}\right)\right\}$$

- $m$: Number of **Training Samples** - 训练样本数
- $L$: Total Number of **Layers** in the network - 网络层数
- $s_{l}$ =no. of **units** (not counting bias unit) in  layer - 每一层激活单元数（不包括常数）

## Cost Function: Representation
神经网络用来分类的时候，它的损失函数可以通过对Logistic Regression的损失函数稍加改造来得到：

### 回顾Cost Function of Logistic Regression (With Regularization)
![正则化以后的损失函数](notes/2021/2021.9/Part.20_Regularized_Logistic_Regression(ML_Andrew.Ng.).md#正则化以后的损失函数)

### Intuition of the relation
- 回顾前面我们提到过的神经网络与Logistic回归的联系：
![与Logistic Regression的联系](notes/2021/2021.9/Part.23_Forward_Propagation-Neural_Network(ML_Andrew.Ng.).md#与Logistic%20Regression的联系)

- 在Output Layer, 

![](notes/2021/2021.10/assets/Pasted%20image%2020211009210215.png)


