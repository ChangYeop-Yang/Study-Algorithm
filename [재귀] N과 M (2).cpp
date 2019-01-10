#include <vector>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

vector<vector<size_t>> answer;
vector<bool> check;

bool duplicate(vector<size_t> comp, vector<size_t> original) {
	sort(comp.begin(), comp.end());
	return comp == original ? true : false;
}

void reculsive(size_t index, const size_t length, const size_t goal, vector<size_t> bucket) {

	if (index > goal) { return; }
	if (index == goal) {

		for (const vector<size_t> original : answer) {
			if (duplicate(bucket, original)) { return; }
		}

		answer.push_back(bucket);
		return;
	}

	for (size_t ii = 0; ii < length; ii++) {

		if (check[ii]) { continue; }

		check[ii] = true;
		bucket[index] = ii + 1;
		reculsive(index + 1, length, goal, bucket);
		check[ii] = false;
	}
}

int main(void)
{
	pair<size_t, size_t> input = make_pair(0, 0);
	cin >> input.first >> input.second;

	check	= vector<bool>(input.first, false);

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