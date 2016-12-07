#include <stdio.h>
 
int _Queue[10000][2] = { 0, };
int _Visit[102][102] = { 0, };
int _Array[102][102] = { 0, };
 
int REAR = 0;
int FRONT = 0;
int COUNT = 0;
 
int _Block = 0;
 
void BFS(int X, int Y);
 
int main()
{
    int _Count[2] = { 0, 0 };
    int _Line = 0; /* 배열의 수 */
    int _Pool[2] = { 0, 0 }; /* 호수의 위치 */
    int _Clock = 0;
    int _MAX = 0;
 
    /* 초기화 */
    for (_Count[0] = 0; _Count[0] < 102; _Count[0]++)
    { for (_Count[1] = 0; _Count[1] < 102; _Count[1]++) { _Array[_Count[0]][_Count[1]] = 1; } }
 
    scanf("%d", &_Line); /* 배열의 크기 */
    for (_Count[0] = 1; _Count[0] <= _Line; _Count[0]++)
    { for (_Count[1] = 1; _Count[1] <= _Line; _Count[1]++) { scanf("%d", &_Array[_Count[0]][_Count[1]]); } }
 
    scanf("%d %d\n%d", &_Pool[1], &_Pool[0], &_Block); /* 호수의 위치 및 댐의 건설 시간 */
 
    BFS(_Pool[0], _Pool[1]); /* BFS 탐색 */
 
    /* 댐 건설시간과 물이 도시를 꽉찬 시간 */
    COUNT == 0 ? printf("OH, MY GOD\n") : printf("%d\n", COUNT);
 
    /* 초기화 */
    _MAX = 0;
    _Clock = 0;
 
    return 0;
}
 
void BFS(int X, int Y)
{
    int SubX = 0, SubY = 0;
    int TIME = 0;
 
    /* QUEUE 초기화 */
    REAR = 0;
    FRONT = 0;
 
    _Queue[REAR][0] = X;
    _Queue[REAR][1] = Y;
    REAR = (REAR + 1) % 10000;
 
    _Visit[X][Y] = 1;
 
    while (REAR != FRONT)
    {
        SubX = _Queue[FRONT][0];
        SubY = _Queue[FRONT][1];
        FRONT = (FRONT + 1) % 10000;
        TIME = _Visit[SubX][SubY];
 
        if (_Visit[SubX][SubY] == _Block + 1) { COUNT++; continue; }
 
        if (_Visit[SubX + 1][SubY] == 0 && _Array[SubX + 1][SubY] == 0)
        {
            _Queue[REAR][0] = SubX + 1;
            _Queue[REAR][1] = SubY;
            REAR = (REAR + 1) % 10000;
            _Visit[SubX + 1][SubY] = TIME + 1;
        }
        if (_Visit[SubX - 1][SubY] == 0 && _Array[SubX - 1][SubY] == 0)
        {
            _Queue[REAR][0] = SubX - 1;
            _Queue[REAR][1] = SubY;
            REAR = (REAR + 1) % 10000;
            _Visit[SubX - 1][SubY] = TIME + 1;
        }
        if (_Visit[SubX][SubY + 1] == 0 && _Array[SubX][SubY + 1] == 0)
        {
            _Queue[REAR][0] = SubX;
            _Queue[REAR][1] = SubY + 1;
            REAR = (REAR + 1) % 10000;
            _Visit[SubX][SubY + 1] = TIME + 1;
        }
        if (_Visit[SubX][SubY - 1] == 0 && _Array[SubX][SubY - 1] == 0)
        {
            _Queue[REAR][0] = SubX;
            _Queue[REAR][1] = SubY - 1;
            REAR = (REAR + 1) % 10000;
            _Visit[SubX][SubY - 1] = TIME + 1;
        }
    }
}
