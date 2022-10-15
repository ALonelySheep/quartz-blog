---
title: "Compiler-4-4_LR(1)_分析"
tags:
- all

date: ""
---
## LR (1) 分析
LR (1) 分析在一开始构建 DFA 的时候便考虑到了前瞻符号, 使得其在结构上更为强大.

### LR (1) 项
在 LR (0) 项的基础上, LR (1) 项添加了前瞻符号:
$$A\rightarrow \alpha\cdot \beta, a $$
- 其中 $a$ 是前瞻符号

### LR(1)分析: 构造DFA
- 构造DFA的目标和之前一样: 寻找LR(1)项的规范集, 并且构造这些集合之间的转换关系.

- 尽管我们在实际构造的时候往往直接构造DFA, 但是从NFA的角度来观察构造过程有助于我们理解LR(1)的本质特征:

- 对于LR(1), 状态转换在构造时最大的不同是: $\varepsilon$-转移需要考虑**前瞻符号的变化**.

#### LR(1): NFA的状态转移
- 我们先考虑非空的转移:
	$$[A\rightarrow \alpha\cdot X\beta,\space a]\overset{shift(X)}\longrightarrow[A\rightarrow \alpha X\cdot\beta,\space a]$$ (X是终结符或非终结符) 
	- 在上面, 项$[A\rightarrow \alpha\cdot X\beta,\space a]$读入了符号$X$(将$X$压入符号栈顶), 转移到了新状态$[A\rightarrow \alpha X\cdot\beta,\space a]$, **前瞻符号不变**.

注意到除了不变的前瞻符号a, 这和LR(0)里面几乎相同.

- 接下来考虑$\varepsilon$-转移, 即构造等价集CLosure(A)的时候涉及到的转移:
	$$[A\rightarrow \alpha\cdot B\gamma,\space a]\overset{\varepsilon}
	\longrightarrow
	[B\rightarrow \cdot\beta,\space b_i\space ]$$  
	其中, $b_i\in First(\gamma a)$, 所以这其实是多个$\varepsilon$-转移:
	![LR(1) Transition Closure](notes/2021/2021.10/assets/LR(1)%20Transition%20Closure.svg)
%%$$\begin{align}[A\rightarrow \alpha\cdot B\gamma,\space a]&\overset{\varepsilon}\longrightarrow	[B\rightarrow \cdot\beta,\space b_1\space ]\\[A\rightarrow \alpha\cdot B\gamma,\space a]&\overset{\varepsilon}\longrightarrow	[B\rightarrow \cdot\beta,\space b_2\space ]\\&\quad\vdots\\[A\rightarrow \alpha\cdot B\gamma,\space a]&\overset{\varepsilon}\longrightarrow	[B\rightarrow \cdot\beta,\space b_n\space ]\end{align}$$%%
- 与LR(0)不同, 我们在构造空转移的时候还需要考虑前瞻符号的变化, 即$b_i$可以是什么符号:
	- 首先, 因为有产生式$A\rightarrow \alpha B\gamma$, 所以$b_i\in First(\gamma)$, 又如果$\gamma$是可为空的, 那么$b_i$可能是$a$. 综上, $b_i\in First(\gamma a)$


- 与SLR(1)不同, 我们在考虑前瞻符号的时候还考虑了前一个LR(1)项 (里面的 $\gamma$ 和 $a$ ), 而不是将整个$Follow(B)$写上去.
	- 我们考虑$First(\gamma a)$ 与$Follow(B)$ 的关系: 
		首先$A\rightarrow \alpha B\gamma$ , 所以$First(\gamma)\subset Follow(B)$. 如果$\gamma$是可为空的, 那么有$Follow(A)\subset Follow(B)$ , 又 $a\in Follow(A)$. 所以$First(\gamma a)\subseteq Follow(B)$. 
- 注意: 因为$B$还可能出现在其他产生式里面, 所以$First(\gamma a)$很有可能是$Follow(B)$的真子集, 这正是LR(1)文法的强大之处.
		*(The power of the general LR(1) method lies in the fact that the set $First(\gamma a)$ may be a proper subset of $Follow(B)$. [^6])*

##### 再论SLR(1)
SLR(1)分析法虽然在构造DFA的时候没有考虑前瞻符号, 但是我们可以这样类比LR(1):
- 令$Follow(B)=\{b_j, c_i\mid b_j\in First(\gamma a), c_i\notin First(\gamma a)\}$, 则我们构造的项目集既包括$[B\rightarrow \cdot\beta,\space b_j\space ]$, 又包括 $[B\rightarrow \cdot\beta,\space c_i\space ]$, 如下图左边所示:

	![SLR(1) Transition States](notes/2021/2021.10/assets/SLR(1)%20Transition%20States.svg)

- 在上图中, 假设$\beta$是一个终结符,  填表的时候在$Follow(B)$对应的地方都填上Reduce, 其实就相当于将图中右边所有的项都当成要规约的项.

- 相比之下, 如果我们仅仅包括$First(\gamma a)$里面的项, 则相当于去除上图里面所有黄色的项. 基于$[A\rightarrow\alpha\cdot B\gamma,\space a]$这个前提, 这些黄色的项实际上是不可能被规约的, 可以见得, LR(1)分析有着"更精准的句柄识别能力", 相比SLR(1)文法, LR(1)文法有着更强的表现力. 

	![LR(1) Transition States](notes/2021/2021.10/assets/LR(1)%20Transition%20States.svg)

### 构造DFA
我们还是从初始状态出发, 逐步构建闭包, 直到整个图形不再变化.

- 初始状态:
	$$[S^\prime\rightarrow\cdot S, \$]$$
	其中$代表句子的结束.

- 下面是取闭包的操作与转移操作的算法:
![](notes/2021/2021.10/assets/Pasted%20image%2020211109222126.png)[^7]

- 下面是 Reduce 的算法, 我们只在这个项前瞻符号对应的地方填上 Reduce, 也就是 $First (\gamma a)$ 指代的地方.
![400](notes/2021/2021.10/assets/Pasted%20image%2020211109222451.png)

### 开始分析!
- 吃掉终结符(Shift)或者非终结符(Goto)都只需要将符号压栈, 移动到拥有对应项的状态: 
 $$[A\rightarrow \alpha\cdot X\beta,\space a]\overset{shift(X)}\longrightarrow[A\rightarrow \alpha X\cdot\beta,\space a]$$
 - Reduce 操作需要前瞻一个符号. 比如现在的状态里面有 $[A\rightarrow\alpha\space ., a\space ]$ 如果输入串里面下一个符号是 $a$, 才进行 Reduce 操作.

 - 遇到 $[S^′ → S., \$]$, 说明分析成功.

- 如果当前表项为空, 则报错 



[^6]: CCP&P 5.4节
[^7]: 这个图是虎书里面的算法, 所以符号和前面稍有不同, 请注意 