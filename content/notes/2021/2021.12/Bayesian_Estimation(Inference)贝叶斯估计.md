---
title: "Bayesian_Estimation(Inference)贝叶斯估计"
tags:
- all
- Bayes
- MachineLearning
date: "2021-12-27"
---
# 贝叶斯估计

<div align="right"> 2021-12-27</div>

Tags: #Bayes #MachineLearning 


贝叶斯估计 有点难, 还要进一步学习

- 贝叶斯估计是一种参数估计方法, 不只局限于设计贝叶斯分类器
- 贝叶斯估计的核心在于用新的样本来更新旧的Prior, 一起得到一个PostPrior的参数的概率分布, 合并的过程利用的是贝叶斯分布.
- 贝叶斯估计和极大似然估计的最大不同就是贝叶斯估计的是参数可能的概率分布, 而不是一个确定的值. 通过对这个概率分布进行积分, 我们可以平均地得到所有情况下最可能出现的参数.



这两篇文章写的很好: 
- [Conjugate Prior Explained. With examples & proofs | by Aerin Kim | Towards Data Science](https://towardsdatascience.com/conjugate-prior-explained-75957dc80bfb)
- [Bayesian Inference — Intuition and Example | by Aerin Kim | Towards Data Science](https://towardsdatascience.com/bayesian-inference-intuition-and-example-148fd8fb95d6)

Duda书上的逻辑是有点乱的, 在整理笔记的时候先看上面的两片文章, 然后看书上的过程, 然后再自己推一遍正态分布的情况.
