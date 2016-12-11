#include <iostream>
using namespace std;

const int mod = 1000000;
const int p = mod / 10 * 15;

int fibo[p] = { 0, 1 };

int main(void)
{
	long long int mNum = 0;
	cin >> mNum;

	for (int ii = 2; ii < p; ii++)
	{
		fibo[ii] = fibo[ii - 1] + fibo[ii - 2];
		fibo[ii] %= mod;
	}

	cout << fibo[mNum%p] << endl;

	return 0;
}
