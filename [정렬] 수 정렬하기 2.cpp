#include <iostream>
#include <algorithm>
#include <cstdio>
#define SWAP(X, Y, Z) (Z=X); (X=Y); (Y=Z);
using namespace std;

void QSort(int * arr, int left, int right)
{
	int mleft = left;
	int mright = right;
	int pivot = arr[(left + right) / 2];
	int temp = 0;

	while (mleft <= mright)
	{
		while (arr[mleft] < pivot) { ++mleft; }
		while (arr[mright] > pivot) { --mright; }
		if (mleft <= mright) { SWAP(arr[mleft], arr[mright], temp); ++mleft; --mright; }
	}

	if (left < mright) { QSort(arr, left, mright); }
	if (mleft < right) { QSort(arr, mleft, right); }
}


int main(void)
{
	int m = 0;
	cin >> m;

	int * arr = new int[m];

	for (int ii = 0; ii < m; ii++)
	{
		scanf("%d", &arr[ii]);
	}

	QSort(arr, 0, m-1);

	for (int ii = 0; ii < m; ii++)
	{
		printf("%d\n", arr[ii]);
	}

	return 0;
}
