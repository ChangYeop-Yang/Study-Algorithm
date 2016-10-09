#include <iostream>
#include <cstring>
#define MAX 5
using namespace std;
 
int main(void)
{
    /* Char */
    char mChar[MAX][16];
 
    memset(mChar, 0, sizeof(mChar));
 
    /* Input */
    for (int count = 0; count < MAX; count++) { cin >> mChar[count]; }
 
    /* output */
    for (int count = 0; count < 16; count++)
    {
        for (int ii = 0; ii < MAX; ii++)
        {
            if (mChar[ii][count] == '\0') { continue; }
            else { cout << mChar[ii][count]; }
        }
    }
 
    cout << endl;
 
    return 0;
}
