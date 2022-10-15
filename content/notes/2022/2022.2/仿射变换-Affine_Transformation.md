---
title: "仿射变换-Affine_Transformation"
tags:
- all
- Math/LinearAlgebra
date: "2022-02-10"
---
# 仿射变换 Affine Transformation

<div align="right"> 2022-02-10</div>

Tags: #Math/LinearAlgebra 

仿射变换就是平移后的线性变换:

![](notes/2022/2022.2/assets/img_2022-10-15.gif)
[^1]
Here is an Interaction: 
[Affine transformations / Kjerand Pedersen / Observable](https://observablehq.com/@kjerandp/affine-transformations)
![](notes/2022/2022.2/assets/img_2022-10-15-1.gif)


- 有趣的是, 我们可以在高维度通过线性变换来完成仿射变换[^2]

<iframe src="https://commons.wikimedia.org/wiki/File:Affine_transformations.ogv?embedplayer=yes" width="512" height="512" frameborder="0" ></iframe> 

[^3]

> - 普通矩阵向量乘法总将原点映射至原点，因此无法呈现平移（原点必须映射至其他点）。借由于所有向量上扩增一坐标 “1”，我们将原空间映至更高维空间的一个子集合以进行变换。在该空间中，原本之空间占有了扩长坐标一的1的子集合。 因此原空间的原点可在(0,0, ... 0, 1)。原空间的平移可借由更高维度空间的线性变换来达成（即为[错切变换](https://zh.wikipedia.org/wiki/%E9%8C%AF%E5%88%87 "错切")）。在高维度中的坐标即为 [齐次坐标](https://zh.wikipedia.org/wiki/%E9%BD%8A%E6%AC%A1%E5%BA%A7%E6%A8%99 "齐次坐标")的一例。 假如原空间为欧几里德空间), 则更高维空间为[实射影空间](https://zh.wikipedia.org/wiki/%E5%AE%9E%E5%B0%84%E5%BD%B1%E7%A9%BA%E9%97%B4 "实射影空间")。
> - 使用齐次坐标的优点为，借由相对应矩阵之乘积，可将任意数目的仿射变换[结合](https://zh.wikipedia.org/wiki/%E5%A4%8D%E5%90%88%E5%87%BD%E6%95%B0 "复合函数")为一。此性质被大量运用于 [计算机图形](https://zh.wikipedia.org/wiki/%E8%AE%A1%E7%AE%97%E6%9C%BA%E5%9B%BE%E5%BD%A2 "计算机图形"), [计算机视觉](https://zh.wikipedia.org/wiki/%E8%A8%88%E7%AE%97%E6%A9%9F%E8%A6%96%E8%A6%BA "计算机视觉") 与 [机器人学](https://zh.wikipedia.org/wiki/%E6%9C%BA%E5%99%A8%E4%BA%BA%E5%AD%A6 "机器人学")。[^3]





[^1]: [Understanding Transformations in Computer Vision: | by Felix Liu | Towards Data Science](https://towardsdatascience.com/understanding-transformations-in-computer-vision-b001f49a9e61)
[^2]: [如何通俗地讲解「仿射变换」这个概念？ - 知乎](https://www.zhihu.com/question/20666664)
[^3]: [仿射变换 - 维基百科，自由的百科全书](https://zh.wikipedia.org/zh-cn/%E4%BB%BF%E5%B0%84%E5%8F%98%E6%8D%A2)