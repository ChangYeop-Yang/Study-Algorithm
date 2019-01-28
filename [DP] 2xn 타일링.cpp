#include <vector>
#include <iostream>
using namespace std;

#define DIV 10007
#define MAX_V 10001

vector<int> answer = vector<int>(MAX_V);

// TOP-DOWN
int reculsive(int index) {

	if (index == 1) { return 1; } /* 2 * 1의 경우는 1개 */
	if (index == 2) { return 2; } /* 2 * 2의 경우는 2개 */

	// Memorization
	if (answer[index] > 0) { return answer[index]; }

	// ※ D[N] = D[N - 1] + D[N - 2]
	answer[index] = ( reculsive(index - 1) + reculsive(index - 2) ) % DIV;
	return answer[index];
}

int main(void)
{
	int input = 0; cin >> input;

	// BOTTOM-UP
	answer[1] = 1; /* 2 * 1의 경우는 1개 */
	answer[2] = 2; /* 2 * 2의 경우는 2개 */
	for (int ii = 3; ii <= input; ii++) { answer[ii] = (answer[ii - 1] + answer[ii - 2]) % DIV; }

	// cout << answer[input] << endl;
	cout << reculsive(input) << endl;

	return 0;
}