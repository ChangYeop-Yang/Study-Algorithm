#include <cstdio>
using namespace std;

int main(void)
{
	char mChar[1001];
	fgets(mChar, 1001, stdin);

	for (int ii = 0; mChar[ii] != '\n'; ii++) 
	{
		if (ii % 10 == 0 && ii != 0) { printf("\n"); }
		printf("%c", mChar[ii]);
	}

	return 0;
}
