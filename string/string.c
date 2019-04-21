#include "string.h"
#include "stdio.h"
#include "stdlib.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 100

typedef int Status;
typedef char String[MAXSIZE+1];

void StrPrint(String T)
{
    int i;
    for(i=1;i<=T[0];i++)
        printf("%c",T[i]);
    printf("\n");        
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

int StrCompare(String S,String T)
{
    int i;
    for(i=1;i<=S[0]&&i<=T[0];++i)
        if(S[i]!=T[i])
            return S[i]-T[i];

    return S[0]-T[0];
}

int StrLength(String S)
{
    return S[0];
}

Status SubString(String Sub,String S,int pos,int len)
{
    int i;
    if(pos<1||pos>S[0]||len<0||len>S[0]-pos+1)
        return ERROR;
    for(i=1;i<=len;i++)
        Sub[i]=S[pos+i-1];
    Sub[0]=len;

    return OK;
}

Status StrEmpty(String S)
{
    if(S[0]==0)
        return TRUE;
    else
        return FALSE;
}

void ClearString(String S)
{
    S[0]=0;
}

Status Concat(String,String,String);
Status StrInsert(String,int,String);
Status StrDelete(String,int,int);
int Index(String,String,int);
Status Replace(String,String,String);

Status Concat(String T,String S1,String S2)
{
    int i;
    if(StrLength(S1)+StrLength(S2)<=MAXSIZE)
    {
        for(i=1;i<=StrLength(S1);i++)
        {
            T[i]=S1[i];
        }
        for(i=1;i<=StrLength(S2);i++)
        {
            T[i+StrLength(S1)]=S2[i];
        }
        T[0]=S1[0]+S2[0];
        return OK;
    }
    else
    {
        for(i=1;i<=StrLength(S1)&&i<=MAXSIZE-1;i++)
        {
            T[i]=S1[i];
        }
        for(i=1;i<=StrLength(S2)&&(i+StrLength(S1))<=MAXSIZE-1;i++)
        {
            T[i+StrLength(S1)]=S2[i];
        }
        T[0]=MAXSIZE-1;
        return ERROR;
    }
}

Status StrInsert(String S,int pos,String T)
{
    int i;
    if(StrLength(S)+StrLength(T)<=MAXSIZE)
    {
        for(i=StrLength(S);i>=pos;i--)
        {
            S[i+StrLength(T)]=S[i];
        }
        for(i=1;i<=StrLength(T);i++)
        {
            S[i+pos-1]=T[i];
        }
        S[0]=StrLength(S)+StrLength(T);
        return OK;
    }
    else
    {
        for(i=MAXSIZE;MAXSIZE>pos+StrLength(T)-1&&i>=StrLength(T)+pos;i--)
        {
            S[i]=S[i-StrLength(T)];
        }
        for(i=1;i<=StrLength(T)&&i+pos-1<=MAXSIZE;i++)
        {
            S[i+pos-1]=T[i];
        }
        S[0]=MAXSIZE;
        return ERROR;
    }
}

Status StrDelete(String S,int pos,int len)
{
    if(pos<1||len<0||pos+len-1>MAXSIZE)
        return ERROR;
    else
    {
        
        int i;
        for(i=pos;i<=StrLength(S)-len;i++)
        {
            S[i]=S[i+len];
        }
        S[0]=StrLength(S)-len;
        return OK;
    }
}

int Index(String S,String T,int pos)
{
    int i,j,m,k;
    if(pos<1)
        return ERROR;
    else
    {
        for(m=pos;m<=(StrLength(S)-StrLength(T)+1);m++)
        {
            k=TRUE;
            for(j=1;j<=StrLength(T);j++)
            {
                i=j+m-1;
                if(S[i]!=T[j])
                {
                    k=FALSE;
                    break;
                }
            }
            if(k==TRUE)
            {
                return m;
            }
        }
        return ERROR;
    }
}

Status Replace(String S,String T,String V)
{
    if(StrLength(T)==0||StrLength(S)-StrLength(T)+StrLength(V)>MAXSIZE)
        return ERROR;
    else
    {
        int m=Index(S,T,1);
        if(m>=1)
        {
            StrDelete(S,m,StrLength(T));
            StrInsert(S,m,V);
            return OK;
        }
    }
}

int main()
{
    int i,j;
    String t1,t2,s,t,s1,s2;

    StrAssign(s,"abcdefgxyzabcdefgh");
    StrAssign(t1,"abcdefgh");
    StrAssign(t2,"fgxy");

    printf("串S为：");
    StrPrint(s);

    i=Index(s,t1,1);
    printf("S的第%d个字母起和t1第一次匹配\n",i);
    printf("串t1为：");
    StrPrint(t1);

    j=Index(s,t2,1);
    printf("S的第%d个字母起和t2第一次匹配\n",j);
    printf("串t2为：");
    StrPrint(t2);


    Status k;
    char c;
    printf("请输入串s1:");

    k=StrAssign(s1,"abcd");
    if(!k)
    {
        printf("串长超过MAXSIZE(=%d)\n",MAXSIZE);
        exit(0);
    }
    printf("串长为%d串空否？%d(1:是 2:否)\n",StrLength(s1),StrEmpty(s1));
    printf("请输入串s2:");

    k=StrAssign(s2,"efghijk");
    if(!k)
    {
        printf("串长超过MAXSIZE(=%d)\n",MAXSIZE);
        exit(0);
    }
    i=StrCompare(s1,s2);
    if(i<1)
        c='<';
    else if(i==0)
        c='=';
    else
        c='>';
    printf("串s1%c串 s2\n",c);
    k=Concat(t,s1,s2);
    printf("串s1联接串s2得到的串t为：");
    StrPrint(t);
    if(k==FALSE)
        printf("串t有截断\n");
    ClearString(s1);
    printf("清为空串后，串s1为：");
    StrPrint(s1);
    printf("串长为%d串空否？%d(1:是 2:否)\n",StrLength(s1),StrEmpty(s1));
    printf("求串t的子串，请输入子串的起始位置，子串长度：");

    i=2;
    j=3;
    printf("%d,%d\n",i,j);

    k=SubString(s2,t,i,j);
    if(k)
    {
        printf("子串s2为：");
        StrPrint(s2);
    }
    StrPrint(t);
    printf("从串t的第pos个字符起，删除len个字符，请输入pos,len:");

    i=4;
    j=2;
    printf("%d,%d\n",i,j);

    StrDelete(t,i,j);
    printf("删除后的串t为：");
    StrPrint(t);
    i=StrLength(s2)/2;
    StrInsert(s2,i,t);
    printf("在串s2的第%d个字符之前插入串t后，串s2为：\n",i);
    StrPrint(s2);
    i=Index(s2,t,1);
    printf("s2的第%d个字母起和t第一次匹配\n",i);
    SubString(t,s2,1,1);
    printf("串t为：");
    StrPrint(t);
    Concat(s1,t,t);
    printf("串s1为：");
    StrPrint(s1);
    Replace(s2,t,s1);
    printf("用串s1取代串s2中和串t相同的不重叠的串后，串s2为：");
    StrPrint(s2);

    return 0;
}
