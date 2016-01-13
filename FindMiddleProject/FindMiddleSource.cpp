#include<iostream>
#define T int

int partition(T*dat, int begin, int end)
{
	int flag = dat[begin];
	while (begin < end)
	{
		while (begin<end&&dat[end]>flag) end--;
		if (begin < end)
			dat[begin++] = dat[end];
		while (begin < end&&dat[begin] < flag) begin++;
		if (begin < end)
			dat[end--] = dat[begin];
	}
	dat[begin] = flag;
	return begin;
}
int FindMiddle(T* dat, int n)
{
	int k = (n-1)/ 2;	//数组从0下标开始
	int t = -1;
	int begin = 0, end = n - 1;
	while (true)
	{
		t = partition(dat, begin, end);
		if (k > t)
			begin = t + 1;
		else if (k < t)
			end = t - 1;
		else
			break;
	}
	return dat[t];
}

void main()
{
	int dat[] = { 9,2,65,3,5,8,6,10,4,1 };
	int middleVal = FindMiddle(dat, 10);
	std::cout << middleVal;
	getchar();
}