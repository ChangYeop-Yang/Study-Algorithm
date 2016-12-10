#include <iostream>
using namespace std;

int search(char * mChar)
{
	int ii = 0;
	for (; *(mChar + ii) == 'a'; ii++);

	return ii;
}

int main(void)
{
	char * mChar1 = new char[1000];
	char * mChar2 = new char[1000];

	cin >> mChar1 >> mChar2;

	cout << (search(mChar1) < search(mChar2) ? "no" : "go") << endl;

	return 0;
}
