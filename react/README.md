# React 慕课学习笔记
---
## **React开发环境的搭建**
1. 进入node官网安装node.js
   命令行node -v查看node版本
   命令行npm -v查看npm版本 （npm会随node同时安装在电脑上）

2. 进入react官网 --> 点击文档 --> 点击创建新的React应用 --> 找到一下三句话并在命令行中依次输入：
```
npx create-react-app my-app
cd my-app
npm start
```
>1. my-app可以是自己随意取的名，如果调用npx语句时的根目录在桌面，那么运行完这一条语句后会自动在桌面上生成一个以my-app命名的文件夹。
>2. cd my-app表示将当前根目录切换到my-app文件底下
>3. npm start运行后，会自动地打开一个浏览器网页，页面模样即：![](images\1.png)
>4. 本例中我将my-app重置为TodoList。

---
## **项目工程代码精简**
1. 所生成的文件夹其中包含的文件有以下几个：
![文件内容](images\2.png)

2. 项目文件内容主要包含在src文件夹中，其中项目入口在index.js文件中。

3. serviceWorker在本项目中不发挥作用，因此注释掉相关的两条语句；除此之外，还有一个serviceWorker.js文件也将其去掉。
![index.js](images\3.png)

4. index.css用于调整输出界面格式，在此程序中当不导入该文件时对界面输出的影响不大，因此将import index.css语句和index.css文件删除。 

5. App.test.js用于后期对jest作自动化测试，此时不需要该文件，将其删除。

6. index.js中引入了import App from '. / App';App没写后缀其实就是App.js文件，那么此时是先寻找App.js文件。

7. 修改App.js中的div标签块中的程序内容,改变网页的界面显示.
![App.js](images\4.png)
![](images\5.png)

8. 删除App.js中调用App.css的语句以及App.css文件。

9. 删除App.js中调用logo.svg(矢量图)的调用语句和logo.svg文件。

**总结**：
- 文件最后精简的程度是src文件夹中只包含index.js文件和App.js文件，index.js文件通过调用App.js文件在页面中中输出相应信息。

---
## **组件**
1. 组件是网页上的一部分！
2. public文件夹中的index.html能显示网页源代码
3. index.js中导入React的目的是让程序能够理解组件的这种语法形式。导入ReactDOM帮助组件能够成功对标签进行渲染。
4. App.js将App定义为一个组件，注意组件都是以大写字母开头。组件的定义要用class，并继承React.Component。组件编写的内部必须包含render(){}函数，它可以用来帮助组件显示内容
5. App.js末尾的export default App是导出，是与import导入功能配套使用的。

---
## **JSX语法**
1. 可以直接使用标签形式的代码结构
2. 可以在JSX中写js的表达式（要用花括号括起来），但不能写js语句。

---
## **编写TodoList功能**
1. 将所有App名字全部改写成TodoList,先解决名字问题。

2. 在TodoList组件中设置功能：
    - 在第一个div标签中设置一个输入框，使用input/标签。同时设置一个按钮，使用button标签，增加提示语。
    - 在第二个div标签内设置列表，使用ul和li标签。
    - 此时运行程序报错，因为return中jsx语法只允许包含一个div，因此考虑将两个div用一个大div包起来。

3. 事件绑定；
```
    -> 修改button语句为：
    <button onClick={this.handleBtnClick}>add</button>
    
    -> 同时在组件中需要新写一个函数：（位置在render()之外）
    handleBtnClick(){
    alert("click!");
    }
```
显示结果就是每次点击add按钮时，浏览器会弹出click！对话框。

4. 修改列表源码的写作形式
    - 在组件中写一个构造函数
    ```
    constructor(props){
        super(props);
        this.state={
            list:[
                'study react',
                'study vue',
                'study english'
            ]
        }
    }
    ```
    - 将原本直接填li列表的代码进行修改
    ```
    {this.state.list.map((item)=>{
            return <li>{item}</li>
           }
        )
    }
    ```
    map()函数用于对this.state中定义的list中每个元素进行循环遍历，并每一次将其值传给item，通关item进行传参参与return 语句的输出。
5. 点击add能增添列表固定值
    - 在handleBtnClick()函数中进行设置
    ```
    handleBtnClick(){
    this.setState({
        list:[...this.state.list,'Hello World!']
        })
    }
    ``` 
    - 注意，此时的this已经不再是原生组件了，而是变成了button，因为它是在button的标签中进行调用的。因此为了改变这个this所指定的对象，修改调用语句。
    ```
    <button onClick={this.handleBtnClick.bind(this)}>add</button>
    ```
    得到的结果是：每点击一次add按钮都会新增一行Hello World!列表
6. 将原来设置的list所包含的值删掉，浏览器刷新，那么每点击一次add，就会新生成一个Hello World！列表，此时打开后台开发者工具console，是有错误提示的。
    原因及解决方案：
    ```
    {this.state.list.map((item,index)=>{
        return <li key="index">{item}</li>
    })}
    ```
    需要给每次的输出贴上一个标签来表示之间的不同。
    map()函数的第二个参数即表示了每个item在其中的位置。用index来标识不同item中的值正好能方便地解决此类问题。

**总结**：
- 难点：this指向问题
- es6语法和js基础！

---

**新增列表项的功能实现**
1. 
