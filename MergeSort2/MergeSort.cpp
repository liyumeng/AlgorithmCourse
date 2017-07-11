#include<iostream>
#include<vector>
#define T int

using namespace std;

void sort(int *A, int *tmp, int begin, int mid, int end) {
	int k = begin;
	int i = begin, j = mid;
	while (i < mid&&j < end) {
		if (A[i] > A[j]) tmp[k++] = A[j++];
		else tmp[k++] = A[i++];
	}
	while (i < mid) tmp[k++] = A[i++];
	while (j < end) tmp[k++] = A[j++];
}

void Merge(int *A, int *tmp, int step, int n) {
	int begin = 0;

	while (begin + 2 * step <= n) {
		sort(A, tmp, begin, begin + step, begin + 2 * step);
		begin += 2 * step;
	}
	if (begin + step < n) {
		sort(A, tmp, begin, begin + step, n);
	}
	else {
		while (begin < n) {
			tmp[begin] = A[begin];
			begin++;
		}
	}
	for (int i = 0; i < n; i++) {
		A[i] = tmp[i];
	}
}

void MergeSort(int *A, int n) {
	int *tmp = (int*)malloc(sizeof(int)*n);
	for (int step = 1; step < n; step *= 2) {
		Merge(A, tmp, step, n);
	}
}

int binSearch(int *A, int begin, int end, int target) {
	while (begin <= end) {
		int mid = begin + (end - begin) / 2;
		if (A[mid] > target) begin = mid + 1;
		else if (A[mid] < target) end = mid - 1;
		else 
			return mid;
	}
	return -1;
}

void main()
{
	T dat[] = { 9,2,65,3,5,2,8,6,10,4 };
	MergeSort(dat, 10);
	for (int i = 0; i < 10; i++)
		std::cout << dat[i] << std::endl;
	std::cout << binSearch(dat, 0, 9, 12) << std::endl;

}