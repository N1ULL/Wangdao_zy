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
	struct LinkNode* next;
}LinkNode;

typedef struct
{
	LinkNode* front, * rear;
}LinkQueue;
void InitQueue(LinkQueue& Q);
bool IsEmpty(LinkQueue Q);
void EnQueue(LinkQueue& Q, ElemType x);
bool DeQueue(LinkQueue& Q, ElemType& x);
