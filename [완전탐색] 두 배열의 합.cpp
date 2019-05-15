#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	// MARK: - A의 부 배열의 합에 B의 부 배열의 합을 더해서 T가 되는 모든 부 배열 쌍의 개수를 구하는 프로그램을 작성하시오.
	int target = 0; cin >> target;

	int first = 0; cin >> first;
	vector<int> firstArray = vector<int>(first);
	for (int ii = 0; ii < first; ii++) { cin >> firstArray[ii]; }
	
	int second = 0; cin >> second;
	vector<int> secondArray = vector<int>(second);
	for (int ii = 0; ii < second; ii++) { cin >> secondArray[ii]; }

	vector<int> firstSum, secondSum;
	for (int ii = 0; ii < first; ii++) {
		int sum = 0;
		for (int jj = ii; jj < first; jj++) {
			sum += firstArray[jj];
			firstSum.push_back(sum);
		}
	}

	for (int ii = 0; ii < second; ii++) {
		int sum = 0;
		for (int jj = ii; jj < second; jj++) {
			sum += secondArray[jj];
			secondSum.push_back(sum);
		}
	}

	std::sort(firstSum.begin(), firstSum.end());
	std::sort(secondSum.begin(), secondSum.end());

	long long answer = 0;
	for (const auto value : firstSum) {
		const auto range = std::equal_range(secondSum.begin(), secondSum.end(), target - value);
		answer += std::distance(range.first, range.second);
	}

	cout << answer << endl;
	return 0;
}
