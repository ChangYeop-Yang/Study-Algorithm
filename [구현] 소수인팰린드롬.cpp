#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
			 
// 100,000,000까지의 마지막 회문수는 9989899이다.
#define MAX_V 9989899
#define LONG long long
#define INT_PAIR pair<int, int>
#define STRING_PAIR pair<string, string>

vector<int> palindrome;
vector<bool> prime = vector<bool>(MAX_V + 1);

void setPalindrome(const int prime) {

	STRING_PAIR comp = make_pair(string(), string());
	comp.first = comp.second = to_string(prime);

	reverse(comp.second.begin(), comp.second.end());

	if (comp.first == comp.second) { palindrome.push_back(prime); }
}

void setPrime(INT_PAIR index) {

	if (index.second > MAX_V) { index.second = MAX_V; }
	
	for (LONG ii = 2; ii <= index.second; ii++) {
		if (prime[ii] == false) {
			setPalindrome(ii);
			for (LONG jj = ii * ii; jj <= index.second; jj += ii) { prime[jj] = true; }
		}
	}
}

int main(void)
{
	INT_PAIR input = make_pair(0, 0);
	cin >> input.first >> input.second;

	setPrime(input);

	for (const auto value : palindrome) {
		if (value < input.first) { continue; }
		printf("%d\n", value);
	}

	cout << -1 << endl;

	return 0;
}