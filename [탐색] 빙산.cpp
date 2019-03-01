#include <queue>
#include <vector>
#include <cstdio>
#include <iostream>
using namespace std;

#define INT_VECTOR vector<short>
#define INT_PAIR pair<short, short>
#define BOOL_VECTOR vector<bool>

vector<INT_VECTOR> map;
vector<INT_VECTOR> yearMap;
vector<BOOL_VECTOR> visited;
const vector<INT_PAIR> direct = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

void findBingsan(INT_PAIR index, const INT_PAIR length) {

	visited[index.first][index.second] = true;

	for (int ii = 0; ii < direct.size(); ii++) {
		const INT_PAIR there = make_pair(index.first + direct[ii].first, index.second + direct[ii].second);

		if (there.first < 0 || there.first >= length.first || there.second < 0 || there.second >= length.second) { continue; }
		
		if (map[there.first][there.second] == 0) { yearMap[index.first][index.second]++; }
		if (map[there.first][there.second] != 0 && visited[there.first][there.second] == false) { findBingsan(there, length); }
	}
}

const int findBingsanNumber(const INT_PAIR length) {

	int result = 0;
	for (int ii = 1; ii < length.first - 1; ii++) {
		for (int jj = 1; jj < length.second - 1; jj++) {
			if (visited[ii][jj] == false && map[ii][jj] != 0) { findBingsan(make_pair(ii, jj), length); result++; }
		}
	}
	
	return result;
}

const int findSeeRange(const INT_PAIR index, const INT_PAIR length) {

	int count = 0;

	for (int ii = 0; ii < direct.size(); ii++) {
		const INT_PAIR there = make_pair(index.first + direct[ii].first, index.second + direct[ii].second);
		if (there.first < 0 || there.first >= length.first || there.second < 0 || there.second >= length.second) { continue; }

		if (map[there.first][there.second] == 0) { count++; }
	}

	return count;
}

int main(void)
{
	INT_PAIR input = make_pair(0, 0);
	cin >> input.first >> input.second;

	map = vector<INT_VECTOR>(input.first, INT_VECTOR(input.second));
	visited = vector<BOOL_VECTOR>(input.first, BOOL_VECTOR(input.second));

	for (int ii = 0; ii < input.first; ii++) {
		for (int jj = 0; jj < input.second; jj++) { scanf("%hd", &map[ii][jj]); }
	}

	int answer = 0;
	yearMap = vector<INT_VECTOR>(input.first, INT_VECTOR(input.second));

	while (true) {

		// Count Bingsan Component.
		const int number = findBingsanNumber(input);
		if (number == 0) { cout << 0 << endl; break; } // Case 만일 빙산이 다 녹을 때까지 분리되지 않으면 0을 출력한다.
		else if (number >= 2) { cout << answer << endl; break; } // Case 빙산이 두 덩어리 이상으로 분리되는 최초의 시간.

		// Case Find See Range.
		/*for (int ii = 1; ii < input.first - 1; ii++) {
			for (int jj = 1; jj < input.second; jj++) {
				yearMap[ii][jj] = findSeeRange(make_pair(ii, jj), input);
			}
		}*/

		for (int ii = 1; ii < input.first - 1; ii++) {
			for (int jj = 1; jj < input.second - 1; jj++) {

				const int value = map[ii][jj] - yearMap[ii][jj];
				yearMap[ii][jj] = 0;
				visited[ii][jj] = false;

				// Case BingSan Value is Zero.
				if (value <= 0) { map[ii][jj] = 0; continue; }

				// Case BingSan Value is not Zero.
				map[ii][jj] = value;
			}
		}

		answer++;
	}

	return 0;
}

// Method 2
#include <queue>
#include <vector>
#include <cstdio>
#include <iostream>
using namespace std;

#define INT_VECTOR vector<short>
#define INT_PAIR pair<short, short>
#define BOOL_VECTOR vector<bool>

queue<INT_PAIR> que;
vector<INT_VECTOR> map;
vector<INT_VECTOR> yearMap;
vector<BOOL_VECTOR> visited;
const vector<INT_PAIR> direct = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

void findBingsan(INT_PAIR index, const INT_PAIR length) {

	visited[index.first][index.second] = true;

	for (int ii = 0; ii < direct.size(); ii++) {
		const INT_PAIR there = make_pair(index.first + direct[ii].first, index.second + direct[ii].second);

		if (there.first < 0 || there.first >= length.first || there.second < 0 || there.second >= length.second) { continue; }
		if (map[there.first][there.second] != 0 && visited[there.first][there.second] == false) { findBingsan(there, length); }
	}
}

const int findSeeRange(const INT_PAIR index, const INT_PAIR length) {

	int count = 0;

	for (int ii = 0; ii < direct.size(); ii++) {
		const INT_PAIR there = make_pair(index.first + direct[ii].first, index.second + direct[ii].second);
		if (there.first < 0 || there.first >= length.first || there.second < 0 || there.second >= length.second) { continue; }

		if (map[there.first][there.second] == 0) { count++; }
	}

	return count;
}

int main(void)
{
	INT_PAIR input = make_pair(0, 0);
	cin >> input.first >> input.second;

	map = vector<INT_VECTOR>(input.first, INT_VECTOR(input.second));
	visited = vector<BOOL_VECTOR>(input.first, BOOL_VECTOR(input.second));

	for (int ii = 0; ii < input.first; ii++) {
		for (int jj = 0; jj < input.second; jj++) {
			scanf("%hd", &map[ii][jj]);
			if (map[ii][jj] != 0) { que.push(make_pair(ii, jj)); }
		}
	}

	yearMap = vector<INT_VECTOR>(input.first, INT_VECTOR(input.second));
	
	int answer = 0;
	while (true) {

		int count = 0;
		while (!que.empty()) { // Count Bingsan Component.
			const INT_PAIR here = que.front(); que.pop();
			if (visited[here.first][here.second] == false && map[here.first][here.second] != 0) { findBingsan(here, input); count++; }
		}

		if (count == 0) { cout << count << endl; break; } // Case 만일 빙산이 다 녹을 때까지 분리되지 않으면 0을 출력한다.
		else if (count >= 2) { cout << answer << endl; break; } // Case 빙산이 두 덩어리 이상으로 분리되는 최초의 시간.

		// Case Find See Range.
		for (int ii = 1; ii < input.first - 1; ii++) {
			for (int jj = 1; jj < input.second; jj++) { yearMap[ii][jj] = findSeeRange(make_pair(ii, jj), input); }
		}

		for (int ii = 1; ii < input.first - 1; ii++) { // 배열의 첫 번째 행과 열, 마지막 행과 열에는 항상 0으로 채워진다.
			for (int jj = 1; jj < input.second - 1; jj++) {
				
				const int value = map[ii][jj] - yearMap[ii][jj];
				yearMap[ii][jj] = 0, visited[ii][jj] = false;

				// Case BingSan Value is Zero.
				if (value <= 0) { map[ii][jj] = 0; continue; }

				// Case BingSan Value is not Zero.
				map[ii][jj] = value;
				que.push(make_pair(ii, jj));
			}
		}

		answer++;
	}

	return 0;
}