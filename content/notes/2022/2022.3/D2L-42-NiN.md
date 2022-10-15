---
title: "D2L-42-NiN"
tags:
- all
- DeepLearning
- NiN
- CNN
date: "2022-03-04"
---
# Network in Network - NiN

<div align="right"> 2022-03-04</div>

Tags: #DeepLearning #NiN #CNN 

![NiN_PixelMLP](notes/2022/2022.3/assets/NiN_PixelMLP.svg)
## 用卷积代替全连接
### 动机
#### 全连接层很贵 (参数很多)
- 一层卷积层需要的参数为: 
	- ![卷积层权重大小的计算](notes/2022/2022.2/assets/卷积层权重大小的计算.svg) 
	- [卷积层参数大小的计算](notes/2022/2022.2/卷积层参数大小的计算.md)

- 卷积层后面第一个全连接层的参数为: $$in\_Channel\times in\_Height\times in\_Width\times num\_of\_Hidden\_Units$$

- **对比 :**
	- 一个 $C_{in}=512, C_{out}=4096$ 卷积核大小为3的卷积层[^2], 参数规模是 $$512\times4096\times3\times3\approx 18M$$
	- 一个输入通道数为512, 隐藏单元为4096, 输入尺寸为 $7\times7$ 的全连接层的参数规模是[^3] :  $$512\times7\times7\times4096\approx 102M$$

#### 全连接层损失了空间信息
- 这一点很好理解:  由卷积层转化到全连接层, 需要将卷积输出全部Flatten为一个一维向量. 而这意味着放弃了卷积层里面的空间信息.

### 1x1 卷积相当于(单像素上的)全连接
 [D2L-36-1x1卷积层](notes/2022/2022.2/D2L-36-1x1卷积层.md)
 
![NiN_PixelMLP](notes/2022/2022.3/assets/NiN_PixelMLP.svg)

## 网络结构
- 交替使用NiN块和步幅为2的最大池化层
	- 逐步减小高宽和增大通道数
![](notes/2022/2022.3/assets/nin.svg)
### 分块
- 和VGG一样, NiN网络也采用了分块的规范化网络结构, 一个NiN块包括一个普通卷积层与两个连续的 $1\times1$ 卷积层.
	```python
	def nin_block(in_channels, out_channels, kernel_size, strides, padding):
		return nn.Sequential(
			nn.Conv2d(in_channels, out_channels, kernel_size, strides, padding),
			nn.ReLU(),
			nn.Conv2d(out_channels, out_channels, kernel_size=1), nn.ReLU(),
			nn.Conv2d(out_channels, out_channels, kernel_size=1), nn.ReLU())
	```
	- 超参数主要调节的是第一个卷积层, 后面两个$1\times1$的卷积层不改变通道数.

### 全局平均池化层 global average pooling layer
- 其他网络里面通常将最后一层的隐藏层输出作为 [Logit](notes/2022/2022.2/Logit.md) 输入到Softmax里面得到预测概率, **但是NiN没有全连接层, 又怎么得到输出标签呢?**
- NiN网络将每一个通道的所有像素取平均值, 作为最后的输出. 这就相当于一个窗口大小是整个输入的平均池化层, 也称 **全局平均池化层(Global Average Pooling layer)**
- 所以NiN网络最后输出的通道数等于预测的类别数, 通过一个全局平均池化层(GAP)来得到每个类别的原始输出.

- 这也是为了避免使用全连接层, 减少参数数量的一个操作. 当然也同时减少了计算量, 防止过拟合

### 与AlexNet相似的超参数
- 最初的NiN网络是在AlexNet后不久提出的，显然从中得到了一些启示。 NiN使用窗口形状为11×11、5×5和3×3的卷积层，输出通道数量与AlexNet中的相同。 每个NiN块后有一个最大汇聚层，汇聚窗口形状为3×3，步幅为2。[^5]

![](notes/2022/2022.3/assets/图片1.jpg)
## 模型的特性
- 参数少, 模型不容易过拟合, 同时也减少了计算量.
- 但是由于增加了大量的1x1卷积, NiN的训练时间更长, 总的计算量也并没有比AlexNet少.


[^2]: 这是一个很大的卷积层了
[^3]: 这就是VGG的第一个全连接层
[^5]: [7.3. 网络中的网络（NiN） — 动手学深度学习 2.0.0-beta0 documentation](https://zh-v2.d2l.ai/chapter_convolutional-modern/nin.html#id3)