#include<stdio.h>
#include<string.h>

void PrintInt(int data[])
{
	int i;
	for (i = 0; i < 10; i++)
	{
		printf("%3d", data[i]);
	}
	printf("\n");
}

void Merge(int data[], int low, int mid, int high)
{
	int temp[10] = { 0 };
	int k;
	for (k = low; k <= high; k++)
	{
		temp[k] = data[k];
	}

	int i = low;
	int j = mid + 1;
	for (k = i; i <= mid && j <= high; k++)
	{
		if (temp[i] > temp[j])
		{
			data[k] = temp[j];
			j++;
		}
		else
		{
			data[k] = temp[i];
			i++;
		}
	}
	while (i <= mid)
	{
		data[k] = temp[i];
		i++;
		k++;
	}
	while (j <= high)
	{
		data[k] = temp[j];
		j++;
		k++;
	}
}

void MergeSort(int data[], int low, int high)
{
	if (low < high)
	{
		int mid = (low + high) / 2;
		MergeSort(data, low, mid);
		MergeSort(data, mid + 1, high);
		Merge(data, low, mid, high);
	}
}

int main()
{
	int data[10] = { 0 };
	int i;

	for (i = 0; i < 10; i++)
	{
		scanf("%d", &data[i]);
	}
	MergeSort(data, 0, 9);
	PrintInt(data);
	return 0;
}