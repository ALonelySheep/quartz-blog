---
title: "D2L-68-Additive Attention"
tags:
- all
- Attention
- DeepLearning
date: "2022-04-21"
---
# 加性注意力

<div align="right"> 2022-04-21</div>

Tags: #Attention #DeepLearning 

- 一般来说，当Query和Key是**不同长度**的矢量时，我们可以使用Additive Attention来作为Scoring Function。
- 给定查询 $\mathbf{q} \in \mathbb{R}^q$ 和键 $\mathbf{k} \in \mathbb{R}^k$，*加性注意力*（additive attention）的评分函数(Scoring Function)为
$$a(\mathbf q, \mathbf k) = \mathbf w_v^\top \text{tanh}(\mathbf W_q\mathbf q + \mathbf W_k \mathbf k) \in \mathbb{R},$$
- 函数输出的是一个标量. 其中可学习的参数是 $\mathbf W_q\in\mathbb R^{h\times q}$、$\mathbf W_k\in\mathbb R^{h\times k}$ 和 $\mathbf w_v\in\mathbb R^{h}$. 前两个权重分别将 Query 和 Key 映射为长度为 $h$ 的向量, 然后 $\mathbf w_v$ 将向量映射为value 对应的注意力权重.

- 下图展示了Additive Attention是怎样等价于一个单隐藏层的MLP的. 
	- (图中简化为一个 $k\times1$ 的key和一个 $q\times1$ 的query)
![Additive Attention](notes/2022/2022.4/assets/Additive%20Attention.svg)
- 注意上面的MLP和下图的对应关系, 一个Query需要和所有的Keys分别计算一次Score. 
![](notes/2022/2022.4/assets/Pasted%20image%2020220427164928.png)


## 通用形式
- 在实际应用中, Scoring function需要面对Batch形式输入的Keys and Queries, 并且每一个Batch里面都有多个Keys and Queries.
```
queries的形状：(batch_size，num_of_queries，query_length)
key的形状：(batch_size，num_of_key－value_pair，key_length)
```
- 在一个Batch里面, 我们需要计算每一个Key和每一个Query的注意力分数, 这可以通过PyTorch里面的Broadcasting机制来巧妙地实现:
```python
class AdditiveAttention(nn.Module):
    """加性注意力"""
    def __init__(self, key_size, query_size, num_hiddens, dropout, **kwargs):
        super(AdditiveAttention, self).__init__(**kwargs)
        self.W_k = nn.Linear(key_size, num_hiddens, bias=False)
        self.W_q = nn.Linear(query_size, num_hiddens, bias=False)
        self.w_v = nn.Linear(num_hiddens, 1, bias=False)
        self.dropout = nn.Dropout(dropout)

    def forward(self, queries, keys, values, valid_lens):
	    # 先和权重相乘
        queries, keys = self.W_q(queries), self.W_k(keys)
        # 在维度扩展后，
        # queries的形状：(batch_size，查询的个数，1，num_hidden)
        # key的形状：(batch_size，1，“键－值”对的个数，num_hiddens)
        # 使用广播方式进行求和
        # 现在feature的形状为: 
        # (batch_size，查询的个数，“键－值”对的个数，num_hiddens)
        features = queries.unsqueeze(2) + keys.unsqueeze(1)
        features = torch.tanh(features)
        # w_v(features)的形状为:(batch_size，查询的个数，“键－值”对的个数，1)
        # self.w_v仅有一个输出，因此从形状中移除最后那个维度。
        scores = self.w_v(features).squeeze(-1)
        # scores的形状：(batch_size，查询的个数，“键-值”对的个数)
        self.attention_weights = masked_softmax(scores, valid_lens)
        # attention_weights的形状：(batch_size，查询的个数，“键-值”对的个数)
        # values的形状：(batch_size，“键－值”对的个数，值的维度)
        return torch.bmm(self.dropout(self.attention_weights), values)
        # 返回值的形状：(batch_size，查询的个数，值的维度)
        
```
- 其中`masked_softmax`对于每一个Query取前`valid_lens`个 "key-value" pair

可视化Softmax的结果: attention_weights如下:
```python
queries, keys = torch.normal(0, 1, (2, 1, 20)), torch.ones((2, 10, 2))
# values的小批量，两个值矩阵是相同的
values = torch.arange(40, dtype=torch.float32).reshape(1, 10, 4).repeat(
    2, 1, 1)
valid_lens = torch.tensor([2, 6])

attention = AdditiveAttention(key_size=2, query_size=20, num_hiddens=8,
                              dropout=0.1)
attention.eval()
attention(queries, keys, values, valid_lens)
```
![](notes/2022/2022.4/assets/Pasted%20image%2020220421153308.png)
![](notes/2022/2022.4/assets/output_attention-scoring-functions_2a8fdc_78_0.svg)
