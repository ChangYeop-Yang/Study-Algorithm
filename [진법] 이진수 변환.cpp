#include<cstdio>
using namespace std;

#define Type unsigned long long int

void Dex(Type mDex)
{
	if (mDex < 2)
	{
		printf("%d", mDex);
	}
	else
	{
		Dex(mDex / 2);
		printf("%d", mDex%2);
	}
}

int main(void)
{
	Type mNum = 0;
	scanf("%llu", &mNum);

	Dex(mNum);
	printf("\n");

	return 0;
}
