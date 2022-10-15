---
title: "D2L-57-LSTM-长短期记忆网络"
tags:
- all
- LSTM
- DeepLearning
- RNN
date: "2022-04-18"
---
# Long Short-Term Memory

<div align="right"> 2022-04-18</div>

Tags: #LSTM #DeepLearning #RNN 

- LSTM是最早用于解决长期依赖问题的一种RNN. 它比GRU复杂, 但是设计思想是一样的. 有趣的是, LSTM(1997)比GRU(2014)早出现近20年.

- LSTM和GRU一样, 使用了不同的门(Gate)来控制上一个隐状态在下一个隐状态里面的占比, 也就是有选择地来混合"长期记忆"和"短期记忆", 这也是其名称的由来.

- 相比GRU(一种隐状态, 2个门), LSTM有两种隐状态: Cell State $\mathbf{C}_{t}$ 和Hidden State $\mathbf{H}_{t}$, 并且LSTM多一个门(3个).

## Cell State
- 相比传统的RNN, LSTM解决长期依赖的关键部分是新加入的Cell State:
![](notes/2022/2022.4/assets/img_2022-10-15-5.png)
- Cell State类似于一个传送带(Conveyor Belt), 信息在其中能够顺畅地流动. 在穿过每一个Cell的时候, 信息只有微小的改变, 这使得网络拥有了长期记忆的能力.[^1]

- 不过注意只有隐状态才会传递到输出层， 而记忆元 $\mathbf{C}_{t}$ 不直接参与输出计算。
## 3 Gates & 1 Candidate State
### 3 Gates
![](notes/2022/2022.4/assets/lstm-0.svg)
- 和GRU一样, 前一个隐状态 $\mathbf{H}_{t-1}$ 和输入 $\mathbf{X}_{t}$ Concatenate起来, 一起作为三个门的输入, 激活函数为Sigmoid:
	$$\begin{aligned}
\mathbf{I}_{t} &=\sigma\left(\mathbf{X}_{t} \mathbf{W}_{x i}+\mathbf{H}_{t-1} \mathbf{W}_{h i}+\mathbf{b}_{i}\right) \\
\mathbf{F}_{t} &=\sigma\left(\mathbf{X}_{t} \mathbf{W}_{x f}+\mathbf{H}_{t-1} \mathbf{W}_{h f}+\mathbf{b}_{f}\right) \\
\mathbf{O}_{t} &=\sigma\left(\mathbf{X}_{t} \mathbf{W}_{x o}+\mathbf{H}_{t-1} \mathbf{W}_{h o}+\mathbf{b}_{o}\right)
\end{aligned}$$
### 1 Candidate State
- 和GRU不一样的是: Candidate Cell State直接接受前一个隐状态 $\mathbf{H}_{t-1}$ 和输入 $\mathbf{X}_{t}$ 作为输入, 而不是先进行"Reset/遗忘"操作:
![](notes/2022/2022.4/assets/lstm-1.svg)
$$\tilde{\mathbf{C}}_{t}=\tanh \left(\mathbf{X}_{t} \mathbf{W}_{x c}+\mathbf{H}_{t-1} \mathbf{W}_{h c}+\mathbf{b}_{c}\right)$$
### Update Cell State
![](notes/2022/2022.4/assets/Pasted%20image%2020220418183027.png)
对上一个Cell State $\mathbf{C}_{t-1}$ 的更新分为两步:

#### Forget using Forget Gate
$$\mathbf{C}_{t}=\textcolor{darkorchid}{\mathbf{F}_{t} \odot \mathbf{C}_{t-1}}+\mathbf{I}_{t} \odot \tilde{\mathbf{C}}_{t}$$
与Forget Gate按元素相乘，屏蔽掉需要忘记的元素。

#### Merge new Candidate State
$$\mathbf{C}_{t}=\mathbf{F}_{t} \odot \mathbf{C}_{t-1}\textcolor{orangered}{+\mathbf{I}_{t} \odot \tilde{\mathbf{C}}_{t}}$$
先将候选Cell State与Input Gate按元素相乘得到需要更新的位置，再和遗忘后的结果相加。

### Output new Hidden State
其实 $\mathbf{H}_{t}$ 只是 $\mathbf{C}_{t}$ 的门控版本: 先利用tanh调整大小范围到 $(-1,1)$, 再使用Output Gate Mask一遍:
$$\mathbf{H}_{t}=\mathbf{O}_{t} \odot \tanh \left(\mathbf{C}_{t}\right)$$
![](notes/2022/2022.4/assets/lstm-3.svg)

## Variants of LSTM
### Peepholes
All gates can have a peep at the cell state $\mathbf{C}_{t-1}$.
![](notes/2022/2022.4/assets/LSTM3-var-peepholes.png)

### Convex Combination[^2] (coupled forget and input gates) 
Forget to remember, remember to forget. The total amount of information stays the same.
![](notes/2022/2022.4/assets/LSTM3-var-tied.png)
### GRU
[D2L-56-门控循环单元GRU](notes/2022/2022.4/D2L-56-门控循环单元GRU.md)




[^1]: [Understanding LSTM Networks -- colah's blog](https://colah.github.io/posts/2015-08-Understanding-LSTMs/) Many pics in this article is from colah's blog.
[^2]: [凸组合 - Convex Combination](notes/2022/2022.4/凸组合%20-%20Convex%20Combination.md)