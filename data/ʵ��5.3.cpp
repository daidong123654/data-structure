/*实验5.3：求两个对称矩阵的积与和
对称矩阵存入到一个一维数组中后M第i行第j列元素
在数组中的位置计算如下：
  {i(i-1)/2+j    if  i>=j;
k={
  {j(j-1)/2+i    if  i<j;
 */
 #include<iostream>
 #define n 4
 #define m 10
 using namespace std;
 int value(int a[],int i,int j)
 {
     if(i>=j)
        return a[(i*(i-1))/2+j];
    else
        return a[(j*(j-1))/2+i];
 }
 void madd(int a[], int b[],int c[n][n] )
 {
     int i,j;
     for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            c[i][j]=value(a,i,j)+value(b,i,j);
 }
 void mult(int a[],int b[],int c[n][n])
 {
     int i,j,k,s;
     for(i=0;i<n;i++)
         for(j=0;j<n;j++)
        {
            s=0;
            for(k=0;k<n;k++)
                s=s+value(a,i,k)*value(b,k,j);
            c[i][j]=s;
        }
 }
 void Disp(int a[])
 {
     int i,j;
     for(int i=0;i<n;i++)
     {
         for(j=0;j<n;j++)
            cout<<"\t"<<value(a,i,j);
        cout<<endl;
     }
 }
 void Disp1(int c[n][n])
 {
     int i,j;
     for(int i=0;i<n;i++)
     {
         for(j=0;j<n;j++)
            cout<<"\t"<<c[i][j];
        cout<<endl;
     }
}
int main()
{
    int a[m]={1,2,3,4,5,6,7,8,9,10};
    int b[m]={1,1,1,1,1,1,1,1,1,1};
    int c1[n][n];
    int c2[n][n];
    madd(a,b,c1);
    mult(a,b,c2);
    cout<<endl;
    cout<<"a矩阵：\n";
    Disp(a);
    cout<<"b矩阵：\n";
    Disp(b);
    cout<<"a+b:\n";
    Disp1(c1);
    cout<<"a*b:\n";
    Disp1(c2);
    cout<<endl;
}

