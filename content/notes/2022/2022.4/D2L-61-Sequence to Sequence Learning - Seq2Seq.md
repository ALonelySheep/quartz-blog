---
title: "D2L-61-Sequence to Sequence Learning - Seq2Seq"
tags:
- all
- Seq2Seq
- EncoderDecoder
- DeepLearning
- RNN
date: "2022-04-19"
---
# Seq2Seq: 序列到序列模型

<div align="right"> 2022-04-19</div>

Tags: #Seq2Seq #EncoderDecoder #DeepLearning #RNN 

- Seq2Seq也就是Sequence to Sequence, 顾名思义, 它实现的是一种序列到另一种序列的转换(比如从英语到中文).
- Seq2Seq符合[Encoder-Decoder](notes/2022/2022.4/D2L-60-Encoder-Decoder.md)架构

![](notes/2022/2022.4/assets/seq2seq.svg)
## 总览
- 如上图所示, 首先Encoder输入长度可变的序列， 并将其转换为固定形状的隐状态。然后隐状态输入Decoder, 解码器根据隐状态和输入来生成最后的输出.
![](notes/2022/2022.4/assets/seq2seq-details.svg)
- 我们如何将Encoder的结果输入到Decoder呢? 其实有两个方式:
	1. 我们可以利用Encoder最后的隐状态来初始化Decoder的隐状态.
		- 这要求Encoder和Decoder的隐藏层大小是一样的.
	
	2. 我们可以把Encoder最后的隐状态作为Decoder输入的一部分. 
		- 也就是说, Decoder每一次的输入既包括前一个词, 又包括Encoder的隐状态.
	
	- 这两种方式可以同时使用.

### Encoder
#### 上下文变量: Encoder的输出
- Encoder不仅将长度不定的序列转换为固定长度的上下文变量 $\mathbf c$, 也将序列所含语义特征也提取到了 $\mathbf c$ 里面.

- 形式化地说, 
	- 隐状态同时取决于输入和上一个隐状态 
	$$\mathbf{h}_t = f(\mathbf{x}_t, \mathbf{h}_{t-1}) $$
	- 而上下文变量则是所有隐状态的综合:
	$$\mathbf{c} =  q(\mathbf{h}_1, \ldots, \mathbf{h}_T)$$
	- 在上面的叙述中做了简化: 上下文变量就是最后一个隐状态: $\mathbf c= \mathbf{h}_T$

#### Encoder的模型选择
- 我们可以使用普通的RNN作为Encoder, 当然也可以使用GRU, LSTM... 
	- 使用LSTM的时候, Cell State也是隐状态的一部分

- 我们可以使用Bi-directional的RNN来作为编码器, 其实双向RNN经常被用在Encoder里面.

### Decoder
解码器需要根据之前所有的预测 $y_1, \ldots, y_{t'-1}$ 和context variable $\mathbf{c}$ 来预测下一个元素 $y_{t'}$, 即:
$$P(y_{t'} \mid y_1, \ldots, y_{t'-1}, \mathbf{c})$$
- 根据RNN的计算方式, Decoder首先根据 $y_{t^\prime-1}, \mathbf{c}, \mathbf{s}_{t^\prime-1}$ 来更新当前时间步的隐变量:
$$\mathbf{s}_{t^\prime} = g(y_{t^\prime-1}, \mathbf{c}, \mathbf{s}_{t^\prime-1})$$
- 然后根据隐变量用输出层的MLP和Softmax来生成对应的输出:
	$$\mathbf{o_{t^\prime}}=p(\mathbf{s}_{t^\prime})$$
	- 也就是计算条件概率分布 $P(y_{t'} \mid y_1, \ldots, y_{t'-1}, \mathbf{c})$

![](notes/2022/2022.4/D2L-53-循环神经网络RNN.md#^ba5f9a)

## Loss Function
- 对于softmax的输出， 我们可以通过计算[交叉熵损失函数](notes/2022/2022.2/D2L-14-Cross%20Entropy%20as%20Loss.md)来进行优化。
- 但是为了进行批量训练, 我们对序列进行了pad, 在计算损失的时候需要将pad排除在外.

![](notes/2022/2022.4/assets/seq2seq.ipynb)

## Train
- 在训练的时候, `<bos>` + 正确序列会被输入到Decoder里面, 这被称为*Teacher Forcing*
![](notes/2022/2022.4/assets/seq2seq.svg)
## Predict
- 在预测的时候, Decoder的输出被用作下一个时间步的输入. 
	- 在输出为`<eos>`或者长度大于num_steps的时候停止输出:
![](notes/2022/2022.4/assets/seq2seq-predict.svg)
## Evaluate
- 一个序列越长, 成功翻译它的难度就更大. 为了平衡不同句子长度的预测难度, 我们使用BLEU来作为输出效果的评价标准. 
	- 之前我们使用的都是[困惑度 Perplexity](notes/2022/2022.4/D2L-53-循环神经网络RNN.md#RNN的评估指标%20困惑度%20Perplexity)

[D2L-62-BLEU (Bilingual Evaluation Understudy)](notes/2022/2022.4/D2L-62-BLEU%20(Bilingual%20Evaluation%20Understudy).md)