#include<stdio.h>

#define MaxSize 5
typedef int ElemType;
typedef struct
{
    ElemType data[MaxSize];
    int length;//当前顺序表中有几个元素
}SqList;
//i
bool ListInsert(SqList &L,int i,ElemType e)
{
    if (i<1||i>L.length+1)//判断要插入的位置是否合法
    {
        return false;
    }
    if (L.length>=MaxSize)//超出空间
    {
        return false;
    }
    for (int j = L.length; j >= i; j--)
    {
        L.data[j]=L.data[j-1];
    }
    L.data[i-1]=e;
    L.length+=1;
    return true;
}
void PrintList(SqList L)
{
    for (int i = 0; i < L.length; i++)
    {
        printf("%3d",L.data[i]);
    }
    printf("\n");
}
bool ListDelete(SqList &L,int i)
{
    if (i<1||i>L.length+1)//判断要插入的位置是否合法
    {
        return false;
    }
    for (int j = i; j < L.length; j++)
    {
        L.data[j-1]=L.data[j];
    }
    L.length-=1;
    return true;
}
int main()
{
    SqList L;
    L.data[0] = {1};
    L.data[1] = {2};
    L.data[2] = {3};
    L.length = 3;

    ElemType n;
    scanf("%d",&n);

    int List;
    List=ListInsert(L,2,n);
    if (List)
    {
        PrintList(L);
    }
    else
    {
        return false;
    }
    int m;
    scanf("%d",&m);

    List = ListDelete(L,m);
    if (List)
    {
        PrintList(L);
    }
    else
    {
        printf("false");
        return false;
    }
    return 0;
}