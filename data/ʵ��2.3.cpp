/*实验2.3：实现双链表的基本运算的算法*/
#include<iostream>
#include<malloc.h>
using namespace std;
typedef char ElemType;
typedef struct DNode
{
    ElemType data;
    struct DNode *pre;
    struct DNode *next;
}DLinkList;
void InitList(DLinkList *&L)
{
    L = (DLinkList *)malloc(sizeof(DLinkList));
    L->pre = NULL;
    L->next= NULL;
}
void DestroyList(DLinkList *&L)
{
    DLinkList *p = L,*q = p->next;
    while(q != NULL)
    {
        free(p);
        p = q;
        q = p->next;
    }
    free(p);
}
int ListEmpty(DLinkList *L)
{
    return (L->next==NULL);
}
int ListLength(DLinkList *L)
{
    DLinkList *p=L;
    int i = 0;
    while(p->next != NULL)
    {
        i++;
        p = p->next;
    }
    return i;
}
void DisplayList(DLinkList *L)
{
    DLinkList *p = L->next;
    while(p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}
int GetElem(DLinkList *L,int i,ElemType &e)   //得到第i个元素
{
    int j = 0;
    DLinkList *p = L;
    while(j<i&&p!=NULL)
    {
        j++;
        p = p->next;
    }
    if(p==NULL)
        return 0;
    else
    {
        e = p->data;
        return 1;
    }
}
int LocateElem(DLinkList *L,ElemType e)        //确定元素e的位置
{
    int n = 1;
    DLinkList *p = L->next;
    while(p!=NULL && p->data != e)
    {
        n++;
        p = p->next;
    }
    if (p==NULL)
        return 0;
    else
        return n;
}
int ListInsert(DLinkList *L,int i,ElemType e)
{
    int j = 0;
    DLinkList *p = L,*s;
    while(j<i-1 && p!=NULL)
    {
        j++;
        p = p->next;
    }
    if(p==NULL)
        return 0;
    else
    {
        s = (DLinkList *) new DLinkList;  //s = (DLinkList *)malloc(sizeof(DLinkList));
        s->data = e;
        s->next = p->next;
        if(p->next != NULL)
        {
            p->next->pre = s;
        }
        p->pre = p;
        p->next = s;
        return 1;
    }
}
int ListDelete(DLinkList *&L,int i,ElemType &e)
{
    int j = 0;
    DLinkList *p=L,*q;
    while(j<i-1 && p!=NULL)
    {
        j++;
        p=p->next;
    }
    if(p==NULL)
        return 0;
    else
    {
        q=p->next;
        if(q==NULL)
            return 0;
        p->next=q->next;
        if(p->next!=NULL)
            p->next->pre=p;
        free(q);
        return 1;
    }
}
int main()
{
    DLinkList *L;
    ElemType e;
    cout << " (1)：初始化双链表L：\n ";
    InitList(L);
    cout << "(2):依次采用插入法插入元素abcde\n";
    ListInsert(L,1,'a');
    ListInsert(L,2,'b');
    ListInsert(L,3,'c');
    ListInsert(L,4,'d');
    ListInsert(L,5,'e');
    cout << " (3)输出双链表L： ";
    DisplayList(L);
    cout << " (4)双链表的长度：";
    cout << ListLength(L) << endl;
    cout << " (5)双链表为:  " << (ListEmpty(L)?"空":"非空");
    GetElem(L,3,e);
    cout << " (6)双链表第3个元素为：" << e << endl;
    cout << " (7)元素a的位置是: " << LocateElem(L,'a') <<endl;
    cout << " (8)在第四个位置上插入元素f";
    ListInsert(L,4,'f');
    cout << " (9)输出双链表L";
    DisplayList(L);
    cout << " (10)删除第三个元素：\n";
    ListDelete(L,3,e);
    cout << " (11)输出双链表L: ";
    DisplayList(L);
    cout << " (12)释放双链表L：";
}


