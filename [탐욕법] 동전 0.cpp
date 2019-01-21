#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

int main(void)
{
	pair<int, int> input = make_pair(0, 0);
	cin >> input.first >> input.second;

	vector<int> coin = vector<int>(input.first);
	for (int ii = 0; ii < input.first; ii++) {
		scanf("%d", &coin[ii]);
	}

	int index = input.first - 1;
	pair<int, int> answer = make_pair(0, 0);
	while (true) {

		if (answer.second == input.second) { cout << answer.first << endl; break; }

		// 현재 Coin의 값이 구하고자 하는 값보다 더 큰 경우는 버린다.
		if (input.second < coin[index]) { index--; continue; }

		// 현재 구한 Coin 합 값의보다 구하조가 하는 값이 더 큰 경우는 버린다.
		if (answer.second + coin[index] > input.second) { index--; continue; }

		answer.first++;
		answer.second += coin[index];
	}

	return 0;
}