---
title: "Part.8_Train_Gradient_Descent(ML_Andrew.Ng.)"
tags:
- all
- GradientDescent
- MachineLearning
date: "2021-08-06"
---
# Train Gradient Descent

<div align="right"> 2021-08-06</div>

Tags: #GradientDescent #MachineLearning 

## 判断收敛(Convergence)的方法

- 画出Cost Function - Iteration图, 平缓后收敛
- 相邻周期变化值小于一个很小的值$\Delta$

## 寻找正常的学习率
- 只要学习率$\alpha$足够小, 损失函数一定是递减的(可以严格证明)
- 如果学习率波动或者递增, 常常是因为学习率过大
- 学习率过大也有一定几率导致收敛缓慢
- 学习率过小会导致收敛过慢
- 合适的方法是类似于二分法的思路, 用一系列的值去尝试, 
	e.g. $0.001, 0.003, 0.006, 0.01\cdots$

