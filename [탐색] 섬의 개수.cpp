#include <stdio.h>
#include <string.h>
#define SIZE1 52
#define SIZE2 10000
 
/* Integer Array */
int Array[SIZE1][SIZE1];
int Visit[SIZE1][SIZE1];
int Queue[SIZE2][2];
 
int main(void)
{
    /* Integer */
    int X = 0, Y = 0;
    int Count = 0;
 
    /*
    * 움직일 수 있는 곳 1
    * 움직일 수 없는 곳 0
    */
 
    while (1)
    {
        /* 지도의 너비와 높이 입력 */
        scanf("%d %d", &Y, &X);
 
        /* 종료조건 */
        if (X == 0 && Y == 0) { break; }
 
        /* 배열 입력 */
        for (int i = 0; i < X; i++) { for (int j = 0; j < Y; j++) { scanf("%d", &Array[i][j]); } }
 
        /* BFS */
        for (int i = 0; i < X; i++)
        { for (int j = 0; j < Y; j++) { if (Visit[i][j] == 0 && Array[i][j] == 1) { BFS(i, j); Count++; } } }
 
        /* 출력 */
        printf("%d\n", Count); Count = 0;
 
        /* 초기화 */
        memset(Array, 0, sizeof(Array));
        memset(Visit, 0, sizeof(Visit));
    }
 
    return 0;
}
 
int BFS(int X, int Y)
{
    /* Integer */
    int SubX = 0, SubY = 0;
 
    /* Queue */
    int REAR = 0, FRONT = 0;
 
    /* Queue 초기값 */
    Queue[REAR][0] = X;
    Queue[REAR][1] = Y;
    REAR = (REAR + 1) % SIZE2;
    
    /* Queue 방문표시 */
    Visit[X][Y] = 1;
 
    while (REAR != FRONT)
    {
        /* Queue 값 변경 */
        SubX = Queue[FRONT][0];
        SubY = Queue[FRONT][1];
        FRONT = (FRONT + 1) % SIZE2;
 
                                /* 상하좌우 */
        if (Visit[SubX + 1][SubY] == 0 && Array[SubX + 1][SubY] == 1)
        {
            /* Queue 값 변경 */
            Queue[REAR][0] = SubX + 1;
            Queue[REAR][1] = SubY;
            REAR = (REAR + 1) % SIZE2;
            /* Visit 값 변경 */
            Visit[SubX + 1][SubY] = 1;
        }
        if (Visit[SubX - 1][SubY] == 0 && Array[SubX - 1][SubY] == 1)
        {
            /* Queue 값 변경 */
            Queue[REAR][0] = SubX - 1;
            Queue[REAR][1] = SubY;
            REAR = (REAR + 1) % SIZE2;
            /* Visit 값 변경 */
            Visit[SubX - 1][SubY] = 1;
        }
        if (Visit[SubX][SubY + 1] == 0 && Array[SubX][SubY + 1] == 1)
        {
            /* Queue 값 변경 */
            Queue[REAR][0] = SubX;
            Queue[REAR][1] = SubY + 1;
            REAR = (REAR + 1) % SIZE2;
            /* Visit 값 변경 */
            Visit[SubX][SubY + 1] = 1;
        }
        if (Visit[SubX][SubY - 1] == 0 && Array[SubX][SubY - 1] == 1)
        {
            /* Queue 값 변경 */
            Queue[REAR][0] = SubX;
            Queue[REAR][1] = SubY - 1;
            REAR = (REAR + 1) % SIZE2;
            /* Visit 값 변경 */
            Visit[SubX][SubY - 1] = 1;
        }
                                /* 대각선 방향 */
        if (Visit[SubX + 1][SubY - 1] == 0 && Array[SubX + 1][SubY - 1] == 1)
        {
            /* Queue 값 변경 */
            Queue[REAR][0] = SubX + 1;
            Queue[REAR][1] = SubY - 1;
            REAR = (REAR + 1) % SIZE2;
            /* Visit 값 변경 */
            Visit[SubX + 1][SubY - 1] = 1;
        }
        if (Visit[SubX - 1][SubY + 1] == 0 && Array[SubX - 1][SubY + 1] == 1)
        {
            /* Queue 값 변경 */
            Queue[REAR][0] = SubX - 1;
            Queue[REAR][1] = SubY + 1;
            REAR = (REAR + 1) % SIZE2;
            /* Visit 값 변경 */
            Visit[SubX - 1][SubY + 1] = 1;
        }
        if (Visit[SubX + 1][SubY + 1] == 0 && Array[SubX + 1][SubY + 1] == 1)
        {
            /* Queue 값 변경 */
            Queue[REAR][0] = SubX + 1;
            Queue[REAR][1] = SubY + 1;
            REAR = (REAR + 1) % SIZE2;
            /* Visit 값 변경 */
            Visit[SubX + 1][SubY + 1] = 1;
        }
        if (Visit[SubX - 1][SubY - 1] == 0 && Array[SubX - 1][SubY - 1] == 1)
        {
            /* Queue 값 변경 */
            Queue[REAR][0] = SubX - 1;
            Queue[REAR][1] = SubY - 1;
            REAR = (REAR + 1) % SIZE2;
            /* Visit 값 변경 */
            Visit[SubX - 1][SubY - 1] = 1;
        }
    }
}
