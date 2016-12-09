#include <cstdio>
#include <cstring>
using namespace std;

char mChar[1000001] = { 0, };
char mTemp[1000001] = { 0, };

// 스택 문제라니... 내가 몇일을 고생했는데
int main(void)
{
	char mBoom[37] = { 0, };
	scanf("%s %s", mChar, mBoom);

	int mTOP = -1;
	int mLength[2] = { strlen(mChar), strlen(mBoom) };

	for (int ii = 0; ii < mLength[0]; ii++)
	{
		mTemp[++mTOP] = mChar[ii];
		if (mTOP >= mLength[1] - 1 && mBoom[mLength[1] - 1] == mTemp[mTOP])
		{
			int mm = mTOP;
			bool mCheck = true;
			for (int ii = mLength[1] - 1; ii >= 0; ii--)
			{ if (mBoom[ii] != mTemp[mm--]) { mCheck = false; break; } }

			if (mCheck) { mTOP -= mLength[1]; }
		}
	}

	if (mTOP == -1) { printf("FRULA\n"); }
	else
	{
		for (int ii = 0; ii <= mTOP; ii++)
		{ printf("%c", mTemp[ii]); }

		printf("\n");
	}


	return 0;
}
