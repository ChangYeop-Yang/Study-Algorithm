#include <queue>
#include <deque>
#include <iostream>
using namespace std;

#define INT_PAIR pair<int, int>

/* Condition
ⓐ 현재 Queue의 가장 앞에 있는 문서의‘중요도’를 확인한다.
ⓑ 나머지 문서들 중 현재 문서보다 중요도가 높은 문서가 하나라도 있다면, 이 문서를 인쇄하지 않고 Queue의 가장 뒤에 재배치 한다. 그렇지 않다면 바로 인쇄를 한다.
*/

int main(void)
{
	int testcase = 0; cin >> testcase;

	while (testcase--) {
		INT_PAIR input = make_pair(0, 0);
		cin >> input.first >> input.second;

		deque<INT_PAIR> deq;
		priority_queue<int> priority;
		for (int ii = 0, number = 0; ii < input.first; ii++) {
			cin >> number; 
			deq.push_back(make_pair(number, ii)), priority.push(number);
		}
		
		int answer = 0;
		while (!deq.empty()) {

			const INT_PAIR front = deq.front();
			// Case 현재 문서보다 중요도가 높은 문서가 하나라도 있다면, 이 문서를 인쇄하지 않고 Queue의 가장 뒤에 재배치
			if (front.first < priority.top()) { deq.push_back(front), deq.pop_front(); continue; }

			// Case 그렇지 않다면 바로 인쇄를 한다.
			if (front.second == input.second) { answer++; break; }

			answer++, deq.pop_front(), priority.pop();
		}

		// 문서가 몇 번째로 인쇄되는지 출력한다.
		cout << answer << endl;
	}

	return 0;
}