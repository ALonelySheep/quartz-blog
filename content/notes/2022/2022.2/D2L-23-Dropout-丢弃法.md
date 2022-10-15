---
title: "D2L-23-Dropout-丢弃法"
tags:
- all
- Dropout
- Regularization
- DeepLearning
date: "2022-02-14"
---
# Dropout - 丢弃法(暂退法)

<div align="right"> 2022-02-14</div>

Tags: #Dropout #Regularization #DeepLearning 

<iframe width="560" height="315" src="https://www.youtube.com/embed/drT5_1TCYrk" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>

[^1]

- Dropout就是在前向传播过程计算每一内部层的同时注入噪声, 从而提高模型的平滑性, 减少过拟合.

![](notes/2022/2022.2/assets/dropout2.svg)

## 实现方式
- 实现的关键是要以一种无偏(不改变期望)的方式注入噪声.

- 在毕晓普的工作中，他将**高斯噪声**添加到线性模型的输入中。 在每次训练迭代中，他将从均值为零的分布 $ϵ∼\mathcal{N}(0,σ^2)$ 采样噪声添加到输入 $\mathbf{x}$， 从而产生扰动点 $\mathbf{x^′=x}+ϵ$， 预期是 $E[\mathbf{x^′}]=\mathbf{x}$ 。

- 但是我们更常用的方式是按一定概念 $p$ 对隐藏层的输出置零, 换言之，每个中间活性值 $h$ 以 _暂退概率_ $p$ 由随机变量 $h^′$ 替换，如下所示：
$$h^{\prime}= \begin{cases}0 & \text { 概率为 } p \\ \frac{h}{1-p} & \text { 其他情况 }\end{cases}$$
根据此模型的设计, 其期望值保持不变, 即 $$E\left[h^{\prime}\right]=h$$

- 前向传播时, 输出的计算不再依赖于被丢弃的变量; 在反向传播时, 被丢弃的变量梯度为0, 不参与参数的优化更新. 这使得输出层的计算不能过分的依赖于隐藏层中的任何一个元素.

### 测试时
- 通常，我们在测试时不用暂退法。 给定一个训练好的模型和一个新的样本，我们不会丢弃任何节点，因此不需要标准化。 

- 然而也有一些例外：一些研究人员在测试时使用暂退法， 用于估计神经网络预测的“不确定性”： 如果通过许多不同的暂退法遮盖后得到的预测结果都是一致的，那么我们可以说网络发挥更稳定。(换言之, 各个部分都是一样重要的, 丢弃了任何一部分影响都是一样的)[^3]

### 适用对象
- Dropout主要应用于全连接层

## Bonus
- 既然是随机丢弃, 那么有没有可能某一层全部被丢完了呢? 
[neural networks - What if all the nodes are dropped when using dropout? - Cross Validated](https://stats.stackexchange.com/questions/302452/what-if-all-the-nodes-are-dropped-when-using-dropout)

- Loss map with drop out - Visualized[^2]
<iframe width="560" height="315" src="https://www.youtube.com/embed/2PqTW_p1fIs" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>

- Dropout被Google申请了专利🤐.



[^1]: [Dropout (DEF 0075) - YouTube](https://www.youtube.com/watch?v=drT5_1TCYrk)
[^2]: [DROP | Dropout variations in weight space | Loss landscape visualization | Deep Learning - YouTube](https://www.youtube.com/watch?v=2PqTW_p1fIs)
[^3]: [4.6. 暂退法（Dropout） — 动手学深度学习 2.0.0-beta0 documentation](https://zh-v2.d2l.ai/chapter_multilayer-perceptrons/dropout.html#id5)