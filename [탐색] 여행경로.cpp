#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define ICN "ICN"
#define STRING_VECTOR vector<vector<string>>

void findTripRoute(const int depth, const int length, const string airport, vector<bool> & visited, vector<string> & answer, vector<string> bucket, STRING_VECTOR & tickets) {

	bucket.push_back(airport);

	// MARK: - 주어진 항공권은 모두 사용해야 합니다. (즉, DFS의 깊이와 주어진 항공권의 크기와 같은 경우가 모든 항공권을 사용한 경우다.)
	if (depth == length) { answer = vector<string>(bucket.begin(), bucket.end()); return; }

	for (int ii = 0; ii < length; ii++) {

		const auto point = make_pair(tickets[ii].front(), tickets[ii].back());

		// MARK: - tickets의 각 행 [a, b]는 a 공항에서 b 공항으로 가는 항공권이 있다는 의미입니다. (즉, 현재의 도착점과 도착점에서의 출발점이 같아야한다.)
		if (point.first == airport && visited[ii] == false) {
			visited[ii] = true;
			findTripRoute(depth + 1, length, point.second, visited, answer, bucket, tickets);

			// MARK: - 주어진 항공권을 통해서 모든 경로를 구한 경우에는 종료한다.
			if (length == answer.size() - 1) { return; }
			visited[ii] = false;
		}
	}

	bucket.pop_back();
}

vector<string> solution(vector<vector<string>> tickets) {

	vector<string> answer;
	vector<bool> visited = vector<bool>(tickets.size());

	// MARK: - 만일 가능한 경로가 2개 이상일 경우 알파벳 순서가 앞서는 경로를 return 합니다.
	std::sort(tickets.begin(), tickets.end());

	// MAKR: - 항상 ICN 공항에서 출발합니다.
	findTripRoute(0, tickets.size(), ICN, visited, answer, vector<string>(), tickets);

	return answer;
}
