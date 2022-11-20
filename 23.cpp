#include<stdio.h>
#include<string.h>

void swap(int& x, int& y)
{
	int temp;
	temp = x;
	x = y;
	y = temp;
}

void Printf_Int(int data[])
{
	int i;
	for (i = 0; i < 10; i++)
	{
		printf("%3d", data[i]);
	}
	printf("\n");
}

void BubbleSort(int data[], int len)
{
	int i;
	int j;
	for (i = 0; i < len - 1; i++)
	{
		int flag = 0;
		for (j = len - 1; j = j; j--)
		{
			if (data[j - 1] > data[j])
			{
				swap(data[j - 1], data[j]);
				flag = 1;
			}
		}
		if (0 == flag)
		{
			return;
		}
	}
}

int change(int kuai[], int left, int right)
{
	int k;
	int i;

	for (i = k = left; i < right; i++)
	{
		if (kuai[i] < kuai[right])
		{
			swap(kuai[i], kuai[k]);
			k++;
		}
	}
	swap(kuai[right], kuai[k]);
	return k;
}

int Partition(int A[], int low, int high)
{
	int pivot = A[low];
	while (low < high)
	{
		while (low < high && A[high] >= pivot)
		{
			--high;
		}
		A[low] = A[high];
		while (low < high && A[low] <= pivot)
		{
			++low;
		}
		A[high] = A[low];
	}
	A[low] = pivot;
	return low;
}

void QuickSort(int kuai[], int low, int high)
{
	int pos;
	if (low < high)
	{
		pos = change(kuai, low, high);
		QuickSort(kuai, pos + 1, high);
		QuickSort(kuai, low, pos - 1);
	}
}

void InsertSort(int elem[], int n)
{
	int i;
	int j;

	for (i = 2; i <= n; i++)
	{
		if (elem[i - 1] > elem[i])
		{
			elem[0] = elem[i];
			for (j = i - 1; elem[0] < elem[j]; j--)
			{
				elem[j + 1] = elem[j];
			}
			elem[j + 1] = elem[0];
		}
	}
}

int main()
{
	int data[10] = { 0 };
	int kuai[10] = { 0 };
	int elem[11] = { 0 };

	int i;
	for (i = 0; i < 10; i++)
	{
		scanf("%d", &data[i]);
	}

	memcpy(kuai, data, sizeof(data));
	memcpy(elem + 1, data, sizeof(data));
	elem[0] = 0;

	BubbleSort(data, 10);
	Printf_Int(data);

	QuickSort(kuai, 0, 9);
	Printf_Int(kuai);

	InsertSort(elem, 10);
	Printf_Int(kuai);

	return 0;
}