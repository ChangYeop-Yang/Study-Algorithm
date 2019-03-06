#include <deque>
#include <string>
#include <vector>
#include <cstdio>
#include <iostream>
using namespace std;

#define MAX_V 4
#define MAX_E 8
#define REAR 6
#define FRONT 2
#define CLOCK_WISE 1
#define COUNTER_CLOCK_WISE -1
#define INT_PAIR pair<int, int>

deque<short> gear[MAX_V];

bool clockWise(deque<short> & target) {
	const short element = target.back();
	target.pop_back(); target.push_front(element);
	return true;
}

bool counterClockWise(deque<short> & target) {
	const short element = target.front();
	target.pop_front(); target.push_back(element);
	return false;
}

int main(void)
{
	string value = string();
	for (int ii = 0; ii < MAX_V; ii++) {
		cin >> value;
		gear[ii] = deque<short>(MAX_E);		
		for (int jj = 0; jj < MAX_E; jj++) { gear[ii][jj] = value[jj] - '0'; }
	}

	int circle = 0; cin >> circle;
	vector<INT_PAIR> direct = vector<INT_PAIR>(circle);
	for (int ii = 0; ii < circle; ii++) {
		cin >> direct[ii].first >> direct[ii].second;
	}

	// 톱니바퀴가 회전할 때, 서로 맞닿은 극에 따라서 옆에 있는 톱니바퀴를 회전시킬 수도 있고, 회전시키지 않을 수도 있다. 톱니바퀴 A를 회전할 때, 
	// 그 옆에 있는 톱니바퀴 B와 서로 맞닿은 톱니의 극이 다르다면, B는 A가 회전한 방향과 반대방향으로 회전하게 된다.
	for (const auto direction : direct) { // 우선, 회전 할 톱니바퀴를 찾은 후 톱니바퀴를 회전시킨다.

		const int index = direction.first - 1;

		vector<short> isDirect = vector<short>(MAX_V);
		isDirect[index] = direction.second; // Point Gear Direction

		// Case Check Remainder Gears Control - Direct Left
		for (int ii = index; ii > 0; ii--) {
			if (gear[ii][REAR] == gear[ii - 1][FRONT]) { break; }
			isDirect[ii - 1] = isDirect[ii] == CLOCK_WISE ? COUNTER_CLOCK_WISE : CLOCK_WISE;
		}

		// Case Check Remainder Gears Control - Direct Right
		for (int ii = index; ii < MAX_V - 1; ii++) {
			if (gear[ii][FRONT] == gear[ii + 1][REAR]) { break; }
			isDirect[ii + 1] = isDirect[ii] == CLOCK_WISE ? COUNTER_CLOCK_WISE : CLOCK_WISE;
		}

		// Case Control All Gear
		for (int ii = 0; ii < MAX_V; ii++) {
			if (isDirect[ii] == CLOCK_WISE) { clockWise(gear[ii]); }
			else if (isDirect[ii] == COUNTER_CLOCK_WISE) { counterClockWise(gear[ii]); }
		}
	}

	int answer = 0;
	for (int ii = 0, score = 1; ii < MAX_V; ii++, score *= 2) {
		if (gear[ii].front() == 1) { answer += score; }
	}

	cout << answer << endl;

	return 0;
}