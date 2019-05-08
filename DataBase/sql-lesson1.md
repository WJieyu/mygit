# 5.6 Study(基础)

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

## 五、AND,OR,NOT
1. AND & OR
- 用于根据一个以上的条件过滤记录（即组合多个条件以缩小SQL语句中的数据） 
- WHERE子句可以和AND OR NOT运算符结合使用 
- 由AND分割的所有条件为TRUE，则AND运算符显示其结果
- 若使用AND组合n个条件，则AND分割的所有条件都必须为TRUE
- 由OR分割的任意条件为TRUE，则OR运算符显示其结果
- 若使用OR组合n个条件，则AND分割的任一条件必须为TRUE
- 如果条件不为TRUE，NOT运算符显示记录
- 语法
    - AND:
    ```
    SELECT column1,column2...
    FROM table_name
    WHERE condition1 AND condition2 AND condition3...;
    ```
    - OR:
    ```
    SELECT column1,column2...
    FROM table_name
    WHERE condition1 OR condition2 OR condition3...;
    ```
    - OR:
    ```
    SELECT column1,column2...
    FROM table_name
    WHERE NOT condition;

## 六、ORDER BY Keyword(按关键字进行排序)
- ORDER BY关键字用于按升序或降序对结果集进行排序
- ORDER BY默认情况下按升序排序记录
- 如果要按照降序，需要关键字DESC
- 语法：
```
SELECT column1,column2,...
FROM table_name
ORDER BY column1,column2,...ASC|DESC;
```

## 七、INSERT INTO(在表中插入)
- INSERT INTO语句用于向表中插入新的数据行
- 语法：
    - (1)指定要插入数据的列的名称，同时提供要插入的值，即可添加一行新的数据，未指明的列的值为null
    ```
    INSERT INTO table_name(column1,column2,...)
    VALUES(value1,value2,value3);
    ```
    - (2)如果要为表中所有列添加值，则不需要在SQL查询中指定列名称，但是要确保顺序相同(添加的值与属性列一一对应)
    ```
    INSERT INTO table_name
    VALUES(value1,value2,value3...)
    ```
    - (3)使用另一个表填充一个表
    通过另一个表上的SELECT语句查询出来的字段块将其填充到本表中，条件是选择出的字段与本表中要插入数据的字段保持一致
    ```
    INSERT INTO first_table_name(column1,column2,...)
    SELECT column1,column2,...
    FROM second_table_name
    [WHEREcondition];
    ```

## 八、NULL Value(空值)
- NULL表示缺失的值。(该值所处的字段为空)
- 如果表中的字段可选，则可以插入新记录或更新记录而不向该记录添加值。此时该字段将被保存为NULL值
- NULL的字段没有值，注意与0或空格的字段是不同的
- 测试NULL值？
    - IS NULL语法
    ```
    SELECT column_names
    FROM table_name
    WHERE column_name IS NULL;
    ```
    - IS NOT NULL语法
    ```
    SELECT column_names
    FROM table_name
    WHERE column_name IS NOT NULL;
    ```
- 创建语法
```
CREATE TABLE CUSTOMERS(
   ID   INT              NOT NULL,
   NAME VARCHAR (20)     NOT NULL,
   AGE  INT              NOT NULL,
   ADDRESS  CHAR (25) ,
   SALARY   DECIMAL (18, 2),       
   PRIMARY KEY (ID)
);
```
注意：值为NULL的字段是在记录创建的过程中留白的字段

## 九、UPDATE语句(更新表中的记录)
- 用于更新表中已存在的记录
- 可以使用AND或OR运算符组合多个条件
- 语法：
```
UPDATE table_name
SET column1 = value1, column2 = value2, ...
WHERE condition;
```
- 注意SQL UPDATE 语句中的 WHERE 子句！ 
WHERE子句指定哪些记录需要更新。如果省略WHERE子句，所有记录都将更新！
- 更新多个记录：WHERE子句决定了将要更新的记录数量

## 十、DELETE语句(删除)
- 用于删除表中现有记录
- 语法：
```
DELETE FROM table_name
WHERE condition;
```
- 删除表格中的记录时要小心！
注意SQL DELETE 语句中的 WHERE 子句！ 
WHERE子句指定需要删除哪些记录。如果省略了WHERE子句，表中所有记录都将被删除！
- 删除所有数据(删除表中行，不删除表)
```
DELETE FROM table_name;
```
或
```
DELETE * FROM table_name;
```

## 十一、运算符
- 算术运算符：+-*/%
- 比较运算符：== |= <>...
- 逻辑运算符:ALL AND ANY BETWEEN EXISTS IN LIKE NOT OR IS/NULL UNIQUE 
- 否定条件运算符

## 十二、表达式
- 布尔表达式
- 数值表达式
- 日期表达式

## 十三、USE语句
- 当存在多个数据库时，使用USE语句选择一个执行所有操作的数据库
- 语法：
```
USE DatabaseName;
```
数据库名称必须唯一
- 查看某个数据库
```
SHOW DATABASES;
```
