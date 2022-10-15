---
title: "VC维-VC_Dimension"
tags:
- all
- DeepLearning
- StatisticalLearning
date: "2022-02-12"
---
# Vapnik–Chervonenkis dimension

<div align="right"> 2022-02-12</div>

Tags: #DeepLearning #StatisticalLearning

- 在VC理论中，VC维是对一个可学习分类函数空间的能力（复杂度，表示能力等）的衡量。它定义为算法能“打散”的点集的势的最大值。

- 对于线性分类器: 

![](notes/2022/2022.2/assets/img_2022-10-15-30.png)

- VC维可以衡量训练误差和泛化误差的间隔, 但是在深度学习中, 我们很难计算一个模型的VC维