#include <queue>
#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

#define PAIR pair<int, int>

vector<vector<int> > adj;
vector<vector<bool> > visit;


void BFS(const int size, PAIR start, PAIR target) {

	vector<PAIR> direct = {make_pair(-2, -1), make_pair(-2, 1), make_pair(-1, -2), make_pair(-1, 2), make_pair(1, -2), make_pair(1, 2), make_pair(2, -1), make_pair(2, 1) };

	queue<PAIR> que;
	que.push(start);

	visit[start.first][start.second] = false;

	while ( !que.empty() ) {
		
		PAIR index = que.front(); que.pop();
		const int cost = adj[index.first][index.second];

		if (index == target) { cout << adj[target.first][target.second] << endl; break; }

		for (int ii = 0, length = direct.size(); ii < length; ii++) {
			
			PAIR xy = make_pair(index.first + direct[ii].first, index.second + direct[ii].second);
			if (xy.first < 0 || xy.first > size || xy.second < 0 || xy.second > size) { continue; }

			if (visit[xy.first][xy.second]) {
				que.push(xy);
				visit[xy.first][xy.second] = false;
				adj[xy.first][xy.second] = cost + 1;
			}
		}

	}
}

int main(void)
{
	int testcase = 0;
	cin >> testcase;

	while (testcase--) {

		int number = 0;
		cin >> number;

		adj = vector<vector<int> >(number, vector<int>(number));
		visit = vector<vector<bool> >(number, vector<bool>(number, true));

		PAIR input[] = { make_pair(0, 0), make_pair(0, 0) };
		for (int ii = 0; ii < 2; ii++) { cin >> input[ii].first >> input[ii].second; }

		BFS(number - 1, input[0], input[1]);
	}

	return 0;
}