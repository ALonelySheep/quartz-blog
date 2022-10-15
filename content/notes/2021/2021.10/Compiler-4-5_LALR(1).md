---
title: "Compiler-4-5_LALR(1)"
tags:
- all


---
## LALR (1)

- LR (1) 的分析表通常十分巨大, 为了在节省空间的同时保留 LR (1) 大部分的优点, 我们常常采用 LALR (1) 分析方法, LALR 代表 Look-Ahead LR.

- LR (1) 分析的 DFA 里面常常有两个状态的产生式完全相同, 只有前瞻符号不同. LALR 分析就是将这样的状态合并为一个状态.

- 在合并状态以后, LALR 的 DFA 和 LR (0) 的 DFA 拓扑结构上是一样的, 唯一不同的是每个状态里面都是 LR (1) 项, 包含了前瞻符号.

- 我们可以从 LR (1) 的 DFA 构造 LALR 的 DFA, 但是这样需要事先构造 LR (1) 庞大的表. 所以我们常常使用一种称为 "前瞻传播 (Look-ahead Propagation) " 的方法来从 LR (0) 的 DFA 构造 LALR 的 DFA.
  - Look-ahead Propagation 很简单, 请参见【CCP&P】Compiler Construction Principles and Practice by Kenneth C. Louden 对应的部分

- 所有合理的程序设计语言都有一个 LALR (1) 文法，并且存在着许多对 LALR (1) 文法有效的语法分析器生成器工具。由于这一原因， LALR (1) 文法已变成程序设计语言和自动语法分析器生成器的标准。[^8]

- Yacc 就是一个 LALR (1) 分析器的自动生成器

[^8]: 虎书 3.3.5
