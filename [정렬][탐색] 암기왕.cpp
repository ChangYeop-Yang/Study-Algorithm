#include <stdio.h>
#define SWAP(X, Y, Z) (Z=X); (X=Y); (Y=Z);
using namespace std;

/* 모든 정수들의 범위는 int 로 한다. (-2147483648, 2147483647) */
/* 그러므로 배열의 크기를 늘려서 저장하여 Flag 형식으로 찾는 방식은 불가능하다. */
/* 값을 배열에 저장을 해서 탐색하는 방법을 통해서 풀어야하는 알고리즘 */
/* cin 이나 cout 같은 함수는 printf와 scanf보다 입출력 시간이 상당히 많이 발생한다 */

/* 이진탐색 */
int BinarySearch(int * arr, int first, int last, int find);
/* 퀵정렬 */
int Qsort(int * arr, int left, int right);

int main(void)
{
	/* Integer */
	int N = 0, M = 0, T = 0, Q = 0;

	/* TestCase */
	scanf("%d", &T);
	for (int count = 0; count < T; count++)
	{
		/* Note1 */
		scanf("%d", &N);
		int * arr1 = new int[N];
		for (int count = 0; count < N; count++) { scanf("%d", &arr1[count]); }
		/* Quick Sort */
		Qsort(arr1, 0, N);

		/* Note2 */
		scanf("%d", &M);
		for (int count = 0; count < M; count++)
		{
			scanf("%d", &Q);
			/* Binary Search */
			if (BinarySearch(arr1, 0, N, Q) == Q) { printf("%d\n", 1); } else { printf("%d\n", 0); }
		}
	}
	return 0;
}

/* 이진탐색 */
int BinarySearch(int * arr, int first, int last, int find)
{
	/* Integer */
	int mid = 0; /* 중간 값을 저장하기 위한 변수 */

	/* 찾으려는 값이 배열에 없는 경우 */
	if (first > last) { return -1; }
	/* 배열에 중간을 찾는 부분 */
	else { mid = (first + last) / 2; } /* mid = (first + last) / 2 : 중간 찾는 공식 */

	/* 배열에서 값을 찾은 경우 */
	if (*(arr + mid) == find) { return find; }
	/* 찾는 값이 중간 값보다 작은 경우 왼쪽으로 이동 */
	else if (*(arr + mid) > find) { return BinarySearch(arr, first, mid - 1, find); }
	/* 찾는 값이 중간 값보다 큰 경우 오른쪽으로 이동 */
	else { return BinarySearch(arr, mid + 1, last, find); }
}
/* 퀵정렬 */
int Qsort(int * arr, int left, int right)
{
	/* Integer */
	int mleft = left; /* 배열의 첫 부분 값 저장하는 변수 */
	int mright = right; /* 배열의 마지막 부분 값 저장하는 변수 */
	int temp = 0; /* 배열 위치를 변경할 때 임시 저장하는 변수 */
	int pivot = arr[(left + right) / 2]; /* 배열의 중간 값을 저장하는 변수 */

	/* 오른쪽 위치 변수가 왼쪽 위치 변수보다 크거나 같은 경우 */
	while (mleft <= mright)
	{
		/* 왼쪽으로 이동 */
		while (arr[mleft] < pivot) { ++mleft; }
		/* 오른쪽으로 이동 */
		while (arr[mright] > pivot) { --mright; }

		/* 왼쪽 위치 변수 값보다 오른쪽 위치 변수 값이 크거나 같은 경우 */
		if (mleft <= mright) { SWAP(arr[mleft], arr[mright], temp); ++mleft, --mright; }
	}

	if (left < mright) { Qsort(arr, left, mright); }
	if (mleft < right) { Qsort(arr, mleft, right); }

	return 0;
}
