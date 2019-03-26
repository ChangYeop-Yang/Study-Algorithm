#include <iostream>
using namespace std;

int main(void)
{
	int e = 1, s = 1, m = 1;
	cin >> e >> s >> m;

	int mE = 1, mS = 1, mM = 1;

	for (int year = 1; true; year++) {

		if (mE == e && mS == s && mM == m) {
			cout << year << endl;
			break;
		}

		mE++, mS++, mM++;

		if (mE > 15) { mE = 1; }
		if (mS > 28) { mS = 1; }
		if (mM > 19) { mM = 1; }
	}

	return 0;
}
