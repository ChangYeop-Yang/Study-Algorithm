#include <iostream>
#include <functional>
#include <string>
#include <map>
using namespace std;

int main(void)
{
	int mNumber = 0;
	cin >> mNumber;

	map <string, int, greater<string> > mMap;

	int mMax = 0;
	while (mNumber--)
	{
		string mString; cin >> mString;
		if (mMap.count(mString)) 
		{ 
			mMap[mString]++;
			if (mMap[mString] > mMax) { mMax = mMap[mString]; }
		}
		else { mMap.insert(make_pair(mString, 1)); }
	}
	
	map<string, int>::iterator mIter;
	for (mIter = mMap.begin(); mIter != mMap.end(); mIter++)
	{
		if (mMax == mIter->second) { cout << mIter->first << " " << mIter->second << endl; break; }
	}

	return 0;
}
