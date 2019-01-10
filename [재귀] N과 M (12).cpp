#include <vector>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

vector<int> number;
set<vector<int> > answer;

void reculsive(const int length, const int goal, int index, int current, vector<int> bucket) {

	if (index > goal)	{ return; }
	if (index == goal)	{ answer.insert(bucket); return; }

	for (int ii = current; ii < length; ii++) {
		bucket[index] = number[ii];
		reculsive(length, goal, index + 1, ii, bucket);
	}
}

int main(void)
{
	pair<int, int> input = make_pair(0, 0);
	cin >> input.first >> input.second;

	number = vector<int>(input.first, 0);

	for (int ii = 0; ii < input.first; ii++) { scanf("%d", &number[ii]); }
	sort(number.begin(), number.end());

	vector<int> bucket = vector<int>(input.second);
	reculsive(input.first, input.second, 0, 0, bucket);

	for (const vector<int> print : answer) {
		for (const int number : print) { printf("%d ", number); }
		printf("\n");
	}

	return 0;
}