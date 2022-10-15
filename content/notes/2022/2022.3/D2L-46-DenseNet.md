---
title: "D2L-46-DenseNet"
tags:
- all
- DenseNet
- DeepLearning
- CNN
date: "2022-03-07"
---
# DenseNet

<div align="right"> 2022-03-07</div>

Tags: #DenseNet #DeepLearning #CNN 
![](notes/2022/2022.3/assets/img_2022-10-15-3.png)

- ResNet极大地改变了如何参数化深层网络中函数的观点。 稠密连接网络（DenseNet）在某种程度上是**ResNet的逻辑扩展**。

- PDF(zotero://select/items/@huang2017densely) 

## 数学直觉: 从ResNet到DenseNet
- 某个函数在 $x=0$ 处的泰勒展开为: 
	$$f(x)=f(0)+f^{\prime}(0) x+\frac{f^{\prime \prime}(0)}{2 !} x^{2}+\frac{f^{\prime \prime \prime}(0)}{3 !} x^{3}+\ldots$$
	- 这其中的思想是: 把事物分解为复杂度不断递增的项
	- ResNet其实也体现了这种思想: $$f(\mathbf{x})=\mathbf{x}+g(\mathbf{x})$$
		它将 $f(\mathbf{x})$ 分解为了简单的线性项 $\mathbf{x}$ 与复杂的非线性项 $g(\mathbf{x})$.

- 我们可以怎样将这种思想进一步推广呢?  
	- 我们需要创建更复杂的连接
	![ResNet2DenseNet|300](notes/2022/2022.3/assets/ResNet2DenseNet.svg)
	- 进一步, 我们使用"拼接"(_concatenation_)代替加法.
	![](notes/2022/2022.3/assets/densenet-block.svg)
	- 新的连接使得最后的输出是各种不同复杂度的项的聚合: 
		$$\mathbf{x} \rightarrow\left[
	\textcolor[RGB]{157, 72, 68}{\mathbf{x}}, 
	\textcolor[RGB]{255, 116, 109}{f_{1}(\mathbf{x})}, 
	\textcolor[RGB]{255, 154, 109}{f_{2}\left(\left[\mathbf{x}, f_{1}(\mathbf{x})\right]\right)}, 
	\textcolor[RGB]{255, 211, 109}{f_{3}\left(\left[\mathbf{x}, f_{1}(\mathbf{x}), f_{2}\left(\left[\mathbf{x}, f_{1}(\mathbf{x})\right]\right)\right]\right)},
	\ldots\right]$$
	![](notes/2022/2022.3/assets/densenet.svg)
	- 可以看到函数依赖图变得十分的"稠密"(Dense), 这也是DenseNet名字的由来.
- 为了使网络不会过于复杂, 我们使用1x1卷积核池化来控制通道的数量.

## 网络架构
- DenseNet由相互制约的两个组件构成: **稠密块**(*Dense Block*)和**过渡层**(*Transition Layer*). 
	- 前者定义如何连接输入和输出，而后者则控制通道数量，使其不会太复杂。

### 稠密块
- DenseNet使用了ResNet改良版的“批量规范化、激活和卷积”架构.[^1]
- 一个_稠密块_由多个卷积块组成，每个卷积块使用相同数量的输出通道。 在前向传播中，我们不再将多路输出相加, 而是直接在通道上相连(Concatenate).

- 详细实现参见 : [7.7. Densely Connected Networks (DenseNet) — Dense Block](https://d2l.ai/chapter_convolutional-modern/densenet.html#dense-blocks)
### 过渡层
- 由于每个稠密块都会带来通道数的增加，使用过多则会过于复杂化模型。 而过渡层可以用来控制模型复杂度。 它通过1×1卷积层来减小通道数，并使用步幅为2的平均汇聚层减半高和宽，从而进一步降低模型复杂度。

- 详细实现参见 : [7.7. Densely Connected Networks (DenseNet) —Transition Layer](https://d2l.ai/chapter_convolutional-modern/densenet.html#transition-layers)

### DenseNet
- DenseNet首先使用同ResNet一样的单卷积层和最大汇聚层。
- 接下来，类似于ResNet使用的4个残差块，DenseNet使用的是4个稠密块。 与ResNet类似，我们可以设置每个稠密块使用多少个卷积层。
- 在每个模块之间，ResNet通过步幅为2的残差块减小高和宽，DenseNet则使用过渡层来减半高和宽，并减半通道数。

- 与ResNet类似，最后接上全局汇聚层和全连接层来输出结果。

- 详细实现参见 : [7.7. Densely Connected Networks (DenseNet) — DenseNet](https://d2l.ai/chapter_convolutional-modern/densenet.html#densenet-model)

[^1]: He, K., Zhang, X., Ren, S., & Sun, J. (2016). Identity mappings in deep residual networks. _European conference on computer vision_ (pp. 630–645).