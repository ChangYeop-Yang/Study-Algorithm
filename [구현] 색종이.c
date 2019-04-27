#include <stdio.h>
#define SIZE 100

char _Arr1[SIZE][SIZE] = { 0, };

void Init();
void Full(int X, int Y);
int Select();

int main()
{
	int _Line = 0; /* 색종이의 수 */
	int _Temp[2] = { 0, 0 };
	int _Count = 0;

		Init();

		scanf("%d", &_Line); /* 색종이수 입력 */
		for (_Count = 0; _Count < _Line; _Count++)
		{
			scanf("%d %d", &_Temp[0], &_Temp[1]);
			Full(_Temp[0], _Temp[1]); /* 색 채우기 */
		}

		printf("%d\n", Select()); /* 출력 */
	return 0;	/* 반드시 return 0으로 해주셔야합니다. */
}

void Init() /* 초기화 */
{
	int _Count[2] = { 0, 0 };

	for (_Count[0] = 0; _Count[0] < SIZE; _Count[0]++)
	{ for (_Count[1] = 0; _Count[1] < SIZE; _Count[1]++) { _Arr1[_Count[0]][_Count[1]] = 0; } }
}

void Full(int X, int Y) /* 색 체우기 */
{
	int _Count[2] = { 0, 0 };
	X--;
	Y--;

	for (_Count[0] = X; (_Count[0] < (X + 10)) && (_Count[0] < 100); _Count[0]++)
	{
		for (_Count[1] = Y; (_Count[1] < (Y + 10)) && (_Count[1] < 100); _Count[1]++)
		{ _Arr1[_Count[0]][_Count[1]] = 'A'; } 
	}
}

int Select()
{
	int _Count[2] = { 0, 0 };
	int _Flag = 0;

	for (_Count[0] = 0; _Count[0] < SIZE; _Count[0]++)
	{ for (_Count[1] = 0; _Count[1] < SIZE; _Count[1]++) { if (_Arr1[_Count[0]][_Count[1]] == 'A' ) { _Flag++; } } }

	return _Flag;
}
