#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define INT_MAX 21478978

int generation() {
	static int number = 0;
	return number++;
}

int main(void)
{
	int number = 0;
	cin >> number;

	int minVal = INT_MAX;

	vector<vector<int> > arr = vector<vector<int> >(number);

	for (int ii = 0; ii < number; ii++) {
		arr[ii] = vector<int>(number);
		for (int jj = 0; jj < number; jj++) { scanf_s("%d", &arr[ii][jj]); }
	}

	vector<int> permutation = vector<int>(number);
	generate(permutation.begin(), permutation.end(), generation);

	do {

		int sum = 0;
		bool isCheck = true;

		for (int ii = 0; ii < number - 1; ii++) {
			/* 도시 i에서 도시 j로 갈 수 없는 경우도 있으며 이럴 경우 W[i][j]=0 */
			if (arr[permutation[ii]][permutation[ii + 1]] == 0) { isCheck = false; }
			else { sum += arr[permutation[ii]][permutation[ii + 1]]; }
		}

		/* 마지막 도시에서 다시 첫 도시로 오는 경우 */
		if (isCheck && arr[permutation[number - 1]][permutation[0]] != 0) {
			sum += arr[permutation[number - 1]][permutation[0]];

			/* 모든 도시 방문 최소 값 */
			if (minVal > sum) { minVal = sum; }
		}

	} while ( next_permutation(permutation.begin(), permutation.end()) );

	cout << minVal << endl;

	return 0;
}