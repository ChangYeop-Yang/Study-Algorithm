#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	int mArr[5] = { 0, };
	int mSum = 0;
	for (int ii = 0; ii < 5; ii++)
	{
		cin >> *(mArr + ii);
		mSum += *(mArr + ii);
	}

	sort(mArr, mArr+5);

	cout << mSum / 5 << endl << mArr[2] << endl;

	return 0;
}
