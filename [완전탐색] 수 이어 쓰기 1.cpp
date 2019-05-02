#include <string>
#include <iostream>
using namespace std;

#define MAX_N 100000000
#define INT_PAIR pair<int, int>

int main(void)
{
	int target = 0; cin >> target;
	int length = std::to_string(target).size();

	INT_PAIR digit = make_pair(1, 9);
	for (int ii = 1; ii < length; ii++) { digit.first *= 10; digit.second = (digit.second * 10) + 9; }

	int answer = 0;
	while (length) {
		// MARK: - 수의 자리수별로 나누어서 문제를 해결한다.
		answer += answer ? (digit.second - digit.first + 1) * length : (target - digit.first + 1) * length;
		digit.first /= 10, digit.second /= 10, length--;
	}

	cout << answer << endl;
	
	return 0;
} 