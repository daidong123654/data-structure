/*实验6.1：输出求解amk（2,1）的递归和求值过程*/
#include<iostream>
using namespace std;
int count=1;
int amk(int m,int n)
{
    int g,f;
    cout<<"\tamk("<<m<<","<<n<<")";
    if(count++%3==0)
        cout<<endl;
    if(m==0)
    {
        cout<<"\tamk(" << 0 << "," <<n << ")= " << n+1 ;
        if(count++%3==0)
            cout<<endl;
        return n+1;
    }
    else if(n==0)
    {
        f=amk(m-1,1);
        cout<<"\tamk(" << m-1 << "," <<1 << ")= " << f;
        if(count++%3==0)
            cout<<endl;
        return f;
    }
    else
    {
        g=amk(m,n-1);
        f=amk(m-1,g);
        cout<<"\tamk(" << m-1 << "," << g << ")= " << f ;
        if(count++%3==0)
            cout<<endl;
        return f;
    }
}
int main()
{
    int m=2,n=1;
    cout<<"求amk（"<<m<<","<<n<<"）的过程如下：\n";
    cout<< "\tamk("<<m<<","<<n<<")= "<<amk(2,1);
}
