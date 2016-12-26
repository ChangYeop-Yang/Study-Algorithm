#include <iostream>
using namespace std;

int main(void)
{	
	int mCount = 0;
	int mRow = 0;
	for (int ii = 0, jj = 0; ii < 64; jj++)
	{
		char mChar = 0;
		cin >> mChar;

		if (ii % 8 == 0 && ii != 0) { mRow++; }

		if (mChar != '\n')
		{
			if (mRow % 2 == 0)
			{
				if (mChar == 'F' && (jj % 2 == 0)) { mCount++; }
			}
			if (mRow % 2 != 0)
			{
				if (mChar == 'F' && (jj % 2 != 0)) { mCount++; }
			}

			ii++;
		}
	}

	cout << mCount << endl;

	return 0;
}
