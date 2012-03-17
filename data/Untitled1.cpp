#include <iostream>
using namespace std;
int main()
{
    int p[10][10];
    int n,m;
    int i,j,k;
    int flag=1;
    while(cin>>n>>m)
    {
          if(n==0&&m==0)break;
          flag=1;
          for(i=0;i<n;i++)
          {
                 for(j=0;j<m;j++)
                 {
                         cin>>p[i][j];
                         if(p[i][j]==0)flag=0;
                 }
          }
          if(flag==1)
          {
                  cout<<"No"<<endl;
  continue;
          }
          for(k=1;k<m;k++)
          {
                   if(p[0][k]==0&&p[0][k-1]==0)
                   {
                           cout<<"No"<<endl;
                           goto RL;
                   }
          }
          for(i=1;i<n;i++)
          {
                   for(int j=0;j<m;j++)
                   {
                        if(p[i][j]==0&&p[i-1][j]==0)
                        {
                               cout<<"No"<<endl;
                               goto RL;
                        }
                        if(j!=0)
                        {
                                if(p[i][j]==0&&p[i][j-1]==0)
 {
                                        cout<<"No"<<endl;
                                        goto RL;
                                }
                        }
                   }
          }
          cout<<"Yes"<<endl;
          continue;
      RL:
          continue;

    }
    return 0;
}

