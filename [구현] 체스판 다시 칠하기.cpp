#include <string>
#include <vector>
#include <climits>
#include <iostream>
#include <algorithm>
using namespace std;

#define WHITE 'W'
#define BLACK 'B'
#define MAX_V 8

#define INT_PAIR pair<int, int>

const int convertCheckBoard(vector<string> & board, const vector<char> casePhone, const INT_PAIR there) {

	int answer = 0;
	vector<char> phone = casePhone;

	for (int ii = there.first; ii < MAX_V + there.first; ii++) {
		int index = 0;
		for (int jj = there.second; jj < MAX_V + there.second; jj++) {
			// Case 체스판을 다시 칠해야 하는 경우.
			if (board[ii][jj] != phone[index]) { answer++; }
			index = (index + 1) % phone.size();
		}
		std::swap(phone.front(), phone.back());
	}

	return answer;
}

int main(void)
{
	INT_PAIR input = make_pair(0, 0);
	cin >> input.first >> input.second;

	vector<string> board = vector<string>(input.first, string());
	for (int ii = 0; ii < input.first; ii++) { cin >> board[ii]; }

	int answer = INT_MAX;

	// Case N * M Matrix
	for (int ii = 0; ii < input.first; ii++) {
		// MARK: - Row Out of Range
		if (ii + MAX_V > input.first) { break; }
		for (int jj = 0; jj < input.second; jj++) {

			// MARK: - Column Out of Rnage
			if (jj + MAX_V > input.second) { break; }

			/* ※ CAPTION ※
				체스판은 각 정사각형이 검정 또는 흰색이며, 
				변을 공유하는 두 개의 사각형이 같은 색이 아닐 때 이다. 
				따라서 위 정의에 의하면 체스판의 색은 항상 두 가지가 가능한데, 
				하나는 왼쪽 위 코너가 흰색인 것, 검정색인 것 두가지이다.
			*/

			// Case Left-Top Black
			const int black = convertCheckBoard(board, { BLACK, WHITE }, make_pair(ii, jj));
			answer = std::min(answer, black);

			// Case Left-Top White
			const int white = convertCheckBoard(board, { WHITE, BLACK }, make_pair(ii, jj));
			answer = std::min(answer, white);

			//answer = std::min(answer, 64 - count); // 90도를 회전 한 다음 칸의 개수를 확인
		}
	}

	cout << answer << endl;

 	return 0;
}
