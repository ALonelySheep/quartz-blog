---
title: "D2L-38-池化层-Pooling_Layer"
tags:
- all
- PoolingLayer
- DeepLearning
- CNN
date: "2022-02-27"
---
# 池化层/汇聚层 - Pooling Layer

<div align="right"> 2022-02-27</div>

Tags: #PoolingLayer #DeepLearning #CNN 

## 首先，池化层为什么叫“池化层”
>  [Collins Dictionary - Pool](https://www.collinsdictionary.com/dictionary/english/pool)   7. verb
> - If a group of people or organizations *pool* their money, knowledge, or equipment, they share it or put it together so that it can be used for a particular purpose.
>	 -	We *pooled* ideas and information. 
>	 - Philip and I *pooled* our savings to start up my business. 
>
> - **Synonyms:** combine, share, merge, put together 

- 从字面上理解, Pool作为动词的时候有"汇集许多个体"的含义, 这和池化层的操作比较相似

![](notes/2022/2022.2/assets/img_2022-10-15-5.gif)
[^1]

## Pooling的作用
- CNN对于物体的位置实际上是很敏感的, 目标物体一点点的变化就会导致卷积层的输出发生对应的变化. 
- 而CNN最终解决的问题其实是和整个图像相关的 (例如: 图像里面有没有小企鹅?) 这就要求网络的最后一层的感受野要覆盖整个输入图像. 整个过程相当于是在逐渐聚合信息 (aggregating information), 生成越来越粗糙的映射 (coarser and coarser maps) , 既在网络的中段充分利用卷积层的优势 (平移不变性, 局部性等), 又能输出我们想要的全局信息. 

- Pooling层的作用就是"让映射具有粗糙性", 或者说, 让Short-sighted的卷积层有"全局观", 对目标的位置不那么敏感.
- 此外, 池化层还有**下采样**的作用 (让图像变小), 这可以加快运算.
	- _Pooling layers_ serve the dual purposes of mitigating the sensitivity of convolutional layers to location and of spatially downsampling representations.[^2]

- 因为池化层的作用和卷积紧密相关, 所以池化层一般是跟在卷积之后的.

- 吴恩达说池化层的作用是实践出来的, 应该没有人能说清楚其中的门道.
	[✂️ Andrew Ng Explain Max Pooling - YouTube](https://youtube.com/clip/UgkxKiNbvqiUlN91gNNwPUcFR-0oCOwmR2uk)
	
### 举几个例子加深理解
![](notes/2022/2022.2/assets/img_2022-10-15-17.png)
- 如果上图中的输出值代表检测到目标的可能性, 那么池化层综合考虑了四个卷积操作的结果, 用"分治"的思想来判断哪个区域存在目标.
- 下图也是这个意思, 无论三个filter里面的哪一个识别到了数字五, max pool都会输出正确的结果.  这也和Pool的字面意思不谋而合: 综合许多人的结果/资源.
![](notes/2022/2022.2/assets/img_2022-10-15-18.png)
- 下图演示了池化层可以增强卷积对微小平移的鲁棒性. 因为我们往往更关注图中是否存在目标, 而不是目标出现在了哪个精确的位置.
![](notes/2022/2022.2/assets/img_2022-10-15-19.png)
- 从上图可以看出, 尽管所有的输入都发生了变化, 但只有一半的Pool输出发生了变化. 这是因为Max Pool只关心它能看到的最大值, 而不是最大值出现的位置.

## 两种池化
- 和卷积层类似, 池化层也是通过一个滑动的窗口来进行池化运算的, 自然也可以通过进行[填充](notes/2022/2022.2/D2L-34-卷积层%20-%20填充%20-%20Padding.md) 和设置[步幅](notes/2022/2022.2/D2L-35-卷积层%20-%20步幅%20-%20Stride.md) 来调整输出的尺寸. 
- 和卷积不同的是, 池化层没有Kernel, 池化层只能进行固定的两种运算: Max 或 Avg. 这也意味着池化层是没有参数可以进行学习的.

	- 池化层还能进行p-norm运算, 具体作用我没有深入了解

![400](notes/2022/2022.2/assets/img_2022-10-15-20.png)

![400](notes/2022/2022.2/assets/img_2022-10-15-21.png)
## 多通道的情况: 逐个Pooling
- 池化层和卷积层的另一个不同在于: **池化层不改变输入的通道数, 对每一个通道单独进行池化操作**. 
	- 相反, 卷积将输入的多个通道根据卷积核转换为一个或多个输出通道.

![Pooling-NoChangeInChannels](notes/2022/2022.2/assets/Pooling-NoChangeInChannels.svg)




[^1]: [Comprehensive Guide to Different Pooling Layers in Deep Learning](https://analyticsindiamag.com/comprehensive-guide-to-different-pooling-layers-in-deep-learning/)
[^2]: [6.5. Pooling — Dive into Deep Learning 0.17.2 documentation](https://d2l.ai/chapter_convolutional-neural-networks/pooling.html#pooling)