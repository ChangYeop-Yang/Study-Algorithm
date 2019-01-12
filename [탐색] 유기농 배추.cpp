#include <queue>
#include <vector>
#include <cstdio>
#include <iostream>
using namespace std;

vector<vector<short> > box;
vector<vector<bool> > visit;

void BFS(int x, int y, int n, int m) {
	
	queue<pair<int, int> > que;
	que.push(make_pair(x, y));

	visit[x][y] = false;

	const vector<pair<int, int> > direct = { make_pair(1, 0), make_pair(0, 1), make_pair(-1, 0), make_pair(0, -1) };

	while (!que.empty()) {

		pair<int, int> index = que.front();
		que.pop();

 		for (int ii = 0, length = direct.size(); ii < length; ii++) {
			
			pair<int, int> xy = make_pair(index.first + direct[ii].first, index.second + direct[ii].second);

			if (xy.first < 0 || xy.first > n || xy.second < 0 || xy.second > m) { continue; }

			if (visit[xy.first][xy.second] && box[xy.first][xy.second] == 1) {
				que.push(make_pair(xy.first, xy.second));
				visit[xy.first][xy.second] = false;
			}
		}
	}
}

int main(void)
{
	int testcase = 0;
	cin >> testcase;

	while (testcase--) {

		int n = 0, m = 0, c = 0;
		scanf("%d %d %d", &n, &m, &c);

		box = vector<vector<short> >(n, vector<short>(m));
		visit = vector<vector<bool> >(n, vector<bool>(m, true));

		pair<int, int> input = make_pair(0, 0);
		for (int ii = 0; ii < c; ii++) {
			scanf("%d %d", &input.first, &input.second);
			box[input.first][input.second] = 1;
		}

		int answer = 0;
		for (int ii = 0; ii < n; ii++) {
			for (int jj = 0; jj < m; jj++) {
				if (visit[ii][jj] && box[ii][jj] == 1) { BFS(ii, jj, n - 1, m - 1); answer++; }
			}
		}

		cout << answer << endl;
	}

	return 0;
}