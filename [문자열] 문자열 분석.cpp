#include <iostream>
#include <cstdio>
using namespace std;

int main(void)
{
	int mSmall = 0, mBig = 0, mNumber = 0, mEmpty = 0;

	char mChar = 0;
	while ( (mChar = getchar()) != EOF )
	{
		if (mChar == '\n') 
		{ 
			cout << mSmall << ' ' << mBig << ' ' << mNumber << ' ' << mEmpty << endl;
			mSmall = mBig = mNumber = mEmpty = 0;
		}

		if (mChar >= 65 && mChar <= 90) { mBig++; }
		else if (mChar >= 97 && mChar <= 122) { mSmall++; }
		else if (mChar >= 48 && mChar <= 57) { mNumber++; }
		else if (mChar == ' ') { mEmpty++; }
	}

	return 0;
}
