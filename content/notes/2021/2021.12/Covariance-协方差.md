---
title: "Covariance-协方差"
tags:
- all
- Math/Statistics
date: "2021-12-11"
---
# Covariance

<div align="right"> 2021-12-11</div>

Tags: #Math/Statistics 


 期望值分别为  $E(X)=\mu$  与  $E(Y)=\nu$ 的两个随机变量  X  与  Y  之间的协方差定义为: 
$$\begin{aligned}
\operatorname{cov}(X,Y)&=\mathrm{E}((X-\mu)(Y-\nu))\\
&=\mathrm{E}(X \cdot Y-\nu X-\mu Y +\mu\nu)\\
&=\mathrm{E}(X \cdot Y)-\nu \mathrm{E}(X)-\mu \mathrm{E}(Y) +\mu\nu\\
&=\mathrm{E}(X \cdot Y)-\mu\nu-\mu\nu +\mu\nu\\
&=\mathrm{E}(X \cdot Y)-\mu \nu
\end{aligned}$$ 

或者也可以表示为:
$$\operatorname{cov}(X,Y)=\mathrm{E}(X \cdot Y)-\mathrm{E}(X)\mathrm{E}(Y)$$

- 如果$X,Y$是相互独立的, 那么它们之间的协方差为$0$ :
	$$\begin{aligned}
\operatorname{cov}(X,Y)&=\mathrm{E}(X \cdot Y)-\mu \nu\\
&=\mathrm{E}(X)\mathrm{E}(Y)-\mu \nu\\
&=\mu \nu-\mu \nu\\
&=0
\end{aligned}$$ 