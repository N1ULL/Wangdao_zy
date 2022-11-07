#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;
typedef struct LNode
{
    ElemType data;
    struct LNode* next;
}LNode,*LinkList;
void List_TailInsert(LinkList &L)
{
    LNode *s;
    ElemType x;
    L=(LinkList)malloc(sizeof(LNode));
    LNode *r=L;
    scanf("%d",&x);
    while (x!=-1)
    {
        s=(LinkList)malloc(sizeof(LNode));
        s->data=x;
        r->next=s;
        r=s;
        scanf("%d",&x);
    }
    r->next=NULL;
}
void PrintList(LinkList L)
{
    L=L->next;
    while (L!=NULL)
    {
        printf("%d",L->data);

        L=L->next;

        if (L!=NULL)
        {
            printf(" ");
        }
        
    }
    printf("\n");
}
int main()
{
    LinkList L;
    List_TailInsert(L);
    PrintList(L);
    return 0;
}