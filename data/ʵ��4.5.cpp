/*实验4.5：求一个串中第一个最长重复串*/
#include<iostream>
#include<malloc.h>
#include<string>
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
SqString *MaxSubstr(SqString s)
{
    SqString *sp;
    int index =0,length=0,length1,i=0,j,k;
    while(i<s.len)
    {
        j=i+1;
        while(j<s.len)
        {
            if(s.ch[i]==s.ch[j])
            {
                length1=1;
                for(k=1;s.ch[i+k]==s.ch[j+k];k++)
                    length1++;
                if(length1>length)
                {
                    index=i;
                    length=length1;
                }
                j+=length1;
            }
            else
                j++;
        }
        i++;
    }
    sp=(SqString *)malloc(sizeof(SqString));
    sp->len=length;
    for(i=0;i<length;i++)
        sp->ch[i]=s.ch[index+i];
    return sp;
}
int main()
{
    char str[MAX];
    SqString s,*sp;
    cout<<"输入串:";
    gets(str);
    StrAssign(s,str);
    sp=MaxSubstr(s);
    cout<<"求最长重复字符串\n";
    cout<<"原串：";
    DispStr(s);
    cout<<"最长重复字符串：";
    DispStr(*sp);
}
