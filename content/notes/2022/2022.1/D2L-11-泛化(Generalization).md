---
title: "D2L-11-泛化(Generalization)"
tags:
- all
- MachineLearning
- DeepLearning
date: "2022-02-08"
---
# Generalization: 泛化

<div align="right"> 2022-02-08</div>

Tags: #MachineLearning #DeepLearning 

- 线性回归恰好是一个在整个域中只有一个最小值的学习问题。 [^1]但是对于像深度神经网络这样复杂的模型来说，损失平面上通常包含多个最小值。 

- 深度学习实践者很少会去花费大力气寻找这样一组参数，使得在_训练集_上的损失达到最小。 事实上，更难做到的是找到一组参数，这组参数能够在我们从未见过的数据上实现较低的损失， 这一挑战被称为_**泛化**_（generalization）。


[^1]: 可以证明, 正则后的线性回归损失函数MSE依然是凸的: [正则项不影响线性回归损失函数的凸性](notes/2021/2021.9/正则项不影响线性回归损失函数的凸性.md)