---
title: "Markov's and Chebyshev's Inequalities"
tags:
- all
- Math/Statistics
date: "2021-12-04"
---
# Markov and Chebyshev Inequalities

<div align="right"> 2021-12-04</div>

Tags: #Math/Statistics 

FileLink(zotero://select/items/@InequalitiesMarkov) 

## Markov's Inequality
 $X$ 是一个非负的随机变量. 对于任意正实数 $a$ , 有
$$
P(X \geq a) \leq \frac{E(X)}{a}
$$

### Proof
- 证明里我们假设$X$是离散随机变量, 对于连续随机变量只需要将求和变成求积分即可.

按照定义, $E(X)=\sum_{x} x P(X=x)$. We'll split this sum into two pieces, depending on whether or not $x \geq a$.
$$
\begin{aligned}
E(X) &=\sum_{x \geq a} x P(X=x)+\sum_{x<a} x P(X=x) \\
& \geq \sum_{x \geq a} a P(X=x)+0 \quad(\text { since in the first sum we assume } x \geq a) \\
&=a \sum_{x \geq a} P(X=x) \\
&=a P(X \geq a)
\end{aligned}
$$

## Chebyshev's Inequality
Let $X$ be any random variable with finite expected value and variance. Then for every positive real number a,
$$
P(|X-E(X)| \geq a) \leq \frac{\operatorname{Var}(X)}{a^{2}} .
$$

### Proof
We can prove it using Markov's Inequality:

Let $Y=(X-E(X))^{2}$. Recall the definition of the variance of $X$:
$$\operatorname{Var}(X)=\mathrm{E}\left[(X-E(X))^{2}\right]$$

Then $Y$ is a non-negative valued random variable with expected value $E(Y)=\operatorname{Var}(X)$. By Markov's inequality,
$$
P\left(Y \geq a^{2}\right) \leq \frac{E(Y)}{a}=\frac{\operatorname{Var}(X)}{a^{2}} .
$$
But notice that the event $Y \geq a^{2}$ is the same as $|X-E(X)| \geq a$, so we conclude that
$$
P(|X-E(X)| \geq a) \leq \frac{\operatorname{Var}(X)}{a^{2}}
$$
