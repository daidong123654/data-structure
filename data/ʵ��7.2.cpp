/*实验7.2：实现二叉树各种遍历算法*/
#include<iostream>
#include<malloc.h>
#define MAX 100
using namespace std;
typedef char ElemType;
typedef struct node
{
    ElemType data;
    node *lchild;
    node *rchild;
}BTNode;
void CreateBTNode(BTNode *&b,char *str)
{
    BTNode *st[MAX],*p=NULL;
    int top=-1,k,j=0;
    char ch;
    b=NULL;
    ch=str[j];
    while(ch != '\0')
    {
        switch(ch)
        {
        case '(':
            top++;
            st[top]=p;
            k=1;    //左孩子节点
            break;
        case ')':
            top--;        //括号匹配，退栈
            break;
        case ',':
            k=2;              //右孩子节点
            break;
        default:
            p = (BTNode *) malloc (sizeof(BTNode));
            p->data = ch;
            p->lchild = p->rchild = NULL;
            if(b == NULL)
                b = p;
            else
            {
                switch(k)
                {
                case 1:
                    st[top]->lchild = p;
                    break;
                case 2:
                    st[top]->rchild = p;
                    break;
                }
            }
        }
        j++;
        ch=str[j];
    }
}
int Display(BTNode *b)
{
    if(b!=NULL)
    {
        cout<<b->data;
        if(b->lchild!=NULL || b->rchild!= NULL)
        {
            cout<<"(";
            Display(b->lchild);
            if(b->rchild!=NULL)
                cout<<",";
            Display(b->rchild);
            cout<<")";
        }
    }
}
void PreOrder(BTNode *b)
{
    if(b!=NULL)
    {
        cout<<b->data;
        PreOrder(b->lchild);
        PreOrder(b->rchild);
    }
}
void PreOrder1(BTNode *b)
{
    BTNode *p;
    struct
    {
        BTNode *pt;
        int tag;
    }st[MAX];
    int top=-1;
    top++;
    st[top].pt=b;
    st[top].tag=1;
    while(top>-1)
    {
        if(st[top].tag==1)
        {
            p=st[top].pt;
            top--;
            if(p!=NULL)
            {
                top++;
                st[top].pt=p->rchild;
                st[top].tag=1;
                top++;
                st[top].pt=p->lchild;
                st[top].tag=1;
                top++;
                st[top].pt=p;
                st[top].tag=0;
            }
        }
        if(st[top].tag==0)
        {
            cout<<st[top].pt->data;
            top--;
        }
    }
}
void PreOrder2(BTNode *b)
{
    BTNode *st[MAX],*p;
    int top=-1;
    if(b!=NULL)
    {
        top++;
        st[top]=b;
        while(top>-1)
        {
            p=st[top];
            top--;
            cout<<p->data;
            if(p->rchild!=NULL)
            {
                top++;
                st[top]=p->rchild;
            }
            if(p->lchild!=NULL)
            {
                top++;
                st[top]=p->lchild;
            }
        }
        cout<<endl;
    }
}
void InOrder(BTNode *b)
{
    if(b!=NULL)
    {
        InOrder(b->lchild);
        cout<<b->data;
        InOrder(b->rchild);
    }
}
void InOrder1(BTNode *b)
{
    BTNode *p;
    struct
    {
        BTNode *pt;
        int tag;
    }st[MAX];
    int top=-1;
    top++;
    st[top].pt=b;
    st[top].tag=1;
    while(top>-1)
    {
        if(st[top].tag==1)
        {
            p=st[top].pt;
            top--;
            if(p!=NULL)
            {
                top++;
                st[top].pt=p->rchild;
                st[top].tag=1;
                top++;
                st[top].pt=p;
                st[top].tag=0;
                top++;
                st[top].pt=p->lchild;
                st[top].tag=1;
            }
        }
        if(st[top].tag==0)
        {
            cout<<st[top].pt->data;
            top--;
        }
    }
}
void InOrder2(BTNode *b)
{
    BTNode *st[MAX],*p;
    int top=-1;
    if(b!=NULL)
    {
        p=b;
        while(top>-1||p!=NULL)
        {
            while(p!=NULL)
            {
                top++;
                st[top]=p;
                p=p->lchild;
            }
            if(top>-1)
            {
                p=st[top];
                top--;
                cout<<p->data;
                p=p->rchild;
            }
        }
        cout<<endl;
    }
}
void PostOrder(BTNode *b)
{
    if(b!=NULL)
    {
        PostOrder(b->lchild);
        PostOrder(b->rchild);
        cout<<b->data;
    }
}
void PostOrder1(BTNode *b)
{
    BTNode *p;
    struct
    {
        BTNode *pt;
        int tag;
    }st[MAX];
    int top=-1;
    top++;
    st[top].pt=b;
    st[top].tag=1;
    while(top>-1)
    {
        if(st[top].tag==1)
        {
            p=st[top].pt;
            top--;
            if(p!=NULL)
            {
                top++;
                st[top].pt=p;
                st[top].tag=0;
                top++;
                st[top].pt=p->rchild;
                st[top].tag=1;
                top++;
                st[top].pt=p->lchild;
                st[top].tag=1;
            }
        }
        if(st[top].tag==0)
        {
            cout<<st[top].pt->data;
            top--;
        }
    }
}
void PostOrder2(BTNode *b)
{
    BTNode *st[MAX],*p;
    int flag,top=-1;
    if(b!=NULL)
    {
        do
        {
            while(b!=NULL)
            {
                top++;
                st[top]=b;
                b=b->lchild;
            }
            p=NULL;
            flag =1;
            while(top!=-1&&flag)
            {
                b=st[top];
                if(b->rchild==p)
                {
                    cout<<b->data;
                    top--;
                    p=b;
                }
                else
                {
                    b=b->rchild;
                    flag=0;
                }
            }
        } while(top!=-1);
        cout<<endl;
    }
}
void Leavel(BTNode *b)
{
    BTNode *qu[MAX];
    int front,rear;
    front=rear=0;
    if(b!=NULL)
    {
        cout<<b->data;
    }
    rear++;
    qu[rear]=b;
    while(rear!=front)
    {
        front=(front+1)%MAX;
        b=qu[front];
        if(b->lchild!=NULL)
        {
            cout<<b->lchild->data;
            rear=(rear+1)%MAX;
            qu[rear]=b->lchild;
        }
        if(b->rchild!=NULL)
        {
            cout<<b->rchild->data;
            rear=(rear+1)%MAX;
            qu[rear]=b->rchild;
        }
    }
    cout<<endl;
}
int main()
{
    BTNode *b;
    CreateBTNode(b,"A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))");
    cout<<"1二叉树：";
    Display(b);
    cout<<endl;
    cout<<"2层序：  ";
    Leavel(b);
    cout<<"3先序：\n";
    cout<<"先序：  ";
    PreOrder(b);
    cout<<endl;
    cout<<"先序1： ";
    PreOrder1(b);
    cout<<endl;
    cout<<"先序2： ";
    PreOrder2(b);
    cout<<endl;
    cout<<"4中序：  \n";
    cout<<"中序：   ";
    InOrder(b);
    cout<<endl;
    cout<<"中序1：  ";
    InOrder1(b);
    cout<<endl;
     cout<<"中序2：  ";
    InOrder2(b);
    cout<<endl;
    cout<<"5后序： \n";
    cout<<"后序： \t";
    PostOrder(b);
    cout<<endl;
    cout<<"后序1:\t";
    PostOrder1(b);
    cout<<endl;
    cout<<"后序2:\t";
    PostOrder2(b);
    cout<<endl;




}
















