#include <cstdio>
using namespace std;

#define MAX_V 1001

bool mArr[MAX_V][MAX_V];
bool mVisit[MAX_V];

void DFS(int index, int mVertax)
{
	mVisit[index] = true;

	for (int ii = 1; ii <= mVertax; ii++)
	{
		if (!mVisit[ii] && mArr[index][ii])
		{ DFS(ii, mVertax); }
	}
}

int main(void)
{
	int mVertax = 0, mEdge = 0;
	scanf("%d %d", &mVertax, &mEdge);

	int mTemp[2] = { 0,0 };
	for (int ii = 0; ii < mEdge; ii++)
	{
		scanf("%d %d", &mTemp[0], &mTemp[1]);
		mArr[mTemp[0]][mTemp[1]] = mArr[mTemp[1]][mTemp[0]] = true;
	}

	int mCount = 0;
	for (int ii = 1; ii <= mVertax; ii++)
	{
		if (!mVisit[ii]) { DFS(ii, mVertax); mCount++; }
	}

	printf("%d\n", mCount);

	return 0;
}
