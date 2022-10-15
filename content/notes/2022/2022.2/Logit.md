---
title: "Logit"
tags:
- all
- Math
- DeepLearning
- SoftmaxRegression
date: "2022-02-11"
---
# Logit: a confusing term

<div align="right"> 2022-02-11</div>

Tags: #Math #DeepLearning #SoftmaxRegression 

Ref: [machine learning - What is the meaning of the word logits in TensorFlow? - Stack Overflow](https://stackoverflow.com/questions/41455101/what-is-the-meaning-of-the-word-logits-in-tensorflow)
- Logits is an overloaded term which can mean many different things:

## 理解[^1]
- 我们可以把Logit理解成"对数几率/概率", 也就是概率的对数:  $\log p_i$.
	- Logit输入到Softmax之后还原成原来的概率: $p_i$  : $$\frac{\exp(\log p_i)}{\sum_K \exp(\log p_i)}=p_i$$ 

## In Math
- **In Math**, [Logit](https://en.wikipedia.org/wiki/Logit) is a function that maps probabilities (`[0, 1]`) to R (`(-inf, inf)`)

	![enter image description here](https://i.stack.imgur.com/zto5q.png)

	- Probability of 0.5 corresponds to a logit of 0. Negative logit correspond to probabilities less than 0.5, positive to > 0.5.

## In ML
- **For Tensorflow**: It's a name that it is thought to imply that this Tensor is the quantity that is being mapped to probabilities by the Softmax.

- **Logits Layer**: In context of deep learning the [logits layer](https://www.tensorflow.org/tutorials/estimators/cnn#logits_layer) means the layer that feeds in to Softmax (or other such normalization). 
	- The output of the softmax are the probabilities for the classification task and its input is **logits layer**. The logits layer typically produces values from -infinity to +infinity and the softmax layer transforms it to values from 0 to 1.

## Historical Context
Where does this term comes from? 

- In 1930s and 40s, several people were trying to adapt linear regression to the problem of predicting probabilities. However linear regression produces output from -infinity to +infinity while for probabilities our desired output is 0 to 1. 

- One way to do this is by somehow mapping the probabilities 0 to 1 to -infinity to +infinity and then use linear regression as usual. One such mapping is cumulative normal distribution that was used by Chester Ittner Bliss in 1934 and he called this "probit" model, short for "probability unit".

- However this function is computationally expensive while lacking some of the desirable properties for multi-class classification. In 1944 Joseph Berkson used the function `log(p/(1-p))` to do this mapping and called it logit, short for "logistic unit". The term logistic regression derived from this as well.

## The Confusion
Unfortunately the term logits is abused in deep learning. 
- From pure mathematical perspective logit is a _function_ that performs above mapping. In deep learning people started calling the layer "logits layer" that feeds in to logit function. Then people started calling the output _values_ of this layer "logit" creating the confusion with logit _the function_.

**TensorFlow Code**
- Unfortunately TensorFlow code further adds in to confusion by names like `tf.nn.softmax_cross_entropy_with_logits`. 

- What does logits mean here? It just means the input of the function is supposed to be the output of last neuron layer as described above. The `_with_logits` suffix is [redundant, confusing and pointless](https://github.com/tensorflow/tensorflow/issues/6531). 

- Functions should be named without regards to such very specific contexts because they are simply mathematical operations that can be performed on values derived from many other domains. In fact TensorFlow has another similar function `sparse_softmax_cross_entropy` where they fortunately forgot to add `_with_logits` suffix creating inconsistency and adding in to confusion. 

- PyTorch on the other hand simply names its function without these kind of suffixes.

**Reference**

- [Logit/Probit lecture slides](http://www.columbia.edu/~so33/SusDev/Lecture_9.pdf)  
- [Wikipedia article](https://en.wikipedia.org/wiki/Logit) 





[^1]: [7.3. 网络中的网络（NiN） — 动手学深度学习 2.0.0-beta0 documentation](https://zh-v2.d2l.ai/chapter_convolutional-modern/nin.html#id3)