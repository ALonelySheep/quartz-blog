---
title: "D2L-56-门控循环单元GRU"
tags:
- all
- GRU
- RNN
- DeepLearning
date: "2022-04-03"
---
# Gated Recurrent Units (GRU)

<div align="right"> 2022-04-03</div>

Tags: #GRU #RNN #DeepLearning 

- GRU在RNN的基础上添加了"门"(*Gate*), 针对性地解决了RNN里面存在的以下问题:
	- **长期依赖问题**: 序列早期的部分可能对未来所有观测值都有非常重要的影响, 我们需要能够保留序列早期信息的网络结构. 
		- GRU里面体现在: **重置门**减少重置, **更新门**更多地保留上一个隐状态
	- 序列里面可能有**干扰信息**, 我们需要能够跳过(遗忘)这些信息的机制
		- GRU里面体现在: **更新门**更多地保留上一个隐状态
	- 序列里面可能有**逻辑中断**, 比如一本书里面章节的变化往往会导致主题的变化. 我们需要有重置网络状态的机制.
		- GRU里面体现在: **重置门**屏蔽掉上一个隐状态


![GRU](notes/2022/2022.4/assets/GRU.svg)
## Gated Hidden State
- 门控循环单元与普通的循环神经网络之间的关键区别在于： 后者用Gate对Hidden state进行了进一步的控制。
	- 这意味着模型有专门的机制来确定应该何时更新隐状态， 以及应该何时重置隐状态。 
	- 这些机制是可学习的，并且能够解决了上面列出的问题。 
		- 例如，如果第一个词元非常重要， 模型将学会在第一次观测之后不更新隐状态。 同样，模型也可以学会跳过不相关的临时观测。 最后，模型还将学会在需要的时候重置隐状态。 

- 下面我们详细讨论两个门控:

### Reset Gate and Update Gate
![](notes/2022/2022.4/assets/gru-1.svg)
这两个门的公式都是一样的, 使用input $\mathbf{X}_{t}$ 和前一个隐状态 $\mathbf{H}_{t-1}$ 作为输入, 利用Sigmoid映射到 $(0,1)$ 区间:
$$\begin{aligned}
&\mathbf{R}_{t}=\sigma\left(\mathbf{X}_{t} \mathbf{W}_{x r}+\mathbf{H}_{t-1} \mathbf{W}_{h r}+\mathbf{b}_{r}\right) \\
&\mathbf{Z}_{t}=\sigma\left(\mathbf{X}_{t} \mathbf{W}_{x z}+\mathbf{H}_{t-1} \mathbf{W}_{h z}+\mathbf{b}_{z}\right)
\end{aligned}$$
不同的是使用它们的方式: 
- 重置门 $\mathbf{R}_{t}$ 将和上一个隐状态 $\mathbf{H}_{t-1}$ 按元素相乘 $\odot$, 相当于一个Soft的Mask, 可以控制有多少 $\mathbf{H}_{t-1}$ 用于生成候选隐状态 $\tilde{\mathbf{H}}_{t}$, 也就是控制有多少 $\mathbf{H}_{t-1}$ 被"重置"掉了(*Reset*).
	- $$\tilde{\mathbf{H}}_{t}=\tanh \left(\mathbf{X}_{t} \mathbf{W}_{x h}+\left(\mathbf{R}_{t} \odot \mathbf{H}_{t-1}\right) \mathbf{W}_{h h}+\mathbf{b}_{h}\right)$$
- 更新门$\mathbf{Z}_{t}$则被用于混合候选隐状态 $\tilde{\mathbf{H}}_{t}$和上一个隐状态 $\mathbf{H}_{t-1}$ :
$$\mathbf{H}_{t}=\mathbf{Z}_{t} \odot \mathbf{H}_{t-1}+\left(1-\mathbf{Z}_{t}\right) \odot \tilde{\mathbf{H}}_{t}$$
	- 注意最后的结果 $\mathbf{H}_{t}$ 是候选隐状态和上一个隐状态的 [凸组合 - Convex Combination](notes/2022/2022.4/凸组合%20-%20Convex%20Combination.md), 这也是为什么 $\mathbf{Z}_{t}$ 要用Sigmoid来把范围控制到 $(0,1)$ 的原因

### 候选隐状态
顾名思义, 就是用来生成结果的隐状态, 使用重置门 $\mathbf{R}_{t}$, input $\mathbf{X}_{t}$ 和前一个隐状态 $\mathbf{H}_{t-1}$ 作为输入, 使用tanh激活函数将结果映射到 $(-1,1)$ 区间:
$$\tilde{\mathbf{H}}_{t}=\tanh \left(\mathbf{X}_{t} \mathbf{W}_{x h}+\left(\mathbf{R}_{t} \odot \mathbf{H}_{t-1}\right) \mathbf{W}_{h h}+\mathbf{b}_{h}\right)$$
![](notes/2022/2022.4/assets/gru-2.svg)

### 输出隐状态
![](notes/2022/2022.4/assets/gru-3.svg)

总之，门控循环单元具有以下两个显著特征：

-   **重置门** $\mathbf{R}_{t}$ 有助于捕获序列中的**短期**依赖关系。
-   **更新门** $\mathbf{Z}_{t}$ 有助于捕获序列中的**长期**依赖关系。

