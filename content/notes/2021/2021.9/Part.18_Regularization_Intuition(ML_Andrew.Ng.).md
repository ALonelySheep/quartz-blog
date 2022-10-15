---
title: "Part.18_Regularization_Intuition(ML_Andrew.Ng.)"
tags:
- all
- MachineLearning
- Regularization
date: "2021-09-10"
---
# Regularization: Intuition

<div align="right"> 2021-09-10</div>

Tags: #MachineLearning #Regularization 

如果我们约束的参数"加大权重", 那么在优化的时候就会重点最小化那些加了权重的参数.
E.g.
$$
\theta_{0}+\theta_{1} x+\theta_{2} x^{2}+\theta_{3} x^{3}+\theta_{4} x^{4}
$$
We'll want to eliminate the influence of $\theta_{3} x^{3}$ and $\theta_{4} x^{4}$. Without actually getting rid of these features or changing the form of our hypothesis, we can instead modify our cost function:
$$
\min _{\theta} \frac{1}{2 m} \sum_{i=1}^{m}\left(h_{\theta}\left(x^{(i)}\right)-y^{(i)}\right)^{2}+1000 \cdot \theta_{3}^{2}+1000 \cdot \theta_{4}^{2}
$$
后面的两项可以约束$\theta_{3}$和$\theta_{4}$, 减小它们的影响.

更一般的形式如下: 
$$
\min _{\theta} \frac{1}{2 m} \left[\sum_{i=1}^{m}
\left(h_{\theta}\left(x^{(i)}\right)-y^{(i)}\right)^{2}
+\lambda \sum_{j=1}^{n} \theta_{j}^{2}\right]
$$

- The $\lambda$, or lambda, is the regularization parameter. It determines how much the costs of our theta parameters are inflated.
- 注意$j$从1开始, 我们通常不约束$\theta_0$ .

