#include <iostream>
#include <cmath>
using namespace std;

int main(void)
{
	bool mCount = true;

	int mArr[8] = { 0, };
	for (int ii = 0; ii < 8; ii++)
	{
		cin >> mArr[ii];
		
		int mMath = abs(mArr[ii] - mArr[ii - 1]);
		if (mMath != 1 && ii != 0) { cout << "mixed" << endl; mCount = false; break; }
	}

	if (mCount)
	{
		cout << (mArr[0] == 1 ? "ascending" : "descending") << endl;
	}

	return 0;
}
