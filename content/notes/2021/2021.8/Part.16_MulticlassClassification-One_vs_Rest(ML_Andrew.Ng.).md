---
title: "Part.16_MulticlassClassification-One_vs_Rest(ML_Andrew.Ng.)"
tags:
- all
- MulticlassClassification
- Classification
- MachineLearning
date: "2021-08-19"
---
# One vs Rest

<div align="right"> 2021-08-19</div>

Tags: #MulticlassClassification #Classification #MachineLearning 

- AKA: One vs All

## MulticlassClassification
![](notes/2021/2021.7/assets/img_2022-10-15-21.png)

$$\begin{aligned}
&y \in\{0,1 \ldots n\} \\
&h_{\theta}^{(0)}(x)=P(y=0 \mid x ; \theta) \\
&h_{\theta}^{(1)}(x)=P(y=1 \mid x ; \theta) \\
&\cdots \\
&h_{\theta}^{(n)}(x)=P(y=n \mid x ; \theta) \\
&\text { prediction }=\max _{i}\left(h_{\theta}^{(i)}(x)\right)
\end{aligned}$$

## One vs Rest
将二分类问题应用到多分类里面, 即对每一个分类分别训练一个二分类模型$h^{(i)}(x)$ , 因为$h^{(i)}(x)$的大小可以看作属于这个分类的概率, 在预测的时候将数据点带入$n$个$h^{(i)}(x)$里面, 取概率最大的分类作为预测结果.
![](notes/2021/2021.7/assets/img_2022-10-15-22.png)
![](notes/2021/2021.7/assets/img_2022-10-15-23.png)