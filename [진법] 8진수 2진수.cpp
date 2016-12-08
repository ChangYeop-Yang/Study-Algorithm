#include <cstdio>
using namespace std;

int main(void)
{
	int mCount = 0;

	char mCharArr[8][3] =
	{
		{ '0', '0', '0' }, // 0
		{ '0', '0', '1' }, // 1
		{ '0', '1', '0' }, // 2
		{ '0', '1', '1' }, // 3
		{ '1', '0', '0' }, // 4
		{ '1', '0', '1' }, // 5
		{ '1', '1', '0' }, // 6
		{ '1', '1', '1' } // 7
	};

	char mChar = 0;
	for (; (mChar = getchar()) != '\n'; mCount++)
	{
		short mShort = (mChar - '0');

		if (mCount == 0 && mShort <= 3)
		{
			switch (mShort)
			{
				case (0) : { mCount--; break; }
				case (1) : { printf("1"); break; }
				case (2) : { printf("10"); break; }
				case (3) : { printf("11"); break; }
			} continue;
		}

		for (int jj = 0; jj < 3; jj++)
		{ printf("%c", mCharArr[mShort][jj]); }
	} 
	
	if (mCount == 0) { printf("0"); }

	printf("\n");

	return 0;
}
