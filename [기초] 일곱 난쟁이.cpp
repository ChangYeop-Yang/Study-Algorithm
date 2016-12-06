#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	int mArr[9] = { 0, };
	for (int ii = 0; ii < 9; ii++)
	{ cin >> mArr[ii]; }

	int mSorted[7] = { 0, };

	for (int ii = 0; ii < 9; ii++)
	{
		for (int jj = ii + 1; jj < 9; jj++)
		{
			for (int kk = jj + 1; kk < 9; kk++)
			{
				for (int qq = kk + 1; qq < 9; qq++)
				{
					for (int zz = qq + 1; zz < 9; zz++)
					{
						for (int aa = zz + 1; aa < 9; aa++)
						{
							for (int ff = aa + 1; ff < 9; ff++)
							{
								int sum = mArr[ii] + mArr[jj] + mArr[kk] + mArr[qq] + mArr[zz] + mArr[aa] + mArr[ff];
								if (sum == 100) 
								{
									mSorted[0] = mArr[ii]; mSorted[1] = mArr[jj]; mSorted[2] = mArr[kk];
									mSorted[3] = mArr[qq]; mSorted[4] = mArr[zz]; mSorted[5] = mArr[aa];
									mSorted[6] = mArr[ff];
								}
							}
						}
					}
				}
			}
		}
	}

	sort(mSorted, mSorted + 7);
	for (int ii = 0; ii < 7; ii++) { cout << mSorted[ii] << ' '; } cout << endl;

	return 0;
}
