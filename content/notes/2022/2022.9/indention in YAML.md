---
title: "indention in YAML"
tags:
- all
- YAML
- Frontmatter
date: "2022-09-05"
---
# YAML里面的缩进

<div align="right"> 2022-09-05</div>

Tags: #YAML #Frontmatter

YAML(YAML Ain't Markup Language)可以在 Markdown 里面用于存储原始数据. 但是 YAML 里面的缩进却难住了我.

一个 YAML 的例子如下:
```YAML
 doe: "a deer, a female deer"
 ray: "a drop of golden sun"
 pi: 3.14159
 xmas: true
 french-hens: 3
 calling-birds:
   - huey
   - dewey
   - louie
   - fred
 xmas-fifth-day:
   calling-birds: four
   french-hens: 3
   golden-rings: 5
   partridges:
     count: 1
     location: "a pear tree"
   turtle-doves: two
```
可以看到 YAML 是允许缩进的, 但是容易忽视的一点是: **YAML 里面的缩进只能是空格(Space), 不可以是制表符(Tab)**.
这是因为 Tab 在不同的文字处理软件里面的处理方式各不相同, 而 YAML 的设计初衷就是为了让它简单通用.

Source: [YAML Tutorial: Everything You Need to Get Started in Minutes | Cloudbees Blog](https://www.cloudbees.com/blog/yaml-tutorial-everything-you-need-get-started)
