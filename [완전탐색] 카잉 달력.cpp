#include <iostream>
using namespace std;

#define INT_PAIR pair<int, int>

int main(void)
{
	int testcase = 0; cin >> testcase;

	while (testcase--) {
		
		int answer = EOF;
		
		INT_PAIR input = make_pair(0, 0), target = make_pair(0, 0);
		cin >> input.first >> input.second >> target.first >> target.second;

		// MARK: - <M:N>은 카잉 달력의 마지막 해를 나타낸다.
		for (int year = target.first - 1; year < (input.first * input.second); year += input.first) {
			const int day = year % input.second;
			if (day == target.second - 1) { answer = year + 1; break; }
		}

		// MARK: - 만일 <x:y>에 의해 표현되는 해가 없다면, 즉, <x:y>가 유효하지 않은 표현이면, -1을 출력한다.
		cout << answer << endl;
	}

	return 0;
}