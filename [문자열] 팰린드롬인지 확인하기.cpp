#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	string mString1;
	string mString2;

	cin >> mString1;
	
	int mSize = mString1.size() - 1;
	for (int ii = mSize; ii >= 0; ii--)
	{ mString2.push_back(mString1[ii]); }

	cout << (mString1.compare(mString2) == 0 ? 1 : 0) << endl;

	return 0;
}
