#include <stdio.h>

int main()
{
	int _Value = 0;
	int _Count = 0;
	int _Result = 0;
	int _Flag = 0;
	int _MIN = 99999999;

	for (_Count = 0; _Count < 7; _Count++)
	{
		scanf("%d", &_Value);

		if (_Value % 2 != 0) /* 짝수가 아닌 것 */
		{
			_Result += _Value; /* 홀수 결과 값 덧셈 */
			if (_MIN > _Value) { _MIN = _Value; }
			_Flag = 2;
		}
	} /* 입력 */

	if (_Flag != 2) { printf("-1\n"); }
	else { printf("%d\n%d\n", _Result, _MIN); }

	return 0;
}
