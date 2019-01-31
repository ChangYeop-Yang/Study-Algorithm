#include <vector>
#include <cstdio>
#include <climits>
#include <iostream>
#include <algorithm>
using namespace std;

#define LONG long long

int main(void)
{
	int number = 0; cin >> number;
	bool minus = true;

	LONG answer = LLONG_MIN;
	vector<LONG> sum   = vector<LONG>(number + 1);
	vector<LONG> score = vector<LONG>(number + 1);
	for (int ii = 1; ii <= number; ii++) { scanf("%lld", &score[ii]); if (score[ii] > 0) { minus = false; } }

	// 모든 수가 음수 일 경우는 가장 큰 음수를 선택하고 끝낸다.
	if (minus) {
		for (int ii = 1; ii <= number; ii++) { answer = max(answer, score[ii]); }
		cout << answer << endl; return 0;
	}
	
	for (int ii = 1; ii <= number; ii++) {
		// D[ii]번째에는 현재까지 더해진 합의 최대 D[ii]와 D[ii - 1] + S[ii]을 비교하여 최대값을 갱신한다.
		sum[ii] = max(sum[ii], sum[ii - 1] + score[ii]);
	}

	// 최대값을 찾는 부분
	for (int ii = 1; ii <= number; ii++) { answer = max(answer, sum[ii]); }
	cout << answer << endl;

	return 0;
}