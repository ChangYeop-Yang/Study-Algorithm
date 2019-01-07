#include <cstdio>
#include <unordered_set>
using namespace std;

int main(void)
{
	pair<int, int> input = make_pair(0, 0);
	scanf("%d", &input.first);

	unordered_set<int> bucket;

	for (int ii = 0; ii < input.first; ii++) {
		int number = 0;
		scanf("%d", &number);

		bucket.insert(number);
	}

	scanf("%d", &input.second);
	for (int ii = 0; ii < input.second; ii++) {
		
		int number = 0;
		scanf("%d", &number);

		int answer = bucket.find(number) != bucket.end() ? 1 : 0;
		printf("%d\n", answer);
	}


	return 0;
}