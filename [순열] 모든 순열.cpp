#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;

int generation() {
	static int number = 0;
	return ++number;
}

int main(void)
{
	int permutation = 0;
	scanf("%d", &permutation);

	vector<int> bucket = vector<int>(permutation);
	generate(bucket.begin(), bucket.end(), generation);

	do {

		for (auto begin = bucket.begin(); begin != bucket.end(); begin++) {
			printf("%d ", *begin);
		}
		
		printf("\n");

	} while ( next_permutation(bucket.begin(), bucket.end()) );

	return 0;
}