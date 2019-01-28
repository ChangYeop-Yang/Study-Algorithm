#include <vector>
#include <cstdio>
#include <iostream>
using namespace std;

#define MAX_V 500000

long long answer = 0;

vector<int> arr = vector<int>(MAX_V);

void mergeTwoArea(int left, int mid, int right) {
	
	// fIdx와 rIdx에는 각각 병합할 두 영역의 첫 번째 위치정보가 담긴다. (fIdx = Left Array, rIdx = Right Array)
	int fIdx = left, rIdx = mid + 1, sIdx = left;

	// 병합 한 결과를 담을 Vector
	vector<int> sortArr;

	// 병합 할 두 영역의 데이터들을 비교하여, 정렬순서대로 Vector에 하나씩 옮겨 담는다.
	while (fIdx <= mid && rIdx <= right) {
		if (arr[fIdx] <= arr[rIdx]) { sortArr.push_back(arr[fIdx++]); }
		else { sortArr.push_back(arr[rIdx++]); answer += (mid + 1 - fIdx); }
	}

	// 배열의 앞 부분이 모두 Vector에 옮겨졌다면, 배열의 뒷 부분에 남은 데이터들을 Vector에 그대로 옮긴다.
	if (fIdx > mid) {
		for (int ii = rIdx; ii <= right; sIdx++, ii++) { sortArr.push_back(arr[ii]); }
	// 배열의 뒷 부분이 모두 Vector에 옮겨졌다면, 배열의 앞 부분에 남은 데이터들을 Vector에 그래도 옮긴다.
	} else {
		for (int ii = fIdx; ii <= mid; sIdx++, ii++) { sortArr.push_back(arr[ii]); }
	}

	for (int ii = left, jj = 0; ii <= right; ii++, jj++) { arr[ii] = sortArr[jj]; }
}

void mergeSort(int left, int right) {
	
	// 배열의 중간 지점 인덱스를 구한다.
	const int mid = (left + right) / 2;
	if (left < right) {
		mergeSort(left, mid); // [Left Index ~ Mid Index] 분할한다.
		mergeSort(mid + 1, right); // [Mid Index ~ Right Index] 분할한다.

		// 분할 된 두 배열을 하나로 병합한다.
		mergeTwoArea(left, mid, right);
	}

}

int main(void)
{
	int input = 0; cin >> input;
	
	for (int ii = 0; ii < input; ii++) { scanf("%d", &arr[ii]); }

	mergeSort(0, input - 1);

	cout << answer << endl;

	return 0;
}