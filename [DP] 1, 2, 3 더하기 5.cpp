#include <cstdio>
#include <iostream>
using namespace std;

#define LONG long long
#define MAX_V 1000001
const LONG DIV = 1000000009LL;

LONG answer[MAX_V][4];

int main(void)
{	
	// 단, 같은 수를 두 번 이상 연속해서 사용하면 안된다. (Ex. 1이 올경우 2가 올수없다)
	for (int ii = 1; ii <= MAX_V - 1; ii++) {

		// +1을 한 경우에는 +2, +3이 올 수 있다.
		if (ii - 1 >= 0) {
			answer[ii][1] = answer[ii - 1][2] + answer[ii - 1][3];
			if (ii == 1) { answer[ii][1] = 1; } // 1인 경우 +1 한 가지
		}

		// +2을 한 경우에는 +1, +3이 올 수 있다.
		if (ii - 2 >= 0) {
			answer[ii][2] = answer[ii - 2][1] + answer[ii - 2][3];
			if (ii == 2) { answer[ii][2] = 1; } // 2인 경우 +2 한 가지
		}

		// +3을 한 경우에는 +1, +2이 올 수 있다.
		if (ii - 3 >= 0) {
			answer[ii][3] = answer[ii - 3][1] + answer[ii - 3][2];
			if (ii == 3) { answer[ii][3] = 1; } // 3인 경우 +3 한 가지
		}

		answer[ii][1] %= DIV; 
		answer[ii][2] %= DIV; 
		answer[ii][3] %= DIV;
	}

	int testcase = 0; cin >> testcase;

	while (testcase--) {
		int number = 0; cin >> number;
		printf("%lld\n", (answer[number][1] + answer[number][2] + answer[number][3]) % DIV);
	}

	return 0;
}