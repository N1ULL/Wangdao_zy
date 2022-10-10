#include<stdio.h>
void change(int* p)
{
	*p = *p / 2;
}

int main()
{
	int i;
	scanf("%d", &i);

	change(&i);
	printf("%d", i);
	return 0;
}