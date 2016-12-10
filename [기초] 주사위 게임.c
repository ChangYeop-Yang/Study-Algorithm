#include <stdio.h>

int _Noon[1002][3] = { 0, };

int main()
{
	int _Line = 0; /* 주사위 값 */
	int _Max = 0;
	int _Flag = 0;
	int _Temp = 0;
	int INDEX[2] = { 0, 0 };
	int _Temp2 = 0;
	int _Count[2] = { 0, 0 };

	scanf("%d\n", &_Line);

	for (_Count[0] = 0; _Count[0] < _Line; _Count[0]++) /* 입력 */
	{ 
		for (_Count[1] = 0; _Count[1] < 3; _Count[1]++) { scanf("%d", &_Noon[_Count[0]][_Count[1]]); } 

		for (_Count[1] = 0, _Flag = 0; _Count[1] < 3; _Count[1]++) /* 검사 */
		{
			_Temp = _Noon[_Count[0]][_Count[1]];
			if (_Temp == _Noon[_Count[0]][_Count[1] + 1]) 
			{ 
				INDEX[0] = _Noon[_Count[0]][_Count[1]]; 
				_Flag++; 
			}
		}

		if (_Flag == 0) 
		{
			for (_Count[1] = 0, _Flag = 0; _Count[1] < 3; _Count[1]++) /* 큰 값 */
			{ if (_Temp2 < _Noon[_Count[0]][_Count[1]]) { _Temp2 = _Noon[_Count[0]][_Count[1]]; } }

			_Temp = _Temp2 * 100;
		}
		else if (_Flag == 1) { _Temp = 1000 + (INDEX[0] * 100); }
		else if (_Flag == 2) { _Temp = 10000 + (INDEX[0] * 1000); } /* 눈이 3개가 같은 경우 */

		if (_Max < _Temp) { _Max = _Temp; } /* 최대 값 */
	}

	printf("%d\n", _Max);

	return 0;
}
