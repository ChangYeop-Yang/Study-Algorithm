#include <bitset>
#include <vector>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

vector<vector<size_t>> answer;

void reculsive(size_t index, const size_t length, const size_t goal, vector<size_t> bucket) {

	if (index > goal) { return; }
	if (index == goal) {
		answer.push_back(bucket);
		return;
	}

	for (size_t ii = 0; ii < length; ii++) {

		bucket[index] = ii + 1;
		reculsive(index + 1, length, goal, bucket);
	}
}

int main(void)
{
	pair<size_t, size_t> input = make_pair(0, 0);
	cin >> input.first >> input.second;

	vector<size_t> bucket = vector<size_t>(input.second, 0);
	reculsive(0, input.first, input.second, bucket);

	for (const vector<size_t> ans : answer) {
		for (auto begin = ans.begin(); begin != ans.end(); begin++) {
			printf("%d ", *begin);
		}
		printf("\n");
	}

	return 0;
}