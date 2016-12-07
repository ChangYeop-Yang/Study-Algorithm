#include <iostream>
#include <cmath>
using namespace std;

int main(void)
{
	int num1 = 0;
	cin >> num1;

	for (int ii = 0; ii < num1; ii++)
	{
		int num2 = 0, num3 = 0, temp = 1;
		cin >> num2 >> num3;

		if (num2 == 1) { cout << 1 << endl; continue; }
		if (num2 % 10 == 0) { cout << 10 << endl; continue; }

		for (int jj = 0; jj < num3; jj++)
		{
			temp *= num2;
			temp %= 10;
		}

		cout << temp << endl;
	}

	return 0;
}
