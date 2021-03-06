# STL编程

## 1.STL编程思想
- 泛型：允许一个值取不同数据类型的技术。
  泛型程序设计：使用泛型技术的编程方法。
- 逻辑层次上看，STL是泛型化程序设计思想在C++上的具体应用。分离数据结构和与算法完全分离，提高代码重用的效率。
- 实现层次上看，STL是类型参数化的程序设计方法。基于模板的标准类库（容器类），每个容器都是一种已经建立完成的标准数据结构。
- STL编程的目的：
将经典的数据结构采用类型参数的形式，设计为通用的类模板或函数模板，允许程序员重复利用C++标准库中已定义好的通用数据结构来构造符合自己需求的特定数据结构，有利于简化程序开发，提高软件的开发效率。
- 5个组成部分：
容器（container）、迭代器（iterator）、适配器（adapter）、算法（algorithm）、函数对象（function object）
## 2.STL容器
- 容器：
    - 所有STL容器都是类模板，一个容器内只能存储同种类型的数据，该类型可以是任何类型的数据，甚至是自己定义的类，而不需要自己在定义其他的数据结构。
    - 包括向量、列表、队列、集合、映射等。
1. 顺序容器
- 以逻辑线性排列方式存储一个元素序列，这个容器类型中的对象在逻辑上被认定是在连续的存储空间中存储的。
- 用于存储线性表类型的数据结构。
- 分类：
    - vector(向量)：
        - 动态数组，可随元素的变化自动扩容。
        - 采用连续存储空间，需要添加元素时直接从尾部插入。
        - 若添加元素后空间不足，将全部搬运到一个新的内存空间中，所有元素值复制过去。
        - 适用于快速的存取元素，而很少增添和删除元素的地方。
        - vector容器中一些重要的成员函数

        |函数名|功能说明
        |------|---
        |push_back|在容器后端添加元素
        |push_pop|	在容器后端删除元素
        |insert|在容器中间插入元素
        |size|返回当前容器中的元素个数
        |begin|返回容器前端的迭代器
        |end|
        
    - list(列表)：
        - 双向链表，每个结点包含一个元素，每个元素均有指针指向前一个元素和下一个元素。
        - 适用于需要快速插入和删除，不在意查找速度的地方。

    - deque(队列)：
        - 在内存中不占用一块连续的空间
        - 可在元素序列的两端插入和删除数据，也能快速的存取某种数据
        - 和vector很类似，但deque能在序列前端插入元素。
        - 如果想插入元素但内存空间不足，将新元素存储到另一块内存当中。
        - deque容器中一些重要的成员函数

        |函数名|功能说明
        |---|---
        |push_front|在容器前端添加元素
        |pop_front|在容器前端删除元素
        |push_back|在容器后端添加元素
        |pop_back|在容器后端删除元素
        |insert|在容器中间插入元素
        |front|返回容器前端元素的引用
        |back|返回容器后端元素的引用

    - 注意它们的头文件都要添加<……>

- 迭代器：广义指针，指向容器中某个位置的数据元素
    - 不同的容器需要不同的迭代器，类型为 容器类名::iterator
    - 基本特征：解除(*p,p->)、赋值(p=q)、比较(p==q,p!=q)、遍历(++p,p++)
    - 操作：读(x=*p)、写(*p=x)、访问(p[2]、p->m)、迭代(++、--、+=、-=)、比较(==、!=、<、>、<=、>=)
- 不同容器提供的迭代器功能不同，值得注意的是list容器的迭代器不支持加减运算，因为是双向迭代器。deque和vector基本上都支持。
- 除了标准迭代器外，其他三种迭代器：
    - reverse_iterator：反转遍历的方向
    - const_iterator：向前方向，返回一个常数值，指向一个只读的值。
    - const_reverse_iterator:朝反方向遍历的迭代器，返回一个常数值。

- 容器适配器：将顺序容器转换为另一种容器（以顺序容器为基础将其转换为新的容器，转换后的新容器有新的特殊操作要求）（不支持迭代器）
    - queue
    - priority queue
    - stack
2. 关联容器
## 3.STL算法
## 4.STL函数对象
