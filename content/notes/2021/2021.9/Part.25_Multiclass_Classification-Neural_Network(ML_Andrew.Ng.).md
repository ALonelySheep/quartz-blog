---
title: "Part.25_Multiclass_Classification-Neural_Network(ML_Andrew.Ng.)"
tags:
- all
- MachineLearning
- NeuralNetwork
date: "2021-09-12"
---
# Multiclass Classification

<div align="right"> 2021-09-12</div>

Tags: #MachineLearning #NeuralNetwork 



![](notes/2021/2021.9/assets/img_2022-10-15-9.png)

We can define our set of resulting classes as y:
$$
y^{(i)}=\left[\begin{array}{l}
1 \\
0 \\
0 \\
0
\end{array}\right],\left[\begin{array}{l}
0 \\
1 \\
0 \\
0
\end{array}\right],\left[\begin{array}{l}
0 \\
0 \\
1 \\
0
\end{array}\right],\left[\begin{array}{l}
0 \\
0 \\
0 \\
1
\end{array}\right]
$$
Each $y^{(i)}$ represents a different image corresponding to either a car, pedestrian, truck, or motorcycle. **The inner layers, each provide us with some new information which leads to our final hypothesis function.** The setup looks like:
$$
\left[\begin{array}{c}
x_{0} \\
x_{1} \\
x_{2} \\
\cdots \\
x_{n}
\end{array}\right] \rightarrow\left[\begin{array}{c}
a_{0}^{(2)} \\
a_{1}^{(2)} \\
a_{2}^{(2)} \\
\ldots
\end{array}\right] \rightarrow\left[\begin{array}{c}
a_{0}^{(3)} \\
a_{1}^{(3)} \\
a_{2}^{(3)} \\
\cdots
\end{array}\right] \rightarrow \ldots \rightarrow\left[\begin{array}{l}
h_{\Theta}(x)_{1} \\
h_{\Theta}(x)_{2} \\
h_{\Theta}(x)_{3} \\
h_{\Theta}(x)_{4}
\end{array}\right]
$$