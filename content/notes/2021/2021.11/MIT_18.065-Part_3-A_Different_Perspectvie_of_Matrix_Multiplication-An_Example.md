---
title: "MIT_18.065-Part_3-A_Different_Perspectvie_of_Matrix_Multiplication-An_Example"
tags:
- all
- Math/LinearAlgebra
- Matrix
- Math
date: ""
---

#Math/LinearAlgebra #Matrix #Math 


$$S=Q \Lambda Q^{\mathrm{T}}$$
- 其中S是一个对称矩阵, $S=S^{\mathrm{T}}$
- Q的行向量是S的特征向量, 这些特征向量相互正交
$$Q=\left[\begin{array}{ccc}
\mid & & \mid \\
q_{1} & \ldots & q_{n} \\
\mid & & \mid
\end{array}\right]$$
- $\Lambda$是对角矩阵, 由S的特征值组成

- $S=(Q \Lambda) (Q^{T})$ , 所以这个矩阵由$Q\Lambda$的列向量组成:
- $$Q\Lambda=\left[\begin{array}{ccc}\mid & & \mid \\
q_{1} & \ldots & q_{n} \\
\mid & & \mid\end{array}\right]\left[\begin{array}{ccc}
\lambda_1 & &  \\& \ddots &  \\ & & \lambda_n
\end{array}\right]=\left[\begin{array}{ccc}\mid & & \mid \\
\lambda_1q_{1} & \ldots & \lambda_nq_{n} \\
\mid & & \mid\end{array}\right]$$

---
$$S=(Q \Lambda) Q^{\mathrm{T}}=
\lambda_{1} \boldsymbol{q}_{1}\boldsymbol{q}_{1}^{\mathrm{T}}+
\lambda_{2} \boldsymbol{q}_{2}\boldsymbol{q}_{2}^{\mathrm{T}}+
\cdots+
\lambda_{n} \boldsymbol{q}_{n} \boldsymbol{q}_{n}^{\mathrm{T}}$$
---

- 这样, S就被拆分成了秩为一的小矩阵的加和, 其中每一个小矩阵$\lambda_{i} \boldsymbol{q}_{i}\boldsymbol{q}_{i}^{\mathrm{T}}$也是对称矩阵, 因为这个小矩阵是特征向量$\boldsymbol{q}_{i}$自己与自己的外积$\boldsymbol{q}_{i}\boldsymbol{q}_{i}^{\mathrm{T}}$的$\lambda_i$倍

- 验证: 如果我们计算$Sq_1$:
	- 因为q相互正交, 所以: $\boldsymbol{q}_{2}^{\mathrm{T}}\boldsymbol{q}_{1}=0$
	- 所以:
	$$\lambda_{2} \boldsymbol{q}_{2}\boldsymbol{q}_{2}^{\mathrm{T}}\boldsymbol{q}_{1}=0$$
- 又因为q是单位向量, 所以: $\boldsymbol{q}_{1}^{\mathrm{T}}\boldsymbol{q}_{1}=1$
	$$S\boldsymbol{q}_{1}=
\lambda_{1}\boldsymbol{q}_{1}\boldsymbol{q}_{1}^{\mathrm{T}}\boldsymbol{q}_{1}=\lambda_{1}\boldsymbol{q}_{1}$$
	符合特征向量的定义.

