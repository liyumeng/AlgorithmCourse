#include<iostream>
#define T int
//快速排序
int partition(T* dat, int begin, int end)
{
	int flag = dat[begin];
	while(begin<end)
	{
		while (begin<end&&dat[end]>flag) end--;
		if (begin < end)
		{
			dat[begin] = dat[end];
			begin++;
		}
		while (begin < end&&dat[begin] < flag) begin++;
		if(begin<end)
		{
			dat[end] = dat[begin];
			end--;
		}
	}
	dat[begin] = flag;
	return begin;
}

void QuickSort(T* dat, int begin, int end)
{
	if (begin < end)
	{
		int t = partition(dat, begin, end);
		QuickSort(dat, begin, t - 1);
		QuickSort(dat, t + 1, end);
	}
}

void main()
{
	int dat[] = { 9,2,65,3,5,2,8,6,10,4 };
	QuickSort(dat, 0, 9);
	for (int i = 0; i < 10; i++)
		std::cout << dat[i] << std::endl;
	getchar();
}