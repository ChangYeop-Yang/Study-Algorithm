#include <cstdio>
#include <map>
using namespace std;

map<int, bool> mMap;

int main(void)
{
	int nn = 0;
	scanf("%d", &nn);

	for (int ii = 0, mTemp = 0; ii < nn; ii++)
	{ scanf("%d", &mTemp); mMap.insert(make_pair(mTemp, true)); }

	int mm = 0;
	scanf("%d", &mm);

	for (int ii = 0, mTemp = 0; ii < mm; ii++, printf(" "))
	{
		scanf("%d", &mTemp);
		printf("%d", mMap.count(mTemp) ? 1 : 0);
	} printf("\n");
		

	return 0;
}
