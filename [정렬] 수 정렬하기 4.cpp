#include <cstdio>
#include <algorithm>
using namespace std;

int arr[1000001];

int main(void)
{
	int num = 0;
	scanf("%d", &num);

	for (int ii = 0; ii < num; ii++)
		scanf("%d", &arr[ii]);

	sort(arr, arr + num, [](int a, int b) {return a > b; });

	for (int ii = 0; ii < num; ii++)
		printf("%d\n", arr[ii]);
		
	return 0;
}
