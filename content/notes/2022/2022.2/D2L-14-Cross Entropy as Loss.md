---
title: "D2L-14-Cross Entropy as Loss"
tags:
- all
- CostFunction
- DeepLearning
- CrossEntropy
date: "2022-02-11"
---
# 交叉熵作为损失函数

<div align="right"> 2022-02-11</div>

Tags: #CostFunction  #DeepLearning  #CrossEntropy 

- 在作为损失函数的时候, 构成[交叉熵](notes/2022/2022.2/Cross_Entropy-交叉熵.md)的概率分布为:
	- 真实分布: $P^*$
	- 模型输出: $P$

![450](notes/2022/2022.2/assets/img_2022-10-15-10.png)
- 作为损失函数, 交叉熵的作用是 **衡量模型输出与真实值的差距**, 作为优化算法的优化对象, 还需要尽量简洁, 减少训练模型的开销.

## 为什么交叉熵可以衡量输出与真实值的差别?
- 我们由[KL_Divergence](notes/2022/2022.2/KL_Divergence-KL散度.md)一节知道, KL散度可以作为衡量两个分布差距的指标: KL散度越接近0, 两个分布的相似度越高. 

- 我们可以证明: 最小化 $D_{KL}(P^*||P)$ 的过程, 就是最小化 $H(P^*|P)$ 的过程: 

证明视频阐述得非常好 `(2:39)` : 
<iframe width="560" height="315" src="https://www.youtube.com/embed/Pwgpl9mKars" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write;  gyroscope; picture-in-picture" allowfullscreen></iframe>

