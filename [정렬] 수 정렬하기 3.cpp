#include <cstdio>
#include <map>
using namespace std;

map<int, int> mMap;
map<int, int>::iterator mIter;

int main(void)
{
	int mNum = 0;
	scanf("%d", &mNum);

	for (int ii = 0; ii < mNum; ii++)
	{
		int mTemp = 0;
		scanf("%d", &mTemp);

		if (mMap.count(mTemp)) { mMap[mTemp]++; }
		else { mMap.insert(make_pair(mTemp, 0)); }
	}

	for (mIter = mMap.begin(); mIter != mMap.end(); mIter++)
	{
		if (mIter->second == 0) { printf("%d\n", mIter->first); continue; }
		else { for (int ii = 0; ii <= mIter->second; ii++) { printf("%d\n", mIter->first); } }
	}
	

	return 0;
}
