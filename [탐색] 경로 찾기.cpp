#include <queue>
#include <cstdio>
#include <vector>
#include <climits>
#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_V 101
#define VECTOR vector<int>

// 그래프의 인접 행렬 (adj[u][v] = u에서 v로가는 간선의 가중치 값이며 간선이 없을 경우 무한 값을 넣는다.)
vector<VECTOR> adj;

// Graph에서의 모든 정점 사이의 최단 거리를 구하는 알고리즘 (시간복잡도 V^3, 공간복잡도 V^2)
void floyd(const int v) {

	for (int kk = 0; kk < v; kk++) { // kk = 경유 노드
		for (int ii = 0; ii < v; ii++) { // ii = 출발 노드
			for (int jj = 0; jj < v; jj++) { // jj 도착 노드
				// adj[ii][kk] (출발점에서 경유점)까지 갈 수 없거나 adj[kk][jj] (경유점에서 도착점)까지 갈 수 없는 경우는 버린다.
				if (adj[ii][kk] == INT_MAX || adj[kk][jj] == INT_MAX) { continue; }

				// adj[ii][jj] (출발점에서 도착점)까지의 거리 중 adj[ii][kk] (출발점에서 경유점) + adj[kk][jj] (경유점에서 도착점)까지의 거리의 값이 더 작은 경우 [ii][jj] 값을 갱신한다.
				adj[ii][jj] = min(adj[ii][jj], adj[ii][kk] + adj[kk][jj]);
			}
		}
	} 

}

int main(void)
{
	int vertax = 0; cin >> vertax;
	adj = vector<VECTOR>(vertax, vector<int>(vertax, INT_MAX));

	for (int ii = 0; ii < vertax; ii++) {
		for (int jj = 0; jj < vertax; jj++) { 
			scanf("%d", &adj[ii][jj]); 
			if (adj[ii][jj] == 0) { adj[ii][jj] = INT_MAX; }
		}
	}

	floyd(vertax);

	for (const auto print : adj) {
		for (const int val : print) {
			cout << (val == INT_MAX ? 0 : 1) << " ";
		}
		cout << endl;
	}

	return 0;
}