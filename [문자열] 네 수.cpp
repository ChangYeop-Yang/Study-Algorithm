#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

int main(void)
{
	string mString1, mString2, mString3, mString4;
	cin >> mString1 >> mString2 >> mString3 >> mString4;

	mString1.append(mString2);
	mString3.append(mString4);

	cout << atoll(mString1.c_str()) + atoll(mString3.c_str()) << endl;

	return 0;
}

/* Py
mList = str(input()).split(" ")

mSub1 = mList[0] + mList[1]
mSub2 = mList[2] + mList[3]

print(int(mSub1) + int(mSub2))
*/
