---
title: "Normal_Equation_Proof_2_Matrix_Method"
tags:
- all

date: ""
---
## 首先补充一点矩阵的知识:求导、迹的性质

矩阵的求导和矩阵的迹是密不可分的

### 矩阵的求导

![矩阵的求导](notes/2021/2021.8/矩阵的求导.md)

### 矩阵的迹

![矩阵迹的性质](notes/2021/2021.8/矩阵迹的性质.md)

### 证明中需要的一些其他性质

结合矩阵的求导, 还有以下性质:
- $$\nabla_{A} \operatorname{tr} A B =B^{T}$$ 
	- 结合[这里](notes/2021/2021.8/矩阵迹的性质.md#^tracecommutative)对$\operatorname{tr} A B$的推导, 可以看出对于矩阵$A$每一个位置单独求偏导, 都会得到$b_{ji}$, 即$B^T$对应的位置.
	- 或者可以从导数的角度来证明:
	标量函数$f=\operatorname{tr}AB$
	$$\begin{align}  
	df &= d\ \operatorname{tr}AB  \\
	   &= \operatorname{tr}d(AB) \\
	   &= \operatorname{tr}BdA \\
	   \end{align}$$
	   联系:![矩阵导数与微分的联系](notes/2021/2021.8/矩阵的求导.md#^e0894d)
	所以: $$\frac{\partial f}{\partial A}=B^T$$
	证毕
- $$\nabla_{A^{T}} f(A) =\left(\nabla_{A} f(A)\right)^{T}$$ 
$$\begin{align}
\nabla_{A^T} f(A)
&=\left[\begin{array}{ccc}
\frac{\partial f}{\partial A^T_{11}} & \cdots & \frac{\partial f}{\partial A^T_{1 n}} \\
\vdots & \ddots & \vdots \\
\frac{\partial f}{\partial A^T_{m 1}} & \cdots & \frac{\partial f}{\partial A^T_{m n}}
\end{array}\right]\\
&=\left[\begin{array}{ccc}
\frac{\partial f}{\partial A_{11}} & \cdots & \frac{\partial f}{\partial A_{1 n}} \\
\vdots & \ddots & \vdots \\
\frac{\partial f}{\partial A_{m 1}} & \cdots & \frac{\partial f}{\partial A_{m n}}
\end{array}\right]^T\\
&=\left(\nabla_{A} f(A)\right)^{T}
\end{align}$$

- $$\nabla_{A} \operatorname{tr} A B A^{T} C =C A B+C^{T} A B^{T} $$
	证明: 
	标量函数$f=\operatorname{tr} A B A^{T} C$
	$$\begin{align}  
	df &= d\ \operatorname{tr} (A B A^{T} C)  \\
	   &= \operatorname{tr}(d(A B A^{T} C)) \\
	   &= \operatorname{tr}(dA (B A^{T} C)+A dB (A^{T} C)+(A B) dA^{T} (C)+(A B A^{T}) dC) \\
	   &= \operatorname{tr}(dA (B A^{T} C)+(A B) dA^{T} (C)) \\
	   &= \operatorname{tr}((B A^{T} C)dA)+\operatorname{tr}( (CA B) dA^{T})) \\
	&= \operatorname{tr}((B A^{T} C)dA)+\operatorname{tr}( (CAB)^T (dA^{T})^T)) \\
	&= \operatorname{tr}((B A^{T} C)dA)+\operatorname{tr}( (CAB)^T dA) \\
	&= \operatorname{tr}\left(\left(BA^{T}C+ (CAB)^T\right) dA\right)
	   \end{align}$$
	所以: $$\frac{\partial f}{\partial A}=\left(BA^{T}C+ (CAB)^T\right)^T=C A B+C^{T} A B^{T}$$
	证毕
	
- $$\nabla_{A}|A| =|A|\left(A^{-1}\right)^{T}$$
	参见吴恩达讲义里面的证明:
	![](notes/2021/2021.7/assets/Pasted%20image%2020210817213317.png)
	
	
## 然后是证明:
内积的另一种表述:  $z^{T} z=\sum_{i} z_{i}^{2}$ :
$$
\begin{aligned}
\frac{1}{2}(X \theta-\vec{y})^{T}(X \theta-\vec{y}) &=\frac{1}{2} \sum_{i=1}^{m}\left(h_{\theta}\left(x^{(i)}\right)-y^{(i)}\right)^{2} \\
&=J(\theta)
\end{aligned}
$$
为了最小化 $J$, 我们对 $\theta$求导. 结合上面的补充性质, 我们有:
$$
\nabla_{A^{T} } \operatorname{tr} A B A^{T} C=B^{T} A^{T} C^{T}+B A^{T} C
$$
这个在下面会用到.
求导有:
$$\begin{aligned}
\nabla_{\theta} J(\theta) &=\nabla_{\theta} \frac{1}{2}(X \theta-\vec{y})^{T}(X \theta-\vec{y}) \\
\text{(展开)}&=\frac{1}{2} \nabla_{\theta}\left(\theta^{T} X^{T} X \theta-\theta^{T} X^{T} \vec{y}-\vec{y}^{T} X \theta+\vec{y}^{T} \vec{y}\right) \\
\text{(标量的迹就是它自己)}&=\frac{1}{2} \nabla_{\theta} \operatorname{tr}\left(\theta^{T} X^{T} X \theta-\theta^{T} X^{T} \vec{y}-\vec{y}^{T} X \theta+\vec{y}^{T} \vec{y}\right) \\
&=\frac{1}{2} \nabla_{\theta}\left(\operatorname{tr} \theta^{T} X^{T} X \theta-2 \operatorname{tr} \vec{y}^{T} X \theta\right) \\
\text{(利用上面的推论)}&=\frac{1}{2}\left(X^{T} X \theta+X^{T} X \theta-2 X^{T} \vec{y}\right) \\
&=X^{T} X \theta-X^{T} \vec{y}
\end{aligned}$$

零导数为零, 有$X^{T} X \theta=X^{T} \vec{y}$ , 所以 $\theta=(X^{T} X )^{-1}X^{T} \vec{y}$
证毕. 