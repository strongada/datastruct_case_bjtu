#include "stdio.h"
#include "stdlib.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 1
#define MAXSIZE 20

typedef int Status;
typedef int QElemType;

typedef struct
{
    QElemType data[MAXSIZE];
    int front;
    int rear;
}SqQueue;

void InitQueue(SqQueue *Q)
{
    Q->front=Q->rear=0;
}

void QueueTraverse(SqQueue Q)
{
    int i;
    i=Q.front;
    while(i!=Q.rear)
    {
        printf("%d",Q.data[i]);
        i=(i+1)%MAXSIZE;
    }
    printf("\n");
}

void ClearQueue(SqQueue *Q)
{
    Q->front=Q->rear=0;
}

Status QueueEmpty(SqQueue Q)
{
    if(Q.front==Q.rear)
        return TRUE;
    else
        return FALSE;
}

int QueueLength(SqQueue Q)
{
    return (Q.rear-Q.front+MAXSIZE)%MAXSIZE;
}

Status GetHead(SqQueue,QElemType *);
Status EnQueue(SqQueue *,QElemType);
Status DeQueue(SqQueue *,QElemType *);

Status GetHead(SqQueue Q,QElemType *e)
{
    if(QueueLength(Q)==0)
        return ERROR;
    else
    {
        *e=Q.data[Q.front];
        return *e;
    }
        
}

Status EnQueue(SqQueue *Q,QElemType e)
{
    if(QueueLength(*Q)==MAXSIZE-1)
        return ERROR;
    else
    {
        Q->data[Q->rear]=e;
        Q->rear=(Q->rear+1)%MAXSIZE;
        return OK;
    }
}

Status DeQueue(SqQueue *Q,QElemType *e)
{
    if(QueueLength==0)
        return ERROR;
    else
    {
        *e=Q->data[Q->front];
        Q->front=(Q->front+1)%MAXSIZE;
        return OK;
    }
}

int main()
{
    Status j;
    int i=0,l;
    QElemType d;
    SqQueue Q;
    InitQueue(&Q);
    printf("初始化队列后，队列空否？%u(1:空 0:否)\n",QueueEmpty(Q));

    printf("请输入整型队列元素（不超过%d个），-1为提前结束符号：",MAXSIZE-1);
    do
    {
        d=i+100;
        if(d==-1)
            break;
        i++;
        EnQueue(&Q,d);
    }while(i<MAXSIZE-1);

    printf("队列长度为：%d\n",QueueLength(Q));
    printf("现在队列长度空否？%u（1:空 2:否）\n",QueueEmpty(Q));
    printf("连续%d次由队头删除元素，队尾插入元素：\n",MAXSIZE);
    for(l=1;l<=MAXSIZE;l++)
    {
        DeQueue(&Q,&d);
        printf("删除的元素是%d,插入的元素：%d\n",d,l+1000);
        d=l+1000;
        EnQueue(&Q,d);
    }
    l=QueueLength(Q);

    printf("现在队列中的元素为：\n");
    QueueTraverse(Q);
    printf("共向队尾插入了%d个元素\n",i+MAXSIZE);
    if(l-2>0)
        printf("现在由队头删除%d个元素：\n",l-2);
    while(QueueLength(Q)>2)
    {
        DeQueue(&Q,&d);
        printf("删除的元素值为%d\n",d);
    }
    j=GetHead(Q,&d);
    if(j)
        printf("现在队头元素为：%d\n",d);
    ClearQueue(&Q);
    printf("清空队列后，队列空否？%u（1:空 2:否）\n",QueueEmpty(Q));
    return 0;
}
