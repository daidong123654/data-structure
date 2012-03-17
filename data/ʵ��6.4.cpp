/*实验6.4：采用递归和非递归方法求解F（n）*/
#include<iostream>
#include<stdio.h>
#define MAX 100
using namespace std;
int fun1(int n)
{
    int f;
    if(n==0)
        return 1;
    else
    {
        f=fun1(n/2);
        return (n*f);
    }
}
int fun2(int n)
{
    int i=1,f=1;
    while(n>0)
    {
        f=n*f;
        n=n/2;
    }
    return f;
}
int fun3(int n)
{
    struct
    {
        int vn;
        int vf;
        int tag;
    }St[MAX];
    int top=-1;
    top++;
    St[top].vn=n;
    St[top].tag=1;
    while(top>-1)
    {
        if(St[top].tag==1)
        {
            if(St[top].vn==0)
            {
                St[top].vf=1;
                St[top].tag=0;
            }
            else
            {
                top++;
                St[top].vn=St[top-1].vn/2;
                St[top].tag=1;
            }
        }
        else if(St[top].tag==0)
        {
            if(St[top-1].vn>0)
            {
                St[top-1].vf=St[top-1].vn*St[top].vf;
                St[top-1].tag=0;
                top--;
            }
        }
        if(top==0&&St[top].tag==0)
            break;
    }
    return St[top].vf;
}
int main()
{
    int n=12;
    cout<<"各种方法求解结果如下：\n";
    printf("\t\t\t fun1(%d) = %d\n",n,fun1(n));
    printf("\t\t\t fun2(%d) = %d\n",n,fun2(n));
    printf("\t\t\t fun3(%d) = %d\n",n,fun3(n));

}
