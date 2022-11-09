#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;
typedef struct LNode
{
    ElemType data;
    struct LNode* next;
}LNode,*LinkList;
void PrintList(LinkList L)
{
	L = L->next;
	while (L != NULL)
	{
		printf("%3d", L->data);//打印当前结点数据
		L = L->next;//指向下一个结点
	}
	printf("\n");
}
LNode* LocateElem(LinkList L,ElemType e)
{
    LNode *p=L->next;
    while (p!=NULL&&p->data!=e)
    {
        p=p->next;
    }
    return p;
}
void List_TailInsert(LinkList &L)//正向建立单链表
{
    ElemType x;//设ElemType为整型
    L=(LinkList)malloc(sizeof(LNode));//建立头结点
    LNode *s,*r=L;//r为表尾指针
    scanf("%d",&x);//输入结点的值
    while (x!=9999)//输入9999表示结束
    {
        s=(LNode *)malloc(sizeof(LNode));
        s->data=x;
        r->next=s;
        r=s;//r指向新的表尾结点
        scanf("%d",&x);
    }
    r->next=NULL;//尾结点指针置空
}
int main()
{
    LinkList L;//链表头
    LinkList search;//储存拿到的结点
    List_TailInsert(L);
    PrintList(L);
    search=LocateElem(L,6);
    if (search!=NULL)
    {
        printf("%d",search->data);
    }
    
}