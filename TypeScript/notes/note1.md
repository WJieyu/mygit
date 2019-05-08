# 5.8 Study

## 一、基础类型
1. 布尔值
> let isDone:boolean = false;

2. 数字
> let decLiteral:number = 6;
> let hexLiteral:number = 0xf00d;
> let binaryLiteral:number = 0b1010;
> let octalLiteral:number = 0o744;

3. 字符串
> let name:string = "jieyu";
> let age:number = 18;
> let sentence:string = \`Hello,my name is \${ name }.
>
>I'll be \${ age+1 }years old next month.`;
>或
>let sentence:string = " Hello,my name is"+name+".\n\n"+"I'll be"+(age+1)+"years old next month.";

4. 数组
- 方式一：
> let list:number[ ]=[1,2,3];
- 方式二：
> let list:Array<number>=[1,2,3];

5. 元组
- 元组表示一个已知元素数量和类型的数组。与数组的区别在于各元素的数据类型可以不一致
- 定义：
> let x:[string,number];
> x = ['hello',10];//OK
> x = [10,'hello'];//error
- 联合类型

6. 枚举
> enum Color {Red=1,Green,Blue};
> let c:Color = Color.Green;
> let colorName:string=Color[2]; 

7. 任意值
>let notSure:any = 4;
>notSure="maybe a string instead";//ok
>notSure=false;//ok
- 定义一个对象，若他的对象类型是any，可以调用其中所有成员。若他的对象类型是object，只能对其成员变量赋初值，不能调用其成员函数 。
- 在定义一个不知道元素数据类型的数组时，可以用any对数组类型进行定义。

8. 空值
- 使用void，如果某个函数没有返回值，就使用它。
- 声明一个void类型的变量，其值只能是undefined或null。

9. Null和Undefined
> let u: undefined = undefined;
> let n: null = null;
- 他们是所有类型的子类型。
- 当指定了--strictNullChecks标记，null和undefined只能赋值给void和它们各自。

10. Never
- never类型表示永不存在的值得类型。
- never类型是那些总是会抛出异常或根本不会有返回值的函数表达式或箭头函数表达式的返回值类型。
- 当变量被永不为真的类型保护所约束时。
- never是任何类型的子类型，比any还低。

11. 类型断言
- 方法一：
>let someValue: any = "this is a string";

let strLength: number = (<string>someValue).length;
- 方法二：
>let someValue: any = "this is a string";

let strLength: number = (someValue as string).length;

12. let
- 尽可能使用let代替var！