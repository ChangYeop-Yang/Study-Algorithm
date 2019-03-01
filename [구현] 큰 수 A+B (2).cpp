#include <deque>
#include <string>
#include <iostream>
using namespace std;

#define CARRY 10
#define INT_PAIR pair<int, int>
#define STRING_PAIR pair<string, string>

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

int main(void)
{
	STRING_PAIR input = make_pair(string(), string());
	cin >> input.first >> input.second;

	cout << plusBigInteger(input.first, input.second) << endl;

	return 0;
}