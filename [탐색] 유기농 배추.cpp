#include <stdio.h>
#include <string.h>
#define SIZE 51
#define SIZE2 10001
 
/* Integer Array */
int Array[SIZE][SIZE];
int Visit[SIZE][SIZE];
int Queue[SIZE2][2];
 
int main(void)
{
    /* Integer */
    unsigned int T = 0;
    unsigned int M = 0, N = 0, K = 0;
    unsigned int temp[2] = { 0, 0 };
    unsigned int Count = 0;
 
    /* TestCase 입력 */
    scanf("%d", &T);
 
    /* TestCase 반복문 */
    for (int count = 0; count < T; count++)
    {
        /* 배추밭 정보 입력 */
        scanf("%d %d %d", &M, &N, &K);
        for (int ii = 0; ii < K; ii++)
        { 
            /* 배추 밭 값 입력 */
            scanf("%d %d", &temp[0], &temp[1]);
            Array[temp[0]][temp[1]] = 1;
        }
 
        /* BFS */
        for (int jj = 0; jj < M; jj++)
        { for (int kk = 0; kk < N; kk++) { if (Visit[jj][kk] == 0 && Array[jj][kk] == 1) { BFS(jj, kk); Count++; } } }
 
        /* 출력 */
        printf("%d\n", Count); Count = 0;
 
        /* 초기화 */
        memset(Array, 0, sizeof(Array));
        memset(Visit, 0, sizeof(Visit));
        memset(Queue, 0, sizeof(Queue));
    }
 
    return 0;
}
 
int BFS(int M, int N)
{
    /* Integer */
    unsigned int SubX = 0, SubY = 0;
    unsigned int REAR = 0, FRONT = 0;
 
    /* Queue 초기값 설정 */
    Queue[REAR][0] = M;
    Queue[REAR][1] = N;
    REAR = (REAR + 1) % SIZE2;
 
    /* 초기값 설정 */
    Visit[M][N] = 1;
 
    while (REAR != FRONT)
    {
        /* Queue */
        SubX = Queue[FRONT][0];
        SubY = Queue[FRONT][1];
        FRONT = (FRONT + 1) % SIZE2;
 
        if (Visit[SubX + 1][SubY] == 0 && Array[SubX + 1][SubY] == 1)
        {
            /* Queue 값 설정 */
            Queue[REAR][0] = SubX + 1;
            Queue[REAR][1] = SubY;
            REAR = (REAR + 1) % SIZE2;
            /* 방문확인 */
            Visit[SubX + 1][SubY] = 1;
        }
        if (Visit[SubX - 1][SubY] == 0 && Array[SubX - 1][SubY] == 1)
        {
            /* Queue 값 설정 */
            Queue[REAR][0] = SubX - 1;
            Queue[REAR][1] = SubY;
            REAR = (REAR + 1) % SIZE2;
            /* 방문확인 */
            Visit[SubX - 1][SubY] = 1;
        }
        if (Visit[SubX][SubY + 1] == 0 && Array[SubX][SubY + 1] == 1)
        {
            /* Queue 값 설정 */
            Queue[REAR][0] = SubX;
            Queue[REAR][1] = SubY + 1;
            REAR = (REAR + 1) % SIZE2;
            /* 방문확인 */
            Visit[SubX][SubY + 1] = 1;
        }
        if (Visit[SubX][SubY - 1] == 0 && Array[SubX][SubY - 1] == 1)
        {
            /* Queue 값 설정 */
            Queue[REAR][0] = SubX;
            Queue[REAR][1] = SubY - 1;
            REAR = (REAR + 1) % SIZE2;
            /* 방문확인 */
            Visit[SubX][SubY - 1] = 1;
        }
    }
 
    return 0;
}
