#include <vector>
#include <iostream>
using namespace std;

void search(vector<int> numbers, int target, int sum, int * answer, int index) {

	int numberLength = numbers.size();

	if (index >= numberLength) {
		if (sum == target) { (*answer)++; return; }
		return;
	}

	search(numbers, target, sum + numbers.at(index), answer, index + 1);
	search(numbers, target, sum - numbers.at(index), answer, index + 1);
}

int solution(vector<int> numbers, int target) {
	
	int answer = 0;

	search(numbers, target, 0, &answer, 0);

	return answer;
}
