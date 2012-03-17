/*实验3.6：病人就看病模拟程序*/
#include<iostream>
#include<malloc.h>
using namespace std;
typedef struct qnode
{
    int data;
    struct qnode *next;
} QNode;
typedef struct
{
    QNode *front,*rear;
} QuType;
void SeeDoctor()
{
    int sel,flag=1,find,no;
    QuType *qu;
    QNode *p;
    qu=(QuType *)malloc(sizeof(QuType));
    qu->front=qu->rear=NULL;
    while(flag==1)
    {
        cout <<"1:排队 2：就诊 3：查看排队 4：不再排队，余下依次就诊 5：下班  请选择：  ";
        cin >> sel;
        switch(sel)
        {
        case 1:
            cout<<" << 输入病号\n";
            do
            {
                cin>>no;
                find=0;
                p=qu->front;
                while(p!=NULL&&!find)
                {
                    if(p->data==no)
                        find=1;
                    else
                        p=p->next;
                }
                if(find)
                    cout<<">>输入病号重复，重新输入: ";
            }
            while(find==1);
            p=(QNode *)malloc(sizeof(QNode));
            p->data=no;
            p->next=NULL;
            if(qu->rear==NULL)
            {
                qu->front=qu->rear=p;
            }
            else
            {
                qu->rear->next=p;
                qu->rear=p;
            }
            break;
        case 2:
            if(qu->front==NULL)
                cout << ">>没有要找的病人！\n";
            else
            {
                p=qu->front;
                cout <<"病人"<<p->data<<"就诊\n";
                if(qu->rear==p)
                {
                    qu->front=qu->rear=NULL;
                }
                else
                {
                    qu->front=p->next;
                }
                free(p);
            }
            break;
        case 3:
            if(qu->front==NULL)
                cout<<">>没有排列的病人！\n";
            else
            {
                p=qu->front;
                cout << "排队病人:";
                while(p!=NULL)
                {
                    cout<<p->data<<" ";
                    p=p->next;
                }
                cout <<endl;
            }
            break;
        case 4:
            if(qu->front==NULL)
                cout<<">>没有排队的病人！\n";
            else
            {
                p=qu->front;
                cout << ">>病人按以下顺序就诊：";
                while(p!=NULL)
                {
                    cout<<p->data<<" ";
                    p=p->next;
                }
                cout <<endl;
            }
            flag=0;
            break;
        case 5:
            if(qu->front!=NULL)
                cout<<">>请排队的病人明天就医！\n";
            flag=0;
            break;
        }
    }
}
int main()
{
    SeeDoctor();
}
