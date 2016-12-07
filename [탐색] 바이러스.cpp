#include <stdio.h>
#include <string.h>

int _Number = 0;
int _Link[3] = { 0, 0, 0 };

/* 2차원 배열 */
int _List[101][101]; /* 임시 저장 변수 */
int _Queue[10000]; /* 큐 배열 */
int _Visit[101]; /* 방문 배열 */

/* Queue 위치 변수 */
int REAR = 0; /* 삽입 위치 변수 */
int FRONT = 0; /* 삭제 위치 변수 */

void BFS(int X);

int main()
{
	int _Count = 0;
	int _Row = 0, _Col = 0;
    
		/* 초기화 */
		memset(_List, 0, sizeof(_List));
		memset(_Visit, 0, sizeof(_Visit)); /* 방문 배열 초기화 */
		memset(_Queue, 0, sizeof(_Queue)); /* 큐 배열 초기화 */
		memset(_Link, 0, sizeof(_Link));

		scanf("%d\n%d", &_Number, &_Link[0]); /* 컴퓨터 수 */
		
		for (_Count = 0; _Count < _Link[0]; _Count++) /* 링크를 연결시켜 주는 반복문 */
		{ 
			scanf("%d %d", &_Link[1], &_Link[2]);
			_List[_Link[1]][_Link[2]] = _Link[2];
			_List[_Link[2]][_Link[1]] = _Link[1];
		}

		BFS(1); /* 경로 탐색 */

		for (_Row = 0; _Row < REAR; _Row++) /* 큐에 중복 된 값을 제거하는 반복문 */
		{
			for (_Col = _Row + 1; _Col < REAR; _Col++)
			{ if (_Queue[_Row] == _Queue[_Col]) { _Queue[_Col] = 0; } }
		}

		for (_Row = 0, _Col = 0; _Row <= REAR; _Row++) /* 카운터 */
		{ if (_Queue[_Row] != 0) { _Col++; } }

		printf("%d\n", _Col - 1); /* 출력 */

		/* 초기화 */
		REAR = 0;
		FRONT = 0;
		_Number = 0;
    
	return 0;	/* 반드시 return 0으로 해주셔야합니다. */
}

void BFS(int X)
{
	int SubX = 0, SubY = 0;

	_Queue[REAR++] = X; /* 초기값 */

	while (REAR > FRONT)
	{
		SubX = _Queue[FRONT++];

		if (_Visit[SubX] == 0)
		{
			_Visit[SubX] = 1;
			for (SubY = 0; SubY <= _Number; SubY++)
			{
				if (_List[SubX][SubY] != 0)
				{ _Queue[REAR++] = _List[SubX][SubY]; }
			}
		}
	}
}
