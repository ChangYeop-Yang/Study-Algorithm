#include <iostream>
#include <stack>
using namespace std;

int mDivied[3] = { 1, 2, 4 };
char mChar1[1000001] = {0,};
stack<char> mStack;

int strlength(char * mChar)
{
	int mLength = 0;
	for (; mChar[mLength] != 0; mLength++);
	return mLength - 1;
}

int main(void)
{
	cin >> mChar1;

	short mCount = 0;
	for (int ii = strlength(mChar1); ii >= 0; ii--)
	{
		if (mCount == 3) { mCount = 0; }
		short mTemp = (mChar1[ii] - '0') % 10;
		mStack.push( (mTemp == 0 ? '0' : mDivied[mCount] + '0') );
		mCount++;
	}

	int mSize = mStack.size();
	while ((mSize % 3) != 0) { mSize++; mStack.push('0'); }

	short mSum = 0;
	for (int ii = mCount = 0; ii < mSize; ii++)
	{
		mCount++;
		mSum += (mStack.top() - '0'); mStack.pop();
		if (mCount == 3) { cout << mSum; mSum = mCount = 0; }
	} cout << endl;

	return 0;
}
