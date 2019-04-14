#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

#define MIN_E 1
#define INT_PRIORITY int, vector<int>, greater<int>

const int calculateScoville(priority_queue<INT_PRIORITY> & scovilles) {

	const int lower_Scoville = scovilles.top(); scovilles.pop();
	const int second_LowerScoville = scovilles.top(); scovilles.pop();

	// MARK: - 섞은 음식의 스코빌 지수 = 가장 맵지 않은 음식의 스코빌 지수 + (두 번째로 맵지 않은 음식의 스코빌 지수 * 2)
	return lower_Scoville + (second_LowerScoville * 2);
}

int solution(vector<int> scoville, int K) {

	int answer = 0;
	// MARK: - 스코빌 지수가 가장 낮은 두 개의 음식을 아래와 같이 특별한 방법으로 섞어 새로운 음식을 만듭니다.
	priority_queue<INT_PRIORITY> scovilles = priority_queue<INT_PRIORITY>(scoville.begin(), scoville.end());

	// MARK: - Leo는 모든 음식의 스코빌 지수가 K 이상이 될 때까지 반복하여 섞습니다.
	while (true) {

		// MARK: - 모든 음식의 스코빌 지수를 K 이상으로 만들기 위해 섞어야 하는 최소 횟수를 return 하도록 solution 함수를 작성해주세요.
		if (scovilles.top() >= K || scovilles.size() <= MIN_E) { break; }

		const int processing_Scoville = calculateScoville(scovilles);
		scovilles.push(processing_Scoville);
		answer++;
	}
	
	// MARK: - 모든 음식의 스코빌 지수를 K 이상으로 만들 수 없는 경우에는 -1을 return 합니다.
	return scovilles.top() >= K ? answer : EOF;
}
