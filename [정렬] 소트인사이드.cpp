#include <iostream>
#include <vector>
#include <cstdio>
#include <functional>
#include <algorithm>
using namespace std;

vector<int> mVector;

int main(void)
{
	int mCount = 0;

	char mChar = 0;
	while ((mChar = getchar()) != '\n')
	{
		int mTemp = mChar - '0';
		mVector.push_back(mTemp);

		mCount++;
	}

	sort(mVector.begin(), mVector.end(), greater<int>());

	for (int ii = 0; mCount > ii; ii++)
	{
		printf("%d", mVector[ii]);
	} printf("\n");

	return 0;
}
