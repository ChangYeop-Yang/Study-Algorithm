#include <cstdio>
#include <map>
using namespace std;

map<int, int> mMap;

int main(void)
{
	int nn = 0;
	scanf("%d", &nn);

	for (int ii = 0, mTemp = 0; ii < nn; ii++)
	{ 
		scanf("%d", &mTemp); 

		if (mMap.count(mTemp)) { mMap[mTemp]++; }
		else { mMap.insert(make_pair(mTemp, 1)); }
	}

	int mm = 0;
	scanf("%d", &mm);

	for (int ii = 0, mTemp = 0; ii < mm; ii++, printf(" "))
	{
		scanf("%d", &mTemp);
		printf("%d", mMap.count(mTemp) ? mMap[mTemp] : 0);
	} printf("\n");
		

	return 0;
}
