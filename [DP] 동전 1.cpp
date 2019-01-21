#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

#define LEN 10001

int main(void)
{
	pair<int, int> input = make_pair(0, 0);
	cin >> input.first >> input.second;

	vector<int> coin = vector<int>(LEN, 0);
	vector<int> answer = vector<int>(LEN, 0);
	for (int ii = 1; ii <= input.first; ii++) {
		scanf("%d", &coin[ii]);
	}

	answer[0] = 1; // 아무 동전도 선택하지 않는 경우
	for (int ii = 1; ii <= input.first; ii++) {
		// D[jj] += D[jj - C[ii]] 2원 단위로 1가지 씩 증가
		for (int jj = coin[ii]; jj <= input.second; jj++) {
			answer[jj] += answer[jj - coin[ii]];
		}
	}

	cout << answer[input.second] << endl;

	return 0;
}