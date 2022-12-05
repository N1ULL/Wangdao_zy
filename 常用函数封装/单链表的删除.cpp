#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;
typedef struct LNode 
{
	ElemType data;
	struct LNode *next;//指向下一个结点
}LNode,*LinkList;
//头插法建立链表
LinkList list_tail_insert(LinkList& L)
{
    LNode* s;
    ElemType x;
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    scanf("%d", &x);
    while (x != -1)
    {
        s = (LNode*)malloc(sizeof(LNode));
        s->data = x;
        s->next = L->next;
        L->next = s;
        scanf("%d", &x);
    }
    return L;
}
//打印链表
void print_list(LinkList L)
{
    L = L->next;
    while (L != NULL)
    {
        printf("%3d", L->data);

        L = L->next;
    }
    printf("\n");
}
//按序号查找
LNode* GetElem(LinkList L, int i)
{
    int j = 1;
    LNode* p = L->next;
    if (i==0)
    {
        return L;
    }
    if (j<1)
    {
        return NULL;
    }
    while (p&&j<i)
    {
        p = p->next;
        j++;
    }
    return p;
}
//删除第i个结点
bool ListDelete(LinkList L, int i)
{
    LinkList p = GetElem(L, i - 1);
    if (NULL==p)
    {
        return false;
    }
    LinkList q;
    q = p->next;
    p->next = q->next;//断链
    free(q);
    return true;
}
int main()
{
	LinkList L;
	list_tail_insert(L);
    print_list(L);
    ListDelete(L, 4);
    print_list(L);
    return 0;
}