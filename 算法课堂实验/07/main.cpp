#include<iostream>
using namespace std;


//将各个物品按单位重量价值从大到小进行排序
void Vsort(int w[],int v[],int order[],int n)
{
    int vw[100];
    for(int i=1;i<=n;i++){
        vw[i]=v[i]/w[i];
    }
    //按照单位价值从高到低排序并依次输出
    for(int i=1;i<=n;i++){
        cout<<order[i]<<'\t';
    }
}

int bestP = 0;//当前背包获得的最大价值
int cw=0
int main()
{
    int w[100];
    int v[100];
    int order[100];
    int n;
    int c;
}
