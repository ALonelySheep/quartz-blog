---
title: "Jupyter_Notebook-使用代理"
tags:
- all
- Jupyter
- Python
- Proxy
date: "2022-05-18"
---
# 如何在Jupyter Notebook里面使用代理

<div align="right"> 2022-05-18</div>

Tags: #Jupyter #Python #Proxy

## 方案一: 使用 IPython 启动脚本
- 根据 [这个回答](https://stackoverflow.com/a/36884552/15893958) 以及下面评论, IPython 可以在启动之前运行一些代码. 我们可以借助这个功能来为 Jupyter Notebook 设置代理
- Windows 的启动脚本默认在以下目录:
	- `C:\Users\[用户名]\.ipython\profile_default\startup`

1. 阅读目录里面的 Readme 查看使用指南
2. 创建新的 python 文件, 输入以下内容: 
	```python
	import os
	os.environ['http_proxy'] = "http://127.0.0.1:7890"
	os.environ['https_proxy'] = "http://127.0.0.1:7890"
	```
	- 注意需要根据自己的配置修改相应的代理地址.
	- 添加后如图所示: 
		![](notes/2022/2022.5/assets/img_2022-10-15-6.png)
3. 以后在启动 Jupyter Notebook 时, 上面的脚本都会自动运行, 所有的 Jupyter Notebook 都会有代理后的网络连接.

- **优点:** 不用为每一个笔记本单独设置代理, 更加方便
- **缺点:** 所有笔记本都被代理了, 这也意味着如果不开代理软件, 笔记本的网络连接会出现问题:
	- ![](notes/2022/2022.5/assets/img_2022-10-15-7.png)
	- **对策:** 运行以下代码取消代理 
```python
import os
os.environ['http_proxy'] = ""
os.environ['https_proxy'] = ""
```

## 方案二: 为某个笔记本单独设置代理
如果只想为某个笔记本单独设置代理, 可以运行如下单元格:
```python
import os
os.environ['http_proxy'] = "http://127.0.0.1:7890"
os.environ['https_proxy'] = "http://127.0.0.1:7890"
```

- 这个方案和方案一是互补的.

## 方案三: 在使用了代理的终端中启动Jupyter Notebook
- **缺点:** 只能在网页版本的Jupyter Notebook中使用代理, 无法在VScode 启动的笔记本中使用代理.









