#include<stdio.h>
#include<string.h>
#define OUTPUT_INTERMEDIATE_RESULT
#define TRUE 1
#define FALSE 0
#define MAXSIZE 10000
typedef int Status;  
typedef struct 
{  
     int r[MAXSIZE+1];
     int length;
}SqList;

void swap(SqList *L,int i,int j)
{
    int temp=L->r[i];
    L->r[i]=L->r[j];
    L->r[j]=temp;
}

void print(SqList L)
{
    int i;
    for(i=1;i<L.length;i++)
        printf("%d,",L.r[i]);
    printf("%d,",L.r[i]);
    printf("\n");
}

void Sort0(SqList *L)
{
    int i,j,a;
    for(i=1;i<L->length;i++)
    {
        for(j=i+1;j<=L->length;j++)
       {
            if(L->r[i]>L->r[j])
            {
                swap(L,i,j);
            }
        }
    }
}

void Sort1(SqList *L)
{
    int i,j;
    for(i=1;i<L->length;i++)
    {
        for(j=L->length-1;j>=i;j--)
        {
            if(L->r[j]>L->r[j+1])
            {
                swap(L,j,j+1);
            }
        }
    }
}

void Sort2(SqList *L)
{
    int i,j;
    Status flag=TRUE;
    for(i=1;i<L->length&&flag==TRUE;i++)
    {   
        flag=FALSE;
        for(j=L->length-1;j>=i;j--)
        {
            if(L->r[j]>L->r[j+1])
            {
                swap(L,j,j+1);
                flag=TRUE;
            }
        }
    }
}

void Sort3(SqList *L)
{
    int i,j,min;
    for(i=1;i<L->length;i++)
    {   
        min=i;
        for(j=i+1;j<=L->length;j++)
        {
            if(L->r[min]>L->r[j])
            {
                min=j;
            }
        }
        if(i!=min)
        {
            swap(L,i,min);
        }
    }
}

void Sort4(SqList *L)
{
    int i,j,k=0;
    int increment=L->length;
    do
    {
        increment=increment/3+1;
        for(i=increment+1;i<=L->length;i++)
        {
            if(L->r[i]<L->r[i-increment])
            {
                L->r[0]=L->r[i];
                for(j=i-increment;j>0&&L->r[0]<L->r[j];j-=increment)
                    L->r[j+increment]=L->r[j];
                L->r[j+increment]=L->r[0];
            }
        }
    }
    while(increment>1);
}

int check(SqList *L)
{
    int i,j;
    j=1;
    for(i=1;i<L->length;i++)
    {
        if(L->r[i]>L->r[i+1])
            j=0;
    }
    return j;
}

void showcheck(SqList *L)
{
if(check(L))
    printf("该算法正确\n\n");
else
    printf("该算法错误\n\n");
}


int main()
{   
    int i, N;
    SqList list0,list1,list2,list3,list4;
    
    printf("请输入乱序数串的长度\n");
    scanf("%d", &N);
    for(i=0; i<N; i++)
    {
        printf("请输入乱序数串中的第%d个数\n", i+1);
        scanf("%d", &list0.r[i+1]);
    }
    list0.length=N;
    list1=list2=list3=list4=list0;

    printf("排序前:\n");
    print(list0);
    printf("基本排序:\n");
    Sort0(&list0);
    print(list0);
    showcheck(&list0);
    printf("冒泡排序:\n");
    Sort1(&list1);
    print(list1);
    showcheck(&list1);
    printf("带判停条件的冒泡排序:\n");
    Sort2(&list2);
    print(list2);
    showcheck(&list2);
    printf("选择排序:\n");
    Sort3(&list3);
    print(list3);
    showcheck(&list3);
    printf("希尔排序:\n");
    Sort4(&list4);
    print(list4);
    showcheck(&list4);

    return 0;

}
