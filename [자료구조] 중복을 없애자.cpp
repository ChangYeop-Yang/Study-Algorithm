#include <iostream>
#include <queue>
using namespace std;

int main(void)
{
	while (true)
	{
		int mNumber = 0; cin >> mNumber;
		if (mNumber == 0) { break; }

		queue<int> mQueue;
		for (int ii = 0; ii < mNumber; ii++)
		{
			int mTemp = 0; cin >> mTemp;
			if (mQueue.empty()) { mQueue.push(mTemp); continue; }
			else if (mQueue.back() != mTemp) { mQueue.push(mTemp); }
		}

		for (; !mQueue.empty(); mQueue.pop(), cout << " ")
		{ cout << mQueue.front(); }

		cout << "$" << endl;
	}

	return 0;
}
