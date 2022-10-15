---
title: "Softmax函数"
tags:
- all

date: ""
---
## Softmax函数
### 直观理解
> Softmax函数的作用隐藏在它关于域的映射关系里: 
> $$\sigma: \mathbb{R}^{K} \rightarrow(0,1)^{K}$$
> 可以看到, Softmax函数将 $K$ 维向量中每一个元素的取值范围由 $\mathbb{R}$ 压缩到 $(0,1)$ , 并且还保证了所有元素加起来等于 $1$, 这就意味着我们可以将每一个元素看作一个概率.

也就是说: 
- Softmax 的作用是把 一个序列，变成概率。
$$\left[\begin{array}{c}
\sigma(\mathbf{z})_{1} \\
\vdots \\
\sigma(\mathbf{z})_{K}
\end{array}\right]=\frac{1}{\sum_{i=1}^{K} e^{z_{i}}}\left[\begin{array}{c}
e^{z_{1}} \\
\vdots \\
e^{z_{K}}
\end{array}\right]=
\left[\begin{array}{c}
P(t=1 \mid \mathbf{z}) \\
\vdots \\
P(t=K \mid \mathbf{z})
\end{array}\right]$$


### 定义
标准Softmax函数 $\sigma: \mathbb{R}^{K} \rightarrow(0,1)^{K}$ 的定义如下所示: 
- 对于 $i=1, \ldots, K$ and $\mathbf{z}=\left(z_{1}, \ldots, z_{K}\right) \in \mathbb{R}^{K}$
 $$\sigma(\mathbf{z})_{i}=\frac{e^{z_{i}}}{\sum_{j=1}^{K} e^{z_{j}}}$$
	- 其中$K$代表类别数, 且$K>1$ (多分类)

另一种表示方法是:
$$\sigma(\mathbf{z})_{i}=\frac{\exp(z_{i})}{\sum_{j=1}^{K} \exp(z_{j})} \quad$$

### 性质
- 容易知道, 输出向量 $\sigma(\mathbf{z})_{i}$ 的所有元素均属于 $(0,1)$ 区间。
- 输出向量中，所有分量相加之和等于1 $$\sum_{i=1}^K\sigma(\mathbf{z})_{i}=\frac{\sum_{i=1}^K e^{z_{i}}}{\sum_{j=1}^{K} e^{z_{j}}}=1$$
- $\mathbf{z}=\left(z_{1}, \ldots, z_{K}\right)$, 单独改变某一个 $z_i$的值, 则 $\sigma(\mathbf{z})_{i}$ 的变化符合Sigmoid函数曲线.
	- <iframe width="560" height="315" src="https://www.youtube.com/embed/ytbYRIN0N4g?start=157" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>

- 如果 $\mathbf{z}$ 中所有元素同时加减相同的值, 比如: $\mathbf{z}=\left(z_{1}, \ldots, z_{K}\right)\rightarrow\mathbf{z}=\left(z_{1}+1, \ldots, z_{K}+1\right)$ , 则根据定义, 相当于分子分母同时乘以一个系数 $e^i$, 结果不变.
	- 这引出了一个有趣的点: Softmax回归的参数是 "over-parameterized", 意味着同样的结果, Softmax的参数可能不唯一: [[notes/2022/2022.2/Softmax_Regression_is_Over-parameterized]]
- 同样, 如果所有元素乘以一个系数, 则会改变结果向量的"突起程度": 
	- <iframe width="560" height="315" src="https://www.youtube.com/embed/ytbYRIN0N4g?start=288" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>
	- 如果系数大于1, 会增加结果向量内部的差异
	- 如果系数小于1, 则会减小结果向量内部的差异(变得更平缓)


### 导数
- 在反向传播时我们需要计算Softmax函数的梯度. 
- 我们定义 $\Sigma_{K}=\sum_{i=1}^{K} e^{z_{i}}$ , for $c=1, \cdots, K$. 所以 $y_{i}=e^{z_{i}} / \Sigma_{K}$. 
- 那么输出 $\mathbf{y}$ 关于输入 $\mathbf{z}$ 的导数 $\partial y_{i} / \partial z_{j}$  为: (需要分情况讨论)
$$\begin{aligned}
&\text { if } i=j: \frac{\partial y_{i}}{\partial z_{i}}=\frac{\partial \frac{e^{z_{i}}}{\Sigma_{K}}}{\partial z_{i}}=\frac{e^{z_{i}} \Sigma_{K}-e^{z_{i}} e^{z_{i}}}{\Sigma_{K}^{2}}=\frac{e^{z_{i}}}{\Sigma_{K}} \frac{\Sigma_{K}-e^{z_{i}}}{\Sigma_{K}}=\frac{e^{z_{i}}}{\Sigma_{K}}\left(1-\frac{e^{z_{i}}}{\Sigma_{K}}\right)=y_{i}\left(1-y_{i}\right) \\
&\text { if } i \neq j: \frac{\partial y_{i}}{\partial z_{j}}=\frac{\partial \frac{e^{z_{i}}}{\Sigma_{K}}}{\partial z_{j}}=\frac{0-e^{z_{i}} e^{z_{j}}}{\Sigma_{K}^{2}}=-\frac{e^{z_{i}}}{\Sigma_{K}} \frac{e^{z_{j}}}{\Sigma_{K}}=-y_{i} y_{j}
\end{aligned}$$
注意: 如果 $i=j$ 那么这个导数和[Sigmoid_Function](notes/2021/2021.8/Sigmoid_Function.md)的导数很相似.

- Funny Version: [The SoftMax Derivative, Step-by-Step!!! - YouTube](https://www.youtube.com/watch?v=M59JElEPgIg)
