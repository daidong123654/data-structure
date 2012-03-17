/*实验7.5： 实现中序线索化二叉树*/
#include<iostream>
#include<malloc.h>
#define MAX 100
using namespace std;
typedef char ElemType;
typedef struct node
{
    ElemType data;
    int ltag,rtag;
    node *lchild;
    node *rchild;
}TBTNode;
void CreateTBTnode(TBTNode *&b,char *str)
{
    TBTNode *st[MAX],*p=NULL;
    int top=-1,k,j=0;
    char ch;
    b=NULL;
    ch=str[j];
    while(ch!='\0')
    {
        switch(ch)
        {
            case '(':top++;st[top]=p;k=1;break;
            case ')':top--;break;
            case ',':k=2;break;
            default:p=(TBTNode *)malloc(sizeof(TBTNode));
            p->data=ch;p->lchild=p->rchild=NULL;
            if(b==NULL)
                b=p;
            else
            {
                switch(k)
                {
                    case 1:st[top]->lchild=p;break;
                    case 2:st[top]->rchild=p;break;
                }
            }
        }
        j++;
        ch=str[j];
    }
}
void DispTBTNode(TBTNode *b)
{
    if(b!=NULL)
    {
        cout<<b->data;
        if(b->lchild!=NULL||b->rchild!=NULL)
        {
            cout<<"(";
            DispTBTNode(b->lchild);
            if(b->rchild!=NULL)
                cout<<",";
            DispTBTNode(b->rchild);
            cout<<")";
        }
    }
}
TBTNode *pre;
void Thread(TBTNode *&p)
{
    if(p!=NULL)
    {
        Thread(p->lchild);
        if(p->rchild==NULL)
        {
            p->lchild=pre;
            p->ltag=1;
        }
        else
            p->ltag=0;
        if(pre->rchild==NULL)
        {
            pre->rchild=p;
            pre->rtag=1;
        }
        else pre->rtag=0;
        pre=p;
        Thread(p->rchild);
    }
}
TBTNode *CreaThread(TBTNode *b)
{
    TBTNode *root;
    root =(TBTNode *)malloc(sizeof(TBTNode));
    root->ltag=0;root->rtag=1;
    root->rchild=b;
    if(b==NULL)
        root->lchild=root;
    else
    {
        root->lchild=b;
        pre=root;
        Thread(b);
        pre->rchild=root;
        pre->rtag=1;
        root->rchild=pre;
    }
    return root;
}
void ThInOrder(TBTNode *tb)
{
    TBTNode *p=tb->lchild;
    while(p!=tb)
    {
        while(p->ltag==0)
            p=p->lchild;
        cout<<p->data;
        while(p->rtag==1&&p->rchild!=tb)
        {
            p=p->rchild;
            cout<<p->data;
        }
        p=p->rchild;
    }
}
int main()
{
    TBTNode *b,*tb;
    CreateTBTnode(b,"A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))");
    cout<<"二叉树：";
    DispTBTNode(b);
    cout<<endl;
    tb=CreaThread(b);
    cout<<"线索化中序序列：";
    ThInOrder(tb);
    cout<<endl;
}
