#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef int ElemType;
typedef struct
{
	ElemType* elem;
	int TableLen;//�洢��̬�������Ԫ�صĸ���
}SSTable;

int Search_Seq(SSTable ST, ElemType key)
{
	ST.elem[0] = key;//�����Ԫ����Ϊ�ڱ�
	int i;
	for (i = ST.TableLen - 1; ST.elem[i] != key; --i);
	return i;
}

void ST_Init(SSTable&ST, int len)
{
	//��������һ��λ�ã�Ϊ�˴���ڱ�
	ST.TableLen = len + 1;
	ST.elem = (ElemType*)malloc(sizeof(ElemType) * ST.TableLen);
	int i;
	srand(time(NULL));//���������
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
	int pos;//�洢��ѯԪ�ص�λ��
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