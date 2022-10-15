---
title: "Part.15_Advanced_Optimization(ML_Andrew.Ng.)"
tags:
- all
- Octave
- MachineLearning
- GradientDescent
- LinearRegression
- LogisticRegression
date: "2021-08-19"
---
# Advanced Optimization

<div align="right"> 2021-08-19</div>

Tags: #Octave #MachineLearning #GradientDescent #LinearRegression #LogisticRegression 


- **More sophisticated, faster way to optimize parameters**: 
	- Conjugate gradient
	- BFGS
	- L-BFGS


[Link:其他Gradient_Descent Different_Gradient_Descent_Methods](notes/2021/2021.8/Different_Gradient_Descent_Methods.md)

在[Octave](notes/2021/2021.8/Part.10_Octave_Tutorial(ML_Andrew.Ng.).md)里面, 只需要写出怎么计算$J(\theta)$, $\frac{\Large\partial}{\Large\partial \Large\theta_{j}} J(\theta)$即可调用内置的库函数快速计算参数值.

```matlab
function [jVal, gradient] = costFunction(theta)
  jVal = [...code to compute J(theta)...];
  gradient = [...code to compute derivative of J(theta)...];
end
```

```matlab
options = optimset('GradObj', 'on', 'MaxIter', 100);
initialTheta = zeros(2,1);
   [optTheta, functionVal, exitFlag] = fminunc(@costFunction, initialTheta, options);
```

- MATLAB里面是`optimoptions`函数
- 在第二次作业(Logistic Regression)里面有对这个方法更具体的介绍.