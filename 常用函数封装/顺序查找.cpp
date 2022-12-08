#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef int ElemType;
typedef struct
{
	ElemType* elem;
	int TableLen;//存储动态数组里的元素的个数
}SSTable;

int Search_Seq(SSTable ST, ElemType key)
{
	ST.elem[0] = key;//让零号元素作为哨兵
	int i;
	for (i = ST.TableLen - 1; ST.elem[i] != key; --i);
	return i;
}

void ST_Init(SSTable&ST, int len)
{
	//多申请了一个位置，为了存放哨兵
	ST.TableLen = len + 1;
	ST.elem = (ElemType*)malloc(sizeof(ElemType) * ST.TableLen);
	int i;
	srand(time(NULL));//随机数生成
	for ( i = 1; i < ST.TableLen; i++)
	{
		ST.elem[i] = rand() % 100;
	}
}

void ST_print(SSTable ST)
{
	for (int i = 1; i < ST.TableLen; i++)
	{
		printf("%3d", ST.elem[i]);
	}
	printf("\n");
}
int main()
{
	SSTable ST;
	ElemType key;
	int pos;//存储查询元素的位置
	ST_Init(ST, 10);
	ST_print(ST);
	printf("key=\n");
	scanf("%d", &key);
	pos = Search_Seq(ST, key);
	if (pos)
	{
		printf("True,pos=%d", pos);
	}
	else
	{
		printf("False\n");
	}
	return 0;
}