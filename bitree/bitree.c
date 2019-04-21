#include "string.h"
#include "stdio.h"
#include "stdlib.h"

#define OK 1
#define ERROR 0
#define MAXSIZE 100

typedef int Status;
typedef char TElemType;
typedef struct BiTNode
{
    TElemType data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;
typedef char String[MAXSIZE+1];

void InitBiTree(BiTree *T)
{
    *T=NULL;
}

Status StrAssign(String T,char *chars)
{
    int i;
    if(strlen(chars)>MAXSIZE)
        return ERROR;
    else
    {
        T[0]=strlen(chars);
        for(i=1;i<=T[0];i++)
            T[i]=*(chars+i-1);
        return OK;
    }
}

Status CreateBiTree(BiTree *T,char extension,String str,int* index)
{
    TElemType ch=str[(*index)++];
    
    if(ch==extension)
        *T=NULL;
    else
    {
        *T=(BiTree)malloc(sizeof(BiTNode));
        if(!*T)
            return ERROR;
        (*T)->data=ch;
        CreateBiTree(&(*T)->lchild,extension,str,index);
        CreateBiTree(&(*T)->rchild,extension,str,index);
    }
    return OK;
}

void DestroyBiTree(BiTree *T)
{
    if(*T)
    {
        if((*T)->lchild)
            DestroyBiTree(&(*T)->lchild);
        if((*T)->rchild)
            DestroyBiTree(&(*T)->rchild);
        free(*T);
        *T=NULL;
    }
}

void PreOrderTraverse(BiTree);
void InOrderTraverse(BiTree);
void PostOrderTraverse(BiTree);
int countLeaf(BiTree);

void PreOrderTraverse(BiTree T)
{
    if(T==NULL)
        return;
    printf("%c",T->data);
    PreOrderTraverse(T->lchild);
    PreOrderTraverse(T->rchild);
}

void InOrderTraverse(BiTree T)
{
    if(T==NULL)
        return;
    InOrderTraverse(T->lchild);
    printf("%c",T->data);
    InOrderTraverse(T->rchild);
}

void PostOrderTraverse(BiTree T)
{
    if(T==NULL)
        return;
    PostOrderTraverse(T->lchild);
    PostOrderTraverse(T->rchild);
    printf("%c",T->data);
}

int countLeaf(BiTree T)
{
    static int CF=0;
    if(T!=NULL)
    {
        CF=countLeaf(T->lchild);
        if(T->lchild==NULL&&T->rchild==NULL)
            CF=CF+1;
        CF=countLeaf(T->rchild);
    }
    return CF;
}

int main()
{
    BiTree T;
    String str;
    int Index=1;
    char extension='#';

    StrAssign(str,"ABDH#K###E##CFI###G#J##");
    InitBiTree(&T);
    CreateBiTree(&T,extension,str,&Index);

    printf("\n二叉树的叶子节点=%d",countLeaf(T));
    printf("\n前序遍历二叉树：");
    PreOrderTraverse(T);
    printf("\n中序遍历二叉树：");
    InOrderTraverse(T);
    printf("\n后序遍历二叉树：");
    PostOrderTraverse(T);
    printf("\n");
    DestroyBiTree(&T);
}
