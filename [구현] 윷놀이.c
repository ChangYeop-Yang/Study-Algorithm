#include <stdio.h>

int main(void)
{
	int _Count[2] = {0,0};
	int mTemp[4] = {0,0,0,0};
	char mChar[4] = {0,0,0,0};

	for (int count = 0; count < 3; count++)
	{
		_Count[0] = _Count[1] = 0;
		scanf("%d %d %d %d", &mTemp[0], &mTemp[1], &mTemp[2], &mTemp[3]);

		for (int x = 0; x < 4; x++)
		{
			if (mTemp[x] == 0) { _Count[0]++; }
			else { _Count[1]++; }
		}

		if (_Count[0] == 1 && _Count[1] == 3) { mChar[count] = 'A'; }
		if (_Count[0] == 2 && _Count[1] == 2) { mChar[count] = 'B'; }
		if (_Count[0] == 3 && _Count[1] == 1) { mChar[count] = 'C'; }
		if (_Count[0] == 4 && _Count[1] == 0) { mChar[count] = 'D'; }
		if (_Count[0] == 0 && _Count[1] == 4) { mChar[count] = 'E'; }
	}

	for (int count = 0; count < 3; count++) { printf("%c\n", mChar[count]); }

	return 0;
}
