#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

typedef int ElemType;
typedef struct
{
	ElemType* elem;//�洢Ԫ�ص���ʼ��ַ
	int TableLen;//Ԫ�ظ���
}SSTable;

void ST_Init(SSTable& ST, int len)
{
	ST.TableLen = len;
	ST.elem = (ElemType*)malloc(sizeof(ElemType) * ST.TableLen);
	int i;
	srand(time(NULL));
	for ( i = 0; i < ST.TableLen; i++)
	{
		ST.elem[i] = rand() % 100;
	}
}
//��ӡ����Ԫ��
void ST_print(SSTable ST)
{
	for (int i = 0; i < ST.TableLen; i++)
	{
		printf("%3d", ST.elem[i]);
	}
	printf("\n");
}
//��������Ԫ��
void swap(ElemType& a, ElemType& b)
{
	ElemType tmp;
	tmp = a;
	a = b;
	b = tmp;
}
void BubbleSort(ElemType A[], int n)
{
	int i, j;
	bool flag;
	for ( i = 0; i < n-1; i++)
	{
		flag = false;
		for ( j = n-1; j > i; j--)
		{
			if (A[j - 1] > A[j])
			{
				swap(A[j - 1], A[j]);
				flag = true;
			}
		}
		if (false==flag)
		{
			return;
		}
	}
}

int main()
{
	SSTable ST;
	ST_Init(ST, 10);
	ST_print(ST);
	BubbleSort(ST.elem, 10);
	ST_print(ST);
	return 0;
}