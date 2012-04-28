# define MAXV 100
typedef int InfoType;
typedef struct
{
    int no;
    InfoType info;
}VertexType;
typedef struct
{
    int edges[MAXV][MAXV];
    int vexnum,arcnum;
    VertexType vexs[MAXV];
}MGraph;
typedef struct ANode
{
    int adjvex;
    struct ANode *nextarc;
    InfoType info;
}ArcNode;
typedef int VerTex;
typedef struct Vnode
{
    VerTex data;
    ArcNode *firstarc;
}VNode;
typedef VNode AdjList[MAXV];
typedef struct
{
    AdjList adjlist;
    int n,e;
}ALGraph;


