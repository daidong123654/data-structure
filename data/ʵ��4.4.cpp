/*实验4.4：文本串的加密和解密*/
#include<iostream>
#include<malloc.h>
#include<stdio.h>
#define MAX 100
using namespace std;
typedef struct
{
    char ch[MAX];
    int len;
}SqString;
void StrAssign(SqString &str,char cstr[])
{
    int i;
    for(i=0;cstr[i]!='\0';i++)
        str.ch[i]=cstr[i];
    str.len=i;
}
void DispStr(SqString s)
{
    int i;
    if(s.len>0)
    {
        for (i=0;i<s.len;i++)
            cout <<s.ch[i];
        cout << endl;
    }
}
SqString A,B;
SqString EnCrypt(SqString p)   //加密过程
{
    int i=0,j;
    SqString q;
    while(i<p.len)
    {
        for(j=0;p.ch[i]!=A.ch[j];j++)
            if(j>=p.len)
                q.ch[i]=p.ch[i];
            else
                q.ch[i]=B.ch[j];
            i++;
    }
    q.len=p.len;
    return q;
}
SqString UnEnCrypt(SqString q)
{
    int i=0,j;
    SqString p;
    while(i<q.len)
    {
        for(j=0;q.ch[i]!=B.ch[j];j++)
        if(j>=q.len)
            p.ch[i]=q.ch[i];
        else
            p.ch[i]=A.ch[j];
        i++;
    }
    p.len=q.len;
    return p;
}
int main()
{
    SqString p,q;
    int ok =1;
    StrAssign(A,"abcdefghijklmnopqrstuvwxyz");
    StrAssign(B,"ngzqtcobmuhelkpdawxfyivrsj");
    char str[MAX];
    cout<<endl;
    cout<<"输入文字串：";
    gets(str);
    StrAssign(p,str);
    cout<<" 加密后如下：\n";
    cout<<"原文串：";
    DispStr(p);
    q=EnCrypt(p);
    cout<<"加密串：";
    DispStr(q);
    p=UnEnCrypt(q);
    cout<<"解密串：";
    DispStr(p);
    cout<<endl;

}
