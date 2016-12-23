#include <iostream>
#include <string>
#include <map>
using namespace std;

map<string, bool> mMap;
map<string, bool>::iterator mIter;

int main(void)
{
	int nn = 0, mm = 0;
	cin >> nn >> mm;

	for (int ii = 0; ii < nn; ii++)
	{
		string mString;
		cin >> mString;

		pair<string, bool> mPair = make_pair(mString, false);
		mMap.insert(mPair);
	}

	int mCount = 0;
	for (int ii = 0; ii < mm; ii++)
	{
		string mString;
		cin >> mString;

		if (mMap.count(mString)) { mMap[mString] = true; mCount++; }
	}

	cout << mCount << endl;
	for (mIter = mMap.begin(); mIter != mMap.end(); ++mIter)
	{
		if (mIter->second) { cout << mIter->first << endl; }
	}

	return 0;
}
