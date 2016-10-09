#include <iostream>
#include <cstring>
using namespace std;
 
int Queue[10001];
int FRONT = 0;
int REAR = 0;
 
void push(int x) { Queue[REAR++] = x; }
int pop() { return REAR == FRONT ? -1 : Queue[FRONT++]; }
int size() { return REAR-FRONT; }
int empty() { return REAR == FRONT ? 1 : 0; }
int front() { return REAR == FRONT ? -1 : Queue[FRONT]; }
int back() { return REAR == FRONT ? -1 : Queue[REAR-1]; }
 
int main(void)
{
    int m = 0;
    cin >> m;
 
    int mTemp = 0;
    char mChar[10];
    for (int count = 0; count < m; count++)
    {
        cin >> mChar;
        if (strcmp(mChar, "push") == 0) { cin >> mTemp; push(mTemp); }
        else if (strcmp(mChar, "pop") == 0) { cout << pop() << endl; }
        else if (strcmp(mChar, "size") == 0) { cout << size() << endl; }
        else if (strcmp(mChar, "empty") == 0) { cout << empty() << endl; }
        else if (strcmp(mChar, "front") == 0) { cout << front() << endl; }
        else { cout << back() << endl; }
    }
 
    return 0;
}
