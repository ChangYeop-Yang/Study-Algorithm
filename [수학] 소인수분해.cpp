#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
	/* input */
	int num = 0;
	cin >> num;

	vector<int> mVector;

	int sqrtn = int(sqrt(num)); /* 입력받은 값의 루트값 */
	for (int div = 2; div <= sqrtn; div++)
	{
		while (num % div == 0)
		{
			num /= div;
			mVector.push_back(div);
		}
	}

	if (num > 1) mVector.push_back(num);

	sort(mVector.begin(), mVector.end());
	
	for (int count = 0, mLength = mVector.size(); count < mLength; count++)
	{
		cout << mVector[count] << endl;
	} 

	return 0;
}
