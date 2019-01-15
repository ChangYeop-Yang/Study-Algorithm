#include <queue>
#include <string>
#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

#define VECTOR vector<short>
#define PAIR pair<short, short>

queue<PAIR> que;

vector<string> map;
vector<VECTOR> water;
vector<VECTOR> animal;

const vector<PAIR> direct = { make_pair(1, 0), make_pair(0, 1), make_pair(-1, 0), make_pair(0, -1) };

void waterBFS(PAIR start, PAIR size) {

	water[start.first][start.second] = 0;

	while (!que.empty()) {

		PAIR index = que.front(); que.pop();
		const int cost = water[index.first][index.second];

		for (int ii = 0; ii < direct.size(); ii++) {

			PAIR xy = make_pair(index.first + direct[ii].first, index.second + direct[ii].second);
			if (xy.first < 0 || xy.first > size.first || xy.second < 0 || xy.second > size.second) continue;

			if (map[xy.first][xy.second] == '.' && water[xy.first][xy.second] == -1) {
				que.push(xy);
				water[xy.first][xy.second] = cost + 1;
			}
		}
	}
}

void animalBFS(PAIR start, PAIR size) {

	que.push(start);
	animal[start.first][start.second] = 0;

	while (!que.empty()) {

		PAIR index = que.front(); que.pop();
		int cost = animal[index.first][index.second];

		for (int ii = 0; ii < direct.size(); ii++) {

			PAIR xy = make_pair(index.first + direct[ii].first, index.second + direct[ii].second);
			if (xy.first < 0 || xy.first > size.first || xy.second < 0 || xy.second > size.second) continue;

			if (animal[xy.first][xy.second] != -1) continue;
			if ((map[xy.first][xy.second] == '.' && (water[xy.first][xy.second] > cost + 1 || water[xy.first][xy.second] == -1)) || map[xy.first][xy.second] == 'D') {
				que.push(xy);
				animal[xy.first][xy.second] = cost + 1;
			}
		}
	}
}

int main(void)
{
	PAIR input = make_pair(0, 0);
	cin >> input.first >> input.second;

	map = vector<string>(input.first);
	water = vector<VECTOR>(input.first, VECTOR(input.second, -1));
	animal = vector<VECTOR>(input.first, VECTOR(input.second, -1));

	PAIR start, end;

	for (int ii = 0; ii < input.first; ii++) {
		cin >> map[ii];
		for (int jj = 0; jj < input.second; jj++) {
			if (map[ii][jj] == '*') { que.push(make_pair(ii, jj)); water[ii][jj] = 0; }
			else if (map[ii][jj] == 'S') { start = make_pair(ii, jj); }
			else if (map[ii][jj] == 'D') { end = make_pair(ii, jj); }
		}
	}

	waterBFS(start, make_pair(input.first - 1, input.second - 1));
	animalBFS(start, make_pair(input.first - 1, input.second - 1));

	if (animal[end.first][end.second] == -1) { cout << "KAKTUS" << endl; }
	else { cout << animal[end.first][end.second] << endl; }

	return 0;
}