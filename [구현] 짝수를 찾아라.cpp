#include <iostream>
using namespace std;

int main(void)
{
	int mTest = 0;
	cin >> mTest;

	while (mTest--)
	{
		int mSum = 0;
		int mMin = 9999999;
		for (int ii = 0; ii < 7; ii++)
		{
			int mTemp = 0; cin >> mTemp;
			if (mTemp % 2 == 0) { mSum += mTemp; if (mMin > mTemp) { mMin = mTemp; } }
		} cout << mSum << " " << mMin << endl;
	}

	return 0;
}
