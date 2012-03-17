/*实验3.5：求迷宫问题的所有路径及最短路径*/
#include<iostream>
#define M 6
#define N 6
#define MAX 100
using namespace std;
int mg[M+1][N+1]={
    {1,1,1,1,1,1},
    {1,0,0,0,1,1},
    {1,0,1,0,0,1},
    {1,0,0,0,1,1},
    {1,1,0,0,0,1},
    {1,1,1,1,1,1},
    };
struct
{
    int i,j,di;
}Stack[MAX],Path[MAX];
int top=-1;
int count=1;
int minlen=MAX;
void mapath()
{
    int i,j,di,find,k;
    top++;
    Stack[top].i=1;
    Stack[top].j=1;
    Stack[top].di=-1;
    mg[1][1]=-1;
    while(top>-1)
    {
        i=Stack[top].i;
        j=Stack[top].j;
        di=Stack[top].di;
        if(i==M-2&&j==N-2)
        {
            cout<<"    "<<count++;
            for(k=0;k<=top;k++)
            {
                cout<<Stack[k].i<<Stack[k].j;
                if((k+1)%5==0)
                    cout<<endl<<"\t";
            }
            cout<<endl;
            if(top+1<minlen)
            {
                for(k=0;k<=top;k++)
                    Path[k]=Stack[k];
                minlen=top+1;
            }
            mg[Stack[top].i][Path[top].j]=0;
            top--;
            i=Stack[top].i;
            j=Stack[top].j;
            di=Stack[top].di;
        }
        find=0;
        while(di<4&&find==0)
        {
            di++;
            switch(di)
            {
                case 0:i=Stack[top].i-1;j=Stack[top].j; break;
                case 1:i=Stack[top].i;j=Stack[top].j+1; break;
                case 2:i=Stack[top].i+1;j=Stack[top].j; break;
                case 3:i=Stack[top].i;j=Stack[top].j-1; break;
            }
            if(mg[i][j]==0)
                find=1;
        }
            if(find==1)
            {
                Stack[top].di=di;
                top++;
                Stack[top].i=i;
                Stack[top].j=j;
                Stack[top].di=-1;
                mg[i][j]=1;
            }
            else
            {
                mg[Stack[top].i][Path[top].j]=0;
                top--;
            }
        }
        cout<<"路径如下：\n";
        cout<<"长度："<<minlen<<endl;
        cout<<"路径：";
        for(k=0;k<minlen;k++)
        {
            cout<<Path[k].i<<Path[k].j;
            if((k+1)%5==0)
                cout<<endl<<"\n";
        }
        cout<<endl;

}
int main()
{
    cout<<"所有路径是：\n";
    mapath();

}
