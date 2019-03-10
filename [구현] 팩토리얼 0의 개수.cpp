#include <deque>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

#define CARRY 10
#define DEQUE_CHAR deque<char>
#define INT_PAIR pair<int, int>
#define STRING_PAIR pair<string, string>

#define MAX_V 100001
#define LONG long long

vector<string> factori = vector<string>(MAX_V, string());

const string plusBigInteger(string num1, string num2) {

	int prefix = 0;
	deque<char> answer;

	while (num1.size() < num2.size()) { num1.insert(0, "0"); }
	while (num1.size() > num2.size()) { num2.insert(0, "0"); }

	for (auto rear = num2.rbegin(), front = num1.rbegin(); rear != num2.rend(); rear++, front++) {
		const INT_PAIR digit = make_pair(*front - '0', *rear - '0');
		const int value = digit.first + digit.second + prefix;

		// Check CARRY Digit
		prefix = value >= CARRY ? 1 : 0;
		answer.push_front((value % CARRY) + '0');
	}

	if (prefix == 1) { answer.push_front('1'); }

	return string(answer.begin(), answer.end());
}

const string bigMultiple(const string & front, const string & rear) {

	int index = 0;
	int carry = 0;

	const int length = rear.size();
	vector<DEQUE_CHAR> result = vector<DEQUE_CHAR>(rear.size(), deque<char>());

	for (auto ii = rear.rbegin(); ii != rear.rend(); ii++, index++) {
		for (auto jj = front.rbegin(); jj != front.rend(); jj++) {
			const INT_PAIR value = make_pair(*ii - '0', *jj - '0');

			const string multipleValue = std::to_string(value.first * value.second + carry);
			carry = multipleValue.size() == 1 ? 0 : multipleValue.front() - '0';

			result[index].push_front(multipleValue.back());
		}

		if (carry != 0) { result[index].push_front(carry + '0'); carry = 0; }

		for (int kk = 0; kk < index; kk++) { result[index].push_back('0'); }
	}

	string answer = string(result.front().begin(), result.front().end());
	for (int ii = 1; ii < result.size(); ii++) {
		answer = plusBigInteger(answer, string(result[ii].begin(), result[ii].end()));
	}

	return answer;
}

const string factorial(const int number) {

	if (number < 2) { return { "1" }; }

	// MARK: - Memorization
	if (!factori[number].empty()) { return factori[number]; }

	factori[number] = bigMultiple(to_string(number), factorial(number - 1));
	return factori[number];
}

int main(void)
{
	int number = 0; cin >> number;

	int count = 0;
	const string answer = factorial(number);

	for (int ii = answer.size() - 1; ii >= 0; ii--) {
		if (answer[ii] != '0') { cout << count << endl; break; }
		count++;
	}

	return 0;
}