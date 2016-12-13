#include <iostream>
#include <cstdio>
using namespace std;

int mArr1[5001] = { 0, };
int mArr2[5001] = { 0, };

int mRead = -1;

int main(void)
{
	int N = 0, M = 0;
	cin >> N >> M;

	for (int ii = 0; ii < N; ii++) { mArr1[ii] = ii + 1; }

	int mCount = 0;
	while (mCount != N)
	{
		for (int ii = 0; ii < M;)
		{
			mRead = (mRead + 1) % N;

			if (mArr1[mRead] != EOF) { ii++; }
		}

		mArr2[mCount++] = mArr1[mRead];
		mArr1[mRead] = EOF;
	}

	cout << "<";
	for (int ii = 0; ii < N; ii++)
	{
		cout << mArr2[ii];
		if (ii != N - 1) { cout << ", "; }
	}
	cout << ">" << endl;

	return 0;
}
