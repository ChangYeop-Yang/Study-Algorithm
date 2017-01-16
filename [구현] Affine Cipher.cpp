#include <iostream>
#include <cstdio>
using namespace std;

#define ROTATE(a, b, x) ((a*x) + b) % 26

int main(void)
{
	int mNumber = 0;
	cin >> mNumber;

	while (mNumber--)
	{
		int mA = 0, mB = 0;
		cin >> mA >> mB;

		char mChar = 0; getchar();
		while ((mChar = getchar()) != '\n')
		{
			int mTemp = mChar - 'A';
			printf("%c", (ROTATE(mA, mB, mTemp)) + 'A');
		}

		cout << endl;
	}

	return 0;
}
