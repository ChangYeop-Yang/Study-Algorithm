#include <iostream>
#include <cstdlib>
using namespace std;

int main(void)
{
	char mChar[2016];

	int N = 0, M = 0;
	cin >> mChar >> M;
	
	N = atoi(mChar);
	int mCount = 0;
	for (int ii = 0; ii < N; ii++)
	{
		for (int jj = 0; mChar[jj] != 0; jj++)
		{
			if (mCount++ == M) { cout << endl; return 0; }
			else { cout << mChar[jj]; }
		}
	} cout << endl;

	return 0;
}
