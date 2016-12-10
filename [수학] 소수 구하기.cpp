#include <cstdio>
#include <cmath>

bool getChe(long long int num)
{
	/* 예외처리 (1과 2는 예외로 처리한다.) */ 
	if (num == 1) return false;
	if (num == 2) return true;

	/* 2를 제외한 모든 짝수는 소수가 아니다. */
	if (num % 2 == 0) return false;

	/* 2를 제외한 3이상의 홀수 소수를 구하는 부분 */
	long long int mSqrt = sqrt(num);
	for (int div = 3; div <= mSqrt; div += 2)
		if (num % div == 0) return false;

	return true;
}

int main(void)
{
	/* input */
	long long int num1 = 0, num2 = 0;
	scanf("%d %d", &num1, &num2);

	for (long long int ii = num1; ii <= num2; ii++)
	{ if (getChe(ii)) printf("%d\n", ii); }

	return 0;
}
