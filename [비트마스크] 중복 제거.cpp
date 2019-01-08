#include <cstdio>
#include <bitset>
using namespace std;

#define SIZE 1 << 25

static bitset<SIZE> answer;

int main(void)
{
	register int number = 0;

	while ( scanf("%d", &number) != EOF) {
		if (answer.test(number)) { continue; }

		answer.set(number);
		printf("%d ", number);
	}

	return 0;
}