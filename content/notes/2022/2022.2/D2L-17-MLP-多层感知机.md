---
title: "D2L-17-MLP-多层感知机"
tags:
- all
- MultilayerPerceptron
- DeepLearning
- Perceptron
date: "2022-02-12"
---
# Multilayer Perceptron  

<div align="right"> 2022-02-12</div>

Tags: #MultilayerPerceptron #DeepLearning #Perceptron 

## 隐藏层
![mlp](notes/2022/2022.2/assets/mlp.svg)
 
 ## 从线性到非线性
- 用$\mathbf{X, H, O}$ 分别代表输入层, 隐藏层和输出层, 带偏置的模型可以表示如下:
$$\begin{aligned}
&\mathbf{H}=\mathbf{X} \mathbf{W}^{(1)}+\mathbf{b}^{(1)} \\
&\mathbf{O}=\mathbf{H} \mathbf{W}^{(2)}+\mathbf{b}^{(2)}
\end{aligned}$$
 
 - 但是线性代数告诉我们, 线性组合的线性组合依然是一个线性组合, 所以仅仅加入一个隐藏层并没有增加模型的表达能力😞.
	 - 证明: 
	 	$$\begin{aligned}
	\mathbf{O}&=\left(\mathbf{X W}^{(1)}+\mathbf{b}^{(1)}\right) \mathbf{W}^{(2)}+\mathbf{b}^{(2)}\\
	&=\mathbf{X} \mathbf{W}^{(1)} \mathbf{W}^{(2)}+\mathbf{b}^{(1)} \mathbf{W}^{(2)}+\mathbf{b}^{(2)}\\
	&=\mathbf{X} \mathbf{W'}+\mathbf{b'}\end{aligned}$$

- 为了发挥多层架构的潜力， 我们还需要一个额外的关键要素： **激活函数**（**activation function**）$σ$。 
	- 在我们的单隐藏层模型里面, 输入之后的权重对数据进行了[仿射变换](notes/2022/2022.2/仿射变换-Affine_Transformation.md), 此后通过对每个隐藏层单元应用非线性的**激活函数**, 我们的多层感知机不再退化成线性模型.
		$$\begin{aligned}&\mathbf{H}=\sigma\left(\mathbf{X W}^{(1)}+\mathbf{b}^{(1)}\right) \\
	&\mathbf{O}=\mathbf{H W}^{(2)}+\mathbf{b}^{(2)}
	\end{aligned}$$
	- 激活函数的输出 $σ(⋅)$ 被称为**活性值**（**activation**）。 
	- 注意, 通常我们不在输出层上作用激活函数, 输出层上面常常是[Softmax](notes/2022/2022.2/D2L-13-Softmax_Regression.md)或者其他变换.

	- 为了构建更通用的多层感知机， 我们可以继续堆叠这样的隐藏层， 例如$\mathbf{H^{(1)}=σ_1(XW^{(1)}+b^{(1)})}$ 和 $\mathbf{H^{(2)}=σ_2(H^{(1)}W^{(2)}+b^{(2)})}$， 从而产生更有表达能力的模型。

## 搞清楚矩阵的形状
- 为了使思路清晰， 我们来理一下D2L里面MLP各个矩阵的形状：
- **输入**: $\mathbf{X} \in \mathbb{R}^{n \times d}$ 表示 $n$ 个样本的小批量, 其中每个样本具有 $d$ 个输入特征。
		![X的维度](notes/2022/2022.2/assets/X的维度.svg)
- **权重矩阵**: 以第一层权重为例：  $\mathbf{W}^{(1)} \in \mathbb{R}^{d \times h}$ 
	![W的维度](notes/2022/2022.2/assets/W的维度.svg)

- **隐藏层偏置** $\mathbf{b}^{(1)} \in \mathbb{R}^{1 \times h}$
	![Bias的维度](notes/2022/2022.2/assets/Bias的维度.svg)
