//8枚硬币问题（即假币问题）
#include <iostream>

using namespace std;

const int N=8;
int a[N]={2,2,2,2,1,2,2,2};

int coin(int low,int high,int n)
{
    int i,num1,num2,num3;
    int add1=0,add2=0;

    if(n==1)    return low+1;

    if(n%3==0)
    {
        num1=num2=n/3;
    }
    else
    {
        num1=num2=n/3+1;
    }
    num3=n-num1-num2;
    for(i=0;i<num1;i++){
        add1+=a[low+i];
    }
    for(i=num1;i<num1+num2;i++){
        add2+=a[low+i];
    }
    if(add1<add2)
        return coin(low,low+num1-1,num1);
    else if(add1>add2)
        return coin(low+num1,low+num1+num2-1,num2);
    else
        return coin(low+num1+num2,low+num1+num2+num3-1,num3);
}
int main()
{
    int t;
    //考虑如果是n枚硬币的话
    /*
    int n;
    int a[100];
    cout<<"请输入硬币的枚数:";
    cin>>n;
    cout<<"请依次输入硬币的质量：";
    for(int i=0;i<n;i++)
        cin>>a[i];
    t=coin(a,0,n-1,n);//这个时候要注意给函数形参定义原质量数组
    */
    t=coin(0,N-1,N);
    cout<<"假币所在的位置是"<<t<<endl;
    return 0;
}
