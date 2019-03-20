#include <deque>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

#define GOAL_TIME 0
#define INT_PAIR pair<int, int>

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	
	vector<int> answer;
	deque<INT_PAIR> passTruck;
	deque<int> waitTruck = deque<int>(truck_weights.begin(), truck_weights.end());

	INT_PAIR time_weight = make_pair(0, 0);

	while (truck_weights.size() != answer.size()) {

		time_weight.first++;

		// Case Decrease Time
		for (int ii = 0; ii < passTruck.size(); ii++) { passTruck[ii].second--; }

		// Case 다리를 건너고 있는 트럭이 다리를 지났을 경우
		if (!passTruck.empty() && passTruck.front().second == GOAL_TIME) {
			const auto truck = passTruck.front(); passTruck.pop_front();
			
			answer.push_back(truck.first);
			time_weight.second -= truck.first;
		}

		// Case 다리를 건너고 있는 트럭의 총 무게가 주어진 무게보다 작은 경우
		if (!waitTruck.empty() && time_weight.second + waitTruck.front() <= weight) {
			const int truck = waitTruck.front(); waitTruck.pop_front();
			
			time_weight.second += truck; // Truck의 Weight 증가
			passTruck.push_back(make_pair(truck, bridge_length));
		}
	}

	return time_weight.first;
}