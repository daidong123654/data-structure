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
} BTNode;
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
void AllPath(BTNode *b)
{
    struct snode
    {
        BTNode *node;
        int parent;
    } qu[MAX];
    int front,rear,p;
    front=rear=-1;
    rear++;
    qu[rear].node=b;
    qu[rear].parent=-1;
    while(front<rear)
    {
        front++;
        b=qu[front].node;
        if(b->lchild==NULL&&b->rchild==NULL)
        {
            cout<<b->data<<" 到根节点的路径： ";
            p=front;
            while(qu[p].parent!=-1)
            {
                cout<<qu[p].node->data;
                p=qu[p].parent;
            }
            cout<<qu[p].node->data<<endl;
        }
        if(b->lchild!=NULL)
        {
            rear++;
            qu[rear].node=b->lchild;
            qu[rear].parent=front;
        }
        if(b->rchild!=NULL)
        {
            rear++;
            qu[rear].node=b->rchild;
            qu[rear].parent=front;
        }
    }
}
void AllPath1(BTNode *b,ElemType path[],int pathlen)
{
    int i;
    if(b!=NULL)
    {
        if(b->lchild==NULL&&b->rchild==NULL)
        {
            cout<<b->data<<"到根的路径： "<<b->data;
            for(i=pathlen-1;i>=0;i--)
            {
                cout<<path[i];
            }
            cout<<endl;
        }
        else
        {
            path[pathlen]=b->data;
            pathlen++;
            AllPath1(b->lchild,path,pathlen);
            AllPath1(b->rchild,path,pathlen);
            pathlen--;
        }
    }
}
void LongPath(BTNode *b,ElemType path[],int pathlen,ElemType longpath[],int &longpathlen)
{
    int i;
    if(b==NULL)
    {
        if(pathlen>longpathlen)
        {
            for(i=pathlen;i>=0;i--)
                longpath[i]=path[i];
                longpathlen=pathlen;
        }
    }
    else
    {
        path[pathlen]=b->data;
        pathlen++;
        LongPath(b->lchild,path,pathlen,longpath,longpathlen);
        LongPath(b->rchild,path,pathlen,longpath,longpathlen);
        pathlen--;
    }
}
void DispLeaf(BTNode *b)
{
    if(b!=NULL)
    {
        if(b->lchild==NULL&&b->rchild==NULL)
            cout<<b->data;
        else
        {
            DispLeaf(b->lchild);
            DispLeaf(b->rchild);
        }
    }
}
int main()
{
    BTNode *b;
    ElemType path[MAX],longpath[MAX];
    int i,longpathlen=0;
    CreateBTNode(b,"A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))");
    cout<<"1二叉树：";
    Display(b);
    cout<<endl;
    cout<<"1叶节点：";
    DispLeaf(b);
    cout<<endl;
    cout<<"Allpath:\n";
    AllPath(b);
    cout<<endl;
    cout<<"Allpath1:\n";
    AllPath1(b,path,0);
    cout<<endl;
    LongPath(b,path,0,longpath,longpathlen);
    cout<<"第一条最长路径长度："<<longpathlen<<endl;
    cout<<"第一条最长路径：";
    for(i=longpathlen;i>=0;i--)
        cout<<longpath[i];
    cout<<endl;
}
