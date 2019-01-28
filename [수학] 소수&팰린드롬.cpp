#include <string>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_V 1043402
#define LONG long long

bool prime[MAX_V + 1];
vector<int> answer;

void getPrime() {

	for (LONG ii = 2; ii <= MAX_V; ii++) {

		if (prime[ii] == false) {
			answer.push_back(ii);
			for (LONG jj = ii * ii; jj <= MAX_V; jj += ii) { prime[jj] = true; }
		}
	}
}

const bool palindromic(const int number) {

	string value = to_string(number);
	reverse(value.begin(), value.end());

	return stoi(value) - number == 0 ? true : false;
}

int main(void)
{
	int input = 0; cin >> input;

	getPrime();

	if (input < 10 && input > 1 && prime[input] == false) { cout << input << endl; return 0; }

	for (int ii = 0, length = answer.size(); ii < length; ii++) {
		if (answer[ii] >= input && palindromic(answer[ii])) { cout << answer[ii] << endl; break; }
	}

	return 0;
}
