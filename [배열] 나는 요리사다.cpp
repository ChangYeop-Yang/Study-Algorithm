#include<iostream>
using namespace std;

int main(void)
{
	int mCount = 0;
	int mMax = 0;
	for (int ii = 0; ii < 5; ii++)
	{
		int mSum = 0;
		for (int jj = 0; jj < 4; jj++)
		{
			int mTemp = 0;
			cin >> mTemp;

			mSum += mTemp;
		}

		if (mMax < mSum) { mMax = mSum; mCount = ii + 1; }
	}

	cout << mCount << ' ' << mMax << endl;

	return 0;
}
