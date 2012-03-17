/*实验2.4：实现循环链表的各种运算的基本算法*/#include<iostream>
#include<malloc.h>
using namespace std;
typedef char ElemType;
typedef struct Lnode                //节点类型
{
    ElemType data;
    struct Lnode *next;
}LinkList;
void InitList(LinkList *&L)         //初始化链表
{
    L = (LinkList *)malloc(sizeof(LinkList));
    L->next = L;
}
void DestroyList(LinkList *&L)
{
    LinkList *p = L,*q = p->next;
    while(q != NULL)
    {
        free(p);
        p = q;
        q = q->next;
    }
    free(p);
}
int ListEmpty(LinkList *L)
{
    return (L->next == L);
}
int ListLength(LinkList *L)    //返回链表长度
{
    LinkList *p = L;
    int i = 0;
    while(p->next != L)
    {
        i++;
        p = p->next;
    }
    return i;
}
void DisplayList(LinkList *L)
{
    LinkList *p = L->next;
    while(p != L)
    {
        cout << p->data <<" ";
        p = p->next;
    }
    cout << endl;
}
int GetElem(LinkList *L, int i ,ElemType &e)
{
    int j = 0;
    LinkList *p;
    if(L->next != L)
    {
        if(i==1)
        {
            e = L->next->data;
            return 1;
        }
        else
        {
            p = L->next;
            while(j<i-1&&p!=L)
            {
                j++;
                p = p->next;
            }
            if(p==L)
                return 0;
            else
            {
                e = p->data;
                return 1;
            }
        }
    }
    else
        return 0;
}

int LocateElem(LinkList *L,ElemType e)
{
    LinkList *p = L->next;
    int n =1;
    while(p != L && p->data != e)
    {
        p = p->next;
        n++;
    }
    if(p==L)
        return 0;
    else
        return n;
}
int ListInsert(LinkList *&L,int i,ElemType e)
{
    int j = 0;
    LinkList *p = L,*s;
    if(p->next ==L || i==1)
    {
        s = (LinkList *)malloc(sizeof(LinkList));
        s->data = e;
        s->next = p->next;
        p->next = s;
        return 1;
    }
    else
    {
        p = L->next;
        while(j<i-2 && p !=L)
        {
            j++;
            p = p->next;
        }
        if(p == L)
            return 0;
        else
        {
            s = (LinkList *)malloc(sizeof(LinkList));
            s->data = e;
            s->next = p->next;
            p->next = s;
            return 1;
        }
    }
}
int ListDelete(LinkList *&L,int i,ElemType &e)
{
    int j = 0;
    LinkList *p = L, *q;
    if(L->next != L)
    {
        if(i==1)
        {
            q = L->next;
            L->next = q->next;
            free(q);
            return 1;
        }
        else
        {
            p = L->next;
            while(j<i-2&&p!=L)
            {
                j++;
                p = p->next;
            }
            if(p==L)
                return 0;
            else
            {
                q = p->next;
                p->next = q->next;
                free(q);
                return 1;
            }
        }
    }
    else
        return 0;
}

int main()
{
    LinkList *L;
    ElemType e;
    cout << "(1)初始化链表L： \n";
    InitList(L);
    cout << "(2)插入法建立链表：\n";
    ListInsert(L,1,'a');
    ListInsert(L,2,'b');
    ListInsert(L,3,'c');
    ListInsert(L,4,'d');
    ListInsert(L,5,'e');
    cout << "(3)输出单链表L：";
    DisplayList(L);
    cout << "(4)单链表长度: ";
    cout << ListLength(L) <<endl;
    cout << "(5)单链表L是：" << (ListEmpty(L)?"空":"非空") <<endl;
    GetElem(L,3,e);
    cout << "(6)单链表L的第三个元素是：" <<  e << endl;
    cout << "(7)元素a的位置是：" << LocateElem(L,'a') <<endl;
    cout << "(8)在第四个位置插入元素f";
    ListInsert(L,4,'f');
    cout << "(9)输出链表L：";
    DisplayList(L);
    cout << "(10)删除第三个元素\n";
    ListDelete(L,3,e);
    cout << "(11)输出单链表L：";
    DisplayList(L);
    cout << "(12)释放单链表L：\n";
    DestroyList(L);
return 0;
}
