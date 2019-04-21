#include "stdio.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 20

typedef int Status;
typedef int SElemType;

typedef struct
{
    SElemType data[MAXSIZE];
    int top;
}SqStack;

void StackTraverse(SqStack S)
{
    int i;
    i=0;
    while(i<=S.top)
    {
        printf("%d",S.data[i++]);
    }
    printf("\n");
}

void ClearStack(SqStack *S)
{
    S->top=-1;
}

Status StackEmpty(SqStack S)
{
    if(S.top==-1)
        return TRUE;
    else
        return FALSE;
}

int StackLength(SqStack S)
{
    return S.top+1;
}


Status GetTop(SqStack,SElemType *);
Status Push(SqStack *,SElemType);
Status Pop(SqStack *,SElemType *);

Status GetTop(SqStack S,SElemType *e)
{
    if(S.top==-1)
        return ERROR;
    else
        *e=S.data[S.top];
}

Status Push(SqStack *S,SElemType e)
{
    if(S->top==MAXSIZE)
        return ERROR;
    else
    {
        S->top++;
        S->data[S->top]=e;
        return OK;
    }
}

Status Pop(SqStack *S,SElemType *e)
{
    if(S->top==-1)
        return ERROR;
    else
    {
        *e=S->data[S->top];
        S->top--;
        return OK;
    }
}

void main()
{
    SqStack S;
    SElemType e;
    ClearStack(&S);
    for(e=1;e<=5;e++)
        Push(&S,e);
    printf("依次将1~5进栈：");
    StackTraverse(S);
    printf("栈的长度=:%d\n",StackLength(S));
    Pop(&S,&e);
    printf("出栈一个为%d的数后：",e);
    StackTraverse(S);
    GetTop(S,&e);
    printf("此时栈顶的数字为：%d\n",e);
}
