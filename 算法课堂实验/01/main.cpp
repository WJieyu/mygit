//求两数的最大公约数
#include <iostream>

using namespace std;

void gys_max(int m,int n){

    //方法一：蛮力硬搞
    /*
    int t = m<n?m:n;
    while(1){
        if((m%t==0)&&(n%t==0)){
            break;
        }
        else{
            t--;
        }
    }
    cout<<m<<"和"<<n<<"的最大公约数是"<<t;
    */

    //方法二：辗转相除法

    int t=m%n;
    while(t!=0){
        m=n;
        n=t;
        t=m%n;
    }
    cout<<"最大公约数是"<<n;


}

int main()
{
    int m;
    int n;

    cout<<"请输入两个整数：";
    cin>>m>>n;
    gys_max(m,n);
    return 0;
}
