#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int i;
	scanf("%d", &i);
	getchar();


	char* c;
	c = (char*)malloc(i);
	gets(c);
	puts(c);

	return 0;
}