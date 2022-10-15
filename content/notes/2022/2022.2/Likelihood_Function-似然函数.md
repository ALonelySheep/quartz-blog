---
title: "Likelihood_Function-似然函数"
tags:
- all
- Math/Statistics
- MachineLearning
date: "2022-02-11"
---
# Likelihood Function - 似然函数

<div align="right"> 2022-02-11</div>

Tags: #Math/Statistics #MachineLearning 

对于某个(某组)随机变量 $X$, 我们通过采样获得了数据集 $x$ :
- 似然函数$\mathcal{L}(\theta \mid x)$就是在某个参数(parameter) $\theta$ 下, 现有数据 $x$ 出现的概率大小, 也就是说: 
$$\mathcal{L}(\theta \mid x) = P(X=x\mid\theta)$$
$P(X=x\mid\theta)$ 也常常写作 $p_{\theta}(x)=P_{\theta}(X=x)=P(X=x\ ;\theta)$

- 因为数据集有许多样本点, 所以似然函数是一个联合概率分布(Joint Probability)

> - **The likelihood function** (often simply called **the likelihood**) describes the *joint probability* of the observed data as *a function of the parameters* of the chosen statistical model. 
> 
> - For each specific parameter value $θ$ in the parameter space, the likelihood function $p ( X | θ )$ therefore assigns a probabilistic prediction to the observed data $X$. 
> 
> - It is essentially the product of sampling densities.[^1]

- [Maximum_Likelihood_Estimation-极大似然估计](notes/2021/2021.12/Maximum_Likelihood_Estimation-极大似然估计.md)

[^1]:[Likelihood function - Wikipedia](https://en.wikipedia.org/wiki/Likelihood_function) 