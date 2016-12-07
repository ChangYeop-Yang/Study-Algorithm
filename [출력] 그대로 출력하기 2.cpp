#include <cstdio>
using namespace std;

int main(void)
{
	char mTemp = 0;
	while ( (mTemp = getc(stdin)) != EOF )
	{
		printf("%c", mTemp);
	}

	return 0;
}
