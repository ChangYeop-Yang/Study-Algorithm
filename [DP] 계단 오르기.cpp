#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	int stairs = 0; cin >> stairs;

	vector<int> score = vector<int>(stairs + 1);
	vector<int> answer = vector<int>(stairs + 1);
	for (int ii = 0; ii < stairs; ii++) { cin >> score[ii]; }

	answer[0] = score.front(); // 첫 계단을 밟은 경우
	answer[1] = max(score[0] + score[1], score[1]); // 첫 계단을 밟지 않은 경우 또는 첫 계단을 밞고 오는 경우
	answer[2] = max(answer[0] + score[2], score[1] + score[2]); // 첫 계단을 밟고 바로 오는 경우, 첫 계단을 밟지 않고 오는 경우

	for (int ii = 3; ii <= stairs; ii++) {
		// 1. 한 계단씩 밟는 경우 D[N] = D[N-3] + C[N-1] + C[N]
		// 2. 두 계단씩 밟는 경우 D[N] = D[N-2] + C[N]
		answer[ii] = max(answer[ii - 3] + score[ii - 1], answer[ii - 2]) + score[ii];
	}

	cout << answer[stairs - 1] << endl;

	return 0;
}