#include <stdio.h>

int GCD(int X, int Y);
int LCM(int X, int Y, int Max);

int main()
{
	int Value[2] = { 0, 0 };
	int Temp = 0;

	scanf("%d %d", &Value[0], &Value[1]);
	
	Temp = GCD(Value[0], Value[1]);
	printf("%d\n%d\n", Temp, LCM(Value[0], Value[1], Temp));

	return 0;
}

int GCD(int X, int Y)
{
	if ( Y == 0 ) { return X; }
	else { return GCD(Y, X%Y); }
}
int LCM(int X, int Y, int Max)
{
	int _X = 0;
	_X = (X / Max) * (Y / Max) * Max;
	return _X;
}
