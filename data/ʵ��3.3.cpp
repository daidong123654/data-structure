#include<iostream>
#include<malloc.h>
#define MAX 10
using namespace std;
typedef char ElemType;
typedef struct
{
    ElemType elem[MAX];
    int front,rear;
}SqQueue;
void InitQueue(SqQueue *&q)
{
    q=(SqQueue *)malloc(sizeof(SqQueue));
    q->front=q->rear=0;
}
void ClearQueue(SqQueue *&q)
{
    free(q);
}
int QueueEmpty(SqQueue *q)
{
    return (q->front==q->rear);
}
int QueueLength(SqQueue *q)
{
    return (q->rear - q->front +MAX) % MAX;
}
int enQueue(SqQueue *&q,ElemType e)
{
    if((q->rear+1)%MAX==q->front)
        return 0;
    q->rear=(q->rear+1)%MAX;
    q->elem[q->rear]=e;
    return 1;
}
int deQueue(SqQueue *q,ElemType &e)
{
    if(q->front==q->rear)
        return 0;
    q->front=(q->front+1)%MAX;
    e=q->elem[q->front];
    return 1;
}
int main()
{
    ElemType e;
    SqQueue *q;

    cout << "(1)初始化队列q：\n";
    InitQueue(q);
    cout <<"(2)队列为： " << (QueueEmpty(q)?"空":"非空") << endl;
    cout << "(3)顺序插入abcde \n";
    enQueue(q,'a');
    enQueue(q,'b');
    enQueue(q,'c');
    cout <<"(4)队列为： " << (QueueEmpty(q)?"空":"非空") << endl;
    if(deQueue(q,e)==0)
        cout << "队列为空，不能出队！\n ";
    else
        cout<<"(5)出队一个元素:   "  << e <<endl;
    cout << "(6)依次入队元素def\n";
    enQueue(q,'d');
    enQueue(q,'e');
    enQueue(q,'f');
    cout << "(7)队列的元素个数是：" << QueueLength(q)<<endl;



}
