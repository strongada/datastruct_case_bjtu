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
typedef struct
{
    int begin;
    int end;
    int weight;
}Edge;

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

void SwapEdges(Edge *edges,int i,int j)
{
    int temp,k;
    temp=edges[i].begin;
    edges[i].begin=edges[j].begin;
    edges[j].begin=temp;
    temp=edges[i].end;
    edges[i].end=edges[j].end;
    edges[j].end=temp;
    temp=edges[i].weight;
    edges[i].weight=edges[j].weight;
    edges[j].weight=temp;
}

void sortEdges(Edge edges[],MGraph *G)
{
    int i,j;
    for(i=0;i<G->numEdges;i++)
    {
        for(j=i+1;j<G->numEdges;j++)
        {
            if(edges[i].weight>edges[j].weight)
            {
                SwapEdges(edges,i,j);
            }
        }
    }
    printf("边表按权升序排序后的为：\n");
    for(i=0;i<G->numEdges;i++)
    {
        printf("(%d%d)%d\n",edges[i].begin,edges[i].end,edges[i].weight);
    }
}

int Find(int *parent,int f)
{
    while(parent[f]>0)
    {
        f=parent[f];
    }
    return f;
}

void MiniSpanTree_Kruskal(MGraph);

void MiniSpanTree_Kruskal(MGraph G)
{
    int parent[MAXVEX];
    Edge edges[MAXVEX];
    int i,j,k=0;
    for(i=0;i<G.numVertexes-1;i++)
    {
        for(j=i+1;j<G.numVertexes;j++)
        {
            if(G.arc[i][j]<INFINITY)
            {
                edges[k].begin=i;
                edges[k].end=j;
                edges[k].weight=G.arc[i][j];
                k++;
            }
        }
    }
    sortEdges(edges,&G);
    for(i=0;i<G.numVertexes;i++)
    {
        parent[i]=0;
    }
    for(i=0;i<G.numEdges;i++)
    {
        j=Find(parent,edges[i].begin);
        k=Find(parent,edges[i].end);
        if(j!=k)
        {
            parent[j]=k;
            printf("(%d,%d)%d\n",edges[i].begin,edges[i].end,edges[i].weight);
        }
    }
}

int main(void)
{
    MGraph G;
    CreateMGraph(&G);
    MiniSpanTree_Kruskal(G);

    return 0;
}
