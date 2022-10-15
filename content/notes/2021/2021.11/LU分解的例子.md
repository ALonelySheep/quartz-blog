---
title: "LU分解的例子"
tags:
- all


---
将一个简单的$3×3$矩阵A进行LU分解：
$$ A=
        \begin{bmatrix}
           1 & 2 & 3 \\
           2 & 5 & 7 \\
           3 & 5 & 3 \\
        \end{bmatrix}
$$

先将矩阵第一列元素中$a_{11}$以下的所有元素变为0，即
$$ L_{1}A=
        \begin{bmatrix}
           1 & 0 & 0 \\
          -2 & 1 & 0 \\
          -3 & 0 & 1 \\
        \end{bmatrix} \times
        \begin{bmatrix}
           1 & 2 & 3 \\
           2 & 5 & 7 \\
           3 & 5 & 3 \\
        \end{bmatrix}  =
        \begin{bmatrix}
           1 & 2 & 3 \\
           0 & 1 & 1 \\
           0 & -1 & -6 \\
        \end{bmatrix}
$$
再将矩阵第二列元素中$a_{22}$以下的所有元素变为0，即
$$ L_{2}(L_{1}A)=
        \begin{bmatrix}
           1 & 0 & 0 \\
           0 & 1 & 0 \\
           0 & 1 & 1 \\
        \end{bmatrix} \times
        \begin{bmatrix}
           1 & 2 & 3 \\
           0 & 1 & 1 \\
           0 & -1 & -6 \\
        \end{bmatrix}  =
        \begin{bmatrix}
           1 & 2 & 3 \\
           0 & 1 & 1 \\
           0 & 0 & -5 \\
        \end{bmatrix} =U
$$
然后我们将 $L_1, L_2$ 移到等号的右边, 就得到了所有步骤的总和$L$:

$$L= L_{1}^{-1}L_{2}^{-1}=
        \begin{bmatrix}
           1 & 0 & 0 \\
           2 & 1 & 0 \\
           3 & 0 & 1 \\
        \end{bmatrix} \times
        \begin{bmatrix}
           1 & 0 & 0 \\
           0 & 1 & 0 \\
           0 & -1 & 1 \\
        \end{bmatrix} =
        \begin{bmatrix}
           1 & 0 & 0 \\
           2 & 1 & 0 \\
           3 & -1 & 1 \\
        \end{bmatrix} $$
  
Ref: [LU分解 - 维基百科，自由的百科全书](https://zh.wikipedia.org/zh-hans/LU%E5%88%86%E8%A7%A3)