- Reference: [Intuitively Understanding the Cross Entropy Loss - YouTube](https://www.youtube.com/watch?v=Pwgpl9mKars)

- **重点:** 
	- 交叉熵和KL散度有这样的关系: 
		$$H(p, q) = H(p) + D_{\mathrm{KL}}(p \parallel q)$$
		也就是说: KL散度 (相对熵) = 交叉熵 - 信息熵	
		- 由于信息熵描述的是消除 $p$ (即真实分布) 的不确定性所需信息量的度量，所以其值应该是最小的、固定的。那么：**优化减小相对熵也就是优化交叉熵，所以在机器学习中使用交叉熵就可以了。**

## Cross Entropy与Softmax
**为什么经常看到Cross Entropy和Softmax在一起?**
- 利用交叉熵作为损失函数的时候, 要求模型的输出 $P$ 是一个概率分布, 而Softmax的作用就是将模型的"直接输出"转化为"概率输出".

	- 模型的直接输出又称为 "[Logit](notes/2022/2022.2/Logit.md)"(至少在深度学习里面)

## 详细推导
- 假设一共有 $K$ 个类别, 令 $\mathbf{y}$ 为真实标签([One-hot编码](notes/2022/2022.1/One-hot_Encoding-独热编码.md), 只有 ${y}_k=1$), $\mathbf{\hat y}$ 为 Softmax 模型预测的输出[^2], $\mathbf{o}$ 表示 logits(Softmax 层的输入).
- 先参考一下交叉熵的定义:
	[Cross Entropy - 交叉熵](notes/2022/2022.2/Cross_Entropy-交叉熵.md#Cross%20Entropy%20-%20交叉熵)
- 损失函数是交叉熵 $H(\mathbf{y}, \mathbf{\hat y})$ :
$$\begin{aligned}
L(\mathbf{y},\hat{\mathbf{y}}) &=\sum_{j=1}^K {y}_j \log \frac{1}{\hat{y}_j} \\ &=-\sum_{j=1}^K {y}_j \log{\hat{y}_j}\\
&=-\sum_{j=1}^K {y}_j \log{\frac{\exp \left(o_{j}\right)}{\sum_{i=1}^{K} \exp \left(o_{i}\right)}}\\
(\text{独热编码,只有}{y}_k\text{为}1)&=-\log{\frac{\exp \left(o_{k}\right)}{\sum_{i=1}^{K} \exp \left(o_{i}\right)}}\\
&=-\log \hat{y}_k
\end{aligned}$$
- 其实就是预测概率 $\hat{y}_k$ 的负对数, 其中 $k$ 对应真实标签 ${y}_k$ 

- 接下来求 $L(\mathbf{y}, \hat{\mathbf{y}})$ 对于Softmax层输入Logit $o_p$ 的导数: 
$$\begin{aligned}\frac{\partial}{\partial o_p}L(\mathbf{y}, \hat{\mathbf{y}})&=-\frac{\partial}{\partial o_p}\left(\log{\frac{\exp \left(o_{k}\right)}{\sum_{i=1}^{K} \exp \left(o_{i}\right)}}\right)\\
&=-\frac{\partial}{\partial o_p}\left(o_{k}-{\sum_{i=1}^{K} \exp \left(o_{i}\right)}\right)
\\
&=\begin{cases}
  \frac{\partial}{\partial o_p}\sum_{i=1}^{K} \exp \left(o_{i}\right)-1 & \text{when }p=k\\    
  \frac{\partial}{\partial o_p}\sum_{i=1}^{K} \exp \left(o_{i}\right)-0 & \text{when }p\neq k
\end{cases}\\
&=\frac{\partial}{\partial o_p}\sum_{i=1}^{K} \exp \left(o_{i}\right)-{y}_p\\   
&=\frac{\exp{o_p}}{\sum_{i=1}^{K} \exp (o_{i})}-{y}_p\\&=\operatorname{Softmax}(\mathbf{o})_p-{y}_p
\end{aligned}$$

其中 $\mathbf{o=W^T X+b}$

- 可以看到这个导数十分简单, 就是模型输出的概率值 $\operatorname{Softmax}(\mathbf{o})_p$ 减去真实的概率值 ${y}_p$.[^1]

### 另一种推导
这里给出另一种推导方式:
$$\begin{aligned}

L(\mathbf{y}, \hat{\mathbf{y}}) &=-\sum_{j=1}^{K} {y}_{j} \log \frac{\exp \left(o_{j}\right)}{\sum_{i=1}^{K} \exp \left(o_{i}\right)} \\

(\text{将负号移进去})&=\quad\sum_{j=1}^{K} {y}_{j} \log \frac{\sum_{i=1}^{K} \exp \left(o_{i}\right)}{\exp \left(o_{j}\right)} \\

&=\sum_{j=1}^{K} {y}_{j} \log \sum_{i=1}^{K} \exp \left(o_{i}\right)-\sum_{j=1}^{K} {y}_{j} o_{j} \\

(\text{独热编码,只有一个}{y}_j\text{为}1)&=\log \sum_{i=1}^{K} \exp \left(o_{i}\right)-\sum_{j=1}^{K} {y}_{j} o_{j} .

\end{aligned}$$
- 上面的推导里面, 并没有把后半部分的${y}_j$消去, 这使得下面求偏导不用分类讨论:

- 我们求 $L(\mathbf{y}, \hat{\mathbf{y}})$ 对于Softmax层输入 $o_p$ 的导数:
$$\begin{aligned}\frac{\partial}{\partial o_p}L(\mathbf{y}, \hat{\mathbf{y}})&=\frac{\exp{o_p}}{\sum_{i=1}^{K} \exp (o_{i})}-{y}_p\\&=\operatorname{Softmax}(\mathbf{o})_p-{y}_p
\end{aligned}$$

## 对比交叉熵与均方误差
[为什么Softmax回归不用MSE](notes/2022/2022.2/为什么Softmax回归不用MSE.md)

## PyTorch的Cross Entropy Loss包括Softmax
> - `class torch.nn.CrossEntropyLoss(weight=None, size_average=True)`
> - 此标准将`LogSoftMax`和`NLLLoss`集成到一个类中。当训练一个多类分类器的时候，这个方法是十分有用的。

- [torch.nn - PyTorch中文文档](https://pytorch-cn.readthedocs.io/zh/latest/package_references/torch-nn/)
- [CrossEntropyLoss — PyTorch 1.10 documentation](https://pytorch.org/docs/stable/generated/torch.nn.CrossEntropyLoss.html)

- PyTorch 的实现还需要考虑一个 Batch 里面的多组数据, 所以比较难懂.
- 假设一个 Batch 由 $N$ 组数据组成, 则我们可以对一个 Batch 的 $N$ 个损失进行三种操作:
	- 取平均
	- 求和
	- 什么也不做
- 上面三种操作分别对应 `reduction='mean', 'sum', 'none'`, 默认 `reduction='mean'`

### `reduction='none'`
$$\ell(x, y)=L=\left\{l_{1}, \ldots, l_{N}\right\}^{\top}, \quad l_{n}=-w_{y_{n}} \log \frac{\exp \left(x_{n, y_{n}}\right)}{\sum_{c=1}^{C} \exp \left(x_{n, c}\right)} \cdot 1\left\{y_{n} \neq \text { ignore\_index }\right\}$$
- 在上面的式子里面, $\ell(x, y)=L=\left\{l_{1}, \ldots, l_{N}\right\}^{\top}$ 的意思是: 一个 Batch 里面有 $N$ 组数据, 而输出是这 $N$ 组损失组成的一个向量.
- $w_{y_{n}}$ 用于对不同类别的损失进行加权, 这常常在类别数据不平衡的时候使用.
- $\cdot 1\left\{y_{n} \neq \text { ignore\_index }\right\}$ 表示忽略 $y_{n} = \text { ignore\_index }$ 的类别 

### `reduction='sum', 'mean'`
$$\ell(x, y)= \begin{cases}\sum_{n=1}^{N} \frac{1}{\sum_{n=1}^{N} w_{y_{n}} \cdot 1\left\{y_{n} \neq \text { ignore\_index }\right\}}l_{n}, & \text { if reduction }=\text { 'mean'; } \\ \sum_{n=1}^{N} l_{n}, & \text { if reduction }=\text { 'sum' }\end{cases}$$

## 需要把标签 one-hot 之后再输入到损失函数里面吗?
[Cross_Entropy_Loss_Input_Format-交叉熵损失函数输入格式](notes/2022/2022.5/Cross_Entropy_Loss_Input_Format-交叉熵损失函数输入格式.md)



[^1]:教材里面说: 这不是巧合，在任何指数族分布模型中 （参见[本书附录中关于数学分布的一节](https://d2l.ai/chapter_appendix-mathematics-for-deep-learning/distributions.html) ）， 对数似然的梯度正是由此得出的。 这使梯度计算在实践中变得容易很多。 但是我还是不是很理解这里什么意思. https://zh-v2.d2l.ai/chapter_linear-networks/softmax-regression.html#subsec-softmax-and-derivatives
[^2]: Y hat (written $ŷ$ ) is **the predicted value of y** (the [dependent variable](https://www.statisticshowto.com/dependent-variable-definition/)) in a [regression equation](https://www.statisticshowto.com/probability-and-statistics/statistics-definitions/what-is-a-regression-equation/). [Y Hat: Definition - Statistics How To](https://www.statisticshowto.com/y-hat-definition/)