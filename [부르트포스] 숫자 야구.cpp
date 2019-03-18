#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>
using namespace std;

#define INT_PAIR pair<int, int>
#define CUS_PAIR pair<string, INT_PAIR>

#define START 123
#define END 987

const bool findDigit(const INT_PAIR condition, const string target, const string match) {

	INT_PAIR conds = make_pair(0, 0);

	for (int ii = 0; ii < target.size(); ii++) {
		for (int jj = 0; jj < match.size(); jj++) {

			// Case Find Strike.
			if (target[ii] == match[jj] && ii == jj) { conds.first++; break; }

			// Case Find Ball.
			if (target[ii] == match[jj]) { conds.second++; break; }
		}
	}

	return condition == conds;
}

const bool checkDigit(const string target) {

	unordered_set<int> number;

	for (const char letter : target) {

		const int digit = letter - '0';

		// Case Contain Duplicate Number.
		if (number.find(digit) != number.end()) { return false; }

		// Case Contain Zero Number.
		if (digit == 0) { return false; }

		number.insert(digit);
	}

	return true;
}

int main(void)
{
	int number = 0; cin >> number;

	vector<CUS_PAIR> bucket = vector<CUS_PAIR>(number);
	for (int ii = 0; ii < number; ii++) {
		INT_PAIR input = make_pair(0, 0);

		cin >> bucket[ii].first >> input.first >> input.second;
		bucket[ii].second = input;
	}

	/* 정답은 1에서 9까지의 서로 다른 숫자 세 개로 구성된 세 자리 수이다. */
	int answer = 0;
	for (int ii = START; ii <= END; ii++) {
		
		bool isSuccess = true;
		const string temp_answer = std::to_string(ii);
		
		if (checkDigit(temp_answer) == false) { continue; }

		for (const auto num : bucket) {
			if (findDigit(num.second, num.first, temp_answer) == false) { isSuccess = false; break; }
		}

		if (isSuccess) { answer++; }
	}

	cout << answer << endl;

	return 0;
}
