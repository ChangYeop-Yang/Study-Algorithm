#include <queue>
#include <string>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_V 1001
#define PAIR pair<int, int>

vector<string> adj;
int dist[MAX_V][MAX_V][2];

typedef struct locate {
	int x = 0, y = 0, z = 0;
	locate(int nx, int ny, int nz) { x = nx, y = ny, z = nz; }
} Locate;

void BFS(const PAIR src, const PAIR length) {
	
	queue<Locate> que;
	que.push(Locate(src.first, src.second, 0));

	dist[src.first][src.second][0] = 1;

	vector<PAIR> direct = { make_pair(1, 0), make_pair(-1, 0), make_pair(0, 1), make_pair(0, -1) };
	
	while (!que.empty()) {
		
		const Locate index = que.front(); que.pop();
		const int cost = dist[index.x][index.y][index.z]; // <X, Y, Z>

		for (int ii = 0; ii < direct.size(); ii++) {
			
			const PAIR next = make_pair(index.x + direct[ii].first, index.y + direct[ii].second);
			if (next.first < 0 || next.first > length.first || next.second < 0 || next.second > length.second) { continue; }

			// 이동할 수 있는 경우이며 벽이 아닌 경우 (0은 길, 1은 벽)
 			if (adj[next.first][next.second] == '0' && dist[next.first][next.second][index.z] == 0) {
				que.push(Locate(next.first, next.second, index.z));
				dist[next.first][next.second][index.z] = cost + 1;
			}

			// 가고자 하는 곳이 벽이면서 벽을 한 번도 부수지 않은 경우
			if (index.z == 0 && dist[next.first][next.second][index.z + 1] == 0 && adj[next.first][next.second] == '1') {
				que.push(Locate(next.first, next.second, index.z + 1));
				dist[next.first][next.second][index.z + 1] = cost + 1;
			}
		}
	}

	// 벽을 부순 경우의 값이 있거나 벽을 부수지 않은 경우의 값이 없을 경우 출력
	if (dist[length.first][length.second][0] != 0 && dist[length.first][length.second][1] != 0) { cout << min(dist[length.first][length.second][0], dist[length.first][length.second][1]) << endl; } 
	// 벽을 부수지 않은 경우의 값이 있는 경우 출력
	else if (dist[length.first][length.second][0] != 0) { cout << dist[length.first][length.second][0] << endl; }
	// 벽을 부순 경우의 값이 있는 경우 출력
	else if (dist[length.first][length.second][1] != 0) { cout << dist[length.first][length.second][1] << endl; }
	// 이동할 수 없는 경우 출력
	else { cout << -1 << endl; }
}

int main(void)
{
	PAIR input = make_pair(0, 0);
	cin >> input.first >> input.second;

	adj = vector<string>(input.first);
	for (int ii = 0; ii < input.first; ii++) { cin >> adj[ii]; }

	BFS(make_pair(0, 0), make_pair(input.first - 1, input.second - 1));
	return 0;
}