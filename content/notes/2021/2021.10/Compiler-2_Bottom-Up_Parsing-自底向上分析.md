---
title: "Compiler-2_Bottom-Up_Parsing-自底向上分析"
tags:
- all
- Compiler
- Course
date: "2021-10-30"
---
# Bottom-Up Parsing

<div align="right"> 2021-10-30</div>

Tags: #Compiler #Course 

- 自底向上分析是一种语法分析方法, 它从语法树的下边缘(即一堆终结符)开始, 逐步向上构建这个句子的推导过程

- 一般来说, 自底向上分析比自上而下分析要更强大, 同时也更复杂.

## Shift-reduce parsing[^1]
- 移位-规约分析(Shift-Reduce Parsing)是自底向上分析的主流方法
![](https://upload.wikimedia.org/wikipedia/en/thumb/0/0e/Shift-Reduce_Parse_Steps_Numbered.svg/265px-Shift-Reduce_Parse_Steps_Numbered.svg.png)

- 有许多不同的移位规约分析方法: 比如: ["算符优先分析"](notes/2021/2021.10/Compiler-3_算符优先分析.md)和"LR分析"都属于移位规约分析.
- This is a good illustration
![](notes/2021/2021.10/assets/img_2022-10-15-25.png)[^2]

- Operator Precedence grammar could be either ambiguous or unambiguous.[^2]
### 课堂概念: 短语 直接短语 句柄 规范规约
![](notes/2021/2021.10/assets/img_2022-10-15-26.png)
规范规约: 每步都替换句柄的规约
![](notes/2021/2021.10/assets/img_2022-10-15-27.png)
句柄就是 **"那个可以直接规约的东西"**

### stack-based shift-reduce parsing

- 像table-driven predictive parser一样(比如LL(1)分析里面的那个表), 有的自底向上分析器使用栈来跟踪分析的位置, 使用分析表来决定接下来做什么.








[^1]: https://en.wikipedia.org/wiki/Shift-reduce_parser
[^2]: https://www.geeksforgeeks.org/role-of-operator-precedence-parser/