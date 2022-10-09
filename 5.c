#include<stdio.h>

int main()
{
	int i;
	char j;
	float k, count;

	scanf("%d %c %f", &i, &j, &k);
	count = (float)i + (float)j + k;
	printf("%.2f\n", count);
	return 0;
}