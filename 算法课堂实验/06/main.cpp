#include<iostream>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
using namespace std;

//定义结点
typedef struct {
    unsigned int parent;
    unsigned int lchild;
    unsigned int rchild;
    unsigned int weight;
} Node,*HuffmanTree;
//定义数组
//(代替一颗哈夫曼树：前n个结点表示所有叶子结点，(2n-1)-n个结点表示其他结点)

//以下数组代表哈夫曼编码，数组的每个元素是一个char字符类型
typedef char *HuffmanCode;

//从现有结点(包括所有不存在父结点的结点)中选取两个权重最小的两个结点进行返回
void select(HuffmanTree *huffmanTree,int n,int *s1,int *s2)//定义了一个指向一颗哈夫曼树的指针，n表示叶子结点的个数，
                                                            //s1和s2分别指向当前weight最小的两个叶子节点
{
    cout<<"-------------------------"<<endl;
    cout<<"now it's turn to select"<<endl;
    int min_;//min_用来存储当前找到权值最小的结点的位置

    //找当前所有没有双亲的结点中的第一个作为后续衡量标准
    for(int i=1;i<=n;i++){
        if((*huffmanTree)[i].parent==0){
            min_=i;
            break;
        }
    }
    //遍历所有没有双亲的结点，找到权值最小的结点的下标
    for(int i=1;i<=n;i++){
        if((*huffmanTree)[i].parent==0){
            if((*huffmanTree)[i].weight<(*huffmanTree)[min_].weight){
                min_=i;
            }
        }
    }
    *s1 = min_;

    //找当前所有没有双亲的结点中的第一个作为后续衡量标准
    for(int i=1;i<=n;i++){
        if(((*huffmanTree)[i].parent==0)&&(i!=*s1)){
            min_=i;
            break;
        }
    }
    //遍历所有没有双亲的结点，找到权值最小的结点的下标
    for(int i=1;i<=n;i++){
        if(((*huffmanTree)[i].parent==0)&&(i!=*s1)){
            if((*huffmanTree)[i].weight<(*huffmanTree)[min_].weight){
                min_=i;
            }
        }
    }
    *s2 = min_;
    cout<<"select over!"<<endl;
    cout<<"-----------------------"<<endl;
}

//构造哈夫曼树
void createHuffmanTree(HuffmanTree *huffmanTree ,int w[],int n)
{
    if(n<=1) return;
    cout<<"-------------------create HuffmanTree Start---------------"<<endl;
    int m=2*n-1;//m是哈夫曼树的总结点数
    int s1;
    int s2;//s1和s2是哈夫曼树中权值最小的两个节点的数组位置下标
    *huffmanTree=(HuffmanTree)malloc((m+1)*sizeof(Node));//第一个存储头结点

    //对于原始的叶子结点
    for(int i=1;i<=n;i++){
        (*huffmanTree)[i].lchild=0;
        (*huffmanTree)[i].rchild=0;
        (*huffmanTree)[i].parent=0;
        (*huffmanTree)[i].weight=w[i];
    }
    //cout<<(*huffmanTree)[1].weight<<endl;

    //对于树中的中间结点（置于数组后端）
    for(int i=n+1;i<=m;i++){
        (*huffmanTree)[i].lchild=0;
        (*huffmanTree)[i].rchild=0;
        (*huffmanTree)[i].parent=0;
        (*huffmanTree)[i].weight=0;
    }

    cout<<endl;
    cout<<" huffmanTree create begin:"<<endl;


    cout<<"output the mid node connection:"<<endl;
    //从非叶子结点出发，补充后续结点
    for(int i=n+1;i<=m;i++){
        select(huffmanTree,i-1,&s1,&s2);
        (*huffmanTree)[s1].parent=i;
        (*huffmanTree)[s2].parent=i;
        (*huffmanTree)[i].lchild=s1;
        (*huffmanTree)[i].rchild=s2;
        (*huffmanTree)[i].weight=(*huffmanTree)[s1].weight+(*huffmanTree)[s2].weight;

        cout<<(*huffmanTree)[s1].weight<<" "<<(*huffmanTree)[s2].weight<<" "<<(*huffmanTree)[i].weight<<endl;
    }

    cout<<endl;
    cout<<"the tree is:"<<endl;
    for(int i=1;i<=m;i++){
        cout<<"Node:"<<i<<":"<<(*huffmanTree)[i].weight<<" "<<(*huffmanTree)[i].parent<<" "<<(*huffmanTree)[i].lchild<<" "<<(*huffmanTree)[i].rchild<<endl;
    }
    //哈夫曼树构造完成！！！
}

//根据哈夫曼树来构造哈夫曼编码
void createHuffmanCode(HuffmanTree *huffmanTree,HuffmanCode *huffmanCode,int n)
{
    cout<<"-------------------create HuffmanCode Start---------------"<<endl;
    int start;
    int c;
    int p;

    huffmanCode=(HuffmanCode *)malloc((n+1) * sizeof(char *));//huffmanCode指向最终需要的大数组
    char *cd = (char *)malloc((n+1) * sizeof(char));//cd指向每个数字的编码小数组

    cd[n]='\0';//注意n个结点的话最长的也只有n-1个编码，这里我将最后的n作为结束标志
    //cout<<"n="<<n<<endl;
    //cout<<"c[n-1]="<<cd[n-1]<<endl;
    for(int i=1;i<=n;i++){//i代表所遍历结点的位置（注意遍历的全是叶子结点）

        start=n-1;//从结点位置倒数第二个开始取值进去
        for(int k=0;k<n;k++) cd[k]=' ';

        cout<<"start="<<start<<endl;
        for(c=i,p=(*huffmanTree)[i].parent;p!=0;c=p,p=(*huffmanTree)[p].parent){
            if((*huffmanTree)[p].lchild == c)
                cd[start--]='0';
            else
                cd[start--]='1';
        }

        huffmanCode[i]=(char *)malloc((n-start-1)*sizeof(char));
        cout<<"the code has "<<n-start-1<<" numbers"<<endl;
        //strcpy(huffmanCode[i],&cd[start]);
        for(int j=start-1;j<=n;j++) cout<<cd[j]<<endl;
        //cout<<cd<<endl;
        strcpy(huffmanCode[i],&cd[start]);
    }
    free(cd);

    for(int i=1;i<=n;i++)
    {
        cout<<"weight is "<<(*huffmanTree)[i].weight<<",it's code is "<<huffmanCode[i]<<endl;
    }

}



int main()
{
    HuffmanCode HC;
    HuffmanTree HT;
    int *w;

    int n;
    cout<<"input the amount:";
    cin>>n;

    w=(int *)malloc((n+1)*sizeof(int));
    cout<<"input their weight:"<<endl;
    for(int i=1;i<=n;i++){
        cout<<"No "<<i<<":";
        cin>>w[i];
    }
    createHuffmanTree(&HT,w,n);
    createHuffmanCode(&HT,&HC,n);
    return 0;
}
