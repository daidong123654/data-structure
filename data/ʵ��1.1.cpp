/* *************求素数********************************* */
/*设计一个程序，输出最小和为N的素数。要求：
    1:每行输出十个素数。
    2:尽可能采用较优算法。  */
#include<iostream>
#include<math.h>
using namespace std;
int prime(int n)
{
    int in;
    for (in=2;in<sqrt(n);in++)
    {
        if(n%in == 0)
            return 0;
    }
        return 1;
}
int main()
{
    int i;
    int j=0;
    int n =0;
    cout <<" n: ";
    cin >> n;
    cout <<"小于n的素数：\n";

    for(i=1;i<=n;i++)
    {
        if(i<=2)
        {
            cout<<i<<" ";
            j++;
        }
        else if(prime(i)==1)
        {
            cout<<i<<" ";
            j++;
        }
        if(j!=0 && ++j%10==0)
                cout<<endl;
    }

}
