#include<stdio.h>
#include <string.h>

void PrintInt(int a[])
{
	int i;
	for (i = 0; i < 10; i++)
	{
		printf("%3d", a[i]);
	}
	printf("\n");
}

void swap(int& x, int& y)
{
	int temp;
	temp = x;
	x = y;
	y = temp;
}

void SelectSort(int a[], int len)
{
	int i;
	int min;
	int j;
	for (i = 0; i < len - 1; i++)
	{
		min = i;
		for (j = i + 1; j < len; j++)
		{
			if (a[j] < a[min])
			{
				min = j;
			}
		}
		if (min != i)
		{
			swap(a[i], a[min]);
		}
	}
}

void AdjustDown(int data[], int root, int len)
{
	int dad = root;
	int son = 2 * dad + 1; 
	while (son <= len)
	{
		if (son + 1 <= len && data[son] < data[son + 1])
		{
			son++;
		}
		if (data[son] > data[dad])
		{
			swap(data[son], data[dad]);
			dad = son;
			son = 2 * dad + 1;
		}
		else {
			break;
		}
	}
}

void HeapSort(int data[], int len)
{
	int i;
	for (i = len / 2; i >= 0; i--)
	{
		AdjustDown(data, i, len);
	}
	swap(data[0], data[len]);

	for (i = len - 1; i > 0; i--)
	{
		AdjustDown(data, 0, i);
		swap(data[0], data[i]);
	}
}


int main()
{
	int a[10] = { 0 };

	int i;
	for (i = 0; i < 10; i++)
	{
		scanf("%d", &a[i]);
	}

	int b[10] = { 0 };
	memcpy(b, a, sizeof(a));

	SelectSort(a, 10);
	PrintInt(a);

	HeapSort(b, 9);
	PrintInt(b);
	return 0;
}