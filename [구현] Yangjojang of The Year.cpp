#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	int mTest = 0;
	cin >> mTest;

	int mNumber = 0;
	string mString;

	while (mTest--)
	{
		pair<string, int> mPair;

		int mCount = 0; cin >> mCount;
		for (int ii = 0; ii < mCount; ii++)
		{
			cin >> mString >> mNumber;
			if (mNumber > mPair.second) { mPair = make_pair(mString, mNumber); }
		}

		cout << mPair.first << endl;
	}

	return 0;
}
