#include <cstdio>
#include <vector>
using namespace std;

vector<pair<char, char>> mVector;

int mCount = 0;

void Haha(int num, char from, char by, char to)
{
	mCount++;
	if (num == 1) { mVector.push_back(make_pair(from, to)); return; }
	
	Haha(num - 1, from, to, by);
	mVector.push_back(make_pair(from, to));
	Haha(num - 1, by, from, to);
}

int main(void)
{
	int num = 0;
	scanf("%d", &num);

	Haha(num, '1', '2', '3');

	printf("%d\n", mCount);
	
	int mLength = mVector.size();
	for (int ii = 0; mLength > ii; ii++)
	{
		printf("%c %c\n", mVector[ii].first, mVector[ii].second); }


	return 0;
}
