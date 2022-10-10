#include<stdio.h>

typedef struct student
{
	int num;
	char name[20];
	char sex;
}stu;

int main()
{
	stu eg = {0};

	scanf("%d %s %c", &eg.num, eg.name, &eg.sex);

	printf("%d %s %c", eg.num, eg.name, eg.sex);
	return 0;
}