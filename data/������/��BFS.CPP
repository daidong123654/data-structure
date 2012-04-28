#include<iostream>
#include<fstream>
#define Num 9
using namespace std;

//搜索算法基类

class TEight
{
public:
    TEight() {} ;//构造函数
    TEight(char *fname); //用文件数据构造节点
    //virtual void Search()=0;
protected:
    int p[Num];          //存储节点状态
    int last,spac;
    static int q[Num],d[],total;
    void Printf();
    bool operator==(const TEight &T);
    bool Extend(int i);
};
int TEight::q[Num];//储存目标节点
int TEight::d[]= {1,3,-1,-3}; //方向
int TEight::total=0;//步数

TEight::TEight(char *fname)    //初始化搜索表
{
    ifstream fin;
    fin.open(fname,ios::in);
    if(!fin)
    {
        cout<<"不能打开数据文件!"<<endl;
        return;
    }
    int i;
    for(i=0; i<Num;) //得到源节点
        fin>>p[i++];
    fin>>spac;
    for(i=0; i<Num;) //得到目标节点
        fin>>q[i++];
    fin.close();
    last=-1;
    total=0;
}

void TEight::Printf()//把路径打印到结果文件
{
    ofstream fout;
    fout.open("eight_result.txt",ios::ate|ios::app);
    fout<<total++<<"t";
    for(int i=0; i<Num;)
        fout<<" "<<p[i++];
    fout<<endl;
    fout.close();
}

bool TEight::operator==(const TEight &T)//判断两个状态是否相同const是常量方式访问。不修改其值
{
    for(int i=0; i<Num;)
        if(T.p[i]!=p[i++])
            return 0;
    return 1;
}

bool TEight::Extend(int i)//扩展
{
    if(i==0 && spac%3==2 || i==1 && spac>5
            || i==2 && spac%3==0 || i==3 && spac<3)
        return 0;
    int temp=spac;
    spac+=d[i];
    p[temp]=p[spac];
    p[spac]=0;
    return 1;
}


//数据文件的结构：

template<class Type> class TList;            //线性表前视定义

template<class Type> class TNode            //线性表结点类模板
{
    friend class TList<Type>;
public:
    TNode() {}
    TNode(const Type& dat);
private:
    TNode<Type>* Next;
    Type Data;
};

template<class Type> class TList     //线性表
{
public:
    TList()
    {
        Last=First=0;    //构造函数
        Length=0;
    }
    int Getlen()const
    {
        return Length;    //成员函数，返回线性表长度   常量方式访问
    }
    int Append(const Type& T);           //成员函数，从表尾加入结点
    int Insert(const Type& T,int k);       //成员函数，插入结点
    Type GetData(int i);                         //成员函数，返回结点数据成员
    void SetData(const Type& T,int k); //成员函数，设置结点数据成员
private:
    TNode<Type> *First,*Last;             //数据成员，线性表首、尾指针
    int Length;                                         //数据成员，线性表长度
};

template<class Type> int TList<Type>::Append(const Type& T)
{
    Insert(T,Length);
    return 1;
}

template<class Type> int TList<Type>::Insert(const Type& T,int k)
{
    TNode<Type> *p=new TNode<Type>;
    p->Data=T;
    if(First)
    {
        if(k<=0)
        {
            p->Next=First;
            First=p;
        }
        if(k>Length-1)
        {
            Last->Next=p;
            Last=Last->Next;
            Last->Next=0;
        }
        if(k>0 && k<Length)
        {
            k--;
            TNode<Type> *q=First;
            while(k-->0)
                q=q->Next;
            p->Next=q->Next;
            q->Next=p;
        }
    }
    else
    {
        First=Last=p;
        First->Next=Last->Next=0;
    }
    Length++;
    return 1;
}

template<class Type> Type TList<Type>::GetData(int k)
{
    TNode<Type> *p=First;
    while(k-->0)
        p=p->Next;
    return p->Data;
}

template<class Type> void TList<Type>::SetData(const Type& T,int k)
{
    TNode<Type> *p=First;
    while(k-- > 0)
        p=p->Next;
    p->Data=T;
}


//广度优先搜索法TBFS类的结构
class TBFS:public TEight
{
public:
    TBFS() {}
    TBFS(char *fname):TEight(fname) {}
    virtual void Search();
private:
    void Printl(TList<TBFS> &L);
    int Repeat(TList<TBFS> &L);
    int Find();  //找到标志
};

void TBFS::Printl(TList<TBFS> &L)    //输出
{
    TBFS T=*this;
    if(T.last==-1)
        return;
    else
    {
        T=L.GetData(T.last);
        T.Printl(L);
        T.Printf();
    }
}

int TBFS::Repeat(TList<TBFS> &L)   //和目标节点进行比较如果是目标节点就结束
{
    int n=L.Getlen();
    int i;
    for(i=0; i<n; i++)
        if(L.GetData(i)==*this)
            break;
    return i;
}

int TBFS::Find()     //比较拓展的节点和目标节点是否相同
{
    for(int i=0; i<Num;)
        if(p[i]!=q[i++])
            return 0;
    return 1;
}

void TBFS::Search()     /*拓展节点并且将其加入到队列L的尾部
                        如果扩展出的结点是目标结点，则输出路径，
                        程序结束。否则继续下一步。（继续拓展）*/
{
    TBFS T=*this;
    TList<TBFS> L;
    L.Append(T);
    int head=0,tail=0;
    while(head<=tail)
    {
        for(int i=0; i<4; i++)
        {
            T=L.GetData(head);
            if(T.Extend(i) && T.Repeat(L)>tail)    //拓展节点并且将它加入到队列L后面
            {
                T.last=head;
                L.Append(T);    //从尾部加入节点
                tail++;
            }
            if(T.Find())     //如果是目标节点就将队列输出，结束程序
            {
                T.Printl(L);
                T.Printf();
                return;
            }
        }
        head++;
    }
}
int main()
{
    //cout<<"Hello World!";
     //template TList T
    TEight E;
    TList<TEight> L;
    L.Append;

}
