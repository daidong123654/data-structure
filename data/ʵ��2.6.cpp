/*实验2.6：求集合（有序单链表表示）的并、交和差运算*/
#include<iostream>
#include<malloc.h>
using namespace std;
typedef char ElemType;
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
}LinkList;
void DisplayList(LinkList *L)
{
    LinkList *p = L->next;
    while(p != NULL)
    {
        cout << p->data <<" ";
        p = p->next;
    }
    cout << endl;
}
void CreateListR(LinkList *L,ElemType a[],int n)
{
    LinkList *s,*r;
    int i;
    L=(LinkList *)malloc(sizeof(LinkList));
    L->next=NULL;
    r=L;
    for(i=0;i<n;i++)
    {
        s=(LinkList *)malloc(sizeof(LinkList));
        s->data=a[i];
        r->next=s;
        r=s;
    }
    r->next=NULL;
}
void Sort(LinkList *&head)
{
    LinkList *p=head->next,*q,*r;
    if(p!=NULL)
    {
        r=p->next;
        p->next=NULL;
        p=r;
        while(p!=NULL)
        {
            r=p->next;
            q=head;
            while(q->next!=NULL && q->next->data < p->data)
                q=q->next;
            p->next=q->next;
            q->next=p;
            p=r;
        }
    }
}
void Union(LinkList *ha,LinkList *hb,LinkList *&hc)   //求两个集合的并
{
    LinkList *pa=ha->next,*pb=hb->next,*s,*tc;
    hc=(LinkList *)malloc(sizeof(LinkList));
    tc=hc;
    while(pa!=NULL&&pb!=NULL)
    {
        if(pa->data < pb->data)
        {
            s=(LinkList *)malloc(sizeof(LinkList));
            s->data=pa->data;
            tc->next=s;
            tc=s;
            pa=pa->next;
        }
        else if(pa->data > pb->data)
        {
            s=(LinkList *)malloc(sizeof(LinkList));
            s->data=pb->data;
            tc->next=s;
            tc=s;
            pb=pb->next;
        }
        else
        {
            s=(LinkList *)malloc(sizeof(LinkList));
            s->data=pa->data;
            tc->next=s;
            tc=s;
            pa=pa->next;
            pb=pb->next;
        }
    }
    if(pb!=NULL)
        pa=pb;
    while(pa!=NULL)
    {
        s=(LinkList *)malloc(sizeof(LinkList));
        s->data=pa->data;
        tc->next=s;
        tc=s;
        pa=pa->next;
    }
    tc->next=NULL;
}
void InterList(LinkList *ha,LinkList *hb,LinkList *&hc)
{
    LinkList *pa=ha->next,*pb,*s,*tc;
    hc=(LinkList *)malloc(sizeof(LinkList));
    tc=hc;
    while(pa!=NULL)
    {
        pb=hb->next;
        while(pb!=NULL&&pb->data < pa->data)
            pb=pb->next;
        if(pb!=NULL&&pb->data==pa->data)
        {
            s=(LinkList *)malloc(sizeof(LinkList));
            s->data=pa->data;
            tc->next=s;
            tc=s;
        }
        pa=pa->next;
    }
    tc->next=NULL;
}
void Subs(LinkList *ha,LinkList *hb,LinkList *&hc)
{
    LinkList *pa=ha->next,*pb,*s,*tc;
    hc=(LinkList *)malloc(sizeof(LinkList));
    tc=hc;
    while(pa!=NULL)
    {
        pb=hb->next;
        while(pb!=NULL&&pb->data < pa->data)
            pb=pb->next;
        if(!(pb!=NULL&&pb->data==pa->data))
        {
            s=(LinkList *)malloc(sizeof(LinkList));
            s->data=pa->data;
            tc->next=s;
            tc=s;
        }
        pa=pa->next;
    }
    tc->next=NULL;
}
int main()
{
    LinkList *ha,*hb,*hc;
    ElemType a[]={'c','a','e','h'};
    ElemType b[]={'f','h','b','g','d','a'};
    CreateListR(ha,a,4);
    CreateListR(hb,b,6);
    cout << " 原集合A：\n";
    //DisplayList(ha);
    cout << " 原集合B：";
    //DisplayList(hb);


}












