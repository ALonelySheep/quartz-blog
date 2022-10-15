---
title: "D2L-41-VGG"
tags:
- all
- DeepLearning
- VGG
- CNN
- todo
date: "2022-03-03"
---
# VGG

<div align="right"> 2022-03-03</div>

Tags: #DeepLearning #VGG #CNN 

![](notes/2022/2022.2/assets/img_2022-10-15-22.png)
- **模块化**是VGG网络最重要的思想.
- 模块化进一步带来了**自由性**, 不同的块配置可以带来不同的模型表现.

![](notes/2022/2022.2/assets/img_2022-10-15-23.png)

## 规范化 - 模块化
- 与芯片设计中工程师从放置晶体管到逻辑元件再到逻辑块的过程类似，神经网络架构的设计也逐渐变得更加抽象。研究人员开始从单个神经元的角度思考问题，发展到整个层，现在又转向块，重复层的模式。
- 使用块的设计同样让模型更加简洁.

### VGG块
![](notes/2022/2022.2/assets/img_2022-10-15-24.png)
- VGG将 [AlexNet](notes/2022/2022.2/D2L-40-AlexNet.md) 里面三层连续的卷积拿出来, 抽象成VGG块, 作为构建网络的基础模式.

- VGG块是可变的, 超参数变量 `conv_arch` 指定了每个VGG块里**卷积层个数**和**输出通道数**。
	- ![一个VGG块](notes/2022/2022.2/assets/一个VGG块.svg)
	方块模型解释: 
	![方块模型表示](notes/2022/2022.2/assets/方块模型表示.svg)
	- 不要想当然地把同一个大小的层作为一个块, VGG块在增大Channel数地同时减半输出尺寸. 下图是VGG 16的示意图, 16是指网络里面有13个卷积层加3个全连接层.
	![](notes/2022/2022.2/assets/VGG16.png)
VGG19: [^2]
![](notes/2022/2022.2/assets/vgg19.jpg)
- **VGG块的参数**
	![](notes/2022/2022.2/assets/img_2022-10-15-24.png)
	- 为了保持卷积输入输出**尺寸不变**, 卷积层采用了 $3\times3$ 的核加上 $1$ 的Padding.
	- VGG的Pooling窗口大小为 $2\times2$, Stride=2, 所以输出图像的尺寸减半. (下采样到1/4的分辨率)

- **为什么不添加全连接层来加深网络呢?**
	- 为了使网络更深, 我们可以添加更多的全连接层(FC)或者卷积层(Conv), 但是因为全连接层过于昂贵(参数数量庞大), 我们通常选择添加更多的卷积层.

- **为什么不用大一点的卷积核?**
	- 在VGG论文中，Simonyan和Ziserman尝试了各种架构。特别是他们发现深层且窄的卷积（即 $3×3$ ）比较浅层且宽的卷积更有效。[^1]
	- 但是为什么更大的卷积核, 更深的网络, 效果更好?
		- 一个可能的原因是: 具有相同感知野的条件下，小的卷积核提升了网络的深度
			- [[notes/2022/2022.2/2个3x3卷积核堆叠后等价于一个5x5卷积核]]
		- 那为什么深的网络效果好? #todo 

## 自由性 - 模型的多样性
![](notes/2022/2022.2/assets/VGG%20Variations.png)
## Origin
- VGG由牛津大学的 [视觉几何组（visualgeometry group）](http://www.robots.ox.ac.uk/~vgg/) 提出.
![](notes/2022/2022.2/assets/Pasted%20image%2020220303152941.png)


[^1]: [7.2. 使用块的网络（VGG） — 动手学深度学习 2.0.0-beta0 documentation](https://zh-v2.d2l.ai/chapter_convolutional-modern/vgg.html#id5)
[^2]: [Image Classification on CIFAR-10 Dataset · Image Classification](https://rishabhjain.xyz/ml-class-project/)