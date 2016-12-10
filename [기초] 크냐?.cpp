#include <iostream>
using namespace std;

int main(void)
{
	int num1 = 0, num2 = 0;
	
	while (true)
	{
		cin >> num1 >> num2;
		if (num1 == 0 && num2 == 0) { return 0; }
		else
		{
			cout << (num1 > num2 ? "Yes" : "No") << endl;
		}
	}

	return 0;
}
