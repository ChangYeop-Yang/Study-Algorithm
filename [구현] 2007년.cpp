#include <iostream>
using namespace std;

const int mMonthArr[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const char * mMonthName[7] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};

int main(void)
{
	int mMonth = 0, mDay = 0;
	cin >> mMonth >> mDay;

	int mStart = 0;
	switch (mMonth)
	{
		case (1): { mStart = 1; break; }
		case (2): { mStart = 4; break; }
		case (3): { mStart = 4; break; }
		case (4): { mStart = 0; break; }
		case (5): { mStart = 2; break; }
		case (6): { mStart = 5; break; }
		case (7): { mStart = 0; break; }
		case (8): { mStart = 3; break; }
		case (9): { mStart = 6; break; }
		case (10): { mStart = 1; break; }
		case (11): { mStart = 4; break; }
		case (12): { mStart = 6; break; }
	}

	for (int ii = 1; ii < mMonthArr[mMonth - 1]; ii++)
	{
		if (mStart > 6) { mStart = 0; }

		if (mDay == ii) { cout << mMonthName[mStart] << endl; }

		mStart++;
	}

	return 0;
}
