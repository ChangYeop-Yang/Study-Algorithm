#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_V 100001

int answer[MAX_V][2];

int main(void)
{
	int number = 0; cin >> number;

	vector<int> score = vector<int>(number + 1);
	for (int ii = 1; ii <= number; ii++) { cin >> score[ii]; }

	answer[1][0] = answer[1][1] = score[1]; // 마지막 도착 계단은 반드시 밟아야 한다. 그러므로 항상 첫 계단의 점수를 저장한다.
	for (int ii = 2; ii <= number; ii++) {
		// 연속된 세 개의 계단을 모두 밟아서는 안 된다. 단, 시작점은 계단에 포함되지 않는다.
		answer[ii][0] = answer[ii - 1][1] + score[ii]; // 전에 칸을 밝고 오는 경우이므로 N-1칸은 반드시 연속 된 칸을 밟지 않은 경우여야 한다.
		answer[ii][1] = max(answer[ii - 2][0], answer[ii - 2][1]) + score[ii]; // 현재 칸에 두 번 건너띄어서 오는 경우는 전전칸의 칸을 한번 건너 뛰거나 두번 건너 뛴경우다.
	}

	cout << max(answer[number][0], answer[number][1]) << endl;

	return 0;
}
