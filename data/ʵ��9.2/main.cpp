#include <iostream>
#include <stdio.h>
#include <malloc.h>
#include "graph.h"
using namespace std;
int visited[MAXV];

void DFS(ALGraph *G,int v)
{
    ArcNode *p;
    visited [v]=1;
    printf("%3d",v);
    p=G->adjlist[v].firstarc;
    while(p!=NULL)
    {
        if(visited[p->adjvex]==0)
            DFS(G,p->adjvex);
        p=p->nextarc;
    }
}

void DFS1(ALGraph *G,int v)
{
    int i,visited[MAXV],St[MAXV],top=-1;
    ArcNode *p;
    for(i=0; i<G->n; i++)
        visited[i]=0;
    printf("%3d",v);
    top++;
    St[top]=v;
    visited[v]=1;
    while(top>= -1)
    {
        v=St[top];
        top--;
        p=G->adjlist[v].firstarc;
        while(p!=NULL && visited[p->adjvex]==1)
            p=p->nextarc;
        if(p==NULL)
            top--;
        else
        {
            v=p->adjvex;
            printf("%3d",v);
            visited[v]=1;
            top++;
            St[top]=v;
        }
    }
    cout<<endl;
}

void BFS(ALGraph *G,int v)
{
    ArcNode *p;
    int queue[MAXV],front=0,rear=0;
    int visited[MAXV];
    int w,i;
    for(i=0; i<G->n; i++)
        visited[i]=0;
    printf("%3d",v);
    visited[v]=1;
    rear=(rear+1)%MAXV;
    queue[rear]=v;
    while(front!=rear)
    {
        front=(front+1)%MAXV;
        w=queue[front];
        p=G->adjlist[w].firstarc;
        while(p!=NULL)
        {
            if(visited[p->adjvex]==0)
            {
                printf("%3d",p->adjvex);
                visited[p->adjvex]=1;
                rear=(rear+1)%MAXV;
                queue[rear]=p->adjvex;
            }
            p=p->nextarc;
        }
    }
    cout<<endl;
}

void MatToList(MGraph g,ALGraph *&G)    //邻接矩阵g转换成邻接表
{
    int i,j,n=g.vexnum;
    ArcNode *p;
    G=(ALGraph *)malloc(sizeof(ALGraph));
    for(i=0; i<n; i++)
        G->adjlist[i].firstarc=NULL;
    for(i=0; i<n; i++)
        for(j=n-1; j>=0; j--)
            if(g.edges[i][j]!=0)
            {
                p=(ArcNode *)malloc(sizeof(ArcNode));
                int m=j;
                p->adjvex=m;
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
    for(i=0; i<G->n; i++)
    {
        p=G->adjlist[i].firstarc;
        if(p!=NULL)
            cout<<"   "<<i;
        while(p!=NULL)
        {
            cout<<"   "<<p->adjvex;
            p=p->nextarc;
        }
        cout<<endl;
    }
}

int main()
{
    int i,j;
    MGraph g;
    ALGraph *G;
    int A[MAXV][6]=
    {
        {0,5,0,7,0,0},
        {0,0,4,0,0,0},
        {8,0,0,0,0,9},
        {0,0,5,0,0,6},
        {0,0,0,5,0,0},
        {3,0,0,0,1,0}
    };
    g.vexnum=6,g.arcnum=10;
    for(i=0; i<g.vexnum; i++)
        for(j=0; j<g.vexnum; j++)
            g.edges[i][j]=A[i][j];
    cout<<endl;
    MatToList(g,G);
    cout<<"图G的邻接表：\n";
    DispAdj(G);
    cout<<endl;
    cout<<"从顶点0开始的DFS算法（递归）:\n";
    DFS(G,0);
    cout<<endl;
    cout<<"从顶点0开始的DFS算法（非递归）:\n";
    DFS1(G,0);
    cout<<endl;
    cout<<"从顶0点开始的BFS算法：\n";
    BFS(G,0);
    cout<<endl;
}
