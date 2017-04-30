#include <set>
#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

/* Define */
#define SIZE 1001
#define INF 99999999L

/* Array */
int mArray[SIZE][SIZE];
int mDestination[SIZE][SIZE];
pair<int, int> mVisit[SIZE][SIZE];

/* Function Declare */
int minDijkstra(const int mStart, const int mEnd);

int main(void)
{
	/* string */
	string sFileName;
	cout << "input file name? ";	cin >> sFileName;
	if (sFileName.find(".txt") == string::npos) { sFileName.append(".txt"); }

	/* FILE */
	FILE * fpInput = fopen(sFileName.c_str(), "rt");
	FILE * fpOutput = fopen("output.txt", "wt+");

	/* Integer */
	int mSize = 0;
	fscanf(fpInput, "%d", &mSize);

	/* Init Array */
	for (int ii = 0; ii <= mSize; ii++)
		for (int jj = 0; jj <= mSize; jj++) { mArray[ii][jj] = mDestination[ii][jj] = INF; }

	/* Input */
	char * sStr = new char[mSize];
	for (int ii = 0; ii < mSize; ii++)
	{
		fscanf(fpInput, "%s", sStr);
		for (int jj = 0; jj < mSize; jj++) { mArray[ii][jj] = sStr[jj] - '0'; }
	}

	/* minResult Output */
	fprintf(fpOutput, "%d\n", minDijkstra(mSize - 1, mSize - 1));

	/* Path Output */
	set<pair<int, int> > sOutPath;
	pair<int, int> pPath;

	for (int nSubX = mSize - 1, nSubY = mSize - 1; true; pPath = mVisit[nSubX][nSubY])
	{
		if (nSubX == 0 && nSubY == 0) break;

		sOutPath.insert(make_pair(nSubX + 1, nSubY + 1));
		nSubX += pPath.first * -1;
		nSubY += pPath.second * -1;
	} sOutPath.insert(make_pair(1, 1));

	set<pair<int, int> >::iterator piter;
	for (piter = sOutPath.cbegin(); piter != sOutPath.cend(); piter++)
		fprintf(fpOutput, "%d %d\n", piter->first, piter->second);

	fclose(fpInput); fclose(fpOutput);
	return 0;
}

/* Function Define */
int minDijkstra(const int mStart, const int mEnd)
{
	/* Pair<int, int> */
	pair<int, int> mPosition[4] = { make_pair(1, 0), make_pair(0, 1), make_pair(-1, 0), make_pair(0, -1) };
	pair<int, int> pSubPair = make_pair(0, 0);

	mDestination[pSubPair.first][pSubPair.second] = 0;
	for (int nMin = INF; true; nMin = INF)
	{
		for (int ii = 0; ii <= mEnd; ii++)
		{
			for (int jj = 0; jj <= mEnd; jj++)
			{
				if (mDestination[ii][jj] != EOF && mDestination[ii][jj] <= nMin)
				{
					nMin = mDestination[ii][jj];
					pSubPair = make_pair(ii, jj);
				}
			}
		}

		if (pSubPair.first == mStart && pSubPair.second == mEnd) { break; }

		for (int jj = 0; jj < 4; jj++)
		{
			int mLowX = pSubPair.first + mPosition[jj].first, mColY = pSubPair.second + mPosition[jj].second;

			if ((mLowX < 0 && mColY < 0) && (mLowX > mStart && mColY > mEnd)) { continue; }
			if (mDestination[mLowX][mColY] != INF) { continue; }

			switch (mArray[mLowX][mColY])
			{
				/* Black Room */ case (0): { mDestination[mLowX][mColY] = mDestination[pSubPair.first][pSubPair.second] + 1; break; }
				/* White Room */ case (1): { mDestination[mLowX][mColY] = mDestination[pSubPair.first][pSubPair.second]; break; }
			}

			mVisit[mLowX][mColY] = mPosition[jj];
		}

		mDestination[pSubPair.first][pSubPair.second] = EOF;
	}

	return mDestination[mStart][mEnd];
}
