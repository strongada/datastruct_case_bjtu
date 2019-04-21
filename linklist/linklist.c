#include "stdio.h"
#include "stdlib.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 20

typedef int Status;
typedef int ElemType;
typedef struct Node
{
    ElemType data;
    struct Node *next;
}Node;
typedef struct Node *LinkList;

void ListTraverse(LinkList L)
{
    LinkList p=L->next;

    while(p)
    {
        printf("%d",p->data);
        p=p->next;
    }
    printf("\n");
}

void ClearList(LinkList *L)
{
    LinkList p,q;
    p=(*L)->next;

    while(p)
    {
        q=p->next;
        free(p);
        p=q;
    }
    (*L)->next=NULL;
}

Status InitList(LinkList *L)
{
    *L=(LinkList)malloc(sizeof(Node));
    if(!(*L))
        return ERROR;
    (*L)->next=NULL;

    return OK;
}

Status listEmpty(LinkList L)
{
    if(L->next)
        return FALSE;
    else
        return TRUE;
}

int ListLength(LinkList);
Status GetElem(LinkList,int,ElemType *);
int LocateElem(LinkList,ElemType);
Status ListInsert(LinkList *,int,ElemType);
Status ListDelete(LinkList *,int,ElemType *);

int ListLength(LinkList L)
{
    LinkList p;
    int i=0;
    p=L->next;
    while(p)
    {
        i++;
        p=p->next;
    }
    return i;
}

Status GetElem(LinkList L,int i,ElemType *e)
{
    if(ListLength(L)<i)
        return ERROR;
    else
    {
        int j=1;
        LinkList p=L->next;
        for(j=2;j<=i;j++)
        {
            p=p->next;
        }
        *e=p->data;
        return OK;
    }
}

int LocateElem(LinkList L,ElemType e)
{
    int i,j;
    j=FALSE;
    LinkList p=L->next;
    for(i=1;i<=ListLength(L);i++)
    {
        if(e==p->data)
            return i;
        else
            p=p->next;
    }
    if(j==FALSE)
        return ERROR;
}

Status ListInsert(LinkList *L,int i,ElemType e)
{
    if(ListLength(*L)<(i-1)|i<1)
        return ERROR;
    else
    {
        LinkList p=*L;
        int j=1;
        for(j=2;j<=i;j++)
        {
            p=p->next;
        }
        LinkList s;
        s=(LinkList)malloc(sizeof(Node));
        s->data=e;
        s->next=p->next;
        p->next=s;
        return OK;
    }
}

Status ListDelete(LinkList *L,int i,ElemType *e)
{
    if(i>ListLength(*L)|i<1)
        return ERROR;
    else
    {
        int j=1;
        LinkList p,q;
        p=*L;
        for(j=2;j<=i;j++)
        {
            p=p->next;
        }
        q=p->next;
        *e=q->data;
        p->next=q->next;
        free(q);
        return OK;
    }
}

int main()
{
    LinkList L;
    ElemType e;
    Status i;
    int j,k;

    i=InitList(&L);
    if(i==ERROR)
    {
        return 0;
    }

    for(j=1;j<=5;j++)
        i=ListInsert(&L,1,j);
    printf("在L的表头依次插入1～5后：L.data=");
    ListTraverse(L);

    printf("ListLength(L)=%d\n",ListLength(L));

    ClearList(&L);
    printf("\n清空L后：ListLength(L)=%d\n",ListLength(L));

    for(j=1;j<=10;j++)
        ListInsert(&L,j,j);
    printf("在L的表尾依次插入1～10后：L.data=");
    ListTraverse(L);

    printf("ListLength(L)=%d\n",ListLength(L));

    ListInsert(&L,1,0);
    printf("\n在L的表头插入0后：L.data=");
    ListTraverse(L);
    printf("ListLength(L)=%d\n",ListLength(L));

    GetElem(L,5,&e);
    printf("\n第5个元素的值为：%d\n",e);

    printf("\n");
    for(j=3;j<=4;j++)
    {
        k=LocateElem(L,j);
        if(k)
            printf("值为%d的元素在第%d个位置\n",j,k);
        else
            printf("没有值为%d的元素\n",j);
    }

    printf("\n");
    k=ListLength(L);
    for(j=k+1;j>=k;j--)
    {
        i=ListDelete(&L,j,&e);
        if(i==ERROR)
            printf("删除第%d个数据失败\n",j);
        else
            printf("删除的第%d个元素的值为%d后：L.data=",j,e);
    }
    ListTraverse(L);
    printf("Listlength(L)=%d \n",ListLength(L));

    int n,m;
    m=ListLength(L);
    for(j=1;j<10;j++)
    {
        if(j==2|j==3|j==6|j==7)
        {
            n=m-j+1;
            printf("测试%d",n);
            i=ListDelete(&L,n,&e);
        }
    }
    printf("删除表中倒数第2、3、6、7个元素后：L.data=");
    ListTraverse(L);

    return 0;
}
