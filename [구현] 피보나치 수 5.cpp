#include <iostream>
using namespace std;

int fibonacci(int n)
{
	if (n <= 1) { return n; }
	else { return fibonacci(n - 1) + fibonacci(n - 2); }
}

int main(void)
{
	int mNum = 0;
	cin >> mNum;

	cout << fibonacci(mNum) << endl;

	return 0;
}
