#include <iostream>
#include <map>
using namespace std;

int main(void)
{
	map<int, bool> mMap;

	for (int ii = 0; ii < 10; ii++)
	{
		int mTemp = 0;
		cin >> mTemp;

		pair<int,int> mPair = make_pair(mTemp % 42, mTemp);
		if (!mMap.count(mTemp % 42)) { mMap.insert(mPair); }
	}

	cout << mMap.size() << endl;

	return 0;
}
