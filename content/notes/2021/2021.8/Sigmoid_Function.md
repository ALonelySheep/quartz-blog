---
title: "Sigmoid_Function"
tags:
- all
- Sigmoid
- MachineLearning
- ActivationFunction
date: "2021-08-19"
---
# Sigmoid Function

<div align="right"> 2021-08-19</div>

Tags: #Sigmoid #MachineLearning #ActivationFunction

## 什么是Sigmoid函数?
- [Sigmoid的含义是](notes/2021/2021.8/Sigmoid-Definition.md)像S型的, 所以Sigmoid函数便是具有S形状的一类函数.

- Sigmoid函数把整个实数域上的任意数映射到一个有限的区间里面: $(0,1)$
- 在分类问题里面,  it's useful for transforming an arbitrary-valued function into a function better suited for classification.

## Logistic Function
- 逻辑斯蒂函数是Sigmoid函数之一.
$$S(x)=\frac{1}{1+e^{-x}}=\frac{e^{x}}{e^{x}+1}=1-S(-x)$$

![](notes/2021/2021.7/assets/img_2022-10-15-25.png)
下图中蓝色曲线为导函数
$$\frac {d}{dx}S(x)=\frac{e^{-x}}{(1+e^{-x})^2}
=\left(\frac{1}{1+e^{-x}}\right)\left(1-\frac{1}{1+e^{-x}}\right)=S(x)\left(1-S(x)\right)$$
![](notes/2021/2021.7/assets/Logistic.svg)

![](notes/2021/2021.8/assets/derivative%20Sigmoid.png)