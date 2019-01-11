#include <vector>
#include <cstdio>
#include <iostream>
using namespace std;

#define MAX_V 1001

vector<bool> visit;
vector<short> adj[MAX_V];

void reculsiveDFS(int index) {

	visit[index] = false;

	for (int ii = 0; ii < adj[index].size(); ii++) {
		short node = adj[index][ii];
		if (visit[node]) { reculsiveDFS(node); }
	}
}

int main(void)
{
	pair<int, int> input = make_pair(0, 0);
	cin >> input.first >> input.second;

	visit = vector<bool>(input.first, true);

	pair<short, short> scale = make_pair(0, 0);
	for (int ii = 0; ii < input.second; ii++) {
		cin >> scale.first >> scale.second;
		adj[scale.first - 1].push_back(scale.second - 1);
		adj[scale.second - 1].push_back(scale.first - 1);
	}

	int answer = 0;
	for (int ii = 0; ii < input.first; ii++) {
		if (visit[ii]) { answer++; reculsiveDFS(ii); }
	}

	cout << answer << endl;

	return 0;
}
