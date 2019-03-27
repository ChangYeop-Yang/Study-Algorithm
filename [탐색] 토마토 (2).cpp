#include <queue>
#include <tuple>
#include <vector>
#include <climits>
#include <iostream>
#include <algorithm>
using namespace std;

#define EMPTY -1
#define TOMATO 1
#define MAX_V 101

#define GET(X, Y) get<X>(Y)
#define INT_PAIR pair<int, int>
#define INT_TUPLE tuple<int, int, int>
#define INT_VECTOR vector<vector<int>>

int answer = INT_MIN;
int board[MAX_V][MAX_V][MAX_V];
bool visited[MAX_V][MAX_V][MAX_V];

const int bfs(const INT_TUPLE size, queue<INT_TUPLE> & que) {

	int day = 0;

	// 하나의 토마토에 인접한 곳은 위, 아래, 왼쪽, 오른쪽, 앞, 뒤 여섯 방향에 있는 토마토를 의미한다.
	const vector<INT_TUPLE> direct = {
		make_tuple(0, 1, 0), make_tuple(0, -1, 0), make_tuple(1, 0, 0), make_tuple(-1, 0, 0), /* 위, 아래, 왼쪽, 오른쪽 방향 */
		make_tuple(0, 0, 1), make_tuple(0, 0, -1) /* 앞, 뒤 방향 */
	};

	while (!que.empty()) {

		const INT_TUPLE here = que.front(); que.pop();
		const int cost = board[GET(0, here)][GET(1, here)][GET(2, here)];

		// MARK: - 토마토가 익는 최대의 날짜 갱신
		answer = std::max(answer, cost);

		for (const auto direction : direct) {
			const INT_TUPLE there = make_tuple(GET(0, here) + GET(0, direction)
				, GET(1, here) + GET(1, direction), GET(2, here) + GET(2, direction));

			// MARK: - Out of Range
			if (GET(0, there) < 0 || GET(1, there) < 0 || GET(2, there) < 0 
				|| GET(0, there) >= GET(1, size) || GET(1, there) >= GET(0, size) || GET(2, there) >= GET(2, size)) { continue; }

			// MARK: - 방문하지 않았거나 익지 않은 토마토인 경우
			if (visited[GET(0, there)][GET(1, there)][GET(2, there)] == false 
				&& board[GET(0, there)][GET(1, there)][GET(2, there)] == 0) {
				
				day++;
				que.push(there);
				board[GET(0, there)][GET(1, there)][GET(2, there)] = cost + 1;
				visited[GET(0, there)][GET(1, there)][GET(2, there)] = true;
			}
		}
	}

	return day;
}

int main(void)
{
	INT_TUPLE size = make_tuple(0, 0, 0);
	cin >> GET(0, size) >> GET(1, size) >> GET(2, size);

	INT_PAIR tomato = make_pair(0, 0);

	queue<INT_TUPLE> que;

	for (int kk = 0; kk < GET(2, size); kk++) {
		for (int ii = 0; ii < GET(1, size); ii++) {
			for (int jj = 0; jj < GET(0, size); jj++) {
				cin >> board[ii][jj][kk];

				// MARK: - Insert Tomato position into vector.
				if (board[ii][jj][kk] == TOMATO) { que.push(make_tuple(ii, jj, kk)); visited[ii][jj][kk] = true; }
				else if (board[ii][jj][kk] == 0) { tomato.second++; }
			}
		}
	}

	tomato.first = bfs(size, que);

	// 토마토가 모두 익지는 못하는 상황이면 -1 을 출력해야 한다.
	if (tomato.first != tomato.second) { cout << EOF << endl; return 0; }

	// 토마토가 모두 익을 때까지 최소 며칠이 걸리는지를 계산해서 출력한다.
	cout << answer - 1 << endl;

	return 0;
}