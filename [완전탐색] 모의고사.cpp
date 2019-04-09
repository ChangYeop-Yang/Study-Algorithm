#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define INT_VECTOR vector<int>
#define INT_PAIR pair<int, int>

const bool compare(const INT_PAIR & comp1, const INT_PAIR & comp2) { 
	if (comp1.second == comp2.second) { return comp1.first < comp2.first; }
	else { return comp1.second > comp2.second; }
}

vector<int> solution(vector<int> answers) {
	
	const vector<INT_VECTOR> student = { {1, 2, 3, 4, 5}, {2, 1, 2, 3, 2, 4, 2, 5}, {3, 3, 1, 1, 2, 2, 4, 4, 5, 5} };

	vector<INT_PAIR> person;

	for (int jj = 0; jj < student.size(); jj++) {
		int success = 0;
		for (int ii = 0, index = 0; ii < answers.size(); ii++, index = (index + 1) % student[jj].size()) { 
			if (answers[ii] == student[jj][index]) { success++; continue; }
		}
		person.push_back(make_pair(jj + 1, success));
	}
	
	std::sort(person.begin(), person.end(), compare);
	
	vector<int> answer = { person.front().first };
	for (int ii = 1; ii < person.size(); ii++) {
		if (person[0].second == person[ii].second) { answer.push_back(person[ii].first); continue; }
	}

	return answer;
}
