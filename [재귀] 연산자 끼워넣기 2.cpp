#include <cstdio>
#include <vector>
#include <climits>
#include <iostream>
#include <algorithm>
using namespace std;

#define LONG long long
#define PAIR pair<long long, long long>

vector<int> operlands;
vector<int> operators = { 0, 0, 0, 0 };
PAIR answer = make_pair(LLONG_MIN, LLONG_MAX);

PAIR reculsiveOperator(int index, LONG val, int plus, int minus, int mul, int div) {

	// 피연산자에 대해서 모든 경우를 다 구한 경우 종료
	if (operlands.size() == index) { return make_pair(val, val); }
	
	vector<PAIR> ret; // 각 연산에 대한 결과값을 저장하는 Vector
	if (plus > 0) { ret.push_back(reculsiveOperator(index + 1, val + operlands[index], plus - 1, minus, mul, div)); }
	if (minus > 0) { ret.push_back(reculsiveOperator(index + 1, val - operlands[index], plus, minus - 1, mul, div)); }
	if (mul > 0) { ret.push_back(reculsiveOperator(index + 1, val * operlands[index], plus, minus, mul - 1, div)); }
	if (div > 0) { ret.push_back(reculsiveOperator(index + 1, val / operlands[index], plus, minus, mul, div - 1)); }

	// 연산에 대하여 구해진 결과에서 최대값과 최소값을 구한다.
	for (const auto value : ret) {
		answer.first = max(answer.first, value.first);
		answer.second = min(answer.second, value.second);
	}

	return answer;
}

int main(void)
{
	int digit = 0; cin >> digit;
	
	operlands = vector<int>(digit);
	for (int ii = 0; ii < digit; ii++) { scanf("%d", &operlands[ii]); }
	cin >> operators[0] >> operators[1] >> operators[2] >> operators[3];

	reculsiveOperator(1, operlands[0], operators[0], operators[1], operators[2], operators[3]);

	cout << answer.first << endl << answer.second << endl;

	return 0;
}