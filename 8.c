#include<stdio.h>

int main()
{
	int a10, b5, c2, d1;
	int num = 0;
	int count = 0;
	int answer = 0;

	for (a10 = 1;a10<=40;a10++)//10
	{
		for (b5=1; b5 <= 40; b5++)//5
		{
			for (c2=1; c2 <= 40; c2++)//2
			{
				for (d1=1; d1 <= 40; d1++) //1
				{
					if (a10 + b5 + c2 + d1 == 40 && a10 * 10 + b5 * 5 + c2 * 2 + d1 * 1 == 100)
					{
						answer=answer+1;
					}
				}
			}
		}
	}

	printf("%d", answer);

	return 0;
}