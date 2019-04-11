#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define NONE 0

vector<int> solution(vector<int> heights) {

	vector<int> answer;

	// MARK: - 왼쪽으로 동시에 레이저 신호를 발사합니다. 
	while (!heights.empty()) {
		
		bool isFind = false;
		const int top = heights.back(); heights.pop_back();

		// MARK: - 발사한 신호는 신호를 보낸 탑보다 높은 탑에서만 수신합니다. 또한, 한 번 수신된 신호는 다른 탑으로 송신되지 않습니다.
		for (int index = heights.size() - 1; index >= 0; index--) {
			if (top < heights[index]) { answer.push_back(index + 1); isFind = true; break; }
		}

		// MARK: 신호를 수신하는 탑이 없으면 0으로 표시합니다.
		if (isFind == false) { answer.push_back(NONE); }
	}
	
	// MARK: - 맨 왼쪽부터 순서대로 탑의 높이를 담은 배열 heights가 매개변수로 주어질 때 각 탑이 쏜 신호를 어느 탑에서 받았는지 기록한 배열을 return 하도록 solution 함수를 작성해주세요.
	std::reverse(answer.begin(), answer.end());
	return answer;
}
