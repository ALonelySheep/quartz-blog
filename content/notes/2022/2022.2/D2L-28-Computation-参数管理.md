---
title: "D2L-28-Computation-参数管理"
tags:
- all
- DeepLearning
- Computation
- Parameter
- PyTorch
date: "2022-02-19"
---
# 深度学习计算: 参数管理

<div align="right"> 2022-02-19</div>

Tags: #DeepLearning #Computation #Parameter #PyTorch 

- [在线代码实例: 5.2. 参数管理](https://zh-v2.d2l.ai/chapter_deep-learning-computation/parameters.html#id1 "Permalink to this headline")
---
本节主要有以下内容：
-   访问参数，用于调试、诊断和可视化。
-   参数初始化。
-   在不同模型组件间共享参数。(保持某几个层的参数是同步的)

## 延后初始化[¶](https://zh-v2.d2l.ai/chapter_deep-learning-computation/deferred-init.html#sec-deferred-init "Permalink to this headline")
- 深度学习框架无法判断网络的输入维度是什么。 这里的诀窍是框架的 _延后初始化_（defers initialization）， 即直到数据第一次通过模型传递时，框架才会动态地推断出每个层的大小。
- 这个在MXNET 和 Tensorflow 里面有, PyTorch还不太完善, 不过LazyLinear可以达到类似的功能