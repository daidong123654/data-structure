#include<iostream>
#include<string.h>
#include<stdio.h>
#define N 50
#define M 2*N-1
using namespace std;
typedef struct
{
    char data[5];
    int weight;
    int parent;
    int lchild;
    int rchild;
}Hnode;      //要转换的字符
typedef struct
{
    char cd[N];
    int start;
}Hcode;         //转换后的哈夫曼编码

void CreateHT(Hnode ht[],int n)
{
    int i,k,lnode,rnode;
    int min1,min2;
    for (int i=0;i<2*n-1;i++)     //初始化
        ht[i].parent = ht[i].rchild=ht[i].lchild = -1;
    for(int i=n;i<2*n-1;i++)        //构造哈夫曼树
    {
        min1=min2=32767;                //两个分别为最小的数
        lnode=rnode=-1;
        for(k=0;k<=i-1;k++)
            if(ht[k].parent==-1)        //在尚未构造二叉树的点中查找最小的两个
            {
                if(ht[k].weight<min1)
                {
                    min2=min1;
                    rnode=lnode;
                    min1=ht[k].weight;
                    lnode=k;
                }
                else if(ht[k].weight<min2)
                {
                    min2=ht[k].weight;
                    rnode=k;
                }
            }
            ht[lnode].parent=i;
            ht[rnode].parent=i;
            ht[i].weight=ht[lnode].weight+ht[rnode].weight;
            ht[i].lchild=lnode;
            ht[i].rchild=rnode;
    }
}

void CreateHuffmanCode(Hnode ht[],Hcode hcd[],int n)  //构造哈夫曼编码
{
    int i,f,c;
    Hcode hc;
    for(i=0;i<n;i++)
    {
        hc.start=n;
        c=i;
        f=ht[i].parent;
        while(f!=-1)                    //循环直到根节点
        {
            if(ht[f].lchild==c)          //左孩子节点
                hc.cd[hc.start--]='0';
            else
                hc.cd[hc.start--]='1';  //右孩子节点
            c=f;
            f=ht[f].parent;
        }
        hc.start++; //指向哈夫曼编码的最开始字符
        hcd[i]=hc;
    }
}

void Display(Hnode ht[],Hcode hcd[],int n)//输出哈夫曼编码
{
    int i,j,k;
    int sum=0;
    int m=0;
    cout<<"Huffman code \n";      //输出哈夫曼编码
    for(i=0;i<n;i++)
    {
        j=0;
        printf("\t %s: \t\t",ht[i].data);
        for(k=hcd[i].start;k<=n;k++)
        {
            printf("%c",hcd[i].cd[k]);
            j++;
        }
    m += ht[i].weight;
    sum += ht[i].weight*j;
    cout <<endl;
    }
    cout <<"\n" <<"Average length = " <<1.0*sum/m;
}

int main()
{
    int n = 15,i;
    cout<<"Hello World!\n";
    char *str[]={"The","of","a","to","and","in","that","he","is",
                "at","on","for","His","are","be"};
    int fum[]={1192,677,541,518,462,450,242,195,190,181,174,157,138,124,123};
    Hnode ht[M];
    Hcode hcd[N];
    for(i=0;i<n;i++)
    {
        strcpy(ht[i].data,str[i]);
        ht[i].weight=fum[i];
    }
    cout <<endl;
    CreateHT(ht,n);
    CreateHuffmanCode(ht,hcd,n);
    Display(ht,hcd,n);
    cout <<endl;
}
