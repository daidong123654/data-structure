#include<iostream>
#define MAX 100
using namespace std;
int main()
{
    double a,l=1.0,y=0.0;
    double x[MAX],fx[MAX];
    int k=0,n,i=0;
    cout<<"请输入n次插值的n: ";
    cin>>n;
    cout<<"请输入n次插值的 x[]: ";
    while(i<=n)
    {
        cin>>x[i];
        i++;
    }
    cout<<"请输入n次插值的 fx[]: ";
    i=0;
    while(i<=n)
    {
        cin>>fx[i];
        i++;
    }
    cout<<"请输入要求值的 x: ";
    cin>>a;
    while(k<=n)
    {
        l=1.0;
        for(int j=0;j<=n;j++)
        {
            if(k!=j)
            {
                l=l*(a-x[j])/(x[k]-x[j]);
            }
        }
        y=y+l*fx[k];
        k++;
    }
    cout<<"("<<a<<","<<y<<")\n";
    cout<<"即函数在"<<a<<"处的值是："<<y<<endl;
return 0;
}
