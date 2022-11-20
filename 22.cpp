#define MaxSize 10
#include<stdio.h>
#include<stdlib.h>


typedef int Elemtype;
typedef struct BiNode
{
	Elemtype data;
	struct BiNode* lchild;
	struct BiNode* rchild;
}BiNode, * Bitree;

typedef struct SeqList
{
	Elemtype elm[MaxSize];
	int length;
}SeqList;

bool BST_Insert(Bitree& tree, Elemtype e)
{
	if (NULL == tree)
	{
		tree = (Bitree)malloc(sizeof(BiNode));
		tree->data = e;
		tree->lchild = NULL;
		tree->rchild = NULL;
		return true;
	}
	else if (tree->data == e)
	{
		return false;
	}
	else if (e > tree->data)
	{
		return BST_Insert(tree->rchild, e);
	}
	else
	{
		return BST_Insert(tree->lchild, e);
	}
}

void Crest_BST(Bitree& tree, Elemtype x[])
{
	tree = NULL;

	int i = 0;

	while (i < 10)
	{
		BST_Insert(tree, x[i]);
		i++;
	}
}

void MidOrder(Bitree tree)
{

	if (NULL != tree)
	{
		MidOrder(tree->lchild);
		printf("%3d", tree->data);
		MidOrder(tree->rchild);
	}
}

int toArrayIn(Bitree tree, SeqList& L, int pos)
{
	if (tree == NULL)
		return pos;
	pos = toArrayIn(tree->lchild, L, pos);
	L.elm[pos] = tree->data;
	return toArrayIn(tree->rchild, L, pos + 1);
}

int Binary_Search(SeqList& L, Elemtype tag)
{
	int low = 0;
	int high = L.length - 1;
	int mid;

	while (low < high)
	{
		mid = (low + high) / 2;
		if (L.elm[mid] == tag)
		{
			return mid;
		}
		else if (L.elm[mid] > tag)
		{
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}
	return -1;
}

int main()
{
	Bitree tree = NULL;

	int i;
	Elemtype x[MaxSize];
	for (i = 0; i < 10; i++)
	{
		scanf("%d", &x[i]);
	}
	Crest_BST(tree, x);
	int pos = 0;
	
	MidOrder(tree);

	SeqList L;
	L.length = 10;
	toArrayIn(tree, L, pos);
	printf("\n");

	printf("%d", Binary_Search(L, 21));
	return 0;
}