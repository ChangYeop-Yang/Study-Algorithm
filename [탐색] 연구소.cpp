#include <queue>
#include <vector>
#include <cstdio>
#include <climits>
#include <iostream>
#include <algorithm>
using namespace std;

#define INT_VECTOR vector<int>
#define INT_PAIR pair<int, int>
#define BOOL_VECTOR vector<bool>

#define HOLE 0
#define WALL 1
#define VIRUS 2
#define MAX_WALL 3

const vector<INT_PAIR> direct = { make_pair(1, 0), make_pair(-1, 0), make_pair(0, 1), make_pair(0, -1) };

// 0 - hole, 1 - Wall, 2 - Virus
int bfs(const INT_PAIR length, queue<INT_PAIR> que, vector<INT_VECTOR> map, vector<BOOL_VECTOR> visited) {

	int answer = 0;

	while (!que.empty()) {

		const INT_PAIR here = que.front(); que.pop();

		for (int ii = 0; ii < direct.size(); ii++) {
			
			const INT_PAIR there = make_pair(direct[ii].first + here.first, direct[ii].second + here.second);
			
			// Case Out of Range
			if (there.first < 0 || there.first >= length.first || there.second < 0 || there.second >= length.second) { continue; }
			
			// Case Empty Hole and Not Visited
			if (map[there.first][there.second] == HOLE && visited[there.first][there.second] == false) {
				que.push(there);
				map[there.first][there.second] = VIRUS;
				visited[there.first][there.second] = true;
			}
		}
	}

	// Counting Zero (Wall)
	for (const auto out : map) {
		for (const auto in : out) { if (in == 0) { answer++; } }
	}

	return answer;
}

void backtracking(const INT_PAIR length, queue<INT_PAIR> que, vector<INT_VECTOR> map, vector<BOOL_VECTOR> visited, int depth, int & answer) {

	// Case 벽의 개수는 3개이며, 꼭 3개를 세워야 한다.
	if (depth == MAX_WALL) { answer = max(answer, bfs(length, que, map, visited)); return; }

	for (int ii = 0; ii < length.first; ii++) {
		for (int jj = 0; jj < length.second; jj++) {
			// Case 벽을 세우고자 하는 곳에 바이러스이거나 벽인 경우는 버린다.
			if (map[ii][jj] == VIRUS || map[ii][jj] == WALL) { continue; }
			map[ii][jj] = WALL;
			backtracking(length, que, map, visited, depth + 1, answer);
			map[ii][jj] = HOLE;
		}
	}
}

int main(void)
{
	INT_PAIR input = make_pair(0, 0);
	cin >> input.first >> input.second;

	// Vector
	vector<INT_VECTOR> map = vector<INT_VECTOR>(input.first, INT_VECTOR(input.second));
	vector<BOOL_VECTOR> visited = vector<BOOL_VECTOR>(input.first, BOOL_VECTOR(input.second));

	// Virus Position
	queue<INT_PAIR> que;

	// Input
	for (int ii = 0; ii < input.first; ii++) {
		for (int jj = 0; jj < input.second; jj++) { 
			scanf("%d", &map[ii][jj]);
			// Case Virus Position
			if (map[ii][jj] == 2) { que.push(make_pair(ii, jj)); }
		}
	}

	int answer = INT_MIN;
	backtracking(input, que, map, visited, 0, answer);
	cout << answer << endl;

	return 0;
}