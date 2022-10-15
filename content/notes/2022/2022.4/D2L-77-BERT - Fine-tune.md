---
title: "D2L-77-BERT - Fine-tune"
tags:
- all
- BERT
- Fine-tune
- DeepLearning
- Transformer
date: "2022-04-30"
---
# BERT: Fine-tune

<div align="right"> 2022-04-30</div>

Tags: #BERT #Fine-tune #DeepLearning #Transformer 


![](notes/2022/2022.4/assets/img_2022-10-15-4.gif)

- 预训练好 BERT 以后, 我们只需要对模型进行很小的改动即可适配很多任务.
- 在 Finetuning 的时候, 新增的输出部分是从头开始训练的, 而 BERT 主体部分是在 pre-train 的基础上进行训练的.

## Single Text Classification
![](notes/2022/2022.4/assets/bert-one-seq.svg)
- 我们可以利用 `<cls>` tag来对一个语句序列进行分类, 只需要添加一个新的全连接层就好了

## Text Pair Classification or Regression
![](notes/2022/2022.4/assets/bert-two-seqs.svg)
- 语句对的分类/回归问题依然只需要添加一个全连接层来对 `<cls>` 标签进行分类. 它和上一个应用的唯一区别就是输入序列的形式不同.
- 有时我们还会对损失函数进行更改, 比如对于回归任务, 我们可以改用[Mean_Squared_Error_均方误差](notes/2021/2021.8/Mean_Squared_Error_均方误差.md)

## Text Tagging
![](notes/2022/2022.4/assets/bert-tagging.svg)
- 文本标注则将Token的输出作为全连接的输入, 尽管有多个Token, 我们仍使用同一个全连接层.

## Question Answering
![](notes/2022/2022.4/assets/bert-qa.svg)
- 问答的输入由 Question 和 Passage 组成
- 在问答任务中, 模型需要在 Passage 里面找到答案的起始位置. 我们的做法是用两个全连接层分别进行"答案起始位置"和"答案结束位置"的预测:  评估 Passage 里面每一个词元作为起始/结束位置的概率, 选择概率最高的片段作为输出.

## 实例
[15.7. 自然语言推断：微调BERT — 动手学深度学习 2.0.0-beta0 documentation](https://zh-v2.d2l.ai/chapter_natural-language-processing-applications/natural-language-inference-bert.html)