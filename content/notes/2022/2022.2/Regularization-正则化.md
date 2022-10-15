---
title: "Regularization-正则化"
tags:
- all
- Regularization
- DeepLearning
date: "2022-02-14"
---
# Regularization

<div align="right"> 2022-02-14</div>

Tags: #Regularization #DeepLearning 

## Definition
- **Regularization**: any modification we make to a learning algorithm that is intended to reduce its *generalization error* but **not** its *training error*.[^1]
	- 对学习算法的修改——旨在减少泛化误差而不是训练误差
	- 这是一个很宽泛的概念, 

- Many strategies used in machine learning are explicitly designed to reduce the test error, possibly at the expense of increased training error. These strategies are known collectively as **regularization**.[^1]

- 正则化只在训练中使用. 也就是说, 在模型实际用来推理得结果的时候不使用正则化.
	- 对于 L2 正则化, 这个没啥影响, 但是对于 Dropout 来说, 意味着 $\mathbf{h}=\operatorname{dropout}(\mathbf{h})$

## Links
- [Part.18_Regularization_Intuition(ML_Andrew.Ng.)](notes/2021/2021.9/Part.18_Regularization_Intuition(ML_Andrew.Ng.).md)
- [D2L-22-权重衰减](notes/2022/2022.2/D2L-22-权重衰减.md)
- [Part.19_Regularized_Linear_Regression(ML_Andrew.Ng.)](notes/2021/2021.9/Part.19_Regularized_Linear_Regression(ML_Andrew.Ng.).md)
- [Part.20_Regularized_Logistic_Regression(ML_Andrew.Ng.)](notes/2021/2021.9/Part.20_Regularized_Logistic_Regression(ML_Andrew.Ng.).md)
- 







[^1]:I. Goodfellow, Y. Bengio, and A. Courville, _Deep learning_. MIT Press, 2016.(zotero://select/items/@Goodfellow-et-al-2016)