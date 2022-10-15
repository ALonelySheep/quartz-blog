---
title: "Compiler-4-1_什么是 LR 分析"
tags:
- all

date: ""
---
## 什么是 LR 分析
- LR 分析方法是一种自底向上的分析方法: 它从终结符开始, 从左到右, 逐步寻找句柄进行归约. 从这个角度看, LR 分析相当于一种高效的句柄查找方法.

- LR 分析比 LL 分析更强大.
> LL (k) 分析技术的一个弱点是，它在仅仅看到右部的前 k 个单词时就必须预测要使用的是哪一个产生式。另一种更有效的分析方法是 LR (k) 分析，它可以将这种判断推迟至己看到与正在考虑的这个产生式的整个右部对应的输入单词以后（多于 K 个单词） 。[^1]

- 字面上来说, LR (k) 分析代表: Left-to-right parse, (Reversed) Right-most derivation, k-token look ahead

- LR 分析是一种表驱动的移进归约分析方法 (Table-driven & shift-reduce), 所以在进行分析的时候我们将语法规则编码到一个表里面, 根据表来选择不同的移进归约操作.
	- 分析表示意图:
		![](notes/2021/2021.10/assets/img_2022-10-15-50.png)
		上面这个表实际上是一个 DFA 的编码表:
		![](notes/2021/2021.10/assets/img_2022-10-15-51.png)
		LR 分析器将"栈顶句柄状态"转化为 (抽象为) 对应的"DFA 状态". 在分析时, 有时读入终结符, 执行"Shift"操作; 有时读入非终结符, 执行"Goto"操作; 有时从栈里面弹出句柄, 执行"Reduce"操作. LR 分析将栈与 DFA 结合, 一起进行分析.
		- **Shift**: Push Terminal to the stack, shift to the next state in DFA 
		- **Goto**: Push Non-terminal to the stack, go to that corresponding state in DFA
		- **Reduce**: Pop the handle out of stack, also pop the corresponding states out of stack. Intuitively, this means "retreat" to the state before the handle. (This may pass through multiple states) 
	- 要注意我们分析的 LR 语言是 CFG 语言的子类, DFA 等价于正则语言, 是 LR 语言的一个子类. 所以我们需要结合栈来增强 DFA 的表现力.
	
	- 分析操作示意图:
		![400](notes/2021/2021.10/assets/img_2022-10-15-52.png)

下面我们将从按照 $LR(0) \rightarrow SLR \rightarrow LR(1) \rightarrow LALR(1)$ 的顺序来梳理 LR 文法的思想.[^2]

### 语法分析: 文法层次结构
![500](notes/2021/2021.10/assets/img_2022-10-15-53.png)[^1]


[^1]: 虎书第三章
[^2]: 这也是虎书的顺序, 我感觉虎书适合第二遍看, 因为它写的十分精炼, 在第一遍学习掌握了大概方法以后, 第二遍看虎书可以快速抓住核心思想. (把书写这么精炼又清晰真的好厉害了)