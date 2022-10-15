---
title: "Maximum_Likelihood_Estimation-极大似然估计"
tags:
- all
- MachineLearning
- Math/Statistics
date: "2021-12-25"
---
# 极大似然估计 MLE

<div align="right"> 2021-12-25</div>

Tags: #MachineLearning #Math/Statistics 

Links: [Likelihood_Function-似然函数](notes/2022/2022.2/Likelihood_Function-似然函数.md)

假设样本 $X$ 服从已知的概率分布(比如正态分布)
- **极大似然估计**就是要找一个参数 $\hat\theta$,  使似然函数 $\mathcal{L}(\theta \mid X)$ 取得最大值$$i.e.\quad \hat{\theta}=\operatorname{argmax}_{\theta \in \Theta} \mathcal{L}(\theta \mid X)$$
- 极大似然估计认为: 最佳的参数 $\hat\theta$ 最可能使取样结果为现在的 $x$, 也就是说, 概率$P(X=x\mid \theta)$最大:
$$\hat{\theta}=\operatorname{argmax}_{\theta \in \Theta} P(X=x\mid \theta)$$
	

