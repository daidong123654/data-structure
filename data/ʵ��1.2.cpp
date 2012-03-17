/* 求一个正整数的各位之和*/
#include<iostream>
using namespace std;
int fun(int num)
{
    int s = 0;
    while(num)
    {
        s += num % 10;
        num /= 10;
    }
    return s;
}
int main()
{
    int n;
    cout << endl;
    cout << "请输入一个正整数：";
    cin >> n;
    cout << "各数位之和为：" << fun(n) << endl;
}
