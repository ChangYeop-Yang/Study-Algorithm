#include <cmath>
#include <queue>
#include <iostream>
using namespace std;

#define INT_PAIR pair<int, int>

int main(void)
{
	int number = 0; cin >> number;

	priority_queue<INT_PAIR> pq;
	for (int ii = 0; ii < number; ii++) {

		int input = 0; scanf("%d", &input);

		// Case Non Zero
		if (input != 0) { pq.push(make_pair(-abs(input), -input)); continue; }

		// Case Empty
		if (pq.empty()) { cout << 0 << endl; continue; }

		cout << -pq.top().second << endl; pq.pop();
	}

	return 0;
}
