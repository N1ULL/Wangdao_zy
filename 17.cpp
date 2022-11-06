#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;
typedef struct LNode
{
	ElemType data;//数据域
	struct LNode* next;//指针域
}LNode, *LinkList;//结构体类型，结构体指针类型

void PrintList(LinkList L)

{
    
    L=L->next;
    
    while(L!=NULL)
    {
        
        printf("%d",L->data);//打印当前结点数据
        
        L=L->next;//指向下一个结点

        if(L!=NULL)
        {
            printf(" ");
        }
        
    }
    
    printf("\n");

}
void List_HeadInsert(LinkList &L)//正向建立单链表
{
    LNode *s;
    ElemType x;
    L=(LinkList)malloc(sizeof(LNode));//建立头结点
    L->next=NULL;//初始值为空链表
    scanf("%d",&x);//输入结点的值
    while (x!=9999)//输入9999表示结束
    {
        s=(LNode *)malloc(sizeof(LNode));//创建新结点
        s->data=x;
        s->next=L->next;
        L->next=s;//将新结点插入表中，L为头指针
        scanf("%d",&x);
    }
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
    LinkList L;
    List_HeadInsert(L);
    PrintList(L);
    List_TailInsert(L);
    PrintList(L);
    return 0;
}