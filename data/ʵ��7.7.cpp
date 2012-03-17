/*实验7.7：表达式求值*/
 #include<iostream>
 #include<malloc.h>
 #include<string.h>
 #include<stdio.h>
 #define MAX
 using namespace std;
 typedef char ElemType;
 typedef struct node
 {
     ElemType data;
     node *lchild;
     node *rchild;
 }BTNode;
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
BTNode *CRTree(char s[],int i,int j)
{
    BTNode *p;
    int k,plus=0,posi;
    if(i==j)
    {
        p=(BTNode *) malloc (sizeof(BTNode));
        p->data=s[i];
        p->lchild=NULL;
        p->rchild=NULL;
        return p;
    }
    for(k=i;k<=j;k++)
    if(s[k]=='+'||s[k]=='-')
    {
        plus++;
        posi=k;
    }
    if(plus==0)
        for(k=i;k<=j;k++)
            if(s[k]=='*'||s[k]=='/')
            {
                plus++;
                posi=k;
            }
    p=(BTNode *) malloc (sizeof(BTNode));
    p->data=s[posi];
    p->lchild=CRTree(s,i,posi-1);
    p->rchild=CRTree(s,posi+1,j);
    return p;
}
int main()
{
    BTNode *b;
    char s[MAX]="a+b*c-e/f";
    cout<<endl;
    printf("代数表达式：%s\n",s);
    b=CRTree(s,0,strlen(s)-1);
    cout<<"对应二叉树：\n";
    Display(b);
    cout<<endl;

}





















