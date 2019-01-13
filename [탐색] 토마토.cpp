#include <queue>
#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

#define PAIR pair<int,int>

int day = 0;
queue<PAIR> que;
vector<vector<int> > adj;
vector<vector<int> > visit;
PAIR tomato = make_pair(0, 0);

// 토마토 문제는 출발점이 익은 토마토에 위치이다. 왜냐하면 토마토가 혼자 저절로 익지 못하고 익은 토마토를 통해서 영향을 받아야 하기 때문이다.
// 그래서 큐에 익은 토마토 좌표를 넣어준다.
void BFS(const int n, const int m) {

	register vector<PAIR> direct = { make_pair(1, 0), make_pair(0, 1), make_pair(-1, 0), make_pair(0, -1) };

	while (!que.empty()) {

		register const PAIR index = que.front(); que.pop();
		register const int cost = visit[index.first][index.second];

		// 토마토가 익을 때 필요한 날짜의 최대 값을 갱신한다.
		if (day < cost) { day = cost; }

		for (int ii = 0, length = direct.size(); ii < length; ii++) {
			
			register const PAIR xy = make_pair(index.first + direct[ii].first, index.second + direct[ii].second);

			// 배열의 범위를 벗어나는 경우 건너뛴다.
			if (xy.first < 0 || xy.first > n || xy.second < 0 || xy.second > m) { continue; }

			// 익은 토마토가 상하좌우로 갈 수 있는 경우
			if (visit[xy.first][xy.second] == 0 && adj[xy.first][xy.second] == 0) {
				que.push(xy);
				tomato.second++;
				visit[xy.first][xy.second] = cost + 1;
			}
		}
	}
}

int main(void)
{
	register PAIR input = make_pair(0, 0);
	cin >> input.first >> input.second;

	adj		= vector<vector<int> >(input.second, vector<int>(input.first));
	visit	= vector<vector<int> >(input.second, vector<int>(input.first));

	for (int ii = 0; ii < input.second; ii++) {
		for (int jj = 0; jj < input.first; jj++) {
			scanf("%d", &adj[ii][jj]);
			
			// 익은 토마토가 상하좌우로 영향을 주므로 익은 토마토의 위치를 큐에 저장한다.
			if (adj[ii][jj] == 1) { que.push(make_pair(ii, jj)); visit[ii][jj] = 1; }
			else if (adj[ii][jj] == 0) { tomato.first++; }
		}
	}

	BFS(input.second - 1, input.first - 1);

	// 아직 상자안에 익지 않은 토마토가 존재하는 경우 -1 출력 후 종료
	if (tomato.first != tomato.second) { cout << -1 << endl; return 0; }

	cout << day - 1 << endl;

	return 0;
}