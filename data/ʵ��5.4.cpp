/*实验5.4:实现稀疏矩阵（采用三元组表示）的基本运算*/
#include<iostream>
#define N 4
#define MAX 100
typedef int ElemType;
using namespace std;
typedef struct
{
    int r;
    int c;
    ElemType d;
} TupNode;
typedef struct
{
    int rows;
    int cols;
    int nums;
    TupNode data[MAX];
} TSMatrix;
void CreatMat(TSMatrix &t,ElemType A[N][N])
{
    int i,j;
    t.rows=N;
    t.cols=N;
    t.nums=0;
    for(i=0; i<N; i++)
    {
        for(j=0; j<N; j++)
            if(A[i][j]!=0)
            {
                t.data[t.nums].r=i;
                t.data[t.nums].c=j;
                t.data[t.nums].d=A[i][j];
                t.nums++;
            }
    }
}
void DispMat(TSMatrix t)
{
    int i;
    if(t.nums<=0)
        return ;
    cout<<"\t"<<t.rows<<"\t"<<t.cols<<"\t"<<t.nums<<endl;
    cout<<"\t-----------------\n";
    for(i=0; i<t.nums; i++)
        cout<<"\t"<<t.data[i].r<<"\t"<<t.data[i].c<<"\t"<<t.data[i].d<<endl;
}
void TranMat(TSMatrix t,TSMatrix &tb)
{
    int p,q=0,v;
    tb.rows=t.cols;
    tb.cols=t.rows;
    tb.nums=t.nums;
    if(t.nums!=0)
    {
        for(v=0; v<t.cols; v++)
            for(p=0; p<t.nums; p++)
                if(t.data[p].c==v)
                {
                    tb.data[q].r=t.data[p].c;
                    tb.data[q].c=t.data[p].r;
                    tb.data[q].d=t.data[p].d;
                    q++;
                }
    }
}
int MatAdd(TSMatrix a,TSMatrix b,TSMatrix &c)
{
    int i=0,j=0,k=0;
    ElemType v;
    if(a.rows!=b.rows || a.cols!=b.cols)
        return 0;
    c.rows=a.rows;
    c.cols=a.cols;
    while(i<a.nums&&j<b.nums)
    {
        if(a.data[i].r==b.data[j].r)
        {
            if(a.data[i].c<b.data[j].c)
            {
                c.data[k].r=a.data[i].r;
                c.data[k].c=a.data[i].c;
                c.data[k].d=a.data[i].d;
                k++;
                i++;
            }
            else if(a.data[i].c>b.data[j].c)
            {
                c.data[k].r=b.data[j].r;
                c.data[k].c=b.data[j].c;
                c.data[k].d=b.data[j].d;
                k++;
                j++;
            }
            else
            {
                v=a.data[i].d+b.data[j].d;
                if(v!=0)
                {
                    c.data[k].r=a.data[i].r;
                    c.data[k].c=a.data[i].c;
                    c.data[k].d=v;
                    k++;
                }
                i++;
                j++;
            }
        }
        else if(a.data[i].r<b.data[j].r)
        {
            c.data[k].r=a.data[i].r;
            c.data[k].c=a.data[i].c;
            c.data[k].d=a.data[i].d;
            k++;i++;
        }
        else
        {
            c.data[k].r=b.data[j].r;
            c.data[k].c=b.data[j].c;
            c.data[k].d=b.data[j].d;
            k++;j++;
        }
        c.nums=k;
    }
    return 1;
}
int value(TSMatrix c,int i,int j)
{
    int k=0;
    while(k<c.nums&&(c.data[k].r!=i||c.data[k].c!=j))
        k++;
    if(k<c.nums)
        return c.data[k].d;
    else
        return 0;
}
int MatMul(TSMatrix a,TSMatrix b,TSMatrix &c)
{
    int i,j,k,p=0;
    ElemType s;
    if(a.cols!=b.rows)
        return 0;
    for(i=0;i<a.rows;i++)
        for(j=0;j<b.cols;j++)
        {
            s=0;
            for(k=0;k<a.cols;k++)
                s=s+value(a,i,k)*value(b,k,j);
            if(s!=0)
            {
                c.data[p].r=i;
                c.data[p].c=j;
                c.data[p].d=s;
                p++;
            }
        }
        c.rows=a.rows;
        c.cols=b.cols;
        c.nums=p;
        return 1;
}
int main()
{
    ElemType a1[N][N]={{1,0,3,0},{0,1,0,0},{0,0,1,0},{0,0,1,1} };
    ElemType b1[N][N]={{3,0,0,0},{0,4,0,0},{0,0,1,0},{0,0,0,2} };
    TSMatrix a,b,c;
    CreatMat(a,a1);
    CreatMat(b,b1);
    cout<<"\na的三元组：\n";
    DispMat(a);
    cout<<"\nb的三元组：\n";
    DispMat(b);
    cout<<"\na的转置为c";
    TranMat(a,c);
    cout<<"\nc的三元组：\n";
    DispMat(c);
    cout<<"\nc=a+b";
    MatAdd(a,b,c);
    cout<<"\nc的三元组：\n";
    DispMat(c);
    cout<<"c=a*b";
    MatMul(a,b,c);
    cout<<"\nc的三元组：\n";
    DispMat(c);
}
