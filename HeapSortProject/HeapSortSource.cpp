#include<iostream>

void swap(int& a, int& b)
{
	int t = a;
	a = b;
	b = t;
}
void HeapAdjust(int *dat, int i, int n)
{
	int child;
	for (int rc = dat[i]; 2 * i + 1 < n; i = child)
	{
		child = 2 * i + 1;
		if (child + 1 < n&&dat[child + 1] > dat[child])
			child++;
		if (dat[child] > rc)
		{
			dat[i] = dat[child];
			dat[child] = rc;
		}
	}
}
void HeapSort(int *dat, int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
	{
		HeapAdjust(dat, i, n);
	}

	for (int i = n - 1; i > 0;i--)
	{
		swap(dat[i], dat[0]);
		HeapAdjust(dat, 0, i);//每次减一个元素
	}
}
void main()
{
	int dat[] = { 9,2,65,3,5,2,8,6,10,4 };
	HeapSort(dat, 10);
	for (int i = 0; i < 10; i++)
		std::cout << dat[i] << std::endl;
	getchar();
}