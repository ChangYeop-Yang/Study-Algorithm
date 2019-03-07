#include <string>
#include <climits>
#include <iostream>
#include <algorithm>
using namespace std;

#define STRING_PAIR pair<string, string>

int main(void)
{
	STRING_PAIR input = make_pair(string(), string());
	cin >> input.first >> input.second;

	int answer = INT_MAX;

	const int diff = input.second.size() - input.first.size();
	for (int ii = 0; ii <= diff; ii++) {
		int letter = 0;
		for (int jj = 0, kk = ii; jj < input.first.size(); jj++, kk++) {
			if (input.first[jj] != input.second[kk]) { letter++; }
		}
		answer = std::min(letter, answer);
	}

	cout << answer << endl;

	return 0;
}