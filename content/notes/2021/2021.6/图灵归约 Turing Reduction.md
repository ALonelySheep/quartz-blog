---
title: "图灵归约 Turing Reduction"
tags:
- all
- Course
- Math
- Cryptography
- TuringReduction
date: ""
---

**把还没解决的问题归约到已经解决的问题上**

**用已经解决的问题去解决还没解决的问题**

> 密码学原理与实践 Page 167
> 
> ![](notes/2021/2021.6/assets/img_2022-10-15-3.png)

假设我们已经存在一个解决问题 A 的算法 $G(x)$

一个A到B的图灵归约即利用$G(x)$构造一个解决问题B的算法$H(x)$, 并且$H(x)$是多项式时间的.

> ![](notes/2021/2021.6/assets/img_2022-10-15-4.png)

> https://zhuanlan.zhihu.com/p/194313998
> 这篇文章译自[reductions-and-jokes](https://rjlipton.wpcomstaging.com/2020/02/28/reductions-and-jokes/)
> 
> > 一个物理学家和一个数学家正坐在教师休息室里。突然间，休息室里的咖啡机着火了。物理学家就拿了一个垃圾桶，把里面的垃圾清空，跑到水池前，给垃圾桶灌满水，随后扑灭了火。由于这个咖啡机着过一次火了，大家都同意把垃圾桶装满水放在这个咖啡机旁边。  
> > 第二天，同样的两个人又坐在同样的休息室里，咖啡机又一次着火了。这一次，数学家站了起来，把装满水的垃圾桶拿了起来，把里面的水倒掉，又放了一些垃圾在里面，交给了物理学家。这样就把问题归约到了一个之前已经解决过的问题上。
> 
> 虽然这个笑话是讽刺数学家的，但确实很好地解释了归约这个概念。其想法很简单：我们现在遇到了个问题，可以把它转化到一个某个已解决的问题上，而不是一定要直接解决这个问题。从这个意义上来说，归约其实是一种比较懒的解决问题的方式。
> 
> Instead of putting out a fire, the following [video](https://thumbs.gfycat.com/DifficultVapidAmericanredsquirrel-size_restricted.gif?fbclid=IwAR2AXbtag_WFTP9bmipr4JOhvViHAQbvEgE8h1oCdG_71IttR28EgcSTqhg) is about retrieving a shoe that is floating away.
> ![https://thumbs.gfycat.com/DifficultVapidAmericanredsquirrel-size_restricted.gif?fbclid=IwAR2AXbtag_WFTP9bmipr4JOhvViHAQbvEgE8h1oCdG_71IttR28EgcSTqhg](https://thumbs.gfycat.com/DifficultVapidAmericanredsquirrel-size_restricted.gif?fbclid=IwAR2AXbtag_WFTP9bmipr4JOhvViHAQbvEgE8h1oCdG_71IttR28EgcSTqhg)


> ## Another Example
> 
> Here is an example of reductions that are not so silly and a little less simple.
> 
> Imagine that Alice and Bob are at it again. Bob wants to be able to multiply integers fast and he plans on building a hardware system that stores the answers in a table. Then his hardware system will be able to compute the product of two integers by just looking up the answers. Okay, there are really better ways to do this, but just play along for the moment.
> 
> [![](https://i0.wp.com/rjlipton.wpcomstaging.com/wp-content/uploads/2020/02/tables2.jpg?resize=200%2C200&ssl=1)](https://i0.wp.com/rjlipton.wpcomstaging.com/wp-content/uploads/2020/02/tables2.jpg?ssl=1)
> 
> Bob’s table is big and he is troubled. The above table has ![{100}](https://s0.wp.com/latex.php?latex=%7B100%7D&bg=ffffff&fg=000000&s=0&c=20201002) entries just to multiply numbers less than ![{10}](https://s0.wp.com/latex.php?latex=%7B10%7D&bg=ffffff&fg=000000&s=0&c=20201002). Clearly for a more extensive table the cost grows fast. He asks his friend Alice for some help. She says:”Just store the diagonal values and I can show you how to handle the general case.” Here is her old trick.
> 
> ![\displaystyle  a \times b = \frac{\left(\left(a + b\right)^{2} - a^{2} - b^{2}\right)}{2}. ](https://s0.wp.com/latex.php?latex=%5Cdisplaystyle++a+%5Ctimes+b+%3D+%5Cfrac%7B%5Cleft%28%5Cleft%28a+%2B+b%5Cright%29%5E%7B2%7D+-+a%5E%7B2%7D+-+b%5E%7B2%7D%5Cright%29%7D%7B2%7D.+&bg=ffffff&fg=000000&s=0&c=20201002)
> 
> Using this allows Bob to just store the diagonal of the multiplication table, and forget all the rest. It is a powerful reduction that shows:
> 
> _One can reduce integer multiplication to addition and taking the square of a number._
> 
> For example,
> 
> ![\displaystyle  \begin{array}{rcl}        37 \times 15 &=& ( 52^{2} - 37^{2} - 15^{2} )/2 \\              &=& (2704 - 1369 - 225)/2 \\            &=& 555. \end{array} ](https://s0.wp.com/latex.php?latex=%5Cdisplaystyle++%5Cbegin%7Barray%7D%7Brcl%7D++++++++37+%5Ctimes+15+%26%3D%26+%28+52%5E%7B2%7D+-+37%5E%7B2%7D+-+15%5E%7B2%7D+%29%2F2+%5C%5C++++++++++++++%26%3D%26+%282704+-+1369+-+225%29%2F2+%5C%5C++++++++++++%26%3D%26+555.+%5Cend%7Barray%7D+&bg=ffffff&fg=000000&s=0&c=20201002)




