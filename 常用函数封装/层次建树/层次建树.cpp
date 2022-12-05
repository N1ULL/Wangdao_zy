#include"function.h"

int main()
{
	BiTree pnew;//用来指向新申请的树结点
	BiTree tree = NULL;//tree是指向树根的，代表树
	char c;
	ptag_t phead = NULL, ptail = NULL, listpnew = NULL, pcur = NULL;
	//abcdefghij
	while (scanf("%c",&c))
	{
		if (c == '\n')
		{
			break;//读到换行就结束
		}
		pnew = (BiTree)calloc(1, sizeof(BiTNode));
		pnew->c = c;
		listpnew = (ptag_t)calloc(1, sizeof(tag_t));
		listpnew->p = pnew;
		//如果是树的第一个结点
		if (NULL==tree)
		{
			tree = pnew;//tree指向树的根结点
			phead = listpnew;//第一个结点既是队列的头，也是队列的尾
			ptail = listpnew;
			pcur = listpnew;//pcur要指向要进入树的父亲元素

		}
		else
		{
			//让元素入队
			ptail->pnext = listpnew;
			ptail = listpnew;
			//把b结点放入树中
			if (NULL==pcur->p->lchild)
			{
				pcur->p->lchild = pnew;//pcur->p左孩子为空，就放入左孩子
			}
			else if(NULL == pcur->p->rchild)
			{
				pcur->p->rchild = pnew;//pcur->p右孩子为空，就放入右孩子
				pcur = pcur->pnext;//当前结点左右孩子都有了，pcur就指向下一个
			}
		}
	}
	return 0;
}
