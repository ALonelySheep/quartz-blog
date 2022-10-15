---
title: "Union_Bound-布尔不等式-Boole's_inequality"
tags:
- all
- Math/Statistics
date: "2021-12-04"
---
# Union Bound: 布尔不等式

<div align="right"> 2021-12-04</div>

Tags: #Math/Statistics 


- This website explained it well:
[The Union Bound and Extension](https://www.probabilitycourse.com/chapter6/6_2_1_union_bound_and_exten.php)

## Intuition

$$\begin{aligned}
P(A \cup B) &=P(A)+P(B)-P(A \cap B) \\
& \leq P(A)+P(B) .
\end{aligned}$$

同样, 对于三个随机变量也有相应的不等关系:

$$\begin{aligned}
P(A \cup B \cup C) &=P((A \cup B) \cup C) \\
& \leq P(A \cup B)+P(C) \\
& \leq P(A)+P(B)+P(C)
\end{aligned}$$

In general, using induction we prove the following:

**The Union Bound**

For any events $A_{1}, A_{2}, \ldots, A_{n}$, we have
$$
P\left(\bigcup_{i=1}^{n} A_{i}\right) \leq \sum_{i=1}^{n} P\left(A_{i}\right)
$$

展开就是:

$$
\mathbb{P}\left(A_{1} \bigcup A_{2} \bigcup \cdots\right) \leq \mathbb{P}\left(A_{1}\right)+\mathbb{P}\left(A_{2}\right)+\cdots
$$