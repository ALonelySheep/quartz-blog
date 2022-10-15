---
title: "JS散度"
tags:
- all
- JSDivergence
date: "2022-06-08"
---
# Jensen–Shannon divergence

<div align="right"> 2022-06-08</div>

Tags: #JSDivergence 

- KL 散度是不对称的, 这使得在训练过程中可能出现一些问题，所以我们在 KL 散度基础上引入 JS 散度

## 定义
- The Jensen–Shannon divergence (JSD) $M_+^1( A ) × M_+^1(A) → [ 0 , ∞ )$ [^1]is a **symmetrized and smoothed version** of the [Kullback–Leibler divergence](notes/2022/2022.2/KL_Divergence-KL散度.md) $D ( P ∥ Q )$ . 
- It is defined by 
$$
\operatorname{JSD}(P \| Q)=\frac{1}{2} D(P \| M)+\frac{1}{2} D(Q \| M)
$$
	where $M=\frac{1}{2}(P+Q)$.






[^1]: 看不懂这个符号: Consider the set $M_+^1( A )$ of probability distributions where $A$ is a set provided with some σ-algebra of measurable subsets. In particular we can take $A$  to be a finite or countable set with all subsets being measurable. [Jensen–Shannon divergence - Wikipedia](https://en.wikipedia.org/wiki/Jensen%E2%80%93Shannon_divergence)