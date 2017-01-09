#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	char * mDelete = "CAMBRIDGE";
	
	string mString;
	cin >> mString;

	int mSize = mString.size();
	for (int ii = 0; ii < mSize; ii++)
	{
		bool mCheck = true;
		for (int jj = 0; jj < 9; jj++) { if (mDelete[jj] == mString[ii]) { mCheck = false; break; } }

		if (mCheck) { cout << mString[ii]; }
	} cout << endl;

	return 0;
}
