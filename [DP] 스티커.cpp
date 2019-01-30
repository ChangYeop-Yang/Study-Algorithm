#include <cstring>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_V 100001
#define LONG long long

// D[N][0]는 스티커를 뜯지 않는 경우, D[N][1]는 위쪽 스티커를 뜯은 경우, D[N][2]는 아래쪽 스티커를 뜯은 경우
LONG answer[MAX_V][3];

int main(void)
{
	int testcase = 0; cin >> testcase;

	while (testcase--) {
		
		int number = 0; cin >> number;
		int score[2][MAX_V];

		for (int ii = 0; ii < 2; ii++) { 
			for (int jj = 1; jj <= number; jj++) { cin >> score[ii][jj]; }
		}

		memset(answer, 0, MAX_V);
		
		for (int ii = 1; ii <= number; ii++) {
			answer[ii][0] = max(answer[ii - 1][0], max(answer[ii - 1][1], answer[ii - 1][2])); // 스티커를 뜯지 않은 경우
			answer[ii][1] = max(answer[ii - 1][0], answer[ii - 1][2]) + score[0][ii]; // 위쪽 스티커를 뜯은 경우에는 아래쪽 스티커의 점수를 더하여 준다.
			answer[ii][2] = max(answer[ii - 1][0], answer[ii - 1][1]) + score[1][ii]; // 아래쪽 스티커를 뜯은 경우에는 위쪽 스티커의 점수를 더하여 준다.
		}

		LONG val = 0;
		for (int ii = 1; ii <= number; ii++) { val = max(max(val, answer[ii][0]), max(answer[ii][1], answer[ii][2])); }
		cout << val << endl;
	}

	return 0;
}