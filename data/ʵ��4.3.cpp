/* 实验4.3：顺序串的各种模式匹配 简单匹配和KMP匹配*/
#include<iostream>
#include<malloc.h>
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
int Index(SqString s,SqString t)
{
    int i=0,j=0,k;
    while(i<s.len&&j<t.len)
    {
        if(s.ch[i]==t.ch[j])
        {
            i++;
            j++;
        }
        else
        {
            i=i-j+1;
            j=0;
        }
    }
    if(j>=t.len)
        k=i-t.len;
    else
        k=-1;
    return k;
}
void GetNext(SqString t,int next[])
{
    int j,k;
    j=0;k=-1;next[0]=-1;
    while(j<t.len-1)
    {
        if(k==-1||t.ch[j]==t.ch[k])
        {
            j++;
            k++;
            next[j]=k;
        }
        else
            k=next[k];
    }
}
void GetNextval(SqString t,int nextval[])
{
    int j=0;
    int k=-1;
    nextval[0]=-1;
    while(j<t.len-1)
    {
        if(k==-1||t.ch[j]==t.ch[k])
        {
            j++;
            k++;
            if(t.ch[j]!=t.ch[k])
                nextval[j]=k;
            else
                nextval[j]=nextval[k];
        }
        else
            k=nextval[k];
    }
}
int KMPIndex(SqString s,SqString t)
{
    int next[MAX],i=0,j=0,v;
    GetNext(t,next);
    while(i<s.len&&j<t.len)
    {
        if(j==-1 || s.ch[i]==t.ch[j])
        {
            j++;
            i++;
        }
        else
        {
            j=next[j];
        }

    }
    if(j>=t.len)
        v=i-t.len;
    else
        v=-1;
return v;
}
int KMPIndex1(SqString s,SqString t)
{
    int nextval[MAX],next[MAX],i=0,j=0,v;
    GetNext(t,next);
    GetNextval(t,nextval);
    while(i<s.len&&j<t.len)
    {
        if(j==-1||s.ch[i]==t.ch[j])
        {
            i++;
            j++;
        }
        else
            j=nextval[j];
    }
    if(j>=t.len)
        v=i-t.len;
    else
        v=-1;
return v;
}
int main()
{
    int j;
    int next[MAX],nextval[MAX];
    SqString s,t;
    StrAssign(s,"abcabcdabcdeabcdefabcdefg");
    StrAssign(t,"abcdeabcdefab");
    cout<<"s: ";
    DispStr(s);
    cout<<"t: ";
    DispStr(t);
    cout <<endl;
    cout <<"简单匹配: "<<Index(s,t)<<endl;
    cout<<"KMP 匹配： "<<KMPIndex(s,t)<<endl;
    cout<<"KMP1 匹配： "<<KMPIndex1(s,t);
}
