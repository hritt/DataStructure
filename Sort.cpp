/************************************************************************
*
*   Description: sort
*
*   Author & Data: JY Liu, 2016/02/29
*
************************************************************************/

#include "Main.h"

void Output(int a[], int start, int end)
{
	for (int i = start; i <= end; i++)
		cout << a[i] << " ";
	cout << endl;
}

void BubbleSort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - i - 1; j++)
			if (a[j] > a[j + 1])
			{
				a[j] = a[j] ^ a[j + 1];
				a[j + 1] = a[j] ^ a[j + 1];
				a[j] = a[j] ^ a[j + 1];
			}
}

void BubbleSort2(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		bool exchange = false;
		for (int j = 0; j < n - i - 1; j++)
			if (a[j] > a[j + 1])
			{
				a[j] = a[j] ^ a[j + 1];
				a[j + 1] = a[j] ^ a[j + 1];
				a[j] = a[j] ^ a[j + 1];
				exchange = true;
			}
		if (exchange == false)
			return;
	}
}

void BubbleSort3(int a[], int n)
{
	if (n < 2)
		return;
	int k = n - 1;
	while (k)
	{
		int i = k;
		k = 0;
		for (int j = 0; j < i; j++)
			if (a[j] > a[j + 1])
			{
				a[j] = a[j] ^ a[j + 1];
				a[j + 1] = a[j] ^ a[j + 1];
				a[j] = a[j] ^ a[j + 1];
				k = j; //just sort data before a[j]
			}
	}
}

void SelectSort(int a[], int n)
{
	int i, j, k;
	for (i = 0; i < n - 1; i++)
	{
		k = 0;
		for (j = 1; j < n - i; j++)
		{
			//select the maximun
			if (a[j] > a[k])
				k = j;
		}
		if (k != j - 1)
		{
			//if k==j-1, can't use xor
			a[k] = a[k] ^ a[j - 1];
			a[j - 1] = a[k] ^ a[j - 1];
			a[k] = a[k] ^ a[j - 1];
		}
	}
}

void InsertSort(int a[], int n)
{
	int i, j;
	for (i = 1; i < n; i++)
	{
		int tmp = a[i];
		for (j = i - 1; j >= 0; j--)
		{
			if (a[j] > tmp)
				a[j + 1] = a[j]; //backward
			else
				break;
		}
		a[j + 1] = tmp;
	}
}

void BiInsertSort(int a[], int n)
{
	int i, j;
	for (i = 1; i < n; i++)
	{
		int low = 0, high = i - 1;
		while (low <= high)
		{
			int mid = (low + high) / 2;
			if (a[mid] > a[i])
				high = mid - 1;
			else
				low = mid + 1;
		}
		int tmp = a[i];
		for (j = i; j > low; j--)
			a[j] = a[j - 1];
		a[j] = tmp;
	}
}

void ShellSort(int a[], int n)
{
	for (int d = n / 2; d >= 1; d /= 2)
	{
		for (int i = d; i < n; i++)
		{
			int tmp = a[i];
			int j;
			for (j = i - d; j >= 0 && a[j] > tmp; j -= d) //backward
				a[j + d] = a[j];
			a[j + d] = tmp;
		}
	}
}

int Partition(int a[], int l, int h)
{
	int tmp = a[l];
	while (l < h)
	{
		while (a[h] > tmp && l < h)
			h--;
		if (l < h)
			a[l++] = a[h];
		while (a[l] < tmp && l < h)
			l++;
		if (l < h)
			a[h--] = a[l];
	}
	a[l] = tmp;
	return l;
}

void QuickSort(int a[], int l, int h)
{
	int p = Partition(a, l, h);
	if (l < p - 1)
		QuickSort(a, l, p - 1);
	if (p + 1 < h)
		QuickSort(a, p + 1, h);
}

void Sift(int a[], int k, int n)
{
	int i = k, j = 2 * i;
	while (j <= n)
	{
		if (j < n && a[j] < a[j + 1]) //select the bigger in left node and right node
			j++;
		if (a[i] > a[j]) //a[i] is bigger then it's children
			break;
		else
		{
			//swap a[i] and a[j]
			a[i] = a[i] ^ a[j];
			a[j] = a[i] ^ a[j];
			a[i] = a[i] ^ a[j];

			//prepare for next loop
			i = j;
			j = 2 * i;
		}
	}
}

void HeapSort(int a[], int n)
{
	int i;
	for (i = n / 2; i >= 1; i--)
		Sift(a, i, n);
	for (i = 0; i < n - 1; i++)
	{
		a[1] = a[1] ^ a[n - i];
		a[n - i] = a[1] ^ a[n - i];
		a[1] = a[1] ^ a[n - i];

		Sift(a, 1, n - i - 1);
	}
}

void Merge(int a[], int b[], int s, int m, int t)
{
	int i = s, j = m + 1, k = s;
	while (i <= m && j <= t)
	{
		if (a[i] < a[j])
			b[k++] = a[i++];
		else
			b[k++] = a[j++];
	}
	while (i <= m)
		b[k++] = a[i++];
	while (j <= t)
		b[k++] = a[j++];
}

void MergePass(int a[], int b[], int n, int h)
{
	int i;
	for (i = 0; i <= n - 2 * h; i += 2 * h)
		Merge(a, b, i, i + h - 1, i + 2 * h - 1);

	if (i < n - h)
		Merge(a, b, i, i + h - 1, n - 1);
	else
		for (int j = i; j < n; j++)
			b[j] = a[j];
}

void MergeSort(int a[], int n)
{
	int* b = new int[n];
	int h = 1;
	while (h < n)
	{
		MergePass(a, b, n, h);
		h *= 2;
		MergePass(b, a, n, h);
		h *= 2;
	}
	delete []b;
}

void Merge2(int a[], int b[], int s, int m, int t)
{
	int i = s, j = m + 1, k = s;
	while (i <= m && j <= t)
	{
		if (a[i] < a[j])
			b[k++] = a[i++];
		else
			b[k++] = a[j++];
	}
	while (i <= m)
		b[k++] = a[i++];
	while (j <= t)
		b[k++] = a[j++];

	//different from Merge()
	for (i = s; i <= t; i++)
		a[i] = b[i];
}

void MergeSortRec(int a[], int b[], int s, int t) //recursion
{
	if (s == t)
		b[s] = a[s];
	else
	{
		MergeSortRec(a, b, s, (s + t) / 2);
		MergeSortRec(a, b, (s + t) / 2 + 1, t);
		Merge2(a, b, s, (s + t) / 2, t);
	}
}

void MergeSort2(int a[], int n)
{
	int* b = new int[n];
	MergeSortRec(a, b, 0, n - 1);
	delete []b;
}
