#include<stdio.h>
#include<stdlib.h>

#define MaxSize 50
typedef int ElemType;
typedef struct
{
	ElemType data[MaxSize];//数组
	int top;
}SqStack;
void InitStack(SqStack& s)
{
	s.top = -1;//代表栈为空
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
//入栈
bool Push(SqStack& s, ElemType x)
{
	if (s.top==MaxSize-1)
	{
		return false;
	}
	s.data[++s.top] = x;
	return true;
}
//出栈
bool Pop(SqStack& s, ElemType& x)
{
	if (-1==s.top)
	{
		return false;
	}
	x = s.data[s.top--];
	return true;
}
//读取栈顶元素
bool GetTop(SqStack& s, ElemType& x)
{
	if (-1==s.top)//栈空
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
	flag = Pop(S, m);//弹出栈顶元素
	if (flag)
	{
		printf("Pop=%d\n", m);
	}
	return 0;
}