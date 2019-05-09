//设置类
class Student{
    fullName:string;
    constructor(public firstName,public middleInitial,public lastName){
        this.fullName=firstName+" "+middleInitial+" "+ lastName;
    }
}

//接口
interface Person{
    firstName:string;
    lastName:string;
}

function greeter(person:Person){
    return "Hello,"+person.firstName+" "+person.lastName;
}

// var user = "wujieyu";
// var user={firstName:"wujieyu",lastName="user"};
// var user = [1,2,3];
var user=new Student("jieyu","wu","User");
document.body.innerHTML = greeter(user);