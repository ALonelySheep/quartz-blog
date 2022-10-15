---
title: "Vision Transformer (ViT)"
tags:
- all
- ViT
date: "2022-09-22"
---
# Vision Transformer

<div align="right"> 2022-09-22</div>

Tags: #ViT

## How the Vision Transformer works in a nutshell[^1]

The total architecture is called Vision Transformer (ViT in short). Let’s examine it step by step.

1.  **Split** an image into **patches**
2.  **Flatten** the patches
3.  Produce lower-dimensional **linear embeddings** from the flattened patches
4.  Add **positional embeddings**
5.  Feed the sequence as an input to a **standard transformer encoder**
6.  **Pretrain** the model with image labels (fully supervised on a huge dataset)
7.  **Finetune** on the downstream dataset for image classification

![](notes/2022/2022.9/assets/img_2022-10-15.gif)






[^1]: [How the Vision Transformer (ViT) works in 10 minutes: an image is worth 16x16 words | AI Summer](https://theaisummer.com/vision-transformer/)