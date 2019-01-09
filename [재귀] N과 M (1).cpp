#include <set>
#include <vector>
#include <cstdio>
using namespace std;

set<vector<size_t> > answer;
vector<bool> check = vector<bool>(10, false);

void reculsive(size_t index, const size_t length, const size_t goal, vector<size_t> bucket) {

	if (index == goal) { answer.insert(bucket); return; }

	for (size_t ii = 1; ii <= length; ii++) {

		if (check[ii]) { continue; }

		check[ii] = true;
		bucket[index] = ii;
		reculsive(index + 1, length, goal, bucket);
		check[ii] = false;
	}
}

int main(void)
{
	pair<size_t, size_t> input = make_pair(0, 0);
	scanf("%d %d", &input.first, &input.second);

	vector<size_t> bucket = vector<size_t>(input.second, 0);
	reculsive(0, input.first, input.second, bucket);

	for (const vector<size_t> print : answer) {
		for (size_t index = 0, length = print.size(); index < length; index++) { printf("%d ", print[index]); }
		printf("\n");
	}

	return 0;
}