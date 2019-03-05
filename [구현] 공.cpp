#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define INT_PAIR pair<int, int>

int main(void)
{
	int swap = 0; cin >> swap;

	vector<bool> cups = {true, false, false};
	for (int ii = 0; ii < swap; ii++) {
		INT_PAIR pos = make_pair(0, 0);
		cin >> pos.first >> pos.second;

		std::swap(cups[pos.first - 1], cups[pos.second - 1]);
	}

	for (int ii = 0; ii < cups.size(); ii++) {
		if (cups[ii]) { cout << ii + 1 << endl; break; }
	}

	return 0;
}
