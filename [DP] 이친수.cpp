#include <iostream>
using namespace std;

#define LONG long long
#define MAX_V 101

LONG answer[MAX_V][2];
// D[N][0]이면 앞자리가 0인 경우, D[N][1]이면 앞자리가 1인 경우

int main(void)
{
	int number = 0; cin >> number;

	answer[1][0] = 0; // 이친수는 0으로 시작하지 않는다. 그러므로 만들 수 있는 갯수는 0로 초기화
	answer[1][1] = 1; // 이친수는 1으로 시작할 수 있다. 그러므로 만들 수 있는 갯수는 1로 초기화
	for (int ii = 2; ii <= number; ii++) {
		// 이친수에서는 1이 두 번 연속으로 나타나지 않는다. 즉, 11을 부분 문자열로 갖지 않는다.
		answer[ii][0] = answer[ii - 1][0] + answer[ii - 1][1]; // D[ii]번째가 0으로 시작하는 경우에는 0 또는 1 (0은 연속해서 올 수 있다.)
		answer[ii][1] = answer[ii - 1][0]; // D[ii]번쨰가 1으로 시작하는 경우에는 0 (1은 두 번 연속 올수없다.)
	}

	cout << answer[number][0] + answer[number][1] << endl;

	return 0;
}