#include <cmath>
#include <vector>
#include <cstdio>
#include <climits>
#include <iostream>
#include <algorithm>
using namespace std;

#define INT_VECTOR vector<int>
#define INT_PAIR pair<int, int>

void createPersonSet(const int length, INT_PAIR index, vector<int> bucket, vector<INT_VECTOR> & set, const vector<int> person) {

	// Case Out of Range
	if (length / 2 < index.first) { return; }

	// Case Goal
	if (length / 2 == index.first) { set.push_back(bucket); return; }

	for (int ii = index.second; ii < length; ii++) {
		bucket[index.first] = person[ii];
		createPersonSet(length, make_pair(index.first + 1, ii + 1), bucket, set, person);
	}
}

const int generation() {
	static int number = 0;
	return ++number;
}

int contentSum(const vector<int> index, const vector<INT_VECTOR> map) {
	
	int sum = 0;

	for (int ii = 0; ii < index.size(); ii++) {
		for (int jj = 0; jj < index.size(); jj++) {
			if (ii == jj) { continue; }
			const INT_PAIR here = make_pair(index[ii] - 1, index[jj] - 1);
			sum += map[here.first][here.second];
		}
	}
	
	return sum;
}

int main(void)
{
	int length = 0; cin >> length;

	vector<INT_VECTOR> map = vector<INT_VECTOR>(length, INT_VECTOR(length));
	for (int ii = 0; ii < length; ii++) {
		for (int jj = 0; jj < length; jj++) { scanf("%d", &map[ii][jj]); }
	}

	vector<int> person = vector<int>(length);
	generate(person.begin(), person.end(), generation);

	int answer = INT_MAX;
	vector<INT_VECTOR> personSet;
	createPersonSet(length, make_pair(0, 0), vector<int>(length / 2), personSet, person);

	for (int ii = 0, jj = personSet.size() - 1; ii < jj; ii++, jj--) {
		const INT_PAIR val = make_pair(contentSum(personSet[ii], map), contentSum(personSet[jj], map));
		answer = min(answer, abs(val.first - val.second));
	}

	cout << answer << endl;

	return 0;
}
