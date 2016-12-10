#include <iostream>
using namespace std;

long long int GCD(long long int num1, long long int num2)
{
	return num2 ? GCD(num2, num1%num2) : num1;
}

int main(void)
{
	long long int num1 = 0, num2 = 0, num3 = 0;
	cin >> num3;

	for (long long int ii = 0; ii < num3; ii++)
	{
		cin >> num1 >> num2;
		
		cout << (num1 * num2) / GCD(num1, num2) << endl;
	}

	return 0;
}
