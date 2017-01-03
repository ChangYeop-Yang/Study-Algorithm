#include <algorithm>
#include <queue>
#include <vector>
#include <cstdio>
using namespace std;

#define MAX_V 26

int mMap[MAX_V][MAX_V];
bool mVisit[MAX_V][MAX_V];

int BFS(int x, int y)
{
	int mCount = 0;

	queue<pair<int, int> > mQueue;
	mQueue.push(make_pair(x, y));

	mVisit[x][y] = true;

	while (!mQueue.empty())
	{
		int mSubX = mQueue.front().first;
		int mSubY = mQueue.front().second; mQueue.pop();

		if (!mVisit[mSubX + 1][mSubY] && mMap[mSubX + 1][mSubY] == 1)
		{
			mVisit[mSubX + 1][mSubY] = true;

			mQueue.push(make_pair(mSubX + 1, mSubY));

			mCount++;
		}
		if (!mVisit[mSubX][mSubY + 1] && mMap[mSubX][mSubY + 1] == 1)
		{
			mVisit[mSubX][mSubY + 1] = true;

			mQueue.push(make_pair(mSubX, mSubY + 1));

			mCount++;
		}
		if (!mVisit[mSubX - 1][mSubY] && mMap[mSubX - 1][mSubY] == 1)
		{
			mVisit[mSubX - 1][mSubY] = true;

			mQueue.push(make_pair(mSubX - 1, mSubY));

			mCount++;
		}
		if (!mVisit[mSubX][mSubY - 1] && mMap[mSubX][mSubY - 1] == 1)
		{
			mVisit[mSubX][mSubY - 1] = true;

			mQueue.push(make_pair(mSubX, mSubY - 1));

			mCount++;
		}
	}

	return mCount + 1;
}

int main(void)
{
	int mVertax = 0;
	scanf("%d", &mVertax);

	for (int ii = 0; ii < mVertax; ii++)
	{
		for (int jj = 0; jj < mVertax; jj++)
		{
			scanf("%1d", &mMap[ii][jj]);
		}
	}

	vector<int> mVector;

	int mCount = 0;
	for (int ii = 0; ii < mVertax; ii++)
	{
		for (int jj = 0; jj < mVertax; jj++)
		{
			if (mVisit[ii][jj] || mMap[ii][jj] == 0) { continue; }
			mVector.push_back(BFS(ii, jj)); mCount++;
		}
	}

	sort(mVector.begin(), mVector.end());

	printf("%d\n", mCount);
	for (int ii = 0, size = mVector.size(); ii < size; ii++)
	{
		printf("%d\n", mVector[ii]);
	}

	return 0;
}
