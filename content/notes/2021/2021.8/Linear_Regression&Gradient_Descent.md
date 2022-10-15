---
title: "Linear_Regression&Gradient_Descent"
tags:
- all


---
%%下面这里我一来就想要写一个最普适的情况, 但是弄得能难懂, 吴恩达在这里比我讲的清晰多了%%

把梯度下降方法应用到我们的线性回归问题里面, 可以得到我们Hypothesis函数参数更新的方法(如何求Cost Function最小值Minimal的方法):
 $$\begin{align*}
 \text{repeat until convergence: }
\lbrace & \newline \theta_0 := & \theta_0 - \alpha \frac{1}{m} \sum\limits_{i=1}^{m}(h_\theta(x^{(i)}) - y^{(i)}) \newline
\theta_1 := & \theta_1 - \alpha \frac{1}{m} \sum\limits_{i=1}^{m}\left((h_\theta(x^{(i)}) - y^{(i)}) x^{(i)}_1\right) \newline
 \rbrace&
 \end{align*}$$

下面我们用一个一般的形式, 详细解释一下应用的过程:

- [Algorithm](notes/2021/2021.8/Part.5_Gradient_Descent(ML_Andrew.Ng.).md#Algorithm)
 这是一个有$n$个变量(Feature  $x$), $n+1$个参数( $\theta$ )的损失函数的梯度下降算法:
$$
\begin{array}{l}
\text { repeat until convergence }\{\\
\begin{array}{cc}
\theta_{j}:=\theta_{j}-\alpha \frac{\Large\partial}{\Large\partial \Large\theta_{j}}   J\left(\theta_{0},\cdots ,\theta_{n}\right) & \text { (simultaneously update }
j=0, \cdots ,j=n)
\end{array}\\
\text { \} }
\end{array}
$$

- [Cost Function](notes/2021/2021.8/Part.3_Linear_Regression(ML_Andrew.Ng.).md#Cost%20Function)
 这是一个平方损失函数
$$J\left(\theta_{0},\cdots ,\theta_{n}\right)=\frac{1}{2 m} \sum_{i=1}^{m}\left(\hat{y}^{(i)}-y^{(i)}\right)^{2}=\frac{1}{2 m} \sum_{i=1}^{m}\left(h_{\theta}\left(x^{(i)}\right)-y^{(i)}\right)^{2}$$

其中 $\mathrm{m}$ 是数据点的个数, $x^{(i)}, y^{(i)}$ 是单个数据点, 这里$x^{(i)}$应当是一个矢量. $\theta_{0}, \cdots ,\theta_{n}$ 是Hypothesis里面的参数, 也是Cost Function里面的变量.

- 我们的Hypothesis是$h_\theta$, 具体的表达式未指明, 暂定为
 $$\begin{align}
 &h_\theta= \theta_n {\large f_{\normalsize n}}(x^{(i)})+\cdots , +\theta_1 {\large f_{\normalsize 1}}(x^{(i)})+\theta_0\quad  \\&and\quad ( { f_{\normalsize 0}}(x^{(i)})=1)
 \end{align}
 $$
 对于我们的线性回归问题, $f_j(x^{(i)})=x_j^{(i)}$
 
下面把Cost Function$:J\left(\theta_{0},\cdots ,\theta_{n}\right)$带入上面的梯度下降公式, 得出具体的梯度下降表达式.

首先是对于$\theta_j$的偏导数计算, 即 $\frac{\Large\partial}{\Large\partial \Large\theta_{j}} J(\theta)$ .
为了使思路清晰, 我们先计算对于一个数据点的平方误差的偏导数$\frac{\Large\partial}{\Large\partial \Large\theta_{j}}  K(\theta)$, 根据导数的性质, 有$\frac{\Large\partial}{\Large\partial \Large\theta_{j}} J(\theta)=\frac{\Large1}{\Large2 m} \sum_{i=1}^{m} \frac{\Large\partial}{\Large\partial \Large\theta_{j}}  K(\theta)$ :

$$
\begin{aligned}
\frac{\partial}{\partial \theta_{j}} K(\theta)
&=\frac{\partial}{\partial \theta_{j}}\left(\hat{y}-y\right)^{2}\\

&=\frac{\partial}{\partial \theta_{j}} \left(h_{\theta}(x)-y\right)^{2} \\

&= 2 \left(h_{\theta}(x)-y\right) \cdot \frac{\partial}{\partial \theta_{j}}\left(h_{\theta}(x)-y\right) \\

&=2\left(h_{\theta}(x)-y\right) \cdot \frac{\partial}{\partial \theta_{j}}\left(\sum_{i=0}^{n} \theta_{i} f_i(x)-y\right) \\

&=2\left(h_{\theta}(x)-y\right) f_{j}(x)

\end{aligned}
$$
带入所有样本点, 计算$\frac{\Large\partial}{\Large\partial \Large\theta_{j}} J(\theta)$:
$$
\begin{aligned}
\frac{\partial}{\partial \theta_{j}} J(\theta)
&=\frac{1}{2 m} \sum_{i=1}^{m} \frac{\partial}{\partial \theta_{j}}  K(\theta)\\

&=\frac{1}{2 m} \sum_{i=1}^{m} 2\left(h_{\theta}(x^{(i)})-y^{(i)}\right) f_{j}(x^{(i)}) \\

&=2\cdot\frac{1}{2}\cdot \frac 1 m \sum_{i=1}^{m} \left(h_{\theta}(x^{(i)})-y^{(i)}\right) f_{j}(x^{(i)}) \\

&=\frac 1 m \sum_{i=1}^{m} \left(h_{\theta}(x^{(i)})-y^{(i)}\right) f_{j}(x^{(i)}) \\

\end{aligned}
$$

- 注意在第三行的$2\cdot{\Large\frac1 2}$, [这里就是为什么Cost Function里面要加入一个$\frac1 2$, 可以让Gradient的形式更好看](notes/2021/2021.8/Part.3_Linear_Regression(ML_Andrew.Ng.).md#Cost%20Function)      ([Regarding the $\frac1 2$ term](notes/2021/2021.8/Why_do_cost_functions_use_the_square_error.md#Regarding%20the%20frac1%202%20term)) ^021e6f

对于我们的线性回归问题, :
$$\frac{\partial}{\partial \theta_{j}} J(\theta) =\frac 1 m \sum_{i=1}^{m} \left(h_{\theta}(x^{(i)})-y^{(i)}\right)x_j^{(i)} $$
再乘上学习率$\alpha$, 即是每一次参数$\theta$变化的大小, 与旧参数相减即得到新的参数.

- [Batch Gradient Descent 批梯度下降 BGD](notes/2021/2021.8/Different_Gradient_Descent_Methods.md#Batch%20Gradient%20Descent%20批梯度下降%20BGD):这里$i$的求和范围是$1$~$m$, 代表每一次都利用所有样本点来更新参数.
