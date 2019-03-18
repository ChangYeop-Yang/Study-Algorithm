#include <deque>
#include <iostream>
#include <algorithm>
using namespace std;

#define INT_PAIR pair<int, int>

const int generation() {
	static int number = 0;
	return ++number;
}

// Case 오른쪽으로 한 칸 이동시킨다. 이 연산을 수행하면, a1, ..., ak가 ak, a1, ..., ak-1이 된다.
void clockWise(deque<int> & target) {
	const int element = target.back();
	target.push_front(element), target.pop_back();
}

// Case 왼쪽으로 한 칸 이동시킨다. 이 연산을 수행하면, a1, ..., ak가 a2, ..., ak, a1이 된다.
void counterClockWise(deque<int> & target) {
	const int element = target.front();
	target.push_back(element), target.pop_front();
}

const int peekClockWise(deque<int> target, const int find) {
	int clockCount = 0;
	while (target.front() != find) { clockWise(target); clockCount++; }
	return clockCount;
}

const int peekCounterClockWise(deque<int> target, const int find) {
	int clockCount = 0;
	while (target.front() != find) { counterClockWise(target); clockCount++; }
	return clockCount;
}

int main(void)
{
	INT_PAIR input = make_pair(0, 0);
	cin >> input.first >> input.second;
	
	deque<int> bucket = deque<int>(input.second);
	for (int ii = 0; ii < input.second; ii++) { cin >> bucket[ii]; }
	
	deque<int> circle = deque<int>(input.first);
	std::generate(circle.begin(), circle.end(), generation);

	register int answer = 0;

	while (!bucket.empty()) {

		const int element = bucket.front(); bucket.pop_front();
		const INT_PAIR rotate = make_pair(peekClockWise(circle, element), peekCounterClockWise(circle, element));

		if (rotate.first < rotate.second) { /* Clock Wise */
			for (int ii = 0; ii < rotate.first; ii++) { clockWise(circle); answer++; }
		}
		else { /* Counter Clock Wise */
			for (int ii = 0; ii < rotate.second; ii++) { counterClockWise(circle); answer++; }
		}

		// Case 첫 번째 원소를 뽑아낸다. 이 연산을 수행하면, 원래 큐의 원소가 a1, ..., ak이었던 것이 a2, ..., ak와 같이 된다.
		circle.pop_front();
	}

	cout << answer << endl;

	return 0;
}