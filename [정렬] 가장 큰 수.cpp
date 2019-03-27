#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX_V 10
#define STRING_VECTOR vector<string>

#define TO_INDEX(X) X - '0'

/* ※ CAPTION ※
  자릿수가 다른 숫자가 주어질 경우에는 (6, 10) 이면 6 + 10 = 610 / 10 + 6 = 106 의 값으로 비교한다. (A + B < B + A의 형태)
  C++에서 String은 아스키코드 값을 통해서 비교한다. 그러므로 610 > 106의 값을 비교한다.
*/
const bool compare(const string & first, const string & second) {
	return first + second > second + first ? true : false;
}

string solution(vector<int> numbers) {

	vector<STRING_VECTOR> bucket = vector<STRING_VECTOR>(MAX_V);

	// MARK: - Processing One Decimal Digit.
	for (const auto value : numbers) {
		const string number = std::to_string(value);
		bucket[TO_INDEX(number.front())].push_back(number);
	}

	// MARK: - Sorting
	for (auto & value : bucket) { std::sort(value.begin(), value.end(), compare); }

	// MARK: - Concat Digit.
	string answer = string();
	for (int ii = bucket.size() - 1; ii >= 0; ii--) {
		for (const auto value : bucket[ii]) { answer += value; }
	}

	if (std::atoi(answer.c_str()) == 0) { return "0"; }
	return answer;
}
