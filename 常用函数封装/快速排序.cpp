#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

typedef int ElemType;
typedef struct
{
	ElemType* elem;//存储元素的起始地址
	int TableLen;//元素个数
}SSTable;

void ST_Init(SSTable& ST, int len)
{
	ST.TableLen = len;
	ST.elem = (ElemType*)malloc(sizeof(ElemType) * ST.TableLen);
	int i;
	srand(time(NULL));
	for (i = 0; i < ST.TableLen; i++)
	{
		ST.elem[i] = rand() % 100;
	}
}
//打印数组元素
void ST_print(SSTable ST)
{
	for (int i = 0; i < ST.TableLen; i++)
	{
		printf("%3d", ST.elem[i]);
	}
	printf("\n");
}
//交换两个元素
void swap(ElemType& a, ElemType& b)
{
	ElemType tmp;
	tmp = a;
	a = b;
	b = tmp;
}
int Partition(ElemType A[], int low,int high)
{
	ElemType pivot = A[low];
	while (low<high)
	{
		while (low < high && A[high] >= pivot)
			--high;
		A[low] = A[high];
		while (low < high && A[low] <= pivot)
			++low;
		A[high] = A[low];
	}
	A[low] = pivot;
	return low;
}
//递归实现
void QuickSort(ElemType A[], int low, int high)
{
	if (low<high)
	{
		int pivotpos = Partition(A, low, high);
		QuickSort(A, low, pivotpos - 1);
		QuickSort(A, pivotpos + 1, high);
	}
}

int main()
{
	SSTable ST;
	ST_Init(ST, 10);
	ST_print(ST);
	QuickSort(ST.elem,0,9);
	ST_print(ST);
	return 0;
}