#include <cstdio>
#include <cstdlib>
#include <string>
#include <map>
using namespace std;

map<string, int> mKey;
map<int, string> mValue;

int main(void)
{
	int mNum1 = 0, mNum2 = 0;
	scanf("%d %d", &mNum1, &mNum2);

	for (int ii = 1; ii <= mNum1; ii++)
	{
		char * mChar = new char[26];
		scanf("%s", mChar);

		mKey.insert(make_pair(string(mChar), ii));
		mValue.insert(make_pair(ii, string(mChar)));
	}

	char * mChar = new char[26];
	for (int ii = 0; ii < mNum2; ii++)
	{
		scanf("%s", mChar);
		if (mChar[0] >= 65 && mChar[0] <= 90) { printf("%d\n", mKey[string(mChar)]); }
		else { printf("%s\n", mValue[atoi(mChar)].c_str()); }
	}

	return 0;
}
