#include<stdio.h>
int main()
{
	int start,end=0,temp;

	scanf("%d", &start);

	temp = start;
	while (temp!=0)
	{
		end = end * 10 + temp % 10;
		temp = temp / 10;
	}

	if (start == end)
	{
		printf("yes");
	}
	else
	{
		printf("no");
	}

	return 0;
}