//设置类
var Student = /** @class */ (function () {
    function Student(firstName, middleInitial, lastName) {
        this.firstName = firstName;
        this.middleInitial = middleInitial;
        this.lastName = lastName;
        this.fullName = firstName + " " + middleInitial + " " + lastName;
    }
    return Student;
}());
function greeter(person) {
    return "Hello," + person.firstName + " " + person.lastName;
}
// var user = "wujieyu";
// var user={firstName:"wujieyu",lastName="user"};
// var user = [1,2,3];
var user = new Student("jieyu", "wu", "User");
document.body.innerHTML = greeter(user);
