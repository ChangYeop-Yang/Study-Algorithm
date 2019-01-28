#include <vector>
#include <iostream>
using namespace std;

#define LONG long long
#define DIV 1000000009
#define MAX_V 1000001

vector<LONG> answer = vector<LONG>(MAX_V);

// TOP-DOWN
LONG reculsive(int index) {

	if (index == 0) { return 0; } // 0을 만들 수 있는 경우 (0가지)
	else if (index == 1) { return 1; } // 1을 만들 수 있는 경우 (1가지)
	else if (index == 2) { return 2; } // 2을 만들 수 있는 경우 (2가지)
	else if (index == 3) { return 4; } // 3을 만들 수 있는 경우 (3가지)

	// Memorization
	if (answer[index] > 0) { return answer[index]; }

	// D[N] = D[N - 1] + D[N - 2] + D[N - 3]
	answer[index] = (reculsive(index - 1) + reculsive(index - 2) + reculsive(index - 3)) % DIV;

	return answer[index];
}

int main(void)
{
	int testcase = 0; cin >> testcase;

	while (testcase--) {
		
		int input = 0; cin >> input;

		// BOTTOM-UP
		answer[0] = 0, answer[1] = 1, answer[2] = 2, answer[3] = 4;
		for (int ii = 4; ii <= input; ii++) {
			// D[N] = D[N - 1] + D[N - 2] + D[N - 3]
			answer[ii] = (answer[ii - 1] + answer[ii - 2] + answer[ii - 3]) % DIV;
		}

		// cout << answer[input] << endl;
		cout << reculsive(input) << endl;
	}

	return 0;
}