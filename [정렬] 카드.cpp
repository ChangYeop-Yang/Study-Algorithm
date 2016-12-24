#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

map<long long, int> mMap;
map<long long, int>::iterator mIter;

int main(void)
{
	int nn = 0;
	cin >> nn;

	int mMax = 0;
	for (int ii = 0; ii < nn; ii++)
	{
		long long mTemp = 0;
		scanf("%llu", &mTemp);

		if (!mMap.count(mTemp))
		{
			pair<long long, int> mPair = make_pair(mTemp, 0);
			mMap.insert(mPair); continue;
		}
		else 
		{
			mMap[mTemp]++;
			if (mMap[mTemp] > mMax) { mMax = mMap[mTemp]; }
		}
	}

	for (mIter = mMap.begin(); mIter != mMap.end(); mIter++)
	{ if (mIter->second == mMax) { cout << mIter->first << endl; break; } }

	return 0;
}
