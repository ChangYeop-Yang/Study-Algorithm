#include <vector>
#include <iostream>
using namespace std;

#define MAX_N 9
#define DIV_N 3

#define INT_VEC vector<int>
#define BOOL_VEC vector<bool>
#define INT_PAIR pair<int, int>

const int inline square(const int x, const int y) {
	return (x / DIV_N) * DIV_N + (y / DIV_N);
}

/* MARK: -
	ⓐ 각각의 가로줄과 세로줄에는 1부터 9까지의 숫자가 한 번씩만 나타나야 한다.
	ⓑ 굵은 선으로 구분되어 있는 3x3 정사각형 안에도 1부터 9까지의 숫자가 한 번씩만 나타나야 한다.
*/

vector<BOOL_VEC> row = vector<BOOL_VEC>(MAX_N + 1, BOOL_VEC(MAX_N + 1)); // 가로줄 1 ~ 9까지의 수
vector<BOOL_VEC> col = vector<BOOL_VEC>(MAX_N + 1, BOOL_VEC(MAX_N + 1)); // 세로줄 1 ~ 9까지의 수
vector<BOOL_VEC> box = vector<BOOL_VEC>(MAX_N + 1, BOOL_VEC(MAX_N + 1)); // 3X3의 1 ~ 9까지의 수

const bool full(const int go, vector<INT_VEC> & board) {

	// MARK: - 스도쿠의 모든 숫자를 기입 한 경우
	if (go == MAX_N * MAX_N) {
		for (int ii = 0; ii < MAX_N; ii++) {
			for (int jj = 0; jj < MAX_N; jj++) { cout << board[ii][jj] << ' '; }
			cout << endl;
		}
		return true;
	}

	// MARK: - Integer 형식의 숫자를 (X, Y)의 배열 형태로 변경
	const INT_PAIR pos = make_pair(go / MAX_N, go % MAX_N);
	
	// MARK: - 스도쿠의 판에 숫자가 기입 된 경우 다음으로 이동한다.
	if (board[pos.first][pos.second] != 0) { return full(go + 1, board); }
	else {
		
		for (int ii = 1; ii <= MAX_N; ii++) {
			// MARK: - 기입하고자 하는 숫자가 행, 열, 3X3 배열에 존재하지 않은 경우에 기입한다.
			if (row[pos.first][ii] == false && col[pos.second][ii] == false && box[square(pos.first, pos.second)][ii] == false) {
				row[pos.first][ii] = col[pos.second][ii] = box[square(pos.first, pos.second)][ii] = true;
				board[pos.first][pos.second] = ii;
				if (full(go + 1, board)) { return true; }
				board[pos.first][pos.second] = 0;
				row[pos.first][ii] = col[pos.second][ii] = box[square(pos.first, pos.second)][ii] = false;
			}
		}

	}

	return false;
}

int main(void) 
{
	vector<INT_VEC> board = vector<INT_VEC>(MAX_N + 1, INT_VEC(MAX_N + 1));

	for (int ii = 0; ii < MAX_N; ii++) {
		for (int jj = 0; jj < MAX_N; jj++) { 
			cin >> board[ii][jj];
			// MARK: - 스도쿠 판의 빈 칸의 경우에는 0이 주어진다.
			if (board[ii][jj] != 0) {
				row[ii][board[ii][jj]] = col[jj][board[ii][jj]] = box[square(ii, jj)][board[ii][jj]] = true;
			}
		}
	}

	full(0, board);

	return 0;
}