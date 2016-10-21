#include <cstdio>
#include <algorithm>
using namespace std;

long int mArr1[2000001] = { 0, };

int main(void)
{
	int number[2] = { 0, 0 };
	scanf("%d %d", &number[0], &number[1]);

	/* Input */
	int mLength = number[0] + number[1];
	for (int ii = 0; ii < mLength; ii++)
	{ scanf("%d", &mArr1[ii]); } 
	
	/* Sorting */
	sort(mArr1, mArr1 + mLength);

	/* Output */
	for (int ii = 0; ii < mLength; ii++)
	{ printf("%d ", mArr1[ii]); } 
	
	printf("\n");

	return 0;
}
