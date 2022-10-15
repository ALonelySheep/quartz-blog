---
title: "Cross Validation"
tags:
- all
- MachineLearning
date: "2021-12-19"
---
# Cross Validation

<div align="right"> 2021-12-19</div>

Tags: #MachineLearning 

- 交叉验证是一种评价模型好坏的方法.
- 设置验证集的目的在于减少样本给模型带来的Bias, 即我们想要找到一个普遍适用的模型, 而不是只在训练集上表现很好的模型.
	- 交叉验证是一种增大验证集, 充分利用数据的方法.


## 交叉验证的方法
- [Cross-validation (statistics) - Wikipedia](https://en.wikipedia.org/wiki/Cross-validation_(statistics)#k-fold_cross-validation)
- [Machine Learning Fundamentals: Cross Validation - YouTube](https://www.youtube.com/watch?v=fSytzGwwBVw)

简单的来说, 交叉验证会把训练集随机分成几个部分. 每次选一小部分当作测试集(Validation Set). 一共训练多个模型, 综合所有结果评价模型的好坏.

## 交叉验证的用处
- 交叉验证可以用来:
	- 对于同一个问题, 选出表现最好的模型
	- 对于同一个模型, 选出最好的参数.

## 交叉验证的分类
交叉验证大致可以分为两类: Exhaustive & Non-exhaustive
- Exhaustive方法的训练次数很多, 每次只用几个样本来测试模型, 这种方法通常被称作 Leave-p-Out Cross Validation, 即每次只leave out p 个样本用来测试
![LOOCV|350](notes/2021/2021.12/assets/img_2022-10-15.gif)
- Non-exhaustive 方法的训练次数更少, 测试集更大, 比如K折交叉验证(K-Fold Cross Validation)就是把样本分成K个部分, 每次舍弃一个作为测试集, 一共训练K个模型.
![KfoldCV|400](notes/2021/2021.12/assets/img_2022-10-15-1.gif)


## 交叉验证会生成一堆模型吗?
不会, The purpose of cross-validation is model checking, not model building.[^1] 在交叉验证之后, 我们会用所有的数据作为训练集来训练一个最终的模型.

- 这个回答写的非常好:  [How to choose a predictive model after k-fold cross-validation? - Cross Validated](https://stats.stackexchange.com/a/52277/354372)

[^1]: [How to choose a predictive model after k-fold cross-validation? - Cross Validated](https://stats.stackexchange.com/a/52277/354372)