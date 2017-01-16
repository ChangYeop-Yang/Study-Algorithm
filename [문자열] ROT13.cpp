#include <iostream>
#include <cstdio>
using namespace std;

int main(void)
{
	char mChar = 0;
	while ((mChar = getchar()) != '\n')
	{
		if (mChar >= 65 && mChar <= 90) { printf("%c", (((mChar - 'A') + 13) % 26) + 'A'); }
		else if (mChar >= 97 && mChar <= 122) { printf("%c", (((mChar - 'a') + 13) % 26) + 'a'); }
		else { printf("%c", mChar); }
	} cout << endl;

	return 0;
}
