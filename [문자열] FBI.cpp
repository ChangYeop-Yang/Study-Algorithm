#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void)
{
	vector<int> mVector;
	for (int ii = 0; ii < 5; ii++)
	{
		string mString;
		cin >> mString;

		if (mString.find("FBI") != -1) { mVector.push_back(ii + 1); }
	}

	if (mVector.size() == 0) { cout << "HE GOT AWAY!" << endl; }
	else
	{
		for (vector<int>::iterator m = mVector.begin(); m != mVector.end(); m++, cout << " ")
		{
			cout << *m;
		}
	} cout << endl;

	return 0;
}
