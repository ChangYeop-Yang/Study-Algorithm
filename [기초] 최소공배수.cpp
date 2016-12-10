#include <iostream>
using namespace std;

int gcd(int num1, int num2)
{ return (num2 == 0 ? num1 : gcd(num2, num1%num2)); }

int main(void)
{
	/* input */
	int num1 = 0;
	cin >> num1;

	for (int count = 0; count < num1; count++)
	{
		int num2 = 0, num3 = 0, num4 = 0;
		cin >> num2 >> num3;

		num4 = gcd(num2, num3);
		cout << (num2 / num4) * num3 << endl;
	}

	return 0;
}
