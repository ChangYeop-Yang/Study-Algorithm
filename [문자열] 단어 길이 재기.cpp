#include <iostream>
using namespace std;

int main(void)
{
	char mChar[100];
	cin >> mChar;

	int Len = 0;
	for (; *(mChar + Len) != '\0'; Len++);

	cout << Len << endl;

	return 0;
}
