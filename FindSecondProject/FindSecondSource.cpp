#include<iostream>
#define T int

int max(int a, int b)
{
	return a > b ? a : b;
}
int FindSecond(T* dat, int n)
{
	int res = INT_MIN;
	T* buffer = (T*)malloc(sizeof(T) * 2 * n);
	//buffer[0]弃用
	for (int i = 0; i < n; i++)
		buffer[i + n] = dat[i];
	//建二叉树
	for (int i = n - 1; i > 0; i--)
	{
		buffer[i] = max(buffer[2 * i], buffer[2 * i + 1]);
	}
	int maxVal = buffer[1];
	int child;
	for (int parent = 1; parent < n; parent = child)
	{
		int tmp;
		if (buffer[parent] == buffer[2 * parent])
		{//右子树为待比较元素
			tmp = buffer[2 * parent + 1];
			child = 2 * parent;
		}
		else
		{//左子树为待比较元素
			tmp = buffer[2 * parent];
			child = 2 * parent + 1;
		}
		if (tmp > res)
			res = tmp;
	}
	return res;
}

void main()
{
	int dat[] = { 9,2,65,3,5,2,8,6,10,4 };
	int secondVal = FindSecond(dat, 10);
	std::cout << secondVal;
	getchar();
}