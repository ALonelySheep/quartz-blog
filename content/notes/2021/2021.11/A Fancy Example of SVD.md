---
title: "A Fancy Example of SVD"
tags:
- all

date: ""
---
==Example==

Consider the $4 × 5$ matrix

  

$$\mathbf{M} = \begin{bmatrix}

 1 & 0 & 0 & 0 & 2 \\

 0 & 0 & 3 & 0 & 0 \\

 0 & 0 & 0 & 0 & 0 \\

 0 & 2 & 0 & 0 & 0

 \end{bmatrix}

$$

  

A singular value decomposition of this matrix is given by $UΣV^⁎$

  

$$\begin{align}

 \mathbf{U} &= \begin{bmatrix}

 \color{Green}0 & \color{Blue}-1 & \color{Cyan}0 & \color{Emerald}0 \\

 \color{Green}-1 & \color{Blue}0 & \color{Cyan}0 & \color{Emerald}0 \\

 \color{Green}0 & \color{Blue}0 & \color{Cyan}0 & \color{Emerald}-1 \\

 \color{Green}0 & \color{Blue}0 & \color{Cyan}-1 & \color{Emerald}0

 \end{bmatrix} \\[6pt]

  

 \boldsymbol{\Sigma} &= \begin{bmatrix}

 3 & 0 & 0 & 0 & \color{Gray}\mathit{0} \\

 0 & \sqrt{5} & 0 & 0 & \color{Gray}\mathit{0} \\

 0 & 0 & 2 & 0 & \color{Gray}\mathit{0} \\

 0 & 0 & 0 & \color{Red}\mathbf{0} & \color{Gray}\mathit{0}

 \end{bmatrix} \\[6pt]

  

 \mathbf{V}^* &= \begin{bmatrix}

 \color{Violet}0 & \color{Violet}0 & \color{Violet}-1 & \color{Violet}0 &\color{Violet}0 \\

 \color{Plum}-\sqrt{0.2}& \color{Plum}0 & \color{Plum}0 & \color{Plum}0 &\color{Plum}-\sqrt{0.8} \\

 \color{Magenta}0 & \color{Magenta}-1 & \color{Magenta}0 & \color{Magenta}0 &\color{Magenta}0 \\

 \color{Orchid}0 & \color{Orchid}0 & \color{Orchid}0 & \color{Orchid}1 &\color{Orchid}0 \\

 \color{Purple} - \sqrt{0.8} & \color{Purple}0 & \color{Purple}0 & \color{Purple}0 & \color{Purple}\sqrt{0.2}

 \end{bmatrix}

\end{align}$$

  

The scaling matrix $\mathbf{\Sigma}$ is zero outside of the diagonal (grey italics) and one diagonal element is zero (red bold). Furthermore, because the matrices $U$ and $V^T$ are unitary matrix|unitary, multiplying by their respective conjugate transposes yields identity matrix|identity matrices, as shown below.  In this case, because $U$ and $V^T$ are real valued, each is an orthogonal matrix.

  

$$\begin{align}

 \mathbf{U} \mathbf{U}^* &=

 \begin{bmatrix}

 1 & 0 & 0 & 0 \\

 0 & 1 & 0 & 0 \\

 0 & 0 & 1 & 0 \\

 0 & 0 & 0 & 1

 \end{bmatrix} = \mathbf{I}_4 \\[6pt]

 \mathbf{V} \mathbf{V}^* &=

 \begin{bmatrix}

 1 & 0 & 0 & 0 & 0 \\

 0 & 1 & 0 & 0 & 0 \\

 0 & 0 & 1 & 0 & 0 \\

 0 & 0 & 0 & 1 & 0 \\

 0 & 0 & 0 & 0 & 1

 \end{bmatrix} = \mathbf{I}_5

\end{align}$$

  

This particular singular value decomposition is not unique.  Choosing $\mathbf V$ such that

$$\mathbf{V}^* = \begin{bmatrix}

 \color{Violet}0 & \color{Violet}1 & \color{Violet}0 & \color{Violet}0 & \color{Violet}0 \\

 \color{Plum}0 & \color{Plum}0 & \color{Plum}1 & \color{Plum}0 & \color{Plum}0 \\

 \color{Magenta}\sqrt{0.2} & \color{Magenta}0 & \color{Magenta}0 & \color{Magenta}0 & \color{Magenta}\sqrt{0.8} \\

 \color{Orchid}\sqrt{0.4} & \color{Orchid}0 & \color{Orchid}0 & \color{Orchid}\sqrt{0.5} & \color{Orchid}-\sqrt{0.1} \\

 \color{Purple}-\sqrt{0.4} & \color{Purple}0 & \color{Purple}0 & \color{Purple}\sqrt{0.5} & \color{Purple}\sqrt{0.1}

\end{bmatrix}$$

  

is also a valid singular value decomposition.