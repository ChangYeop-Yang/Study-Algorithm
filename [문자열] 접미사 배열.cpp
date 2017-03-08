#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main(void)
{
	string mString;
	cin >> mString;

	vector<string> mVector;
	mVector.push_back(mString);

	string::iterator mIter = mString.begin();
	for (int ii = 0, mSize = mString.size(); ii < mSize; ii++)
	{
		mIter = mString.erase(mIter);
		mVector.push_back(mString);
	}

	sort(mVector.begin(), mVector.end());

	for (int ii = 1, mSize = mVector.size(); ii < mSize; ii++)
		cout << mVector[ii] << endl;

	return 0;
}
