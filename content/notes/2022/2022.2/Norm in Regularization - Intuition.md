---
title: "Norm in Regularization - Intuition"
tags:
- all
- Norm
- Regularization
- DeepLearning
- MachineLearning
date: "2022-02-14"
---
# Norm in Regularization - Intuition

<div align="right"> 2022-02-14</div>

Tags: #Norm #Regularization #DeepLearning #MachineLearning 


![](notes/2022/2022.2/assets/img_2022-10-15-31.png)
### L2 Norm $\ell_{2}$ in Regularization
- L2 Norm 的等高线是圆形的
- 使用$L_2$范数的一个原因是它对权重向量的大分量施加了巨大的惩罚。 这使得我们的学习算法偏向于在大量特征上均匀分布权重的模型。 在实践中，这可能使它们对单个变量中的观测误差更为稳定。[^2]
- 使用L2正规化在训练时"更稳定".
	 ![](notes/2022/2022.2/assets/img_2022-10-15-32.png)
	 - 因为在进行[小批量随机梯度下降](notes/2022/2022.1/D2L-10-小批量随机梯度下降.md)的时候, 每次训练获得的数据具有一定随机性, 从上图中可以看到, L2正则项在 $J(\theta)$ 出现变化的时候梯度变化更小, 而L1正则项变化较大[^1]

- [GeoGebra的直观互动例子](https://www.geogebra.org/m/jgq2yu36)
	![400](notes/2022/2022.2/assets/img_2022-10-15-33.png)


### L1 Norm $\ell_{2}$ in Regularization
- L1 Norm的等高线是方形的, 在正方形上面每一点的取值相同.
- L1 范数形状更"尖锐", 从图形中可以看出正方形的四个角都在坐标轴上, 这使得L1范数找到的"平衡点"很可能将权重集中在一小部分特征上， 而将其他权重清除为零, 也就是说, [L1范数约束后的解很"稀疏", 这在特征选择时是很有用的](notes/2021/2021.8/Why_do_cost_functions_use_the_square_error.md#^269677)

	- 这个视频将L1范数与稀疏性的关系讲的很好: 
		<iframe width="560" height="315" src="https://www.youtube.com/embed/76B5cMEZA4Y" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>

- [GeoGebra的直观互动例子](https://www.geogebra.org/m/abbbqute)
	![400](notes/2022/2022.2/assets/img_2022-10-15-34.png)

### L1 L2 范数约束下的线性回归: LASSO回归 与 岭回归
- 线性回归加上L2范数进行正则化就是岭回归, 岭回归通常在样本特征之间相关性很高的时候使用, "让参数的方差变小", 获得比较稳定的解.

- 线性回归加上L1范数进行正则化则叫做LASSO回归(**Least Absolute Shrinkage and Selection Operator**,  套索回归), LASSO的主要思想是构造一个一阶惩罚函数获得一个精炼的模型, 通过最终确定一些变量的系数为0进行特征筛选。[^3]

下面的文章可以进一步了解这两种方法: 
- [机器学习算法实践-岭回归和LASSO - 知乎](https://zhuanlan.zhihu.com/p/30535220)
- [【机器学习】一文读懂线性回归、岭回归和Lasso回归 - 知乎](https://zhuanlan.zhihu.com/p/88698511)
- [岭回归和最小二乘法的区别是什么？什么时候比较适合用岭回归？ - 知乎](https://www.zhihu.com/question/28221429)

[^1]: [什么是 L1 L2 正规化 正则化 Regularization (深度学习 deep learning) - YouTube](https://www.youtube.com/watch?v=TmzzQoO8mr4)
[^2]: [4.5. 权重衰减 — 动手学深度学习 2.0.0-beta0 documentation](https://zh-v2.d2l.ai/chapter_multilayer-perceptrons/weight-decay.html#id2)
[^3]: [机器学习算法实践-岭回归和LASSO - 知乎](https://zhuanlan.zhihu.com/p/30535220)