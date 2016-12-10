#include <cstdio>
using namespace std;

int main(void)
{
	char mTemp = 0;
	while ( (mTemp = getc(stdin)) != '\n')
	{
		printf("%c", (mTemp < 91 ? mTemp + 32 : mTemp - 32) );
	}

	return 0;
}
