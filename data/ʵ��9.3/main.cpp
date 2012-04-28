/*实验9.3:求有向图的简单路径*/
#include<iostream>
#include<malloc.h>
#include<stdio.h>
#include "graph.h"
using namespace std;
int visited[MAXV];

void MatToList(MGraph g,ALGraph *&G)    //邻接矩阵g转换成邻接表
{
    int i,j,n=g.vexnum;
    ArcNode *p;
    G=(ALGraph *)malloc(sizeof(ALGraph));
    for(i=0;i<n;i++)
        G->adjlist[i].firstarc=NULL;
    for(i=0;i<n;i++)
        for(j=n-1;j>=0;j--)
           if(g.edges[i][j]!=0)
           {
               p=(ArcNode *)malloc(sizeof(ArcNode));
               p->adjvex=j;
               p->info=g.edges[i][j];
               p->nextarc=G->adjlist[i].firstarc;
               G->adjlist[i].firstarc=p;
           }
    G->n=n;
    G->e=g.arcnum;
}
void DispAdj(ALGraph *G)
{
    int i;
    ArcNode *p;
    for(i=0;i<G->n;i++)
    {
        p=G->adjlist[i].firstarc;
        if(p!=NULL)
            cout<<"   "<<i<<":";
        while(p!=NULL)
        {
            cout<<"   "<<p->adjvex;
            p=p->nextarc;
        }
    cout<<endl;
    }
}

void PathAll(ALGraph *G,int u,int v,int path[],int i)
{
    ArcNode *p;
    int j,n;
    visited[u]=1;
    p=G->adjlist[u].firstarc;
    while(p!=NULL)
    {
        n=p->adjvex;
        if(n==v)
        {
            path[i+1]=v;
            for(j=0;j<=i+1;j++)
                printf("%3d",path[j]);
            printf("\n");
        }
        else if(visited[n]==0)
        {
            path[i+1]=n;
            PathAll(G,n,v,path,i+1);
        }
        p=p->nextarc;
    }
    visited[u]=0;
}
void PathAll2(ALGraph *G,int u,int v,int l,int path[],int d)
{
    int m,i;
    ArcNode *p;
    visited[u]=1;
    d++;
    path[d]=u;
    if(u==v && d==1)
    {
        for(i=0;i<=d;i++)
            printf("%3d",path[i]);
        printf("\n");
    }
    p=G->adjlist[u].firstarc;
    while(p!=NULL)
    {
        m=p->adjvex;
        if(visited[m]==0)
            PathAll2(G,m,v,l,path,d);
        p=p->nextarc;
    }
    visited[u]=0;
    d--;
}
int ShortPath(ALGraph *G,int u,int v,int path[])
{
    struct
    {
        int vno;
        int level;
        int parent;
    }qu[MAXV];
    int front=-1,rear=-1,k,lev,i,j;
    ArcNode *p;
    visited[u]=1;
    rear++;
    qu[rear].vno=u;
    qu[rear].level=0;
    qu[rear].parent=-1;
    while(front<rear)
    {
        front++;
        k=qu[front].vno;
        lev=qu[front].level;
        if(k==v)
        {
            i=0;
            j=front;
            while(j!=-1)
            {
                path[lev-1]=qu[j].vno;
                j=qu[j].parent;
                i++;
            }
            return lev;
        }
        p=G->adjlist[k].firstarc;
        while(p!=NULL)
        {
            if(visited[p->adjvex]==0)
            {
                visited[p->adjvex]=1;
                rear++;
                qu[rear].vno=p->adjvex;
                qu[rear].level=lev+1;
                qu[rear].parent=front;
            }
            p=p->nextarc;
        }
    }
    return 0;
}
int main()
{
    int i,j;
    int u=5,v=2,d=3;
    int path[MAXV];
    MGraph g;
    ALGraph *G;
    int A[MAXV][6]={
                    {0,1,0,1,0,0},
                    {0,0,1,0,0,0},
                    {1,0,0,0,0,1},
                    {0,0,1,0,0,1},
                    {0,0,0,1,0,0},
                    {1,1,0,1,1,0}};
    g.vexnum=6,g.arcnum=10;
    for(i=0;i<g.vexnum;i++)
        for(j=0;j<g.vexnum;j++)
            g.edges[i][j]=A[i][j];
    cout<<endl;
    G = new ALGraph;
    MatToList(g,G);
    printf("邻接表：\n");
    DispAdj(G);
    for(i=0;i<g.vexnum;i++)
        visited[i]=0;
    printf("从%d到%d的所有路径是：\n",u,v);
    path[0]=u;
    visited[u]=1;
    PathAll(G,u,v,path,0);
    cout<<endl;

    printf("从%d到%d的所有长度为%d路径是：\n",u,v,d);
    PathAll2(G,u,v,d,path,-1);
    for(i=0;i<g.vexnum;i++)
        visited[i]=0;

    printf("从%d到%d的最短路径是：\n",u,v);
    for(i=0;i<g.vexnum;i++)
        visited[i]=0;
    j=ShortPath(G,u,v,path);

    for(i=0;i<=j;i++)
        printf("%3d",path[i]);
    printf("\n\n");

}
