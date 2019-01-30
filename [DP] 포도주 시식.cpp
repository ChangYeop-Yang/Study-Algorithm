#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_V 100001

int answer[MAX_V][3];

int main(void)
{
	int number = 0; cin >> number;

	vector<int> score = vector<int>(number + 1);
	for (int ii = 1; ii <= number; ii++) { cin >> score[ii]; }

	for (int ii = 1; ii <= number; ii++) {
		// D[ii] 번째의 포도주를 마시지 않은 경우 ii - 1번째의 포도주를 마시거나, 마시지 않거나, 연속으로 마신 경우
		answer[ii][0] = max(answer[ii - 1][0], max(answer[ii - 1][1], answer[ii - 1][2]));
		// D[ii] 번째의 포도주는 마신 경우 ii - 1번째의 포도주를 마시지 않아야 한다. (즉, 현재 1번 마셨기 때문에 전에 포도주를 마시지 않아야 1번 연속 마신 상태가 된다.)
		answer[ii][1] = answer[ii - 1][0] + score[ii];
		// D[ii] 번째의 포도주를 연속해서 마신 경우 ii - 1번쨰의 포도주를 마셔야 한다. (즉, 현재 2번 마셨기 때문에 전에 포도주를 마신 상태여야 2번 역속 마신 상태가 된다.)
		answer[ii][2] = answer[ii - 1][1] + score[ii];
	}

	cout << max(answer[number][0], max(answer[number][1], answer[number][2])) << endl;

	return 0;
}