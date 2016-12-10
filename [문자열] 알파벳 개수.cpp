#include <iostream>
using namespace std;

int main(void)
{
	int mArr1[26] = { 0, };

	char mChar[101];
	cin >> mChar;

	for (int count = 0; *(mChar + count) != '\0'; count++) { mArr1[mChar[count] - 'a']++; }
	
	for (int count = 0; count < 26; count++) { cout << mArr1[count] << ' '; }

	cout << endl;

	return 0;
}
