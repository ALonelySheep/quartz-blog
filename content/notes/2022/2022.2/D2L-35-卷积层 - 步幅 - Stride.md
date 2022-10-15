---
title: "D2L-35-卷积层 - 步幅 - Stride"
tags:
- all
- DeepLearning
- CNN
- Stride
date: "2022-02-27"
---
# Stride - 步幅

<div align="right"> 2022-02-27</div>

Tags: #DeepLearning #CNN #Stride

- It's always nice to have an interactive example: 
	- [Convolution Visualizer](https://ezyang.github.io/convolution-visualizer/index.html)
	- [CNN Explainer](https://poloclub.github.io/cnn-explainer/)

- 卷积操作会使图像尺寸变小, 增大步幅 (Stride) 可以**加快**这个过程.

![](notes/2022/2022.2/assets/img_2022-10-15-4.gif)
- 为了高效计算或是缩减采样次数，卷积窗口可以跳过中间位置，每次滑动多个元素。而每次滑动元素的数量就称为_步幅_（*stride*）

## 尺寸变化: 定量计算
- 通常, 当垂直步幅为 $s_{h}$  (height) 、水平步幅为 $s_{w}$ 时 (width) , 输出形状为
$$
\left\lfloor\frac{x_{h}-k_{h}+p_{h}+s_{h}}{s_{h}}\right\rfloor \times\left\lfloor\frac{x_{w}-k_{w}+p_{w}+s_{w}}{s_{w}}\right\rfloor
$$

- 如果我们设置了 $p_{h}=k_{h}-1$ 和 $p_{w}=k_{w}-1$, 则输出形状将简化为 $$\left\lfloor\frac{x_{h}+s_{h}-1}{s_{h}}\right\rfloor \times\left\lfloor\frac{x_{w}+s_{w}-1}{s_{w}}\right\rfloor$$ 

- 更进一步, 如果输入的高度和宽度可以被垂直和水平步幅整除, 则输出形状将为 $$\left(\frac{x_{h}}{s_{h}}\right) \times\left(\frac{x_{w}} {s_{w}}\right)$$ 