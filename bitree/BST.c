#include "stdio.h"
#include "stdlib.h"

#define TRUE 1
#define FALSE 0

typedef int Status;
typedef struct BiTNode
{
    int data;
    struct BiTNode *lchild,*rchild;
}BiNode,*BiTree;

void InOrderTraverse(BiTree T)
{
    if(T==NULL)
        return;
    InOrderTraverse(T->lchild);
    printf("%d",T->data);
    InOrderTraverse(T->rchild);
}

Status SearchBST(BiTree T,int key,BiTree f,BiTree *p)
{
    if(!T)
    {
        *p=f;
        return FALSE;
    }
    else if(key==T->data)
    {
        *p=T;
        return TRUE;
    }
    else if(key<T->data)
        return SearchBST(T->lchild,key,T,&(*p));
    else
        return SearchBST(T->rchild,key,T,&(*p));
}

Status Delete1(BiTree *p)
{

    BiTree q,s;
    if((*p)->rchild==NULL)
    {
        q=*p;
        *p=(*p)->lchild;
        free(*p);
    }
    else if((*p)->lchild==NULL)
    {
        q=*p;
        *p=(*p)->rchild;
        free(*p);
    }
    else
    {
        q=*p;
        *p=(*p)->lchild;
        s=*p;
        while(s->rchild)
        {
            s=s->rchild;
        }
        s->rchild=q->rchild;
        free(q);
    }
}

Status DeleteBST1(BiTree *T,int key)
{
    if(!*T)
        return FALSE;
    else
    {
        if(key==(*T)->data)
            return Delete1(T);
        else if(key<(*T)->data)
            return DeleteBST1(&(*T)->lchild,key);
        else
            return DeleteBST1(&(*T)->rchild,key);
    }
}

Status Delete2(BiTree *p)
{
    BiTree q,s;
    if((*p)->rchild==NULL)
    {
        q=*p;
        *p=(*p)->lchild;
        free(*p);
    }
    else if((*p)->lchild==NULL)
    {
        q=*p;
        *p=(*p)->rchild;
        free(*p);
    }
    else
    {
        q=*p;
        s=(*p)->rchild;
        while(s->lchild)
        {
            q=s;
            s=s->lchild;
        }
        (*p)->data=s->data;
        if(q!=*p)
            q->lchild=s->rchild;
        else
            q->lchild=s->rchild;
        free(s);
    }
    return TRUE;
}

Status DeleteBST2(BiTree *T,int key)
{
    if(!*T)
        return FALSE;
    else
    {
        if(key==(*T)->data)
            return Delete2(T);
        else if(key<(*T)->data)
            return DeleteBST2(&(*T)->lchild,key);
        else
            return DeleteBST2(&(*T)->rchild,key);
    }
}

Status Delete3(BiTree *p)
{
    BiTree q,s;
    if((*p)->rchild==NULL)
    {
        q=*p;
        *p=(*p)->lchild;
        free(*p);
    }
    else if((*p)->lchild==NULL)
    {
        q=*p;
        *p=(*p)->rchild;
        free(*p);
    }
    else
    {
        q=*p;
        s=(*p)->lchild;
        while(s->rchild)
        {
            q=s;
            s=s->rchild;
        }
        (*p)->data=s->data;
        if(q!=*p)
            q->rchild=s->lchild;
        else
            q->lchild=s->lchild;
        free(s);
    }
    return TRUE;
}

Status DeleteBST3(BiTree *T,int key)
{
    if(!*T)
        return FALSE;
    else
    {
        if(key==(*T)->data)
            return Delete3(T);
        else if(key<(*T)->data)
            return DeleteBST3(&(*T)->lchild,key);
        else
            return DeleteBST3(&(*T)->rchild,key);
    }
}

Status InsertBST(BiTree *T,int key)
{
    BiTree p,s;
    if(!SearchBST(*T,key,NULL,&p))
    {
        s=(BiTree)malloc(sizeof(BiTree));
        s->data=key;
        s->lchild=s->rchild=NULL;
        if(!p)
            *T=s;
        else if(key<p->data)
            p->lchild=s;
        else
            p->rchild=s;
        return TRUE;
    }
    else
        return FALSE;
}

int main(void)
{
    int i;
    int a[11]={62,88,58,47,35,73,51,99,37,93,49};
    BiTree T1=NULL,T2=NULL,T3=NULL;

    for(i=0;i<11;i++)
    {
        InsertBST(&T1,a[i]);
        InsertBST(&T2,a[i]);
        InsertBST(&T3,a[i]);
        InOrderTraverse(T1);
        printf("\n");
    }

    DeleteBST1(&T1,93);
    InOrderTraverse(T1);
    printf("\n");

    DeleteBST1(&T1,47);
    InOrderTraverse(T1);
    printf("\n");

    DeleteBST2(&T2,93);
    InOrderTraverse(T2);
    printf("\n");
    
    DeleteBST2(&T2,47);
    InOrderTraverse(T2);
    printf("\n");

    DeleteBST3(&T3,93);
    InOrderTraverse(T3);
    printf("\n");

    DeleteBST3(&T3,47);
    InOrderTraverse(T3);
    printf("\n");

    return 0;
}
