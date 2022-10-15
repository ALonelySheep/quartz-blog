---
title: "Moment Generating Function-MGF"
tags:
- all
- Math/Statistics
date: "2021-12-04"
---
# Moment Generating Function - MGF

<div align="right"> 2021-12-04</div>

Tags: #Math/Statistics 


- **This article covers it all.**
[Moment Generating Function Explained | by Aerin Kim | Towards Data Science](https://towardsdatascience.com/moment-generating-function-explained-27821a739035)


- The moments are the expected values of $X$, e.g., $E(X), E(X^2), E(X^3)$, … etc.

- what is Moment Generating Function (MGF)?
	As its name hints, MGF is literally the function that generates the moments — **E(X), E(X²), E(X³), … , E(X^n).**
	
- $M_{X}(t)=\mathbb{E}\left(e^{t X}\right)$

- 从MGF得到相应的Moment只需要取导数
![](notes/2021/2021.12/assets/img_2022-10-15.png)