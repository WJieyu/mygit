#include<iostream>
using namespace std;


//��������Ʒ����λ������ֵ�Ӵ�С��������
void Vsort(int w[],int v[],int order[],int n)
{
    int vw[100];
    for(int i=1;i<=n;i++){
        vw[i]=v[i]/w[i];
    }
    //���յ�λ��ֵ�Ӹߵ��������������
    for(int i=1;i<=n;i++){
        cout<<order[i]<<'\t';
    }
}

int bestP = 0;//��ǰ������õ�����ֵ
int cw=0
int main()
{
    int w[100];
    int v[100];
    int order[100];
    int n;
    int c;
}
