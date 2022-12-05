#include"funcation.h"

//递归实现
//abdecfg 前序遍历，前序遍历就是深度优先遍历
void PreOrder(BiTree p)
{
	if (p != NULL)
	{
		putchar(p->c);
		PreOrder(p->lchild);
		PreOrder(p->rchild);
	}
}
//dbeafcg 中序遍历
void InOrder(BiTree p)
{
	if (p != NULL)
	{
		InOrder(p->lchild);
		putchar(p->c);
		InOrder(p->rchild);
	}
}
//debfgca 后序遍历
void PostOrder(BiTree p)
{
	if (p != NULL)
	{
		PostOrder(p->lchild);
		PostOrder(p->rchild);
		putchar(p->c);
	}
}
int main()
{
	BiTree pnew;
	char c;
	BiTree tree = NULL;
	ptag_t phead = NULL, ptail = NULL, listpnew = NULL, pcur = NULL;
	while (scanf("%c", &c))
	{
		if (c == '\n')
		{
			break;
		}
		pnew = (BiTree)calloc(1, sizeof(BiTNode));
		pnew->c = c;
		listpnew = (ptag_t)calloc(1, sizeof(tag_t));
		listpnew->p = pnew;
		if (NULL == tree)
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
	printf("----PreOrder----\n");
	PreOrder(tree);
	printf("\n----InOrder----\n");
	InOrder(tree);
	printf("\n----PostOrder----\n");
	PostOrder(tree);
	return 0;
}
