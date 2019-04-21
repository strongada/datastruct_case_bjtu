#include "stdio.h"
#include "stdlib.h"

#define NOT_FOUND -1
#define MAXSIZE 100

typedef int Status;
typedef struct
{
    int r[MAXSIZE+1];
    int length;
}SqList;

void print(SqList L)
{
    int i;
    for(i=1;i<=L.length;i++)
        printf("%d",L.r[i]);
    printf("\n");
}

Status Sequentiao_Search(int *,int,int);
Status Binary_Search(int *,int,int);
Status Interpolation_Search(int *,int,int);

Status Sequential_Search(int *a,int n,int key)
{
    int i;
    for(i=1;i<=n;i++)
    {
        if(a[i]==key)
            return i;
    }
    return NOT_FOUND;
}

int Binary_Search(int *a,int n,int key)
{
    int low,high,mid;
    low=1;
    high=n;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(a[mid]<key)
            low=mid+1;
        else if(a[mid]>key)
            high=mid-1;
        else
            return mid;
    }
    return NOT_FOUND;
}

Status Interpolation_Search(int *a,int n,int key)
{
    int low,high,mid;
    low=1;
    high=n;
    while(low<=high)
    {
        mid=low+(high-low)*(key-a[low])/(a[high]-a[low]);
        if(a[mid]<key)
            low=mid+1;
        else if(a[mid]>key)
            high=mid-1;
        else
            return mid;
    }
    return NOT_FOUND;
}

int main()
{
    int a[MAXSIZE+1],i,result;
    int arr[MAXSIZE]={-1,0,1,16,24,35,47,59,62,73,88,99};

    for(i=1;i<=MAXSIZE;i++)
    {
        a[i]=i;
    }
    result=Sequential_Search(a,MAXSIZE,MAXSIZE);
    printf("Sequential_Search:%d\n",result);

    result=Binary_Search(arr,11,62);
    printf("Binary_Search:%d\n",result);

    result=Interpolation_Search(arr,11,62);
    printf("Interpolation_Search:%d\n",result);

    return 0;
}
