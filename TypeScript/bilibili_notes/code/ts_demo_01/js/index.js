"use strict";
/*
console.log("nihao");

function getData(){

}
var num:number=5;
var str:string="晚安！";
*/
/*
1. vscode配置自动编译

    1.第一步：tsc --init 生成tsconfig.json 改"outdir":"./js",

    2.第二步：终端 - 运行任务 监视tsconfig.json

2. typescript中的数据类型

    typescript中为了使编写的代码更规范，更有利于维护，增强了类型校验，在typescript中主要给我们提供了以下数据类型

        布尔类型（boolean）
        数字类型（number）
        字符串类型（string）
        数组类型（array）
        元组类型（tuple）
        枚举类型（enum）
        null和undefined
        void类型
        never类型

*/
//布尔类型（boolean）
/*
es5的写法（正确语法）   ts中（错误语法）
    var flag=true;
    flag=456;
*/
/*
 typescript中为了使编写的代码更规范，更有利于维护，增加了类型校验
 写ts代码必须指明类型

    var flag:boolean=true;

    //flag = 123; //  error!

    flag = false; //    ok!

    console.log(flag);
*/
//数字类型（number）
/*
    var num:number=123;
    
    num=456;
    
    console.log(num);     //ok

    num='str';   //error!
*/
//字符串类型（string）
/*
    var str:string = 'this is ts';
    
    str="haha"; //ok
    
    str= true;//error
*/
//数组类型（array）
//ts中定义数组有两种方式
//var arr=['1','2'];//es5定义数组
//1.第一种定义数组的方式
/*
 var arr1:number[]=[11,22,33];
 console.log(arr1);
*/
//2.第二种定义数组的方式
/*
 var arr2:Array<number>=[11,22,33];
 console.log(arr2);
*/
//3.第三种
/*
 var arr3:any[]=['123',22,true];
 console.log(arr);
*/
//元组类型（tuple）属于数组的一种
//var arr:Array<number>=[11,22,33];  
//console.log(arr);
//元组类型
//let arr:[number,string]=[123,"this is a ts"];
//console.log(arr);
//枚举类型（tuple）
/*
    enum 枚举名{
        标识符[=整型常量],
        标识符[=整型常量],
        ...
        标识符[=整型常量],
    };

*/
/*
    enum Flag{
        success=1,
        error=2,
    };
    let s:Flag=Flag.success;
    console.log(s);

    enum Flag{
        success=1,
        error=2,
    };
    let f:Flag=Flag.error;
    console.log(f);
*/
/*
    enum color{blue,red,'orange'};
    var c:color=color.red;
    console.log(c);//1 如果标识符没有赋值，它的值就是下标
*/
/*
    enum color{blue,red=3,'orange'};
    var c:color=color.red;
    console.log(c);     //3
    var d:color=color.orange;
    console.log(d);     //4
*/
/*
    enum Err{'undefined'=-1,'null'=-2,'success'=1}；
    var e:Err=Err.null;
    console.log(e);
*/
//任意类型（any）
//var num:any=123;
//num='str';
//num='true';
//console.log(num);
//任意类型的用处
// var oBox:any=document.getElementById('box');
// oBox.style.color='red';
//null 和 undefined   其他（never类型）数据类型的子类型
// var num:number;
// console.log(num);//输出:undefined 报错
// var num:undefined;
// console.log(num);   //输出：undefined 正确
// var num:number |undefined;
// num=123;
// console.log(num);
//定义未赋值
// var num:number |undefined;
// console.log(num);
//var num:null;
// num=123; //出错
// num=null; //正确
//一个元素可能是number类型，可能是null，可能是undefined
// var num:number|null|undefined;
// num=123;
// console.log(num);
//void类型：typescript中的void表示没有任何类型，一般用于定义方法的时候方法没有返回值
//es5的定义方法
// function run(){
//     console.log('run');
// }
// run();
//表示方法没有返回任何类型
// function run():void{
//     console.log('run');
// }
// run();
//错误写法
// function run():number{
//     console.log('run');
// }
// run();
//正确写法
function run() {
    return 123;
}
//never类型：是其他类型（包括null 和 undefined）的子类型，代表从不会出现的值，
//这意味着声明never的变量只能被never类型所赋值
// var a:undefined;
// a=undefined;
// var b:null;
// b=null;
// var a:never;
// //a = 123;//error
// a=(()=>{
//     throw new Error("错误");
// })()
