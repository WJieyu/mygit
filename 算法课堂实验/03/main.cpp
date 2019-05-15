//最近对问题(涉及快速排序)
//基于分治法
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
        while(i<j&&p[i].y<=p[j].y) j--;//从右往左进行扫描，找到从右边看第一个比左值大的数
        if(i<j){
            point temp=p[i];
            p[i]=p[j];
            p[j]=temp;
            i++;
        }
        while(i<j&&p[i].y<=p[j].y) i++;//从左往右进行扫描，找到从左边看第一个比左值小的数
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
    cout<<"进入快排程序"<<endl;
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

    if(high-low==1){      //  只有两个点的情况
        cout<<"进入第一种情况"<<endl;
        return Distance(S[low],S[high]);

    }

    if(high-low==2){          //  有3个点的情况
        cout<<"进入第二种情况"<<endl;
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

    cout<<"进入第三种情况"<<endl;
    mid = (high+low)/2;         //有n多个点的情况
    d1 = closest(S,low,mid);//左边的最短距离
    d2 = closest(S,mid+1,high);//右边的距离
    if(d1<d2)   d=d1;
    else    d=d2;//记录讲两边完全隔开时的最短距离
    cout<<d<<endl;

    index = 0;
    for(i=mid;(i>=low)&&(S[mid].x-S[i].x<d);i--){    //从中间往前边回溯
        P[index++]=S[i];
    }
    for(i=mid+1;(i<=high)&&(S[i].x-S[mid].x<d);i++){     //从中间往后边回溯
        P[index++]=S[i];
    }
    //将所有离中轴的距离小于等于d的点全部收进P数组中

    quicksort(P,0,index-1);//按y轴坐标进行排序
    for(int i=0;i<index;i++)
    {
        cout<<P[i].y<<'\t';
    }
    cout<<endl;
    for(i=0;i<index;i++){
        for(j=i+1;j<index;j++){
            //cout<<"进入排序后的最终选择"<<endl;
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

    cout<<"要输入的点的个数：";
    cin>>n;

    cout<<"请依次输入点的坐标："<<endl;
    for(int i=0;i<n;i++){
        cout<<"第"<<i+1<<"个点："<<endl;
        cin>>S[i].x>>S[i].y;
    }

    closest_distance=closest(S,0,n-1);

    cout<<"最近对的距离是"<<closest_distance<<endl;
    return 0;
}

/*举例：
    第一种情况：（1，3）（2，4） 返回1.4141
    第二种情况：（1，3）（2，4）（2，3） 返回1
    第三种情况：（1，2）（3，5）（2，4） （3，2） 返回1.4141
*/
