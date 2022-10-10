#include<stdio.h>
#include <malloc.h>

void printf_str(char* &q)
{
	q = (char*)malloc(100);
	fgets(q, 100, stdin);

}

int main()
{
	char* p = NULL;

	printf_str(p);
	puts(p);
	return 0;
}