#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int mArr1[100001] = { 0, };
vector<int> mVector;

int main(void)
{
	int mNum = 0;
	scanf("%d", &mNum);

	int mTemp = 0;
	for (int ii = 0; ii < mNum; ii++)
	{
		scanf("%d", &mTemp);
		mArr1[ii] = mTemp;
	}

	sort(mArr1, mArr1 + mNum);

	for (int ii = 0, jj = 0; ii < mNum; ii++)
	{ 
		if (ii == 0) { mVector.push_back(mArr1[ii]); }
		else if (mVector[jj] != mArr1[ii]) { mVector.push_back(mArr1[ii]); jj++; }
	}
	
	int mSize = mVector.size();
	for (int ii = 0; ii < mSize; ii++)
	{
		printf("%d", mVector[ii]);
		if (ii != mSize) { printf(" "); }
	} printf("\n");

	return 0;
}
