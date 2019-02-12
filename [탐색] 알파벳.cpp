#include <string>
#include <vector>
#include <climits>
#include <iostream>
#include <algorithm>
using namespace std;

#define INT_PAIR pair<int, int>

int answer = INT_MIN;

// 새로 이동한 칸에 적혀 있는 알파벳은 지금까지 지나온 모든 칸에 적혀 있는 알파벳과는 달라야 한다. 즉, 같은 알파벳이 적힌 칸을 두 번 지날 수 없다.
vector<bool> alpabat = vector<bool>(26, false);

// 말은 상하좌우로 인접한 네 칸 중의 한 칸으로 이동
vector<INT_PAIR> direct = { make_pair(0, 1), make_pair(0, -1), make_pair(1, 0), make_pair(-1, 0) };

void reculsiveDFS(const INT_PAIR length, INT_PAIR index, vector<string> & map, int count) {
	
	// Alpabat을 삽입 및 삭제의 경우를 모두 한 경우 최대값을 구한다.
	answer = max(answer, count);

	// Case 현재 Alpabat을 넣고 경로를 구하는 경우
	alpabat[map[index.first][index.second] - 'A'] = true;

	for (int ii = 0; ii < direct.size(); ii++) {
	
		const INT_PAIR there = make_pair(direct[ii].first + index.first, direct[ii].second + index.second);

		// Case Out of Range
		if (there.first < 0 || there.first >= length.first || there.second < 0 || there.second >= length.second) { continue; }

		// Case Not Contain Alpabat
		if (alpabat[map[there.first][there.second] - 'A'] == false) { reculsiveDFS(length, there, map, count + 1); }
	}

	// Case 현재 Alpabat을 빼고 경로를 구하는 경우
	alpabat[map[index.first][index.second] - 'A'] = false;
}

int main(void)
{
	INT_PAIR input = make_pair(0, 0);
	cin >> input.first >> input.second;
	
	vector<string> map = vector<string>(input.first, string());
	for (int ii = 0; ii < input.first; ii++) { cin >> map[ii]; }

	int number = 1; // 말이 지나는 칸은 좌측 상단의 칸도 포함된다.
	reculsiveDFS(input, make_pair(0, 0), map, number);

	cout << answer << endl;

	return 0;
}
