---
title: "Entropy-熵"
tags:
- all
- InformationTheory

---
# Entropy - 熵

2022-02-11</div>

Tags: #InformationTheory

## 理解

- 熵是Surprise的期望
[Entropy (for data science) Clearly Explained!!! - YouTube](https://www.youtube.com/watch?v=YtebGVx-Fxw)

- 熵是对事件复杂度的衡量, 即我们最少需要多少信息才能完整地描述这个事件
[Intuitively Understanding the Shannon Entropy - YouTube](https://www.youtube.com/watch?v=0GCGaw0QOhA)

- 换句话说, 熵的大小是编码一个随机事件所需要的**最短平均编码长度**

**联系:**  一个事件越复杂, 那么就需要更多的信息来描述这个事件, 这个事件的平均"惊讶程度"就越高, 这个事件的熵就越高.

## 公式

$$\text { Entropy }=-\sum p(x) \log (p(x))$$
or
$$\text { Entropy }=\sum p(x) \log \left(\frac{1}{p(x)}\right)$$
(The Average *Surprise*)
