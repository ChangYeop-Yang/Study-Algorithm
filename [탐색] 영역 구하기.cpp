#include <queue>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define BOOL_VECTOR vector<bool>
#define INT_PAIR pair<int, int>

typedef struct Pos {
	INT_PAIR start = make_pair(0, 0);
	INT_PAIR end   = make_pair(0, 0);
} POS;

vector<BOOL_VECTOR> map;
vector<BOOL_VECTOR> visit;

int bfs(const INT_PAIR index, const INT_PAIR size) {

	const vector<INT_PAIR> direct = {make_pair(0, 1), make_pair(0, -1), make_pair(1, 0), make_pair(-1, 0)};

	queue<INT_PAIR> que;
	que.push(index);
	visit[index.first][index.second] = false;

	int count = 1;
	while (!que.empty()) {
		
		INT_PAIR here = que.front(); que.pop();

		for (int ii = 0; ii < direct.size(); ii++) {
			INT_PAIR there = make_pair(here.first + direct[ii].first, here.second + direct[ii].second);

			if (there.first < 0 || there.first >= size.first || there.second < 0 || there.second >= size.second) { continue; }
			if (map[there.first][there.second] && visit[there.first][there.second]) {
				count++;
				que.push(there);
				visit[there.first][there.second] = false;
			}
		}
	}

	return count;
}

int main(void)
{
	INT_PAIR size = make_pair(0, 0);
	cin >> size.first >> size.second;

	map = vector<BOOL_VECTOR>(size.first, BOOL_VECTOR(size.second, true));
	visit = vector<BOOL_VECTOR>(size.first, BOOL_VECTOR(size.second, true));

	int triangle = 0; cin >> triangle;
	vector<Pos> pos = vector<Pos>(triangle);
	for (int ii = 0; ii < triangle; ii++) {
		cin >> pos[ii].start.first >> pos[ii].start.second; // Input Start
		cin >> pos[ii].end.first >> pos[ii].end.second;		// Input End
	}

	// Fill Triangle
	for (const auto loc : pos) {
		for (int ii = loc.start.first; ii < loc.end.first; ii++) {
			for (int jj = loc.start.second; jj < loc.end.second; jj++) { map[jj][ii] = false; }
		}
	}

	vector<int> answer;
	for (int ii = 0; ii < size.first; ii++) {
		for (int jj = 0; jj < size.second; jj++) {
			if (map[ii][jj] && visit[ii][jj]) { answer.push_back(bfs(make_pair(ii, jj), size)); }
		}
	}

	sort(answer.begin(), answer.end());

	cout << answer.size() << endl;
	for (const auto print : answer) { cout << print << " "; }

	return 0;
}