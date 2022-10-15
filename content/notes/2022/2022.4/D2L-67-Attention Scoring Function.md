---
title: "D2L-67-Attention Scoring Function"
tags:
- all
- Attention
- DeepLearning
date: "2022-04-21"
---
# 注意力评分函数

<div align="right"> 2022-04-21</div>

Tags: #Attention #DeepLearning 

- 抽取出Attention Pooling里面都有的Softmax部分, 我们可以将注意力机制的设计简化为Attention Scoring Function的设计.

![](notes/2022/2022.4/assets/attention-output%201.svg)

形式化的表达如下: 
- query $\mathbf{q} \in \mathbb{R}^q$,  
- $m$ 个key-value pairs $(\mathbf{k}_1, \mathbf{v}_1), \ldots, (\mathbf{k}_m, \mathbf{v}_m)$, 其中 $\mathbf{k}_i \in \mathbb{R}^k$ 且 $\mathbf{v}_i \in \mathbb{R}^v$.
则Attention Pooling $f$ 可以表达为value的如下加权平均: 
$$f(\mathbf{q}, (\mathbf{k}_1, \mathbf{v}_1), \ldots, (\mathbf{k}_m, \mathbf{v}_m)) = \sum_{i=1}^m \alpha(\mathbf{q}, \mathbf{k}_i) \mathbf{v}_i \in \mathbb{R}^v$$
- 进一步将attention weight里面的softmax提取出来:
$$\alpha(\mathbf{q}, \mathbf{k}_i) = \mathrm{softmax}(a(\mathbf{q}, \mathbf{k}_i)) = \frac{\exp(a(\mathbf{q}, \mathbf{k}_i))}{\sum_{j=1}^m \exp(a(\mathbf{q}, \mathbf{k}_j))} \in \mathbb{R}$$
其中 $a(\mathbf{q}, \mathbf{k}_i)$ 便是注意力评分函数的一般形式.

- One Query + Multiple Keys $\rightarrow$ Multiple Scores $\rightarrow$ Multiple Weights + Corresponding Values $\rightarrow$ One Output 

- 更一般的情况会同时存在多个Query $q_1,\cdots, q_i$, 我们需要计算每一个key和每一个query对应的注意力分数 $a(\mathbf{q}_i, \mathbf{k}_j)$. 也就是说, 注意力分数是一个二维的矩阵, 而**注意力Pooling的输出的个数等于Query的个数, 输出的维度等于Value的维度**

## Masked SoftMax
- 因为batch训练的时候需要对长度进行Pad, 所以不仅需要对Cost Function进行Mask, 还需要对Softmax进行Mask, 在概率计算的时候排除掉Pad的位置.
- 相比每次根据序列长度控制计算的元素个数, 一个技巧是直接先把pad的位置替换成一个很大的负数(e.g. -1e6), 再计算Softmax. 这样在计算的时候无关的项就会变为0, 简化了计算的逻辑.
- [代码示例](https://d2l.ai/chapter_attention-mechanisms/attention-scoring-functions.html#masked-softmax-operation)

## 两种注意力评分函数
### Additive Attention
![D2L-68-Additive Attention](notes/2022/2022.4/D2L-68-Additive%20Attention.md)

### Scaled Dot-Product Attention
![D2L-69-Scaled Dot-Product Attention](notes/2022/2022.4/D2L-69-Scaled%20Dot-Product%20Attention.md)


