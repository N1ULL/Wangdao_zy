#include<stdio.h>
#include<stdlib.h>

typedef int KeyType;
typedef struct BSTNode
{
	KeyType key;
	struct BSTNode *lchild,*rchild;//存储动态数组里的元素的个数
}BSTNode,*BiTree;

int BST_Insert(BiTree& T, KeyType k)
{
	if (NULL==T)
	{
		T = (BiTree)malloc(sizeof(BSTNode));
		T->key = k;
		T->lchild = T->rchild = NULL;
		return 1;
	}
	BiTree p = T, parent;
	while (p)
	{
		parent = p;
		if (k==p->key)
		{
			return 0;
		}
		else if (k<p->key)
		{
			p = p->lchild;
		}
		else
		{
			p = p->rchild;
		}
	}
	BiTree pnew = (BiTree)malloc(sizeof(BSTNode));
	pnew->key = k;
	pnew->lchild = pnew->rchild = NULL;
	if (k>parent->key)
	{
		parent->rchild = pnew;
	}
	else
	{
		parent->lchild = pnew;
	}
}

void Creat_BST(BiTree& T, KeyType str[], int n)
{
	T = NULL;
	int i = 0;
	while (i<n)
	{
		BST_Insert(T, str[i]);
		i++;
	}
}

BSTNode* BST_Search(BiTree T, KeyType key, BiTree& p)
{
	p = NULL;
	while (T!=NULL&&key!=T->key)
	{
		p = T;
		if (key < T->key)T = T->lchild;
		else
		{
			T = T->rchild;
		}
	}
	return T;
}
void InOrder(BiTree T)
{
	if (T!=NULL)
	{
		InOrder(T->lchild);
		printf("%3d", T->key);
		InOrder(T->rchild);
	}
}

int main()
{
	BiTree T = NULL;
	BiTree parent;
	BiTree search;
	KeyType str[7] = { 54,20,66,40,28,79,58 };
	Creat_BST(T, str, 7);
	InOrder(T);
	printf("\n");
	search = BST_Search(T, 40, parent);
	if (search)
	{
		printf("True key=%d\n", search->key);
	}
	else
	{
		printf("False\n");
	}
	return 0;
}