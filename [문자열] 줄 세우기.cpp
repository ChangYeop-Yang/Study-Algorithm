#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int main(void)
{
	int mNum = 0;
	cin >> mNum;

	bool mCheck[2] = { false, false };

	vector<char*> mVector;
	for (int ii = 0; ii < mNum; ii++)
	{
		char * mChar = new char[13];
		cin >> mChar;

		mVector.push_back(mChar);		
	}

	for (int ii = 0; ii < mNum; ii++)
	{
		for (int jj = ii + 1; jj < mNum; jj++)
		{
			short mShort = strcmp(mVector[ii], mVector[jj]);
			if (mShort == 0) { mCheck[0] = mCheck[1] = true; break; }
			else if (mShort < 0) { mCheck[1] = true; }
			else { mCheck[0] = true; }
		}
	}

	if (mCheck[0] == true && mCheck[1] == true) { cout << "NEITHER" << endl; }
	else if (mCheck[0] == true) { cout << "DECREASING" << endl; }
	else { cout << "INCREASING" << endl; }

	return 0;
}
