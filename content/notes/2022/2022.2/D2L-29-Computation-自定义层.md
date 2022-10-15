---
title: "D2L-29-Computation-自定义层"
tags:
- all
- DeepLearning
- Computation
- PyTorch
date: "2022-02-19"
---
# 深度学习计算: 自定义一个层

<div align="right"> 2022-02-19</div>

Tags: #DeepLearning #Computation #PyTorch 

 - [在线代码实例: 5.4. 自定义层](https://zh-v2.d2l.ai/chapter_deep-learning-computation/custom-layer.html#id1 "Permalink to this headline")
---
-   我们可以通过基本层类设计自定义层。这允许我们定义灵活的新层。
-   在自定义层定义完成后，我们就可以在任意环境和网络架构中调用该自定义层。
-   层可以有局部参数，这些参数可以通过内置函数创建。