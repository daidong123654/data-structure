/*    第二章
    实验2.1 : 实现顺序表的基本运算的算法。
    数组实现顺序表*/
#include<iostream>
#include<malloc.h>
#define MAX 100
using namespace std;
typedef char ElemType;
typedef struct Sqlist             //顺序表定义
{
    ElemType elem [MAX];
    int length;
};
void InitList(Sqlist *&L)           //顺序表初始化
{
    L = (Sqlist *)malloc( sizeof(Sqlist) );
    L->length =0;
}
void DeleteList(Sqlist *&L)    //删除节点
{
    free(L);
}
int ListEmpty(Sqlist *&L)      //判断队空
{
   return (L->length==0);
}
int ListLength(Sqlist *&L)     //返回链表长度
{
    return (L->length);
}
void DisplayList(Sqlist *&L)
{
    int i;
    if(ListEmpty(L))
        return ;
    for(i=0;i<L->length;i++)
    {
        cout << L->elem[i] <<" ";
    }
    cout << endl;
}
int GetElem (Sqlist *L,int i,ElemType &e)          //得到第i个元素
{
    if(i<1 || i>L->length)
        return 0;
    e = L->elem[i-1];
    return 1;
}
int LocateElem(Sqlist *L,ElemType e)
{
    int i = 0;
    while(i<L->length && L->elem[i] != e)   i++;
    if(i >= L->length)
        return 0;
    else
        return i+1;
}
int ListInsert(Sqlist *&L,int i,ElemType e)
{
    int j;
    if(i<1 || i>L->length+1)
        return 0;
    i--;
    for(j=L->length;j>i;j--)
        L->elem[j]=L->elem[j-1];
    L->elem[i] = e;
    L->length++;
    return 1;
}
int ListDelete(Sqlist *&L, int  i,ElemType &e)
{
    int j;
    if(i<1 || i>L->length)
        return 0;
    i--;
    e = L->elem[i];
    for (j=i; j<L->length-1;j++)
        L->elem[j] = L->elem[j+1];
    L->length--;
    return 1;
}
int main()
{
    Sqlist *L;
    ElemType e;
    InitList(L);

    ListInsert(L,1,'a'); DisplayList(L);
    ListInsert(L,2,'b'); DisplayList(L);
    ListInsert(L,3,'c'); DisplayList(L);
    ListInsert(L,4,'d'); DisplayList(L);
    ListInsert(L,5,'e'); DisplayList(L);
    ListInsert(L,6,'f'); DisplayList(L);
    ListInsert(L,1,'a'); DisplayList(L);
    ListInsert(L,2,'b'); DisplayList(L);
    ListInsert(L,3,'c'); DisplayList(L);
    ListInsert(L,4,'d'); DisplayList(L);
    ListInsert(L,5,'e'); DisplayList(L);
    DisplayList(L);
    cout << "顺序表长度："  << ListLength(L) <<endl;
    cout << "顺序表L：" << (ListEmpty(L)?"空":"非空") <<endl;
    GetElem(L,3,e);
    cout << "顺序表L的第3个元素是：" << e <<endl;
    cout << "元素a的位置为：" << LocateElem(L,'a') <<endl;
    cout << "在第四个位置插入元素n \n";
    ListInsert(L,4,'n');
    cout << "输出顺序表：";
    DisplayList(L);
    cout << "删除第三个元素：\n";
    ListDelete(L,3,e);
    cout << "输出顺序表：";
    DisplayList(L);
    cout << "释放顺序表：";
    DeleteList(L);
    DisplayList(L);
}
