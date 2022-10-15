---
title: "Why_do_cost_functions_use_the_square_error"
tags:
- all
- MachineLearning
- CostFunction
- MeanSquareError
date: "2021-07-31"
---
# Why do cost functions use the square error?

<div align="right"> 2021-07-31</div>

Tags: #MachineLearning #CostFunction #MeanSquareError

Reference: [StackExchange: why-do-cost-functions-use-the-square-error?](https://datascience.stackexchange.com/questions/10188/why-do-cost-functions-use-the-square-error?newreg=50bfd55599464f059209bd22b6898660)

StackExchange上面一个关于均方差的一个很好的解释, 翻译如下:

## Question:
>I'm just getting started with some machine learning, and until now I have been dealing with linear regression over one variable.
I have learnt that there is a hypothesis, which is:
$h_{\theta}(x)=\theta_{0}+\theta_{1} x$
To find out good values for the parameters $\theta_{0}$ and $\theta_{1}$ we want to minimize the difference between the calculated result and the actual result of our test data. So we subtract
$h_{\theta}\left(x^{(i)}\right)-y^{(i)}$
for all $i$ from 1 to $m$. Hence we calculate the sum over this difference and then calculate the average by multiplying the sum by $\frac{1}{m}$. So far, so good. This would result in:
$\frac{1}{m} \sum_{i=1}^{m} \left(h_{\theta}\left(x^{(i)}\right)-y^{(i)}\right)$
But this is not what has been suggested. Instead the course suggests to take the square value of the difference, and to multiply by $\frac{1}{2 m}$. So the formula is:
$\frac{1}{2 m} \sum_{i=1}^{m}\left(h_{\theta}\left(x^{(i)}\right)-y^{(i)}\right)^{2}$
Why is that? Why do we use the square function here, and why do we multiply by $\frac{1}{2 m}$ instead of $\frac{1}{m} ?$


我是一个机器学习的初学者, 现在正在学习一元线性回归问题.
我学到了下面这个假设函数:
$h_{\theta}(x)=\theta_{0}+\theta_{1} x$
为了找到参数$\theta_{0}$ 和 $\theta_{1}$ 的最优值, 我们需要使预测值与真实值之间的误差最小, 所以我们把他们相减: $h_{\theta}\left(x^{(i)}\right)-y^{(i)}$  其中 $i$ 取遍 $1$ 到 $m$.
然后我们计算所有误差的和, 并且乘上 $\frac{1}{m}$得到误差的平均数, 得到:
$\frac{1}{m} \sum_{i=1}^{m} \left(h_{\theta}\left(x^{(i)}\right)-y^{(i)}\right)$
但是这并不是正确的公式, 课程里面说我们需要把误差进行平方, 然后乘以$\frac{1}{2 m}$, 所以应该是
$\frac{1}{2 m} \sum_{i=1}^{m}\left(h_{\theta}\left(x^{(i)}\right)-y^{(i)}\right)^{2}$
为什么要这样做? 为什么我们需要将误差进行平方, 并且乘上$\frac{1}{2 m}$ 而不是 $\frac{1}{m} ?$

## Answer:
Your loss function would not work because it incentivizes setting $\theta_{1}$ to any finite value and $\theta_{0}$ to $-\infty$.

Let's call $r(x, y)=\frac{1}{m} \sum_{i=1}^{m} \left(h_{\theta}\left(x^{(i)}\right)-y\right)$ the residual for $h$.

Your goal is to make $r$ as close to zero as possible, not just minimize it. A high negative value is just as bad as a high positive value.

EDIT: You can counter this by artificially limiting the parameter space $\boldsymbol{\Theta}$ (e.g. you want $\left|\theta_{0}\right|<\mathbf{1 0}$ ). In this case, the optimal parameters would lie on certain points on the boundary of the parameter space. See [https://math.stackexchange.com/q/896388/12467](https://math.stackexchange.com/q/896388/12467). This is not what you want.

## Why do we use the square loss
The squared error forces $h(x)$ and $y$ to match. It's minimized at $\boldsymbol{u}=v$, if possible, and is always $\geq 0$, because it's a square of the real number $\boldsymbol{u}-\boldsymbol{v}$.

$|\boldsymbol{u}-\boldsymbol{v}|$ would also work for the above purpose, as would $(\boldsymbol{u}-\boldsymbol{v})^{2 n}$, with $\boldsymbol{n}$ some positive integer. The first of these is actually used (it's called the $\ell_{1}$ loss; you might also come across the $\ell_{2}$ loss, which is another name for squared error).

So, why is the squared loss better than these? This is a *deep* question related to the link between Frequentist and Bayesian inference. In short, the squared error relates to **Gaussian Noise**.

If your data does not fit all points exactly, i.e. $h(x)-y$ is not zero for some point no matter what $\theta$ you choose (as will always happen in practice), that might be because of noise. In any complex system there will be many small **independent** causes for the difference between your model $h$ and reality $y$ : measurement error, environmental factors etc. By the [Central Limit Theorem](https://en.wikipedia.org/wiki/Central_limit_theorem) $(\mathrm{CLT})$, the total noise would be distributed Normally, i.e. according to the **Gaussian distribution**. We want to pick the best fit $\boldsymbol{\theta}$ taking this noise distribution into account. Assume $\boldsymbol{R}=\boldsymbol{h}(\boldsymbol{X})-\boldsymbol{Y}$, the part of $\mathbf{y}$ that your model cannot explain, follows the Gaussian distribution $\mathcal{N}(\mu, \sigma)$. We're using capitals because we're talking about random variables now.

The Gaussian distribution has two parameters, mean $\mu=\mathbb{E}[R]=\frac{1}{m} \sum_{i}\left(h_{\theta}\left(X^{(i)}\right)-Y^{(i))}\right)$ and variance $\sigma^{2}=E\left[R^{2}\right]=\frac{1}{m} \sum_{i}\left(h_{\theta}\left(X^{(i)}\right)-Y^{(i))}\right)^{2}$. See [here](https://math.stackexchange.com/questions/518281/how-to-derive-the-mean-and-variance-of-a-gaussian-random-variable) to understand these terms better.

- Consider $\boldsymbol{\mu}$, it is the systematic error of our measurements. Use $\boldsymbol{h}^{\prime}(\boldsymbol{x})=\boldsymbol{h}(\boldsymbol{x})-\boldsymbol{\mu}$ to correct for systematic error, so that $\boldsymbol{\mu}^{\prime}=\mathbb{E}\left[\boldsymbol{R}^{\prime}\right]=\mathbf{0}$ (exercise for the reader). Nothing else to do here.

- $\sigma$ represents the random error, also called noise. Once we've taken care of the systematic noise component as in the previous point, the best predictor is obtained when $\boldsymbol{\sigma}^{2}=\frac{1}{m} \sum_{i}\left(h_{\theta}\left(X^{(i)}\right)-Y^{(i))}\right)^{2}$ is minimized. Put another way, the best predictor is the one with the tightest distribution (smallest variance) around the predicted value, i.e. smallest variance. **Minimizing the the least squared loss is the same thing as minimizing the variance**! That explains why the least squared loss works for a wide range of problems. The underlying noise is very often Gaussian, because of the $\mathrm{CLT}$, and minimizing the squared error turns out to be the *right* thing to do!

To simultaneously take both the mean and variance into account, we include a _bias_ term in our classifier (to handle systematic error μ), then minimize the square loss.

Followup questions:
- **Least squares loss = Gaussian error. Does every other loss function also correspond to some noise distribution?** Yes. For example, the $\ell_{1}$ loss (minimizing absolute value instead of squared error) corresponds to the [Laplace distribution](https://en.wikipedia.org/wiki/Laplace_distribution) (Look at the formula for the PDF in the infobox -- it's just the Gaussian with  $|\boldsymbol{x}-\boldsymbol{\mu}|$ instead of $(\boldsymbol{x}-\boldsymbol{\mu})^{2}$). A popular loss for probability distributions is the [KL-divergence](https://en.wikipedia.org/wiki/Kullback%E2%80%93Leibler_divergence). -The Gaussian distribution is very well motivated because of the **Central Limit Theorem**, which we discussed earlier. When is the Laplace distribution the right noise model? There are some circumstances where it comes about naturally, but it's more commonly as a regularizer [to enforce **sparsity**](https://math.stackexchange.com/q/1904767/12467): the $\ell_{1}$ loss is the _least convex_ among all convex losses.
 ^b7e1c9
	-  As [Jan](https://datascience.stackexchange.com/users/14904/jan-van-der-vegt) mentions in the comments, the minimizer of _squared_ deviations is the mean and the minimizer of the sum of **absolute** deviations is the **median**. Why would we want to find the median of the residuals instead of the mean? Unlike the mean, the median isn't thrown off by one very large outlier. So, the ℓ1 loss is used for increased robustness. Sometimes a combination of the two is used.
- **Are there situations where we minimize both the Mean and Variance?** Yes. Look up [Bias-Variance Trade-off](https://en.wikipedia.org/wiki/Bias%E2%80%93variance_tradeoff). Here, we are looking at a set of classifiers $h_\theta \in H$ and asking which among them is best. If we ask which _set_ of classifiers is the best for a problem, minimizing both the bias and variance becomes important. It turns out that there is always a trade-off between them and we use **regularization** to achieve a compromise. ^91cd90

## Regarding the $\frac1 2$ term

The 1/2 does not matter and actually, neither does the $m$ - they're both constants. The optimal value of $\theta$ would remain the same in both cases.

- The expression for the gradient becomes prettier with the $\frac1 2$, because the 2 from the square term cancels out.
	- When writing code or algorithms, we're usually concerned more with the gradient, so it helps to keep it concise. You can check progress just by checking the norm of the gradient. The loss function itself is sometimes omitted from code because it is used only for validation of the final answer.
- The $m$ is useful if you solve this problem with gradient descent. Then your gradient becomes the average of $m$ terms instead of a sum, so its' scale does not change when you add more data points.
	- I've run into this problem before: I test code with a small number of points and it works fine, but when you test it with the entire dataset there is loss of precision and sometimes over/under-flows, i.e. your gradient becomes `nan` or `inf`. To avoid that, just normalize w.r.t. number of data points.
- These aesthetic decisions are used here to maintain consistency with future equations where you'll add **regularization** terms. If you include the $m$, the regularization parameter λ will not depend on the dataset size $m$ and it will be more interpretable across problems.


---
你的损失函数并不正确, 因为它倾向于将$\theta_{1}$ 设置为任意有限值,并且将 $\theta_{0}$ 设置为 $-\infty$.

我们不妨把$r(x, y)=\frac{1}{m} \sum_{i=1}^{m} \left(h_{\theta}\left(x^{(i)}\right)-y\right)$ 称为 $h$的残差.

你的目标是让$r$ **尽可能地接近0**, **不是让其尽可能地小**. 一个(绝对值)很大的负数和一个很大的整数一样糟糕.

**附**: 你也可以人为限制参数的变化范围 $\boldsymbol{\Theta}$ (比如: 令$\left|\theta_{0}\right|<\mathbf{1 0}$ ). 此时,你的方法得到的最优参数会是很靠近边界的一个值. (参见 [https://math.stackexchange.com/q/896388/12467](https://math.stackexchange.com/q/896388/12467)). 这并不是我们想要的结果.

## 为什么要使用平方误差
平方误差会让 $h(x)$ 靠近 $y$. 它在 $\boldsymbol{u}=v$的时候取得最小值,  并且因为它是实数 $\boldsymbol{u}-\boldsymbol{v}$的平方, 它始终$\geq 0$.

$|\boldsymbol{u}-\boldsymbol{v}|$ 也有一样的效果,  正如$(\boldsymbol{u}-\boldsymbol{v})^{2 n}$,  ($\boldsymbol{n}$ 是任意正数)也一样. 绝对值误差其实在实际问题中也用到了 (称为 $\ell_{1}$ 误差; 你有时也会看到 $\ell_{2}$ 误差, 这是平方误差的另一种称呼).

所以为什么平方误差比它们都好? 这个问题其实十分深入, 它涉及到了频率学派推断[^1]和贝叶斯推断[^2]之间的联系. 简而言之, 平方误差其实和**高斯噪声**有关. [^3]

如果你的预测值和真实值总是对不上, 也就是无论$\theta$选什么值, 总有一些点$h(x)-y$ 不为零(这很常见). 那么很可能你的数据有噪声. 在一个复杂的系统中, 许多微小但是**相互独立**的因素会使 $h$ 和真实值 $y$不一样 : 比如测量误差, 环境因素等等. 根据[中心极限定理](https://en.wikipedia.org/wiki/Central_limit_theorem)  Central Limit Theorem$(\mathrm{CLT})$ , 整体上这些噪声会呈正态分布, 也就是说, 它们服从 **高斯分布**(也称正态分布). 我们在选取 $\boldsymbol{\theta}$ 的时候, 也需要尽可能地考虑到这些因素. 假设 $\boldsymbol{R}=\boldsymbol{h}(\boldsymbol{X})-\boldsymbol{Y}$, 其中$\mathbf{y}$的有一部分是你的模型无法解释的噪声, 服从高斯分布$\mathcal{N}(\mu, \sigma)$. (我们之所以使用大写字母, 是因为它们都代表随机变量)

高斯分布包含两个变量: 期望值$\mu=\mathbb{E}[R]=\frac{1}{m} \sum_{i} h_{\theta}\left(X^{(i)}\right)-Y^{(i))}$ 和方差 $\sigma^{2}=E\left[R^{2}\right]=\frac{1}{m} \sum_{i}\left(h_{\theta}\left(X^{(i)}\right)-Y^{(i))}\right)^{2}$. 如果你想要了解更多,可以参考 [这个链接](https://math.stackexchange.com/questions/518281/how-to-derive-the-mean-and-variance-of-a-gaussian-random-variable) .

- 对于 $\boldsymbol{\mu}$, 它表示我们测量的系统误差. 我们可以利用$\boldsymbol{h}^{\prime}(\boldsymbol{x})=\boldsymbol{h}(\boldsymbol{x})-\boldsymbol{\mu}$ 来修正系统误差, 所以 $\boldsymbol{\mu}^{\prime}=\mathbb{E}\left[\boldsymbol{R}^{\prime}\right]=\mathbf{0}$ (你可以试一试). 这样我们便已经修正了系统误差.

- $\sigma$ 代表系统的随机误差, 也称作*噪声*. 在修正了系统误差之后, 最好的预测结果在$\boldsymbol{\sigma}^{2}=\frac{1}{m} \sum_{i}\left(h_{\theta}\left(X^{(i)}\right)-Y^{(i))}\right)^{2}$ 最小的时候取得. 换句话说, 最好的预测结果在预测值周围有着最紧密的分布 (最小的方差) . **取平方误差最小值的过程就是取方差最小值的过程**! 这也是最小二乘法[^4]适用面如此之广的原因. 一个系统里面隐藏的噪声常常是成正态分布的, 根据中心极限定理, 我们需要使平方误差最小化!

为了同时考虑数学期望和方差, 我们在判别器里面引入了一个*偏置* (为了修正系统误差μ), 然后最小化平方误差.

进一步的问题:
- **最小二乘法 对应 高斯误差. 其他类型的损失函数也有对应的误差分布吗?** 
	是的. 比如 $\ell_{1}$ 误差 (使绝对值之和最小而不是平方误差最小) 对应着 [拉普拉斯分布(Laplace distribution)](https://en.wikipedia.org/wiki/Laplace_distribution) (注意观察一下拉普拉斯分布的概率密度函数 -- 相当于把高斯分布 $(\boldsymbol{x}-\boldsymbol{\mu})^{2}$  的换成 $|\boldsymbol{x}-\boldsymbol{\mu}|$).[^5] 另一个常见的损失函数对应的误差分布是 [KL-散度（相对熵）](notes/2022/2022.2/KL_Divergence-KL散度.md). 我们之前提到过，因为中心极限定理，高斯分布非常常见. 那么拉普拉斯分布又在什么时候适用呢? 的确有的问题符合拉普拉斯分布, 但是拉普拉斯分布更常被用于"正则化"来[保证**稀疏性(Sparsity)**](https://math.stackexchange.com/q/1904767/12467):  $\ell_{1}$ 损失是所有凸损失函数里面凸起最小的. ^269677
	- 正如Jan在评论里面提到的一样, **平均值**使**平方误差**最小, 而**中位数**使**绝对误差**最小, 为什么($\ell_{1}$损失中)我们要去找残差的中位数而不是均值呢? 这是因为不像平均值, 中位数不会被很大的离群值干扰. 所以$\ell_{1}$损失被用来增加鲁棒性, 有时也会综合利用两者.
	- 附: 答案下方的评论:
		- 抱歉再问一下, 为什么不用绝对值而是用平方误差? – Alexander Suraphel Sep 5 '17 at 16:42
		- 绝对误差也可以, 但是你就是在找中位数而不是平均值了, 你可以用一小组数据来试一试, 观察不同估计值对于两个损失函数的影响 - Jan van der Vegt Oct 26 '17 at 10:58

- **有没有同时最小化数学期望和方差的方法?** 
	有. 参见 [偏差-方差权衡_Bias-Variance Trade-off](https://en.wikipedia.org/wiki/Bias%E2%80%93variance_tradeoff). 比方说我们需要从一堆分类器$h_\theta \in H$ 里面选出最好的分类器.  如果我们需要找出*一组*最好的分类器, 那么就需要同时最小化偏差(Bias, 预期期望和真实值的差距) 和方差. 其实现实中总是需要在这两个量之间做出取舍的, 而这个取舍的过程常常通过**正则化**来实现.

## 关于损失函数里面的$\frac1 2$ 

其实这个 1/2 并不重要,  $m$ 也是 - 他们都是常数.  $\theta$ 的最优值与它们无关.

- 加上 $\frac1 2$会让梯度的表达式更好看, [因为平方项的2被约掉了](notes/2021/2021.8/Linear_Regression&Gradient_Descent.md#^021e6f).
	- 在设计算法和写代码的时候, 我们通常更关注梯度, 所以让梯度的表达式更简洁是很有用的, 你可以通过检查梯度的范数来检查表达式, 而在代码中损失函数有时会被省略掉, 因为它只有在核验最终答案的时候才会被用到.
- 在你使用梯度下降法的时候, $m$ 是很有用的. 这样你的梯度就是$m$项的平均值, 而不是他们的和, 这样在你改变数据量的时候, 梯度的数量级不会改变. 
	- 我遇到过这样的问题: 在少量的数据上面代码运行的很好, 但是当我用整个数据集来测试的时候就出现了精度的损失, 有时候甚至会出现上/下溢, 也就是说, 梯度变成了`nan` 或者 `inf`. 只要用数据项的个数$m$来规格化数据即可
- 这其中也有审美的因素在, 如果将来可能添加更多的公式, 此举可以保持"一致性", 因为这样如果将来的公式里面包含**正则化**的部分, 那么正则化的参数λ将不依赖于数据集大小$m$, 这样更有利于不同规格问题之间的统一.


[^1]: https://en.wikipedia.org/wiki/Frequentist_inference
[^2]: https://en.wikipedia.org/wiki/Bayesian_inference
[^3]: https://en.wikipedia.org/wiki/Gaussian_noise
[^4]: 在高中学习的时候并没有讲解最小二乘法名字的含义, 现在看来, 可以理解成"取最小的平方误差的方法"
[^5]: [Related_Post](notes/2021/2021.8/拉普拉斯分布与高斯分布的联系_Relation_of_Laplace_distribution%20_and_Gaussian_distribution.md)