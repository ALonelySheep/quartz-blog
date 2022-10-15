---
title: "参数估计-Parameter_Estimation"
tags:
- all
- MachineLearning
- ParameterEstimation
- Math/Statistics
date: "2021-12-25"
---
# 参数估计

<div align="right"> 2021-12-25</div>

Tags: #MachineLearning #ParameterEstimation #Math/Statistics 

- 在设计分类器或者进行回归预测的时候, 我们需要知道目标问题的概率分布情况. 但是通常我们能得到的数据只是一些特例(即训练样本). 为了对问题进行建模, 我们不仅需要确定合适的概率分布模型, 还需要根据训练样本确定模型里面的具体参数. 参数估计就是在模型已知的情况下得到最优参数的过程.


- 对于贝叶斯分类器, 估计先验概率$P(\omega_i)$通常不是很困难. 难点在于估计类条件概率密度$p(x|\omega_i)$, 这是因为: 
	- 在很多情况下, 我们没有足够的样本
	- 在表示特征的向量$x$维数较大的情况下, 计算复杂度很高.

- 目前比较常用的参数估计方法有极大似然估计(Maximum LIkelihood Estimation)和贝叶斯估计(Bayesian Estimation).

	- [Maximum_Likelihood_Estimation-极大似然估计](notes/2021/2021.12/Maximum_Likelihood_Estimation-极大似然估计.md)



