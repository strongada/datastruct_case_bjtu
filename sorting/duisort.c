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

void HeapAdjust0(SqList *L,int s,int m)
{
    int temp,j;
    temp=L->r[s];
    for(j=2*s;j<=m;j*=2)
    {
        if(j<m&&L->r[j]<L->r[j+1])
            ++j;
        if(temp>L->r[j])
            break;
        L->r[s]=L->r[j];
        s=j;
    }
    L->r[s]=temp;
}

void HeapSort0(SqList *L)
{
    int i;
    for(i=L->length/2;i>0;i--)
        HeapAdjust0(L,i,L->length);
    for(i=L->length;i>1;i--)
    {
        swap(L,1,i);
        HeapAdjust0(L,1,i-1);
    }
}

void HeapAdjust1(SqList *L,int s,int m)
{
    int j=2*s;
    while(s<=m/2)
    {
        if(j<m&&L->r[j]<L->r[j+1])
            j++;
        if(L->r[j]>L->r[s])
        {
            swap(L,s,j);
            HeapAdjust1(L,j,m);
        }
        else
            break;
    }
}

void HeapStep(SqList *L,int s)
{
    if(s>1)
    {
        swap(L,1,s);
        HeapAdjust1(L,1,s-1);
        s--;
        HeapStep(L,s);
    }
}

void HeapSort1(SqList *L)
{
    int i;
    printf("length:%d\n",L->length);
    for(i=L->length/2;i>0;i--)
        HeapAdjust1(L,i,L->length);
    HeapStep(L,L->length);
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
    SqList list0,list1,list2;
    
    printf("请输入乱序数串的长度\n");
    scanf("%d", &N);
    for(i=0; i<N; i++)
    {
        printf("请输入乱序数串中的第%d个数\n", i+1);
        scanf("%d", &list0.r[i+1]);
    }
    list0.length=N;
    list1=list0;

    printf("排序前:\n");
    print(list0);
    printf("堆排序:\n");
    HeapSort0(&list0);
    print(list0);
    showcheck(&list0);
    printf("堆排序（递归）:\n");
    HeapSort1(&list1);
    print(list1);
    showcheck(&list1);

    return 0;

}
