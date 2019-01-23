#include <vector>
#include <cstdio>
#include <iostream>
using namespace std;

#define MAX 10001

bool check[MAX];

/* Sieve of Eratoshenes */
void SoE() {
	for (long ii = 2; ii <= MAX; ii++) {
		if (check[ii] == false) {
			for (long jj = ii * ii; jj <= MAX; jj += ii) { check[jj] = true; }
		}
	}
}

void printPrim(int goal) {
	pair<int, int> answer = make_pair(0, 0);

	for (int ii = goal / 2; ii > 0; ii--) {
		int idx1 = ii;
		int idx2 = goal - ii;
		if ((check[idx1] == false && check[idx2] == false) && idx1 + idx2 == goal) {
			answer = make_pair(idx1, idx2); break;
		}
	}

	cout << answer.first << " " << answer.second << endl;
}

int main(void)
{
	SoE();

	long number = 0;
	scanf("%d", &number);

 	for (int ii = 0; ii < number; ii++) {
		int input = 0;
		scanf("%d", &input);

		printPrim(input);
	}

	return 0;
}