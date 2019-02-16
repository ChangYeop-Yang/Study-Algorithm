#include <queue>
#include <iostream>
using namespace std;

#define INT_VECTOR vector<int>
#define INT_PAIR pair<int, int>

int main(void)
{
	INT_PAIR input = make_pair(0, 0);
	cin >> input.first >> input.second;

	vector<int> degree = vector<int>(input.first);
	vector<INT_VECTOR> adj = vector<INT_VECTOR>(input.first);
	for (int ii = 0; ii < input.second; ii++) {
		INT_PAIR pos = make_pair(0, 0);
		cin >> pos.first >> pos.second;

		// 위상정렬의 핵심은 들어오는 간선이 하나도 없는 정점들을 찾아서 결과를 찾는다.
		degree[pos.second - 1]++;
		adj[pos.first - 1].push_back(pos.second - 1);
	}

	priority_queue<int> pq;
	// 간선이 하나도 존재하지 않는 정점을 우선순위 큐에 넣는다.
	for (int ii = 0; ii < degree.size(); ii++) { if (degree[ii] == 0) { pq.push(-ii); } }

	// Degree가 0이 되는 것을 Priority Queue에 추가해주며 Queue가 Empty가 될 때 까지 반복한다.
	while (!pq.empty()) {
		// Priority Queue에서 Pop의 순서가 위상 정렬의 순서가 된다.
		const int here = -pq.top(); pq.pop();
		cout << here + 1 << " ";

		// 현재 Vertax의 Degree를 하나 씩 감소시켜주면서 Degree가 0이 되면 Priority Queue에 저장한다.
		for (int ii = 0; ii < adj[here].size(); ii++) {
			const int there = adj[here][ii];
			degree[there]--; // 현재 Vertax에 연결 된 다음 Vertax의 대한 차수를 하나 감소한다.
			if (degree[there] == 0) { pq.push(-there); } // Degree가 0이 되면 Priroirty Queue에 넣는다.
		}
	}

	cout << endl;

	return 0;
}
