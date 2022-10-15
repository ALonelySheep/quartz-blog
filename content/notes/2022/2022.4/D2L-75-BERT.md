---
title: "D2L-75-BERT"
tags:
- all
- BERT
- Transformer
- DeepLearning
date: "2022-04-30"
---
# Bidirectional Encoder Representations from Transformers (BERT)
<div align="right"> 2022-04-30</div>

Tags: #BERT #Transformer #DeepLearning 

![](notes/2022/2022.4/assets/img_2022-10-15-2.gif)

## Motivation
### 构建一个通用的语言模型
- 在计算机视觉领域中, 我们能对一个已经训练好的大型网络进行微调(Fine-tune), 以较小的计算成本和网络改动就能获得很好的模型.
- BERT就是期望能够构建一个足够强大的预训练模型(Pretrained), 来适配各种各样的任务.
![450](notes/2022/2022.4/assets/img_2022-10-15-11.png)
### 结合两个现有架构的优点: ELMo & GPT
### GPT: task-agnostic
- 其实在 BERT 以前, OpenAI 已经提出了 GPT （Generative Pre-Training，生成式预训练）模型, 试图提供一种既考虑上下文语意(context-sensitive), 又能适配多任务(task-agnostic[^2])的模型
- 但是 GPT 是基于 Transformer Decoder 的, 这就意味着它具备自回归模型(Auto-regressive)的性质: 只能"向前看"(从左到右).

- 在 Fine-tune 的时候, GPT 不冻结任何参数, 所有原来的所有参数会跟着新的输出层一起训练
### ELMo: Bi-directional
 - 尽管基于 BiLSTM 的 ELMo 模型能够很好的综合两个方向的语义信息, 但是 ELMo 是 task-specific 的, 无法适配多种任务.

- 这就意味着我们 Pretrained ELMo 之后, 还需要为不同的 NLP 任务设计不同的后续架构, 这是很累的

### BERT: Combining the Best of Both Worlds
- BERT 基于 Transformer 的 Bidirectional Encoder, 既可以综合 Bidirectional 的上下文信息, 又可以适配多种模型(task-agnostic).
![](notes/2022/2022.4/assets/elmo-gpt-bert.svg)
- 并且 BERT 在 Fine-tune 的时候和 GPT 类似: 所有原来的所有参数会跟着新的输出层一起训练.

![](notes/2022/2022.4/assets/BERT%20hang%20out.gif)

## Model - Overview
- 作为一个预训练模型, 训练 BERT 分为 Pre-train 和 Fine-tune 两部分.
	- 而且我们需要为 Pretrain 设计一个通用的训练任务, 适配多种应用场景.
	![](notes/2022/2022.4/assets/Pasted%20image%2020220430172119.png)

- BERT 相当于一个只有 Encoder 的 Transformer.
	- 为了适配设计的"通用任务", 我们还需要对模型进行相应的改进 ,后面详述.

- 作为预训练模型, BERT提供了不同规格的两个版本.
```
Base: 
	#blocks = 12, hidden size = 768, #heads = 12, #parameters = 110M
Large: 
	#blocks = 24, hidden size = 1024, #heads = 16, #parameter = 340M
```

