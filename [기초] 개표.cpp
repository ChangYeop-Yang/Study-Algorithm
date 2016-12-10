#include <iostream>
using namespace std;

int main(void)
{
	int num = 0;
	cin >> num;

	int A = 0, B = 0;
	for (int ii = 0; ii < num; ii++)
	{
		char mChar = 0;
		cin >> mChar;

		mChar == 'A' ? A++ : B++;
	}

	if (A > B) cout << 'A' << endl;
	else if (A < B) cout << 'B' << endl;
	else cout << "Tie" << endl;

	return 0;
}
