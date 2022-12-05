#include<stdio.h>
#include<stdlib.h>

#define MaxSize 50
typedef int ElemType;
typedef struct
{
	ElemType data[MaxSize];//����
	int top;
}SqStack;
void InitStack(SqStack& s)
{
	s.top = -1;//����ջΪ��
}
bool StackEmpty(SqStack& s)
{
	if (s.top==-1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
//��ջ
bool Push(SqStack& s, ElemType x)
{
	if (s.top==MaxSize-1)
	{
		return false;
	}
	s.data[++s.top] = x;
	return true;
}
//��ջ
bool Pop(SqStack& s, ElemType& x)
{
	if (-1==s.top)
	{
		return false;
	}
	x = s.data[s.top--];
	return true;
}
//��ȡջ��Ԫ��
bool GetTop(SqStack& s, ElemType& x)
{
	if (-1==s.top)//ջ��
	{
		return false;
	}
	x = s.data[s.top];
	return true;
}
int main()
{
	SqStack S;
	bool flag;
	ElemType m;
	InitStack(S);
	flag = StackEmpty(S);
	if (flag)
	{
		printf("Empty\n");
	}
	Push(S, 3);
	Push(S, 4);
	Push(S, 5);
	flag = GetTop(S, m);
	if (flag)
	{
		printf("StackTop=%d\n", m);
	}
	flag = Pop(S, m);//����ջ��Ԫ��
	if (flag)
	{
		printf("Pop=%d\n", m);
	}
	return 0;
}