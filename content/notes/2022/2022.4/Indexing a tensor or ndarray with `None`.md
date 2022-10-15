---
title: "Indexing a tensor or ndarray with `None`"
tags:
- all
- Numpy
- PyTorch
date: "2022-04-20"
---
#  `None` as index 

<div align="right"> 2022-04-20</div>

Tags: #Numpy #PyTorch 

## `None` in index is equivalent to `unsqueeze()`
Similar to NumPy you can insert a singleton dimension (_"unsqueeze"_ a dimension) by indexing this dimension with `None`. In turn `n[:, None]` will have the effect of inserting a new dimension on `dim=1`. This is equivalent to `n.unsqueeze(dim=1)`:

```
>>> n = torch.rand(3, 100, 100)

>>> n[:, None].shape
(3, 1, 100, 100)

>>> n.unsqueeze(1).shape
(3, 1, 100, 100)
```

## Some other types of _`None` indexings_.
In the example above `:` is was used as a placeholder to designate the first dimension `dim=0`. If you want to insert a dimension on `dim=2`, you can add a second `:` as `n[:, :, None]`.

You can also _place_ `None` with respect to the last dimension instead. To do so you can use the [ellipsis](https://python-reference.readthedocs.io/en/latest/docs/brackets/ellipsis.html) syntax `...`:

-   `n[..., None]` will insert a dimension last, _i.e._ `n.unsqueeze(dim=-1)`.
    
-   `n[..., None, :]` on the before last dimension, _i.e._ `n.unsqueeze(dim=-2)`.

## `None` is slower than `unsqueeze()`
`None` is a version with advanced indexing , which might be a bit slower because it has more checking to do to find out exactly what you want to do.

---
Sources:
- [syntax - Indexing a tensor with None in PyTorch - Stack Overflow](https://stackoverflow.com/a/69797906/15893958)
- [What is the difference between [None, ...] and unsqueeze? - PyTorch Forums](https://discuss.pytorch.org/t/what-is-the-difference-between-none-and-unsqueeze/28451)