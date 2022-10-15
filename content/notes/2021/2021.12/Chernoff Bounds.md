---
title: "Chernoff Bounds"
tags:
- all
- Math/Statistics
date: "2021-12-04"
---
# Chernoff Bounds

<div align="right"> 2021-12-04</div>

Tags: #Math/Statistics 

[probabilitycourse.com - Chernoff Bounds](https://www.probabilitycourse.com/chapter6/6_2_3_chernoff_bounds.php)

zotero:@ChernoffBounds(zotero://select/items/@ChernoffBounds)


- The generic Chernoff bound for a random variable $X$ is attained by applying Markov's inequality to $e^{tX}$. This gives a bound in terms of the [moment-generating function](https://en.wikipedia.org/wiki/Moment-generating_function "Moment-generating function") of $X$. For every $t ≥ 0$:

$$\operatorname{Pr}(X \geq a)=\operatorname{Pr}\left(e^{t \cdot X} \geq e^{t \cdot a}\right) \leq \frac{E\left[e^{t \cdot X}\right]}{e^{t \cdot a}}$$

- $E\left[e^{t \cdot X}\right]$实际上就是moment-generating function: $M_{X}(s)$

$$\begin{array}{ll}
P(X \geq a) \leq e^{-t a} M_{X}(t), & \text { for all } t>0 \\
P(X \leq a) \leq e^{-t a} M_{X}(t), & \text { for all } t<0
\end{array}$$