#include <stdio.h>
#include <string.h>
#define SIZE1 10000
#define SIZE2 102

int Queue[SIZE1][2];
int Visit[SIZE2][SIZE2];
char Array[SIZE2][SIZE2];

int REAR = 0;
int FRONT = 0;

int main(void)
{
	int mX = 0, mY = 0;
	scanf("%d %d", &mX, &mY);

	for (int count = 0; count < mX; count++)
	{
		scanf("%s", &Array[count]);
	}

	BFS(0, 0);
	printf("%d\n", Visit[mX-1][mY-1]);
	return 0;
}

int BFS(int x, int y)
{
	int SubX = 0, SubY = 0;
	int COUNT = 0;

	Queue[REAR][0] = x;
	Queue[REAR][1] = y;
	REAR = (REAR + 1) % SIZE1;

	Visit[x][y] = 1;

	while(REAR > FRONT)
	{
		SubX = Queue[FRONT][0];
		SubY = Queue[FRONT][1];
		FRONT = (FRONT + 1) % SIZE1;
		COUNT = Visit[SubX][SubY];

		if (Visit[SubX + 1][SubY] == 0 && Array[SubX + 1][SubY] == '1')
		{
			Queue[REAR][0] = SubX + 1;
			Queue[REAR][1] = SubY;
			REAR = (REAR + 1) % SIZE1;

			Visit[SubX + 1][SubY] = COUNT + 1;
		}
		if (Visit[SubX][SubY + 1] == 0 && Array[SubX][SubY + 1] == '1')
		{
			Queue[REAR][0] = SubX;
			Queue[REAR][1] = SubY + 1;
			REAR = (REAR + 1) % SIZE1;

			Visit[SubX][SubY + 1] = COUNT + 1;
		}
		if (Visit[SubX - 1][SubY] == 0 && Array[SubX - 1][SubY] == '1')
		{
			Queue[REAR][0] = SubX - 1;
			Queue[REAR][1] = SubY;
			REAR = (REAR + 1) % SIZE1;

			Visit[SubX - 1][SubY] = COUNT + 1;
		}
		if (Visit[SubX][SubY - 1] == 0 && Array[SubX][SubY - 1] == '1')
		{
			Queue[REAR][0] = SubX;
			Queue[REAR][1] = SubY - 1;
			REAR = (REAR + 1) % SIZE1;

			Visit[SubX][SubY - 1] = COUNT + 1;
		}
	}
}
