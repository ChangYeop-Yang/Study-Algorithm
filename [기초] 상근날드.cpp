#include<iostream>
using namespace std;

int main(void)
{
	int mArr[5] = { 0, 0, 0, 0, 0 };
	cin >> mArr[0] >> mArr[1] >> mArr[2] >> mArr[3] >> mArr[4];

	int mMin = 9999999;
	for (int ii = 0; ii < 3; ii++)
	{
		for (int jj = 3; jj < 5; jj++)
		{
			int mTemp = (mArr[ii] + mArr[jj]) - 50;
			if (mTemp < mMin) { mMin = mTemp; }
		}
	}

	cout << mMin << endl;

	return 0;
}
