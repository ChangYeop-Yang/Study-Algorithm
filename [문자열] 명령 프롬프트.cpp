#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

#define CHAR_PAIR pair<char, bool>

int main(void)
{
	int input = 0; cin >> input;

	vector<string> names = vector<string>(input);
	for (int ii = 0; ii < input; ii++) { cin >> names[ii]; }

	vector<CHAR_PAIR> answer;

	// Case First Insert
	for (int ii = 0; ii < names.front().size(); ii++) {
		const auto node = make_pair(names.front().at(ii), false);
		answer.push_back(node); 
	}

	// Case First Next
	for (int ii = 1; ii < names.size(); ii++) {
		for (int jj = 0; jj < names.at(ii).size(); jj++) { 
			if (answer[jj].first == names[ii][jj]) { continue; }
			answer[jj].second = true;
		}
	}

	for (const auto letter : answer) { printf("%c", letter.second ? '?' : letter.first); }

	return 0;
}
