#include <cstdio>
#include <iostream>
using namespace std;

int main(void)
{
	register int number = 0;
	scanf("%d", &number);

	for (register int ii = 0; ii < number; ii++) {
		register pair<int, int> value = make_pair(0, 0);
		scanf("%d %d", &value.first, &value.second);

		printf("%d\n", value.first + value.second);
	}

	return 0;
}