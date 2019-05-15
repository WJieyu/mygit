//最大子段和问题
//采用分治法

#include <iostream>

using namespace std;

int max_sum(int *a,int left,int right)
{
    int sum=0;
    int midSum=0,leftSum=0,rightSum=0;
    int center;
    int s1,s2,lefts,rights;

    if(left==right)//序列只有一个元素的情况
        return a[left];
    else
    {
        center=(left+right)/2;//将序列划为左右两个部分
        leftSum=max_sum(a,left,center);//左边部分的最大字段和
        rightSum=max_sum(a,center+1,right);//右边部分的最大子段和

        s1=0;//第三种情况，当最大子段和的元素横跨了中间元素的时候
        lefts=0;
        for(int i=center;i>=left;i--){
            lefts+=a[i];
            if(lefts>s1)
                s1=lefts;//从中往左数最大的子段和
        }

        s2=0;
        rights=0;
        for(int j=center+1;j<=right;j++){
            rights+=a[j];
            if(rights>s2)   s2=rights;//从中往右的最大的子段和
        }
        midSum=s1+s2;
        if(midSum<leftSum) sum=leftSum;
        else sum=midSum;
        if(sum<rightSum)    sum=rightSum;
    }
    return sum;
}

int main()
{
    int a[100];
    int n;

    cout<<"请输入一组序列的数字个数：";
    cin>>n;

    cout << "请输入该组序列:";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    cout<<"最大子段和的值为:"<<max_sum(a,0,n-1)<<endl;
    return 0;
}


