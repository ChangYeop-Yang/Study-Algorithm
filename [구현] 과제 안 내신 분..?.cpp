#include <iostream>
#include <map>
using namespace std;

map<int, bool> mMap;

int main(void)
{
	for (int ii = 0; ii < 30; ii++)
	{ mMap.insert(make_pair(ii + 1, false)); }

	int mNumber = 0;
	for (int ii = 0; ii < 28; ii++)
	{
		cin >> mNumber;
		mMap[mNumber] = true;
	}

	map<int, bool>::iterator miterator;
	for (miterator = mMap.begin(); miterator != mMap.end(); miterator++)
	{
		if (!miterator->second) { cout << miterator->first << endl; }
	}

	return 0;
}
