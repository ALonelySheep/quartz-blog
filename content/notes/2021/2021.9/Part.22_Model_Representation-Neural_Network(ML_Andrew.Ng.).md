---
title: "Part.22_Model_Representation-Neural_Network(ML_Andrew.Ng.)"
tags:
- all
- NeuralNetwork
- MachineLearning
date: "2021-09-11"
---
# Model Representation - NN

<div align="right"> 2021-09-11</div>

Tags: #NeuralNetwork #MachineLearning 

## Hypothesis
![](notes/2021/2021.9/assets/Neuron.svg)
一个神经元(Neuron / Activation Unit)的输出计算公式由如下公式给出:
$$h_\Theta(x)=
a = g(x_0\theta_0+x_1\theta_1+\cdots+x_n\theta_n)$$
是线性的. ($g(x)$是Sigmoid Function)

神经网络的结构如下:
![](notes/2021/2021.9/assets/Network.svg)
可以看出, 每一层(Layer)都有许多节点组成, 所有的e节点一层层组成一个网络, 构成了比线性Hypothesis更复杂的结构.

> **进一步思考:** 为什么一定要是一层一层的呢? 为什么不是图结构的呢?

每一个节点的权重(Weights, 即$\theta$)都构成一个行向量, 所有的行向量组成这一层的权重矩阵$\Theta^{(i)}$
![](notes/2021/2021.9/assets/ThetaWeights.svg)



以上图为例:
$$\begin{aligned}
a_{1}^{(2)} &=g\left(\Theta_{10}^{(1)} x_{0}+\Theta_{11}^{(1)} x_{1}+\Theta_{12}^{(1)} x_{2}+\Theta_{13}^{(1)} x_{3}\right) \\
a_{2}^{(2)} &=g\left(\Theta_{20}^{(1)} x_{0}+\Theta_{21}^{(1)} x_{1}+\Theta_{22}^{(1)} x_{2}+\Theta_{23}^{(1)} x_{3}\right) \\
a_{3}^{(2)} &=g\left(\Theta_{30}^{(1)} x_{0}+\Theta_{31}^{(1)} x_{1}+\Theta_{32}^{(1)} x_{2}+\Theta_{33}^{(1)} x_{3}\right) \\
h_{\Theta}(x) &=a_{1}^{(3)}=g\left(\Theta_{10}^{(2)} a_{0}^{(2)}+\Theta_{11}^{(2)} a_{1}^{(2)}+\Theta_{12}^{(2)} a_{2}^{(2)}+\Theta_{13}^{(2)} a_{3}^{(2)}\right)
\end{aligned}$$

![](notes/2021/2021.9/assets/WeightsMatrix.svg)

The dimensions of these matrices of weights is determined as follows:

If network has $s_j$ units in layer $j$ and $s_{j+1}$ units in layer $j+1$, then $Θ^{(j)}$ will be of dimension $s_{j+1}×(s_j+1)$. If network has $s_j$ units in layer $j$ and $s_{j+1}$ units in layer $j+1$, then $\Theta^{(j)}$ will be of dimension $s_{j+1} \times (s_j + 1)$.

The $+1$ comes from the addition in $\Theta^{(j)}$ of the "bias nodes," $x_0$ and $\Theta_0^{(j)}$. In other words the output nodes will not include the bias nodes while the inputs will.