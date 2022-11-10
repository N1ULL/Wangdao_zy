#define SMaxsize 4
#define Maxsize 5

#include<stdio.h>

typedef int ElemType;
typedef struct
{
	ElemType data[SMaxsize];//栈的数据
	int top;//栈的指针
}SqStack;

typedef struct
{
	ElemType data[Maxsize];//数据
	int front, rear;//队头指针，队尾指针
}CQueue;

void InintStack(SqStack &S)
{
	S.top = -1;//栈顶指针指向－1
}

bool PushStack(SqStack& S, ElemType x)
{
	if ( SMaxsize - 1 == S.top)
	{
		return false;
	}
	S.top++;
	S.data[S.top] = x;
	return true;
}

bool PopStack(SqStack& S, ElemType &e)
{
	if (- 1 == S.top)
	{
		return false;
	}
	e = S.data[S.top];
	S.top--;
	return true;
}

void InintQueue(CQueue& Q)
{
	Q.front = Q.rear = 0;
}

bool EnQueue(CQueue& Q, ElemType y)
{
	if ((Q.rear + 1) % Maxsize == Q.front)
	{
		return false;
	}
	Q.data[Q.rear] = y;
	Q.rear++;
	return true;
}

bool DeQueue(CQueue& Q, ElemType &z)
{
	if (Q.rear == Q.front)
	{
		return false;
	}
	z = Q.data[Q.front];
	Q.front++;
	return true;
}

int main()
{
	SqStack S;//新建顺序栈
	InintStack(S);//初始化顺序栈

	int i = 0;//用来记输入几个数
	ElemType x;//用来接收输入数据
	for (i = 0; i < 3; i++)
	{
		scanf("%d", &x);
		PushStack(S, x);
	}
	ElemType e ;//用来接收出栈数据
	for (i = 0; i < 3; i++)
	{
		PopStack(S,e);
		printf("%2d", e);
	}
	printf("\n", e);

	CQueue Q;//新建顺序栈
	InintQueue(Q);//初始化顺序栈
	int j = 0;//用来记输入几个数
	ElemType y;//用来接收输入数据
	int ret;//判断返回值，看操作是否成功
	for (j = 0; j < 5; j++)
	{
		scanf("%d", &y);
		ret = EnQueue(Q, y);
		if (ret == 0)
		{
			printf("false\n");
		}
	}
	ElemType z;//用来接收出队数据
	for (j = 0; j < Maxsize-1; j++)
	{
		DeQueue(Q, z);
		printf("%2d", z);
	}

}