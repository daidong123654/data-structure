/*实验2.7：求两个多项式相加运算*/
#include<iostream>
#include<malloc.h>
#define MAX 20
using namespace std;
typedef struct
{
    float coef;
    int exp;
}PolyArray[MAX];
typedef struct pnode
{
    float coef;
    int exp;
    struct pnode *next;
}PolyNode;
void DispPloy(PolyNode *L)
{
    PolyNode *p=L->next;
    while(p!=NULL)
    {
        cout << p->coef << p->exp <<endl;
        p=p->next;
    }
    cout << endl;
}
void CreateListR(PolyNode *&L,PolyArray a,int n)
{
    PolyNode *s,*r;
    int i;
    L=(PolyNode *)malloc(sizeof(PolyNode));
    L->next=NULL;
    r=L;
    for(i=0;i<n;i++)
    {
        s=(PolyNode *)malloc(sizeof(PolyNode));
        s->coef=a[i].coef;
        s->exp=a[i].exp;
        r->next=s;
        r=s;
    }
    r->next=NULL;
}
void Sort(PolyNode *&head)
{
    PolyNode *p=head->next,*q,*r;
    if(p!=NULL)
    {
        r=p->next;
        p->next=NULL;
        p=r;
        while(p!=NULL)
        {
            r=p->next;
            q=head;
            while(q->next!=NULL && q->next->exp < p->exp)
                q=q->next;
            p->next=q->next;
            q->next=p;
            p=r;
        }
    }
}
void Add(PolyNode *ha,PolyNode *hb,PolyNode *&hc)
{
    PolyNode *pa=ha->next,pb=hb->next,*s,*tc;
    float c;
    hc=(PolyNode *)malloc(sizeof(PolyNode));
    while(pa!=NULL)
    {
        if(pa->exp > pb->exp)
        {
            s=(PloyNode *)malloc(sizeof(PolyNode));
            s->exp=pa->exp;
            s->coef=pa->coef;
            tc->next=s;
            tc=s;
            pa=pa->next;
        }
        else if(pa->exp<pb->exp)
        {
            s=(PolyNode *)malloc(sizeof(PolyNode));
            s->exp=pb->exp;
            s->coef=pb->coef;
            tc->next=s;
            tc=s;
            pb=pb->next;
        }
        else
        {
            c=pa->coef+pb->coef;
            if(c!-)
        }
    }
}
int main()
{

}
