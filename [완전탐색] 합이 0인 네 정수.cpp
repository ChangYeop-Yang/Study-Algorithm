#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	// MARK: - A[a], B[b], C[c], D[d]의 합이 0인 (a, b, c, d) 쌍의 개수를 구하는 프로그램을 작성하시오.
	int number = 0; cin >> number;

	vector<int> a(number), b(number), c(number), d(number);
	for (int ii = 0; ii < number; ii++) {
		cin >> a[ii] >> b[ii] >> c[ii] >> d[ii];
	}

	vector<int> firstSum, secondSum;
	for (int ii = 0; ii < number; ii++) {
		for (int jj = 0; jj < number; jj++) {
			firstSum.push_back(a[ii] + b[jj]);		// A + B의 모든 합을 저장한다.
			secondSum.push_back(c[ii] + d[jj]);		// C + D의 모든 합을 저장한다.
		}
	}

	// -(C[c] + D[d])의 합의 수를 찾으면 되기에 secondSum만 정렬한다.
	std::sort(secondSum.begin(), secondSum.end());

	long long answer = 0;
	// MARK: - A[a] + B[b] + C[c] + D[d] = 0 ---> A[a] + B[b] = -(C[c] + D[d])
	for (const auto sum : firstSum) {

		// MARK: - equal_range()는 lower_bound(), upper_bound() 결과를 쌍으로 던져준다.
		auto range = std::equal_range(secondSum.begin(), secondSum.end(), -sum);
		// MARK: - Iterator의 거리를 구한다. (https://en.cppreference.com/w/cpp/iterator/distance) 즉, 1번째 반복자와 2번째 반복자를 포함해서 그 사이에 있는 원소들의 개수를 구한다.
		answer += std::distance(range.first, range.second); // Upper, Lower Bound를 통해서 동일한 값이 몆개 있는지 계산할 수 있다.
	}

	cout << answer << endl;

	return 0;
}