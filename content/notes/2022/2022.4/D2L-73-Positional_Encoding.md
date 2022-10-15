---
title: "D2L-73-Positional_Encoding"
tags:
- all
- PositionalEncoding
- Self-Attention
- DeepLearning
date: "2022-04-27"
---
# 位置编码: 将位置信息加入数据

<div align="right"> 2022-04-27</div>

Tags: #PositionalEncoding #Self-Attention #DeepLearning 


- **为了使用序列的顺序信息**，我们通过在输入表示中添加 **位置编码**（*positional encoding*）来注入**绝对的**或**相对的**位置信息。

- 我觉得D2L讲的很深入很好了: [10.6. Self-Attention and Positional Encoding](https://d2l.ai/chapter_attention-mechanisms/self-attention-and-positional-encoding.html#positional-encoding)

**Highlights:**
![Positional Encoding|300](notes/2022/2022.4/assets/Positional%20Encoding.svg)
- In binary representations, a higher bit has a lower frequency than a lower bit. Similarly, as demonstrated in the heat map below, the positional encoding decreases frequencies along the encoding dimension by using trigonometric functions. Since the outputs are float numbers, such continuous representations are more space-efficient than binary representations.
![](notes/2022/2022.4/assets/output_self-attention-and-positional-encoding_d76d5a_67_0.svg)



