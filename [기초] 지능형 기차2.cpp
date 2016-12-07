#include <stdio.h>

int main(void)
{
	int mTemp[2] = {0, 0};
	int mMax = 0;
	int mNow = 0;

	for (int count = 0; count < 10; count++)
	{
		scanf("%d %d", &mTemp[0], &mTemp[1]);

		/* 계산 */
		mNow = (mNow - mTemp[0]) + mTemp[1];
		if (mMax < mNow) { mMax = mNow; }
	}

	printf("%d\n", mMax);

	return 0;
}
