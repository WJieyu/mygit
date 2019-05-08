# 5.8 Study(高级)

## 一、SELECT TOP,LIMINT,ROWNUM
1. SELECT TOP子句
- 用于指定要返回的记录数量
- 在包含数千条记录的大型表上很有用，因为返回大量记录会影响性能。
- MYSQL支持LIMIT子句来选择有限数量的记录，Oracle使用ROWNUM
2. 语法
- 返回表中前两条所有记录
```
SELECT TOP 2 * FROM table_name;
``` 
- 返回表中前50%所有记录
```
SELECT TOP 50 PERCENT * FROM table_name;
```
- 如若添加条件可选择在其原有语句后边加WHERE子句。

## 二、LIKE运算符
1. 在WHERE子句中使用LIKE运算符来搜索列中的指定模式
2. 与LIKE一起使用的两个重要通配符
    - %:百分号表示0个、一个、多个字符
    - _:下划线表示单个字符
3. 语法
```
SELECT column1, column2, ...
FROM table_name
WHERE columnN LIKE pattern;
```
4. 实例：
- columnN表示的是表中某个列的某个具体值，当其满足pattern要求时予以选择

## 三、Wildcards通配符
1. 用于替换字符串中的任何其它字符
2. 与LIKE运算符一起使用。在WHERE子句中使用LIKE运算符来搜索列中指定模式。
3. 两个重要的通配符：% _
4. 通配符可组合使用
5. 通配符[charlist]
- 定义要匹配的字符的集合和范围
6. 通配符[!charlist]
- 定义不匹配的字符的集合和范围

## 四、IN运算符
1. 允许在WHERE子句中指定多个值
IN运算符是多个OR条件的简写
NOT IN运算符
2. 语法：
```
SELECT column_name(s)
FROM table_name
WHERE column_name IN (value1, value2, ...);
```
或
```
SELECT column_name(s)
FROM table_name
WHERE column_name IN (SELECT STATEMENT);
```

## 五、BETWEEN运算符
1. 用于选取介于两个值之间的数据范围内的值，值可以是数字、文本或日期。它是包含性的：包括开始和结束值，且开始值小于结束值

