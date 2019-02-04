#include <vector>
#include <climits>
#include <iostream>
#include <algorithm>
using namespace std;

#define PAIR pair<int, int>
#define VECTOR vector<int>

void floyd(const int size, vector<VECTOR> & adj) {

	for (int ii = 1; ii <= size; ii++) { adj[ii][ii] = 0; }

	for (int kk = 1; kk <= size; kk++) {
		for (int ii = 1; ii <= size; ii++) {
			for (int jj = 1; jj <= size; jj++) {
				if (adj[ii][kk] == INT_MAX || adj[kk][jj] == INT_MAX) { continue; }
				adj[ii][jj] = min(adj[ii][jj], adj[ii][kk] + adj[kk][jj]);
			}
		}
	}

}

int main(void)
{
	int x, y, z; cin >> x >> y >> z;

	vector<VECTOR> adj = vector<VECTOR>(x + 1, vector<int>(x + 1, INT_MAX));
	for (int ii = 0; ii < y; ii++) {
		int a, b, c; cin >> a >> b >> c;
		adj[a][b] = c;
	}

	floyd(x, adj);

	int answer = INT_MIN;
	for (int ii = 1; ii <= x; ii++) {
		// 모든 학생들은 집에서 X에 갈수 있고, X에서 집으로 돌아올 수 있는 데이터만 입력으로 주어진다.
		answer = max(answer, adj[ii][z] + adj[z][ii]);
	}
	
	cout << answer << endl;

 	return 0;
}