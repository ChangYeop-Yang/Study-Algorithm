#include <deque>
#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>
using namespace std;

int main(void)
{
	int input = 0; cin >> input;

	vector<string> bucket = vector<string>(input);
	for (int ii = 0; ii < bucket.size(); ii++) { cin >> bucket[ii]; }

	deque<string> answer;
	for (const auto target : bucket) {

		answer.push_back(target);
		unordered_set<char> duplicate;
		for (int ii = 0; ii < target.size() - 1; ii++) {
			// Case Not Group Word.
			if (target[ii] != target[ii + 1] && duplicate.find(target[ii + 1]) != duplicate.end()) { answer.pop_front(); break; }
			
			if (duplicate.find(target[ii]) == duplicate.end()) { duplicate.insert(target[ii]); }
		}
	}

	cout << answer.size() << endl;

	return 0;
}
