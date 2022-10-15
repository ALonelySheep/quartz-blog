---
title: "MIT_18.065-Part_10-SVD_in_Action"
tags:
- all
- SVD
- Math/LinearAlgebra
date: "2021-11-17"
---
# SVD in Action

<div align="right"> 2021-11-17</div>

Tags: #SVD #Math/LinearAlgebra 



## Economy SVD
在被分解的矩阵A特别"瘦高"的时候(m>>n), 我们可以只取$U$的前n列, 因为后面的"重要性"不大.
<iframe width="560" height="315" src="https://www.youtube.com/embed/xy3QyyhiuY4?start=246" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>

## Application

### Digital Watermark

<iframe width="560" height="315" src="https://www.youtube.com/embed/QQ8vxj-9OfQ?start=554" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>


## Hands-on Tips
### Plot how the information varies
<iframe width="560" height="315" src="https://www.youtube.com/embed/QQ8vxj-9OfQ?start=610" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>



### SVD Method of Snapshots
- A different way to compute SVD if the data is so large that you can't store it into memory at once.

[SVD Method of Snapshots - YouTube](https://youtu.be/rs63fnUWJkk)


### Relation with Fourier
SVD is kind of a data-driven generation of Fourier Transform/
(如何理解？)

傅里叶变换矩阵就是一个酉矩阵， SVD里面的U也是一个酉矩阵
[Unitary Transformations - YouTube](https://www.youtube.com/watch?v=46Hpy4FiGls&list=PLMrJAkhIeNNSVjnsviglFoY2nXildDCcv&index=10)
