---
title: "Latex Colored Text"
tags:
- all


---
![](notes/2022/2022.3/assets/img_2022-10-15-5.png)

- 使用颜色名
$$\textcolor{red}{Sample}$$

```latex
\textcolor{red}{Sample}
```

- 使用 `rgb`
$$\textcolor[rgb]{0.5,0.2,0.8}{text}$$

```latex
\textcolor[rgb]{r,g,b}{text}
```

其中{r,g,b}代表red、green和blue三种颜色的组合，取值范围为[0-1]

- 使用 `RGB`
$$\textcolor[RGB]{123,234,099}{text}$$

```latex
\textcolor[RGB]{R,G,B}{text}
```

其中{R,G,B}代表red、green和blue三种颜色的组合，取值范围为[0-255]

#### 比较好看的颜色

$\textcolor{forestgreen}{forestgreen}$
$\textcolor{royalblue}{royalblue}$
$\textcolor{darkorchid}{darkorchid}$
$\textcolor{orangered}{orangered}$
$\textcolor{salmon}{salmon}$
$\textcolor{darkorange}{darkorange}$
