#include <stdio.h>
#include <stdlib.h>
typedef char BiElemType;
typedef struct BiTNode
{
	BiElemType c;
	struct BiTNode* lchild;
	struct BiTNode* rchild;
}BiTNode, * BiTree;
typedef struct tag
{
	BiTree p;
	struct tag* pnext;
}tag_t, * ptag_t;

typedef BiTree ElemType;
typedef struct LinkNode
{
	ElemType data;
	struct LinkNode *next;
}LinkNode;

typedef struct
{
	LinkNode *front, *rear;
}LinkQueue;

void InitQueue(LinkQueue& Q)
{
	Q.front = Q.rear = (LinkNode*)malloc(sizeof(LinkNode));
	Q.front->next = NULL;
}
bool IsEmpty(LinkQueue Q)
{
	if (Q.front == Q.rear)
		return true;
	else
		return false;
}
void EnQueue(LinkQueue& Q, ElemType x)
{
	LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
	s->data = x; s->next = NULL;
	Q.rear->next = s;
	Q.rear = s;
}
bool DeQueue(LinkQueue& Q, ElemType& x)
{
	if (Q.front == Q.rear) return false;
	LinkNode* p = Q.front->next;
	x = p->data;
	Q.front->next = p->next;
	if (Q.rear == p)
		Q.rear = Q.front;
	free(p);
	return true;
}

void InOrder(BiTree p)
{
	if (p!=NULL)
	{
		InOrder(p->lchild);
		putchar(p->c);
		InOrder(p->rchild);
	}
}

void PostOrder(BiTree p)
{
	if (p != NULL)
	{
		PostOrder(p->lchild);
		PostOrder(p->rchild);
		putchar(p->c);
	}
}
void LevelOrder(BiTree T)
{
	LinkQueue Q;//辅助队列
	InitQueue(Q);//初始化队列
	BiTree p;
	EnQueue(Q, T);//树根入队
	while (!IsEmpty(Q))
	{
		DeQueue(Q, p);//出队当前结点并打印
		putchar(p->c);
		if (p->lchild != NULL) //入队左孩子
			EnQueue(Q, p->lchild);
		if (p->rchild != NULL)
		{
			EnQueue(Q, p->rchild);
		}
	}
}
int main()
{
	BiTree pnew;
	char c;
	BiTree tree = NULL;
	ptag_t phead = NULL, ptail = NULL, listpnew = NULL, pcur = NULL;
	while (scanf("%c",&c))
	{
		if (c == '\n')
		{
			break;
		}
		pnew = (BiTree)calloc(1, sizeof(BiTNode));
		pnew->c = c;
		listpnew = (ptag_t)calloc(1, sizeof(tag_t));
		listpnew->p = pnew;
		if (NULL==tree)
		{
			tree = pnew;
			phead = listpnew;
			ptail = listpnew;
			pcur = listpnew;
			continue;
		}
		else
		{
			ptail->pnext = listpnew;
			ptail = listpnew;
		}
		if (NULL == pcur->p->lchild)
		{
			pcur->p->lchild = pnew;
		}
		else if (NULL == pcur->p->rchild)
		{
			pcur->p->rchild = pnew;
			pcur = pcur->pnext;
		}
	}
	InOrder(tree);
	printf("\n");
	PostOrder(tree);
	printf("\n");
	LevelOrder(tree);
	return 0;
}