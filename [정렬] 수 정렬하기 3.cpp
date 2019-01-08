#include <bitset>
#include <cstdio>
#include <unordered_map>
using namespace std;

#define SIZE 10001

bitset<SIZE> checkBit;
unordered_map<int, int> answer;

int main(void)
{
	register int count = 0;
	int input = 0;
	scanf("%d", &input);

	for (int ii = 0, number = 0; ii < input; ii++) {
		scanf("%d", &number);

		if ( checkBit.test(number) ) { answer[number]++; continue; }

		checkBit.set(number);
		answer.insert(make_pair(number, 1));
	}

	for (int ii = 0; ii < SIZE && count < input; ii++) {
		for (int jj = 0; jj < answer[ii]; jj++) { printf("%d\n", ii); count++; }
	}

	return 0;
}