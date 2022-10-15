---
title: "Hamming_Distance_汉明距离"
tags:
- all
- InformationTheory
- Math
- CodingTheory
date: "2021-06-25"
---
# Hamming Distance / 汉明距离



汉明距离是对于两个**相同长度**的字符串而言, the number of positions at which the corresponding symbols are different(相同的位置上对应字符不同的位置个数)

### 图例
带色线条是路径示意

![3-bit binary cube|350](https://upload.wikimedia.org/wikipedia/commons/thumb/b/b4/Hamming_distance_3_bit_binary.svg/1280px-Hamming_distance_3_bit_binary.svg.png)

Two example distances: 100→011 has distance 3; 010→111 has distance 2

![3-bit binary cube Hamming distance examples|350](https://upload.wikimedia.org/wikipedia/commons/thumb/6/6e/Hamming_distance_3_bit_binary_example.svg/1280px-Hamming_distance_3_bit_binary_example.svg.png)

![4-bit binary tesseract|600](https://upload.wikimedia.org/wikipedia/commons/thumb/b/bf/Hamming_distance_4_bit_binary.svg/1920px-Hamming_distance_4_bit_binary.svg.png)
![4-bit binary tesseract Hamming distance examples|600](https://upload.wikimedia.org/wikipedia/commons/thumb/b/b4/Hamming_distance_4_bit_binary_example.svg/1920px-Hamming_distance_4_bit_binary_example.svg.png)

## Hamming Weight / 汉明重量
一个字符串与相同长度的全零字符串之间的汉明距离

The Hamming weight of a string is the number of symbols that are different from the zero-symbol of the alphabet used. 
It is thus equivalent to the Hamming distance from the **all-zero string of the same length**. 
