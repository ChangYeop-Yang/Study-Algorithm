#include <climits>
#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

#define MAX_C 1000000

const int possible(const int target, const unordered_set<int> & keys) {

	if (target == 0) { return keys.find(target) != keys.end() ? 0 : 1; }

	int len = 0;
	for (int ii = target; ii > 0; ii /= 10) {
		if (keys.find(ii % 10) != keys.end()) { return 0; }
		len++;
	}
	return len;
}

int main(void)
{
	int target = 0, malfunction = 0;
	cin >> target >> malfunction;

	// MARK: - 채널 0에서 -를 누른 경우에는 채널이 변하지 않고, 채널은 무한대 만큼 있다.
	unordered_set<int> malfunctionKeys;
	for (int ii = 0, key = 0; ii < malfunction; ii++) { 
		cin >> key;
		malfunctionKeys.insert(key);
	}

	// MARK: - 초기값 채널인 100에서 아무런 숫자 버튼을 누르지 않는 경우
	int answer = target - 100;
	if (answer < 0) { answer = -answer; }

	// MARK: - 채널 N (0 ≤ N ≤ 500,000)은 만약 채널의 시작이 0번인 경우 모든 버튼이 고장나서 500,000까지 가려면 +500,000만을 한다. 그리고 -을 통해서 500,000만을 가려면 100,000,000에서 시작해야 한다.
	for (int ii = 0; ii <= MAX_C; ii++) {
		// MARK: - C에 포함되어 있는 숫자 중에 고장난 버튼이 있는지 확인한다.
		const int length = possible(ii, malfunctionKeys);
		if (length == 0) { continue; }
		
		int press = ii - target;
		if (press < 0) { press = -press; }

		answer = std::min(answer, press + length);
	}

	/*	※ LOGIC ※
		ⓐ 이동할 채널 C를 정한다.
		ⓑ C에 포함되어 있는 숫자 중에 고장난 버튼이 있는지 확인한다.
		ⓒ 고장난 버튼이 포함되어 있지 않다면 |C-N|을 계산하여 +나 -버튼을 몇 번 눌러야하는지 계산한다.
	*/
	cout << answer << endl;

	return 0;
}