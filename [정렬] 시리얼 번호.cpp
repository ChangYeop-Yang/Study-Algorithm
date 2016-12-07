#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

class Person
{
	public :
		int mLength = 0;
		int mSum = 0;
		char mChar[51] = { 0, };

		Person(char * mChar)
		{
			strcpy(this->mChar, mChar);
			mLength = strlen(mChar);
			mSum = checkNumber(mChar);
		}

		int checkNumber(char * mChar)
		{
			int mSum = 0;
			for (int ii = 0; mChar[ii] != 0; ii++) 
			{
				short mShort = *(mChar + ii) - '0';
				if (mShort >= 0 && mShort <= 9) { mSum += mShort; }
			}

			return mSum;
		}
};

bool cmp(const Person & a, const Person & b)
{
	if (a.mLength != b.mLength) { return a.mLength < b.mLength; }
	else if (a.mSum != b.mSum) { return a.mSum < b.mSum; }
	else { return strcmp(a.mChar, b.mChar) < 0; }
}

int main(void)
{
	int mNum = 0;
	cin >> mNum;

	vector<Person> mVector;
	for (int ii = 0; ii < mNum; ii++)
	{
		char * mChar = new char[51];
		cin >> mChar;

		mVector.push_back(Person(mChar));
	}

	sort(mVector.begin(), mVector.end(), cmp);

	for (int ii = 0; ii < mNum; ii++)
	{
		cout << mVector[ii].mChar << endl;
	}

	return 0;
}
