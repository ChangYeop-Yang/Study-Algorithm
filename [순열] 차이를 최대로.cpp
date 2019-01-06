#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;

int main(void)
{
	int permutation = 0;
	scanf_s("%d", &permutation);
	
	int max = 0;
	vector<int> bucket = vector<int>(permutation);

	for (int ii = 0; ii < permutation; ii++) {
		scanf_s("%d", &bucket[ii]);
	}

	// 처음순서 부터 순열을 만들어 모든 순열을 구하기 위해서 정렬. (정렬을 하지 않으면 해당 입력 된 수열부터 수열을 구함)
	sort(bucket.begin(), bucket.end());

	do {

		int sum = 0;
		for (int ii = 0; ii < permutation - 1; ii++) {
			sum += abs(bucket[ii] - bucket[ii + 1]);
		}

		if (sum > max) { max = sum; }

	} while ( next_permutation(bucket.begin(), bucket.end()) );

	printf("%d\n", max);

	return 0;
}