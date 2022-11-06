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
	L = L->next;
	while (L != NULL)
	{
		printf("%3d", L->data);//打印当前结点数据
		L = L->next;//指向下一个结点
	}
	printf("\n");
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
LinkList SerchList(LinkList L, int i)
{
	//找到第i节点即可输出
	int j = 1;//用来计数
	LNode* p = L->next;//用指针p进行遍历
	if (0 == i)
	{
		return L;//只有头节点
	}
	if (i<1)//位置不合法
	{
		return NULL;
	}
	//遍历寻找
	while (p != NULL && j < i)
	{
		p = p->next;
		j++;
	}
	return p;//返回第i个节点的指针
}

void InsertList(LinkList L, int i, ElemType e)
{
	//找到前一个位置，在其后面加入点
	LNode* p = SerchList(L, i - 1);
	LNode* s = (LinkList)malloc(sizeof(LNode));//为新节点申请空间
	s->data = e;
	s->next = p->next;
	p->next = s;
}
void DeleteList(LinkList L, int i)
{
	//找到第i-1个节点，然后删除第i个节点0
	LNode* p = SerchList(L, i - 1);
	LNode* s = p->next;//指针s指向要被删除的第i个节点
	p->next = s->next;//断链
    free(s);//释放后继结点的存储空间
}
int main()
{
	LinkList L;

	//尾插法创建链表
	List_TailInsert(L);
	LinkList answer;//存储查找的返回值

	//查找第二个位置的值并输出
	answer = SerchList(L, 2);
	if (answer != NULL)
	{
		printf("%d\n", answer->data);
	}

	//在2个位置插入99
	InsertList(L, 2, 99);
	PrintList(L);
	//删除第4个位置的值
	DeleteList(L, 4);
	PrintList(L);
	return 0;
}