#include "stdio.h"
#include "stdlib.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 20

typedef int Status;
typedef int ElemType;

typedef struct
{
    ElemType data[MAXSIZE];
    int length;
}SqList;

void ListTraverse(SqList L)
{
    int i;
    for(i=0;i<L.length;i++)
        printf("%d",L.data[i]);
    printf("\n");
}

void ClearList(SqList *L)
{
    L->length=0;
}

int ListLength(SqList L)
{
    return L.length;
}

Status ListEmply(SqList L)
{
    if(L.length==0)
        return TRUE;
    else
        return FALSE;
}

Status GetElem(SqList, int, ElemType *);
int LocateElem(SqList, ElemType);
Status ListInsert(SqList *, int, ElemType);
Status ListDelete(SqList *,int, ElemType *);

Status GetElem(SqList L,int i,ElemType *e)
{
    if(L.length==0|L.length<i)
        return ERROR;
    else
    {
        *e=L.data[i-1];
        return OK;
    }
}

int LocateElem(SqList L,ElemType e)
{
    int i,j;
    j=FALSE;
    for(i=0;i<L.length;i++)
        {
            if(e==L.data[i-1])
                {
                    j=TRUE;
                    return i-1;
                }
        }
    if(j=FALSE)
        return ERROR;
}

Status ListInsert(SqList *L,int i,ElemType e)
{
    if(L->length<i-1|i<1)
        return ERROR;
    else
    {
        int j;
        for(j=L->length;j>=i;j--)
        {
            L->data[j]=L->data[j-1];
        }
        L->data[i-1]=e;
        L->length++;
        return OK;
    }
}

Status ListDelete(SqList *L,int i,ElemType *e)
{
    if(i>L->length|i<1)
        return ERROR;
    else
    {
        int j;
        *e=L->data[i-1];
        for(j=i;j<L->length;j++)
            L->data[j-1]=L->data[j];
        L->length--;
        return OK;
    }
}

int main()
{
    SqList L;
    ElemType e;
    Status i;
    int j;

    ClearList(&L);

    L.length=0;
    for(j=1;j<=5;j++)
    {
        i=ListInsert(&L,1,j);
    }
    printf("在L的表头依次插入1～5后：L.data=");
    ListTraverse(L);
    printf("L.length=%d \n",L.length);

    ClearList(&L);
    printf("清空L后：L.length=%d\n",L.length);

    for(j=1;j<=10;j++)
    {
        ListInsert(&L,j,j);    
    }
    printf("在L的表尾依次插入1～10后：L.data=");
    ListTraverse(L);
    printf("L.length=%d \n",L.length);

    ListInsert(&L,1,0);
    printf("在L的表头插入0后：L.data=");
    ListTraverse(L);
    printf("L.length=%d \n",L.length);

    GetElem(L,5,&e);
    printf("第5个元素的值为：%d\n",e);
    
    j=5;
    ListDelete(&L,j,&e);
    printf("删除L的第5个元素后：L.data=");
    ListTraverse(L);

    int k,m;
    m=L.length;
    for(j=1;j<10;j++)
    {   
        if(j==2|j==3|j==6|j==7)
        {   
            k=m-j+1;
            ListDelete(&L,k,&e);
        }
    }
    printf("删除L的倒数第2、3、6、7个元素后：L.data=");
    ListTraverse(L);

    return 0;
}
