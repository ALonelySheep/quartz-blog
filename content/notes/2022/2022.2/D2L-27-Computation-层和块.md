---
title: "D2L-27-Computation-层和块"
tags:
- all
- DeepLearning
- Computation
- PyTorch
date: "2022-02-19"
---
# 深度学习计算: 使用*层* 和*块*

<div align="right"> 2022-02-19</div>

Tags: #DeepLearning #Computation #PyTorch 

- 这一章主要介绍框架的使用细节, 最好的方法就是结合代码示例, 边运行边理解. 这里我们记录一些容易忽略的要点.
	- [在线代码实例: 5.1. 层和块](https://zh-v2.d2l.ai/chapter_deep-learning-computation/model-construction.html#sec-model-construction "Permalink to this headline")
---

## 层和块: 定义
- **"层"具有三个特征:** 
	1. 接受一组输入， 
	2. 生成相应的输出，
	3. 由一组可调整参数描述。

- 事实证明，**研究讨论“比单个层大”但“比整个模型小”的组件更有价值**。 例如，在计算机视觉中广泛流行的ResNet-152架构就有数百层， 这些层是由 _**层组**_（groups of layers）的重复模式组成。
	- [我们可以自定义一个层](notes/2022/2022.2/D2L-29-Computation-自定义层.md)


- 为了实现这些复杂的网络，我们引入了神经网络 _**块**_ 的概念。 _块_（block）可以描述单个层、由多个层组成的组件或整个模型本身。
![](notes/2022/2022.2/assets/blocks.svg)
## 层和块: 实现

- 从编程的角度来看，块由 _**类**_ （class）表示。 
	- 它的任何子类都必须定义一个将其输入转换为输出的**前向传播函数**`forward()`， 并且必须存储任何必需的参数。
	- 反向传播与自动求导通常由框架自动完成.







