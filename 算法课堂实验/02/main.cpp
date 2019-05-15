#include<iostream>
#include<string.h>
using namespace std;

//ʹ��BF�㷨
/*
int BF(char S[],char T[]){
    int i=0;//Ŀ�괮
    int j=0;//ģʽ��
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

//��������ʹ��KMP�㷨
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
    char S[100] = {"vcdfhjaba"}; //Ŀ�괮
    char T[100] = {"aba"}; //ģʽ��
    //int flag = BF(S,T);
    int flag =  KMP(S,T);
    if(flag == 0)
    cout<<"ƥ��ʧ�ܣ�"<<endl;
    else
    cout<<"ƥ��ɹ�����Ŀ�괮��"<<flag<<"����ʼƥ��"<<endl;
}
