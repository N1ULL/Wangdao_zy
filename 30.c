#include <stdio.h>
int main()
{
	int i;
	int arr[5];
	for ( i = 0; i < 5; i++)
	{
		scanf("%d", arr+i);
	}
	int result = 0;
	for (i = 0; i < 5; i++)
	{
		result ^= arr[i];
	}
	printf("%d\n", result);
	return 0;
}