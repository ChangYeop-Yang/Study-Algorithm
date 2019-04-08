#include <deque>
#include <vector>
#include <iostream>
using namespace std;

#define MAX_P 100

#define INT_PAIR pair<int, int>
#define DEQUE_ITERATOR deque<INT_PAIR>::iterator

vector<int> solution(vector<int> progresses, vector<int> speeds) {

	vector<int> answer;

	// MARK: - 각 기능은 진도가 100%일 때 서비스에 반영할 수 있습니다.
	deque<INT_PAIR> completeJop;
	for (int ii = 0; ii < progresses.size(); ii++) { completeJop.push_back(make_pair(progresses[ii], speeds[ii])); }

	/* ※ CAPTION ※
		각 기능의 개발속도는 모두 다르기 때문에 뒤에 있는 기능이 앞에 있는 기능보다 먼저 개발될 수 있고, 
		이때 뒤에 있는 기능은 앞에 있는 기능이 배포될 때 함께 배포됩니다.
	*/
	while (!completeJop.empty()) {

		vector<DEQUE_ITERATOR> complete;

		// MARK: - 하루에 X %의 속도를 통하여 작업을 수행한다.
		for (auto & jop : completeJop) { jop.first += jop.second; }

		// MARK: - 배포는 하루에 한 번만 할 수 있으며, 하루의 끝에 이루어진다고 가정합니다.
		for (auto begin = completeJop.begin(); begin != completeJop.end(); begin++) {
			const auto jop = *begin;
			
			if (jop.first >= MAX_P) { complete.push_back(begin); continue; }
			break;
		}

		if (complete.empty() == false) {
			answer.push_back(complete.size());
			for (const auto begin : complete) { completeJop.erase(begin); }
		}
	}

	return answer;
}
