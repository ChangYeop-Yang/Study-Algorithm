#include <iostream>
#include <queue>
#define SIZE 100001
using namespace std;
 
queue<int> mQueue;
int mArray[SIZE] = { 0, };
 
int BFS(int X, int Y)
{
    int cost = 0, position = 0;
    mQueue.push(X);
 
    mArray[X] = 1;
 
    while (!mQueue.empty())
    {
        position = mQueue.front(); mQueue.pop();
        cost = mArray[position];
 
        if (position == Y) { return mArray[position] - 1; }
 
        if (position - 1 >= 0 && mArray[position - 1] == 0 ) 
        {
            mQueue.push(position - 1);
            mArray[position - 1] = cost + 1;
        }
        if (position + 1 <= SIZE && mArray[position + 1] == 0)
        {
            mQueue.push(position + 1);
            mArray[position + 1] = cost + 1;
        }
        if (position * 2 <= SIZE && mArray[position * 2] == 0)
        {
            mQueue.push(position * 2);
            mArray[position * 2] = cost + 1;
        }
    }
}
 
int main(void)
{
    int num1 = 0, num2 = 0;
    cin >> num1 >> num2;
 
    cout << BFS(num1, num2) << endl;
 
    return 0;
}
