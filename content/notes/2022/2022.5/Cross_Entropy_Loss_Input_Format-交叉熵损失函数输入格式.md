---
title: "Cross_Entropy_Loss_Input_Format-交叉熵损失函数输入格式"
tags:
- all


---
## PyTorch

标签不需要变成独热编码:

![](notes/2022/2022.5/assets/img_2022-10-15-1.png)

## Keras

Kears有两种形式:

- Categorical Cross Entropy [Doc](https://keras.io/api/losses/probabilistic_losses/#categoricalcrossentropy-class):

> Use this crossentropy loss function when there are two or more label classes. We expect labels to be provided in a one_hot representation.

```python
>>> y_true = [[0, 1, 0], [0, 0, 1]]
>>> y_pred = [[0.05, 0.95, 0], [0.1, 0.8, 0.1]]
>>> # Using 'auto'/'sum_over_batch_size' reduction type.  
>>> cce = tf.keras.losses.CategoricalCrossentropy()
>>> cce(y_true, y_pred).numpy()
1.177
```

- Sparse Categorical Cross Entropy [Doc](https://keras.io/api/losses/probabilistic_losses/#sparsecategoricalcrossentropy-class):

> Use this crossentropy loss function when there are two or more label classes. We expect labels to be provided as integers.

```python
>>> y_true = [1, 2]
>>> y_pred = [[0.05, 0.95, 0], [0.1, 0.8, 0.1]]
>>> # Using 'auto'/'sum_over_batch_size' reduction type.  
>>> scce = tf.keras.losses.SparseCategoricalCrossentropy()
>>> scce(y_true, y_pred).numpy()
1.177
```

[python - What is the difference between sparse_categorical_crossentropy and categorical_crossentropy? - Stack Overflow](https://stackoverflow.com/a/68617676/15893958)
