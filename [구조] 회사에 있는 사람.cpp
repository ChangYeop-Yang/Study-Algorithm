#include <iostream>
#include <functional>
#include <string>
#include <cstring>
#include <cstdio>
#include <map>
using namespace std;

map<string, bool, greater<string> > mMap;
map<string, bool>::iterator mIter;

int main(void)
{
	int nn = 0;
	cin >> nn;

	for (int ii = 0; ii < nn; ii++)
	{
		char * mString[2] = { new char[51], new char[51] };
		scanf("%s %s", mString[0], mString[1]);

		switch (strcmp(mString[1], "leave"))
		{
			case (0): 
			{ 
				if (mMap.count(string(mString[0]))) { mMap.erase(string(mString[0])); }
				break;
			}
			default: 
			{ 
				pair <string, bool> mPair = make_pair(string(mString[0]), false);
				if (!mMap.count(string(mString[0]))) { mMap.insert(mPair); }
				break; 
			}
		}
	}

	for (mIter = mMap.begin(); mIter != mMap.end(); mIter++)
	{ cout << mIter->first << endl; }

	return 0;
}
