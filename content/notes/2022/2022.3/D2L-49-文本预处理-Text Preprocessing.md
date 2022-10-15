---
title: "D2L-49-文本预处理-Text Preprocessing"
tags:
- all
- Preprocessing
date: "2022-03-08"
---
# 文本预处理

<div align="right"> 2022-03-08</div>

Tags: #Preprocessing 

- 动手是最好的学习: [8.2. 文本预处理 — 动手学深度学习 2.0.0-beta0 documentation](https://zh-v2.d2l.ai/chapter_recurrent-neural-networks/text-preprocessing.html)

- 一些常见的操作:
	1.  将文本作为字符串加载到内存中。
	2.  将字符串拆分为词元（如单词和字符）。Tokenize
	3.  建立一个词表，将拆分的词元映射到数字索引。
	4.  将文本转换为数字索引序列，方便模型操作。

- 语料 in English: corpus

- 语料库中不存在或已删除的任何词元都将映射到一个特定的未知词元 `<unk>` 。 我们可以选择增加一个列表，用于保存那些被保留的词元， 例如：填充词元（ `<pad` >）； 序列开始词元（ `<bos>` ）； 序列结束词元（ `<eos>` ）。
	- 尖括号通常用来表示特殊字符

