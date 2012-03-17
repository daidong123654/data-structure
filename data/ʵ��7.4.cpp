/*实验7.3：遍历序列构造二叉树*/
#include<iostream>
#include<malloc.h>
#include<stdio.h>
#define MAX 100
#define Width 40
using namespace std;
typedef char ElemType;
typedef struct node
{
    ElemType data;
    node *lchild;
    node *rchild;
}BTNode;
BTNode *CreateBT1(char *pre,char *in,int n)
{
    BTNode *s;
    char *p;
    int k;
    if(n<=0)
    {
        return NULL;
    }
    s=(BTNode *)malloc(sizeof(BTNode));
    s->data=*pre;
    for(p=in;p<in+n;p++)
        if(*p==*pre)
            break;
    k=p-in;
    s->lchild=CreateBT1(pre+1,in,k);
    s->lchild=CreateBT1(pre+k,p+1,n-k-1);
    return s;
}
BTNode *CreateBT2(char *post,char *in,int n,int m)
{
    BTNode *s;
    char *p,*q,*maxp;
    int maxpost,maxin,k;
    if(n<=0)
        return NULL;
    maxpost=-1;
    for(p=in;p<in+n;p++)
        for(q=post;q<post+m;p++)
            if(*p==*q)
            {
                k=q-post;
                if(k>maxpost)
                {
                    maxpost=k;
                    maxp=p;
                    maxin=p-in;
                }
            }
    s=(BTNode *)malloc(sizeof(BTNode));
    s->data=post[maxpost];
    s->lchild=CreateBT2(post,in,maxin,m);
    s->rchild=CreateBT2(post,maxp+1,n-maxin-1,m);
    return s;
}
void DispBTNode(BTNode *b)
{
    if(b!=NULL)
    {
        cout<<b->data;
        if(b->lchild!=NULL||b->rchild!=NULL)
        {
            cout<<"(";
            DispBTNode(b->lchild);
            if(b->rchild!=NULL)
                cout<<",";
            DispBTNode(b->rchild);
            cout<<")";
        }
    }
}
void DispBTNode1(BTNode *b)
{
    BTNode *st[MAX],*p;
    int level[MAX][2],top=-1,n,i,width;
    char type;
    if(b!=NULL)
    {
        top++;
        st[top]=b;
        level[top][0]=width;
        level[top][1]=2;
        while(top>-1)
        {
            p=st[top];
            n=level[top][0];
            switch(level[top][1])
            {
                case 0:type='L';break;
                case 1:type='R';break;
                case 2:type='B';break;
            }
            for(i=1;i<=n;i++)
            {
                cout<<" ";
            }
            cout<<p->data<<"("<<type;
            for(i=n+1;i<=width;i+=2)
            cout<<"--";
            cout<<endl;
            top--;
            if(p->rchild!=NULL)
            {
                top++;
                st[top]=p->rchild;
                level[top][0]=n+width;
                level[top][1]=1;
            }
            if(p->lchild!=NULL)
            {
                top++;
                st[top]=p->lchild;
                level[top][0]=n+width;
                level[top][1]=0;
            }
        }
    }
}
int main()
{
    BTNode *b;
    ElemType pre[]="ABDEHJKLMNCFGI";
    ElemType in[]="DBJHLKMNEAGCGI";
    ElemType post[]="DJLNMKHEBFIGCA";
    b=CreateBT1(pre,in,14);
    printf("先序:%s\n");
    printf("中序:%s\n");
    printf("构造二叉树\n");
    cout<<"\n括号表示：";
    DispBTNode(b);
    cout<<"\n凹入法表示：\n";
    DispBTNode1(b);
    b=CreateBT2(post,in,14,14);
    printf("构造二叉树\n");
    cout<<"\n括号表示：";
    DispBTNode(b);
    cout<<"\n凹入法表示：\n";
    DispBTNode1(b);





}



