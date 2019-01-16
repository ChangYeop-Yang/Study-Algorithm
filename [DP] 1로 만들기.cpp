#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define LEN 1000001

vector<int> bucket = vector<int>(LEN);

int reculsive(long long index) {

	if (index == 1) return 0;

	// Memorization
	if (bucket[index] > 0) return bucket[index];

	// ＊ Case: D[N - 1] + 1
	bucket[index] = reculsive(index - 1) + 1;

	// ＊ Case: D[N / 2] + 1
	if (index % 2 == 0) {
		int temp = reculsive(index / 2) + 1;
		if (temp < bucket[index]) bucket[index] = temp;
	}

	// ＊ Case: D[N / 3] + 1
	if (index % 3 == 0) {
		int temp = reculsive(index / 3) + 1;
		if (temp < bucket[index]) bucket[index] = temp;
	}

	return bucket[index];
}

int main(void)
{
	// ※ D[N] = min(D[N/3], D[N/2], D[N - 1]) + 1

	int input = 0;
	cin >> input;

	cout << reculsive(input) << endl;

	return 0;
}