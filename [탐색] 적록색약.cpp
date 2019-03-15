#include <queue>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

#define RED 'R'
#define BLUE 'B'
#define GREEN 'G'
#define INT_PAIR pair<int, int>
#define BOOL_VECTOR vector<bool>

const vector<char> color = { RED, BLUE, GREEN };
const vector<INT_PAIR> direction = { make_pair(0, 1), make_pair(0, -1), make_pair(1, 0), make_pair(-1, 0) };

void dfs(const int length, const INT_PAIR index, const char letter, vector<BOOL_VECTOR> & visited, const vector<string> & map, const bool isOn) {
	
	visited[index.first][index.second] = true;

	for (const auto direct : direction) {
		const INT_PAIR there = make_pair(index.first + direct.first, index.second + direct.second);

		// MARK: - Vector Out of Range.
		if (there.first < 0 || there.first >= length || there.second < 0 || there.second >= length) { continue; }

		// Case 적록색약인 아닌 사람.
		if (isOn) {
			if (visited[there.first][there.second] == false && map[there.first][there.second] == letter) {
				dfs(length, there, letter, visited, map, isOn);
			}
		}
		// Case 적록색약인 사람.
		else {
			if (visited[there.first][there.second] == false && (map[there.first][there.second] == RED || map[there.first][there.second] == GREEN)) {
				dfs(length, there, letter, visited, map, isOn);
			}
		}
	}
}

int main(void)
{
	int length = 0; cin >> length;

	vector<string> board = vector<string>(length, string());
	for (int ii = 0; ii < length; ii++) { cin >> board[ii]; }

	INT_PAIR answer = make_pair(0, 0);
	vector<BOOL_VECTOR> visited = vector<BOOL_VECTOR>(length, BOOL_VECTOR(length));

	// Case 적록색약인 사람이 봤을 때와 아닌 사람이 봤을 때 구역의 수.
	for (const auto letter : color) {
		for (int ii = 0; ii < length; ii++) {
			for (int jj = 0; jj < length; jj++) {
				if (visited[ii][jj] == false && board[ii][jj] == letter) { 
					dfs(length, make_pair(ii, jj), letter, visited, board, true); 
					answer.first++;

					if (letter == BLUE) { answer.second++; }
				}
			}
		}
	}

	// Case 적록색약인 사람이 봤을 때의 구역의 수.
	visited = vector<BOOL_VECTOR>(length, BOOL_VECTOR(length));
	for (int ii = 0; ii < length; ii++) {
		for (int jj = 0; jj < length; jj++) {
			if (visited[ii][jj] == false && (board[ii][jj] == RED || board[ii][jj] == GREEN)) { dfs(length, make_pair(ii, jj), RED, visited, board, false); answer.second++; }
		} 
	}

	cout << answer.first << " " << answer.second << endl;

	return 0;
}