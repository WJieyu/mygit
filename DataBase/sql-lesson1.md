# 5.6 Lesson

## 一、语法

1. 语法规则
- 语句以关键字开始
- 语句以分号结尾
- 不区分大小

2. 数据库表
- 数据库通常包含一个或多个表。
- 每个表用一个名称标识
- 每个表都包含带有数据(行)的记录

3. SQL语句
- 数据库上执行的大部分操作都是由SQL语句完成的

4. 分号？
- 一些数据库系统是需要的分号结尾的
- 分号是分离数据库系统中每个SQL语句的标准方法

5. 一些重要的SQL命令
- SELECT——从数据库中提取数据
- UPDATE——更新数据库中的数据
- DELETE——从数据库中删除数据
- INSERT INTO——向数据库中插入新数据
- CREATE DATABASE——创建新数据库
- ALTER DATABASE——修改数据库
- CREATE TABLE——创建新表
- ALTER TABLE——变更（改变）数据库表
- DROP TABLE——删除表
- CREATE INDEX——创建索引（搜索键）
- DROP INDEX——删除索引

## 二、Select语法(选择语句)
- 用于从数据库中选择数据
- 返回的结果存储在结果表中，称为结果集
- 基本语法SELECT FROM
    - 必须SELECT在前、FROM在后
    - SELECT指示查看哪些列，FROM标识它所在的表
    - column是要从中选择数据的表的字段名称
    ```
    SELECT column1,column2,...
    FROM table_name;
    ```
    - 如果要选中表中可用的所有字段：
    ```
    SELECT * FROM table_name;
    ```
- SELECT用例：
    - 检索一列：SELECT Sno FROM SC;
    - 检索多列：SELECT Sno,Cno FROM SC;(注意多列之间用逗号隔开)
    - 检索所有列：SELECT * FROM SC;

## 三、SELECT DISTINCT(选择不同)
1. SELECT DISTINCT语法用于仅返回不同的值
2. 在一张表中，一列可能包含许多重复的值，又是只想列出不同的值
3. 基本语法格式：
```
SELECT DISTINCT column1,column2,...
FROM table_name;
```
4. 如果想返回不同值的个数，例如：
```
SELECT COUNT(DISTINCT Cno) FROM SC; 
```

## 四、WHERE Clause(查询字句)
1. WHERE子句
- 用于过滤记录
- 用于提取满足制定标准的记录
- 语法：
```
SELECT column1,column2,...
FROM table_name
WHERE condition;
```
- WHERE子句不仅适用于SELECT语法，还适用于UPDATE,DELETE语法
    - UPDATE语句
    ```
    UPDATE "table_name"
    SET "column_1"="new value"
    WHERE "condition"
    ```
    - DELETE语句
    ```
    DELETE FROM "table_name"
    WHERE "condition";
    ```
2. 文本字段与数值字段
- 文本字段周围使用单引号
- 数值字段不要使用引号
3. WHERE子句中的运算符

|运算符|描述
|------|--
|=|等于
|<>|不等于
|>|大于
|<|小于
|>=|大于等于
|<=|小于等于
|BETWEEN|在某个范围内
|LIKE|搜索某种模式
|IN| 为列指定多个可能的值

## 五、AND OR NOT
1. AND & OR
- 用于根据一个以上的条件过滤记录（即组合多个条件以缩小SQL语句中的数据） 
- WHERE字句可以和AND OR NOT运算符结合使用 