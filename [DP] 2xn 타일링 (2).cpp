#include <vector>
#include <iostream>
using namespace std;

#define DIV 10007
#define MAX_V 100001

vector<int> answer = vector<int>(MAX_V);

int main(void)
{
	int input = 0; cin >> input;

	answer[1] = 1; /* 2 * 1의 경우는 1개 */
	answer[2] = 3; /* 2 * 2의 경우는 3개 (2*2의 경우가 추가) */
	for (int ii = 3; ii <= input; ii++) { answer[ii] = (2 * answer[ii - 2] + answer[ii - 1]) % DIV; }
	// 정사각형의 경우가 추가 되어서 2가지 경우가 늘어남으로 * 2 해준다.

	cout << answer[input] << endl;

	return 0;
}