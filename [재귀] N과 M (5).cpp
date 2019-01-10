#include <vector>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

vector<bool> check;
vector<int> number;
vector<vector<int> > answer;

void reculsive(const int length, const int goal, int index, vector<int> bucket) {

	if (index > goal) { return; }
	if (index == goal) { answer.push_back(bucket); return; }

	for (int ii = 0; ii < length; ii++) {

		if (check[ii]) { continue; }

		check[ii] = true;
		bucket[index] = number[ii];
		reculsive(length, goal, index + 1, bucket);
		check[ii] = false;
	}
}

int main(void)
{
	pair<int, int> input = make_pair(0, 0);
	cin >> input.first >> input.second;

	check = vector<bool>(input.first, false);
	number = vector<int>(input.first, 0);
	for (int ii = 0; ii < input.first; ii++) {
		scanf("%d", &number[ii]);
	}

	vector<int> bucket = vector<int>(input.second);
	reculsive(input.first, input.second, 0, bucket);

	sort(answer.begin(), answer.end());
	for (const vector<int> print : answer) {
		for (const int number : print) { printf("%d ", number); }
		printf("\n");
	}

	return 0;
}