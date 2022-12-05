#include "function.h"
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
	BiTree pnew;//用来指向新申请的树结点
	char c;
	BiTree tree = NULL;//树根
	//phead 就是队列头，ptail 就是队列尾
	ptag_t phead = NULL, ptail = NULL, listpnew = NULL, pcur = NULL;
	//输入内容为 abcdefghij
	while (scanf("%c", &c))
	{
		if (c == '\n')
		{
			break;
		}
		pnew = (BiTree)calloc(1, sizeof(BiTNode));//calloc 申请空间并对空间进行初始化，赋值为 0
		pnew->c = c;//数据放进去
		listpnew = (ptag_t)calloc(1, sizeof(tag_t));//给队列结点申请空间
		listpnew->p = pnew;
		if (NULL == tree)
		{
			tree = pnew;//树的根
			phead = listpnew;//队列头
			ptail = listpnew;//队列尾
			pcur = listpnew;
			continue;
		}
		else {
			ptail->pnext = listpnew;//新结点放入链表，通过尾插法
			ptail = listpnew;//ptail 指向队列尾部
		}//pcur 始终指向要插入的结点的位置
		if (NULL == pcur->p->lchild)//如何把新结点放入树
		{
			pcur->p->lchild = pnew;//把新结点放到要插入结点的左边
		}
		else if (NULL == pcur->p->rchild)
		{
			pcur->p->rchild = pnew;//把新结点放到要插入结点的右边
			pcur = pcur->pnext;//左右都放了结点后，pcur 指向队列的下一个
		}
	}
	printf("--------层次遍历-----------\n");
	LevelOrder(tree);
	return 0;
}
