#include <stdio.h>

int main(void)
{
	int mTemp[2] = {0, 0};
	int mMax = 0;

	for (int count = 0; count < 4; count++)
	{
		scanf("%d %d", &mTemp[0], &mTemp[1]);

		/* 계산 */
		int mValue = (mMax - mTemp[0]) + mTemp[1];
		if (mMax < mValue) { mMax = mValue; }
	}

	printf("%d\n", mMax);

	return 0;
}
