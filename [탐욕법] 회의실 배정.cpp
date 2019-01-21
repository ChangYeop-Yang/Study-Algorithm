#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define PAIR pair<int, int>

vector<PAIR> schedule;

bool compare(const PAIR comp1, const PAIR comp2) {
	// 회의의 종료시간이 같을 경우에는 시작시간이 이른 순으로 정렬한다.
	if (comp1.second == comp2.second) { return comp1.first < comp2.first; }
	else { return comp1.second < comp2.second; }
}

int main(void)
{
	int time = 0; cin >> time;

	schedule = vector<PAIR>(time);
	for (int ii = 0; ii < time; ii++) { scanf("%d %d", &schedule[ii].first, &schedule[ii].second); }
	
	// 회의의 끝나는 시간이 가장 작은 시간 순으로 정렬한다.
	sort(schedule.begin(), schedule.end(), compare);

	// <Count, Begin Time(회의의 종료 된 시간이 결국 다음 회의의 시간)>
	PAIR answer = make_pair(0, 0);
	for (long ii = 0; ii < time; ii++) {
		
		// <회의 시작 시간, 회의 종료 시간>
		PAIR currentTime = schedule[ii];

		// 회의의 끝난 시간으로 값을 갱신한다.
		if (answer.second <= currentTime.first) {
			answer.second = currentTime.second;
			answer.first++;
		}
	}

	cout << answer.first << endl;

	return 0;
}