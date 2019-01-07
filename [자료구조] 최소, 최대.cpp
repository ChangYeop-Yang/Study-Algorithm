#include <unordered_set>
#include <cstdio>
#include <climits>
#include <iostream>
using namespace std;

int main(void)
{
	int input = 0;
	cin >> input;

	pair<int, int> val = make_pair(INT_MIN, INT_MAX);

	unordered_set<int> bucket;
	for (int ii = 0; ii < input; ii++) {
		int number = 0;
		scanf_s("%d", &number);

		if (bucket.find(number) != bucket.end()) { continue; }

		bucket.insert(number);
		
		if (number > val.first) { val.first = number; }
		if (number < val.second) { val.second = number; }
	}

	cout << val.second << " " << val.first;

	return 0;
}