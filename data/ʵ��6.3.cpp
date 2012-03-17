/*实验6.3：求解背包问题*/
#include<iostream>
#define N 100
using namespace std;
int limitw;
int totv;
int maxv;
int option[N],cop[N];
struct
{
    int weight;
    int value;
}a[N];
int n;
void find(int i,int tw,int tv)
{
    int k;
    if(tw+a[i].weight<=limitw)
    {
        cop[i]=1;
        if(i<n-1)
            find(i+1,tw+a[i].weight,tv);
        else
        {
            for(k=0;k<n;k++)
                option[k]=cop[k];
            maxv=tv;
        }
        cop[i]=0;
    }
    if(tv-a[i].value>maxv)
        if(i<n-1)
            find(i+1,tw,tv-a[i].value);
        else
        {
            for(k=0;k<n;k++)
                option[k]=cop[k];
            maxv=tv-a[i].value;
        }
}
int main()
{
    int k,w,v;
    cout<<"物品种数：";
    cin>>n;
    for(totv=0,k=0;k<n;k++)
    {
        cout<<"第"<<k+1<<"种物品（重量，数量）:";
        cin>>w>>v;
        a[k].weight=w;
        a[k].value=v;
        totv+=v;
    }
    cout<<"背包能承受重量：";
    cin>>limitw;
    maxv=0;
    for(k=0;k<n;k++)
    {
        cop[k]=0;
    }
    find(0,0,totv);
    cout<<"最佳填装方法：\n";
    for(k=0;k<n;k++)
    {
        if(option[k])
            cout<<"第"<<k+1<<"种物品\n";
    }
    cout<<"总价值= "<<maxv<<endl;
}
