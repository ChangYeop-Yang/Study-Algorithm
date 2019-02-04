#include <cstdio>
#include <vector>
#include <climits>
#include <iostream>
#include <algorithm>
using namespace std;

#define PAIR pair<int, int>
#define VECTOR vector<int>

void floyd(const int length, vector<VECTOR> & adj) {

	for (int kk = 1; kk <= length; kk++) {
		for (int ii = 1; ii <= length; ii++) {
			for (int jj = 1; jj <= length; jj++) {
				if (adj[ii][kk] == INT_MAX || adj[kk][jj] == INT_MAX) { continue; }
				adj[ii][jj] = min(adj[ii][jj], adj[ii][kk] + adj[kk][jj]);
			}
		}
	}

}

int main(void)
{
	PAIR input = make_pair(0, 0);
	cin >> input.first >> input.second;

	vector<VECTOR> adj = vector<VECTOR>(input.first + 1, vector<int>(input.first + 1, INT_MAX));
	for (int ii = 0; ii < input.second; ii++) {
		PAIR index = make_pair(0, 0);
		scanf("%d %d", &index.first, &index.second);

		adj[index.first][index.second] = adj[index.second][index.first] = 1;
	}

	floyd(input.first, adj);

	vector<int> answer = vector<int>(input.first + 1);
	for (int ii = 1; ii <= input.first; ii++) {
		for (int jj = 1; jj <= input.first; jj++) {
			if (ii == jj) { continue; }
			answer[ii] += adj[ii][jj];
		}
	}

	PAIR minVal = make_pair(INT_MAX, 0);
	for (int ii = 1; ii <= input.first; ii++) {
		if (minVal.first > answer[ii]) { minVal = make_pair(answer[ii], ii); }
	}

	cout << minVal.second << endl;

	return 0;
}