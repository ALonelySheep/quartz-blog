---
title: "D2L-65-Attention Cues & Attention Mechanisms"
tags:
- all
- Attention
- DeepLearning
date: "2022-04-20"
---
# 注意力信号 与 注意力机制

<div align="right"> 2022-04-20</div>

Tags: #Attention #DeepLearning 

## Attention Cue
- Attention Cue分为两种: _nonvolitional cue_ 和 _volitional cue_.

> Your **volition** is the power you have to decide something for yourself. 

- 我在这里翻译为"自发的"(_volitional_)和"非自发的"(_nonvolitional_)信号

- Volitional的信号本身就是醒目的. (intrinsically salient and conspicuous)
![300](notes/2022/2022.4/assets/eye-coffee.svg)
- Nonvolitional的信号是你主动去关注的. 比如你想要看书, 所以会去寻找书本的信号.
![300](notes/2022/2022.4/assets/eye-book.svg)

## Attention Mechanism
- 尽管上面的注意力信号分类是粗浅的, 但我们也可以按照这个思路去构造深度学习里面的**注意力机制**(Attention Mechanism).
![](notes/2022/2022.4/assets/qkv.svg)
### New Jargons
- 我们先给两种动机不同的信号起个新名字:
	- **Query**: Volitional Cue
	- **Key**: Nonvolitional Cue

- 并且我们称 intermediate feature representations, 也就是 Sensory Inputs 为 **Value**[^1]

### Incorporate 2 Cues
- 前面我们提到, Query和Key分别代表了两种不同的Attention Cue. 在Attention Mechanism里面, 我们可以将两者通过Attention Pooling结合到一起. 然后与Values一起生成最后的Output.
![](notes/2022/2022.4/assets/qkv.svg)
- One Query + Multiple Key-Value Pairs $\rightarrow$ One Output

- 其实还有其他构造Attention Mechanism的方式.



[^1]: 其实我感觉这个名字起的不是很好, 很多时候并没有value里"结果"的意思