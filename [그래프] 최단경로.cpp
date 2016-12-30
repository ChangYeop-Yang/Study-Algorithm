#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <queue>
using namespace std;

#define INF 987654321
#define MAX_V 200001

/* Vector */
vector<pair<int, int> > adj[MAX_V]; /* 그래프의 인접 리스트 (연결된 정점 번호, 간선 가중치) 쌍을 저장 */

/* Function */
vector<int> dijkstra(int src, int V) /* V - 정점의 갯수, src - 출발점 */
{
	/* Vector */
	vector<int> dist(V, INF); /* 최단 거리 값 Vector */
	dist[src] = 0;

	/* Queue */
	priority_queue<pair<int, int> > pq;
	pq.push(make_pair(0, src));

	while (!pq.empty())
	{
		/* Integer */
		int cost = -pq.top().first;
		int here = pq.top().second; pq.pop();

		/* 만약 지금 꺼낸 값보다 더 짧은 경로를 알고 있다면 지금 꺼낸 것을 무시 */
		if (dist[here] < cost) { continue; }

		/* 인전합 정점 모두 검사 */
		int mSize = adj[here].size();
		for (int ii = 0; ii < mSize; ii++)
		{
			int there = adj[here][ii].first; /* 연결된 정점 번호 */
			int nextDist = cost + adj[here][ii].second; /* 비용 + 현 리스트의 간선 가중치 */

			/* 더 짧은 경로를 발견할 경우 큐와 최단 거리 Vector를 갱신 */
			if (dist[there] > nextDist) { dist[there] = nextDist; pq.push(make_pair(-nextDist, there)); }
		}
	}

	return dist;
}

int main(void)
{
	int mNum1 = 0, mNum2 = 0;
	cin >> mNum1 >> mNum2;

	int mStart = 0;
	cin >> mStart;

	for (int ii = 0; ii < mNum2; ii++)
	{
		int mTemp[3] = { 0,0,0 };
		scanf("%d %d %d", &mTemp[0], &mTemp[1], &mTemp[2]);

		adj[mTemp[0]].push_back(make_pair(mTemp[1], mTemp[2]));
	}

	vector<int> mVector = dijkstra(mStart, mNum1 + 1);
	int mSize = mVector.size();

	for (int ii = 1; ii < mSize; ii++)
	{
		if (mVector[ii] != INF) { cout << mVector[ii] << endl; }
		else { cout << "INF" << endl; }
	}

	return 0;
}
