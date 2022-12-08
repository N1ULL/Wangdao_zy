#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef int ElemType;
typedef struct
{
	ElemType* elem;
	int TableLen;//存储动态数组里的元素的个数
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

void ST_print(SSTable ST)
{
	for (int i = 0; i < ST.TableLen; i++)
	{
		printf("%3d", ST.elem[i]);
	}
	printf("\n");
}

int BinarySearch(SSTable L, ElemType key)
{
	int low = 0, high = L.TableLen - 1, mid;
	while (low<=high)
	{
		mid = (low + high) / 2;
		if (L.elem[mid]==key)
		{
			return mid;
		}
		else if(L.elem[mid]>key)
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
int compare(const void* left, const void* right)
{
	return *(ElemType*)left - *(ElemType*)right;
}
int main()
{
	SSTable ST;
	ElemType key;
	int pos;
	ST_Init(ST, 10);
	qsort(ST.elem, ST.TableLen, sizeof(ElemType), compare);
	ST_print(ST);
	printf("BinarySearch key=\n");
	scanf("%d", &key);
	pos = BinarySearch(ST, key);
	if (pos!=-1)
	{
		printf("True pos=%d\n", pos);
	}
	else
	{
		printf("False\n");
	}
	return 0;
}