---
title: "RNN中output和hidden_state的区别"
tags:
- all
- RNN
date: "2022-04-22"
---
# Difference between `output` and `hidden_state` in RNN

<div align="right"> 2022-04-22</div>

Tags: #RNN 

- 首先要将RNN理解为一个二维的网络, 它不仅可能有多个隐藏层, 还在时间维度上有多个时间步.

![RNN in detail](notes/2022/2022.4/assets/RNN%20in%20detail.svg)

- `output`是 **最后一层隐藏层** 在 *每一个时间步* 的状态
- `hidden_state` 是 **最后一个时间步** *所有隐藏层* 的状态

- `output` 常常被用作Encoder-Decoder架构里面Attention的输入
- `hidden_state` 常常在Encoder-Decoder架构里面被用来初始化Decoder隐藏状态

## Bidirectional Case
> 1.  The `output` will give you the hidden layer outputs of the network for each time-step, _but only for the final layer_. This is useful in many applications, particularly encoder-decoders using attention. (These architectures build up a 'context' layer from all the hidden outputs, and it is extremely useful to have them sitting around as a self-contained unit.)
>     
> 2.  The `h_n` will give you the hidden layer outputs for the last time-step only, but for all the layers. Therefore, if and only if you have a single layer architecture, `h_n` is a strict subset of `output`. Otherwise, `output` and `h_n` intersect, but are not strict subsets of one another. (You will often want these, in an encoder-decoder model, from the encoder in order to jumpstart the decoder.)
>     
> 3.  **If you are using a bidirectional output** and you want to actually verify that part of `h_n` is contained in `output` (and vice-versa) you need to understand what PyTorch does behind the scenes in the organization of the inputs and outputs. Specifically, it concatenates a time-reversed input with the time-forward input and runs them together. This is literal. This means that the 'forward' output at time T is in the final position of the `output` tensor sitting right next to the 'reverse' output at time 0; if you're looking for the 'reverse' output at time T, it is in the first position.[^1]




[^1]: [machine learning - Is hidden and output the same for a GRU unit in Pytorch? - Stack Overflow](https://stackoverflow.com/a/61195982/15893958)