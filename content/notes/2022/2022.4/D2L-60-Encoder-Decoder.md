---
title: "D2L-60-Encoder-Decoder"
tags:
- all
- EncoderDecoder
- RNN
- DeepLearning
date: "2022-04-19"
---
# 编码器-解码器架构

<div align="right"> 2022-04-19</div>

Tags: #EncoderDecoder #RNN #DeepLearning 

![](notes/2022/2022.4/assets/encoder-decoder.svg)

- Encoder-Decoder将模型分为两部分, 使得我们可以先用编码器处理不规则的输入, 然后再将输出送入Decoder得到最终结果.
- Encoder-Decoder是一种抽象的模型架构, 可以有许多不同的实现方式.

- 有的时候Decoder也需要Input, 所以上图也可以表示成下面的样子:

![](notes/2022/2022.4/assets/encoder-decoder-cn.svg)
Intuition:
![](notes/2022/2022.4/assets/Encode-decoder-Intuition.svg)

- Encoder-Decoder模型适用于机器翻译等序列转换问题。


