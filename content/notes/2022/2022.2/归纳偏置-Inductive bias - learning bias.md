---
title: "归纳偏置-Inductive bias - learning bias"
tags:
- all
- DeepLearning
- MachineLearning
date: "2022-02-26"
---
# Inductive Bias - 归纳偏置 / 归纳偏好

<div align="right"> 2022-02-26</div>

Tags: #DeepLearning #MachineLearning 


- 当学习器去预测其未遇到过的输入的结果时，会做一些假设（Mitchell, 1980）。而学习算法中的归纳偏置（Inductive bias）则是这些假设的集合。[^1]

- 一个典型的归纳偏置例子是[奥卡姆剃刀](https://zh.wikipedia.org/wiki/%E5%A5%A7%E5%8D%A1%E5%A7%86%E5%89%83%E5%88%80 "奥卡姆剃刀")，它假设最简单而又一致的假设是最佳的。这里的一致是指学习器的假设会对所有样本产生正确的结果。

[^1]: Machine Learning - Mitchell Chapter 2.7 