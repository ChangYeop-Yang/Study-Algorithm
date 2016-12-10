#include <iostream>
using namespace std;

long long int fac(long long int num)
{
	if (num == 0 || num == 1) return num;

	long long int a = fac((num + 1) / 2);
	long long int b = fac(((num + 1) / 2) - 1);

	if (num % 2 == 0) return a * (a + 2 * b);
	else return a * a + b * b;
}

int main(void)
{
	/* input */
	long long int num = 0;
	cin >> num;

	cout << fac(num) << endl;

	return 0;
}
