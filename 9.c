#include<stdio.h>

int main()
{
	int a[100] = {0};
	int num;
	int count = 0;

	scanf("%d", &num);

	for (int i = 0; i < num; i++)
	{
		scanf("%d", &a[i]);
		if (a[i] == 2)
		{
			count++;
		}
	}
	printf("%d", count);
	return 0;
    
}