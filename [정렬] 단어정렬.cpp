#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

class Person
{
	public :
		char mChar[51];
		int mLength = 0;

	public :
		Person(char * mChar)
		{
			mLength = strlen(mChar);
			strcpy(this->mChar, mChar);
		}
};

bool cmp(const Person &a, const Person &b)
{ 
	if (a.mLength == b.mLength) { return strcmp(a.mChar, b.mChar) < 0; }
	else { return a.mLength < b.mLength; }
}

bool check(char* mString, vector<Person> mVector)
{
	for (; !mVector.empty(); mVector.pop_back())
	{
		if (strcmp(mString, mVector.back().mChar) == 0) { return false; }
	}
	return true;
}

vector<Person> mVector;

int main(void)
{
	int mNum = 0;
	scanf("%d", &mNum);

	for (int ii = 0; ii < mNum; ii++)
	{
		char * mString = new char[51];
		scanf("%s", mString);
		
		if (ii == 0) { mVector.push_back(Person(mString)); }
		else if (check(mString, mVector)) { mVector.push_back(Person(mString)); }
	} 
	
	sort(mVector.begin(), mVector.end(), cmp);

	int mLength = mVector.size();
	for (int ii = 0; ii < mLength; ii++)
	{
		printf("%s\n", mVector[ii].mChar);
	}

	return 0;
}
