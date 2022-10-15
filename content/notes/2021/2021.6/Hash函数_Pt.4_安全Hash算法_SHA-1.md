---
title: "Hash函数_Pt.4_安全Hash算法_SHA-1"
tags:
- all
- Cryptography
- Math
- Course
- Hash
- todo
---
# SHA-1

Tags: #Cryptography  #Math  #Course #Hash 

**SHA-1是一个具有160bit消息摘要的迭代Hash函数**

## 主要思想
SHA-1 的分组大小是 512bit, 意味着每一次迭代处理 512bit 的数据

SHA-1建立在对比特串面向**字**的操作上, 意味着在处理512bit的时候是每次32bit, ~~一共16次~~, 一共80次. (为什么变多了? 因为在循环里面需要将16个字扩充到80个字, 如下图)

![](notes/2021/2021.6/assets/img_2022-10-15-22.png)

(刚开始我一直看不懂这里, 觉得数组下标超限了, 但仔细看, 意思其实是根据原来的16个字利用异或与循环左移构建新的字)

SHA-1在循环的时候使用了5个中间变量$A,B,C,D,E$, 大小为一个字, 不通过断更新它们的值来进行处理

[Youtube - An Intuitive Introduction](https://www.youtube.com/watch?v=DMtFhACPnTY)
![](notes/2021/2021.6/assets/img_2022-10-15-23.png)
同时这个视频里面还指出了其他地方都没有提到的一点: SHA-1 里面的所有加法都是循环加法(溢出位变成最低位), 这样会损失信息, 让 Hash 变得更安全.

**(但是这一点其他地方都没有提到, 待验证!)**
#todo

老师的课件中把SHA-1与Merkle-Damgard结构的对应关系写的很清晰

[Merkle-Damgard结构](notes/2021/2021.6/Hash函数_Pt.3_迭代Hash函数.md#Merkle-Damgard结构)

![](notes/2021/2021.6/assets/img_2022-10-15-24.png)
![](notes/2021/2021.6/assets/img_2022-10-15-25.png)



红色"do"里面的部分如下图例:

![File:SHA-1.svg](https://upload.wikimedia.org/wikipedia/commons/thumb/e/e2/SHA-1.svg/365px-SHA-1.svg.png)


## 预处理:
注意的一点是SHA-1能处理的串是有最大长度的, 为$2^{64}-1$

同时因为在预处理的时候需要填充x的长度$l$, 从上面可以知道$|l|\leq 64\space bits$, 如果$l$长度不够, 在左边加0, (在左边加0也符合正常的大小表示方法(用0
填充没有用到的高位))

预处理方法:
$$y\leftarrow x||一个1||许多0||l$$
0 有多少个呢? 让 y 的长度 mod 512=0 即可

更清晰一点的话, 是:

![|480](notes/2021/2021.6/assets/img_2022-10-15-26.png)

## 处理
直觉理解上面已经谈过了, 详细的话可以看<密码学原理与实践 page118>或者官方文档:[RFC3174](https://datatracker.ietf.org/doc/html/rfc3174#section-6)

## 结果变换
不需要变换, 最后的$H_0||H_1||H_2||H_3||H_4$连起来, 便是一个$32bits\cdot 5=160\space bits$的消息摘要.


## Further Questions
- SHA-1的这种迭代结构与Merkel-Damgard结构的关系是什么?(History, 是Merkel首创了这种结构吗?)

[SHA-1的Wikipedia写的蛮好](https://en.wikipedia.org/wiki/SHA-1)

