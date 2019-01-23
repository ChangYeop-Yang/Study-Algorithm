#include <vector>
#include <climits>
#include <iostream>
#include <algorithm>
using namespace std;

#define PAIR pair<int, int>

int answer = INT_MIN;

void reculsive(int day, int cost, const vector<PAIR> table) {

	if (day > table.size())  { return; } // 퇴사하는 날을 넘어간 경우
	if (day == table.size()) { answer = max(cost, answer); return; } // 퇴사하는 날인 경우

	reculsive(day + table[day].first, cost + table[day].second, table); // 상담을 하는 경우 (날짜를 더해주고, 비용을 더하여 준다.)
	reculsive(day + 1, cost, table); // 상담을 하지 않는 경우 (상담을 하지 않은 경우에도 날짜는 흐르므로 날짜를 1 더하여 준다.)
}

int main(void)
{
	int day = 0; cin >> day;
	
	vector<PAIR> table = vector<PAIR>(day, make_pair(0, 0));
	for (int ii = 0; ii < day; ii++) { cin >> table[ii].first >> table[ii].second; }

	reculsive(0, 0, table);
	cout << answer << endl;

	return 0;
}