---
title: "D2L-76-BERT - Pretrain"
tags:
- all
- BERT
- Pretrain
- DeepLearning
- Transformer
date: "2022-04-30"
---
# BERT: Pretrain

<div align="right"> 2022-04-30</div>

Tags: #BERT #Pretrain #DeepLearning #Transformer 


## Pretrain Tasks
### Task 1 - Masked Language Modeling
#### Motivation
- [语言模型(Language Model)](notes/2022/2022.3/D2L-50-语言模型-传统模型的不足.md#语言模型) 在输出时是从左到右进行的, 使用左侧的上下文来预测未知词元。

- 而 BERT 是双向地对文本进行编码的, 我们需要为模型保留两个方向的上下文. 
	- 所以我们用一种类似"完形填空"的方式来训练模型: 随机 mask 掉序列里面的一些词元, 让模型使用双向上下文以类似自监督的方式预测掩蔽词元. 
	- 这类任务称为**掩蔽语言建模 (模型)** : _masked language model_, MLM.

#### 任务细节

**预测哪些词?  预测多少词?**
- 在 BERT 的训练任务中, 我们 **随机** 选择 **15%** 的词元进行预测

**怎么处理输入?**
- 对于随机选择的 15%:
	- **80%** 的概率: 替换为 `<mask>` 
		- （例如，“this movie is **great**” 变为 “this movie is `<mask>` ")
	- **10%** 的概率: 替换为 `随机词元`
		- （例如，“this movie is **great**” 变为 “this movie is **drink**” ）
	- **10%** 的概率: `不做任何改动`
		- （例如，“this movie is **great**” 变为 “this movie is **great**” ）。

**为什么我们要加入随机词元的 10%和不做任何改动的 10%?**
- 因为在 Finetuning 的时候, 训练数据都是没有 `<mask>` 的语句, 这会导致 Pretrain 和 Finetune 的 mismatch.
- 我们加入 **10%** 和 Finetune 里面一样的数据
- 加入 **10%** 随机数据作为噪声, 让模型不会过多关注 `<mask>` 符号.

### Task 2 - Next Sentence Prediction
#### Motivation
- 尽管 Masked Language Modeling 能够编码双向上下文来表示单个词元，但它不能显式地建模文本对(text pairs)之间的逻辑关系。[^1]
	- 为了帮助BERT理解两个文本序列之间的关系，我们设计了一个二分类任务:  **下一句预测** *(Next Sentence Prediction)* 

#### 任务细节
- 在生成句子对时: 
	- **50%** 的概率它们的确是连续的, 标签为"True"
	- **50%** 的概率第二个句子是从语料库中随机抽取的，标签为"False"

## Data Representation
详见[14.9. 用于预训练BERT的数据集 — 动手学深度学习 2.0.0-beta0 documentation](https://zh-v2.d2l.ai/chapter_natural-language-processing-pretraining/bert-dataset.html)
## Start Pretrain
详细的过程可以参见: [14.10. 预训练BERT — 动手学深度学习 2.0.0-beta0 documentation](https://zh-v2.d2l.ai/chapter_natural-language-processing-pretraining/bert-pretraining.html) , 这里说明几个需要注意的点:

- BERT 预训练的最终损失是遮蔽语言模型损失和下一句预测损失的和。当然也可以是加权了的和.
- 因为BERT模型是很大的, 用来训练BERT的数据集也是很大的, 所以我们通常指定入`num_steps`指定了训练的迭代步数，指定`num_epoch`
-  在预训练BERT之后，我们可以用它来表示单个文本、文本对或其中的任何词元。
-  在实验中，同一个词元在不同的上下文中具有不同的BERT表示。这支持BERT表示是**上下文敏感**的。

![](notes/2022/2022.4/assets/img_2022-10-15-3.gif)

[^1]: [14.8. Bidirectional Encoder Representations from Transformers (BERT) — Dive into Deep Learning 0.17.5 documentation](https://d2l.ai/chapter_natural-language-processing-pretraining/bert.html#next-sentence-prediction)