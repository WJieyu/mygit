//�����������Լ��
#include <iostream>

using namespace std;

void gys_max(int m,int n){

    //����һ������Ӳ��
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
    cout<<m<<"��"<<n<<"�����Լ����"<<t;
    */

    //��������շת�����

    int t=m%n;
    while(t!=0){
        m=n;
        n=t;
        t=m%n;
    }
    cout<<"���Լ����"<<n;


}

int main()
{
    int m;
    int n;

    cout<<"����������������";
    cin>>m>>n;
    gys_max(m,n);
    return 0;
}
