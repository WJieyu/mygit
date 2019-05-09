"use strict";
/*
    typescript中的函数
    
        1.函数的定义
        2.可选参数
        3.默认参数
        4.剩余参数
        5.函数重载
        6.箭头函数  es6
*/
//1.函数的定义
//es5定义函数
//函数声明法
// function run(){
//     return 'run';
// }
//匿名函数
// var run2=function(){
//     return "run2";
// }
//ts中定义函数的方法
//函数声明法
// function run():string{
//     return 'run';
// }
//错误写法
// function run():string{
//     return 123;
// }
//匿名函数
var fun2 = function () {
    return 123;
};
alert(fun2()); /*调用方法*/
