#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

#define MAX_V 8

int solution(int N, int number) {
	
	int answer = EOF;
	int base = 0;

	// MARK: - 최솟값이 8보다 크면 -1을 return 합니다.
	unordered_set<int> numbers[MAX_V];

	// MARK: - 주어진 N을 최대 8번을 사용하여 만든다.
	for (int ii = 0; ii < MAX_V; ii++) { 
		base = 10 * base + 1; 
		numbers[ii].insert(base * N); 
	}

	for (int ii = 1; ii < MAX_V; ii++) {
		for (int jj = 0; jj < ii; jj++) {
			for (auto op1 : numbers[jj]) {
				// MARK: - 각 피연산자들을 이용하여 연산을 수행한다.
				for (auto op2 : numbers[ii - jj - 1]) {
					numbers[ii].insert(op1 + op2); // + 연산을 수행한다.
					numbers[ii].insert(op1 - op2); // - 연산을 수행한다.
					numbers[ii].insert(op1 * op2); // * 연산을 수행한다.

					// MARK: - 수식에는 괄호와 사칙연산만 가능하며 나누기 연산에서 나머지는 무시합니다.
					if (op2 != 0) { numbers[ii].insert(op1 / op2); } // / 연산을 수행한다.
				}
			}
		}
		// MARK: - 주어진 Number를 N을 통해 만들어 진 경우
		if (numbers[ii].count(number) > 0) { answer = ii + 1; break; }
	}

	return answer;
}
