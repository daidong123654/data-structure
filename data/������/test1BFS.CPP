#include<iostream>
#include<fstream>
using namespace std;
#define Num 9
typedef struct TEight
{
    TEight ;
    int p[Num];     //存储节点状态
    int last ,space;
    int q[Num],d[],total;
    bool find;
};
int q[Num];  //目标节点
int d[]={1,3,-1,-3}; //diraction
int total=0;   //bushu



