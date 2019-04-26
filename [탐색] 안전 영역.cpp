#include <stdio.h>
#include <string.h>
#define SIZE1 101
#define SIZE2 10000
 
/* Integer Array */
int Array[SIZE1][SIZE1];
int Visit[SIZE1][SIZE1];
int Queue[SIZE2][2];
 
int main(void)
{
    int x = 0, Count = 0, Max[2] = { 0, 0 };
    
    /* 배열 크기 입력 */
    scanf("%d", &x);
 
    /* 배열 요소 입력 */
    for (int i = 0; i < x; i++)
    { 
        for (int j = 0; j < x; j++) 
        { 
            scanf("%d", &Array[i][j]); 
            if (Max[0] < Array[i][j]) { Max[0] = Array[i][j]; }
        } 
    }
 
    /* 안전 영역 구하는 구문 */
    for (int z = 0; z < Max[0]; z++)
    {
        /* 침수 */
        for (int q = 0; q < x; q++)
        { for (int w = 0; w < x; w++) { if (Array[q][w] <= z) { Array[q][w] = 0; } } }
        
        /* BFS */
        for (int i = 0; i < x; i++)
        { for (int j = 0; j < x; j++) { if (Visit[i][j] == 0 && Array[i][j] != 0) { BFS(i, j); Count++; } } }
 
        /* 최대값 저장 */
        if (Max[1] < Count) { Max[1] = Count; }
        Count = 0;
 
        /* 초기화 */
        memset(Queue, 0, sizeof(Queue));
        memset(Visit, 0, sizeof(Visit));
    }
    
    /* 출력 */
    printf("%d\n", Max[1]);
 
    return 0;
}
 
int BFS(int X, int Y)
{
    /* Integer */
    int SubX = 0, SubY = 0;
    int REAR = 0, FRONT = 0;
 
    /* Queue 초기값 설정 */
    Queue[REAR][0] = X;
    Queue[REAR][1] = Y;
    REAR = (REAR + 1) % SIZE2;
 
    /* Visit 초기값 설정 */
    Visit[X][Y] = 1;
 
    while (REAR != FRONT)
    {
        /* Queue 값 설정 */
        SubX = Queue[FRONT][0];
        SubY = Queue[FRONT][1];
        FRONT = (FRONT + 1) % SIZE2;
 
        if (Visit[SubX + 1][SubY] == 0 && Array[SubX + 1][SubY] != 0)
        {
            /* Queue 값 변경 */
            Queue[REAR][0] = SubX + 1;
            Queue[REAR][1] = SubY;
            REAR = (REAR + 1) % SIZE2;
 
            Visit[SubX + 1][SubY] = 1;
        }
        if (Visit[SubX - 1][SubY] == 0 && Array[SubX - 1][SubY] != 0)
        {
            /* Queue 값 변경 */
            Queue[REAR][0] = SubX - 1;
            Queue[REAR][1] = SubY;
            REAR = (REAR + 1) % SIZE2;
 
            Visit[SubX - 1][SubY] = 1;
        }
        if (Visit[SubX][SubY + 1] == 0 && Array[SubX][SubY + 1] != 0)
        {
            /* Queue 값 변경 */
            Queue[REAR][0] = SubX;
            Queue[REAR][1] = SubY + 1;
            REAR = (REAR + 1) % SIZE2;
 
            Visit[SubX][SubY + 1] = 1;
        }
        if (Visit[SubX][SubY - 1] == 0 && Array[SubX][SubY - 1] != 0)
        {
            /* Queue 값 변경 */
            Queue[REAR][0] = SubX;
            Queue[REAR][1] = SubY - 1;
            REAR = (REAR + 1) % SIZE2;
 
            Visit[SubX][SubY - 1] = 1;
        }
    }
}
