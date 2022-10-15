---
title: "Latex White Spaces"
tags:
- all
- Latex
date: "2022-04-03"
---
# Latex 里面的空格

<div align="right"> 2022-04-03</div>

Tags: #Latex 

[There are a number of horizontal spacing macros for LaTeX](https://tex.stackexchange.com/a/74354/267634) :
1.  `\,` inserts a `.16667em` space in text mode, or `\thinmuskip` (equivalent to `3mu`) in math mode; there's an equivalent `\thinspace` macro;

3.  `\>` (or `\:`) inserts a `.2222em` space in text mode, or `\medmuskip` (equivalent to `4.0mu plus 2.0mu minus 4.0mu`) in math mode; there's an equivalent `\medspace`;
4.  `\negmedspace` is the _negative_ equivalent to `\medspace`;
5.  `\;` inserts a `.2777em` space in text mode, or `\thickmuskip` (equivalent to `5.0mu plus 5.0mu`) in math mode; there's an equivalent `\thickspace`;

7.  `\enspace` inserts a space of `.5em` in text or math mode;
8.  `\quad` inserts a space of `1em` in text or math mode;
9.  `\qquad` inserts a space of `2em` in text or math mode;


12.  `\hspace{<len>}` ==inserts a space of length== `<len>` (may be negative) in math or text mode (a LaTeX `\hskip`); ==得带单位==

