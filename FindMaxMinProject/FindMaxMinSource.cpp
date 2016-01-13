#include<iostream>
#define T int

void FindMaxMin(T* dat, int n, T& maxVal, T& minVal)
{
	T* buffer = (T*)malloc(sizeof(T)*n);
	maxVal = dat[n - 1];
	minVal = dat[n - 1];
	for (int i = 0; i < n - 1; i += 2)
	{
		//小到在前,大的放在后面
		if (dat[i] > dat[i + 1])
		{
			buffer[i] = dat[i + 1];	
			buffer[i + 1] = dat[i];
		}
		else
		{
			buffer[i] = dat[i];
			buffer[i + 1] = dat[i + 1];
		}
	}
	for (int i = 0; i < n - 1; i += 2)
	{
		if (buffer[i] < minVal)
			minVal = buffer[i];
		if (buffer[i + 1]>maxVal)
			maxVal = buffer[i + 1];
	}
	free(buffer);
}

void main()
{
	int dat[] = { 9,2,65,3,5,2,8,6,10,4 };
	int maxVal = 0;
	int minVal = 0;
	FindMaxMin(dat, 10, maxVal, minVal);
	std::cout << maxVal << "," << minVal;
	getchar();
}