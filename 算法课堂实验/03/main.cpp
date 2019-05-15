//���������(�漰��������)
//���ڷ��η�
#include <iostream>
#include <math.h>
using namespace std;

struct point
{
    int x,y;
};

double Distance(point a,point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

int partion(point p[],int first,int last)
{
    int i=first;
    int j=last;

    while(i<j){
        while(i<j&&p[i].y<=p[j].y) j--;//�����������ɨ�裬�ҵ����ұ߿���һ������ֵ�����
        if(i<j){
            point temp=p[i];
            p[i]=p[j];
            p[j]=temp;
            i++;
        }
        while(i<j&&p[i].y<=p[j].y) i++;//�������ҽ���ɨ�裬�ҵ�����߿���һ������ֵС����
        if(i<j){
            point temp=p[i];
            p[i]=p[j];
            p[j]=temp;
            j--;
        }
    }
    return i;
}

void quicksort(point p[],int first,int last)
{
    cout<<"������ų���"<<endl;
    int pivot;
    if(first<last){
        pivot=partion(p,first,last);
        quicksort(p,first,pivot-1);
        quicksort(p,pivot+1,last);
    }
}

double closest(point *S,int low,int high)
{
    double d1,d2,d3,d;
    int mid,i,j,index;
    point P[high+1];

    if(high-low==1){      //  ֻ������������
        cout<<"�����һ�����"<<endl;
        return Distance(S[low],S[high]);

    }

    if(high-low==2){          //  ��3��������
        cout<<"����ڶ������"<<endl;
        d1=Distance(S[low],S[low+1]);
        d2=Distance(S[low+1],S[high]);
        d3=Distance(S[low],S[high]);
        if((d1<d2)&&(d1<d3)){
            return d1;
        }
        else if(d2<d3){
            return d2;
        }else
            return d3;
    }

    cout<<"������������"<<endl;
    mid = (high+low)/2;         //��n���������
    d1 = closest(S,low,mid);//��ߵ���̾���
    d2 = closest(S,mid+1,high);//�ұߵľ���
    if(d1<d2)   d=d1;
    else    d=d2;//��¼��������ȫ����ʱ����̾���
    cout<<d<<endl;

    index = 0;
    for(i=mid;(i>=low)&&(S[mid].x-S[i].x<d);i--){    //���м���ǰ�߻���
        P[index++]=S[i];
    }
    for(i=mid+1;(i<=high)&&(S[i].x-S[mid].x<d);i++){     //���м�����߻���
        P[index++]=S[i];
    }
    //������������ľ���С�ڵ���d�ĵ�ȫ���ս�P������

    quicksort(P,0,index-1);//��y�������������
    for(int i=0;i<index;i++)
    {
        cout<<P[i].y<<'\t';
    }
    cout<<endl;
    for(i=0;i<index;i++){
        for(j=i+1;j<index;j++){
            //cout<<"��������������ѡ��"<<endl;
            cout<<"----------"<<endl;
            cout<<P[i].x<<P[i].y<<endl;
            cout<<P[j].x<<P[j].y<<endl;
            if(P[j].y-P[i].y>d){
                cout<<"break"<<endl;
                break;
            }
            else{
                d3=Distance(P[i],P[j]);
                cout<<"d3="<<d3<<endl;
                if(d3<d) d=d3;


            }
        }
    }
    return d;
}


int main()
{
    int n;

    point S[20];

    double closest_distance;

    cout<<"Ҫ����ĵ�ĸ�����";
    cin>>n;

    cout<<"���������������꣺"<<endl;
    for(int i=0;i<n;i++){
        cout<<"��"<<i+1<<"���㣺"<<endl;
        cin>>S[i].x>>S[i].y;
    }

    closest_distance=closest(S,0,n-1);

    cout<<"����Եľ�����"<<closest_distance<<endl;
    return 0;
}

/*������
    ��һ���������1��3����2��4�� ����1.4141
    �ڶ����������1��3����2��4����2��3�� ����1
    �������������1��2����3��5����2��4�� ��3��2�� ����1.4141
*/
