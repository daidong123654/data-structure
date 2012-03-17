/*实验3.1：实现顺序栈的各种基本运算的算法*/
#include<iostream>
#include<malloc.h>
#define MAX 100
using namespace std;
typedef char ElemType;
typedef struct
{
    ElemType elem[MAX];
    int top;
}SqStack;
void InitStack(SqStack *&s)
{
    s=(SqStack *)malloc(sizeof(SqStack));
    s->top=-1;
}
void ClearStack(SqStack *&s)
{
    free(s);
}
int StackLength(SqStack *s)
{
    return (s->top + 1);
}
int StackEmpty(SqStack *s)
{
    return (s->top== -1);
}
int Push(SqStack *&s,ElemType e)
{
    if(s->top==MAX-1)
        return 0;
    s->top++;
    s->elem[s->top]=e;
    return 1;
}
int Pop(SqStack *&s,ElemType &e)
{
    if(s->top==-1)
        return 0;
    e=s->elem[s->top];
    s->top--;
    return 1;
}
int GetTop(SqStack *s,ElemType &e)
{
    if(s->top==MAX-1)
        return 0;
    e=s->elem[s->top];
    return 1;
}
void DispStack(SqStack *s)
{
    int i;
    for(i=s->top;i>=0;i--)
        cout << s->elem[i] << " ";
    cout << endl;
}
int main()
{
    ElemType e;
    SqStack *s;
    cout << "(1)初始化栈s：\n";
    InitStack(s);
    cout <<"(2)栈为" << (StackEmpty(s)?"空":"非空") << endl;
    cout << "(3)顺序插入abcde \n";
    Push(s,'a');
    Push(s,'b');
    Push(s,'c');
    Push(s,'d');
    Push(s,'e');
    cout <<"(4)栈为:  " << (StackEmpty(s)?"空":"非空") << endl;
    cout << "(5)栈长度为: ";
    cout << StackLength(s) <<endl;
    cout << "(6)从栈顶栈底元素依次为： ";
    DispStack(s);
    cout << "(7)出栈序列:";
    while(!StackEmpty(s))
    {
        Pop(s,e);
        cout << e <<" ";
    }
    cout << endl;
    cout << "(8)栈为：" << (StackEmpty(s)?"空":"非空") << endl;
    cout <<"(9)释放栈\n";
    ClearStack(s);
}
/*This is the end of code!
2010/2/7/18:07*/
