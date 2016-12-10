#include <cstdio>
using namespace std;

int main(void)
{
	int mArr[26] = { 0, };
	for (int ii = 0; ii < 26; ii++) *(mArr + ii) = -1;
	char * mChar = new char[101];

	scanf("%s", mChar);
	for (int jj = 0; *(mChar + jj) != '\0'; ++jj)
	{
		if (mArr[mChar[jj] - 'a'] == -1) { mArr[mChar[jj] - 'a'] = jj; }
	}

	for (int ii = 0; ii < 26; ii++)
	{
		printf("%d ", mArr[ii]);
	}

	printf("\n");

	return 0;
}
