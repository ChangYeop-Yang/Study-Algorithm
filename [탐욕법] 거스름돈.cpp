#include <vector>
#include <iostream>
using namespace std;

int main(void)
{
	int cost = 0; cin >> cost;
	cost = 1000 - cost;

	vector<int> coin = {500, 100, 50, 10, 5, 1};

	int index = 0;
	pair<int, int> answer = make_pair(0, 0);
	while (true) {

		// 거스름돈의 최적의 해를 구한 경우
		if (answer.second == cost) { cout << answer.first << endl; break; }

		// 구하고자 한는 값보다 동전의 값이 더 큰 경우는 버린다.
		if (cost < coin[index]) { index++; continue; }
		// 현재 구해 진 거스름돈에 다음 동전을 더하였을 때 구하고자 하는 값보다 더 큰 경우는 버린다.
		if (answer.second + coin[index] > cost) { index++; continue; }

		answer.first++;
		answer.second += coin[index];
	}

	return 0;
}