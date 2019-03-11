#include <vector>
#include <iostream>
using namespace std;

#define INT_PAIR pair<int, int>

int main(void)
{
	int input = 0; cin >> input;

	vector<INT_PAIR> answer = vector<INT_PAIR>(input);
	for (int ii = 0; ii < input; ii++) {
		INT_PAIR person = make_pair(0, 0);
		cin >> person.first >> person.second;

		answer[ii] = make_pair(person.first, person.second);
	}

	// 만일 자신보다 더 큰 덩치의 사람이 k명이라면 그 사람의 덩치 등수는 k + 1이 된다.
	for (const auto person : answer) {
		int score = 0;
		for (int ii = 0; ii < answer.size(); ii++) {
			if (person == answer[ii]) { continue; }
			if (person.first < answer[ii].first && person.second < answer[ii].second) { score++; }
		}
		cout << score + 1 << " ";
	}

	cout << endl;

	return 0;
}