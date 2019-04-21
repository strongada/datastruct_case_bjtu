#include "stdio.h"
#include "stdlib.h"

#define TRUE 1
#define FALSE 0

#define LH +1
#define EH 0
#define RH -1

typedef int Status;
typedef struct BiTNode
{
    int data;
    int bf;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

void InOrderTraverse(BiTree T)
{
    if(T==NULL)
        return;
        InOrderTraverse(T->lchild);
        printf("%d_",T->data);
        InOrderTraverse(T->rchild);
}

void PreOrderTraverse(BiTree T,int member)
{
    if(T==NULL)
        return;
    switch(member)
    {
        case 1:
            printf("%d~",T->data);
            break;
        case 2:
            printf("%d,",T->bf);
            break;
        default:
            printf("wrong member:%d\n",member);
            break;
    }
    PreOrderTraverse(T->lchild,member);
    PreOrderTraverse(T->rchild,member);
}

void R_Rotate(BiTree *p)
{
    BiTree L;
    L=(*p)->lchild;
    (*p)->lchild=L->rchild;
    L->rchild=(*p);
    (*p)=L;
}

void L_Rotate(BiTree *p)
{
    BiTree R;
    R=(*p)->rchild;
    (*p)->rchild=R->lchild;
    R->lchild=(*p);
    (*p)=R;
}

void RightBalance(BiTree *T)
{
    BiTree R,Rl;
    R=(*T)->rchild;
    switch(R->bf)
    {
        case RH:
            (*T)->bf=R->bf=EH;
            L_Rotate(T);
            break;
        case LH:
            Rl=R->lchild;
            switch(Rl->bf)
            {
                case RH:
                    (*T)->bf=LH;
                    R->bf=EH;
                    break;
                case EH:
                    (*T)->bf=R->bf=EH;
                    break;
                case LH:
                    (*T)->bf=EH;
                    R->bf=RH;
                    break;
            }
            Rl->bf=EH;
            R_Rotate(&(*T)->rchild);
            L_Rotate(T);
    }
}

void LeftBalance(BiTree *T)
{
    BiTree L,Lr;
    L=(*T)->lchild;
    switch(L->bf)
    {
        case LH:
            (*T)->bf=L->bf=EH;
            R_Rotate(T);
            break;
        case RH:
            Lr=L->rchild;
            switch(Lr->bf)
            {
                case LH:
                    (*T)->bf=RH;
                    L->bf=EH;
                    break;
                case EH:
                    (*T)->bf=L->bf=EH;
                    break;
                case RH:
                    (*T)->bf=EH;
                    L->bf=LH;
                    break;
            }
            Lr->bf=EH;
            L_Rotate(&(*T)->lchild);
            R_Rotate(T);
    }
}

Status InsertAVL(BiTree *T,int e,Status *taller)
{
    if(!*T)
    {
        *T=(BiTree)malloc(sizeof(BiTNode));
        (*T)->data=e;
        (*T)->lchild=(*T)->rchild=NULL;
        (*T)->bf=EH;
        *taller=TRUE;
    }
    else
    {
        if(e==(*T)->data)
        {
            *taller=FALSE;
            return FALSE;
        }
        if(e<(*T)->data)
        {
            if(!InsertAVL(&(*T)->lchild,e,taller))
                return FALSE;
            if(*taller)
                switch((*T)->bf)
                {
                    case LH:
                        LeftBalance(T);
                        *taller=FALSE;
                        break;
                    case EH:
                        (*T)->bf=LH;
                        *taller=TRUE;
                        break;
                    case RH:
                        (*T)->bf=EH;
                        *taller=FALSE;
                        break;
                }
        }
        else
        {
            if(!InsertAVL(&(*T)->rchild,e,taller))
                return FALSE;
            if(*taller)
            {
                switch((*T)->bf)
                {
                    case LH:
                        (*T)->bf=EH;
                        *taller=FALSE;
                        break;
                    case EH:
                        (*T)->bf=RH;
                        *taller=TRUE;
                        break;
                    case RH:
                        RightBalance(T);
                        *taller=FALSE;
                        break;
                }
            }
        }
    }
    return TRUE;
}

int main(void)
{
    int i;
    int a[18]={3,2,1,4,5,6,7,62,88,58,47,35,73,51,99,37,93,49};
    BiTree T=NULL;
    Status taller;

    for(i=0;i<18;i++)
    {
        InsertAVL(&T,a[i],&taller);
        printf("中序遍历AVL:\n");
        InOrderTraverse(T);
        printf("\n");

        printf("前序遍历AVL:\n");
        PreOrderTraverse(T,1);
        printf("\n");

        printf("前序遍历AVL的bf:\n");
        PreOrderTraverse(T,2);
        printf("\n");
        printf("\n");
    }

    R_Rotate(&T);
    printf("R旋1次之后的中序遍历AVL:\n");
    InOrderTraverse(T);
    printf("\n");
    printf("R旋1次之后的前序遍历AVL:\n");
    PreOrderTraverse(T,1);
    printf("\n");

    R_Rotate(&T);
    printf("R旋2次之后的中序遍历AVL:\n");
    InOrderTraverse(T);
    printf("\n");
    printf("R旋2次之后的前序遍历AVL:\n");
    PreOrderTraverse(T,1);
    printf("\n");

    L_Rotate(&T);
    L_Rotate(&T);
    L_Rotate(&T);
    printf("L旋1次之后的中序遍历AVL:\n");
    InOrderTraverse(T);
    printf("\n");
    printf("L旋1次之后的前序遍历AVL:\n");
    PreOrderTraverse(T,1);
    printf("\n");

    L_Rotate(&T);
    printf("L旋2次之后的中序遍历AVL:\n");
    InOrderTraverse(T);
    printf("\n");
    printf("L旋2次之后的前序遍历AVL:\n");
    PreOrderTraverse(T,1);
    printf("\n");

    return 0;
}

