#include <iostream>
using namespace std;

int main(void)
{
	int mJOI = 0;
	int mIOI = 0;

	char mCJOI[3] = { 'J', 'O', 'I' };
	char mCIOI[3] = { 'I', 'O', 'I' };

	char mCharArr[10001] = { 0, };
	cin >> mCharArr;

	int mIndex = 0;
	while (mCharArr[mIndex] != 0)
	{
		if (mCJOI[0] == mCharArr[mIndex]) 
		{
			bool mCheck = true;

			int mTemp = mIndex;
			for (int ii = 0; ii < 3; ii++)
			{ if (mCJOI[ii] != mCharArr[mTemp++]) { mCheck = false; break; } }
			
			if (mCheck) { mJOI++; }
		}

		if (mCIOI[0] == mCharArr[mIndex])
		{
			bool mCheck = true;

			int mTemp = mIndex;
			for (int ii = 0; ii < 3; ii++)
			{ if (mCIOI[ii] != mCharArr[mTemp++]) { mCheck = false; break; } }

			if (mCheck) { mIOI++; }
		}

		mIndex++;
	}

	cout << mJOI << endl << mIOI << endl;

	return 0;
}
