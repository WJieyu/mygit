#include<iostream>
#include<string.h>
using namespace std;

//使用BF算法
/*
int BF(char S[],char T[]){
    int i=0;//目标串
    int j=0;//模式串
    int index=0;
    while((S[i]!='\0')&&(T[j]!='\0')){
       if(S[i]==T[j]){
            i++;
            j++;
       }else{
            index++;
            i=index;
            j=0;
       }
    }
    if(T[j]=='\0')return index+1;
    else return 0;
}
*/

//方法二：使用KMP算法
void getNext(char T[],int next[]){
    int i,j,len;
    next[0]=-1;
    for(j=1;T[j]!='\0';j++){
        for(len=j-1;len>=1;len--){
            for(i=0;i<len;i++){
                if(T[i]!=T[j-len+i]) break;
            }
            if(i==len){
                next[j]=len;
                break;
            }
        }
    if(len<1) next[j]=0;
    }
}

int KMP(char S[],char T[]){
    int i=0;
    int j=0;
    int next[80];
    getNext(T,next);
    while(S[i]!='\0'&&T[j]!='\0'){
        if(S[i]==T[j]){
            i++;
            j++;
        }else{
            j=next[j];
            if(j==-1){
                i++;
                j++;
            }
        }
    }
    if(T[j]=='\0'){return i-strlen(T)+1;}
    else return 0;
}


int main(){
    char S[100] = {"vcdfhjaba"}; //目标串
    char T[100] = {"aba"}; //模式串
    //int flag = BF(S,T);
    int flag =  KMP(S,T);
    if(flag == 0)
    cout<<"匹配失败！"<<endl;
    else
    cout<<"匹配成功！从目标串的"<<flag<<"处开始匹配"<<endl;
}
