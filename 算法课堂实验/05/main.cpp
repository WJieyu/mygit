//����Ӷκ�����
//���÷��η�

#include <iostream>

using namespace std;

int max_sum(int *a,int left,int right)
{
    int sum=0;
    int midSum=0,leftSum=0,rightSum=0;
    int center;
    int s1,s2,lefts,rights;

    if(left==right)//����ֻ��һ��Ԫ�ص����
        return a[left];
    else
    {
        center=(left+right)/2;//�����л�Ϊ������������
        leftSum=max_sum(a,left,center);//��߲��ֵ�����ֶκ�
        rightSum=max_sum(a,center+1,right);//�ұ߲��ֵ�����Ӷκ�

        s1=0;//�����������������Ӷκ͵�Ԫ�غ�����м�Ԫ�ص�ʱ��
        lefts=0;
        for(int i=center;i>=left;i--){
            lefts+=a[i];
            if(lefts>s1)
                s1=lefts;//���������������Ӷκ�
        }

        s2=0;
        rights=0;
        for(int j=center+1;j<=right;j++){
            rights+=a[j];
            if(rights>s2)   s2=rights;//�������ҵ������Ӷκ�
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

    cout<<"������һ�����е����ָ�����";
    cin>>n;

    cout << "�������������:";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    cout<<"����Ӷκ͵�ֵΪ:"<<max_sum(a,0,n-1)<<endl;
    return 0;
}


