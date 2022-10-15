---
title: "D2L-18-激活函数-Activation_Functions"
tags:
- all
- DeepLearning
- ActivationFunction
date: "2022-02-12"
---
# 常用激活函数

<div align="right"> 2022-02-12</div>

Tags: #DeepLearning #ActivationFunction 

![](notes/2022/2022.2/assets/img_2022-10-15-2.gif)[^2]

## ReLU
**修正线性单元**（Rectified Linear Unit，_ReLU_）
![](notes/2022/2022.2/assets/ReLU.svg)
- ReLU就是一个 $max(0,x)$ 函数.
- ReLU是分段线性的
- ReLU的变体通过设置一个线性项, 使得负轴的一些信息得到保留(Parameterized ReLU)
	$\mathbf{pReLU}(x)=max(0,x)+α\space min(0,x).$
	![](notes/2022/2022.2/assets/Pasted%20image%2020220212160706.png)

### 导数
![](notes/2022/2022.2/assets/Derivative_of_ReLU.svg)
- 使用ReLU的原因是，它求导表现得特别好：要么让参数消失，要么让参数通过。
- 注意，当输入值精确等于0时，ReLU函数不可导。 在此时，我们默认使用左侧的导数，即当输入为0时导数为0。[^1]

## Sigmoid 函数
![Sigmoid_Function](notes/2021/2021.8/Sigmoid_Function.md)

## Tanh 函数
- 与sigmoid函数类似， tanh(双曲正切)函数将其输入压缩转换到区间$(-1, 1)$上。
	- 与Sigmoid的区别是压缩的区间不一样(Sigmoid: $(0,1)$, Tanh: $(-1,1)$). 同时, tanh函数是奇函数.

$$\tanh (x)=\frac{1-\exp (-2 x)}{1+\exp (-2 x)}$$

![](notes/2022/2022.2/assets/Tanh.svg)
### 导数
$$\frac{d}{d x} \tanh (x)=1-\tanh ^{2}(x)$$

![](notes/2022/2022.2/assets/Derivative-of-Tanh.svg)






[^1]: 我们可以忽略这种情况，因为输入可能永远都不会是0。 这里引用一句古老的谚语，“如果微妙的边界条件很重要，我们很可能是在研究数学而非工程”， 这个观点正好适用于这里。
[^2]: [Activation Functions Explained - GELU, SELU, ELU, ReLU and more](https://mlfromscratch.com/activation-functions-explained/#/)