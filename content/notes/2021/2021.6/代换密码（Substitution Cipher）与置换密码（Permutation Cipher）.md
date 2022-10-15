---
title: "代换密码（Substitution Cipher）与置换密码（Permutation Cipher）"
tags:
- all
- Math
- Cryptography
- Course
date: ""
---
# 代换密码与置换密码（Substitution Cipher & Permutation Cipher）

Tags: #Math #Cryptography  #Course 

> 分不清楚这两个完全是翻译的锅

## 置换（不是置换密码）Permutation（Not Permutation Cipher)
首先置换是数学上的一种操作，是对一组确定的元素进行重新排列
- 元素不变
- 只改变顺序

![|100](https://upload.wikimedia.org/wikipedia/commons/thumb/4/4c/Permutations_RGB.svg/220px-Permutations_RGB.svg.png)

Wikipedia:
> In [mathematics](https://en.wikipedia.org/wiki/Mathematics "Mathematics"), a **permutation** of a [set](https://en.wikipedia.org/wiki/Set_(mathematics) "Set (mathematics)") is, loosely speaking, an arrangement of its members into a [sequence](https://en.wikipedia.org/wiki/Sequence "Sequence") or [linear order](https://en.wikipedia.org/wiki/Linear_order "Linear order"), or if the set is already ordered, a rearrangement of its elements. The word "permutation" also refers to the act or process of changing the linear order of an ordered set

## 辨析
当以替换式密码与[置换式密码（Transposition Cipher)](https://zh.wikipedia.org/w/index.php?title=%E7%BD%AE%E6%8F%9B%E5%BC%8F%E5%AF%86%E7%A2%BC&action=edit&redlink=1)（或称转位式密码或移转式密码(Permutation Cipher属于Transposition Cipher的一种）相比较时，可以发现转位式密码只是改变明文中单元的位置，而单元本身没有转变；相反，替换式密码只是转换单元，但密文中单元的位置没有改变

## 代换密码 Substitution Cipher
![500](notes/2021/2021.6/assets/img_2022-10-15.png)

又称**替换密码、取代式密码**

关键是”**元素变，位置不变**“，观察上图，原来有两个黄色的方块，加密后变成了两个红色的圆圈。
这说明 **"元素类型/分布/组成"** 发生了变化，原来是正方形，现在变成了圆形；原来是黄色最多，现在变成红色最多了。

为什么**代换**密码中涉及到**置换（Substitution）**？
![](notes/2021/2021.6/assets/img_2022-10-15-1.png)
因为他的意思其实是，”更换26个字幕对应的元素相当于将两个Permutation上下对应地放起来“
$$
\begin{alignat}{}
&A&B&C&D&E\\
&\downarrow
&\downarrow
&\downarrow
&\downarrow
&\downarrow
\\
&E&A&D&C&B
\end{alignat}
$$

## 置换密码 Permutation Cipher
![](notes/2021/2021.6/assets/img_2022-10-15-2.png)
先阅读这个网站：
[Transposition Cipher - Columnar Transposition Cipher](https://crypto.interactive-maths.com/columnar-transposition-cipher.html)
再阅读这个：
[Permutation Cipher](https://crypto.interactive-maths.com/permutation-cipher.html)

可以看出，置换密码即一种一段一段地交换位置的加密方式，如果这个”一小段"的长度是整个字符串，那么便是一种Transposition Cipher

在整个过程中，只有元素顺序发生了变化，元素组成没有变化。
In classical cryptography, a permutation cipher is a transposition cipher in which the key is a permutation.
[reference](https://en.wikibooks.org/wiki/Cryptography/Permutation_cipher)


