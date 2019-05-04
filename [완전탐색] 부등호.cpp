#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_N 9
#define INT_PAIR pair<int, int>
#define STRING_PAIR pair<string, string>

const bool checkInequalitySign(const vector<char> & signs, const vector<int> & digits) {

	int index = 0;
	for (const auto sign : signs) {

		const INT_PAIR number = make_pair(digits[index], digits[index + 1]);
		index++;

		if (sign == '>') {
			if (number.first < number.second) { return false; }
		} else if (sign == '<') {
			if (number.first > number.second) { return false; }
		}
	}

	return true;
}

const string convertString(const vector<int> & digits) {

	string answer = string();
	for (const auto number : digits) { answer.push_back(number + '0'); }

	return answer;
}

int main(void)
{
	int number = 0; cin >> number;

	STRING_PAIR answer = make_pair(string(), string());
	vector<char> inequalitySign = vector<char>(number);
	for (int ii = 0; ii < number; ii++) { cin >> inequalitySign[ii]; }

	vector<int> small, big;
	for (int ii = 0; ii <= number; ii++) {
		// MARK: - 부등호 기호 앞뒤에 넣을 수 있는 숫자는 0부터 9까지의 정수이며 선택된 숫자는 모두 달라야 한다. 또한 최솟값은 가장 작은 수들인 K내에서 나오며 최댓값은 가장 큰 수들인 K내에서 나온다.
		small.push_back(ii), big.push_back(MAX_N - ii);
	}

	// MARK: - 제시된 k개의 부등호 순서를 만족하는 (k+1)자리의 정수 중에서 최솟값
	do {
		if (checkInequalitySign(inequalitySign, small)) { answer.first = convertString(small); break; }
	} while ( std::next_permutation(small.begin(), small.end()) );

	// MARK: - 제시된 k개의 부등호 순서를 만족하는 (k+1)자리의 정수 중에서 최댓값
	do {
		if (checkInequalitySign(inequalitySign, big)) { answer.second = convertString(big); break; }
	} while ( std::prev_permutation(big.begin(), big.end()) );

	cout << answer.second << endl << answer.first << endl;

	return 0;
}
