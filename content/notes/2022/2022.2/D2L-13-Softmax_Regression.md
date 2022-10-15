---
title: "D2L-13-Softmax_Regression"
tags:
- all
- SoftmaxRegression
- MachineLearning
- Classification
- MulticlassClassification
date: "2022-02-11"
---
# Softmax 回归

<div align="right"> 2022-02-11</div>

Tags: #SoftmaxRegression #MachineLearning #Classification #MulticlassClassification 

- Softmax回归解决的是多分类问题[^1], 它可以看作是二分类的[Logistic_Regression](notes/2021/2021.8/Part.12_Logistic_Regression(ML_Andrew.Ng.).md)的推广.

![Softmax函数](notes/2022/2022.2/Softmax函数.md)

## Softmax回归
- Softmax回归就是在线性回归的基础上套上一个Softmax函数, 取输出结果中概率最大的项作为预测结果.
![](notes/2022/2022.2/assets/Pasted%20image%2020220211175631.png)

### 交叉熵作为损失函数
[D2L-14-Cross Entropy as Loss](notes/2022/2022.2/D2L-14-Cross%20Entropy%20as%20Loss.md)




## Softmax and Argmax
- 不像Softmax输出K个概率值, Argmax函数直接将输入向量里面最大的元素设置为1, 其他均置为0.
- Argmax常常用于输出预测结果, 但是Argmax有个很严重的缺点: 它的结果没法用于反向传播优化参数: (因为它要么不可导要么导数为0)

解释: 
<iframe width="560" height="315" src="https://www.youtube.com/embed/KpKog-L9veg?start=185" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>

### Softmax名称的由来
> Softmax的名字是怎么来的？ - 2WaveTech的文章 - 知乎 https://zhuanlan.zhihu.com/p/58859958

Softmax是"Hardmax"函数的Soft版本: 
![](notes/2022/2022.2/assets/Pasted%20image%2020220211181821.png)



## 与Logistic(Sigmoid)回归的联系
[Relation_between_Softmax_and_Logistic_Regression](notes/2022/2022.2/Relation_between_Softmax_and_Logistic_Regression.md)


## 数值稳定性上面的一些细节
> softmax和cross-entropy是什么关系？ - 董鑫的回答 - 知乎 https://www.zhihu.com/question/294679135/answer/885285177



[^1]: 和Logistic回归一样, 虽然它名字叫回归, 实际上解决的却是分类问题. 为什么呢? 搜索了一会儿没有得到结果😥
