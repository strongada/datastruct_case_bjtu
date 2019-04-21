#include "stdio.h"
#include "stdlib.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXVEX 20
#define MAXEDGE MAXVEX*MAXVEX

#define INFINITY 65535

typedef char VertexType;
typedef int EdgeType;

typedef int Status;

typedef struct
{
    VertexType vexs[MAXVEX];
    EdgeType arc[MAXVEX][MAXVEX];
    int numVertexes,numEdges;
}MGraph;

Status CreateMGraph(MGraph *G)
{
    int i,j,k,w;
    
    printf("请输入顶点的个数:\n");
    scanf("%d",&G->numVertexes);
    if(G->numVertexes>MAXVEX||G->numVertexes<2)
        return ERROR;

    printf("请输入边的条数:\n");
    scanf("%d",&G->numEdges);
    if(G->numEdges>MAXEDGE||G->numEdges<1)
        return ERROR;

    for(i=0;i<G->numVertexes;i++)
    {
        printf("请输入第%d个顶点(共%d个)的标示符:\n",i+1,G->numVertexes);
        scanf("%s",&G->vexs[i]);
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
        printf("请输入第%d条边(Vi,Vj)的下标i，j和权w:(共%d条)\n",k+1,G->numEdges);
        scanf("%d%d%d",&i,&j,&w);
        if(w<1||i==j||i>=G->numVertexes||i<0||j>=G->numVertexes||j<0)
            return ERROR;
        G->arc[i][j]=w;
        G->arc[j][i]=w;
    }

    return OK;
}

//void MiniSpanTree_Prim(int *,int *,MGraph);

void MiniSpanTree_Prim(MGraph G)
{
    int i,j,k,min;
    int lowcost[G.numVertexes];
    int adjvex[G.numVertexes];
    lowcost[0]=0;
    adjvex[0]=0;
    for(i=1;i<G.numVertexes;i++)
    {
        lowcost[i]=G.arc[0][i];
        adjvex[i]=0;
    }
    for(i=1;i<G.numVertexes;i++)
    {
        min=INFINITY;
        for(j=1,k=0;j<G.numVertexes;j++)
        {
            if(lowcost[j]!=0&&lowcost[j]<min)
            {
                min=lowcost[j];
                k=j;
            }
        }
        lowcost[k]=0;
        printf("(%d%d)",adjvex[k],k);
        for(j=1;j<G.numVertexes;j++)
        {
            if(lowcost[j]!=0&&G.arc[k][j]<lowcost[j])
            {
                lowcost[j]=G.arc[k][j];
                adjvex[j]=k;
            }
        }
    }
}

int main(void)
{
    MGraph G;
    CreateMGraph(&G);
    MiniSpanTree_Prim(G);

    return 0;
}
