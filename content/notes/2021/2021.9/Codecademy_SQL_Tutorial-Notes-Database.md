---
title: "Codecademy_SQL_Tutorial-Notes-Database"
tags:
- all
- Database
- SQL
- SQLite
date: "2021-09-26"
---
# SQL Tutorial

<div align="right"> 2021-09-26</div>

Tags: #Database #SQL #SQLite

- This course use SQLite

**复习材料:**
- [SQL Commands - Glossary](https://www.codecademy.com/articles/sql-commands)
- [CheatSheet](https://www.codecademy.com/learn/learn-sql/modules/learn-sql-manipulation/cheatsheet)

下面只叙述CheatSheet里面没有的内容



## Clauses
`CREATE TABLE` is a _clause_. Clauses perform specific tasks in SQL. By convention, clauses are written in capital letters. Clauses can also be referred to as commands.
`INSERT`, `SELECT` etc. are also clauses.
中文: 子句?
## INSERT
- insert attribute 的顺序可以交换, 只要Tuple里面的顺序一一对应即可.
```sql
 INSERT INTO celebs (id, name, age)
 VALUES (1, 'Justin Bieber', 22);

 INSERT INTO celebs (name, id, age)
 VALUES ('Jeremy Lin', 3, 26);
```

- Multiple tuples: Quick way:
```sql
INSERT INTO table (col1, col2, col3)
VALUES
(row1_val1, row1_val2, row1_val3),
(row2_val1, row2_val2, row2_val3),
(row3_val1, row3_val2, row3_val3);
```

## ALTER
Order:
### Question

In the context of this [exercise 89](https://www.codecademy.com/paths/data-science/tracks/dspath-why-data-python-basics/modules/dspath-introduction-to-sql/lessons/manipulation/exercises/alter), can we add a column at a specific position to a table?

### Answer

No, unfortunately, you cannot specify what position to add a column to a table.

By default, a new column will always be added at the end of the table. For most intents and purposes, this should not affect much, since you can always select the columns in any order, for instance, like

```
SELECT col3, col1, col2
```

If column order is very important, then an alternative is to create a new table and add the columns in the specific order they should appear.

## DELETE
```sql
DELETE FROM celebs 
WHERE twitter_handle IS NULL;
```
- 这里的`IS NULL`可以换成`= NULL`吗?
	- 不可以, 没法删除


## SQLite
- In SQLite, a database is stored in **a single file** — a trait that distinguishes it from other database engines.
- Drawbacks
	- Security and Data Integrity issue
	- No Data-Type Verification
	- Less advanced features
	- SQLite’s maintainers consider it to be among the [most replicated pieces of software in the world](https://www.sqlite.org/mostdeployed.html).
	- 

## Part 2 Queries
### AS
- AS不改变原来的relation
- 你可以用逗号分隔两个查询重命名的项: 
```sql
SELECT name AS movie, imdb_rating AS IMDb
FROM movies;
```

### WHERE
- WHERE里面的相等是一个等号: `=`

### LIKE
- wildcard: `_` -> a single character
- `%` is a wildcard character that matches zero or more missing letters in the pattern.
- `LIKE` is **not** case sensitive.
- 如果要查找`_` 或`%`, 利用反斜杠表示转义字符: `\_`  `\%`

> ### Question
> 
> Can we apply the `LIKE` operator to values other than `TEXT`?
> 
> ### Answer
> 
> Yes, you can apply the `LIKE` operator to numerical values as well.
> 
> Whenever you use `LIKE` however, you must always wrap the pattern within a pair of quotations, whether for matching a number or a string.
> 
> #### Example
> 
> ```
> /* 
> This will select movies where the id number
> starts with 2 and is followed by any two numbers.
> */
> SELECT * 
> FROM movies
> WHERE id LIKE '2__';
> ```


### BETWEEN
```sql
SELECT *
FROM movies
WHERE year BETWEEN 1990 AND 1999;
```
这个范围是 [1990, 1999], 包括了1999,

但是如果是字符串的话, 就变得稍微有一点复杂:
看这个:
```sql
SELECT *
FROM movies
WHERE name BETWEEN 'A' AND 'J';
```
'Jaw' 会包括在里面吗? -> 不会
但是'J'会包括在里面

因为其实是这个顺序:
'A', 'Aa' ...... 'J', 'Ja',...........
到'J'那里就停下来了.

### CASE
```sql
SELECT name,
 CASE
  WHEN imdb_rating > 8 THEN 'Fantastic'
  WHEN imdb_rating > 6 THEN 'Poorly Received'
  ELSE 'Avoid at All Costs'
 END AS 'Review'
FROM movies;
```
- 注意第一行最后有一个逗号!
ELSE不是必须的
```sql
SELECT *,
  CASE
    WHEN review > 4.5 THEN 'Extraordinary'
    WHEN review > 4   THEN 'Excellent'
    WHEN review > 3   THEN 'Good'
    WHEN review > 2   THEN 'Fair'
    ELSE 'Poor'
  END AS 'New Review'
FROM nomnom;
```
CASE是从上向下匹配的, 所以第二行的不用再说明要小于4.5:
![](notes/2021/2021.9/assets/img_2022-10-15.png)

## Multiple Tables
### Inner Join
![](https://content.codecademy.com/courses/learn-sql/multiple-tables/inner-join.gif)

### LEFT JOIN
![](https://content.codecademy.com/courses/learn-sql/multiple-tables/left-join.gif)




## 学完了
有三个网站来回顾学习内容：
- [学前预览](https://www.codecademy.com/learn/learn-sql/modules/learn-sql-manipulation)
- [CheatSheet](https://www.codecademy.com/learn/learn-sql/modules/learn-sql-multiple-tables/cheatsheet)
- [Glossary Article](https://www.codecademy.com/articles/sql-commands)