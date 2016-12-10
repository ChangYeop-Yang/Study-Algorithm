#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

vector<pair<char, int> > mVector;

int main(void)
{
	for (int ii = 0; ii < 26; ii++)
	{ mVector.push_back(make_pair( ((char)97 + ii), 0) ); }

	char mChar = 0;
	while ( (mChar = getchar()) != -1 )
	{
		for (int ii = 0; ii < 26; ii++)
		{ if (mVector[ii].first == mChar) { mVector[ii].second++; break; } }
	}

	int mMax = 0;
	for (int ii = 0; ii < 26; ii++)
	{ 
		if (mMax < (mVector[ii].second)) 
		{ mMax = mVector[ii].second; } 
	}

	for (int ii = 0; ii < 26; ii++)
	{ 
		if (mMax == mVector[ii].second) 
		{ cout << mVector[ii].first; } 
	} 
	
	cout << endl;

	return 0;
}
