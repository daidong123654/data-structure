/*实验5.1：求一个矩阵的马鞍点*/
#include<iostream>
#define M 4
#define N 4
using namespace std;
void MinMax(int A[M][N])
{
    int i,j,have=0;
    int min[M],max[N];
    for(i=0;i<M;i++)
    {
        min[i]=A[i][0];
        for(j=1;j<N;j++)
            if(A[i][j]<min[i])
                min[i]=A[i][j];
    }
    for(j=0;j<N;j++)
    {
        max[j]=A[0][j];
        for(i=1;i<M;i++)
            if(A[i][j]>max[i])
                max[j]=A[i][j];
    }
    for(i=0;i<M;i++)
        for(j=0;j<N;j++)
            if(min[i]==max[j])
            {
                cout<<"A["<<i<<","<<j<<"] = "<<A[i][j]<<endl;
                have=1;
            }
    if(! have)
        cout<<"没有马鞍点！\n";
}
int main()
{
    int j,i;
    int A[M][N]={{9,7,6,8},{20,26,22,25},{28,36,25,30},{12,4,2,6} };
    cout<<"A矩阵：\n";
    for(i=0;i<M;i++)
    {
        for(j=0;j<N;j++)
        {
            cout<<" \t"<<A[i][j];
        }
        cout<<endl;
    }
    cout<<"A矩阵的马鞍点是：\n";
    MinMax(A);

}
