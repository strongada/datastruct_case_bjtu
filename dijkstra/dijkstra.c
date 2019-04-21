#include "stdio.h"
#include "stdlib.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXVEX 20
#define MAXEDGE MAXVEX*MAXVEX
#define INFINITY 65535

typedef int VertexType;
typedef int EdgeType;
typedef int Status;
typedef struct
{
    VertexType vexs[MAXVEX];
    EdgeType arc[MAXVEX][MAXVEX];
    int numVertexes,numEdges;
}MGraph;

typedef int Patharc[MAXVEX];
typedef int ShortPathTable[MAXVEX];

Status CreateMGraph(MGraph *G)
{
    int i,j,k,w;
    printf("请输入顶点的个数：\n");
    scanf("%d",&G->numVertexes);
    if(G->numVertexes>MAXVEX||G->numVertexes<2)
        return ERROR;
    printf("请输入边的条数：\n");
    scanf("%d",&G->numEdges);
    if(G->numEdges>MAXEDGE||G->numEdges<1)
        return ERROR;

    for(i=0;i<G->numVertexes;i++)
    {
        printf("请输入第%d个顶点（共%d个）的标识符：\n",i+1,G->numVertexes);
        scanf("%d",&G->vexs[i]);
    }

    for(i=0;i<G->numVertexes;i++)
    {
        for(j=0;j<G->numVertexes;j++)
        {
            G->arc[i][j]=INFINITY;
        }
        G->arc[i][i]=0;
    }

    for(k=0;k<G->numEdges;k++)
    {
        printf("请输入第%d条边(Vi,Vj)的下标i,j和权w：(共%d条)\n",k+1,G->numEdges);
        scanf("%d%d%d",&i,&j,&w);
        if(w<1||i==j||i>=G->numVertexes||i<0||j>=G->numVertexes||j<0)
            return ERROR;
        G->arc[i][j]=w;
        G->arc[j][i]=w;
    }
    return OK;
}

void shortestPath_Dijkstra(MGraph G,int v0,Patharc *P,ShortPathTable *D)
{
    int v,w,k,min;
    int final[MAXVEX];
    for(v=0;v<G.numVertexes;v++)
    {
        final[v]=0;
        (*D)[v]=G.arc[v0][v];
        (*P)[v]=-1;
    }

    (*D)[v0]=0;
    final[v0]=1;
    
    for(v=1;v<G.numVertexes;v++)
    {
        min=INFINITY;
        for(w=0;w<G.numVertexes;w++)
        {
            if(!final[w]&&(*D)[w]<min)
            {
                k=w;
                min=(*D)[w];
            }
        }
        final[k]=1;
        for(w=0;w<G.numVertexes;w++)
        {
            if(!final[w]&&(min+G.arc[k][w])<(*D)[w])
            {
                (*D)[w]=(min+G.arc[k][w]);
                (*P)[w]=k;
            }
        }
    }
}

int main(void)
{
    int i,j,v0;
    MGraph G;
    Patharc P;
    ShortPathTable D;
    v0=0;

    CreateMGraph(&G);
    shortestPath_Dijkstra(G,v0,&P,&D);
    for(i=1;i<G.numVertexes;i++)
    {
        printf("(%d,%d)",i,P[i]);
    }
    return 0;
}
