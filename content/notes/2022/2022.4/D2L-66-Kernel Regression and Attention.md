---
title: "D2L-66-Kernel Regression and Attention"
tags:
- all
- KernelRegression
- Attention
- DeepLearning
date: "2022-04-20"
---
# Kernel Regression And Attention

<div align="right"> 2022-04-20</div>

Tags: #KernelRegression #Attention #DeepLearning 

- Nadaraya-Watson kernel regression is an example of machine learning with attention mechanisms.

## 更一般化的Attention Pooling
- 在Kernel Regression里面, Estimator有如下形式:
$$f(x) = \sum_{i=1}^n \frac{K(x - x_i)}{\sum_{j=1}^n K(x - x_j)} y_i$$
其中 $x$ 对应query, 而 $(x_i, y_i)$ 是key-value pair.

- 其中attention pooling的部分其实只包括: $$\frac{K(x - x_i)}{\sum_{j=1}^n K(x - x_j)}$$
它综合query里面的volitional cue和key里面的nonvolitional cue, 和value $y_i$ 一起生成最后的结果.
![](notes/2022/2022.4/assets/qkv.svg)
- Kernel Regression只是注意力机制一个简单的特例. 我们可以将Attention Pooling抽象成更一般的形式: $$f(x) = \sum_{i=1}^n \alpha(x, x_i) y_i$$
其中 $\alpha(x, x_i)$ 代表 _Attention Weight_ , 表示query $x$ 和 key $x_i$ 一起生成的注意力权重, 对应着value $y_i$.

- 在[Kernel Regression 里面的采用高斯核的时候](notes/2022/2022.4/D2L-64-Kernel%20Regression.md#^33f5b4), 我们可以可视化拟合后的注意力权重$\alpha(x, x_i)$如下所示:
![](notes/2022/2022.4/assets/output_nadaraya-watson_61a333_56_0.svg)
- 其中testing inputs代表query $x$, training inputs代表keys $x_i$. 
- 可以看到两者之前的注意力权重和两者之间的距离呈正相关, 距离越近, 权重越大.

### 总结
- Kernel Regression里面的Attention Pooling是所有value $y_i$ (训练输出)的加权平均. 其中权重就是 $\alpha(x, x_i)$ , 其值取决于query $x$ 和 key $x_i$

## Parameterized Kernel Regression
- Attention Pooling可以是**nonparametric**的, 也可以是**parametric**的, 下面便是一个例子:
- 我们可以很容易在Kernel Regression里面加入可学习的参数, 提高模型的性能. 当然这同时也会改变Attention weight的分布.
- 参数化的Kernel Regression可以表示如下(依然采用高斯函数作为核函数)
$$\begin{split}\begin{aligned}f(x) &= \sum_{i=1}^n \alpha(x, x_i) y_i \\&= \sum_{i=1}^n \frac{\exp\left(-\frac{1}{2}((x - x_i)w)^2\right)}{\sum_{j=1}^n \exp\left(-\frac{1}{2}((x - x_j)w)^2\right)} y_i \\&= \sum_{i=1}^n \mathrm{softmax}\left(-\frac{1}{2}((x - x_i)w)^2\right) y_i.\end{aligned}\end{split}$$
- 训练的结果如下:
![](notes/2022/2022.4/assets/output_nadaraya-watson_61a333_128_0.svg)
- 可以看到, 加入了weight的Attention Weight变得更集中了:

![](notes/2022/2022.4/assets/output_nadaraya-watson_61a333_140_0.svg)