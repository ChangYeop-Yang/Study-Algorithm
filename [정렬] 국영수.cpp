#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

class Person
{
	public :
		char mName[11];

		int mLang = 0;
		int mEng = 0;
		int mMath = 0;

		Person(char * mName, int mLang, int mEng, int mMath)
		{
			strcpy(this->mName, mName);
			this->mLang = mLang;
			this->mEng = mEng;
			this->mMath = mMath;
		}
};

bool cmp(const Person & mPerson1, const Person & mPerson2)
{
	if (mPerson1.mLang != mPerson2.mLang) { return mPerson1.mLang > mPerson2.mLang; }
	else if (mPerson1.mEng != mPerson2.mEng) { return mPerson1.mEng < mPerson2.mEng; }
	else if (mPerson1.mMath != mPerson2.mMath) { return mPerson1.mMath > mPerson2.mMath; }
	else { return strcmp(mPerson1.mName, mPerson2.mName) < 0; }
}

vector<Person> mVector;

int main(void)
{
	int mNum = 0;
	scanf("%d", &mNum);
	
	for (int ii = 0; ii < mNum; ii++)
	{
		int mTemp[3] = { 0,0,0 };
		char * mString = new char[11];
		scanf("%s %d %d %d", mString, &mTemp[0], &mTemp[1], &mTemp[2]);

		Person mPersone = Person(mString, mTemp[0], mTemp[1], mTemp[2]);
		mVector.push_back(mPersone);
	}

	sort(mVector.begin(), mVector.end(), cmp);

	for (int ii = 0; ii < mNum; ii++)
	{ printf("%s\n", mVector[ii].mName); }

	return 0;
}
