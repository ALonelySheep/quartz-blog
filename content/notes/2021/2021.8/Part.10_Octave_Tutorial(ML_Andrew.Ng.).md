---
title: "Part.10_Octave_Tutorial(ML_Andrew.Ng.)"
tags:
- all
- Octave
- MachineLearning
date: "2021-08-18"
---
# Octave Tutorial

<div align="right"> 2021-08-18</div>

Tags: #Octave #MachineLearning 

- 还是要在实践中学习Octave


## 为什么吴恩达说Octave比Python好呢?  
- 或许这里涉及到编程与建模的区别? 
		建模的目的是快速实现一个模型, 像 `Matlab` `Octave` `Labview`之类的软件的目标就是快速建模, 而编程语言像是Python之类的, 他们的目的偏向于 建立一个模型的可靠的应用实例, 不仅要实现, 还需要可靠, 性能需要优化
		但是像IPython Console, Jupyter Notebook之类的交互式编程界面是否已经打破了这两个之间的隔阂? 	
		
		
	- Cousera 上面Machine Learning 大概开始于2011
		
		>In October 2011, the "applied" version of the Stanford class (CS229a) was hosted on ml-class.org and launched, with over 100,000 students registered for its first edition[^1]
	- IPython Notebook & Jupyter Notebook 也大致自2011-2015年间逐渐起步, 后来才逐步变得流行起来.
		 >-  IPython在0.12版本（2011年12月）中添加了Notebook界面，2015年更名为Jupyter Notebook[^2]
		 > - 据《大西洋》杂志报道，在2018年初，用户对Jupyter的兴趣超过了Mathematica Notebook界面的流行程度[^2]
	- 故一种合理的猜测是在Andrew Ng 的课程录制的时候, Python 的交互性还没有得到很好的发展与推广, 时至今日(2021), Python作为机器学习建模工具的易用性值得关注.

## 实用技巧: 向量化Vectorization

相比于利用循环, 在需要对一个矩阵里面的元素进行相似的操作的时候, 我们可以利用矩阵乘法来进行相同的操作, 这样我们可以利用**性能优化过的函数**, 加快程序性能. 

E.g. $$\sum x_i^2=\vec X^T \vec X$$ 


[^1]: https://en.wikipedia.org/wiki/Andrew_Ng
[^2]: https://zh.wikipedia.org/zh-sg/Jupyter#Jupyter_Notebook