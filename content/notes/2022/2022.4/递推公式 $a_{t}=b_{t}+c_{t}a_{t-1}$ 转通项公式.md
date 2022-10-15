---
title: "递推公式 $a_{t}=b_{t}+c_{t}a_{t-1}$ 转通项公式"
tags:
- all
- Math
date: "2022-04-02"
---
# 递推公式 $a_{t}=b_{t}+c_{t}a_{t-1}$ 转通项公式

<div align="right"> 2022-04-02</div>

Tags: #Math 


$$\begin{aligned}
a_{t}=b_{t} &+c_{t} a_{t-1} \\
&+ c_{t}\left(b_{t-1}+c_{t-1} a_{t-2}\right) \\
&\hspace{4.25em}+c_{t-1}\left(b_{t-2}+c_{t-2} a_{t-3}\right) \\
&\hspace{13em}\vdots \\
&\hspace{12.5em}+c_{2}\left(b_{1}+c_{1} a_{0}\right) \\
&\hspace{17.5em}\uparrow\\
&\hspace{17.8em}0\\
\end{aligned}$$
右边:
$$\begin{aligned}
&\textcolor{blue}{b_{t}}+\textcolor{darkorange}{c_{t}}(\textcolor{blue}{b_{t-1}}+\cdots \textcolor{darkorange}{c_{4}}(\textcolor{blue}{b_{3}}+\textcolor{darkorange}{c_{3}}(\textcolor{blue}{b_{2}}+\textcolor{darkorange}{c_{2}} \textcolor{blue}{b_{1}})))\\
=&\textcolor{darkorange}{c_{t}c_{t-1}\cdots c_{4}c_{3}c_{2}}\textcolor{blue}{b_{1}}+\textcolor{darkorange}{c_{t}c_{t-1}\cdots c_{4}c_{3}}\textcolor{blue}{b_{2}}+\textcolor{darkorange}{c_{t}c_{t-1}\cdots c_{4}}\textcolor{blue}{b_{3}}+\cdots+\textcolor{darkorange}{c_{t}}\textcolor{blue}{b_{t-1}}+\textcolor{blue}{b_{t}}
\\=&\textcolor{blue}{b_{t}}+\textcolor{blue}{\sum_{i=1}^{t-1}}\left(\textcolor{darkorange}{\prod_{j=i+1}^{t}c_{j}}\right)\textcolor{blue}{b_{i}}
\\=&b_{t}+\sum_{i=1}^{t-1}\left(\prod_{j=i+1}^{t}c_{j}\right)b_{i}
\end{aligned}$$
故
$$a_{t}=b_{t}+\sum_{i=1}^{t-1}\left(\prod_{j=i+1}^{t}c_{j}\right)b_{i}$$

