---
title: "Part.31_Principal_Component_Analysis(ML_Andrew.Ng.)"
tags:
- all
- MachineLearning
- DimensionalityReduction
- PCA
date: "2021-11-11"
---
# Principal Component Analysis - 主成分分析

<div align="right"> 2021-11-11</div>

Tags: #MachineLearning #DimensionalityReduction #PCA

## 基本步骤
### Step 0 - Data Preprocessing
- [Normalization 归一化](notes/2021/2021.8/Part.7_Feature_Scaling(ML_Andrew.Ng.).md#Normalization%20归一化)
- [Standardization 标准化](notes/2021/2021.8/Part.7_Feature_Scaling(ML_Andrew.Ng.).md#Standardization%20标准化)

[PCA依赖于欧氏距离](notes/2021/2021.8/Part.7_Feature_Scaling(ML_Andrew.Ng.).md#^375f2a), 所以预处理数据可以让降维效果更好.

### Step 1 - Compute the Covariance Matrix
$$\Sigma=\frac{1}{m} \sum_{i=1}^{n}\left(x^{(i)}\right)\left(x^{(i)}\right)^{T}$$

### Step 2 - Compute Eigenvectors of Matrix $\Sigma$
- Using Singular Value Decomposition
- `[U,S,V] = svd(Sigma);`
- We need to use
	 $$U=\left[\begin{array}{cccc}
\mid & \mid & & \mid \\
u^{(1)} & u^{(2)} & \ldots & u^{(n)} \\
\mid & \mid & & \mid
\end{array}\right] \in \mathbb{R}^{n \times n}$$

### Step 3 - Mapping the Data
- 取出$U$里面的前$k$个特征向量:
 	$$\left[\begin{array}{cccc}
	\mid & \mid & & \mid \\
	u^{(1)} & u^{(2)} & \ldots & u^{(k)} \\
	\mid & \mid & & \mid
	\end{array}\right] \in \mathbb{R}^{n \times k}$$
	- 这就是我们的投影矩阵 

- 单个数据点的投影:
	$$z^{(i)}=\left[\begin{array}{cccc}
	\mid & \mid & & \mid \\
	u^{(1)} & u^{(2)} & \ldots & u^{(k)} \\
	\mid & \mid & & \mid
	\end{array}\right]^{T} x^{(i)}_{n \times 1}=\left[\begin{array}{c}
-\left(u^{(1)}\right)^T- \\
\vdots \\
-\left(u^{(k)}\right)^T-
\end{array}\right]_{k \times n}x^{(i)}_{n \times 1}$$





