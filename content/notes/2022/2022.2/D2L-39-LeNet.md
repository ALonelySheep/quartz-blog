---
title: "D2L-39-LeNet"
tags:
- all
- LeNet
- DeepLearning
- CNN
- NeuralNetwork
date: "2022-03-01"
---
# LeNet

<div align="right"> 2022-03-01</div>

Tags: #LeNet #DeepLearning #CNN #NeuralNetwork 

## 架构
![](notes/2022/2022.2/assets/lenet.svg)[^1]
- 总体来看，LeNet（LeNet-5）由两个部分组成：
	-   **卷积编码器**：由两个卷积层组成;
	-   **全连接层密集块**：由三个全连接层组成。

- 每个卷积块中的基本单元是**一个卷积层**(含**一个sigmoid激活函数**) 和一个**Avg Pooling 层**。
	- 请注意，虽然ReLU和最大汇聚层(Max Pooling)更有效，但它们在20世纪90年代还没有出现。

- 每个卷积层使用 $5×5$ 卷积核[^1]和一个sigmoid激活函数。这些层将输入映射到多个二维特征输出，通常同时增加通道的数量。
	- 第一卷积层有6个输出通道，而第二个卷积层有16个输出通道。每个 $2×2$ 池操作（步骤2, Stride=2）通过空间下采样将维数减少4倍 (指面积, 相当于边长减半)。

- 为了将卷积块的输出传递给稠密块，我们必须在第二个Pooling后中展平每个样本。(16x5x5=400), LeNet的稠密块有三个全连接层，分别有120、84和10个输出。(所以是 $400\rightarrow 120\rightarrow 84\rightarrow 10$ 因为我们在执行分类任务，所以输出层的10维对应于最后输出结果的数量。

- 相比原始模型，我们去掉了最后一层的高斯激活。除此之外，这个网络与最初的LeNet-5一致。
![](notes/2022/2022.2/assets/lenet-vert.svg)

## Origin
- LeNet是**最早发布的卷积神经网络之一**，因其在计算机视觉任务中的高效性能而受到广泛关注。 这个模型是由AT&T贝尔实验室的研究员**Yann LeCun在1989年提出**的（并**以其命名**），目的是识别图像中的**手写数字(MNIST)**。 
- 一睹大佬真容:
	Yann LeCun(杨立昆) 
	![150](notes/2022/2022.2/assets/Pasted%20image%2020220301203532.png)
- Paper: PDF(zotero://select/items/@lecun1998gradient) Y. LeCun, L. Bottou, Y. Bengio, and P. Haffner, “Gradient-based learning applied to document recognition,” _Proceedings of the IEEE_, vol. 86, no. 11, pp. 2278–2324, 1998, doi: [10.1109/5.726791](https://doi.org/10.1109/5.726791) .


[^1]: 图里面的像素大小有点不对, 卷积核是5x5的