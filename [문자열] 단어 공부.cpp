#include <cstdio>
#include <cctype>
using namespace std;

int mCount[26] = {0,};

int main(void)
{
	char mChar = 0;
	while ((mChar = getchar()) != EOF)
	{ mCount[(toupper(mChar) - 'A')]++; }
	
	int mMax = 0;
	int mIndex = 0;
	for (int ii = 0; ii < 26; ii++)
	{ if (mMax < mCount[ii]) { mMax = mCount[ii]; mIndex = ii; } }

	for (int ii = 0; ii < 26; ii++)
	{ if (mIndex != ii && mMax == mCount[ii]) { printf("?\n"); return 0; } }

	printf("%c\n", mIndex + 'A');

	return 0;
}