## 预训练任务
![Pretrain Tasks](notes/2022/2022.4/D2L-76-BERT%20-%20Pretrain.md#Pretrain%20Tasks)

## Model - Detail
![](notes/2022/2022.4/assets/bert.ipynb)
### Masked Language Model 任务
- 我们使用一个单隐层的 MLP 来将 Encoder 的输出转化为预测的单词标签(Vocab 里面的序号)
```python
class MaskLM(nn.Module):
    """BERT的掩蔽语言模型任务"""
    def __init__(self, vocab_size, num_hiddens, num_inputs=768, **kwargs):
        super(MaskLM, self).__init__(**kwargs)
        self.mlp = nn.Sequential(
	     nn.Linear(num_inputs, num_hiddens),
		 nn.ReLU(),
		 nn.LayerNorm(num_hiddens),
		 nn.Linear(num_hiddens, vocab_size))

    def forward(self, X, pred_positions):
        num_pred_positions = pred_positions.shape[1] # 一共有多少个位置需要预测
        pred_positions = pred_positions.reshape(-1)  # 全部排成一列
        batch_size = X.shape[0] 
        batch_idx = torch.arange(0, batch_size) # batch的序号
        # 假设batch_size=4，num_pred_positions=2
        # 那么batch_idx是np.array（[0,0,1,1,2,2,3,3]）
        batch_idx = torch.repeat_interleave(batch_idx, num_pred_positions)
        # 取出X里面需要预测的位置
        masked_X = X[batch_idx, pred_positions]
        masked_X = masked_X.reshape((batch_size, num_pred_positions, -1))
        # 进行预测
        mlm_Y_hat = self.mlp(masked_X)
        return mlm_Y_hat
```

### Next Sentence Prediction 任务
- 我们依然使用一个单隐层的 MLP 来处理 NSP 任务
- 但是和 MLM 任务不同, BERT 在这一步只使用了每一个序列的 `<cls>` 标签, 这个标签在每个句子的开头, 可以使用 `encoded_X[:, 0, :]` 来提取出来
![](notes/2022/2022.4/assets/bert-output-tensor%201.png)
![](notes/2022/2022.4/assets/bert-output-tensor-selection.png)[^1]
- `<cls>` 标签表示 Classification, 是 BERT 中专门用于句子分类的一个标签.
	- [What is purpose of the [CLS] token and why is its encoding output important? - Data Science Stack Exchange](https://datascience.stackexchange.com/questions/66207/what-is-purpose-of-the-cls-token-and-why-is-its-encoding-output-important )
	- [Why Bert transformer uses [CLS] token for classification instead of average over all tokens? - Data Science Stack Exchange](https://datascience.stackexchange.com/questions/77044/bert-transformer-why-bert-transformer-uses-cls-token-for-classification-inst?rq=1)

```python
class NextSentencePred(nn.Module):
    """BERT的下一句预测任务"""

    def __init__(self, num_inputs,  num_hiddens, **kwargs):
        super(NextSentencePred, self).__init__(**kwargs)
        print("num_inputs:", num_inputs)

        self.output = nn.Sequential(
            nn.Linear(num_inputs, num_hiddens),
            nn.Tanh(),
            nn.Linear(num_hiddens, 2))

    def forward(self, X):
        # X的形状：(batchsize,num_hiddens)
        return self.output(X)
```

### 完整的模型
```python
class BERTModel(nn.Module):
    """BERT模型"""

    def __init__(self, vocab_size, num_hiddens, norm_shape, ffn_num_input, 
                 ffn_num_hiddens, num_heads, num_layers, dropout,
                 max_len=1000,
                 #  这里设置默认大小 768 有点误导, 
                 #  768是BERT base版本的hidden_size
                 #  其实这里的维度要和前面的hidden_size对应起来,
                 key_size=768,
                 query_size=768,
                 value_size=768,
                 mlm_in_features=768,
                 nsp_in_features=768):
        super(BERTModel, self).__init__()
        self.encoder = BERTEncoder(vocab_size, 
	        num_hiddens, norm_shape,  ffn_num_input, ffn_num_hiddens,
	        num_heads, num_layers, dropout, max_len=max_len,
	        key_size=key_size, query_size=query_size, 
	        value_size=value_size)
        # mlm的hidden_size是768, 但是可以取不一样的
        self.mlm = MaskLM(vocab_size, num_hiddens, mlm_in_features)
        self.nsp = NextSentencePred(nsp_in_features, num_hiddens)

    def forward(self, tokens, segments, 
		    valid_lens=None, pred_positions=None):
        encoded_X = self.encoder(tokens, segments, valid_lens)
        if pred_positions is not None:
            mlm_Y_hat = self.mlm(encoded_X, pred_positions)
        else:
            mlm_Y_hat = None
        # 用于下一句预测的多层感知机分类器的隐藏层，0是“<cls>”标记的索引
        nsp_Y_hat = self.nsp(encoded_X[:, 0, :])
        return encoded_X, mlm_Y_hat, nsp_Y_hat
```

## Fine-tune
[D2L-77-BERT - Fine-tune](notes/2022/2022.4/D2L-77-BERT%20-%20Fine-tune.md)

![](notes/2022/2022.4/assets/BERT%20and%20ERNIE.gif)

[^1]: [A Visual Guide to Using BERT for the First Time – Jay Alammar – Visualizing machine learning one concept at a time.](https://jalammar.github.io/a-visual-guide-to-using-bert-for-the-first-time/)
[^2]: Agonistic: someone who does not know, or believes that it is impossible to know, if a god exists 不可知论者（对神存在与否不能肯定或认为不可知）,