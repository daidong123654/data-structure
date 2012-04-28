 #include<iostream>
 using namespace std;
struct node{
int nodesun[4][4];

int x,y;
}path[1000];
int zx[4]={-1,0,1,0};
int zy[4]={0,-1,0,1};
int top;
int desti[4][4];//目标状态
int detect(struct node *p)
{int i,j;
  for(i=1;i<4;i++)
     for(j=1;j<4;j++)
   if(p->nodesun[i][j]!=desti[i][j])
    return 0;
  return 1;
}

void printlj()
{int tempt;
int i,j;
tempt=1;
while(tempt<=top)
{    for(i=1;i<4;i++)
     for(j=1;j<4;j++)
  {cout<<path[tempt].nodesun[i][j];
   if(j==3)
    cout<<" "<<endl;
  }
  tempt++;
}
}


int main()
{ //初始化
  int i,j,m,n,f;
  int temp,find=0;
  top=1;
for(i=1;i<4;i++)
     for(j=1;j<4;j++)
  {cout<<"请输入第"<<i<<"行"<<"第"<<j<<"列的值"<<endl;
   cin>>temp;
   path[1].nodesun[i][j]=temp;
  }
  cout<<"请输入初始状态的空格的位置(行)"<<endl;
  cin>>temp;
  path[1].x=temp;
cout<<"请输入初始状态的空格的位置(列)"<<endl;
  cin>>temp;
  path[1].y=temp;
//目标状态
for(i=1;i<4;i++)
     for(j=1;j<4;j++)
  {cout<<"请输入目标状态第"<<i<<"行"<<"第"<<j<<"列的值"<<endl;
   cin>>temp;
   desti[i][j]=temp;
  }
  //深度优先搜索
while(!find)
{ m=path[top].x;
  n=path[top].y ;
  for(f=0;f<4;f++)
  {i=m+zx[f];
   j=n+zy[f];
   if(i>=1&&i<=3&&j>=1&&j<=3)
   {top++;
    path[top]=path[top-1];
path[top].nodesun[m][n]=path[top-1].nodesun[i][j];
path[top].nodesun[i][j]=0;

path[top].x=i;
path[top].y=j;

   if(detect(&path[top]))
   {printlj();
   find=1;
   break;
   }

   break;
   }//if

  }//for

   }//while
}



/*#include"iostream.h"
struct node{
int nodesun[4][4];
int pre;
int x,y;
}path[400];
int zx[4]={-1,0,1,0};
int zy[4]={0,-1,0,1};
int front,rear;
int desti[4][4];//目标状态
int detect(struct node *p)
{int i,j;
  for(i=1;i<4;i++)
     for(j=1;j<4;j++)
   if(p->nodesun[i][j]!=desti[i][j])
    return 0;
  return 1;
}

void printlj()
{int tempt;
int i,j;
tempt=rear;
while(tempt!=0)
{    for(i=1;i<4;i++)
     for(j=1;j<4;j++)
  {cout<<path[tempt].nodesun[i][j];
   if(j==3)
    cout<<" "<<endl;
  }
  tempt=path[tempt].pre;
}
}




void main()
{ //初始化
  int i,j,m,n,f;
  int temp,find=0;
  front=rear=1;
  path[1].pre=0;
for(i=1;i<4;i++)
     for(j=1;j<4;j++)
  {cout<<"请输入第"<<i<<"行"<<"第"<<j<<"列的值"<<endl;
   cin>>temp;
   path[1].nodesun[i][j]=temp;
  }
  cout<<"请输入初始状态的空格的位置(行)"<<endl;
  cin>>temp;
  path[1].x=temp;
cout<<"请输入初始状态的空格的位置(列)"<<endl;
  cin>>temp;
  path[1].y=temp;
//目标状态
for(i=1;i<4;i++)
     for(j=1;j<4;j++)
  {cout<<"请输入目标状态第"<<i<<"行"<<"第"<<j<<"列的值"<<endl;
   cin>>temp;
   desti[i][j]=temp;
  }
  //广度优先搜索
while(front<=rear&&!find)
{ m=path[front].x;
  n=path[front].y ;
  for(f=0;f<4;f++)
  {i=m+zx[f];
   j=n+zy[f];
   if(i>=1&&i<=3&&j>=1&&j<=3)
   {rear++;
    path[rear]=path[front];
path[rear].nodesun[m][n]=path[front].nodesun[i][j];
path[rear].nodesun[i][j]=0;
path[rear].pre=front;
path[rear].x=i;
path[rear].y=j;
   if(detect(&path[rear]))
   {printlj();
   find=1;
   break;
   }
   }
  }
   front++;
   }
}
*/
