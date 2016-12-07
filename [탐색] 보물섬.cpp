#include <stdio.h>
#define SIZE1 10000
#define SIZE2 52

int _Visit[SIZE2][SIZE2] = { 0, }; /* 방문 */
int _Queue[SIZE1][2] = { 0, }; /* Queue */
char _Str1[SIZE2][SIZE2] = { 0, }; /* 문자열 */

int MAX = 0;
int REAR = 0;
int FRONT = 0;

void Init();
void ClearVisit();
void BFS(int X, int Y);

int main()
{
	int _Count[2] = { 0, 0 };
	int _Row = 0; /* 행 */
	int _Col = 0; /* 열 */

		scanf("%d %d", &_Row, &_Col); /* 행과 열 입력 */

		for (_Count[0] = 0; _Count[0] < _Row; _Count[0]++) /* 문자열 입력 */
		{ scanf("%s", _Str1[_Count[0]]); }

		for (_Count[0] = 0; _Count[0] < _Row; _Count[0]++) /* 탐색 */
		{ 
			for (_Count[1] = 0; _Count[1] < _Col; _Count[1]++) 
			{
				if (_Visit[_Count[0]][_Count[1]] == 0 && _Str1[_Count[0]][_Count[1]] == 'L')
				{ BFS(_Count[0], _Count[1]); }
				ClearVisit();
			} 
        }
    
		printf("%d\n", MAX-1); /* 출력 */
	return 0;	/* 반드시 return 0으로 해주셔야합니다. */
}
void Init()
{
	int _Count[2] = { 0, 0 };

	/* Queue 위치 변수 초기화 */
	REAR = 0;
	FRONT = 0;

	/* MAX 변수 초기화 */
	MAX = 0;

	for (_Count[0] = 0; _Count[0] < SIZE2; _Count[0]++) /* 배열 초기화 */
	{ 
		for (_Count[1] = 0; _Count[1] < SIZE2; _Count[1]++) 
		{ 
			_Str1[_Count[0]][_Count[1]] = 0;
			_Visit[_Count[0]][_Count[1]] = 0; 
		} 
	}

	for (_Count[0] = 0; _Count[0] < SIZE1; _Count[0]++) /* 큐 초기화 */
	{ 
		_Queue[_Count[0]][0] = 0;
		_Queue[_Count[0]][1] = 0; 
	}
}
void BFS(int X, int Y)
{
	int SubX = 0, SubY = 0, TIME = 0;

	/* Queue 위치 변수 초기화 */
	REAR = 0;
	FRONT = 0;

	/* Queue 초기 값 저장 */
	_Queue[REAR][0] = X;
	_Queue[REAR][1] = Y;
	REAR = (REAR + 1) % SIZE1;

	/* 처음 방문 */
	_Visit[X][Y] = 1;

	while (REAR > FRONT)
	{
		SubX = _Queue[FRONT][0];
		SubY = _Queue[FRONT][1];
		FRONT = (FRONT + 1) % SIZE1;

		/* 최대 시간 */
		TIME = _Visit[SubX][SubY];

		if (MAX < _Visit[SubX][SubY]) { MAX = _Visit[SubX][SubY]; } /* 최대 값 */

		if (_Visit[SubX + 1][SubY] == 0 && _Str1[SubX + 1][SubY] == 'L')
		{
			/* Queue */
			_Queue[REAR][0] = SubX + 1;
			_Queue[REAR][1] = SubY;
			REAR = (REAR + 1) % SIZE1;

			/* 최대 시간 */
			_Visit[SubX + 1][SubY] = TIME + 1;
		}
		if (_Visit[SubX - 1][SubY] == 0 && _Str1[SubX - 1][SubY] == 'L')
		{
			_Queue[REAR][0] = SubX - 1;
			_Queue[REAR][1] = SubY;
			REAR = (REAR + 1) % SIZE1;

			_Visit[SubX - 1][SubY] = TIME + 1;
		}
		if (_Visit[SubX][SubY + 1] == 0 && _Str1[SubX][SubY + 1] == 'L')
		{
			_Queue[REAR][0] = SubX;
			_Queue[REAR][1] = SubY + 1;
			REAR = (REAR + 1) % SIZE1;

			_Visit[SubX][SubY + 1] = TIME + 1;
		}
		if (_Visit[SubX][SubY - 1] == 0 && _Str1[SubX][SubY - 1] == 'L')
		{
			_Queue[REAR][0] = SubX;
			_Queue[REAR][1] = SubY - 1;
			REAR = (REAR + 1) % SIZE1;

			_Visit[SubX][SubY - 1] = TIME + 1;
		}
	}
}
void ClearVisit()
{
	int _Count[2] = { 0, 0 };

	for (_Count[0] = 0; _Count[0] < SIZE2; _Count[0]++)
	{ for (_Count[1] = 0; _Count[1] < SIZE2; _Count[1]++) { _Visit[_Count[0]][_Count[1]] = 0; }}
}
